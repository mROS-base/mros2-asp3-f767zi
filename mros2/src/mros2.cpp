#include "mros2.h"

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include <rtps/rtps.h>
#include "sample1.h"
#include "cmsis_os.h"
#include "lwip.h"
#include <cstdint>
#include <map>

#include "stm32f7xx_hal.h"
#include "stm32f7xx_nucleo_144.h"

#include "rtps/rtps.h"

#include "TEST.hpp"
#include "std_msgs/msg/string.hpp"

#include "mros2_cfg.h"

namespace mros2 {

rtps::Domain *domain_ptr = NULL;
rtps::Participant *part_ptr = NULL; //TODO: detele this
rtps::Writer *pub_ptr = NULL;

std::map<int_t, intptr_t> subscriber_map;
std::map<int_t, intptr_t> callback_arg_map;

uint8_t recv_buf[MROS2_RECV_BUF_SIZE];
uint8_t pub_buf[MROS2_SEND_BUF_SIZE];

Node Node::create_node()
{
   Node node;
   syslog(LOG_NOTICE, "create_node");
   syslog(LOG_NOTICE, "start creating participant");
   while(domain_ptr == NULL){dly_tsk(100000);}
   node.part = domain_ptr->createParticipant();
   part_ptr = node.part;
   if(node.part == nullptr){
       syslog(LOG_ERROR, "NODE CREATION FAILED");
       while(true){}
   }
   syslog(LOG_NOTICE, "successfully created participant");
   return node;
}
bool completeSubInit = false;
bool completePubInit = false;
uint8_t endpointId = 0;
uint32_t subCbArray[10];
ID tskid;

template <class T>
Subscriber Node::create_subscription(std::string node_name, int qos, void(*fp)(T))
{
	rtps::Reader* reader = domain_ptr->createReader(*(this->part), ("rt/"+node_name).c_str(), message_traits::TypeName<T>().value(), false);
    completeSubInit = true;
    Subscriber sub;
    sub.topic_name = node_name;
	sub.cb_fp = (void (*)(intptr_t))fp;
	get_tid(&tskid);
	sub.task_id = tskid;
	reader->registerCallback(sub.callback_handler, (void *)&sub);
	subscriber_map[tskid] = (intptr_t)&sub;
	syslog(LOG_NOTICE, "create subscription complete. taskID=%d", tskid);
    return sub;
}

template <class T>
Publisher Node::create_publisher(std::string node_name, int qos)
{
    rtps::Writer* writer = domain_ptr->createWriter(*part_ptr, ("rt/"+node_name).c_str(), message_traits::TypeName<T*>().value(), false);
    completePubInit = true;
    Publisher pub;
    pub_ptr = writer;
    pub.topic_name = node_name;
	get_tid(&tskid);
	syslog(LOG_NOTICE, "create publisher complete. taskID=%d", tskid);
    return pub;
}

void Subscriber::callback_handler(void* callee, const rtps::ReaderCacheChange& cacheChange)
{
	//TODO: move this to msg header files
	uint32_t msg_size;
	memcpy(&msg_size, &cacheChange.data[4], 4);
	std_msgs::msg::String *msg = (std_msgs::msg::String *)&recv_buf;
	msg->data.resize(msg_size);
	memcpy(&msg->data[0], &cacheChange.data[8], msg_size);
	mros2::Subscriber *sub = (mros2::Subscriber*)callee;
	callback_arg_map[sub->task_id] = (intptr_t)msg ;
	wup_tsk(sub->task_id);
}

template <class T>
void Publisher::publish(T& msg)
{
	msg.copyToBuf(&pub_buf[4]);
	pub_ptr->newChange(rtps::ChangeKind_t::ALIVE, pub_buf, msg.getTotalSize() + 4);
}

void init(int argc, char *argv)
{
	pub_buf[0] = 0;
	pub_buf[1] = 1;
	pub_buf[2] = 0;
	pub_buf[3] = 0;
    sys_thread_new("mROS2Thread", mros2_init, NULL, 1000, 24); //TODO: fix this
}

void spin()
{
    while(true){
        slp_tsk();
        get_tid(&tskid);
        syslog(LOG_NOTICE, "mros2::spin taskid=%d",tskid);
        mros2::Subscriber *sub = (mros2::Subscriber *)subscriber_map[tskid];
        void (*fp)(intptr_t) = sub->cb_fp;
        intptr_t msg = callback_arg_map[tskid];
        fp((intptr_t)msg);
    }
}

//Callback function to set the boolean to true upon a match
void setTrue(void* args){
	*static_cast<volatile bool*>(args) = true;
}
void pubMatch(void* args){
	syslog(LOG_NOTICE, "publisher matched with remote subscriber");
}

void subMatch(void* args){
	syslog(LOG_NOTICE, "subscriber matched with remote publisher");
}


void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange){
	syslog(LOG_NOTICE, "recv message");
}

void mros2_init(void *args)
{
    static rtps::Domain domain;
    domain_ptr = &domain;
	syslog(LOG_NOTICE, "mROS2 init start");
    while(!completeSubInit || !completePubInit){dly_tsk(100000);}

	 bool subMatched = false;
	 bool pubMatched = false;
	 bool received_message = false;

	 //Register callback to ensure that a publisher is matched to the writer before sending messages
	 part_ptr->registerOnNewPublisherMatchedCallback(subMatch, &pubMatched);
	 part_ptr->registerOnNewSubscriberMatchedCallback(pubMatch, &subMatched);


	 domain.completeInit();
	 //syslog(LOG_NOTICE, "mROS2 init complete");
	 get_tid(&tskid);
	syslog(LOG_NOTICE, "mROS2 init complete. taskID=%d", tskid);
	 ext_tsk();
	 //BSP_LED_On(LED1);
}


}//namespace mros2
void sub_task_dummy()
{
	get_tid(&mros2::tskid);
	syslog(LOG_NOTICE, "sub task called, taskid=%d", mros2::tskid);
	ext_tsk();
	while(true){}
}

//specialize template functions

template mros2::Publisher mros2::Node::create_publisher<TEST>(std::string node_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string node_name, int qos, void (*fp)(TEST*));

template mros2::Publisher mros2::Node::create_publisher<std_msgs::msg::String>(std::string node_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string node_name, int qos, void (*fp)(std_msgs::msg::String*));
template void mros2::Publisher::publish(std_msgs::msg::String& msg);
