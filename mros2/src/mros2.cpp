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

namespace mros2 {

void init(int argc, char *argv)
{
	syslog(LOG_NOTICE, "mROS2 init start");
    //Initialize variables and complete RTPS initialization
    bool subMatched = false;
    bool pubMatched = false;
    bool received_message = false;

    static rtps::Domain domain;

    //Create RTPS participant
    rtps::Participant* part = domain.createParticipant();
    if(part == nullptr){
        return;
    }

    //Register callback to ensure that a publisher is matched to the writer before sending messages
    part->registerOnNewPublisherMatchedCallback(setTrue, &pubMatched);
    part->registerOnNewSubscriberMatchedCallback(setTrue, &subMatched);

    //Create new writer to send messages
    rtps::Writer* writer = domain.createWriter(*part, "TOLINUX","TEST", false);
    rtps::Reader* reader = domain.createReader(*part, "TOSTM",  "TEST", false);
    reader->registerCallback(&message_callback, writer);

    domain.completeInit();

    //Check that writer creation was successful
    if(writer == nullptr || reader == nullptr){
        return;
    }
    syslog(LOG_NOTICE, "mROS2 init complete");
    //Wait for the subscriber on the Linux side to match
    while(!subMatched || !pubMatched){
    tslp_tsk(1000000);
    //BSP_LED_Toggle(LED3);
    }
}

//Callback function to set the boolean to true upon a match
void setTrue(void* args){
	*static_cast<volatile bool*>(args) = true;
}

void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange){
	rtps::Writer* writer = (rtps::Writer*) callee;
	static std::array<uint8_t,10> data{};
	data.fill(10);
	auto* change = writer->newChange(rtps::ChangeKind_t::ALIVE, data.data(), data.size());
}

}//namespace mros2
