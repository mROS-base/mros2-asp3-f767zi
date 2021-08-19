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

// To avoid link error
void* __dso_handle=0;

void startRTPStest();

void *networkSubDriverPtr;
void *networkPubDriverPtr;
void (*hbPubFuncPtr)(void *);
void (*hbSubFuncPtr)(void *);

extern "C" void callHbPubFunc(void *arg)
{
  if(hbPubFuncPtr != NULL && networkPubDriverPtr != NULL) {
    (*hbPubFuncPtr)(networkPubDriverPtr);
  }
}
extern "C" void callHbSubFunc(void *arg)
{
  if(hbSubFuncPtr != NULL && networkSubDriverPtr != NULL) {
    (*hbSubFuncPtr)(networkSubDriverPtr);
  }
}

void main_task(void)
{
  osThreadAttr_t attributes;
  memset(&attributes, 0x0, sizeof(osThreadAttr_t));
  attributes.name = "UserDefaultTask";
  attributes.stack_size = 250;
  attributes.priority = osPriorityRealtime;
  osThreadNew(StartDefaultTask, NULL, &attributes);
}

//Callback function to set the boolean to true upon a match
void setPubTrue(void* args)
{
  *static_cast<volatile bool*>(args) = true;
}
void setSubTrue(void* args)
{
  *static_cast<volatile bool*>(args) = true;
}

void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange)
{
  /*
  rtps::Writer* writer = (rtps::Writer*) callee;
  static std::array<uint8_t,10> data{};
  data.fill(10);
  auto* change = writer->newChange(rtps::ChangeKind_t::ALIVE, data.data(), data.size());
  */
  syslog(LOG_NOTICE, "recv");
}

void StartDefaultTask(void *argument)
{
  /* init code for LWIP */
  MX_LWIP_Init();

  startRTPStest();

  /* TODO: check whether the task with rtps::Domain would be exited */
  /*
  while(1){
  	osDelay(1000);
  	BSP_LED_Toggle(LED1);
  }
  */
  BSP_LED_On(LED1);
}

//Function to start the RTPS Test
void startRTPStest()
{
  syslog(LOG_NOTICE, "starting RTPS test");
  //Initialize variables and complete RTPS initialization
  bool subMatched = false;
  bool pubMatched = false;
  bool received_message = false;

  static rtps::Domain domain;

  //Create RTPS participant
  rtps::Participant* part = domain.createParticipant();
  if(part == nullptr) {
    return;
  }

  //Register callback to ensure that a publisher is matched to the writer before sending messages
  part->registerOnNewPublisherMatchedCallback(setPubTrue, &pubMatched);
  part->registerOnNewSubscriberMatchedCallback(setSubTrue, &subMatched);

  //Create new writer to send messages
  rtps::Writer* writer = domain.createWriter(*part, "TOLINUX","TEST", false);
  rtps::Reader* reader = domain.createReader(*part, "TOSTM",  "TEST", false);
  reader->registerCallback(&message_callback, writer);

  domain.completeInit();

  //Check that writer creation was successful
  if(writer == nullptr || reader == nullptr) {
    return;
  }

  //Wait for the subscriber on the Linux side to match
  while(!subMatched || !pubMatched) {
    osDelay(100);
    BSP_LED_Toggle(LED3);
  }
  BSP_LED_Off(LED3);
}

void
led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}
