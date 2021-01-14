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

void main_task(void)
{
	MX_LWIP_Init();
	mros2::init(NULL, NULL);
	BSP_LED_On(LED1);
	ext_tsk();
}

void
led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}
