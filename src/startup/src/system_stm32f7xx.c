#include "stm32f7xx_hal.h"
#include "lwip/opt.h"
#include "lwip/timeouts.h"
#include "lwip/tcpip.h"
#include "netif/ethernet.h"
#include "netif/etharp.h"
#include "ethernetif.h"


uint32_t SystemCoreClock = 16000000;
//uint32_t HAL_RCC_GetHCLKFreq(void)
//{
//  return SystemCoreClock;
//}
  const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
  const uint8_t APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4};


