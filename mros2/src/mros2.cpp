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

#include "stm32f7xx_hal.h"
#include "stm32f7xx_nucleo_144.h"

#include "rtps/rtps.h"
#include "std_msgs/msg/string.hpp"
namespace mros2 {

rtps::Domain *domain_ptr = NULL;
rtps::Participant *part_ptr = NULL; //TODO: detele this

Node Node::create_node()
{
   Node node;
   syslog(LOG_NOTICE, "create_node");
   syslog(LOG_NOTICE, "start creating participant");
   while(domain_ptr == NULL){tslp_tsk(100000);}
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

template <class T>
Subscriber Node::create_subscription(char *node_name, int qos, void(*fp)(T))
{
	rtps::Reader* reader = domain_ptr->createReader(*(this->part), node_name, message_traits::TypeName<T>().value(), false);
    reader->registerCallback(message_callback, NULL);
    completeSubInit = true;
    Subscriber sub;
    sub.topic_name = node_name;
    return sub;
}

template <class T>
Publisher Node::create_publisher(char *node_name, int qos, int callback)
{
    rtps::Writer* writer = domain_ptr->createWriter(*part_ptr, node_name, message_traits::TypeName<T*>().value(), false);
    completePubInit = true;
    Publisher pub;
    pub.topic_name = node_name;
    return pub;
}

void init(int argc, char *argv)
{
    sys_thread_new("mROS2Thread", mros2_init, NULL, 1000, 24); //TODO: fix this
}

void spin()
{
    while(true){
        slp_tsk();
    }
}

//Callback function to set the boolean to true upon a match
void setTrue(void* args){
	*static_cast<volatile bool*>(args) = true;
}

void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange){
	syslog(LOG_NOTICE, "recv message");
}

void mros2_init(void *args)
{
    static rtps::Domain domain;
    domain_ptr = &domain;
	syslog(LOG_NOTICE, "mROS2 init start");
    while(!completeSubInit || !completePubInit){tslp_tsk(100000);}
//    domain.completeInit();
//    syslog(LOG_NOTICE,"mROS2 RTPS init complete ");
//    ext_tsk();
	//Initialize variables and complete RTPS initialization
    
	 bool subMatched = false;
	 bool pubMatched = false;
	 bool received_message = false;

	 //Register callback to ensure that a publisher is matched to the writer before sending messages
	 part_ptr->registerOnNewPublisherMatchedCallback(setTrue, &pubMatched);
	 part_ptr->registerOnNewSubscriberMatchedCallback(setTrue, &subMatched);

	 //Create new writer to send messages
	 //rtps::Writer* writer = domain.createWriter(*part_ptr, "TOLINUX","TEST", false);
	 //rtps::Reader* reader = domain.createReader(*part, "TOSTM",  "TEST", false);
	 //reader->registerCallback(&message_callback, writer);

	 domain.completeInit();

	 //Check that writer creation was successful
	 //if(writer == nullptr || reader == nullptr){
	 //	return;
	 //}
	 syslog(LOG_NOTICE, "mROS2 init complete");
	 //Wait for the subscriber on the Linux side to match
	 while(!subMatched || !pubMatched){
	 	tslp_tsk(1000000);
	 	//BSP_LED_Toggle(LED3);
	 }

	 //BSP_LED_On(LED1);
	 ext_tsk();
    while(true)
	{
		syslog(LOG_NOTICE,"hogehoge");
		tslp_tsk(1000000);
	}
}


}//namespace mros2

//specialize template functions
#include "TEST.hpp"

template mros2::Publisher mros2::Node::create_publisher<TEST>(char *node_name, int qos, int callback);
template mros2::Subscriber mros2::Node::create_subscription(char *node_name, int qos, void (*fp)(TEST*));

/*
void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange){
	rtps::Writer* writer = (rtps::Writer*) callee;
	static std::array<uint8_t,10> data{};
	data.fill(10);
	auto* change = writer->newChange(rtps::ChangeKind_t::ALIVE, data.data(), data.size());
}
*/
