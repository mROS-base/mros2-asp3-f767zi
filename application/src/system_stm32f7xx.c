#include "stm32f7xx_hal.h"
#include "lwip/opt.h"
#include "lwip/timeouts.h"
#include "lwip/tcpip.h"
#include "netif/ethernet.h"
#include "netif/etharp.h"
#include "ethernetif.h"


uint32_t SystemCoreClock = 16000000;
uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return SystemCoreClock;
}

extern ETH_HandleTypeDef EthHandle;
/**
  * @brief  This function handles Ethernet interrupt request.
  * @param  None
  * @retval None
  */
void ETH_IRQHandler(void)
{
  HAL_ETH_IRQHandler(&EthHandle);
}

