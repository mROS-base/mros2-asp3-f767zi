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

#include "GPIO.h"

#include "mros2.h"

// To avoid link error
void* __dso_handle=0;

void startRTPStest();

void *networkSubDriverPtr;
void *networkPubDriverPtr;
void (*hbPubFuncPtr)(void *);
void (*hbSubFuncPtr)(void *);

extern "C" void callHbPubFunc(void *arg)
{
	if(hbPubFuncPtr != NULL && networkPubDriverPtr != NULL)
	{
		(*hbPubFuncPtr)(networkPubDriverPtr);
	}
}
extern "C" void callHbSubFunc(void *arg)
{
	if(hbSubFuncPtr != NULL && networkSubDriverPtr != NULL)
	{
		(*hbSubFuncPtr)(networkSubDriverPtr);
	}
}

void setTrue(void* args){
	*static_cast<volatile bool*>(args) = true;
}

void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange){
	rtps::Writer* writer = (rtps::Writer*) callee;
	static std::array<uint8_t,10> data{};
	data.fill(10);
	auto* change = writer->newChange(rtps::ChangeKind_t::ALIVE, data.data(), data.size());
}

void main_task(void)
{
	MX_LWIP_Init();
	mros2::init(NULL, NULL);
	mros2::Node node = mros2::Node::create_node();
	node.create_subscription("TOSTM", NULL, NULL);

}

void
led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}
