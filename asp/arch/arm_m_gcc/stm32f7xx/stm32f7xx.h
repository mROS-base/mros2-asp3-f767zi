/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2019 by TOPPERS PROJECT Educational Working Group.
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: stm32f7xx.h,v 1.4 2019/06/28 22:49:38 roi Exp $
 */

#ifndef _STM32F7XX_H_
#define _STM32F7XX_H_

/*
 *  Cortex-M7プロセッサとコアペイフェラル設定
 */
#include <sil.h>
#define __NVIC_PRIO_BITS    4		/* CM7 uses 4 Bits for the Priority Levels       */
#include "cmsis_f7.h"				/* Cortex-M7 processor and core peripherals      */

/*
 *  割込み番号の最大値
 */
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
#define TMAX_INTNO          (16 + 109)
#elif defined(TOPPERS_STM32F723_DISCOVERY)
#define TMAX_INTNO          (16 + 103)
#else
#define TMAX_INTNO          (16 + 98)
#endif

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG             (16 + 0)	/* Window WatchDog Interrupt */
#define IRQ_VECTOR_PVD              (16 + 1)	/* PVD through EXTI Line detection Interrupt */
#define IRQ_VECTOR_TAMP_STAMP       (16 + 2)	/* Tamper and TimeStamp interrupts through the EXTI line */
#define IRQ_VECTOR_RTC_WKUP         (16 + 3)	/* RTC Wakeup interrupt through the EXTI line */
#define IRQ_VECTOR_FLASH            (16 + 4)	/* FLASH global Interrupt */
#define IRQ_VECTOR_RCC              (16 + 5)	/* RCC global Interrupt */
#define IRQ_VECTOR_EXTI0            (16 + 6)	/* EXTI Line0 Interrupt */
#define IRQ_VECTOR_EXTI1            (16 + 7)	/* EXTI Line1 Interrupt */
#define IRQ_VECTOR_EXTI2            (16 + 8)	/* EXTI Line2 Interrupt */
#define IRQ_VECTOR_EXTI3            (16 + 9)	/* EXTI Line3 Interrupt */
#define IRQ_VECTOR_EXTI4            (16 + 10)	/* EXTI Line4 Interrupt */
#define IRQ_VECTOR_DMA1_STREAM0     (16 + 11)	/* DMA1 Stream 0 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM1     (16 + 12)	/* DMA1 Stream 1 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM2     (16 + 13)	/* DMA1 Stream 2 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM3     (16 + 14)	/* DMA1 Stream 3 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM4     (16 + 15)	/* DMA1 Stream 4 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM5     (16 + 16)	/* DMA1 Stream 5 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM6     (16 + 17)	/* DMA1 Stream 6 global Interrupt */
#define IRQ_VECTOR_ADC              (16 + 18)	/* ADC1, ADC2 and ADC3 global Interrupts */
#define IRQ_VECTOR_CAN1_TX          (16 + 19)	/* CAN1 TX Interrupt */
#define IRQ_VECTOR_CAN1_RX0         (16 + 20)	/* CAN1 RX0 Interrupt */
#define IRQ_VECTOR_CAN1_RX1         (16 + 21)	/* CAN1 RX1 Interrupt */
#define IRQ_VECTOR_CAN1_SCE         (16 + 22)	/* CAN1 SCE Interrupt */
#define IRQ_VECTOR_EXTI9_5          (16 + 23)	/* External Line[9:5] Interrupts */
#define IRQ_VECTOR_TIM1_BRK_TIM9    (16 + 24)	/* TIM1 Break interrupt and TIM9 global interrupt */
#define IRQ_VECTOR_TIM1_UP_TIM10    (16 + 25)	/* TIM1 Update Interrupt and TIM10 global interrupt */
#define IRQ_VECTOR_TIM1_TRG_COM_TIM11 (16+26)	/* TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
#define IRQ_VECTOR_TIM1_CC          (16 + 27)	/* TIM1 Capture Compare Interrupt */
#define IRQ_VECTOR_TIM2             (16 + 28)	/* TIM2 global Interrupt */
#define IRQ_VECTOR_TIM3             (16 + 29)	/* TIM3 global Interrupt */
#define IRQ_VECTOR_TIM4             (16 + 30)	/* TIM4 global Interrupt */
#define IRQ_VECTOR_I2C1_EV          (16 + 31)	/* I2C1 Event Interrupt */
#define IRQ_VECTOR_I2C1_ER          (16 + 32)	/* I2C1 Error Interrupt */
#define IRQ_VECTOR_I2C2_EV          (16 + 33)	/* I2C2 Event Interrupt */
#define IRQ_VECTOR_I2C2_ER          (16 + 34)	/* I2C2 Error Interrupt */
#define IRQ_VECTOR_SPI1             (16 + 35)	/* SPI1 global Interrupt */
#define IRQ_VECTOR_SPI2             (16 + 36)	/* SPI2 global Interrupt */
#define IRQ_VECTOR_USART1           (16 + 37)	/* USART1 global Interrupt */
#define IRQ_VECTOR_USART2           (16 + 38)	/* USART2 global Interrupt */
#define IRQ_VECTOR_USART3           (16 + 39)	/* USART3 global Interrupt */
#define IRQ_VECTOR_EXTI15_10        (16 + 40)	/* External Line[15:10] Interrupts */
#define IRQ_VECTOR_RTC_ALARM        (16 + 41)	/* RTC Alarm (A and B) through EXTI Line Interrupt */
#define IRQ_VECTOR_OTG_FS_WKUP      (16 + 42)	/* USB OTG FS Wakeup through EXTI line interrupt */
#define IRQ_VECTOR_TIM8_BRK_TIM12   (16 + 43)	/* TIM8 Break Interrupt and TIM12 global interrupt */
#define IRQ_VECTOR_TIM8_UP_TIM13    (16 + 44)	/* TIM8 Update Interrupt and TIM13 global interrupt */
#define IRQ_VECTOR_TIM8_TRG_COM_TIM14 (16+45)	/* TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
#define IRQ_VECTOR_TIM8_CC          (16 + 46)	/* TIM8 Capture Compare Interrupt */
#define IRQ_VECTOR_DMA1_STREAM7     (16 + 47)	/* DMA1 Stream7 Interrupt */
#define IRQ_VECTOR_FMC              (16 + 48)	/* FMC global Interrupt */
#define IRQ_VECTOR_SDMMC            (16 + 49)	/* SDMMC global Interrupt */
#define IRQ_VECTOR_TIM5             (16 + 50)	/* TIM5 global Interrupt */
#define IRQ_VECTOR_SPI3             (16 + 51)	/* SPI3 global Interrupt */
#define IRQ_VECTOR_UART4            (16 + 52)	/* UART4 global Interrupt */
#define IRQ_VECTOR_UART5            (16 + 53)	/* UART5 global Interrupt */
#define IRQ_VECTOR_TIM6_DAC         (16 + 54)	/* TIM6 global and DAC1&2 underrun error interrupts */
#define IRQ_VECTOR_TIM7             (16 + 55)	/* TIM7 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM0     (16 + 56)	/* DMA2 Stream 0 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM1     (16 + 57)	/* DMA2 Stream 1 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM2     (16 + 58)	/* DMA2 Stream 2 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM3     (16 + 59)	/* DMA2 Stream 3 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM4     (16 + 60)	/* DMA2 Stream 4 global Interrupt */
#define IRQ_VECTOR_ETH              (16 + 61)	/* Ethernet global Interrupt */
#define IRQ_VECTOR_ETH_WKUP         (16 + 62)	/* Ethernet Wakeup through EXTI line Interrupt */
#define IRQ_VECTOR_CAN2_TX          (16 + 63)	/* CAN2 TX Interrupt */
#define IRQ_VECTOR_CAN2_RX0         (16 + 64)	/* CAN2 RX0 Interrupt */
#define IRQ_VECTOR_CAN2_RX1         (16 + 65)	/* CAN2 RX1 Interrupt */
#define IRQ_VECTOR_CAN2_SCE         (16 + 66)	/* CAN2 SCE Interrupt */
#define IRQ_VECTOR_OTG_FS           (16 + 67)	/* USB OTG FS global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM5     (16 + 68)	/* DMA2 Stream 5 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM6     (16 + 69)	/* DMA2 Stream 6 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM7     (16 + 70)	/* DMA2 Stream 7 global interrupt */
#define IRQ_VECTOR_USART6           (16 + 71)	/* USART6 global interrupt */
#define IRQ_VECTOR_I2C3_EV          (16 + 72)	/* I2C3 event interrupt */
#define IRQ_VECTOR_I2C3_ER          (16 + 73)	/* I2C3 error interrupt */
#define IRQ_VECTOR_OTG_HS_EP1_OUT   (16 + 74)	/* USB OTG HS End Point 1 Out global interrupt */
#define IRQ_VECTOR_OTG_HS_EP1_IN    (16 + 75)	/* USB OTG HS End Point 1 In global interrupt */
#define IRQ_VECTOR_OTG_HS_WKUP      (16 + 76)	/* USB OTG HS Wakeup through EXTI interrupt */
#define IRQ_VECTOR_OTG_HS           (16 + 77)	/* USB OTG HS global interrupt */
#define IRQ_VECTOR_DCMI             (16 + 78)	/* DCMI global interrupt */
#define IRQ_VECTOR_CRYP             (16 + 79)	/* CRYP crypto global interrupt */
#define IRQ_VECTOR_HASH_RNG         (16 + 80)	/* Hash and Rng global interrupt */
#define IRQ_VECTOR_FPU              (16 + 81)	/* FPU global interrupt */
#define IRQ_VECTOR_UART7            (16 + 82)	/* UART7 global interrupt */
#define IRQ_VECTOR_UART8            (16 + 83)	/* UART8 global interrupt */
#define IRQ_VECTOR_SPI4             (16 + 84)	/* SPI4 global Interrupt */
#define IRQ_VECTOR_SPI5             (16 + 85)	/* SPI5 global Interrupt */
#define IRQ_VECTOR_SPI6             (16 + 86)	/* SPI6 global Interrupt */
#define IRQ_VECTOR_SAI1             (16 + 87)	/* SAI1 global Interrupt */
#define IRQ_VECTOR_LTDC             (16 + 88)	/* LTDC global Interrupt */
#define IRQ_VECTOR_LTDC_ER          (16 + 89)	/* LTDC Error global Interrupt */
#define IRQ_VECTOR_DMA2D            (16 + 90)	/* DMA2D global Interrupt */
#define IRQ_VECTOR_SAI2             (16 + 91)	/* SAI2 global Interrupt */
#define IRQ_VECTOR_QUADSPI          (16 + 92)	/* Quad SPI global interrupt */
#define IRQ_VECTOR_LPTIM1           (16 + 93)	/* LP TIM1 interrupt */
#if defined(TOPPERS_STM32F723_DISCOVERY)
#define IRQ_VECTOR_SDMMC2           (16 + 103)	/* SDMMC2 global Interrupt */
#else
#define IRQ_VECTOR_CEC              (16 + 94)	/* HDMI-CEC global Interrupt */
#define IRQ_VECTOR_I2C4_EV          (16 + 95)	/* I2C4 Event Interrupt */
#define IRQ_VECTOR_I2C4_ER          (16 + 96)	/* I2C4 Error Interrupt */
#define IRQ_VECTOR_SPDIF_RX         (16 + 97)	/* SPDIF-RX global Interrupt */
#endif
#if defined(TOPPERS_STM32F769_DISCOVERY)
#define IRQ_VECTOR_DSI              (16 + 98)	/* DSI global Interrupt */
#endif
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
#define IRQ_DFSDM1_FLT0	            (16 + 99)	/* DFSDM1 Filter 0 global Interrupt */
#define IRQ_DFSDM1_FLT1	            (16 + 100)	/* DFSDM1 Filter 1 global Interrupt */
#define IRQ_DFSDM1_FLT2	            (16 + 101)	/* DFSDM1 Filter 2 global Interrupt */
#define IRQ_DFSDM1_FLT3             (16 + 102)	/* DFSDM1 Filter 3 global Interrupt */
#define IRQ_VECTOR_SDMMC2           (16 + 103)	/* SDMMC2 global Interrupt */
#define IRQ_VECTOR_CAN3_TX          (16 + 104)	/* CAN3 TX Interrupt */
#define IRQ_VECTOR_CAN3_RX0         (16 + 105)	/* CAN3 RX0 Interrupt */
#define IRQ_VECTOR_CAN3_RX1         (16 + 106)	/* CAN3 RX1 Interrupt */
#define IRQ_VECTOR_CAN3_SCE         (16 + 107)	/* CAN3 SCE Interrupt */
#define IRQ_VECTOR_JPEG             (16 + 108)	/* JPEG global Interrupt */
#define IRQ_VECTOR_MDIOS            (16 + 109)	/* MDIO Slave global Interrupt */
#endif

/*
 *  PERIPHERAL MEMORY MAP
 */
#define RAMITCM_BASE        0x00000000	/* Base address of :16KB RAM reserved for CPU execution/instruction accessible over ITCM   */
#define FLASHITCM_BASE      0x00200000	/* Base address of :(up to 1 MB) embedded FLASH memory  accessible over ITCM               */                       
#define FLASHAXI_BASE       0x08000000	/* Base address of : (up to 1 MB) embedded FLASH memory accessible over AXI                */                       
#define RAMDTCM_BASE        0x20000000	/* Base address of : 64KB system data RAM accessible over DTCM                             */
#define SRAM1_BASE          0x20010000	/* Base address of : 240KB RAM1 accessible over AXI/AHB                                    */
#define SRAM2_BASE          0x2004C000	/* Base address of : 16KB RAM2 accessible over AXI/AHB                                     */
#define PERIPH_BASE         0x40000000	/* Base address of : AHB/ABP Peripherals                                                   */
#define BKPSRAM_BASE        0x40024000	/* Base address of : Backup SRAM(4 KB)                                                     */
#define QSPI_BASE           0x90000000	/* Base address of : QSPI memories  accessible over AXI                                    */
#define FMC_R_BASE          0xA0000000	/* Base address of : FMC Control registers                                                 */
#define QSPI_R_BASE         0xA0001000	/* Base address of : QSPI Control  registers                                               */
#define FLASH_END           0x080FFFFF	/* FLASH end address */

#define FLASH_BASE          FLASHAXI_BASE	/* FLASH(up to 1 MB) base address in the alias region                         */

/* Peripheral memory map */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x10000000)

/* USB registers base address */
#define USB_OTG_HS_PERIPH_BASE     0x40040000
#define USB_OTG_FS_PERIPH_BASE     0x50000000

#define USB_OTG_DEVICE_BASE         0x800
#define USB_OTG_IN_ENDPOINT_BASE    0x900
#define USB_OTG_OUT_ENDPOINT_BASE   0xB00
#define USB_OTG_HOST_BASE           0x400
#define USB_OTG_HOST_PORT_BASE      0x440
#define USB_OTG_HOST_CHANNEL_BASE   0x500
#define USB_OTG_PCGCCTL_BASE        0xE00
#define USB_OTG_FIFO_BASE           0x1000
#define USB_OTG_FIFO_SIZE           0x1000


/*
 *  TIM
 */
#define TADR_TIM2_BASE      (APB1PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (APB1PERIPH_BASE + 0x0400)
#define TADR_TIM4_BASE      (APB1PERIPH_BASE + 0x0800)
#define TADR_TIM5_BASE      (APB1PERIPH_BASE + 0x0C00)
#define TADR_TIM6_BASE      (APB1PERIPH_BASE + 0x1000)
#define TADR_TIM7_BASE      (APB1PERIPH_BASE + 0x1400)
#define TADR_TIM12_BASE     (APB1PERIPH_BASE + 0x1800)
#define TADR_TIM13_BASE     (APB1PERIPH_BASE + 0x1C00)
#define TADR_TIM14_BASE     (APB1PERIPH_BASE + 0x2000)
#define TADR_TIM1_BASE      (APB2PERIPH_BASE + 0x0000)
#define TADR_TIM8_BASE      (APB2PERIPH_BASE + 0x0400)
#define TADR_TIM9_BASE      (APB2PERIPH_BASE + 0x4000)
#define TADR_TIM10_BASE     (APB2PERIPH_BASE + 0x4400)
#define TADR_TIM11_BASE     (APB2PERIPH_BASE + 0x4800)
#define TOFF_TIM_CR1        0x0000		/* (RW) TIM control register 1 */
  #define TIM_CR1_CEN        0x0001		/* Counter enable */
  #define TIM_CR1_UDIS       0x0002		/* Update disable */
  #define TIM_CR1_URS        0x0004		/* Update request source */
  #define TIM_CR1_OPM        0x0008		/* One pulse mode */
  #define TIM_CR1_DIR        0x0010		/* Direction */
  #define TIM_CR1_CMS_0      0x0020		/* CMS[1:0] bit 0 */
  #define TIM_CR1_CMS_1      0x0040		/* CMS[1:0] bit 1 */
  #define TIM_CR1_ARPE       0x0080		/* Auto-reload preload enable */
  #define TIM_CR1_CKD_0      0x0100		/* CKD[1:0] bit 0 */
  #define TIM_CR1_CKD_1      0x0200		/* CKD[1:0] bit 1 */
  #define TIM_CR1_UIFREMAP   0x0800		/* UIF status bit */
#define TOFF_TIM_CR2        0x0004		/* (RW) TIM control register 2 */
  #define TIM_CR2_CCPC       0x00000001	/* Capture/Compare Preloaded Control        */
  #define TIM_CR2_CCUS       0x00000004	/* Capture/Compare Control Update Selection */
  #define TIM_CR2_CCDS       0x00000008	/* Capture/Compare DMA Selection            */
  #define TIM_CR2_OIS5       0x00010000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_OIS6       0x00040000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_MMS        0x0070		/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS_0      0x0010		/* Bit 0 */
  #define TIM_CR2_MMS_1      0x0020		/* Bit 1 */
  #define TIM_CR2_MMS_2      0x0040		/* Bit 2 */
  #define TIM_CR2_MMS2       0x00F00000	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS2_0     0x00100000	/* Bit 0 */
  #define TIM_CR2_MMS2_1     0x00200000	/* Bit 1 */
  #define TIM_CR2_MMS2_2     0x00400000	/* Bit 2 */
  #define TIM_CR2_MMS2_3     0x00800000	/* Bit 2 */
  #define TIM_CR2_TI1S       0x0080		/* TI1 Selection */
  #define TIM_CR2_OIS1       0x0100		/* Output Idle state 1 (OC1 output)  */
  #define TIM_CR2_OIS1N      0x0200		/* Output Idle state 1 (OC1N output) */
  #define TIM_CR2_OIS2       0x0400		/* Output Idle state 2 (OC2 output)  */
  #define TIM_CR2_OIS2N      0x0800		/* Output Idle state 2 (OC2N output) */
  #define TIM_CR2_OIS3       0x1000		/* Output Idle state 3 (OC3 output)  */
  #define TIM_CR2_OIS3N      0x2000		/* Output Idle state 3 (OC3N output) */
  #define TIM_CR2_OIS4       0x4000		/* Output Idle state 4 (OC4 output)  */
#define TOFF_TIM_SMCR       0x0008		/* (RW) TIM slave mode control register */
  #define TIM_SMCR_SMS       0x00010007	/* SMS[2:0] bits (Slave mode selection)    */
  #define TIM_SMCR_SMS_0     0x00000001	/* Bit 0 */
  #define TIM_SMCR_SMS_1     0x00000002	/* Bit 1 */
  #define TIM_SMCR_SMS_2     0x00000004	/* Bit 2 */
  #define TIM_SMCR_SMS_3     0x00010000	/* Bit 3 */
  #define TIM_SMCR_OCCS      0x00000008	/* OCREF clear selection */
  #define TIM_SMCR_TS        0x0070		/* TS[2:0] bits (Trigger selection)        */
  #define TIM_SMCR_TS_0      0x0010		/* Bit 0 */
  #define TIM_SMCR_TS_1      0x0020		/* Bit 1 */
  #define TIM_SMCR_TS_2      0x0040		/* Bit 2 */
  #define TIM_SMCR_MSM       0x0080		/* Master/slave mode                       */
  #define TIM_SMCR_ETF       0x0F00		/* ETF[3:0] bits (External trigger filter) */
  #define TIM_SMCR_ETF_0     0x0100		/* Bit 0 */
  #define TIM_SMCR_ETF_1     0x0200		/* Bit 1 */
  #define TIM_SMCR_ETF_2     0x0400		/* Bit 2 */
  #define TIM_SMCR_ETF_3     0x0800		/* Bit 3 */
  #define TIM_SMCR_ETPS      0x3000		/* ETPS[1:0] bits (External trigger prescaler) */
  #define TIM_SMCR_ETPS_0    0x1000		/* Bit 0 */
  #define TIM_SMCR_ETPS_1    0x2000		/* Bit 1 */
  #define TIM_SMCR_ECE       0x4000		/* External clock enable     */
  #define TIM_SMCR_ETP       0x8000		/* External trigger polarity */
#define TOFF_TIM_DIER       0x000C		/* (RW) TIM DMA/interrupt enable register */
  #define TIM_DIER_UIE       0x0001		/* Update interrupt enable */
  #define TIM_DIER_CC1IE     0x0002		/* Capture/Compare 1 interrupt enable */
  #define TIM_DIER_CC2IE     0x0004		/* Capture/Compare 2 interrupt enable */
  #define TIM_DIER_CC3IE     0x0008		/* Capture/Compare 3 interrupt enable */
  #define TIM_DIER_CC4IE     0x0010		/* Capture/Compare 4 interrupt enable */
  #define TIM_DIER_COMIE     0x0020		/* COM interrupt enable */
  #define TIM_DIER_TIE       0x0040		/* Trigger interrupt enable */
  #define TIM_DIER_BIE       0x0080		/* Break interrupt enable */
  #define TIM_DIER_UDE       0x0100		/* Update DMA request enable */
  #define TIM_DIER_CC1DE     0x0200		/* Capture/Compare 1 DMA request enable */
  #define TIM_DIER_CC2DE     0x0400		/* Capture/Compare 2 DMA request enable */
  #define TIM_DIER_CC3DE     0x0800		/* Capture/Compare 3 DMA request enable */
  #define TIM_DIER_CC4DE     0x1000		/* Capture/Compare 4 DMA request enable */
  #define TIM_DIER_COMDE     0x2000		/* COM DMA request enable */
  #define TIM_DIER_TDE       0x4000		/* Trigger DMA request enable */
#define TOFF_TIM_SR         0x0010		/* (RW) TIM status register */
  #define TIM_SR_UIF         0x0001		/* Update interrupt Flag */
  #define TIM_SR_CC1IF       0x0002		/* Capture/Compare 1 interrupt Flag */
  #define TIM_SR_CC2IF       0x0004		/* Capture/Compare 2 interrupt Flag */
  #define TIM_SR_CC3IF       0x0008		/* Capture/Compare 3 interrupt Flag */
  #define TIM_SR_CC4IF       0x0010		/* Capture/Compare 4 interrupt Flag */
  #define TIM_SR_COMIF       0x0020		/* COM interrupt Flag */
  #define TIM_SR_TIF         0x0040		/* Trigger interrupt Flag */
  #define TIM_SR_BIF         0x0080		/* Break interrupt Flag */
  #define TIM_SR_CC1OF       0x0200		/* Capture/Compare 1 Overcapture Flag */
  #define TIM_SR_CC2OF       0x0400		/* Capture/Compare 2 Overcapture Flag */
  #define TIM_SR_CC3OF       0x0800		/* Capture/Compare 3 Overcapture Flag */
  #define TIM_SR_CC4OF       0x1000		/* Capture/Compare 4 Overcapture Flag */
#define TOFF_TIM_EGR        0x0014		/* (RW) TIM event generation register */
  #define TIM_EGR_UG         0x00000001	/* Update Generation */
  #define TIM_EGR_CC1G       0x00000002	/* Capture/Compare 1 Generation */
  #define TIM_EGR_CC2G       0x00000004	/* Capture/Compare 2 Generation */
  #define TIM_EGR_CC3G       0x00000008	/* Capture/Compare 3 Generation */
  #define TIM_EGR_CC4G       0x00000010	/* Capture/Compare 4 Generation              */
  #define TIM_EGR_COMG       0x00000020	/* Capture/Compare Control Update Generation */
  #define TIM_EGR_TG         0x00000040	/* Trigger Generation */
  #define TIM_EGR_BG         0x00000080	/* Break Generation */
  #define TIM_EGR_B2G        0x00000100	/* Break2 Generation */
#define TOFF_TIM_CCMR1      0x0018		/* (RW) TIM capture/compare mode register 1 */
  #define TIM_CCMR1_CC1S     0x00000003	/* CC1S[1:0] bits (Capture/Compare 1 Selection) */
  #define TIM_CCMR1_CC1S_0   0x00000001	/* Bit 0 */
  #define TIM_CCMR1_CC1S_1   0x00000002	/* Bit 1 */
  #define TIM_CCMR1_OC1FE    0x00000004	/* Output Compare 1 Fast enable                 */
  #define TIM_CCMR1_OC1PE    0x00000008	/* Output Compare 1 Preload enable              */
  #define TIM_CCMR1_OC1M     0x00010070	/* OC1M[2:0] bits (Output Compare 1 Mode)       */
  #define TIM_CCMR1_OC1M_0   0x00000010	/* Bit 0 */
  #define TIM_CCMR1_OC1M_1   0x00000020	/* Bit 1 */
  #define TIM_CCMR1_OC1M_2   0x00000040	/* Bit 2 */
  #define TIM_CCMR1_OC1M_3   0x00010000	/* Bit 3 */
  #define TIM_CCMR1_OC1CE    0x00000080	/* Output Compare 1Clear Enable                 */
  #define TIM_CCMR1_CC2S     0x00000300	/* CC2S[1:0] bits (Capture/Compare 2 Selection) */
  #define TIM_CCMR1_CC2S_0   0x00000100	/* Bit 0 */
  #define TIM_CCMR1_CC2S_1   0x00000200	/* Bit 1 */
  #define TIM_CCMR1_OC2FE    0x00000400	/* Output Compare 2 Fast enable                 */
  #define TIM_CCMR1_OC2PE    0x00000800	/* Output Compare 2 Preload enable              */
  #define TIM_CCMR1_OC2M     0x01007000	/* OC2M[2:0] bits (Output Compare 2 Mode)       */
  #define TIM_CCMR1_OC2M_0   0x00001000	/* Bit 0 */
  #define TIM_CCMR1_OC2M_1   0x00002000	/* Bit 1 */
  #define TIM_CCMR1_OC2M_2   0x00004000	/* Bit 2 */
  #define TIM_CCMR1_OC2M_3   0x01000000	/* Bit 3 */
  #define TIM_CCMR1_IC1PSC   0x000C		/* IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
  #define TIM_CCMR1_IC1PSC_0 0x0004		/* Bit 0 */
  #define TIM_CCMR1_IC1PSC_1 0x0008		/* Bit 1 */
  #define TIM_CCMR1_IC1F     0x00F0		/* IC1F[3:0] bits (Input Capture 1 Filter)      */
  #define TIM_CCMR1_IC1F_0   0x0010		/* Bit 0 */
  #define TIM_CCMR1_IC1F_1   0x0020		/* Bit 1 */
  #define TIM_CCMR1_IC1F_2   0x0040		/* Bit 2 */
  #define TIM_CCMR1_IC1F_3   0x0080		/* Bit 3 */
  #define TIM_CCMR1_IC2PSC   0x0C00		/* IC2PSC[1:0] bits (Input Capture 2 Prescaler)  */
  #define TIM_CCMR1_IC2PSC_0 0x0400		/* Bit 0 */
  #define TIM_CCMR1_IC2PSC_1 0x0800		/* Bit 1 */
  #define TIM_CCMR1_IC2F     0xF000		/* IC2F[3:0] bits (Input Capture 2 Filter)       */
  #define TIM_CCMR1_IC2F_0   0x1000		/* Bit 0 */
  #define TIM_CCMR1_IC2F_1   0x2000		/* Bit 1 */
  #define TIM_CCMR1_IC2F_2   0x4000		/* Bit 2 */
  #define TIM_CCMR1_IC2F_3   0x8000		/* Bit 3 */
  #define TIM_CCMR1_OC2CE    0x00008000	/* Output Compare 2 Clear Enable */
#define TOFF_TIM_CCMR2      0x001C		/* (RW) TIM capture/compare mode register 2 */
  #define TIM_CCMR2_CC3S     0x00000003	/* CC3S[1:0] bits (Capture/Compare 3 Selection)  */
  #define TIM_CCMR2_CC3S_0   0x00000001	/* Bit 0 */
  #define TIM_CCMR2_CC3S_1   0x00000002	/* Bit 1 */
  #define TIM_CCMR2_OC3FE    0x00000004	/* Output Compare 3 Fast enable           */
  #define TIM_CCMR2_OC3PE    0x00000008	/* Output Compare 3 Preload enable        */
  #define TIM_CCMR2_OC3M     0x00010070	/* OC3M[2:0] bits (Output Compare 3 Mode) */
  #define TIM_CCMR2_OC3M_0   0x00000010	/* Bit 0 */
  #define TIM_CCMR2_OC3M_1   0x00000020	/* Bit 1 */
  #define TIM_CCMR2_OC3M_2   0x00000040	/* Bit 2 */
  #define TIM_CCMR2_OC3M_3   0x00010000	/* Bit 3 */
  #define TIM_CCMR2_OC3CE    0x00000080	/* Output Compare 3 Clear Enable */
  #define TIM_CCMR2_CC4S     0x00000300	/* CC4S[1:0] bits (Capture/Compare 4 Selection) */
  #define TIM_CCMR2_CC4S_0   0x00000100	/* Bit 0 */
  #define TIM_CCMR2_CC4S_1   0x00000200	/* Bit 1 */
  #define TIM_CCMR2_OC4FE    0x00000400	/* Output Compare 4 Fast enable    */
  #define TIM_CCMR2_OC4PE    0x00000800	/* Output Compare 4 Preload enable */
  #define TIM_CCMR2_OC4M     0x01007000	/* OC4M[2:0] bits (Output Compare 4 Mode) */
  #define TIM_CCMR2_OC4M_0   0x00001000	/* Bit 0 */
  #define TIM_CCMR2_OC4M_1   0x00002000	/* Bit 1 */
  #define TIM_CCMR2_OC4M_2   0x00004000	/* Bit 2 */
  #define TIM_CCMR2_OC4M_3   0x01000000	/* Bit 3 */
  #define TIM_CCMR2_OC4CE    0x8000		/* Output Compare 4 Clear Enable */
  #define TIM_CCMR2_IC3PSC   0x000C		/* IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
  #define TIM_CCMR2_IC3PSC_0 0x0004		/* Bit 0 */
  #define TIM_CCMR2_IC3PSC_1 0x0008		/* Bit 1 */
  #define TIM_CCMR2_IC3F     0x00F0		/* IC3F[3:0] bits (Input Capture 3 Filter) */
  #define TIM_CCMR2_IC3F_0   0x0010		/* Bit 0 */
  #define TIM_CCMR2_IC3F_1   0x0020		/* Bit 1 */
  #define TIM_CCMR2_IC3F_2   0x0040		/* Bit 2 */
  #define TIM_CCMR2_IC3F_3   0x0080		/* Bit 3 */
  #define TIM_CCMR2_IC4PSC   0x0C00		/* IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
  #define TIM_CCMR2_IC4PSC_0 0x0400		/* Bit 0 */
  #define TIM_CCMR2_IC4PSC_1 0x0800		/* Bit 1 */
  #define TIM_CCMR2_IC4F     0xF000		/* IC4F[3:0] bits (Input Capture 4 Filter) */
  #define TIM_CCMR2_IC4F_0   0x1000		/* Bit 0 */
  #define TIM_CCMR2_IC4F_1   0x2000		/* Bit 1 */
  #define TIM_CCMR2_IC4F_2   0x4000		/* Bit 2 */
  #define TIM_CCMR2_IC4F_3   0x8000		/* Bit 3 */
#define TOFF_TIM_CCER       0x0020		/* (RW) TIM capture/compare enable register */
  #define TIM_CCER_CC1E      0x00000001	/* Capture/Compare 1 output enable */
  #define TIM_CCER_CC1P      0x00000002	/* Capture/Compare 1 output Polarity */
  #define TIM_CCER_CC1NE     0x00000004	/* Capture/Compare 1 Complementary output enable */
  #define TIM_CCER_CC1NP     0x00000008	/* Capture/Compare 1 Complementary output Polarity */
  #define TIM_CCER_CC2E      0x00000010	/* Capture/Compare 2 output enable */
  #define TIM_CCER_CC2P      0x00000020	/* Capture/Compare 2 output Polarity */
  #define TIM_CCER_CC2NE     0x00000040	/* Capture/Compare 2 Complementary output enable */
  #define TIM_CCER_CC2NP     0x00000080	/* Capture/Compare 2 Complementary output Polarity */
  #define TIM_CCER_CC3E      0x00000100	/* Capture/Compare 3 output enable */
  #define TIM_CCER_CC3P      0x00000200	/* Capture/Compare 3 output Polarity */
  #define TIM_CCER_CC3NE     0x00000400	/* Capture/Compare 3 Complementary output enable */
  #define TIM_CCER_CC3NP     0x00000800	/* Capture/Compare 3 Complementary output Polarity */
  #define TIM_CCER_CC4E      0x00001000	/* Capture/Compare 4 output enable */
  #define TIM_CCER_CC4P      0x00002000	/* Capture/Compare 4 output Polarity */
  #define TIM_CCER_CC4NP     0x00008000	/* Capture/Compare 4 Complementary output Polarity */
  #define TIM_CCER_CC5E      0x00010000	/* Capture/Compare 5 output enable */
  #define TIM_CCER_CC5P      0x00020000	/* Capture/Compare 5 output Polarity */
  #define TIM_CCER_CC6E      0x00100000	/* Capture/Compare 6 output enable */
  #define TIM_CCER_CC6P      0x00200000	/* Capture/Compare 6 output Polarity */
#define TOFF_TIM_CNT        0x0024		/* (RW) TIM counter register */
#define TOFF_TIM_PSC        0x0028		/* (RW) TIM prescaler */
#define TOFF_TIM_ARR        0x002C		/* (RW) TIM auto-reload register */
#define TOFF_TIM_RCR        0x0030		/* (RW) TIM repetition counter register */
#define TOFF_TIM_CCR1       0x0034		/* (RW) TIM capture/compare register 1 */
#define TOFF_TIM_CCR2       0x0038		/* (RW) TIM capture/compare register 2 */
#define TOFF_TIM_CCR3       0x003C		/* (RW) TIM capture/compare register 3 */
#define TOFF_TIM_CCR4       0x0040		/* (RW) TIM capture/compare register 4 */
#define TOFF_TIM_BDTR       0x0044		/* (RW) TIM break and dead-time register */
  #define TIM_BDTR_DTG       0x000000FF	/* DTG[0:7] bits (Dead-Time Generator set-up) */
  #define TIM_BDTR_DTG_0     0x00000001	/* Bit 0 */
  #define TIM_BDTR_DTG_1     0x00000002	/* Bit 1 */
  #define TIM_BDTR_DTG_2     0x00000004	/* Bit 2 */
  #define TIM_BDTR_DTG_3     0x00000008	/* Bit 3 */
  #define TIM_BDTR_DTG_4     0x00000010	/* Bit 4 */
  #define TIM_BDTR_DTG_5     0x00000020	/* Bit 5 */
  #define TIM_BDTR_DTG_6     0x00000040	/* Bit 6 */
  #define TIM_BDTR_DTG_7     0x00000080	/* Bit 7 */
  #define TIM_BDTR_LOCK      0x00000300	/* LOCK[1:0] bits (Lock Configuration) */
  #define TIM_BDTR_LOCK_0    0x00000100	/* Bit 0 */
  #define TIM_BDTR_LOCK_1    0x00000200	/* Bit 1 */
  #define TIM_BDTR_OSSI      0x00000400	/* Off-State Selection for Idle mode */
  #define TIM_BDTR_OSSR      0x00000800	/* Off-State Selection for Run mode  */
  #define TIM_BDTR_BKE       0x00001000	/* Break enable                      */
  #define TIM_BDTR_BKP       0x00002000	/* Break Polarity                    */
  #define TIM_BDTR_AOE       0x00004000	/* Automatic Output enable           */
  #define TIM_BDTR_MOE       0x00008000	/* Main Output enable                */
  #define TIM_BDTR_BKF       0x000F0000	/* Break Filter for Break1 */
  #define TIM_BDTR_BK2F      0x00F00000	/* Break Filter for Break2 */
  #define TIM_BDTR_BK2E      0x01000000	/* Break enable for Break2 */
  #define TIM_BDTR_BK2P      0x02000000	/* Break Polarity for Break2 */
#define TOFF_TIM_DCR        0x0048		/* (RW) TIM DMA control register */
  #define TIM_DCR_DBA        0x001F		/* DBA[4:0] bits (DMA Base Address) */
  #define TIM_DCR_DBA_0      0x0001		/* Bit 0 */
  #define TIM_DCR_DBA_1      0x0002		/* Bit 1 */
  #define TIM_DCR_DBA_2      0x0004		/* Bit 2 */
  #define TIM_DCR_DBA_3      0x0008		/* Bit 3 */
  #define TIM_DCR_DBA_4      0x0010		/* Bit 4 */
  #define TIM_DCR_DBL        0x1F00		/* DBL[4:0] bits (DMA Burst Length) */
  #define TIM_DCR_DBL_0      0x0100		/* Bit 0 */
  #define TIM_DCR_DBL_1      0x0200		/* Bit 1 */
  #define TIM_DCR_DBL_2      0x0400		/* Bit 2 */
  #define TIM_DCR_DBL_3      0x0800		/* Bit 3 */
  #define TIM_DCR_DBL_4      0x1000		/* Bit 4 */
#define TOFF_TIM_DMAR       0x004C		/* (RW) TIM DMA address for full transfer */
#define TOFF_TIM_OR         0x0050		/* (RW) TIM option register */
  #define TIM_OR_TI4_RMP     0x00C0		/* TI4_RMP[1:0] bits (TIM5 Input 4 remap)             */
  #define TIM_OR_TI4_RMP_0   0x0040		/* Bit 0 */
  #define TIM_OR_TI4_RMP_1   0x0080		/* Bit 1 */
  #define TIM_OR_ITR1_RMP    0x0C00		/* ITR1_RMP[1:0] bits (TIM2 Internal trigger 1 remap) */
  #define TIM_OR_ITR1_RMP_0  0x0400		/* Bit 0 */
  #define TIM_OR_ITR1_RMP_1  0x0800		/* Bit 1 */
#define TOFF_TIM_CCMR3      0x0054		/* (RW) TIM capture/compare mode register 3 */
  #define TIM_CCMR3_OC5FE    0x00000004	/* Output Compare 5 Fast enable */
  #define TIM_CCMR3_OC5PE    0x00000008	/* Output Compare 5 Preload enable */
  #define TIM_CCMR3_OC5M     0x00010070	/* OC5M[2:0] bits (Output Compare 5 Mode) */
  #define TIM_CCMR3_OC5M_0   0x00000010	/* Bit 0 */
  #define TIM_CCMR3_OC5M_1   0x00000020	/* Bit 1 */
  #define TIM_CCMR3_OC5M_2   0x00000040	/* Bit 2 */
  #define TIM_CCMR3_OC5M_3   0x00010000	/* Bit 3 */
  #define TIM_CCMR3_OC5CE    0x00000080	/* Output Compare 5 Clear Enable */
  #define TIM_CCMR3_OC6FE    0x00000400	/* Output Compare 4 Fast enable */
  #define TIM_CCMR3_OC6PE    0x00000800	/* Output Compare 4 Preload enable */
  #define TIM_CCMR3_OC6M     0x01007000	/* OC4M[2:0] bits (Output Compare 4 Mode) */
  #define TIM_CCMR3_OC6M_0   0x00001000	/* Bit 0 */
  #define TIM_CCMR3_OC6M_1   0x00002000	/* Bit 1 */
  #define TIM_CCMR3_OC6M_2   0x00004000	/* Bit 2 */
  #define TIM_CCMR3_OC6M_3   0x01000000	/* Bit 3 */
  #define TIM_CCMR3_OC6CE    0x00008000	/* Output Compare 4 Clear Enable */
#define TOFF_TIM_CCR5       0x0058		/* (RW) TIM capture/compare mode register5 */
  #define TIM_CCR5_CCR5      0xFFFFFFFF	/* Capture/Compare 5 Value */
  #define TIM_CCR5_GC5C1     0x20000000	/* Group Channel 5 and Channel 1 */
  #define TIM_CCR5_GC5C2     0x40000000	/* Group Channel 5 and Channel 2 */
  #define TIM_CCR5_GC5C3     0x80000000	/* Group Channel 5 and Channel 3 */
#define TOFF_TIM_CCR6       0x005C		/* (RW) TIM capture/compare mode register6 */

/*
 *  LPTIMIMER
 */
#define TADR_LPTIM1_BASE    (APB1PERIPH_BASE + 0x2400)
#define TOFF_LPTIM_ISR      0x0000		/* (RW) LPTIM Interrupt and Status register */
  #define LPTIM_ISR_CMPM     0x00000001	/* Compare match                       */
  #define LPTIM_ISR_ARRM     0x00000002	/* Autoreload match                    */
  #define LPTIM_ISR_EXTTRIG  0x00000004	/* External trigger edge event         */
  #define LPTIM_ISR_CMPOK    0x00000008	/* Compare register update OK          */
  #define LPTIM_ISR_ARROK    0x00000010	/* Autoreload register update OK       */
  #define LPTIM_ISR_UP       0x00000020	/* Counter direction change down to up */
  #define LPTIM_ISR_DOWN     0x00000040	/* Counter direction change up to down */
#define TOFF_LPTIM_ICR      0x0004		/* (RW) LPTIM Interrupt Clear register */
  #define LPTIM_ICR_CMPMCF   0x00000001	/* Compare match Clear Flag                       */
  #define LPTIM_ICR_ARRMCF   0x00000002	/* Autoreload match Clear Flag                    */
  #define LPTIM_ICR_EXTTRIGCF 0x00000004 /* External trigger edge event Clear Flag         */
  #define LPTIM_ICR_CMPOKCF  0x00000008	/* Compare register update OK Clear Flag          */
  #define LPTIM_ICR_ARROKCF  0x00000010	/* Autoreload register update OK Clear Flag       */
  #define LPTIM_ICR_UPCF     0x00000020	/* Counter direction change down to up Clear Flag */
  #define LPTIM_ICR_DOWNCF   0x00000040	/* Counter direction change up to down Clear Flag */
#define TOFF_LPTIM_IER      0x0008		/* (RW) LPTIM Interrupt Enable register */
  #define LPTIM_IER_CMPMIE   0x00000001	/* Compare match Interrupt Enable                       */
  #define LPTIM_IER_ARRMIE   0x00000002	/* Autoreload match Interrupt Enable                    */
  #define LPTIM_IER_EXTTRIGIE 0x00000004 /* External trigger edge event Interrupt Enable         */
  #define LPTIM_IER_CMPOKIE  0x00000008	/* Compare register update OK Interrupt Enable          */
  #define LPTIM_IER_ARROKIE  0x00000010	/* Autoreload register update OK Interrupt Enable       */
  #define LPTIM_IER_UPIE     0x00000020	/* Counter direction change down to up Interrupt Enable */
  #define LPTIM_IER_DOWNIE   0x00000040	/* Counter direction change up to down Interrupt Enable */
#define TOFF_LPTIM_CFGR     0x000C		/* (RW) LPTIM Configuration register */
  #define LPTIM_CFGR_CKSEL   0x00000001	/* Clock selector */
  #define LPTIM_CFGR_CKPOL   0x00000006	/* CKPOL[1:0] bits (Clock polarity) */
  #define LPTIM_CFGR_CKPOL_0 0x00000002	/* Bit 0 */
  #define LPTIM_CFGR_CKPOL_1 0x00000004	/* Bit 1 */
  #define LPTIM_CFGR_CKFLT   0x00000018	/* CKFLT[1:0] bits (Configurable digital filter for external clock) */
  #define LPTIM_CFGR_CKFLT_0 0x00000008	/* Bit 0 */
  #define LPTIM_CFGR_CKFLT_1 0x00000010	/* Bit 1 */
  #define LPTIM_CFGR_TRGFLT  0x000000C0	/* TRGFLT[1:0] bits (Configurable digital filter for trigger) */
  #define LPTIM_CFGR_TRGFLT_0 0x00000040	/* Bit 0 */
  #define LPTIM_CFGR_TRGFLT_1 0x00000080	/* Bit 1 */
  #define LPTIM_CFGR_PRESC   0x00000E00	/* PRESC[2:0] bits (Clock prescaler) */
  #define LPTIM_CFGR_PRESC_0 0x00000200	/* Bit 0 */
  #define LPTIM_CFGR_PRESC_1 0x00000400	/* Bit 1 */
  #define LPTIM_CFGR_PRESC_2 0x00000800	/* Bit 2 */
  #define LPTIM_CFGR_TRIGSEL 0x0000E000	/* TRIGSEL[2:0]] bits (Trigger selector) */
  #define LPTIM_CFGR_TRIGSEL_0 0x00002000	/* Bit 0 */
  #define LPTIM_CFGR_TRIGSEL_1 0x00004000	/* Bit 1 */
  #define LPTIM_CFGR_TRIGSEL_2 0x00008000	/* Bit 2 */
  #define LPTIM_CFGR_TRIGEN  0x00060000	/* TRIGEN[1:0] bits (Trigger enable and polarity) */
  #define LPTIM_CFGR_TRIGEN_0 0x00020000	/* Bit 0 */
  #define LPTIM_CFGR_TRIGEN_1 0x00040000	/* Bit 1 */
  #define LPTIM_CFGR_TIMOUT  0x00080000	/* Timout enable           */
  #define LPTIM_CFGR_WAVE    0x00100000	/* Waveform shape          */
  #define LPTIM_CFGR_WAVPOL  0x00200000	/* Waveform shape polarity */
  #define LPTIM_CFGR_PRELOAD 0x00400000	/* Reg update mode         */
  #define LPTIM_CFGR_COUNTMODE 0x00800000	/* Counter mode enable     */     
  #define LPTIM_CFGR_ENC     0x01000000	/* Encoder mode enable     */          
#define TOFF_LPTIM_CR       0x0010		/* (RW) LPTIM Control register */
  #define LPTIM_CR_ENABLE    0x00000001	/* LPTIMer enable                 */
  #define LPTIM_CR_SNGSTRT   0x00080002	/* Timer start in single mode     */
  #define LPTIM_CR_CNTSTRT   0x00000004	/* Timer start in continuous mode */
#define TOFF_LPTIM_CMP      0x0014		/* (RW) LPTIM Compare register */
#define TOFF_LPTIM_ARR      0x0018		/* (RW) LPTIM Autoreload register */
#define TOFF_LPTIM_CNT      0x001C		/* (RW) LPTIM Counter register */
#define TOFF_LPTIM_OR       0x0020		/* (RW) LPTIM Option register */


/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (APB1PERIPH_BASE + 0x2800)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_SU          0x0000000F
  #define RTC_TR_ST          0x00000070
  #define RTC_TR_MNU         0x00000F00
  #define RTC_TR_MNT         0x00007000
  #define RTC_TR_HU          0x000F0000
  #define RTC_TR_HT          0x00300000
  #define RTC_TR_PM          0x00400000
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_DU          0x0000000F
  #define RTC_DR_DT          0x00000030
  #define RTC_DR_MU          0x00000F00
  #define RTC_DR_MT          0x00001000
  #define RTC_DR_WDU         0x0000E000
  #define RTC_DR_YU          0x000F0000
  #define RTC_DR_YT          0x00F00000
#define TOFF_RTC_CR         0x0008		/* (RW) RTC control register */
  #define RTC_CR_WUCKSEL     0x00000007
  #define RTC_CR_WUCKSEL_0   0x00000001
  #define RTC_CR_WUCKSEL_1   0x00000002
  #define RTC_CR_WUCKSEL_2   0x00000004
  #define RTC_CR_TSEDGE      0x00000008
  #define RTC_CR_REFCKON     0x00000010
  #define RTC_CR_BYPSHAD     0x00000020
  #define RTC_CR_FMT         0x00000040
  #define RTC_CR_ALRAE       0x00000100
  #define RTC_CR_ALRBE       0x00000200
  #define RTC_CR_WUTE        0x00000400
  #define RTC_CR_TSE         0x00000800
  #define RTC_CR_ALRAIE      0x00001000
  #define RTC_CR_ALRBIE      0x00002000
  #define RTC_CR_WUTIE       0x00004000
  #define RTC_CR_TSIE        0x00008000
  #define RTC_CR_ADD1H       0x00010000
  #define RTC_CR_SUB1H       0x00020000
  #define RTC_CR_BCK         0x00040000
  #define RTC_CR_BKP         RTC_CR_BCK
  #define RTC_CR_COSEL       0x00080000
  #define RTC_CR_POL         0x00100000
  #define RTC_CR_OSEL        0x00600000
  #define RTC_CR_OSEL_0      0x00200000
  #define RTC_CR_OSEL_1      0x00400000
  #define RTC_CR_COE         0x00800000
  #define RTC_CR_ITSE        0x01000000
#define TOFF_RTC_ISR        0x000C		/* (RW) RTC initialization and status register */
  #define RTC_ISR_ALRAWF     0x00000001
  #define RTC_ISR_ALRBWF     0x00000002
  #define RTC_ISR_WUTWF      0x00000004
  #define RTC_ISR_SHPF       0x00000008
  #define RTC_ISR_INITS      0x00000010
  #define RTC_ISR_RSF        0x00000020
  #define RTC_ISR_INITF      0x00000040
  #define RTC_ISR_INIT       0x00000080
  #define RTC_ISR_ALRAF      0x00000100
  #define RTC_ISR_ALRBF      0x00000200
  #define RTC_ISR_WUTF       0x00000400
  #define RTC_ISR_TSF        0x00000800
  #define RTC_ISR_TSOVF      0x00001000
  #define RTC_ISR_TAMP1F     0x00002000
  #define RTC_ISR_TAMP2F     0x00004000
  #define RTC_ISR_TAMP3F     0x00008000
  #define RTC_ISR_RECALPF    0x00010000
  #define RTC_ISR_ITSF       0x00020000
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_ALRMAR     0x001C		/* (RW) RTC alarm A register */

  #define RTC_ALRMAR_SU      0x0000000F
  #define RTC_ALRMAR_ST      0x00000070
  #define RTC_ALRMAR_MSK1    0x00000080
  #define RTC_ALRMAR_MNU     0x00000F00
  #define RTC_ALRMAR_MNT     0x00007000
  #define RTC_ALRMAR_MSK2    0x00008000
  #define RTC_ALRMAR_HU      0x000F0000
  #define RTC_ALRMAR_HT      0x00300000
  #define RTC_ALRMAR_PM      0x00400000
  #define RTC_ALRMAR_MSK3    0x00800000
  #define RTC_ALRMAR_DU      0x0F000000
  #define RTC_ALRMAR_DT      0x30000000
  #define RTC_ALRMAR_WDSEL   0x40000000
  #define RTC_ALRMAR_MSK4    0x80000000

#define TOFF_RTC_ALRMBR     0x0020		/* (RW) RTC alarm B register */
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
#define TOFF_RTC_SSR        0x0028		/* (RW) RTC sub second register */
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_CALR       0x003C		/* (RW) RTC calibration register */
#define TOFF_RTC_TAFCR      0x0040		/* (RW) RTC tamper and alternate function configuration register */
#define TOFF_RTC_TAMPCR     TOFF_RTC_TAFCR
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_SS    0x00007FFF
#define TOFF_RTC_ALRMBSSR   0x0048		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_SS    0x00007FFF
#define TOFF_RTC_OR         0x004C		/* (RW) RTC option register */
  #define RTC_OR_TSINSEL     0x00000006
  #define RTC_OR_TSINSEL_0   0x00000002
  #define RTC_OR_TSINSEL_1   0x00000004
  #define RTC_OR_ALARMTYPE   0x00000008
#define TOFF_RTC_BKP0R      0x0050		/* (RW) RTC backup register 0 */
#define TOFF_RTC_BKP1R      0x0054		/* (RW) RTC backup register 1 */
#define TOFF_RTC_BKP2R      0x0058		/* (RW) RTC backup register 2 */
#define TOFF_RTC_BKP3R      0x005C		/* (RW) RTC backup register 3 */
#define TOFF_RTC_BKP4R      0x0060		/* (RW) RTC backup register 4 */
#define TOFF_RTC_BKP5R      0x0064		/* (RW) RTC backup register 5 */
#define TOFF_RTC_BKP6R      0x0068		/* (RW) RTC backup register 6 */
#define TOFF_RTC_BKP7R      0x006C		/* (RW) RTC backup register 7 */
#define TOFF_RTC_BKP8R      0x0070		/* (RW) RTC backup register 8 */
#define TOFF_RTC_BKP9R      0x0074		/* (RW) RTC backup register 9 */
#define TOFF_RTC_BKP10R     0x0078		/* (RW) RTC backup register 10 */
#define TOFF_RTC_BKP11R     0x007C		/* (RW) RTC backup register 11 */
#define TOFF_RTC_BKP12R     0x0080		/* (RW) RTC backup register 12 */
#define TOFF_RTC_BKP13R     0x0084		/* (RW) RTC backup register 13 */
#define TOFF_RTC_BKP14R     0x0088		/* (RW) RTC backup register 14 */
#define TOFF_RTC_BKP15R     0x008C		/* (RW) RTC backup register 15 */
#define TOFF_RTC_BKP16R     0x0090		/* (RW) RTC backup register 16 */
#define TOFF_RTC_BKP17R     0x0094		/* (RW) RTC backup register 17 */
#define TOFF_RTC_BKP18R     0x0098		/* (RW) RTC backup register 18 */
#define TOFF_RTC_BKP19R     0x009C		/* (RW) RTC backup register 19 */
#define TOFF_RTC_BKP20R     0x00A0		/* (RW) RTC backup register 20 */
#define TOFF_RTC_BKP21R     0x00A4		/* (RW) RTC backup register 21 */
#define TOFF_RTC_BKP22R     0x00A8		/* (RW) RTC backup register 22 */
#define TOFF_RTC_BKP23R     0x00AC		/* (RW) RTC backup register 23 */
#define TOFF_RTC_BKP24R     0x00B0		/* (RW) RTC backup register 24 */
#define TOFF_RTC_BKP25R     0x00B4		/* (RW) RTC backup register 25 */
#define TOFF_RTC_BKP26R     0x00B8		/* (RW) RTC backup register 26 */
#define TOFF_RTC_BKP27R     0x00BC		/* (RW) RTC backup register 27 */
#define TOFF_RTC_BKP28R     0x00C0		/* (RW) RTC backup register 28 */
#define TOFF_RTC_BKP29R     0x00C4		/* (RW) RTC backup register 29 */
#define TOFF_RTC_BKP30R     0x00C8		/* (RW) RTC backup register 30 */
#define TOFF_RTC_BKP31R     0x00CC		/* (RW) RTC backup register 31 */

/*
 *  WINDOW WATCHDOG
 */
#define TADR_WWDG_BASE      (APB1PERIPH_BASE + 0x2C00)
#define TOFF_WWDG_CR        0x0000		/* (RW) WWDG Control register */
  #define WWDG_CR_T           0x0000007F	/* T[6:0] bits (7-Bit counter (MSB to LSB)) */
  #define WWDG_CR_T_0         0x00000001
  #define WWDG_CR_T_1         0x00000002
  #define WWDG_CR_T_2         0x00000004
  #define WWDG_CR_T_3         0x00000008
  #define WWDG_CR_T_4         0x00000010
  #define WWDG_CR_T_5         0x00000020
  #define WWDG_CR_T_6         0x00000040
  #define WWDG_CR_T0          WWDG_CR_T_0
  #define WWDG_CR_T1          WWDG_CR_T_1
  #define WWDG_CR_T2          WWDG_CR_T_2
  #define WWDG_CR_T3          WWDG_CR_T_3
  #define WWDG_CR_T4          WWDG_CR_T_4
  #define WWDG_CR_T5          WWDG_CR_T_5
  #define WWDG_CR_T6          WWDG_CR_T_6
  #define WWDG_CR_WDGA        0x00000080	/* Activation bit */
#define TOFF_WWDG_CFR       0x0004		/* (RW) WWDG Configuration register */
  #define WWDG_CFR_W          0x0000007F	/* W[6:0] bits (7-bit window value) */
  #define WWDG_CFR_W_0        0x00000001
  #define WWDG_CFR_W_1        0x00000002
  #define WWDG_CFR_W_2        0x00000004
  #define WWDG_CFR_W_3        0x00000008
  #define WWDG_CFR_W_4        0x00000010
  #define WWDG_CFR_W_5        0x00000020
  #define WWDG_CFR_W_6        0x00000040
  #define WWDG_CFR_W0         WWDG_CFR_W_0
  #define WWDG_CFR_W1         WWDG_CFR_W_1
  #define WWDG_CFR_W2         WWDG_CFR_W_2
  #define WWDG_CFR_W3         WWDG_CFR_W_3
  #define WWDG_CFR_W4         WWDG_CFR_W_4
  #define WWDG_CFR_W5         WWDG_CFR_W_5
  #define WWDG_CFR_W6         WWDG_CFR_W_6
  #define WWDG_CFR_WDGTB      0x00000180	/* WDGTB[1:0] bits (Timer Base) */
  #define WWDG_CFR_WDGTB_0    0x00000080
  #define WWDG_CFR_WDGTB_1    0x00000100
  #define WWDG_CFR_WDGTB0     WWDG_CFR_WDGTB_0
  #define WWDG_CFR_WDGTB1     WWDG_CFR_WDGTB_1
  #define WWDG_CFR_EWI        0x00000200	/* Early Wakeup Interrupt */
#define TOFF_WWDG_SR        0x0008		/* (R)  WWDG Status register */
  #define WWDG_SR_EWIF        0x00000001	/* Early Wakeup Interrupt Flag */

/*
 *  INDEPENDENT WATCHDOG
 */
#define TADR_IWDG_BASE      (APB1PERIPH_BASE + 0x3000)
#define TOFF_IWDG_KR        0x0000		/* (RW) IWDG Key register */
#define TOFF_IWDG_PR        0x0004		/* (RW) IWDG Prescaler register */
#define TOFF_IWDG_RLR       0x0008		/* (RW) IWDG Reload register */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */
#define TOFF_IWDG_WINR      0x0010		/* (RW) IWDG Window register */

/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_SPI2_BASE      (APB1PERIPH_BASE + 0x3800)
#define TADR_SPI3_BASE      (APB1PERIPH_BASE + 0x3C00)
#define TADR_SPI1_BASE      (APB2PERIPH_BASE + 0x3000)
#define TADR_SPI4_BASE      (APB2PERIPH_BASE + 0x3400)
#define TADR_SPI5_BASE      (APB2PERIPH_BASE + 0x5000)
#define TADR_SPI6_BASE      (APB2PERIPH_BASE + 0x5400)
#define TOFF_SPI_CR1        0x0000		/* (RW-16) SPI control register 1 (not used in I2S mode) */
  #define SPI_CR1_CPHA          0x00000001	/* Clock Phase */
  #define SPI_CR1_CPOL          0x00000002	/* Clock Polarity */
  #define SPI_CR1_MSTR          0x00000004	/* Master Selection */
  #define SPI_CR1_BR            0x00000038	/* BR[2:0] bits (Baud Rate Control) */
  #define SPI_CR1_BR_0          0x00000008	/* Bit 0 */
  #define SPI_CR1_BR_1          0x00000010	/* Bit 1 */
  #define SPI_CR1_BR_2          0x00000020	/* Bit 2 */
  #define SPI_CR1_SPE           0x00000040	/* SPI Enable */
  #define SPI_CR1_LSBFIRST      0x00000080	/* Frame Format */
  #define SPI_CR1_SSI           0x00000100	/* Internal slave select */
  #define SPI_CR1_SSM           0x00000200	/* Software slave management */
  #define SPI_CR1_RXONLY        0x00000400	/* Receive only */
  #define SPI_CR1_CRCL          0x00000800	/* CRC Length */
  #define SPI_CR1_CRCNEXT       0x00001000	/* Transmit CRC next */
  #define SPI_CR1_CRCEN         0x00002000	/* Hardware CRC calculation enable */
  #define SPI_CR1_BIDIOE        0x00004000	/* Output enable in bidirectional mode */
  #define SPI_CR1_BIDIMODE      0x00008000	/* Bidirectional data mode enable */
#define TOFF_SPI_CR2        0x0004		/* (RW-16) SPI control register 2 */
  #define SPI_CR2_RXDMAEN       0x00000001	/* Rx Buffer DMA Enable */
  #define SPI_CR2_TXDMAEN       0x00000002	/* Tx Buffer DMA Enable */
  #define SPI_CR2_SSOE          0x00000004	/* SS Output Enable */
  #define SPI_CR2_NSSP          0x00000008	/* NSS pulse management Enable */
  #define SPI_CR2_FRF           0x00000010	/* Frame Format Enable */
  #define SPI_CR2_ERRIE         0x00000020	/* Error Interrupt Enable */
  #define SPI_CR2_RXNEIE        0x00000040	/* RX buffer Not Empty Interrupt Enable */
  #define SPI_CR2_TXEIE         0x00000080	/* Tx buffer Empty Interrupt Enable */
  #define SPI_CR2_DS            0x00000F00	/* DS[3:0] Data Size */
  #define SPI_CR2_DS_0          0x00000100	/* Bit 0 */
  #define SPI_CR2_DS_1          0x00000200	/* Bit 1 */
  #define SPI_CR2_DS_2          0x00000400	/* Bit 2 */
  #define SPI_CR2_DS_3          0x00000800	/* Bit 3 */
  #define SPI_CR2_FRXTH         0x00001000	/* FIFO reception Threshold */
  #define SPI_CR2_LDMARX        0x00002000	/* Last DMA transfer for reception */
  #define SPI_CR2_LDMATX        0x00004000	/* Last DMA transfer for transmission */
#define TOFF_SPI_SR         0x0008		/* (RW-16) SPI status register */
  #define  SPI_SR_RXNE          0x00000001	/* Receive buffer Not Empty  */
  #define  SPI_SR_TXE           0x00000002	/* Transmit buffer Empty */
  #define  SPI_SR_CHSIDE        0x00000004	/* Channel side */
  #define  SPI_SR_UDR           0x00000008	/* Underrun flag */
  #define  SPI_SR_CRCERR        0x00000010	/* CRC Error flag */
  #define  SPI_SR_MODF          0x00000020	/* Mode fault */
  #define  SPI_SR_OVR           0x00000040	/* Overrun flag */
  #define  SPI_SR_BSY           0x00000080	/* Busy flag */
  #define  SPI_SR_FRE           0x00000100	/* TI frame format error */
  #define  SPI_SR_FRLVL         0x00000600	/* FIFO Reception Level */
  #define  SPI_SR_FRLVL_0       0x00000200	/* Bit 0 */
  #define  SPI_SR_FRLVL_1       0x00000400	/* Bit 1 */
  #define  SPI_SR_FTLVL         0x00001800	/* FIFO Transmission Level */
  #define  SPI_SR_FTLVL_0       0x00000800	/* Bit 0 */
  #define  SPI_SR_FTLVL_1       0x00001000	/* Bit 1 */
#define TOFF_SPI_DR         0x000C		/* (RW-16) SPI data register */
#define TOFF_SPI_CRCPR      0x0010		/* (RW-16) SPI CRC polynomial register (not used in I2S mode) */
#define TOFF_SPI_RXCRCR     0x0014		/* (RW-16) SPI RX CRC register (not used in I2S mode) */
#define TOFF_SPI_TXCRCR     0x0018		/* (RW-16) SPI TX CRC register (not used in I2S mode) */
#define TOFF_SPI_I2SCFGR    0x001C		/* (RW-16) SPI_I2S configuration register */
  #define SPI_I2SCFGR_CHLEN     0x00000001	/* Channel length (number of bits per audio channel) */
  #define SPI_I2SCFGR_DATLEN    0x00000006	/* DATLEN[1:0] bits (Data length to be transferred)  */
  #define SPI_I2SCFGR_DATLEN_0  0x00000002	/* Bit 0 */
  #define SPI_I2SCFGR_DATLEN_1  0x00000004	/* Bit 1 */
  #define SPI_I2SCFGR_CKPOL     0x00000008	/* steady state clock polarity */
  #define SPI_I2SCFGR_I2SSTD    0x00000030	/* I2SSTD[1:0] bits (I2S standard selection) */
  #define SPI_I2SCFGR_I2SSTD_0  0x00000010	/* Bit 0 */
  #define SPI_I2SCFGR_I2SSTD_1  0x00000020	/* Bit 1 */
  #define SPI_I2SCFGR_PCMSYNC   0x00000080	/* PCM frame synchronization */
  #define SPI_I2SCFGR_I2SCFG    0x00000300	/* I2SCFG[1:0] bits (I2S configuration mode) */
  #define SPI_I2SCFGR_I2SCFG_0  0x00000100	/* Bit 0 */
  #define SPI_I2SCFGR_I2SCFG_1  0x00000200	/* Bit 1 */
  #define SPI_I2SCFGR_I2SE      0x00000400	/* I2S Enable */
  #define SPI_I2SCFGR_I2SMOD    0x00000800	/* I2S mode selection */
  #define SPI_I2SCFGR_ASTRTEN   0x00001000	/* Asynchronous start enable */
#define TOFF_SPI_I2SPR      0x0020		/* (RW-16) SPI_I2S prescaler register */

/*
 *  SPDIF-RX INTERFACE
 */
#define TADR_SPDIFRX_BASE   (APB1PERIPH_BASE + 0x4000)
#define TOFF_SPDIFRX_CR     0x0000		/* (RW) Control register */
#define TOFF_SPDIFRX_IMR    0x0004		/* (RW) Interrupt mask register */
#define TOFF_SPDIFRX_SR     0x0008		/* (RW) Status register */
#define TOFF_SPDIFRX_IFCR   0x000C		/* (RW) Interrupt Flag Clear register */
#define TOFF_SPDIFRX_DR     0x0010		/* (RW) Data input register */
#define TOFF_SPDIFRX_CSR    0x0014		/* (RW) Channel Status register */
#define TOFF_SPDIFRX_DIR    0x0018		/* (RW) Debug Information register */


/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART2_BASE    (APB1PERIPH_BASE + 0x4400)
#define TADR_USART3_BASE    (APB1PERIPH_BASE + 0x4800)
#define TADR_UART4_BASE     (APB1PERIPH_BASE + 0x4C00)
#define TADR_UART5_BASE     (APB1PERIPH_BASE + 0x5000)
#define TADR_UART7_BASE     (APB1PERIPH_BASE + 0x7800)
#define TADR_UART8_BASE     (APB1PERIPH_BASE + 0x7C00)
#define TADR_USART1_BASE    (APB2PERIPH_BASE + 0x1000)
#define TADR_USART6_BASE    (APB2PERIPH_BASE + 0x1400)
#define TOFF_USART_CR1      0x0000		/* (RW) USART Control register 1 */
  #define USART_CR1_UE       0x00000001	/* USART Enable */
  #define USART_CR1_RE       0x00000004	/* Receiver Enable */
  #define USART_CR1_TE       0x00000008	/* Transmitter Enable */
  #define USART_CR1_IDLEIE   0x00000010	/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE   0x00000020	/* RXNE Interrupt Enable */
  #define USART_CR1_TCIE     0x00000040	/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE    0x00000080	/* TXE Interrupt Enable */
  #define USART_CR1_PEIE     0x00000100	/* PE Interrupt Enable */
  #define USART_CR1_PS       0x00000200	/* Parity Selection */
  #define USART_CR1_PCE      0x00000400	/* Parity Control Enable */
  #define USART_CR1_WAKE     0x00000800	/* Receiver Wakeup method */
  #define USART_CR1_M        0x10001000	/* Word length */
  #define USART_CR1_M_0      0x00001000	/* Word length - Bit 0 */
  #define USART_CR1_MME      0x00002000	/* Mute Mode Enable */
  #define USART_CR1_CMIE     0x00004000	/* Character match interrupt enable */
  #define USART_CR1_OVER8    0x00008000	/* Oversampling by 8-bit or 16-bit mode */
  #define USART_CR1_DEDT     0x001F0000	/* DEDT[4:0] bits (Driver Enable Deassertion Time) */
  #define USART_CR1_DEDT_0   0x00010000	/* Bit 0 */
  #define USART_CR1_DEDT_1   0x00020000	/* Bit 1 */
  #define USART_CR1_DEDT_2   0x00040000	/* Bit 2 */
  #define USART_CR1_DEDT_3   0x00080000	/* Bit 3 */
  #define USART_CR1_DEDT_4   0x00100000	/* Bit 4 */
  #define USART_CR1_DEAT     0x03E00000	/* DEAT[4:0] bits (Driver Enable Assertion Time)   */
  #define USART_CR1_DEAT_0   0x00200000	/* Bit 0 */
  #define USART_CR1_DEAT_1   0x00400000	/* Bit 1 */
  #define USART_CR1_DEAT_2   0x00800000	/* Bit 2 */
  #define USART_CR1_DEAT_3   0x01000000	/* Bit 3 */
  #define USART_CR1_DEAT_4   0x02000000	/* Bit 4 */
  #define USART_CR1_RTOIE    0x04000000	/* Receive Time Out interrupt enable */
  #define USART_CR1_EOBIE    0x08000000	/* End of Block interrupt enable */
  #define USART_CR1_M_1      0x10000000	/* Word length - Bit 1 */
#define TOFF_USART_CR2      0x0004		/* (RW) USART Control register 2 */
  #define USART_CR2_ADDM7    0x00000010	/* 7-bit or 4-bit Address Detectio */
  #define USART_CR2_LBDL     0x00000020	/* LIN Break Detection Length */
  #define USART_CR2_LBDIE    0x00000040	/* LIN Break Detection Interrupt Enable */
  #define USART_CR2_LBCL     0x00000100	/* Last Bit Clock pulse */
  #define USART_CR2_CPHA     0x00000200	/* Clock Phase */
  #define USART_CR2_CPOL     0x00000400	/* Clock Polarity */
  #define USART_CR2_CLKEN    0x00000800	/* Clock Enable */
  #define USART_CR2_STOP     0x00003000	/* STOP[1:0] bits (STOP bits) */
  #define USART_CR2_STOP_0   0x00001000	/* Bit 0 */
  #define USART_CR2_STOP_1   0x00002000	/* Bit 1 */
  #define USART_CR2_LINEN    0x00004000	/* LIN mode enable */
  #define USART_CR2_SWAP     0x00008000	/* SWAP TX/RX pins */
  #define USART_CR2_RXINV    0x00010000	/* RX pin active level inversion */
  #define USART_CR2_TXINV    0x00020000	/* TX pin active level inversion */
  #define USART_CR2_DATAINV  0x00040000	/* Binary data inversion */
  #define USART_CR2_MSBFIRST 0x00080000	/* Most Significant Bit First */
  #define USART_CR2_ABREN    0x00100000	/* Auto Baud-Rate Enable */
  #define USART_CR2_ABRMODE  0x00600000	/* ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
  #define USART_CR2_ABRMODE_0 0x00200000	/* Bit 0 */
  #define USART_CR2_ABRMODE_1 0x00400000	/* Bit 1 */
  #define USART_CR2_RTOEN    0x00800000	/* Receiver Time-Out enable */
  #define USART_CR2_ADD      0xFF000000	/* Address of the USART node */
#define TOFF_USART_CR3      0x0008		/* (RW) USART Control register 3 */
  #define USART_CR3_EIE      0x00000001	/* Error Interrupt Enable */
  #define USART_CR3_IREN     0x00000002	/* IrDA mode Enable */
  #define USART_CR3_IRLP     0x00000004	/* IrDA Low-Power */
  #define USART_CR3_HDSEL    0x00000008	/* Half-Duplex Selection */
  #define USART_CR3_NACK     0x00000010	/* SmartCard NACK enable */
  #define USART_CR3_SCEN     0x00000020	/* SmartCard mode enable */
  #define USART_CR3_DMAR     0x00000040	/* DMA Enable Receiver  */
  #define USART_CR3_DMAT     0x00000080	/* DMA Enable Transmitter */
  #define USART_CR3_RTSE     0x00000100	/* RTS Enable */
  #define USART_CR3_CTSE     0x00000200	/* CTS Enable */
  #define USART_CR3_CTSIE    0x00000400	/* CTS Interrupt Enable */
  #define USART_CR3_ONEBIT   0x00000800	/* One sample bit method enable */
  #define USART_CR3_OVRDIS   0x00001000	/* Overrun Disable */
  #define USART_CR3_DDRE     0x00002000	/* DMA Disable on Reception Error */
  #define USART_CR3_DEM      0x00004000	/* Driver Enable Mode */
  #define USART_CR3_DEP      0x00008000	/* Driver Enable Polarity Selection */
  #define USART_CR3_SCARCNT  0x000E0000	/* SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
  #define USART_CR3_SCARCNT_0 0x00020000	/* Bit 0 */
  #define USART_CR3_SCARCNT_1 0x00040000	/* Bit 1 */
  #define USART_CR3_SCARCNT_2 0x00080000	/* Bit 2 */
#define TOFF_USART_BRR      0x000C		/* (RW) USART Baud rate register */
#define TOFF_USART_GTPR     0x0010		/* (RW) USART Guard time and prescaler register */
#define TOFF_USART_RTOR     0x0014		/* (RW) USART Receiver Time Out register */
#define TOFF_USART_RQR      0x0018		/* (RW) USART Request register */
  #define USART_RQR_ABRRQ    0x00000001	/* Auto-Baud Rate Request */
  #define USART_RQR_SBKRQ    0x00000002	/* Send Break Request */
  #define USART_RQR_MMRQ     0x00000004	/* Mute Mode Request */
  #define USART_RQR_RXFRQ    0x00000008	/* Receive Data flush Request */
  #define USART_RQR_TXFRQ    0x00000010	/* Transmit data flush Request */
#define TOFF_USART_ISR      0x001C		/* (RW) USART Interrupt and status register */
  #define USART_ISR_PE       0x00000001	/* Parity Error */
  #define USART_ISR_FE       0x00000002	/* Framing Error */
  #define USART_ISR_NE       0x00000004	/* Noise detected Flag */
  #define USART_ISR_ORE      0x00000008	/* OverRun Error */
  #define USART_ISR_IDLE     0x00000010	/* IDLE line detected */
  #define USART_ISR_RXNE     0x00000020	/* Read Data Register Not Empty */
  #define USART_ISR_TC       0x00000040	/* Transmission Complete */
  #define USART_ISR_TXE      0x00000080	/* Transmit Data Register Empty */
  #define USART_ISR_LBD      0x00000100	/* LIN Break Detection Flag */
  #define USART_ISR_CTSIF    0x00000200	/* CTS interrupt flag */
  #define USART_ISR_CTS      0x00000400	/* CTS flag */
  #define USART_ISR_RTOF     0x00000800	/* Receiver Time Out */
  #define USART_ISR_EOBF     0x00001000	/* End Of Block Flag */
  #define USART_ISR_ABRE     0x00004000	/* Auto-Baud Rate Error */
  #define USART_ISR_ABRF     0x00008000	/* Auto-Baud Rate Flag */
  #define USART_ISR_BUSY     0x00010000	/* Busy Flag */
  #define USART_ISR_CMF      0x00020000	/* Character Match Flag */
  #define USART_ISR_SBKF     0x00040000	/* Send Break Flag */
  #define USART_ISR_RWU      0x00080000	/* Receive Wake Up from mute mode Flag */
  #define USART_ISR_WUF      0x00100000	/* Wake Up from stop mode Flag */
  #define USART_ISR_TEACK    0x00200000	/* Transmit Enable Acknowledge Flag */
  #define USART_ISR_REACK    0x00400000	/* Receive Enable Acknowledge Flag */
#define TOFF_USART_ICR      0x0020		/* (RW) USART Interrupt flag Clear register */
  #define USART_ICR_PECF     0x00000001	/* Parity Error Clear Flag */
  #define USART_ICR_FECF     0x00000002	/* Framing Error Clear Flag */
  #define USART_ICR_NCF      0x00000004	/* Noise detected Clear Flag */
  #define USART_ICR_ORECF    0x00000008	/* OverRun Error Clear Flag */
  #define USART_ICR_IDLECF   0x00000010	/* IDLE line detected Clear Flag */
  #define USART_ICR_TCCF     0x00000040	/* Transmission Complete Clear Flag */
  #define USART_ICR_LBDCF    0x00000100	/* LIN Break Detection Clear Flag */
  #define USART_ICR_CTSCF    0x00000200	/* CTS Interrupt Clear Flag */
  #define USART_ICR_RTOCF    0x00000800	/* Receiver Time Out Clear Flag */
  #define USART_ICR_EOBCF    0x00001000	/* End Of Block Clear Flag */
  #define USART_ICR_CMCF     0x00020000	/* Character Match Clear Flag */
  #define USART_ICR_WUCF     0x00100000	/* Wake Up from stop mode Clear Flag */
#define TOFF_USART_RDR      0x0024		/* (RW) USART Receive Data register */
#define TOFF_USART_TDR      0x0028		/* (RW) USART Transmit Data register */

/*
 *  INTER-INTERATED CIRCUIT IINTERFACE(16)
 */
#define TADR_I2C1_BASE      (APB1PERIPH_BASE + 0x5400)
#define TADR_I2C2_BASE      (APB1PERIPH_BASE + 0x5800)
#define TADR_I2C3_BASE      (APB1PERIPH_BASE + 0x5C00)
#define TADR_I2C4_BASE      (APB1PERIPH_BASE + 0x6000)
#define TOFF_I2C_CR1        0x0000		/* (RW) I2C Control register 1 */
  #define I2C_CR1_PE         0x00000001	/* Peripheral enable */
  #define I2C_CR1_TXIE       0x00000002	/* TX interrupt enable */
  #define I2C_CR1_RXIE       0x00000004	/* RX interrupt enable */
  #define I2C_CR1_ADDRIE     0x00000008	/* Address match interrupt enable */
  #define I2C_CR1_NACKIE     0x00000010	/* NACK received interrupt enable */
  #define I2C_CR1_STOPIE     0x00000020	/* STOP detection interrupt enable */
  #define I2C_CR1_TCIE       0x00000040	/* Transfer complete interrupt enable  */
  #define I2C_CR1_ERRIE      0x00000080	/* Errors interrupt enable */
  #define I2C_CR1_DNF        0x00000F00	/* Digital noise filter */
  #define I2C_CR1_ANFOFF     0x00001000	/* Analog noise filter OFF */
  #define I2C_CR1_SWRST      0x00002000	/* Software reset */
  #define I2C_CR1_TXDMAEN    0x00004000	/* DMA transmission requests enable */
  #define I2C_CR1_RXDMAEN    0x00008000	/* DMA reception requests enable */
  #define I2C_CR1_SBC        0x00010000	/* Slave byte control */
  #define I2C_CR1_NOSTRETCH  0x00020000	/* Clock stretching disable */
  #define I2C_CR1_WUPEN      0x00040000	/* Wakeup from STOP enable */
  #define I2C_CR1_GCEN       0x00080000	/* General call enable */
  #define I2C_CR1_SMBHEN     0x00100000	/* SMBus host address enable */
  #define I2C_CR1_SMBDEN     0x00200000	/* SMBus device default address enable */
  #define I2C_CR1_ALERTEN    0x00400000	/* SMBus alert enable */
  #define I2C_CR1_PECEN      0x00800000	/* PEC enable */
#define TOFF_I2C_CR2        0x0004		/* (RW) I2C Control register 2 */
  #define I2C_CR2_SADD       0x000003FF	/* Slave address (master mode) */
  #define I2C_CR2_RD_WRN     0x00000400	/* Transfer direction (master mode) */
  #define I2C_CR2_ADD10      0x00000800	/* 10-bit addressing mode (master mode) */
  #define I2C_CR2_HEAD10R    0x00001000	/* 10-bit address header only read direction (master mode) */
  #define I2C_CR2_START      0x00002000	/* START generation */
  #define I2C_CR2_STOP       0x00004000	/* STOP generation (master mode) */
  #define I2C_CR2_NACK       0x00008000	/* NACK generation (slave mode) */
  #define I2C_CR2_NBYTES     0x00FF0000	/* Number of bytes */
  #define I2C_CR2_RELOAD     0x01000000	/* NBYTES reload mode */
  #define I2C_CR2_AUTOEND    0x02000000	/* Automatic end mode (master mode) */
  #define I2C_CR2_PECBYTE    0x04000000	/* Packet error checking byte */
#define TOFF_I2C_OAR1       0x0008		/* (RW) I2C Own address register 1 */
  #define I2C_OAR1_OA1       0x000003FF	/* Interface own address 1 */
  #define I2C_OAR1_OA1MODE   0x00000400	/* Own address 1 10-bit mode */
  #define I2C_OAR1_OA1EN     0x00008000	/* Own address 1 enable */
#define TOFF_I2C_OAR2       0x000C		/* (RW) I2C Own address register 2 */
  #define I2C_OAR2_OA2       0x000000FE	/* Interface own address 2 */
  #define I2C_OAR2_OA2MSK    0x00000700	/* Own address 2 masks     */
  #define I2C_OAR2_OA2NOMASK 0x00000000	/* No mask */
  #define I2C_OAR2_OA2MASK01 0x00000100	/* OA2[1] is masked, Only OA2[7:2] are compared */
  #define I2C_OAR2_OA2MASK02 0x00000200	/* OA2[2:1] is masked, Only OA2[7:3] are compared */
  #define I2C_OAR2_OA2MASK03 0x00000300	/* OA2[3:1] is masked, Only OA2[7:4] are compared */
  #define I2C_OAR2_OA2MASK04 0x00000400	/* OA2[4:1] is masked, Only OA2[7:5] are compared */
  #define I2C_OAR2_OA2MASK05 0x00000500	/* OA2[5:1] is masked, Only OA2[7:6] are compared */
  #define I2C_OAR2_OA2MASK06 0x00000600	/* OA2[6:1] is masked, Only OA2[7] are compared */
  #define I2C_OAR2_OA2MASK07 0x00000700	/* OA2[7:1] is masked, No comparison is done */
  #define I2C_OAR2_OA2EN     0x00008000	/* Own address 2 enable    */
#define TOFF_I2C_TIMINGR    0x0010		/* (RW) I2C Timing register */
  #define I2C_TIMINGR_SCLL   0x000000FF	/* SCL low period (master mode)  */
  #define I2C_TIMINGR_SCLH   0x0000FF00	/* SCL high period (master mode) */
  #define I2C_TIMINGR_SDADEL 0x000F0000	/* Data hold time */
  #define I2C_TIMINGR_SCLDEL 0x00F00000	/* Data setup time */
  #define I2C_TIMINGR_PRESC  0xF0000000	/* Timings prescaler */
#define TOFF_I2C_TIMEOUTR   0x0014		/* (RW) I2C Timeout register */
  #define I2C_TIMEOUTR_TIMEOUTA 0x00000FFF	/* Bus timeout A */
  #define I2C_TIMEOUTR_TIDLE    0x00001000	/* Idle clock timeout detection  */
  #define I2C_TIMEOUTR_TIMOUTEN 0x00008000	/* Clock timeout enable */
  #define I2C_TIMEOUTR_TIMEOUTB 0x0FFF0000	/* Bus timeout B */
  #define I2C_TIMEOUTR_TEXTEN   0x80000000	/* Extended clock timeout enable */
#define TOFF_I2C_ISR        0x0018		/* (RW) I2C Interrupt and status register */
  #define I2C_ISR_TXE        0x00000001	/* Transmit data register empty */
  #define I2C_ISR_TXIS       0x00000002	/* Transmit interrupt status */
  #define I2C_ISR_RXNE       0x00000004	/* Receive data register not empty */
  #define I2C_ISR_ADDR       0x00000008	/* Address matched (slave mode) */
  #define I2C_ISR_NACKF      0x00000010	/* NACK received flag */
  #define I2C_ISR_STOPF      0x00000020	/* STOP detection flag */
  #define I2C_ISR_TC         0x00000040	/* Transfer complete (master mode) */
  #define I2C_ISR_TCR        0x00000080	/* Transfer complete reload */
  #define I2C_ISR_BERR       0x00000100	/* Bus error */
  #define I2C_ISR_ARLO       0x00000200	/* Arbitration lost */
  #define I2C_ISR_OVR        0x00000400	/* Overrun/Underrun */
  #define I2C_ISR_PECERR     0x00000800	/* PEC error in reception */
  #define I2C_ISR_TIMEOUT    0x00001000	/* Timeout or Tlow detection flag  */
  #define I2C_ISR_ALERT      0x00002000	/* SMBus alert */
  #define I2C_ISR_BUSY       0x00008000	/* Bus busy */
  #define I2C_ISR_DIR        0x00010000	/* Transfer direction (slave mode) */
  #define I2C_ISR_ADDCODE    0x00FE0000	/* Address match code (slave mode) */
#define TOFF_I2C_ICR        0x001C		/* (RW) I2C Interrupt clear register */
  #define I2C_ICR_ADDRCF     0x00000008	/* Address matched clear flag */
  #define I2C_ICR_NACKCF     0x00000010	/* NACK clear flag */
  #define I2C_ICR_STOPCF     0x00000020	/* STOP detection clear flag */
  #define I2C_ICR_BERRCF     0x00000100	/* Bus error clear flag */
  #define I2C_ICR_ARLOCF     0x00000200	/* Arbitration lost clear flag */
  #define I2C_ICR_OVRCF      0x00000400	/* Overrun/Underrun clear flag */
  #define I2C_ICR_PECCF      0x00000800	/* PAC error clear flag */
  #define I2C_ICR_TIMOUTCF   0x00001000	/* Timeout clear flag */
  #define I2C_ICR_ALERTCF    0x00002000	/* Alert clear flag */
#define TOFF_I2C_PECR       0x0020		/* (RW) I2C PEC register */
#define TOFF_I2C_RXDR       0x0024		/* (RW) I2C Receive data register */
#define TOFF_I2C_TXDR       0x0028		/* (RW) I2C Transmit data register */  

/*
 *  CONTROLLER AREA NETWORK
 */
#define TADR_CAN1_BASE      (APB1PERIPH_BASE + 0x6400)
#define TADR_CAN2_BASE      (APB1PERIPH_BASE + 0x6800)
#define TOFF_CAN_MCR        0x0000		/* (RW) CAN master control register */
#define TOFF_CAN_MSR        0x0004		/* (R)  CAN master status register */
#define TOFF_CAN_TSR        0x0008		/* (R)  CAN transmit status register */
#define TOFF_CAN_RF0R       0x000C		/* (RW) CAN receive FIFO 0 register */
#define TOFF_CAN_RF1R       0x0010		/* (RW) CAN receive FIFO 1 register */
#define TOFF_CAN_IER        0x0014		/* (RW) CAN interrupt enable register */
#define TOFF_CAN_ESR        0x0018		/* (RW) CAN error status register */
#define TOFF_CAN_BTR        0x001C		/* (RW) CAN bit timing register */
										/* CAN TX MailBox */
#define TOFF_CAN_TIR1       0x0180		/* (RW) CAN(1) TX mailbox identifier register */
#define TOFF_CAN_TDTR1      0x0184		/* (RW) CAN(1) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR1      0x0188		/* (RW) CAN(1) mailbox data low register */
#define TOFF_CAN_TDHR1      0x018C		/* (RW) CAN(1) mailbox data high register */
#define TOFF_CAN_TIR2       0x0190		/* (RW) CAN(2) TX mailbox identifier register */
#define TOFF_CAN_TDTR2      0x0194		/* (RW) CAN(2) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR2      0x0198		/* (RW) CAN(2) mailbox data low register */
#define TOFF_CAN_TDHR2      0x019C		/* (RW) CAN(2) mailbox data high register */
#define TOFF_CAN_TIR3       0x01A0		/* (RW) CAN(3) TX mailbox identifier register */
#define TOFF_CAN_TDTR3      0x01A4		/* (RW) CAN(3) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR3      0x01A8		/* (RW) CAN(3) mailbox data low register */
#define TOFF_CAN_TDHR3      0x01AC		/* (RW) CAN(3) mailbox data high register */
										/* CAN FIFO MailBox */
#define TOFF_CAN_RIR1       0x01B0		/* (RW) CAN(1) receive FIFO mailbox identifier register */
#define TOFF_CAN_RDTR1      0x01B4		/* (RW) CAN(1) receive FIFO mailbox data length control and time stamp register */
#define TOFF_CAN_RDLR1      0x01B8		/* (RW) CAN(1) receive FIFO mailbox data low register */
#define TOFF_CAN_RDHR1      0x01BC		/* (RW) CAN(1) receive FIFO mailbox data high register */
#define TOFF_CAN_RIR2       0x01C0		/* (RW) CAN(2) receive FIFO mailbox identifier register */
#define TOFF_CAN_RDTR2      0x01C4		/* (RW) CAN(2) receive FIFO mailbox data length control and time stamp register */
#define TOFF_CAN_RDLR2      0x01C8		/* (RW) CAN(2) receive FIFO mailbox data low register */
#define TOFF_CAN_RDHR2      0x01CC		/* (RW) CAN(2) receive FIFO mailbox data high register */
#define TOFF_CAN_FMR        0x0200		/* (RW) CAN filter master register */
#define TOFF_CAN_FM1R       0x0204		/* (RW) CAN filter mode register */
#define TOFF_CAN_FS1R       0x020C		/* (RW) CAN filter scale register */
#define TOFF_CAN_FFA1R      0x0214		/* (RW) CAN filter FIFO assignment register */
#define TOFF_CAN_FA1R       0x0218		/* (RW) CAN filter activation register */
#define TOFF_CAN_FR_BASE    0x0240		/*      0x240-0x31C */
#define TOFF_CAN_FR1        0x0240		/* (RW) CAN Filter bank register 1 */
#define TOFF_CAN_FR2        0x0244		/* (RW) CAN Filter bank register 2 */

/* 
 * HDMI-CEC 
 */
#define TADR_CEC_BASE      (APB1PERIPH_BASE + 0x6C00)
#define TOFF_CEC_CR        0x0000		/* (RW) CEC control register */
#define TOFF_CEC_CFGR      0x0004		/* (RW) CEC configuration register */
#define TOFF_CEC_TXDR      0x0008		/* (RW) CEC Tx data register  */
#define TOFF_CEC_RXDR      0x000C		/* (RW) CEC Rx Data Register */
#define TOFF_CEC_ISR       0x0010		/* (RW) CEC Interrupt and Status Register */
#define TOFF_CEC_IER       0x0014		/* (RW) CEC interrupt enable register */

/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (APB1PERIPH_BASE + 0x7000)
#define TOFF_PWR_CR1        0x0000		/* (RW) PWR power control register */
  #define PWR_CR1_LPDS       0x00000001	/* Low-Power Deepsleep                 */
  #define PWR_CR1_PDDS       0x00000002	/* Power Down Deepsleep                */
  #define PWR_CR1_CSBF       0x00000008	/* Clear Standby Flag                  */
  #define PWR_CR1_PVDE       0x00000010	/* Power Voltage Detector Enable       */
  #define PWR_CR1_PLS        0x000000E0	/* PLS[2:0] bits (PVD Level Selection) */
  #define PWR_CR1_PLS_0      0x00000020	/* Bit 0 */
  #define PWR_CR1_PLS_1      0x00000040	/* Bit 1 */
  #define PWR_CR1_PLS_2      0x00000080	/* Bit 2 */
  #define PWR_CR1_PLS_LEV0   0x00000000	/* PVD level 0 */
  #define PWR_CR1_PLS_LEV1   0x00000020	/* PVD level 1 */
  #define PWR_CR1_PLS_LEV2   0x00000040	/* PVD level 2 */
  #define PWR_CR1_PLS_LEV3   0x00000060	/* PVD level 3 */
  #define PWR_CR1_PLS_LEV4   0x00000080	/* PVD level 4 */
  #define PWR_CR1_PLS_LEV5   0x000000A0	/* PVD level 5 */
  #define PWR_CR1_PLS_LEV6   0x000000C0	/* PVD level 6 */
  #define PWR_CR1_PLS_LEV7   0x000000E0	/* PVD level 7 */
  #define PWR_CR1_DBP        0x00000100	/* Disable Backup Domain write protection                     */
  #define PWR_CR1_FPDS       0x00000200	/* Flash power down in Stop mode                              */
  #define PWR_CR1_LPUDS      0x00000400	/* Low-power regulator in deepsleep under-drive mode          */
  #define PWR_CR1_MRUDS      0x00000800	/* Main regulator in deepsleep under-drive mode               */
  #define PWR_CR1_ADCDC1     0x00002000	/* Refer to AN4073 on how to use this bit */ 
  #define PWR_CR1_VOS        0x0000C000	/* VOS[1:0] bits (Regulator voltage scaling output selection) */
  #define PWR_CR1_VOS_0      0x00004000	/* Bit 0 */
  #define PWR_CR1_VOS_1      0x00008000	/* Bit 1 */
  #define PWR_CR1_ODEN       0x00010000	/* Over Drive enable                   */
  #define PWR_CR1_ODSWEN     0x00020000	/* Over Drive switch enabled           */
  #define PWR_CR1_UDEN       0x000C0000	/* Under Drive enable in stop mode     */
  #define PWR_CR1_UDEN_0     0x00040000	/* Bit 0                               */
  #define PWR_CR1_UDEN_1     0x00080000	/* Bit 1                               */
#define TOFF_PWR_CSR1       0x0004		/* (RW) PWR power control/status register */
  #define PWR_CSR1_WUIF      0x00000001	/* Wake up internal Flag                            */
  #define PWR_CSR1_SBF       0x00000002	/* Standby Flag                                     */
  #define PWR_CSR1_PVDO      0x00000004	/* PVD Output                                       */
  #define PWR_CSR1_BRR       0x00000008	/* Backup regulator ready                           */
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define PWR_CSR1_EIWUP     0x00000100	/* Enable internal wakeup                           */
#endif
  #define PWR_CSR1_BRE       0x00000200	/* Backup regulator enable                          */
  #define PWR_CSR1_VOSRDY    0x00004000	/* Regulator voltage scaling output selection ready */
  #define PWR_CSR1_ODRDY     0x00010000	/* Over Drive generator ready                       */
  #define PWR_CSR1_ODSWRDY   0x00020000	/* Over Drive Switch ready                          */
  #define PWR_CSR1_UDSWRDY   0x000C0000	/* Under Drive ready                                */
  #define PWR_CSR1_UDRDY     PWR_CSR1_UDSWRDY
#define TOFF_PWR_CR2        0x0008		/* (RW) PWR power control register 2 */
  #define PWR_CR2_CWUPF1     0x00000001	/* Clear Wakeup Pin Flag for PA0      */
  #define PWR_CR2_CWUPF2     0x00000002	/* Clear Wakeup Pin Flag for PA2      */
  #define PWR_CR2_CWUPF3     0x00000004	/* Clear Wakeup Pin Flag for PC1      */
  #define PWR_CR2_CWUPF4     0x00000008	/* Clear Wakeup Pin Flag for PC13     */
  #define PWR_CR2_CWUPF5     0x00000010	/* Clear Wakeup Pin Flag for PI8      */
  #define PWR_CR2_CWUPF6     0x00000020	/* Clear Wakeup Pin Flag for PI11     */
  #define PWR_CR2_WUPP1      0x00000100	/* Wakeup Pin Polarity bit for PA0    */
  #define PWR_CR2_WUPP2      0x00000200	/* Wakeup Pin Polarity bit for PA2    */
  #define PWR_CR2_WUPP3      0x00000400	/* Wakeup Pin Polarity bit for PC1    */
  #define PWR_CR2_WUPP4      0x00000800	/* Wakeup Pin Polarity bit for PC13   */
  #define PWR_CR2_WUPP5      0x00001000	/* Wakeup Pin Polarity bit for PI8    */
  #define PWR_CR2_WUPP6      0x00002000	/* Wakeup Pin Polarity bit for PI11   */
#define TOFF_PWR_CSR2       0x000C		/* (RW) PWR power control/status register 2, Address offset: 0x0C */
  #define PWR_CSR2_WUPF1     0x00000001	/* Wakeup Pin Flag for PA0            */
  #define PWR_CSR2_WUPF2     0x00000002	/* Wakeup Pin Flag for PA2            */
  #define PWR_CSR2_WUPF3     0x00000004	/* Wakeup Pin Flag for PC1            */
  #define PWR_CSR2_WUPF4     0x00000008	/* Wakeup Pin Flag for PC13           */
  #define PWR_CSR2_WUPF5     0x00000010	/* Wakeup Pin Flag for PI8            */
  #define PWR_CSR2_WUPF6     0x00000020	/* Wakeup Pin Flag for PI11           */
  #define PWR_CSR2_EWUP1     0x00000100	/* Enable Wakeup Pin PA0              */
  #define PWR_CSR2_EWUP2     0x00000200	/* Enable Wakeup Pin PA2              */
  #define PWR_CSR2_EWUP3     0x00000400	/* Enable Wakeup Pin PC1              */
  #define PWR_CSR2_EWUP4     0x00000800	/* Enable Wakeup Pin PC13             */
  #define PWR_CSR2_EWUP5     0x00001000	/* Enable Wakeup Pin PI8              */
  #define PWR_CSR2_EWUP6     0x00002000	/* Enable Wakeup Pin PI11             */

/*
 *  DIGITAL TO ANALOG CONVTER
 */
#define TADR_DAC_BASE       (APB1PERIPH_BASE + 0x7400)
#define TOFF_DAC_CR         0x0000		/* (RW) DAC control register */
#define TOFF_DAC_SWTRIGR	0x0004		/* (RW) DAC software trigger register */
#define TOFF_DAC_DHR12R1    0x0008		/* (RW) DAC channel1 12-bit right-aligned data holding register */
#define TOFF_DAC_DHR12L1    0x000C		/* (RW) DAC channel1 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8R1     0x0010		/* (RW) DAC channel1 8-bit right aligned data holding register */
#define TOFF_DAC_DHR12R2    0x0014		/* (RW) DAC channel2 12-bit right aligned data holding register */
#define TOFF_DAC_DHR12L2    0x0018		/* (RW) DAC channel2 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8R2     0x001C		/* (RW) DAC channel2 8-bit right-aligned data holding register */
#define TOFF_DAC_DHR12RD    0x0020		/* (RW) Dual DAC 12-bit right-aligned data holding register */
#define TOFF_DAC_DHR12LD    0x0024		/* (RW) DUAL DAC 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8RD     0x0028		/* (RW) DUAL DAC 8-bit right aligned data holding register */
#define TOFF_DAC_DOR1       0x002C		/* (RW) DAC channel1 data output register */
#define TOFF_DAC_DOR2       0x0030		/* (RW) DAC channel2 data output register */
#define TOFF_DAC_SR         0x0034		/* (RW) DAC status register */


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (APB2PERIPH_BASE + 0x2000)
#define TADR_ADC2_BASE      (APB2PERIPH_BASE + 0x2100)
#define TADR_ADC3_BASE      (APB2PERIPH_BASE + 0x2200)
#define TOFF_ADC_SR         0x0000		/* (RW) ADC status register */
  #define ADC_SR_AWD                0x00000001	/* Analog watchdog flag */
  #define ADC_SR_EOC                0x00000002	/* End of conversion */
  #define ADC_SR_JEOC               0x00000004	/* Injected channel end of conversion */
  #define ADC_SR_JSTRT              0x00000008	/* Injected channel Start flag */
  #define ADC_SR_STRT               0x00000010	/* Regular channel Start flag */
  #define ADC_SR_OVR                0x00000020	/* Overrun flag */
#define TOFF_ADC_CR1        0x0004		/* (RW) ADC control register 1 */
  #define ADC_CR1_AWDCH             0x0000001F	/* AWDCH bits (Analog watchdog channel select bits) */
  #define ADC_CR1_AWDCH_0           0x00000001	/* Bit 0 */
  #define ADC_CR1_AWDCH_1           0x00000002	/* Bit 1 */
  #define ADC_CR1_AWDCH_2           0x00000004	/* Bit 2 */
  #define ADC_CR1_AWDCH_3           0x00000008	/* Bit 3 */
  #define ADC_CR1_AWDCH_4           0x00000010	/* Bit 4 */
  #define ADC_CR1_EOCIE             0x00000020	/* Interrupt enable for EOC */
  #define ADC_CR1_AWDIE             0x00000040	/* Analog Watchdog interrupt enable */
  #define ADC_CR1_JEOCIE            0x00000080	/* Interrupt enable for injected channels */
  #define ADC_CR1_SCAN              0x00000100	/* Scan mode */
  #define ADC_CR1_AWDSGL            0x00000200	/* Enable the watchdog on a single channel in scan mode */
  #define ADC_CR1_JAUTO             0x00000400	/* Automatic injected group conversion */
  #define ADC_CR1_DISCEN            0x00000800	/* Discontinuous mode on regular channels */
  #define ADC_CR1_JDISCEN           0x00001000	/* Discontinuous mode on injected channels */
  #define ADC_CR1_DISCNUM           0x0000E000	/* DISCNUM bits (Discontinuous mode channel count) */
  #define ADC_CR1_DISCNUM_0         0x00002000	/* Bit 0 */
  #define ADC_CR1_DISCNUM_1         0x00004000	/* Bit 1 */
  #define ADC_CR1_DISCNUM_2         0x00008000	/* Bit 2 */
  #define ADC_CR1_JAWDEN            0x00400000	/* Analog watchdog enable on injected channels */
  #define ADC_CR1_AWDEN             0x00800000	/* Analog watchdog enable on regular channels */
  #define ADC_CR1_RES               0x03000000	/* RES bits (Resolution) */
  #define ADC_CR1_RES_0             0x01000000	/* Bit 0 */
  #define ADC_CR1_RES_1             0x02000000	/* Bit 1 */
  #define ADC_CR1_OVRIE             0x04000000	/* Overrun interrupt enable */
#define TOFF_ADC_CR2        0x0008		/* (RW) ADC control register 2 */
  #define ADC_CR2_ADON              0x00000001	/* A/D Converter ON / OFF */
  #define ADC_CR2_CONT              0x00000002	/* Continuous Conversion */
  #define ADC_CR2_DMA               0x00000100	/* Direct Memory access mode */
  #define ADC_CR2_DDS               0x00000200	/* DMA disable selection (Single ADC) */
  #define ADC_CR2_EOCS              0x00000400	/* End of conversion selection */
  #define ADC_CR2_ALIGN             0x00000800	/* Data Alignment */
  #define ADC_CR2_JEXTSEL           0x000F0000	/* JEXTSEL bits (External event select for injected group) */
  #define ADC_CR2_JEXTSEL_0         0x00010000	/* Bit 0 */
  #define ADC_CR2_JEXTSEL_1         0x00020000	/* Bit 1 */
  #define ADC_CR2_JEXTSEL_2         0x00040000	/* Bit 2 */
  #define ADC_CR2_JEXTSEL_3         0x00080000	/* Bit 3 */
  #define ADC_CR2_JEXTEN            0x00300000	/* JEXTEN bits (External Trigger Conversion mode for injected channelsp) */
  #define ADC_CR2_JEXTEN_0          0x00100000	/* Bit 0 */
  #define ADC_CR2_JEXTEN_1          0x00200000	/* Bit 1 */
  #define ADC_CR2_JSWSTART          0x00400000	/* Start Conversion of injected channels */
  #define ADC_CR2_EXTSEL            0x0F000000	/* EXTSEL bits (External Event Select for regular group) */
  #define ADC_CR2_EXTSEL_0          0x01000000	/* Bit 0 */
  #define ADC_CR2_EXTSEL_1          0x02000000	/* Bit 1 */
  #define ADC_CR2_EXTSEL_2          0x04000000	/* Bit 2 */
  #define ADC_CR2_EXTSEL_3          0x08000000	/* Bit 3 */
  #define ADC_CR2_EXTEN             0x30000000	/* EXTEN bits (External Trigger Conversion mode for regular channelsp) */
  #define ADC_CR2_EXTEN_0           0x10000000	/* Bit 0 */
  #define ADC_CR2_EXTEN_1           0x20000000	/* Bit 1 */
  #define ADC_CR2_SWSTART           0x40000000	/* Start Conversion of regular channels */
#define TOFF_ADC_SMPR1      0x000C		/* (RW) ADC sample time register 1 */
  #define ADC_SMPR1_SMP10           0x00000007	/* SMP10 bits (Channel 10 Sample time selection) */
  #define ADC_SMPR1_SMP11           0x00000038	/* SMP11 bits (Channel 11 Sample time selection) */
  #define ADC_SMPR1_SMP12           0x000001C0	/* SMP12 bits (Channel 12 Sample time selection) */
  #define ADC_SMPR1_SMP13           0x00000E00	/* SMP13 bits (Channel 13 Sample time selection) */
  #define ADC_SMPR1_SMP14           0x00007000	/* SMP14 bits (Channel 14 Sample time selection) */
  #define ADC_SMPR1_SMP15           0x00038000	/* SMP15 bits (Channel 15 Sample time selection) */
  #define ADC_SMPR1_SMP16           0x001C0000	/* SMP16 bits (Channel 16 Sample time selection) */
  #define ADC_SMPR1_SMP17           0x00E00000	/* SMP17 bits (Channel 17 Sample time selection) */
  #define ADC_SMPR1_SMP18           0x07000000	/* SMP18 bits (Channel 18 Sample time selection) */
#define TOFF_ADC_SMPR2      0x0010		/* (RW) ADC sample time register 2 */
  #define ADC_SMPR2_SMP0            0x00000007	/* SMP0 bits (Channel 0 Sample time selection) */
  #define ADC_SMPR2_SMP1            0x00000038	/* SMP1 bits (Channel 1 Sample time selection) */
  #define ADC_SMPR2_SMP2            0x000001C0	/* SMP2 bits (Channel 2 Sample time selection) */
  #define ADC_SMPR2_SMP3            0x00000E00	/* SMP3 bits (Channel 3 Sample time selection) */
  #define ADC_SMPR2_SMP4            0x00007000	/* SMP4 bits (Channel 4 Sample time selection) */
  #define ADC_SMPR2_SMP5            0x00038000	/* SMP5 bits (Channel 5 Sample time selection) */
  #define ADC_SMPR2_SMP6            0x001C0000	/* SMP6 bits (Channel 6 Sample time selection) */
  #define ADC_SMPR2_SMP7            0x00E00000	/* SMP7 bits (Channel 7 Sample time selection) */
  #define ADC_SMPR2_SMP8            0x07000000	/* SMP8 bits (Channel 8 Sample time selection) */
  #define ADC_SMPR2_SMP9            0x38000000	/* SMP9 bits (Channel 9 Sample time selection) */
#define TOFF_ADC_JOFR1      0x0014		/* (RW) ADC injected channel data offset register 1 */
#define TOFF_ADC_JOFR2      0x0018		/* (RW) ADC injected channel data offset register 2 */
#define TOFF_ADC_JOFR3      0x001C		/* (RW) ADC injected channel data offset register 3 */
#define TOFF_ADC_JOFR4      0x0020		/* (RW) ADC injected channel data offset register 4 */
#define TOFF_ADC_HTR        0x0024		/* (RW) ADC watchdog higher threshold register */
#define TOFF_ADC_LTR        0x0028		/* (RW) ADC watchdog lower threshold register */
#define TOFF_ADC_SQR1       0x002C		/* (RW) ADC regular sequence register 1 */
  #define ADC_SQR1_SQ13             0x0000001F	/* SQ13 bits (13th conversion in regular sequence) */
  #define ADC_SQR1_SQ14             0x000003E0	/* SQ14 bits (14th conversion in regular sequence) */
  #define ADC_SQR1_SQ15             0x00007C00	/* SQ15 bits (15th conversion in regular sequence) */
  #define ADC_SQR1_SQ16             0x000F8000	/* SQ16 bits (16th conversion in regular sequence) */
  #define ADC_SQR1_L                0x00F00000	/* L[3:0] bits (Regular channel sequence length) */
#define TOFF_ADC_SQR2       0x0030		/* (RW) ADC regular sequence register 2 */
  #define ADC_SQR2_SQ7              0x0000001F	/* SQ7 bits (7th conversion in regular sequence) */
  #define ADC_SQR2_SQ8              0x000003E0	/* SQ8 bits (8th conversion in regular sequence) */
  #define ADC_SQR2_SQ9              0x00007C00	/* SQ9 bits (9th conversion in regular sequence) */
  #define ADC_SQR2_SQ10             0x000F8000	/* SQ10 bits (10th conversion in regular sequence) */
  #define ADC_SQR2_SQ11             0x01F00000	/* SQ11 bits (11th conversion in regular sequence) */
  #define ADC_SQR2_SQ12             0x3E000000	/* SQ12 bits (12th conversion in regular sequence) */
#define TOFF_ADC_SQR3       0x0034		/* (RW) ADC regular sequence register 3 */
  #define ADC_SQR3_SQ1              0x0000001F	/* SQ1 bits (1st conversion in regular sequence) */
  #define ADC_SQR3_SQ2              0x000003E0	/* SQ2 bits (2nd conversion in regular sequence) */
  #define ADC_SQR3_SQ3              0x00007C00	/* SQ3 bits (3rd conversion in regular sequence) */
  #define ADC_SQR3_SQ4              0x000F8000	/* SQ4 bits (4th conversion in regular sequence) */
  #define ADC_SQR3_SQ5              0x01F00000	/* SQ5 bits (5th conversion in regular sequence) */
  #define ADC_SQR3_SQ6              0x3E000000	/* SQ6 bits (6th conversion in regular sequence) */
#define TOFF_ADC_JSQR       0x0038		/* (RW) ADC injected sequence register */
#define TOFF_ADC_JDR1       0x003C		/* (RW) ADC injected data register 1 */
#define TOFF_ADC_JDR2       0x0040		/* (RW) ADC injected data register 2 */
#define TOFF_ADC_JDR3       0x0044		/* (RW) ADC injected data register 3 */
#define TOFF_ADC_JDR4       0x0048		/* (RW) ADC injected data register 4 */
#define TOFF_ADC_DR         0x004C		/* (RW) ADC regular data register */

#define TADR_ADC_BASE       (APB2PERIPH_BASE + 0x2300)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC Common status register */
#define TOFF_ADC_CCR        0x0004		/* (RW) ADC common control register */
  #define ADC_CCR_MULTI             0x0000001F	/* MULTI[4:0] bits (Multi-ADC mode selection) */  
  #define ADC_CCR_MULTI_0           0x00000001	/* Bit 0 */
  #define ADC_CCR_MULTI_1           0x00000002	/* Bit 1 */
  #define ADC_CCR_MULTI_2           0x00000004	/* Bit 2 */
  #define ADC_CCR_MULTI_3           0x00000008	/* Bit 3 */
  #define ADC_CCR_MULTI_4           0x00000010	/* Bit 4 */
  #define ADC_CCR_DELAY             0x00000F00	/* DELAY[3:0] bits (Delay between 2 sampling phases) */  
  #define ADC_CCR_DELAY_0           0x00000100	/* Bit 0 */
  #define ADC_CCR_DELAY_1           0x00000200	/* Bit 1 */
  #define ADC_CCR_DELAY_2           0x00000400	/* Bit 2 */
  #define ADC_CCR_DELAY_3           0x00000800	/* Bit 3 */
  #define ADC_CCR_DDS               0x00002000	/* DMA disable selection (Multi-ADC mode) */
  #define ADC_CCR_DMA               0x0000C000	/* DMA[1:0] bits (Direct Memory Access mode for multimode) */  
  #define ADC_CCR_DMA_0             0x00004000	/* Bit 0 */
  #define ADC_CCR_DMA_1             0x00008000	/* Bit 1 */
  #define ADC_CCR_ADCPRE            0x00030000	/* ADCPRE[1:0] bits (ADC prescaler) */  
  #define ADC_CCR_ADCPRE_0          0x00010000	/* Bit 0 */
  #define ADC_CCR_ADCPRE_1          0x00020000	/* Bit 1 */
  #define ADC_CCR_VBATE             0x00400000	/* VBAT Enable */
  #define ADC_CCR_TSVREFE           0x00800000	/* Temperature Sensor and VREFINT Enable */
#define TOFF_ADC_CDR        0x0008		/* (RW) ADC common regular data register for dual AND triple modes */

/*
 *  SD HOST INTERFACE
 */
#define TADR_SDMMC1_BASE    (APB2PERIPH_BASE + 0x2C00)
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
#define TADR_SDMMC2_BASE    (APB2PERIPH_BASE + 0x1C00)
#endif
#define TOFF_SDIO_POWER     0x0000		/* (RW) SDIO power control register */
  #define SDMMC_POWER_PWRCTRL   0x00000003	/* PWRCTRL[1:0] bits (Power supply control bits) */
  #define SDMMC_POWER_PWRCTRL_0 0x00000001	/* Bit 0 */
  #define SDMMC_POWER_PWRCTRL_1 0x00000002	/* Bit 1 */
#define TOFF_SDIO_CLKCR     0x0004		/* (RW) SDI clock control register */
  #define SDMMC_CLKCR_CLKDIV    0x000000FF	/* Clock divide factor             */
  #define SDMMC_CLKCR_CLKEN     0x00000100	/* Clock enable bit                */
  #define SDMMC_CLKCR_PWRSAV    0x00000200	/* Power saving configuration bit  */
  #define SDMMC_CLKCR_BYPASS    0x00000400	/* Clock divider bypass enable bit */
  #define SDMMC_CLKCR_WIDBUS    0x00001800	/* WIDBUS[1:0] bits (Wide bus mode enable bit) */
  #define SDMMC_CLKCR_WIDBUS_0  0x00000800	/* Bit 0 */
  #define SDMMC_CLKCR_WIDBUS_1  0x00001000	/* Bit 1 */
  #define SDMMC_CLKCR_NEGEDGE   0x00002000	/* SDMMC_CK dephasing selection bit */
  #define SDMMC_CLKCR_HWFC_EN   0x00004000	/* HW Flow Control enable          */
#define TOFF_SDIO_ARG       0x0008		/* (RW) SDIO argument register */
#define TOFF_SDIO_CMD       0x000C		/* (RW) SDIO command register */
  #define SDMMC_CMD_CMDINDEX    0x0000003F	/* Command Index                               */
  #define SDMMC_CMD_WAITRESP    0x000000C0	/* WAITRESP[1:0] bits (Wait for response bits) */
  #define SDMMC_CMD_WAITRESP_0  0x00000040	/* Bit 0 */
  #define SDMMC_CMD_WAITRESP_1  0x00000080	/* Bit 1 */
  #define SDMMC_CMD_WAITINT     0x00000100	/* CPSM Waits for Interrupt Request */
  #define SDMMC_CMD_WAITPEND    0x00000200	/* CPSM Waits for ends of data transfer (CmdPend internal signal) */
  #define SDMMC_CMD_CPSMEN      0x00000400	/* Command path state machine (CPSM) Enable bit */
  #define SDMMC_CMD_SDIOSUSPEND 0x00000800	/* SD I/O suspend command */
#define TOFF_SDIO_RESPCMD   0x0010		/* (R)  SDIO command response register */
#define TOFF_SDIO_RESP      0x0014		/* (R)  SDIO response 1 register */
#define TOFF_SDIO_RESP2     0x0018		/* (R)  SDIO response 2 register */
#define TOFF_SDIO_RESP3     0x001C		/* (R)  SDIO response 3 register */
#define TOFF_SDIO_RESP4     0x0020		/* (R)  SDIO response 4 register */
#define TOFF_SDIO_DTIMER    0x0024		/* (RW) SDIO data timer register */
#define TOFF_SDIO_DLEN      0x0028		/* (RW) SDIO data length register */
#define TOFF_SDIO_DCTRL     0x002C		/* (RW) SDIO data control register */
  #define SDMMC_DCTRL_DTEN      0x00000001	/* Data transfer enabled bit */
  #define SDMMC_DCTRL_DTDIR     0x00000002	/* Data transfer direction selection */
  #define SDMMC_DCTRL_DTMODE    0x00000004	/* Data transfer mode selection      */
  #define SDMMC_DCTRL_DMAEN     0x00000008	/* DMA enabled bit                   */
  #define SDMMC_DCTRL_DBLOCKSIZE    0x00F0	/* DBLOCKSIZE[3:0] bits (Data block size) */
  #define SDMMC_DCTRL_DBLOCKSIZE_0  0x0010	/* Bit 0 */
  #define SDMMC_DCTRL_DBLOCKSIZE_1  0x0020	/* Bit 1 */
  #define SDMMC_DCTRL_DBLOCKSIZE_2  0x0040	/* Bit 2 */
  #define SDMMC_DCTRL_DBLOCKSIZE_3  0x0080	/* Bit 3 */
  #define SDMMC_DCTRL_RWSTART   0x00000100	/* Read wait start */
  #define SDMMC_DCTRL_RWSTOP    0x00000200	/* Read wait stop */
  #define SDMMC_DCTRL_RWMOD     0x00000400	/* Read wait mode */
  #define SDMMC_DCTRL_SDIOEN    0x00000800	/* SD I/O enable functions */
#define TOFF_SDIO_DCOUNT    0x0030		/* (R)  SDIO data counter register */
#define TOFF_SDIO_STA       0x0034		/* (R)  SDIO status register */
  #define SDMMC_STA_CCRCFAIL    0x00000001	/* Command response received (CRC check failed)  */
  #define SDMMC_STA_DCRCFAIL    0x00000002	/* Data block sent/received (CRC check failed)   */
  #define SDMMC_STA_CTIMEOUT    0x00000004	/* Command response timeout                      */
  #define SDMMC_STA_DTIMEOUT    0x00000008	/* Data timeout                                  */
  #define SDMMC_STA_TXUNDERR    0x00000010	/* Transmit FIFO underrun error                  */
  #define SDMMC_STA_RXOVERR     0x00000020	/* Received FIFO overrun error                   */
  #define SDMMC_STA_CMDREND     0x00000040	/* Command response received (CRC check passed)  */
  #define SDMMC_STA_CMDSENT     0x00000080	/* Command sent (no response required)           */
  #define SDMMC_STA_DATAEND     0x00000100	/* Data end (data counter, SDIDCOUNT, is zero)   */
  #define SDMMC_STA_DBCKEND     0x00000400	/* Data block sent/received (CRC check passed)   */
  #define SDMMC_STA_CMDACT      0x00000800	/* Command transfer in progress                  */
  #define SDMMC_STA_TXACT       0x00001000	/* Data transmit in progress                     */
  #define SDMMC_STA_RXACT       0x00002000	/* Data receive in progress                      */
  #define SDMMC_STA_TXFIFOHE    0x00004000	/* Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
  #define SDMMC_STA_RXFIFOHF    0x00008000	/* Receive FIFO Half Full: there are at least 8 words in the FIFO */
  #define SDMMC_STA_TXFIFOF     0x00010000	/* Transmit FIFO full */
  #define SDMMC_STA_RXFIFOF     0x00020000	/* Receive FIFO full */
  #define SDMMC_STA_TXFIFOE     0x00040000	/* Transmit FIFO empty */
  #define SDMMC_STA_RXFIFOE     0x00080000	/* Receive FIFO empty */
  #define SDMMC_STA_TXDAVL      0x00100000	/* Data available in transmit FIFO */
  #define SDMMC_STA_RXDAVL      0x00200000	/* Data available in receive FIFO */
  #define SDMMC_STA_SDIOIT      0x00400000	/* SDMMC interrupt received */
#define TOFF_SDIO_ICR       0x0038		/* (RW) SDIO interrupt clear register */
  #define SDMMC_ICR_CCRCFAILC   0x00000001	/* CCRCFAIL flag clear bit */
  #define SDMMC_ICR_DCRCFAILC   0x00000002	/* DCRCFAIL flag clear bit */
  #define SDMMC_ICR_CTIMEOUTC   0x00000004	/* CTIMEOUT flag clear bit */
  #define SDMMC_ICR_DTIMEOUTC   0x00000008	/* DTIMEOUT flag clear bit */
  #define SDMMC_ICR_TXUNDERRC   0x00000010	/* TXUNDERR flag clear bit */
  #define SDMMC_ICR_RXOVERRC    0x00000020	/* RXOVERR flag clear bit  */
  #define SDMMC_ICR_CMDRENDC    0x00000040	/* CMDREND flag clear bit  */
  #define SDMMC_ICR_CMDSENTC    0x00000080	/* CMDSENT flag clear bit  */
  #define SDMMC_ICR_DATAENDC    0x00000100	/* DATAEND flag clear bit  */
  #define SDMMC_ICR_DBCKENDC    0x00000400	/* DBCKEND flag clear bit  */
  #define SDMMC_ICR_SDIOITC     0x00400000	/* SDMMCIT flag clear bit   */
#define TOFF_SDIO_MASK      0x003C		/* (RW) SDIO mask register */
  #define SDMMC_MASK_CCRCFAILIE 0x00000001	/* Command CRC Fail Interrupt Enable */
  #define SDMMC_MASK_DCRCFAILIE 0x00000002	/* Data CRC Fail Interrupt Enable */
  #define SDMMC_MASK_CTIMEOUTIE 0x00000004	/* Command TimeOut Interrupt Enable */
  #define SDMMC_MASK_DTIMEOUTIE 0x00000008	/* Data TimeOut Interrupt Enable */
  #define SDMMC_MASK_TXUNDERRIE 0x00000010	/* Tx FIFO UnderRun Error Interrupt Enable */
  #define SDMMC_MASK_RXOVERRIE  0x00000020	/* Rx FIFO OverRun Error Interrupt Enable */
  #define SDMMC_MASK_CMDRENDIE  0x00000040	/* Command Response Received Interrupt Enable */
  #define SDMMC_MASK_CMDSENTIE  0x00000080	/* Command Sent Interrupt Enable */
  #define SDMMC_MASK_DATAENDIE  0x00000100	/* Data End Interrupt Enable */
  #define SDMMC_MASK_DBCKENDIE  0x00000400	/* Data Block End Interrupt Enable */
  #define SDMMC_MASK_CMDACTIE   0x00000800	/* CCommand Acting Interrupt Enable */
  #define SDMMC_MASK_TXACTIE    0x00001000	/* Data Transmit Acting Interrupt Enable */
  #define SDMMC_MASK_RXACTIE    0x00002000	/* Data receive acting interrupt enabled */
  #define SDMMC_MASK_TXFIFOHEIE 0x00004000	/* Tx FIFO Half Empty interrupt Enable */
  #define SDMMC_MASK_RXFIFOHFIE 0x00008000	/* Rx FIFO Half Full interrupt Enable */
  #define SDMMC_MASK_TXFIFOFIE  0x00010000	/* Tx FIFO Full interrupt Enable */
  #define SDMMC_MASK_RXFIFOFIE  0x00020000	/* Rx FIFO Full interrupt Enable */
  #define SDMMC_MASK_TXFIFOEIE  0x00040000	/* Tx FIFO Empty interrupt Enable */
  #define SDMMC_MASK_RXFIFOEIE  0x00080000	/* Rx FIFO Empty interrupt Enable */
  #define SDMMC_MASK_TXDAVLIE   0x00100000	/* Data available in Tx FIFO interrupt Enable */
  #define SDMMC_MASK_RXDAVLIE   0x00200000	/* Data available in Rx FIFO interrupt Enable */
  #define SDMMC_MASK_SDIOITIE   0x00400000	/* SDMMC Mode Interrupt Received interrupt Enable */
#define TOFF_SDIO_FIFOCNT   0x0048		/* (R)  SDIO FIFO counter register */
#define TOFF_SDIO_FIFO      0x0080		/* (RW) SDIO data FIFO register */

/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (APB2PERIPH_BASE + 0x3800)
#define TOFF_SYSCFG_MEMRMP  0x0000		/* (RW) SYSCFG memory remap register */
#define TOFF_SYSCFG_PMC     0x0004		/* (RW) SYSCFG peripheral mode configuration register */
#define TOFF_SYSCFG_EXTICR0 0x0008		/* (RW) SYSCFG external interrupt configuration registers 0 */
#define TOFF_SYSCFG_EXTICR1 0x000C		/* (RW) SYSCFG external interrupt configuration registers 1 */
#define TOFF_SYSCFG_EXTICR2 0x0010		/* (RW) SYSCFG external interrupt configuration registers 2 */
#define TOFF_SYSCFG_EXTICR3 0x0014		/* (RW) SYSCFG external interrupt configuration registers 3 */
#define TOFF_SYSCFG_CMPCR   0x0020		/* (RW) SYSCFG Compensation cell control register */

/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (APB2PERIPH_BASE + 0x3C00)
#define TOFF_EXTI_IMR       0x0000		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR_MR0       0x00000001	/* Interrupt Mask on line 0 */
  #define EXTI_IMR_MR1       0x00000002	/* Interrupt Mask on line 1 */
  #define EXTI_IMR_MR2       0x00000004	/* Interrupt Mask on line 2 */
  #define EXTI_IMR_MR3       0x00000008	/* Interrupt Mask on line 3 */
  #define EXTI_IMR_MR4       0x00000010	/* Interrupt Mask on line 4 */
  #define EXTI_IMR_MR5       0x00000020	/* Interrupt Mask on line 5 */
  #define EXTI_IMR_MR6       0x00000040	/* Interrupt Mask on line 6 */
  #define EXTI_IMR_MR7       0x00000080	/* Interrupt Mask on line 7 */
  #define EXTI_IMR_MR8       0x00000100	/* Interrupt Mask on line 8 */
  #define EXTI_IMR_MR9       0x00000200	/* Interrupt Mask on line 9 */
  #define EXTI_IMR_MR10      0x00000400	/* Interrupt Mask on line 10 */
  #define EXTI_IMR_MR11      0x00000800	/* Interrupt Mask on line 11 */
  #define EXTI_IMR_MR12      0x00001000	/* Interrupt Mask on line 12 */
  #define EXTI_IMR_MR13      0x00002000	/* Interrupt Mask on line 13 */
  #define EXTI_IMR_MR14      0x00004000	/* Interrupt Mask on line 14 */
  #define EXTI_IMR_MR15      0x00008000	/* Interrupt Mask on line 15 */
  #define EXTI_IMR_MR16      0x00010000	/* Interrupt Mask on line 16 */
  #define EXTI_IMR_MR17      0x00020000	/* Interrupt Mask on line 17 */
  #define EXTI_IMR_MR18      0x00040000	/* Interrupt Mask on line 18 */
  #define EXTI_IMR_MR19      0x00080000	/* Interrupt Mask on line 19 */
  #define EXTI_IMR_MR20      0x00100000	/* Interrupt Mask on line 20 */
  #define EXTI_IMR_MR21      0x00200000	/* Interrupt Mask on line 21 */
  #define EXTI_IMR_MR22      0x00400000	/* Interrupt Mask on line 22 */
  #define EXTI_IMR_MR23      0x00800000	/* Interrupt Mask on line 23 */
#define TOFF_EXTI_EMR       0x0004		/* (RW) EXTI Event mask register */
  #define EXTI_EMR_MR0       0x00000001	/* Event Mask on line 0 */
  #define EXTI_EMR_MR1       0x00000002	/* Event Mask on line 1 */
  #define EXTI_EMR_MR2       0x00000004	/* Event Mask on line 2 */
  #define EXTI_EMR_MR3       0x00000008	/* Event Mask on line 3 */
  #define EXTI_EMR_MR4       0x00000010	/* Event Mask on line 4 */
  #define EXTI_EMR_MR5       0x00000020	/* Event Mask on line 5 */
  #define EXTI_EMR_MR6       0x00000040	/* Event Mask on line 6 */
  #define EXTI_EMR_MR7       0x00000080	/* Event Mask on line 7 */
  #define EXTI_EMR_MR8       0x00000100	/* Event Mask on line 8 */
  #define EXTI_EMR_MR9       0x00000200	/* Event Mask on line 9 */
  #define EXTI_EMR_MR10      0x00000400	/* Event Mask on line 10 */
  #define EXTI_EMR_MR11      0x00000800	/* Event Mask on line 11 */
  #define EXTI_EMR_MR12      0x00001000	/* Event Mask on line 12 */
  #define EXTI_EMR_MR13      0x00002000	/* Event Mask on line 13 */
  #define EXTI_EMR_MR14      0x00004000	/* Event Mask on line 14 */
  #define EXTI_EMR_MR15      0x00008000	/* Event Mask on line 15 */
  #define EXTI_EMR_MR16      0x00010000	/* Event Mask on line 16 */
  #define EXTI_EMR_MR17      0x00020000	/* Event Mask on line 17 */
  #define EXTI_EMR_MR18      0x00040000	/* Event Mask on line 18 */
  #define EXTI_EMR_MR19      0x00080000	/* Event Mask on line 19 */
  #define EXTI_EMR_MR20      0x00100000	/* Event Mask on line 20 */
  #define EXTI_EMR_MR21      0x00200000	/* Event Mask on line 21 */
  #define EXTI_EMR_MR22      0x00400000	/* Event Mask on line 22 */
  #define EXTI_EMR_MR23      0x00800000	/* Event Mask on line 23 */
#define TOFF_EXTI_RTSR      0x0008		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR_TR0      0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR_TR1      0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR_TR2      0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR_TR3      0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR_TR4      0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR_TR5      0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR_TR6      0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR_TR7      0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR_TR8      0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR_TR9      0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR_TR10     0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR_TR11     0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR_TR12     0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR_TR13     0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR_TR14     0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR_TR15     0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR_TR16     0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR_TR17     0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR_TR18     0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR_TR19     0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR_TR20     0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR_TR21     0x00200000	/* Rising trigger event configuration bit of line 21 */
  #define EXTI_RTSR_TR22     0x00400000	/* Rising trigger event configuration bit of line 22 */
  #define EXTI_RTSR_TR23     0x00800000	/* Rising trigger event configuration bit of line 23 */
#define TOFF_EXTI_FTSR      0x000C		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR_TR0      0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR_TR1      0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR_TR2      0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR_TR3      0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR_TR4      0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR_TR5      0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR_TR6      0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR_TR7      0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR_TR8      0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR_TR9      0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR_TR10     0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR_TR11     0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR_TR12     0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR_TR13     0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR_TR14     0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR_TR15     0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR_TR16     0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR_TR17     0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR_TR18     0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR_TR19     0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR_TR20     0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR_TR21     0x00200000	/* Falling trigger event configuration bit of line 21 */
  #define EXTI_FTSR_TR22     0x00400000	/* Falling trigger event configuration bit of line 22 */
  #define EXTI_FTSR_TR23     0x00800000	/* Falling trigger event configuration bit of line 23 */
#define TOFF_EXTI_SWIER     0x0010		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER_SWIER0  0x00000001	/* Software Interrupt on line 0 */
  #define EXTI_SWIER_SWIER1  0x00000002	/* Software Interrupt on line 1 */
  #define EXTI_SWIER_SWIER2  0x00000004	/* Software Interrupt on line 2 */
  #define EXTI_SWIER_SWIER3  0x00000008	/* Software Interrupt on line 3 */
  #define EXTI_SWIER_SWIER4  0x00000010	/* Software Interrupt on line 4 */
  #define EXTI_SWIER_SWIER5  0x00000020	/* Software Interrupt on line 5 */
  #define EXTI_SWIER_SWIER6  0x00000040	/* Software Interrupt on line 6 */
  #define EXTI_SWIER_SWIER7  0x00000080	/* Software Interrupt on line 7 */
  #define EXTI_SWIER_SWIER8  0x00000100	/* Software Interrupt on line 8 */
  #define EXTI_SWIER_SWIER9  0x00000200	/* Software Interrupt on line 9 */
  #define EXTI_SWIER_SWIER10 0x00000400	/* Software Interrupt on line 10 */
  #define EXTI_SWIER_SWIER11 0x00000800	/* Software Interrupt on line 11 */
  #define EXTI_SWIER_SWIER12 0x00001000	/* Software Interrupt on line 12 */
  #define EXTI_SWIER_SWIER13 0x00002000	/* Software Interrupt on line 13 */
  #define EXTI_SWIER_SWIER14 0x00004000	/* Software Interrupt on line 14 */
  #define EXTI_SWIER_SWIER15 0x00008000	/* Software Interrupt on line 15 */
  #define EXTI_SWIER_SWIER16 0x00010000	/* Software Interrupt on line 16 */
  #define EXTI_SWIER_SWIER17 0x00020000	/* Software Interrupt on line 17 */
  #define EXTI_SWIER_SWIER18 0x00040000	/* Software Interrupt on line 18 */
  #define EXTI_SWIER_SWIER19 0x00080000	/* Software Interrupt on line 19 */
  #define EXTI_SWIER_SWIER20 0x00100000	/* Software Interrupt on line 20 */
  #define EXTI_SWIER_SWIER21 0x00200000	/* Software Interrupt on line 21 */
  #define EXTI_SWIER_SWIER22 0x00400000	/* Software Interrupt on line 22 */
  #define EXTI_SWIER_SWIER23 0x00800000	/* Software Interrupt on line 23 */
#define TOFF_EXTI_PR        0x0014		/* (RW) EXTI Pending register */
  #define EXTI_PR_PR0        0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR_PR1        0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR_PR2        0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR_PR3        0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR_PR4        0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR_PR5        0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR_PR6        0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR_PR7        0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR_PR8        0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR_PR9        0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR_PR10       0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR_PR11       0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR_PR12       0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR_PR13       0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR_PR14       0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR_PR15       0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR_PR16       0x00010000	/* Pending bit for line 16 */
  #define EXTI_PR_PR17       0x00020000	/* Pending bit for line 17 */
  #define EXTI_PR_PR18       0x00040000	/* Pending bit for line 18 */
  #define EXTI_PR_PR19       0x00080000	/* Pending bit for line 19 */
  #define EXTI_PR_PR20       0x00100000	/* Pending bit for line 20 */
  #define EXTI_PR_PR21       0x00200000	/* Pending bit for line 21 */
  #define EXTI_PR_PR22       0x00400000	/* Pending bit for line 22 */
  #define EXTI_PR_PR23       0x00800000	/* Pending bit for line 23 */


/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (AHB1PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (AHB1PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (AHB1PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (AHB1PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (AHB1PERIPH_BASE + 0x1000)
#define TADR_GPIOF_BASE     (AHB1PERIPH_BASE + 0x1400)
#define TADR_GPIOG_BASE     (AHB1PERIPH_BASE + 0x1800)
#define TADR_GPIOH_BASE     (AHB1PERIPH_BASE + 0x1C00)
#define TADR_GPIOI_BASE     (AHB1PERIPH_BASE + 0x2000)
#define TADR_GPIOJ_BASE     (AHB1PERIPH_BASE + 0x2400)
#define TADR_GPIOK_BASE     (AHB1PERIPH_BASE + 0x2800)
#define TOFF_GPIO_MODER     0x0000		/* (RW) GPIO port mode register */
  #define GPIO_MODER_MODER0  0x00000003
  #define GPIO_MODER_MODER1  0x0000000C
  #define GPIO_MODER_MODER2  0x00000030
  #define GPIO_MODER_MODER3  0x000000C0
  #define GPIO_MODER_MODER4  0x00000300
  #define GPIO_MODER_MODER5  0x00000C00
  #define GPIO_MODER_MODER6  0x00003000
  #define GPIO_MODER_MODER7  0x0000C000
  #define GPIO_MODER_MODER8  0x00030000
  #define GPIO_MODER_MODER9  0x000C0000
  #define GPIO_MODER_MODER10 0x00300000
  #define GPIO_MODER_MODER11 0x00C00000
  #define GPIO_MODER_MODER12 0x03000000
  #define GPIO_MODER_MODER13 0x0C000000
  #define GPIO_MODER_MODER14 0x30000000
  #define GPIO_MODER_MODER15 0xC0000000
#define TOFF_GPIO_OTYPER    0x0004		/* (RW) GPIO port output type register */
  #define GPIO_OTYPER_OT     0x00000001
  #define GPIO_OTYPER_OT_0   0x00000001
  #define GPIO_OTYPER_OT_1   0x00000002
  #define GPIO_OTYPER_OT_2   0x00000004
  #define GPIO_OTYPER_OT_3   0x00000008
  #define GPIO_OTYPER_OT_4   0x00000010
  #define GPIO_OTYPER_OT_5   0x00000020
  #define GPIO_OTYPER_OT_6   0x00000040
  #define GPIO_OTYPER_OT_7   0x00000080
  #define GPIO_OTYPER_OT_8   0x00000100
  #define GPIO_OTYPER_OT_9   0x00000200
  #define GPIO_OTYPER_OT_10  0x00000400
  #define GPIO_OTYPER_OT_11  0x00000800
  #define GPIO_OTYPER_OT_12  0x00001000
  #define GPIO_OTYPER_OT_13  0x00002000
  #define GPIO_OTYPER_OT_14  0x00004000
  #define GPIO_OTYPER_OT_15  0x00008000
#define TOFF_GPIO_OSPEEDR   0x0008		/* (RW) GPIO port output speed register */
  #define GPIO_OSPEEDER_OSPEEDR0 0x00000003
  #define GPIO_OSPEEDER_OSPEEDR1 0x0000000C
  #define GPIO_OSPEEDER_OSPEEDR2 0x00000030
  #define GPIO_OSPEEDER_OSPEEDR3 0x000000C0
  #define GPIO_OSPEEDER_OSPEEDR4 0x00000300
  #define GPIO_OSPEEDER_OSPEEDR5 0x00000C00
  #define GPIO_OSPEEDER_OSPEEDR6 0x00003000
  #define GPIO_OSPEEDER_OSPEEDR7 0x0000C000
  #define GPIO_OSPEEDER_OSPEEDR8 0x00030000
  #define GPIO_OSPEEDER_OSPEEDR9 0x000C0000
  #define GPIO_OSPEEDER_OSPEEDR10 0x00300000
  #define GPIO_OSPEEDER_OSPEEDR11 0x00C00000
  #define GPIO_OSPEEDER_OSPEEDR12 0x03000000
  #define GPIO_OSPEEDER_OSPEEDR13 0x0C000000
  #define GPIO_OSPEEDER_OSPEEDR14 0x30000000
  #define GPIO_OSPEEDER_OSPEEDR15 0xC0000000
#define TOFF_GPIO_PUPDR     0x000C		/* (RW) GPIO port pull-up/pull-down register */
  #define GPIO_PUPDR_PUPDR0  0x00000003
  #define GPIO_PUPDR_PUPDR1  0x0000000C
  #define GPIO_PUPDR_PUPDR2  0x00000030
  #define GPIO_PUPDR_PUPDR3  0x000000C0
  #define GPIO_PUPDR_PUPDR4  0x00000300
  #define GPIO_PUPDR_PUPDR5  0x00000C00
  #define GPIO_PUPDR_PUPDR6  0x00003000
  #define GPIO_PUPDR_PUPDR7  0x0000C000
  #define GPIO_PUPDR_PUPDR8  0x00030000
  #define GPIO_PUPDR_PUPDR9  0x000C0000
  #define GPIO_PUPDR_PUPDR10 0x00300000
  #define GPIO_PUPDR_PUPDR11 0x00C00000
  #define GPIO_PUPDR_PUPDR12 0x03000000
  #define GPIO_PUPDR_PUPDR13 0x0C000000
  #define GPIO_PUPDR_PUPDR14 0x30000000
  #define GPIO_PUPDR_PUPDR15 0xC0000000
#define TOFF_GPIO_IDR       0x0010		/* (R)  GPIO port input data register */
#define TOFF_GPIO_ODR       0x0014		/* (RW) GPIO port output data register */
#define TOFF_GPIO_BSRR      0x0018		/* (RW) GPIO port bit set/reset low register */
#define TOFF_GPIO_LCKR      0x001C		/* (RW) GPIO port configuration lock register */
#define TOFF_GPIO_AFR0      0x0020		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_AFR1      0x0024		/* (RW) GPIO alternate function registers */

/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (AHB1PERIPH_BASE + 0x3000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */
#define TOFF_CRC_INIT       0x0010		/* (RW) Initial CRC value register */
#define TOFF_CRC_POL        0x0014		/* (RW) CRC polynomial register */

/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (AHB1PERIPH_BASE + 0x3800)
#define TOFF_RCC_CR         0x0000		/* (RW) RCC clock control register */
  #define RCC_CR_HSION             0x00000001
  #define RCC_CR_HSIRDY            0x00000002
  #define RCC_CR_HSITRIM           0x000000F8
  #define RCC_CR_HSITRIM_0         0x00000008	/* Bit 0 */
  #define RCC_CR_HSITRIM_1         0x00000010	/* Bit 1 */
  #define RCC_CR_HSITRIM_2         0x00000020	/* Bit 2 */
  #define RCC_CR_HSITRIM_3         0x00000040	/* Bit 3 */
  #define RCC_CR_HSITRIM_4         0x00000080	/* Bit 4 */
  #define RCC_CR_HSICAL            0x0000FF00
  #define RCC_CR_HSICAL_0          0x00000100	/* Bit 0 */
  #define RCC_CR_HSICAL_1          0x00000200	/* Bit 1 */
  #define RCC_CR_HSICAL_2          0x00000400	/* Bit 2 */
  #define RCC_CR_HSICAL_3          0x00000800	/* Bit 3 */
  #define RCC_CR_HSICAL_4          0x00001000	/* Bit 4 */
  #define RCC_CR_HSICAL_5          0x00002000	/* Bit 5 */
  #define RCC_CR_HSICAL_6          0x00004000	/* Bit 6 */
  #define RCC_CR_HSICAL_7          0x00008000	/* Bit 7 */
  #define RCC_CR_HSEON             0x00010000
  #define RCC_CR_HSERDY            0x00020000
  #define RCC_CR_HSEBYP            0x00040000
  #define RCC_CR_CSSON             0x00080000
  #define RCC_CR_PLLON             0x01000000
  #define RCC_CR_PLLRDY            0x02000000
  #define RCC_CR_PLLI2SON          0x04000000
  #define RCC_CR_PLLI2SRDY         0x08000000
  #define RCC_CR_PLLSAION          0x10000000
  #define RCC_CR_PLLSAIRDY         0x20000000
#define TOFF_RCC_PLLCFGR    0x0004		/* (RW) RCC PLL configuration register */
  #define RCC_PLLCFGR_PLLM         0x0000003F
  #define RCC_PLLCFGR_PLLM_0       0x00000001
  #define RCC_PLLCFGR_PLLM_1       0x00000002
  #define RCC_PLLCFGR_PLLM_2       0x00000004
  #define RCC_PLLCFGR_PLLM_3       0x00000008
  #define RCC_PLLCFGR_PLLM_4       0x00000010
  #define RCC_PLLCFGR_PLLM_5       0x00000020
  #define RCC_PLLCFGR_PLLN         0x00007FC0
  #define RCC_PLLCFGR_PLLN_0       0x00000040
  #define RCC_PLLCFGR_PLLN_1       0x00000080
  #define RCC_PLLCFGR_PLLN_2       0x00000100
  #define RCC_PLLCFGR_PLLN_3       0x00000200
  #define RCC_PLLCFGR_PLLN_4       0x00000400
  #define RCC_PLLCFGR_PLLN_5       0x00000800
  #define RCC_PLLCFGR_PLLN_6       0x00001000
  #define RCC_PLLCFGR_PLLN_7       0x00002000
  #define RCC_PLLCFGR_PLLN_8       0x00004000
  #define RCC_PLLCFGR_PLLP         0x00030000
  #define RCC_PLLCFGR_PLLP_0       0x00010000
  #define RCC_PLLCFGR_PLLP_1       0x00020000
  #define RCC_PLLCFGR_PLLSRC       0x00400000
  #define RCC_PLLCFGR_PLLSRC_HSE   0x00400000
  #define RCC_PLLCFGR_PLLSRC_HSI   0x00000000
  #define RCC_PLLCFGR_PLLQ         0x0F000000
  #define RCC_PLLCFGR_PLLQ_0       0x01000000
  #define RCC_PLLCFGR_PLLQ_1       0x02000000
  #define RCC_PLLCFGR_PLLQ_2       0x04000000
  #define RCC_PLLCFGR_PLLQ_3       0x08000000
#define TOFF_RCC_CFGR       0x0008		/* (RW) RCC clock configuration register */
  #define RCC_CFGR_SW              0x00000003	/* SW[1:0] bits (System clock Switch) */
  #define RCC_CFGR_SW_0            0x00000001	/* Bit 0 */
  #define RCC_CFGR_SW_1            0x00000002	/* Bit 1 */
  #define RCC_CFGR_SW_HSI          0x00000000	/* HSI selected as system clock */
  #define RCC_CFGR_SW_HSE          0x00000001	/* HSE selected as system clock */
  #define RCC_CFGR_SW_PLL          0x00000002	/* PLL selected as system clock */
  #define RCC_CFGR_SWS             0x0000000C	/* SWS[1:0] bits (System Clock Switch Status) */
  #define RCC_CFGR_SWS_0           0x00000004	/* Bit 0 */
  #define RCC_CFGR_SWS_1           0x00000008	/* Bit 1 */
  #define RCC_CFGR_SWS_HSI         0x00000000	/* HSI oscillator used as system clock */
  #define RCC_CFGR_SWS_HSE         0x00000004	/* HSE oscillator used as system clock */
  #define RCC_CFGR_SWS_PLL         0x00000008	/* PLL used as system clock */
  #define RCC_CFGR_HPRE            0x000000F0	/* HPRE[3:0] bits (AHB prescaler) */
  #define RCC_CFGR_HPRE_0          0x00000010	/* Bit 0 */
  #define RCC_CFGR_HPRE_1          0x00000020	/* Bit 1 */
  #define RCC_CFGR_HPRE_2          0x00000040	/* Bit 2 */
  #define RCC_CFGR_HPRE_3          0x00000080	/* Bit 3 */
  #define RCC_CFGR_HPRE_DIV1       0x00000000	/* SYSCLK not divided */
  #define RCC_CFGR_HPRE_DIV2       0x00000080	/* SYSCLK divided by 2 */
  #define RCC_CFGR_HPRE_DIV4       0x00000090	/* SYSCLK divided by 4 */
  #define RCC_CFGR_HPRE_DIV8       0x000000A0	/* SYSCLK divided by 8 */
  #define RCC_CFGR_HPRE_DIV16      0x000000B0	/* SYSCLK divided by 16 */
  #define RCC_CFGR_HPRE_DIV64      0x000000C0	/* SYSCLK divided by 64 */
  #define RCC_CFGR_HPRE_DIV128     0x000000D0	/* SYSCLK divided by 128 */
  #define RCC_CFGR_HPRE_DIV256     0x000000E0	/* SYSCLK divided by 256 */
  #define RCC_CFGR_HPRE_DIV512     0x000000F0	/* SYSCLK divided by 512 */
  #define RCC_CFGR_PPRE1           0x00001C00	/* PRE1[2:0] bits (APB1 prescaler) */
  #define RCC_CFGR_PPRE1_0         0x00000400	/* Bit 0 */
  #define RCC_CFGR_PPRE1_1         0x00000800	/* Bit 1 */
  #define RCC_CFGR_PPRE1_2         0x00001000	/* Bit 2 */
  #define RCC_CFGR_PPRE1_DIV1      0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE1_DIV2      0x00001000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE1_DIV4      0x00001400	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE1_DIV8      0x00001800	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE1_DIV16     0x00001C00	/* HCLK divided by 16 */
  #define RCC_CFGR_PPRE2           0x0000E000	/* PRE2[2:0] bits (APB2 prescaler) */
  #define RCC_CFGR_PPRE2_0         0x00002000	/* Bit 0 */
  #define RCC_CFGR_PPRE2_1         0x00004000	/* Bit 1 */
  #define RCC_CFGR_PPRE2_2         0x00008000	/* Bit 2 */
  #define RCC_CFGR_PPRE2_DIV1      0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE2_DIV2      0x00008000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE2_DIV4      0x0000A000	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE2_DIV8      0x0000C000	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE2_DIV16     0x0000E000	/* HCLK divided by 16 */
  #define RCC_CFGR_RTCPRE          0x001F0000
  #define RCC_CFGR_RTCPRE_0        0x00010000
  #define RCC_CFGR_RTCPRE_1        0x00020000
  #define RCC_CFGR_RTCPRE_2        0x00040000
  #define RCC_CFGR_RTCPRE_3        0x00080000
  #define RCC_CFGR_RTCPRE_4        0x00100000
  #define RCC_CFGR_MCO1            0x00600000
  #define RCC_CFGR_MCO1_0          0x00200000
  #define RCC_CFGR_MCO1_1          0x00400000
  #define RCC_CFGR_I2SSRC          0x00800000
  #define RCC_CFGR_MCO1PRE         0x07000000
  #define RCC_CFGR_MCO1PRE_0       0x01000000
  #define RCC_CFGR_MCO1PRE_1       0x02000000
  #define RCC_CFGR_MCO1PRE_2       0x04000000
  #define RCC_CFGR_MCO2PRE         0x38000000
  #define RCC_CFGR_MCO2PRE_0       0x08000000
  #define RCC_CFGR_MCO2PRE_1       0x10000000
  #define RCC_CFGR_MCO2PRE_2       0x20000000
  #define RCC_CFGR_MCO2            0xC0000000
  #define RCC_CFGR_MCO2_0          0x40000000
  #define RCC_CFGR_MCO2_1          0x80000000
#define TOFF_RCC_CIR        0x000C		/* (RW) RCC clock interrupt register */
  #define RCC_CIR_LSIRDYF          0x00000001
  #define RCC_CIR_LSERDYF          0x00000002
  #define RCC_CIR_HSIRDYF          0x00000004
  #define RCC_CIR_HSERDYF          0x00000008
  #define RCC_CIR_PLLRDYF          0x00000010
  #define RCC_CIR_PLLI2SRDYF       0x00000020
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_CIR_PLLSAIRDYF       0x00000040
#endif
  #define RCC_CIR_CSSF             0x00000080
  #define RCC_CIR_LSIRDYIE         0x00000100
  #define RCC_CIR_LSERDYIE         0x00000200
  #define RCC_CIR_HSIRDYIE         0x00000400
  #define RCC_CIR_HSERDYIE         0x00000800
  #define RCC_CIR_PLLRDYIE         0x00001000
  #define RCC_CIR_PLLI2SRDYIE      0x00002000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_CIR_PLLSAIRDYIE      0x00004000
#endif
  #define RCC_CIR_LSIRDYC          0x00010000
  #define RCC_CIR_LSERDYC          0x00020000
  #define RCC_CIR_HSIRDYC          0x00040000
  #define RCC_CIR_HSERDYC          0x00080000
  #define RCC_CIR_PLLRDYC          0x00100000
  #define RCC_CIR_PLLI2SRDYC       0x00200000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_CIR_PLLSAIRDYC       0x00400000
#endif
  #define RCC_CIR_CSSC             0x00800000
#define TOFF_RCC_AHB1RSTR   0x0010		/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_GPIOARST    0x00000001
  #define RCC_AHB1RSTR_GPIOBRST    0x00000002
  #define RCC_AHB1RSTR_GPIOCRST    0x00000004
  #define RCC_AHB1RSTR_GPIODRST    0x00000008
  #define RCC_AHB1RSTR_GPIOERST    0x00000010
  #define RCC_AHB1RSTR_GPIOFRST    0x00000020
  #define RCC_AHB1RSTR_GPIOGRST    0x00000040
  #define RCC_AHB1RSTR_GPIOHRST    0x00000080
  #define RCC_AHB1RSTR_GPIOIRST    0x00000100
  #define RCC_AHB1RSTR_GPIOJRST    0x00000200
  #define RCC_AHB1RSTR_GPIOKRST    0x00000400
  #define RCC_AHB1RSTR_CRCRST      0x00001000
  #define RCC_AHB1RSTR_DMA1RST     0x00200000
  #define RCC_AHB1RSTR_DMA2RST     0x00400000
  #define RCC_AHB1RSTR_DMA2DRST    0x00800000
  #define RCC_AHB1RSTR_ETHMACRST   0x02000000
  #define RCC_AHB1RSTR_OTGHRST     0x20000000
#define TOFF_RCC_AHB2RSTR   0x0014		/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_DCMIRST     0x00000001
  #define RCC_AHB2RSTR_CRYPRST     0x00000010
  #define RCC_AHB2RSTR_HSAHRST     0x00000020
  #define RCC_AHB2RSTR_RNGRST      0x00000040
  #define RCC_AHB2RSTR_OTGFSRST    0x00000080
#define TOFF_RCC_AHB3RSTR   0x0018		/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_FSMCRST     0x00000001
  #define RCC_AHB3RSTR_FMCRST      RCC_AHB3RSTR_FSMCRST
  #define RCC_AHB3RSTR_QSPIRST     0x00000002
#define TOFF_RCC_APB1RSTR   0x0020		/* (RW) RCC APB1 peripheral reset register */
  #define RCC_APB1RSTR_TIM2RST     0x00000001
  #define RCC_APB1RSTR_TIM3RST     0x00000002
  #define RCC_APB1RSTR_TIM4RST     0x00000004
  #define RCC_APB1RSTR_TIM5RST     0x00000008
  #define RCC_APB1RSTR_TIM6RST     0x00000010
  #define RCC_APB1RSTR_TIM7RST     0x00000020
  #define RCC_APB1RSTR_TIM12RST    0x00000040
  #define RCC_APB1RSTR_TIM13RST    0x00000080
  #define RCC_APB1RSTR_TIM14RST    0x00000100
  #define RCC_APB1RSTR_WWDGRST     0x00000800
  #define RCC_APB1RSTR_SPI2RST     0x00008000
  #define RCC_APB1RSTR_SPI3RST     0x00010000
  #define RCC_APB1RSTR_USART2RST   0x00020000
  #define RCC_APB1RSTR_USART3RST   0x00040000
  #define RCC_APB1RSTR_UART4RST    0x00080000
  #define RCC_APB1RSTR_UART5RST    0x00100000
  #define RCC_APB1RSTR_I2C1RST     0x00200000
  #define RCC_APB1RSTR_I2C2RST     0x00400000
  #define RCC_APB1RSTR_I2C3RST     0x00800000
  #define RCC_APB1RSTR_I2C4RST     0x01000000
  #define RCC_APB1RSTR_CAN1RST     0x02000000
  #define RCC_APB1RSTR_CAN2RST     0x04000000
  #define RCC_APB1RSTR_PWRRST      0x10000000
  #define RCC_APB1RSTR_DACRST      0x20000000
  #define RCC_APB1RSTR_UART7RST    0x40000000
  #define RCC_APB1RSTR_UART8RST    0x80000000
#define TOFF_RCC_APB2RSTR   0x0024		/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_TIM1RST     0x00000001
  #define RCC_APB2RSTR_TIM8RST     0x00000002
  #define RCC_APB2RSTR_USART1RST   0x00000010
  #define RCC_APB2RSTR_USART6RST   0x00000020
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2RSTR_SDMMC2RST   0x00000080
#endif
  #define RCC_APB2RSTR_ADCRST      0x00000100
  #define RCC_APB2RSTR_SDIORST     0x00000800
  #define RCC_APB2RSTR_SDMMC1RST   RCC_APB2RSTR_SDIORST
  #define RCC_APB2RSTR_SPI1RST     0x00001000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2RSTR_SPI4RST     0x00002000
#endif
  #define RCC_APB2RSTR_SYSCFGRST   0x00004000
  #define RCC_APB2RSTR_TIM9RST     0x00010000
  #define RCC_APB2RSTR_TIM10RST    0x00020000
  #define RCC_APB2RSTR_TIM11RST    0x00040000
  #define RCC_APB2RSTR_SPI5RST     0x00100000
  #define RCC_APB2RSTR_SPI6RST     0x00200000
  #define RCC_APB2RSTR_SAI1RST     0x00400000
  #define RCC_APB2RSTR_SAI2RST     0x00800000
  #define RCC_APB2RSTR_LTDCRST     0x04000000
#ifdef TOPPERS_STM32F769_DISCOVERY
  #define RCC_APB2RSTR_DSIRST      0x08000000
#endif
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
  #define RCC_APB2RSTR_DFSDM1RST   0x20000000U
  #define RCC_APB2RSTR_MDIORST     0x40000000U
#endif
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2RSTR_OTGPHYCRST  0x80000000
#endif
#define TOFF_RCC_AHB1ENR    0x0030		/* (RW) RCC AHB1 peripheral clock register */
  #define RCC_AHB1ENR_GPIOAEN      0x00000001
  #define RCC_AHB1ENR_GPIOBEN      0x00000002
  #define RCC_AHB1ENR_GPIOCEN      0x00000004
  #define RCC_AHB1ENR_GPIODEN      0x00000008
  #define RCC_AHB1ENR_GPIOEEN      0x00000010
  #define RCC_AHB1ENR_GPIOFEN      0x00000020
  #define RCC_AHB1ENR_GPIOGEN      0x00000040
  #define RCC_AHB1ENR_GPIOHEN      0x00000080
  #define RCC_AHB1ENR_GPIOIEN      0x00000100
  #define RCC_AHB1ENR_GPIOJEN      0x00000200
  #define RCC_AHB1ENR_GPIOKEN      0x00000400
  #define RCC_AHB1ENR_CRCEN        0x00001000
  #define RCC_AHB1ENR_BKPSRAMEN    0x00040000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_AHB1ENR_DTCMRAMEN    0x00100000
#else
  #define RCC_AHB1ENR_CCMDATARAMEN 0x00100000
#endif
  #define RCC_AHB1ENR_DMA1EN       0x00200000
  #define RCC_AHB1ENR_DMA2EN       0x00400000
  #define RCC_AHB1ENR_DMA2DEN      0x00800000
  #define RCC_AHB1ENR_ETHMACEN     0x02000000
  #define RCC_AHB1ENR_ETHMACTXEN   0x04000000
  #define RCC_AHB1ENR_ETHMACRXEN   0x08000000
  #define RCC_AHB1ENR_ETHMACPTPEN  0x10000000
  #define RCC_AHB1ENR_OTGHSEN      0x20000000
  #define RCC_AHB1ENR_OTGHSULPIEN  0x40000000
#define TOFF_RCC_AHB2ENR    0x0034		/* (RW) RCC AHB2 peripheral clock register */
  #define RCC_AHB2ENR_DCMIEN       0x00000001
  #define RCC_AHB2ENR_CRYPEN       0x00000010
  #define RCC_AHB2ENR_HASHEN       0x00000020
  #define RCC_AHB2ENR_RNGEN        0x00000040
  #define RCC_AHB2ENR_OTGFSEN      0x00000080
#define TOFF_RCC_AHB3ENR    0x0038		/* (RW) RCC AHB3 peripheral clock register */
  #define RCC_AHB3ENR_FSMCEN       0x00000001
  #define RCC_AHB3ENR_FMCEN        RCC_AHB3ENR_FSMCEN
  #define RCC_AHB3ENR_QSPIEN       0x00000002
#define TOFF_RCC_APB1ENR    0x0040		/* (RW) RCC APB1 peripheral clock enable register */
  #define RCC_APB1ENR_TIM2EN       0x00000001
  #define RCC_APB1ENR_TIM3EN       0x00000002
  #define RCC_APB1ENR_TIM4EN       0x00000004
  #define RCC_APB1ENR_TIM5EN       0x00000008
  #define RCC_APB1ENR_TIM6EN       0x00000010
  #define RCC_APB1ENR_TIM7EN       0x00000020
  #define RCC_APB1ENR_TIM12EN      0x00000040
  #define RCC_APB1ENR_TIM13EN      0x00000080
  #define RCC_APB1ENR_TIM14EN      0x00000100
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB1ENR_LPTIM1EN     0x00000200
  #define RCC_APB1ENR_RTCEN        0x00000400
#endif
  #define RCC_APB1ENR_WWDGEN       0x00000800
  #define RCC_APB1ENR_SPI2EN       0x00004000
  #define RCC_APB1ENR_SPI3EN       0x00008000
  #define RCC_APB1ENR_USART2EN     0x00020000
  #define RCC_APB1ENR_USART3EN     0x00040000
  #define RCC_APB1ENR_UART4EN      0x00080000
  #define RCC_APB1ENR_UART5EN      0x00100000
  #define RCC_APB1ENR_I2C1EN       0x00200000
  #define RCC_APB1ENR_I2C2EN       0x00400000
  #define RCC_APB1ENR_I2C3EN       0x00800000
  #define RCC_APB1ENR_I2C4EN       0x01000000
  #define RCC_APB1ENR_CAN1EN       0x02000000
  #define RCC_APB1ENR_CECEN        0x08000000
  #define RCC_APB1ENR_CAN2EN       0x04000000
  #define RCC_APB1ENR_PWREN        0x10000000
  #define RCC_APB1ENR_DACEN        0x20000000
  #define RCC_APB1ENR_UART7EN      0x40000000
  #define RCC_APB1ENR_UART8EN      0x80000000
#define TOFF_RCC_APB2ENR    0x0044		/* (RW) RCC APB2 peripheral clock enable register */
  #define RCC_APB2ENR_TIM1EN       0x00000001
  #define RCC_APB2ENR_TIM8EN       0x00000002
  #define RCC_APB2ENR_USART1EN     0x00000010
  #define RCC_APB2ENR_USART6EN     0x00000020
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144) || defined(TOPPERS_STM32F723_DISCOVERY)
  #define RCC_APB2ENR_SDMMC2EN     0x00000080
#endif
  #define RCC_APB2ENR_ADC1EN       0x00000100
  #define RCC_APB2ENR_ADC2EN       0x00000200
  #define RCC_APB2ENR_ADC3EN       0x00000400
  #define RCC_APB2ENR_SDIOEN       0x00000800
  #define RCC_APB2ENR_SDMMC1EN     0x00000800
  #define RCC_APB2ENR_SPI1EN       0x00001000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2ENR_SPI4EN       0x00002000
#endif
  #define RCC_APB2ENR_SYSCFGEN     0x00004000
  #define RCC_APB2ENR_TIM11EN      0x00040000
  #define RCC_APB2ENR_TIM10EN      0x00020000
  #define RCC_APB2ENR_TIM9EN       0x00010000
  #define RCC_APB2ENR_TIM10EN      0x00020000
  #define RCC_APB2ENR_TIM11EN      0x00040000
  #define RCC_APB2ENR_SPI5EN       0x00100000
  #define RCC_APB2ENR_SPI6EN       0x00200000
  #define RCC_APB2ENR_SAI1EN       0x00400000
  #define RCC_APB2ENR_SAI2EN       0x00800000
  #define RCC_APB2ENR_LTDCEN       0x04000000
#if defined(TOPPERS_STM32F769_DISCOVERY)
  #define RCC_APB2ENR_DSIEN        0x08000000
#endif
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
  #define RCC_APB2ENR_DFSDM1EN     0x20000000
  #define RCC_APB2ENR_MDIOEN       0x40000000
#endif
#define TOFF_RCC_AHB1LPENR  0x0050		/* (RW) RCC AHB1 peripheral clock enable in low power mode register */
  #define RCC_AHB1LPENR_GPIOALPEN     0x00000001
  #define RCC_AHB1LPENR_GPIOBLPEN     0x00000002
  #define RCC_AHB1LPENR_GPIOCLPEN     0x00000004
  #define RCC_AHB1LPENR_GPIODLPEN     0x00000008
  #define RCC_AHB1LPENR_GPIOELPEN     0x00000010
  #define RCC_AHB1LPENR_GPIOFLPEN     0x00000020
  #define RCC_AHB1LPENR_GPIOGLPEN     0x00000040
  #define RCC_AHB1LPENR_GPIOHLPEN     0x00000080
  #define RCC_AHB1LPENR_GPIOILPEN     0x00000100
  #define RCC_AHB1LPENR_CRCLPEN       0x00001000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_AHB1LPENR_AXILPEN       0x00002000
#endif
  #define RCC_AHB1LPENR_FLITFLPEN     0x00008000
  #define RCC_AHB1LPENR_SRAM1LPEN     0x00010000
  #define RCC_AHB1LPENR_SRAM2LPEN     0x00020000
  #define RCC_AHB1LPENR_BKPSRAMLPEN   0x00040000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_AHB1LPENR_DTCMLPEN      0x00100000
#endif
  #define RCC_AHB1LPENR_DMA1LPEN      0x00200000
  #define RCC_AHB1LPENR_DMA2LPEN      0x00400000
  #define RCC_AHB1LPENR_ETHMACLPEN    0x02000000
  #define RCC_AHB1LPENR_ETHMACTXLPEN  0x04000000
  #define RCC_AHB1LPENR_ETHMACRXLPEN  0x08000000
  #define RCC_AHB1LPENR_ETHMACPTPLPEN 0x10000000
  #define RCC_AHB1LPENR_OTGHSLPEN     0x20000000
  #define RCC_AHB1LPENR_OTGHSULPILPEN 0x40000000
#define TOFF_RCC_AHB2LPENR  0x0054		/* (RW) RCC AHB2 peripheral clock enable in low power mode register */
  #define RCC_AHB2LPENR_DCMILPEN   0x00000001
  #define RCC_AHB2LPENR_CRYPLPEN   0x00000010
  #define RCC_AHB2LPENR_HASHLPEN   0x00000020
  #define RCC_AHB2LPENR_RNGLPEN    0x00000040
  #define RCC_AHB2LPENR_OTGFSLPEN  0x00000080
#define TOFF_RCC_AHB3LPENR  0x0058		/* (RW) RCC AHB3 peripheral clock enable in low power mode register */
  #define RCC_AHB3LPENR_FSMCLPEN   0x00000001
  #define RCC_AHB3LPENR_FMCLPEN    RCC_AHB3LPENR_FSMCLPEN
  #define RCC_AHB3LPENR_QSPILPEN   0x00000002
#define TOFF_RCC_APB1LPENR  0x0060		/* (RW) RCC APB1 peripheral clock enable in low power mode register */
  #define RCC_APB1LPENR_TIM2LPEN   0x00000001
  #define RCC_APB1LPENR_TIM3LPEN   0x00000002
  #define RCC_APB1LPENR_TIM4LPEN   0x00000004
  #define RCC_APB1LPENR_TIM5LPEN   0x00000008
  #define RCC_APB1LPENR_TIM6LPEN   0x00000010
  #define RCC_APB1LPENR_TIM7LPEN   0x00000020
  #define RCC_APB1LPENR_TIM12LPEN  0x00000040
  #define RCC_APB1LPENR_TIM13LPEN  0x00000080
  #define RCC_APB1LPENR_TIM14LPEN  0x00000100
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB1LPENR_LPTIM1LPEN 0x00000200
  #define RCC_APB1LPENR_RTCLPEN    0x00000400
#endif
  #define RCC_APB1LPENR_WWDGLPEN   0x00000800
  #define RCC_APB1LPENR_SPI2LPEN   0x00004000
  #define RCC_APB1LPENR_SPI3LPEN   0x00008000
  #define RCC_APB1LPENR_USART2LPEN 0x00020000
  #define RCC_APB1LPENR_USART3LPEN 0x00040000
  #define RCC_APB1LPENR_UART4LPEN  0x00080000
  #define RCC_APB1LPENR_UART5LPEN  0x00100000
  #define RCC_APB1LPENR_I2C1LPEN   0x00200000
  #define RCC_APB1LPENR_I2C2LPEN   0x00400000
  #define RCC_APB1LPENR_I2C3LPEN   0x00800000
  #define RCC_APB1LPENR_CAN1LPEN   0x02000000
  #define RCC_APB1LPENR_CAN2LPEN   0x04000000
  #define RCC_APB1LPENR_PWRLPEN    0x10000000
  #define RCC_APB1LPENR_DACLPEN    0x20000000
  #define RCC_APB1LPENR_UART7LPEN  0x40000000
  #define RCC_APB1LPENR_UART8LPEN  0x80000000
#define TOFF_RCC_APB2LPENR  0x0064		/* (RW) RCC APB2 peripheral clock enable in low power mode register */
  #define RCC_APB2LPENR_TIM1LPEN   0x00000001
  #define RCC_APB2LPENR_TIM8LPEN   0x00000002
  #define RCC_APB2LPENR_USART1LPEN 0x00000010
  #define RCC_APB2LPENR_USART6LPEN 0x00000020
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2LPENR_SDMMC2LPEN 0x00000080
#endif
  #define RCC_APB2LPENR_ADC1LPEN   0x00000100
  #define RCC_APB2LPENR_ADC2LPEN   0x00000200
  #define RCC_APB2LPENR_ADC3LPEN   0x00000400
  #define RCC_APB2LPENR_SDIOLPEN   0x00000800
  #define RCC_APB2LPENR_SDMMC1LPEN RCC_APB2LPENR_SDIOLPEN
  #define RCC_APB2LPENR_SPI1LPEN   0x00001000
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2LPENR_SPI4LPEN   0x00002000
#endif
  #define RCC_APB2LPENR_SYSCFGLPEN 0x00004000
  #define RCC_APB2LPENR_TIM9LPEN   0x00010000
  #define RCC_APB2LPENR_TIM10LPEN  0x00020000
  #define RCC_APB2LPENR_TIM11LPEN  0x00040000
  #define RCC_APB2LPENR_SPI5LPEN   0x00100000
  #define RCC_APB2LPENR_SPI6LPEN   0x00200000
  #define RCC_APB2LPENR_SAI1LPEN   0x00400000
  #define RCC_APB2LPENR_SAI2LPEN   0x00800000
#ifndef TOPPERS_STM32F723_DISCOVERY
  #define RCC_APB2LPENR_LTDCLPEN   0x04000000
#else
  #define RCC_APB2ENR_OTGPHYCEN    0x80000000
#endif
#define TOFF_RCC_BDCR       0x0070		/* (RW) RCC Backup domain control register */
  #define RCC_BDCR_LSEON           0x00000001
  #define RCC_BDCR_LSERDY          0x00000002
  #define RCC_BDCR_LSEBYP          0x00000004
#ifdef TOPPERS_STM32F723_DISCOVERY
  #define RCC_BDCR_LSEDRV          0x00000018
  #define RCC_BDCR_LSEDRV_0        0x00000008
  #define RCC_BDCR_LSEDRV_1        0x00000010
#endif
  #define RCC_BDCR_RTCSEL          0x00000300
  #define RCC_BDCR_RTCSEL_0        0x00000100
  #define RCC_BDCR_RTCSEL_1        0x00000200
  #define RCC_BDCR_RTCEN           0x00008000
  #define RCC_BDCR_BDRST           0x00010000
#define TOFF_RCC_CSR        0x0074		/* (RW) RCC clock control & status register */
  #define RCC_CSR_LSION            0x00000001
  #define RCC_CSR_LSIRDY           0x00000002
  #define RCC_CSR_RMVF             0x01000000
  #define RCC_CSR_BORRSTF          0x02000000
  #define RCC_CSR_PADRSTF          0x04000000
  #define RCC_CSR_PINRSTF          RCC_CSR_PADRSTF
  #define RCC_CSR_PORRSTF          0x08000000
  #define RCC_CSR_SFTRSTF          0x10000000
  #define RCC_CSR_WDGRSTF          0x20000000
  #define RCC_CSR_IWDGRSTF         RCC_CSR_WDGRSTF
  #define RCC_CSR_WWDGRSTF         0x40000000
  #define RCC_CSR_LPWRRSTF         0x80000000
#define TOFF_RCC_SSCGR      0x0080		/* (RW) RCC spread spectrum clock generation register */
  #define RCC_SSCGR_MODPER         0x00001FFF
  #define RCC_SSCGR_INCSTEP        0x0FFFE000
  #define RCC_SSCGR_SPREADSEL      0x40000000
  #define RCC_SSCGR_SSCGEN         0x80000000
#define TOFF_RCC_PLLI2SCFGR 0x0084		/* (RW) RCC PLLI2S configuration register */
  #define RCC_PLLI2SCFGR_PLLI2SN   0x00007FC0
  #define RCC_PLLI2SCFGR_PLLI2SP   0x00030000
  #define RCC_PLLI2SCFGR_PLLI2SQ   0x0F000000
  #define RCC_PLLI2SCFGR_PLLI2SR   0x70000000
#define TOFF_RCC_PLLSAICFGR 0x0088		/* (RW) RCC PLLSAI configuration register */
  #define RCC_PLLSAICFGR_PLLSAIN   0x00007FC0
  #define RCC_PLLSAICFGR_PLLSAIP   0x00030000
  #define RCC_PLLSAICFGR_PLLSAIQ   0x0F000000
  #define RCC_PLLSAICFGR_PLLSAIR   0x70000000
#define TOFF_RCC_DCKCFGR1   0x008C		/* (RW) RCC Dedicated Clocks configuration register1 */
  #define RCC_DCKCFGR1_PLLI2SDIVQ  0x0000001F
  #define RCC_DCKCFGR1_PLLSAIDIVQ  0x00001F00
  #define RCC_DCKCFGR1_PLLSAIDIVR  0x00030000
  #define RCC_DCKCFGR1_PLLSAIDIVR_0 0x00010000
  #define RCC_DCKCFGR1_PLLSAIDIVR_1 0x00020000
  #define RCC_DCKCFGR1_SAI1SEL     0x00300000
  #define RCC_DCKCFGR1_SAI1SEL_0   0x00100000
  #define RCC_DCKCFGR1_SAI1SEL_1   0x00200000
  #define RCC_DCKCFGR1_SAI2SEL     0x00C00000
  #define RCC_DCKCFGR1_SAI2SEL_0   0x00400000
  #define RCC_DCKCFGR1_SAI2SEL_1   0x00800000
  #define RCC_DCKCFGR1_TIMPRE      0x01000000
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
  #define RCC_DCKCFGR1_DFSDM1SEL   0x02000000
  #define RCC_DCKCFGR1_ADFSDM1SEL  0x04000000
#endif
#define TOFF_RCC_DCKCFGR2   0x0090		/* (RW) RCC Dedicated Clocks configuration register2 */
  #define RCC_DCKCFGR2_USART1SEL   0x00000003
  #define RCC_DCKCFGR2_USART1SEL_0 0x00000001
  #define RCC_DCKCFGR2_USART1SEL_1 0x00000002
  #define RCC_DCKCFGR2_USART2SEL   0x0000000C
  #define RCC_DCKCFGR2_USART3SEL   0x00000030
  #define RCC_DCKCFGR2_UART4SEL    0x000000C0
  #define RCC_DCKCFGR2_UART5SEL    0x00000300
  #define RCC_DCKCFGR2_USART6SEL   0x00000C00
  #define RCC_DCKCFGR2_USART6SEL_0 0x00000400
  #define RCC_DCKCFGR2_USART6SEL_1 0x00000800
  #define RCC_DCKCFGR2_UART7SEL    0x00003000
  #define RCC_DCKCFGR2_UART8SEL    0x0000C000
  #define RCC_DCKCFGR2_I2C1SEL     0x00030000
  #define RCC_DCKCFGR2_I2C2SEL     0x000C0000
  #define RCC_DCKCFGR2_I2C3SEL     0x00300000
  #define RCC_DCKCFGR2_I2C4SEL     0x00C00000
  #define RCC_DCKCFGR2_LPTIM1SEL   0x03000000
  #define RCC_DCKCFGR2_CECSEL      0x04000000
  #define RCC_DCKCFGR2_CK48MSEL    0x08000000
  #define RCC_DCKCFGR2_SDMMC1SEL   0x10000000
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
  #define RCC_DCKCFGR2_SDMMC2SEL   0x20000000
  #define RCC_DCKCFGR2_DSISEL      0x40000000
#elif defined(TOPPERS_STM32F723_DISCOVERY)
  #define RCC_DCKCFGR2_SDMMC2SEL   0x20000000
#endif

/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (AHB1PERIPH_BASE + 0x3C00)
#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
  #define FLASH_ACR_LATENCY        0x0000000F
  #define FLASH_ACR_LATENCY_0WS    0x00000000
  #define FLASH_ACR_LATENCY_1WS    0x00000001
  #define FLASH_ACR_LATENCY_2WS    0x00000002
  #define FLASH_ACR_LATENCY_3WS    0x00000003
  #define FLASH_ACR_LATENCY_4WS    0x00000004
  #define FLASH_ACR_LATENCY_5WS    0x00000005
  #define FLASH_ACR_LATENCY_6WS    0x00000006
  #define FLASH_ACR_LATENCY_7WS    0x00000007
  #define FLASH_ACR_LATENCY_8WS    0x00000008
  #define FLASH_ACR_LATENCY_9WS    0x00000009
  #define FLASH_ACR_LATENCY_10WS   0x0000000A
  #define FLASH_ACR_LATENCY_11WS   0x0000000B
  #define FLASH_ACR_LATENCY_12WS   0x0000000C
  #define FLASH_ACR_LATENCY_13WS   0x0000000D
  #define FLASH_ACR_LATENCY_14WS   0x0000000E
  #define FLASH_ACR_LATENCY_15WS   0x0000000F
  #define FLASH_ACR_PRFTEN         0x00000100
  #define FLASH_ACR_ARTEN          0x00000200
  #define FLASH_ACR_ARTRST         0x00000800
#define TOFF_FLASH_KEYR     0x0004		/* (RW) FLASH key register */
#define TOFF_FLASH_OPTKEYR  0x0008		/* (RW) FLASH option key register */
#define TOFF_FLASH_SR       0x000C		/* (RW) FLASH status register */
  #define FLASH_SR_EOP             0x00000001
  #define FLASH_SR_SOP             0x00000002
  #define FLASH_SR_WRPERR          0x00000010
  #define FLASH_SR_PGAERR          0x00000020
  #define FLASH_SR_PGPERR          0x00000040
  #define FLASH_SR_PGSERR          0x00000080
  #define FLASH_SR_BSY             0x00010000
#define TOFF_FLASH_CR       0x0010		/* (RW) FLASH control register */
  #define FLASH_CR_PG              0x00000001
  #define FLASH_CR_SER             0x00000002
  #define FLASH_CR_MER             0x00000004
  #define FLASH_CR_SNB_0           0x00000008
  #define FLASH_CR_SNB_1           0x00000010
  #define FLASH_CR_SNB_2           0x00000020
  #define FLASH_CR_SNB_3           0x00000040
  #define FLASH_CR_PSIZE_0         0x00000100
  #define FLASH_CR_PSIZE_1         0x00000200
  #define FLASH_CR_STRT            0x00010000
  #define FLASH_CR_EOPIE           0x01000000
  #define FLASH_CR_LOCK            0x80000000
#define TOFF_FLASH_OPTCR    0x0014		/* (RW) FLASH option control register */
  #define FLASH_OPTCR_OPTLOCK      0x00000001
  #define FLASH_OPTCR_OPTSTRT      0x00000002
  #define FLASH_OPTCR_BOR_LEV_0    0x00000004
  #define FLASH_OPTCR_BOR_LEV_1    0x00000008
  #define FLASH_OPTCR_BOR_LEV      0x0000000C
  #define FLASH_OPTCR_WDG_SW       0x00000020
  #define FLASH_OPTCR_nRST_STOP    0x00000040
  #define FLASH_OPTCR_nRST_STDBY   0x00000080
  #define FLASH_OPTCR_RDP_0        0x00000100
  #define FLASH_OPTCR_RDP_1        0x00000200
  #define FLASH_OPTCR_RDP_2        0x00000400
  #define FLASH_OPTCR_RDP_3        0x00000800
  #define FLASH_OPTCR_RDP_4        0x00001000
  #define FLASH_OPTCR_RDP_5        0x00002000
  #define FLASH_OPTCR_RDP_6        0x00004000
  #define FLASH_OPTCR_RDP_7        0x00008000
  #define FLASH_OPTCR_nWRP_0       0x00010000
  #define FLASH_OPTCR_nWRP_1       0x00020000
  #define FLASH_OPTCR_nWRP_2       0x00040000
  #define FLASH_OPTCR_nWRP_3       0x00080000
  #define FLASH_OPTCR_nWRP_4       0x00100000
  #define FLASH_OPTCR_nWRP_5       0x00200000
  #define FLASH_OPTCR_nWRP_6       0x00400000
  #define FLASH_OPTCR_nWRP_7       0x00800000
  #define FLASH_OPTCR_IWDG_STDBY   0x40000000
  #define FLASH_OPTCR_IWDG_STOP    0x80000000
#define TOFF_FLASH_OPTCR1   0x0018		/* (RW) FLASH option control register 1 */

/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (AHB1PERIPH_BASE + 0x6000)
#define TADR_DMA2_BASE      (AHB1PERIPH_BASE + 0x6400)
#define TOFF_DMAI_LISR      0x0000		/* (RW) DMA low interrupt status register */
  #define DMA_LISR_TCIF3           0x08000000
  #define DMA_LISR_HTIF3           0x04000000
  #define DMA_LISR_TEIF3           0x02000000
  #define DMA_LISR_DMEIF3          0x01000000
  #define DMA_LISR_FEIF3           0x00400000
  #define DMA_LISR_TCIF2           0x00200000
  #define DMA_LISR_HTIF2           0x00100000
  #define DMA_LISR_TEIF2           0x00080000
  #define DMA_LISR_DMEIF2          0x00040000
  #define DMA_LISR_FEIF2           0x00010000
  #define DMA_LISR_TCIF1           0x00000800
  #define DMA_LISR_HTIF1           0x00000400
  #define DMA_LISR_TEIF1           0x00000200
  #define DMA_LISR_DMEIF1          0x00000100
  #define DMA_LISR_FEIF1           0x00000040
  #define DMA_LISR_TCIF0           0x00000020
  #define DMA_LISR_HTIF0           0x00000010
  #define DMA_LISR_TEIF0           0x00000008
  #define DMA_LISR_DMEIF0          0x00000004
  #define DMA_LISR_FEIF0           0x00000001
#define TOFF_DMAI_HISR      0x0004		/* (RW) DMA high interrupt status register */
  #define DMA_HISR_TCIF7           0x08000000
  #define DMA_HISR_HTIF7           0x04000000
  #define DMA_HISR_TEIF7           0x02000000
  #define DMA_HISR_DMEIF7          0x01000000
  #define DMA_HISR_FEIF7           0x00400000
  #define DMA_HISR_TCIF6           0x00200000
  #define DMA_HISR_HTIF6           0x00100000
  #define DMA_HISR_TEIF6           0x00080000
  #define DMA_HISR_DMEIF6          0x00040000
  #define DMA_HISR_FEIF6           0x00010000
  #define DMA_HISR_TCIF5           0x00000800
  #define DMA_HISR_HTIF5           0x00000400
  #define DMA_HISR_TEIF5           0x00000200
  #define DMA_HISR_DMEIF5          0x00000100
  #define DMA_HISR_FEIF5           0x00000040
  #define DMA_HISR_TCIF4           0x00000020
  #define DMA_HISR_HTIF4           0x00000010
  #define DMA_HISR_TEIF4           0x00000008
  #define DMA_HISR_DMEIF4          0x00000004
  #define DMA_HISR_FEIF4           0x00000001
#define TOFF_DMAI_LIFCR     0x0008		/* (RW) DMA low interrupt flag clear register */
  #define DMA_LIFCR_CTCIF3         0x08000000
  #define DMA_LIFCR_CHTIF3         0x04000000
  #define DMA_LIFCR_CTEIF3         0x02000000
  #define DMA_LIFCR_CDMEIF3        0x01000000
  #define DMA_LIFCR_CFEIF3         0x00400000
  #define DMA_LIFCR_CTCIF2         0x00200000
  #define DMA_LIFCR_CHTIF2         0x00100000
  #define DMA_LIFCR_CTEIF2         0x00080000
  #define DMA_LIFCR_CDMEIF2        0x00040000
  #define DMA_LIFCR_CFEIF2         0x00010000
  #define DMA_LIFCR_CTCIF1         0x00000800
  #define DMA_LIFCR_CHTIF1         0x00000400
  #define DMA_LIFCR_CTEIF1         0x00000200
  #define DMA_LIFCR_CDMEIF1        0x00000100
  #define DMA_LIFCR_CFEIF1         0x00000040
  #define DMA_LIFCR_CTCIF0         0x00000020
  #define DMA_LIFCR_CHTIF0         0x00000010
  #define DMA_LIFCR_CTEIF0         0x00000008
  #define DMA_LIFCR_CDMEIF0        0x00000004
  #define DMA_LIFCR_CFEIF0         0x00000001
#define TOFF_DMAI_HIFCR     0x000C		/* (RW) DMA high interrupt flag clear register */
  #define DMA_HIFCR_CTCIF7         0x08000000
  #define DMA_HIFCR_CHTIF7         0x04000000
  #define DMA_HIFCR_CTEIF7         0x02000000
  #define DMA_HIFCR_CDMEIF7        0x01000000
  #define DMA_HIFCR_CFEIF7         0x00400000
  #define DMA_HIFCR_CTCIF6         0x00200000
  #define DMA_HIFCR_CHTIF6         0x00100000
  #define DMA_HIFCR_CTEIF6         0x00080000
  #define DMA_HIFCR_CDMEIF6        0x00040000
  #define DMA_HIFCR_CFEIF6         0x00010000
  #define DMA_HIFCR_CTCIF5         0x00000800
  #define DMA_HIFCR_CHTIF5         0x00000400
  #define DMA_HIFCR_CTEIF5         0x00000200
  #define DMA_HIFCR_CDMEIF5        0x00000100
  #define DMA_HIFCR_CFEIF5         0x00000040
  #define DMA_HIFCR_CTCIF4         0x00000020
  #define DMA_HIFCR_CHTIF4         0x00000010
  #define DMA_HIFCR_CTEIF4         0x00000008
  #define DMA_HIFCR_CDMEIF4        0x00000004
  #define DMA_HIFCR_CFEIF4         0x00000001

#define TADR_DMA1_STM0_BASE (TADR_DMA1_BASE + 0x010)
#define TADR_DMA1_STM1_BASE (TADR_DMA1_BASE + 0x028)
#define TADR_DMA1_STM2_BASE (TADR_DMA1_BASE + 0x040)
#define TADR_DMA1_STM3_BASE (TADR_DMA1_BASE + 0x058)
#define TADR_DMA1_STM4_BASE (TADR_DMA1_BASE + 0x070)
#define TADR_DMA1_STM5_BASE (TADR_DMA1_BASE + 0x088)
#define TADR_DMA1_STM6_BASE (TADR_DMA1_BASE + 0x0A0)
#define TADR_DMA1_STM7_BASE (TADR_DMA1_BASE + 0x0B8)
#define TADR_DMA2_STM0_BASE (TADR_DMA2_BASE + 0x010)
#define TADR_DMA2_STM1_BASE (TADR_DMA2_BASE + 0x028)
#define TADR_DMA2_STM2_BASE (TADR_DMA2_BASE + 0x040)
#define TADR_DMA2_STM3_BASE (TADR_DMA2_BASE + 0x058)
#define TADR_DMA2_STM4_BASE (TADR_DMA2_BASE + 0x070)
#define TADR_DMA2_STM5_BASE (TADR_DMA2_BASE + 0x088)
#define TADR_DMA2_STM6_BASE (TADR_DMA2_BASE + 0x0A0)
#define TADR_DMA2_STM7_BASE (TADR_DMA2_BASE + 0x0B8)
#define TOFF_DMAS_CR        0x0000		/* (RW) DMA stream x configuration register      */
  #define DMA_SxCR_CHSEL           0x0E000000
  #define DMA_SxCR_CHSEL_0         0x02000000
  #define DMA_SxCR_CHSEL_1         0x04000000
  #define DMA_SxCR_CHSEL_2         0x08000000
  #define DMA_SxCR_MBURST          0x01800000
  #define DMA_SxCR_MBURST_0        0x00800000
  #define DMA_SxCR_MBURST_1        0x01000000
  #define DMA_SxCR_PBURST          0x00600000
  #define DMA_SxCR_PBURST_0        0x00200000
  #define DMA_SxCR_PBURST_1        0x00400000
  #define DMA_SxCR_ACK             0x00100000
  #define DMA_SxCR_CT              0x00080000
  #define DMA_SxCR_DBM             0x00040000
  #define DMA_SxCR_PL              0x00030000
  #define DMA_SxCR_PL_0            0x00010000
  #define DMA_SxCR_PL_1            0x00020000
  #define DMA_SxCR_PINCOS          0x00008000
  #define DMA_SxCR_MSIZE           0x00006000
  #define DMA_SxCR_MSIZE_0         0x00002000
  #define DMA_SxCR_MSIZE_1         0x00004000
  #define DMA_SxCR_PSIZE           0x00001800
  #define DMA_SxCR_PSIZE_0         0x00000800
  #define DMA_SxCR_PSIZE_1         0x00001000
  #define DMA_SxCR_MINC            0x00000400
  #define DMA_SxCR_PINC            0x00000200
  #define DMA_SxCR_CIRC            0x00000100
  #define DMA_SxCR_DIR             0x000000C0
  #define DMA_SxCR_DIR_0           0x00000040
  #define DMA_SxCR_DIR_1           0x00000080
  #define DMA_SxCR_PFCTRL          0x00000020
  #define DMA_SxCR_TCIE            0x00000010
  #define DMA_SxCR_HTIE            0x00000008
  #define DMA_SxCR_TEIE            0x00000004
  #define DMA_SxCR_DMEIE           0x00000002
  #define DMA_SxCR_EN              0x00000001
#define TOFF_DMAS_NDTR      0x0004		/* (RW) DMA stream x number of data register     */
#define TOFF_DMAS_PAR       0x0008		/* (RW) DMA stream x peripheral address register */
#define TOFF_DMAS_M0AR      0x000C		/* (RW) DMA stream x memory 0 address register   */
#define TOFF_DMAS_M1AR      0x0010		/* (RW) DMA stream x memory 1 address register   */
#define TOFF_DMAS_FCR       0x0014		/* (RW) DMA stream x FIFO control register       */
  #define DMA_SxFCR_FEIE           0x00000080
  #define DMA_SxFCR_FS             0x00000038
  #define DMA_SxFCR_FS_0           0x00000008
  #define DMA_SxFCR_FS_1           0x00000010
  #define DMA_SxFCR_FS_2           0x00000020
  #define DMA_SxFCR_DMDIS          0x00000004
  #define DMA_SxFCR_FTH            0x00000003
  #define DMA_SxFCR_FTH_0          0x00000001
  #define DMA_SxFCR_FTH_1          0x00000002

/*
 *  DMA2D CONTROLLER
 */

#define TADR_DMA2D_BASE     (AHB1PERIPH_BASE + 0xB000)
#define TOFF_DMA2D_CR       0x0000	/* (RW) DMA2D Control Register */
  #define DMA2D_CR_START     0x00000001	/* Start transfer */
  #define DMA2D_CR_SUSP      0x00000002	/* Suspend transfer */
  #define DMA2D_CR_ABORT     0x00000004	/* Abort transfer */
  #define DMA2D_CR_TEIE      0x00000100	/* Transfer Error Interrupt Enable */
  #define DMA2D_CR_TCIE      0x00000200	/* Transfer Complete Interrupt Enable */
  #define DMA2D_CR_TWIE      0x00000400	/* Transfer Watermark Interrupt Enable */
  #define DMA2D_CR_CAEIE     0x00000800	/* CLUT Access Error Interrupt Enable */
  #define DMA2D_CR_CTCIE     0x00001000	/* CLUT Transfer Complete Interrupt Enable */
  #define DMA2D_CR_CEIE      0x00002000	/* Configuration Error Interrupt Enable */
  #define DMA2D_CR_MODE      0x00030000	/* DMA2D Mode */
#define TOFF_DMA2D_ISR      0x0004	/* (RW) DMA2D Interrupt Status Register */
  #define DMA2D_ISR_TEIF     0x00000001	/* Transfer Error Interrupt Flag */
  #define DMA2D_ISR_TCIF     0x00000002	/* Transfer Complete Interrupt Flag */
  #define DMA2D_ISR_TWIF     0x00000004	/* Transfer Watermark Interrupt Flag */
  #define DMA2D_ISR_CAEIF    0x00000008	/* CLUT Access Error Interrupt Flag */
  #define DMA2D_ISR_CTCIF    0x00000010	/* CLUT Transfer Complete Interrupt Flag */
  #define DMA2D_ISR_CEIF     0x00000020	/* Configuration Error Interrupt Flag */
#define TOFF_DMA2D_IFCR     0x0008	/* (RW) DMA2D Interrupt Flag Clear Register */
  #define DMA2D_IFSR_CTEIF   0x00000001	/* Clears Transfer Error Interrupt Flag */
  #define DMA2D_IFSR_CTCIF   0x00000002	/* Clears Transfer Complete Interrupt Flag */
  #define DMA2D_IFSR_CTWIF   0x00000004	/* Clears Transfer Watermark Interrupt Flag */
  #define DMA2D_IFSR_CCAEIF  0x00000008	/* Clears CLUT Access Error Interrupt Flag */
  #define DMA2D_IFSR_CCTCIF  0x00000010	/* Clears CLUT Transfer Complete Interrupt Flag */
  #define DMA2D_IFSR_CCEIF   0x00000020	/* Clears Configuration Error Interrupt Flag */
#define TOFF_DMA2D_FGMAR    0x000C	/* (RW) DMA2D Foreground Memory Address Register */
#define TOFF_DMA2D_FGOR     0x0010	/* (RW) DMA2D Foreground Offset Register */
  #define DMA2D_FGOR_LO      0x00003FFF	/* Line Offset */
#define TOFF_DMA2D_BGMAR    0x0014	/* (RW) DMA2D Background Memory Address Register */
  #define DMA2D_BGMAR_MA     0xFFFFFFFF	/* Memory Address */
#define TOFF_DMA2D_BGOR     0x0018	/* (RW) DMA2D Background Offset Register */
  #define DMA2D_BGOR_LO      0x00003FFF	/* Line Offset */
#define TOFF_DMA2D_FGPFCCR  0x001C	/* (RW) DMA2D Foreground PFC Control Register */
  #define DMA2D_FGPFCCR_CM    0x0000000F	/* Color mode */
  #define DMA2D_FGPFCCR_CCM   0x00000010	/* CLUT Color mode */
  #define DMA2D_FGPFCCR_START 0x00000020	/* Start */
  #define DMA2D_FGPFCCR_CS    0x0000FF00	/* CLUT size */
  #define DMA2D_FGPFCCR_AM    0x00030000	/* Alpha mode */
  #define DMA2D_FGPFCCR_ALPHA 0xFF000000	/* Alpha value */
#define TOFF_DMA2D_FGCOLR   0x0020	/* (RW) DMA2D Foreground Color Register */
  #define DMA2D_FGCOLR_BLUE  0x000000FF	/* Blue Value  */
  #define DMA2D_FGCOLR_GREEN 0x0000FF00	/* Green Value */
  #define DMA2D_FGCOLR_RED   0x00FF0000	/* Red Value */
#define TOFF_DMA2D_BGPFCCR  0x0024	/* (RW) DMA2D Background PFC Control Register */
  #define DMA2D_BGPFCCR_CM    0x0000000F	/* Color mode */
  #define DMA2D_BGPFCCR_CCM   0x00000010	/* CLUT Color mode */
  #define DMA2D_BGPFCCR_START 0x00000020	/* Start */
  #define DMA2D_BGPFCCR_CS    0x0000FF00	/* CLUT size */
  #define DMA2D_BGPFCCR_AM    0x00030000	/* Alpha Mode */
  #define DMA2D_BGPFCCR_ALPHA 0xFF000000	/* Alpha value */
#define TOFF_DMA2D_BGCOLR   0x0028	/* (RW) DMA2D Background Color Register */
  #define DMA2D_BGCOLR_BLUE   0x000000FF	/* Blue Value  */
  #define DMA2D_BGCOLR_GREEN  0x0000FF00	/* Green Value */
  #define DMA2D_BGCOLR_RED    0x00FF0000	/* Red Value   */
#define TOFF_DMA2D_FGCMAR   0x002C	/* (RW) DMA2D Foreground CLUT Memory Address Register */
#define TOFF_DMA2D_BGCMAR   0x0030	/* (RW) DMA2D Background CLUT Memory Address Register */
#define TOFF_DMA2D_OPFCCR   0x0034	/* (RW) DMA2D Output PFC Control Register */
  #define DMA2D_OPFCCR_CM    0x00000007	/* Color mode */
#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
  #define DMA2D_OPFCCR_AI    0x00100000	/* Output Alpha Inverted */
  #define DMA2D_OPFCCR_RBS   0x00200000	/* Output Red Blue Swap */
#endif
#define TOFF_DMA2D_OCOLR    0x0038	/* (RW) DMA2D Output Color Register */
  /* Mode_ARGB8888/RGB888 */
  #define DMA2D_OCOLR_BLUE_1  0x000000FF	/* BLUE Value          */
  #define DMA2D_OCOLR_GREEN_1 0x0000FF00	/* GREEN Value         */
  #define DMA2D_OCOLR_RED_1   0x00FF0000	/* Red Value           */
  #define DMA2D_OCOLR_ALPHA_1 0xFF000000	/* Alpha Channel Value */
  /* Mode_RGB565 */
  #define DMA2D_OCOLR_BLUE_2  0x0000001F	/* BLUE Value   */
  #define DMA2D_OCOLR_GREEN_2 0x000007E0	/* GREEN Value  */
  #define DMA2D_OCOLR_RED_2   0x0000F800	/* Red Value    */
  /* Mode_ARGB1555 */
  #define DMA2D_OCOLR_BLUE_3  0x0000001F	/* BLUE Value          */
  #define DMA2D_OCOLR_GREEN_3 0x000003E0	/* GREEN Value         */
  #define DMA2D_OCOLR_RED_3   0x00007C00	/* Red Value           */
  #define DMA2D_OCOLR_ALPHA_3 0x00008000	/* Alpha Channel Value */
  /* Mode_ARGB4444 */
  #define DMA2D_OCOLR_BLUE_4  0x0000000F	/* BLUE Value          */
  #define DMA2D_OCOLR_GREEN_4 0x000000F0	/* GREEN Value         */
  #define DMA2D_OCOLR_RED_4   0x00000F00	/* Red Value           */
  #define DMA2D_OCOLR_ALPHA_4 0x0000F000	/* Alpha Channel Value */
#define TOFF_DMA2D_OMAR     0x003C	/* (RW) DMA2D Output Memory Address Register */
  #define DMA2D_OMAR_MA      0xFFFFFFFF	/* Memory Address */
#define TOFF_DMA2D_OOR      0x0040	/* (RW) DMA2D Output Offset Register */
  #define DMA2D_OOR_LO       0x00003FFF	/* Line Offset */
#define TOFF_DMA2D_NLR      0x0044	/* (RW) DMA2D Number of Line Register */
#define TOFF_DMA2D_LWR      0x0048	/* (RW) DMA2D Line Watermark Register */
#define TOFF_DMA2D_AMTCR    0x004C	/* (RW) DMA2D AHB Master Timer Configuration Register */
#define TOFF_DMA2D_FGCLUT   0x0400	/* (RW) DMA2D Foreground CLUT 400-7FF */
#define TOFF_DMA2D_BGCLUT   0x0800	/* (RW) DMA2D Background CLUT 800-BFF */



#define TADR_ETH_BASE       (AHB1PERIPH_BASE + 0x8000)
#define ETH_MAC_BASE        (ETH_BASE)
#define TOFF_ETH_MACCR      0x0000		/* (RW) Ethernet MAC configuration register */
  #define ETH_MACCR_RE          0x00000004	/* Receiver enable */
  #define ETH_MACCR_TE          0x00000008	/* Transmitter enable */
  #define ETH_MACCR_DC          0x00000010	/* Defferal check */
  #define ETH_MACCR_BL          0x00000060	/* Back-off limit: random integer number (r) of slot time delays before rescheduling
                                          	    a transmission attempt during retries after a collision: 0 =< r <2^k */
  #define ETH_MACCR_BL_10       0x00000000	/* k = min (n, 10) */
  #define ETH_MACCR_BL_8        0x00000020	/* k = min (n, 8) */
  #define ETH_MACCR_BL_4        0x00000040	/* k = min (n, 4) */
  #define ETH_MACCR_BL_1        0x00000060	/* k = min (n, 1) */
  #define ETH_MACCR_APCS        0x00000080	/* Automatic Pad/CRC stripping */
  #define ETH_MACCR_RD          0x00000200	/* Retry disable */
  #define ETH_MACCR_IPCO        0x00000400	/* IP Checksum offload */
  #define ETH_MACCR_DM          0x00000800	/* Duplex mode */
  #define ETH_MACCR_LM          0x00001000	/* loopback mode */
  #define ETH_MACCR_ROD         0x00002000	/* Receive own disable */
  #define ETH_MACCR_FES         0x00004000	/* Fast ethernet speed */
  #define ETH_MACCR_CSD         0x00010000	/* Carrier sense disable (during transmission) */
  #define ETH_MACCR_IFG         0x000E0000	/* Inter-frame gap */
  #define ETH_MACCR_IFG_96Bit   0x00000000	/* Minimum IFG between frames during transmission is 96Bit */
  #define ETH_MACCR_IFG_88Bit   0x00020000	/* Minimum IFG between frames during transmission is 88Bit */
  #define ETH_MACCR_IFG_80Bit   0x00040000	/* Minimum IFG between frames during transmission is 80Bit */
  #define ETH_MACCR_IFG_72Bit   0x00060000	/* Minimum IFG between frames during transmission is 72Bit */
  #define ETH_MACCR_IFG_64Bit   0x00080000	/* Minimum IFG between frames during transmission is 64Bit */
  #define ETH_MACCR_IFG_56Bit   0x000A0000	/* Minimum IFG between frames during transmission is 56Bit */
  #define ETH_MACCR_IFG_48Bit   0x000C0000	/* Minimum IFG between frames during transmission is 48Bit */
  #define ETH_MACCR_IFG_40Bit   0x000E0000	/* Minimum IFG between frames during transmission is 40Bit */
  #define ETH_MACCR_JD          0x00400000	/* Jabber disable */
  #define ETH_MACCR_WD          0x00800000	/* Watchdog disable */
#define TOFF_ETH_MACFFR     0x0004		/* (RW) Ethernet MAC frame filter register */
  #define ETH_MACFFR_PM         0x00000001	/* Promiscuous mode */
  #define ETH_MACFFR_HU         0x00000002	/* Hash unicast */
  #define ETH_MACFFR_HM         0x00000004	/* Hash multicast */
  #define ETH_MACFFR_DAIF       0x00000008	/* DA Inverse filtering */
  #define ETH_MACFFR_PAM        0x00000010	/* Pass all mutlicast */
  #define ETH_MACFFR_BFD        0x00000020	/* Broadcast frame disable */
  #define ETH_MACFFR_PCF        0x000000C0	/* Pass control frames: 3 cases */
  #define ETH_MACFFR_PCF_BlockAll                 0x00000040	/* MAC filters all control frames from reaching the application */
  #define ETH_MACFFR_PCF_ForwardAll               0x00000080	/* MAC forwards all control frames to application even if they fail the Address Filter */
  #define ETH_MACFFR_PCF_ForwardPassedAddrFilter  0x000000C0	/* MAC forwards control frames that pass the Address Filter. */
  #define ETH_MACFFR_SAIF       0x00000100	/* SA inverse filtering */
  #define ETH_MACFFR_SAF        0x00000200	/* Source address filter enable */
  #define ETH_MACFFR_HPF        0x00000400	/* Hash or perfect filter */
  #define ETH_MACFFR_RA         0x80000000	/* Receive all */
#define TOFF_ETH_MACHTHR    0x0008		/* (RW) Ethernet MAC hash table high register */
#define TOFF_ETH_MACHTLR    0x000C		/* (RW) Ethernet MAC hash table low register */
#define TOFF_ETH_MACMIIAR   0x0010		/* (RW) Ethernet MAC MII address register */
  #define ETH_MACMIIAR_MB       0x00000001	/* MII busy */
  #define ETH_MACMIIAR_MW       0x00000002	/* MII write */
  #define ETH_MACMIIAR_CR       0x0000001C	/* CR clock range: 6 cases */
  #define ETH_MACMIIAR_CR_Div42 0x00000000	/* HCLK:60-100 MHz; MDC clock= HCLK/42 */
  #define ETH_MACMIIAR_CR_Div62 0x00000004	/* HCLK:100-150 MHz; MDC clock= HCLK/62 */
  #define ETH_MACMIIAR_CR_Div16 0x00000008	/* HCLK:20-35 MHz; MDC clock= HCLK/16 */
  #define ETH_MACMIIAR_CR_Div26 0x0000000C	/* HCLK:35-60 MHz; MDC clock= HCLK/26 */
  #define ETH_MACMIIAR_CR_Div102 0x00000010	/* HCLK:150-168 MHz; MDC clock= HCLK/102 */
  #define ETH_MACMIIAR_MR       0x000007C0	/* MII register in the selected PHY */
  #define ETH_MACMIIAR_PA       0x0000F800	/* Physical layer address */
#define TOFF_ETH_MACMIIDR   0x0014		/* (RW) Ethernet MAC MII data register */
#define TOFF_ETH_MACFCR     0x0018		/* (RW) Ethernet MAC flow control register */
  #define ETH_MACFCR_FCBBPA     0x00000001	/* Flow control busy/backpressure activate */
  #define ETH_MACFCR_TFCE       0x00000002	/* Transmit flow control enable */
  #define ETH_MACFCR_RFCE       0x00000004	/* Receive flow control enable */
  #define ETH_MACFCR_UPFD       0x00000008	/* Unicast pause frame detect */
  #define ETH_MACFCR_PLT        0x00000030	/* Pause low threshold: 4 cases */
  #define ETH_MACFCR_PLT_Minus4   0x00000000	/* Pause time minus 4 slot times */
  #define ETH_MACFCR_PLT_Minus28  0x00000010	/* Pause time minus 28 slot times */
  #define ETH_MACFCR_PLT_Minus144 0x00000020	/* Pause time minus 144 slot times */
  #define ETH_MACFCR_PLT_Minus256 0x00000030	/* Pause time minus 256 slot times */
  #define ETH_MACFCR_ZQPD       0x00000080	/* Zero-quanta pause disable */
  #define ETH_MACFCR_PT         0xFFFF0000	/* Pause time */
#define TOFF_ETH_MACVLANTR  0x001C	/* (RW) Ethernet MAC VLAN tag register */
  #define ETH_MACVLANTR_VLANTI  0x0000FFFF	/* VLAN tag identifier (for receive frames) */
  #define ETH_MACVLANTR_VLANTC  0x00010000	/* 12-bit VLAN tag comparison */
#define TOFF_ETH_MACRWUFFR  0x0028	/* (RW) Ethernet MAC remote wakeup frame filter register */
#define TOFF_ETH_MACPMTCSR  0x002C	/* (RW) Ethernet MAC PMT control and status register */
  #define ETH_MACPMTCSR_PD      0x00000001	/* Power Down */
  #define ETH_MACPMTCSR_MPE     0x00000002	/* Magic Packet Enable */
  #define ETH_MACPMTCSR_WFE     0x00000004	/* Wake-Up Frame Enable */
  #define ETH_MACPMTCSR_MPR     0x00000020	/* Magic Packet Received */
  #define ETH_MACPMTCSR_WFR     0x00000040	/* Wake-Up Frame Received */
  #define ETH_MACPMTCSR_GU      0x00000200	/* Global Unicast */
  #define ETH_MACPMTCSR_WFFRPR  0x80000000	/* Wake-Up Frame Filter Register Pointer Reset */
#define TOFF_ETH_MACDBGR    0x0034	/* (RW) Ethernet MAC debug register */
  #define ETH_MACDBGR_MMRPEA    0x00000001	/* MAC MII receive protocol engine active */
  #define ETH_MACDBGR_MSFRWCS   0x00000006	/* MAC small FIFO read / write controllers status  mask */
  #define ETH_MACDBGR_MSFRWCS_0 0x00000002
  #define ETH_MACDBGR_MSFRWCS_1 0x00000004
  #define ETH_MACDBGR_RFWRA     0x00000010	/* Rx FIFO write controller active */
  #define ETH_MACDBGR_RFRCS     0x00000060	/* Rx FIFO read controller status mask */
  #define ETH_MACDBGR_RFRCS_FLUSHING      0x00000060	/* Flushing the frame data and status */
  #define ETH_MACDBGR_RFRCS_STATUSREADING 0x00000040	/* Reading frame status (or time-stamp) */
  #define ETH_MACDBGR_RFRCS_DATAREADING   0x00000020	/* Reading frame data */
  #define ETH_MACDBGR_RFRCS_IDLE          0x00000000	/* IDLE state */
  #define ETH_MACDBGR_RFFL      0x00000300	/* Rx FIFO fill level mask */
  #define ETH_MACDBGR_RFFL_FULL           0x00000300	/* RxFIFO full */
  #define ETH_MACDBGR_RFFL_ABOVEFCT       0x00000200	/* RxFIFO fill-level above flow-control activate threshold */
  #define ETH_MACDBGR_RFFL_BELOWFCT       0x00000100	/* RxFIFO fill-level below flow-control de-activate threshold  */
  #define ETH_MACDBGR_RFFL_EMPTY          0x00000000	/* RxFIFO empty */
  #define ETH_MACDBGR_MMTEA     0x00010000	/* MAC MII transmit engine active */
  #define ETH_MACDBGR_MTFCS     0x00060000	/* MAC transmit frame controller status mask */
  #define ETH_MACDBGR_MTFCS_TRANSFERRING  0x00060000	/* Transferring input frame for transmission */
  #define ETH_MACDBGR_MTFCS_GENERATINGPCF 0x00040000	/* Generating and transmitting a Pause control frame (in full duplex mode) */
  #define ETH_MACDBGR_MTFCS_WAITING       0x00020000	/* Waiting for Status of previous frame or IFG/backoff period to be over   */
  #define ETH_MACDBGR_MTFCS_IDLE          0x00000000	/* Idle */
  #define ETH_MACDBGR_MTP       0x00080000	/* MAC transmitter in pause */
  #define ETH_MACDBGR_TFRS      0x00300000	/* Tx FIFO read status mask */
  #define ETH_MACDBGR_TFRS_WRITING        0x00300000	/* Writing the received TxStatus or flushing the TxFIFO */
  #define ETH_MACDBGR_TFRS_WAITING        0x00200000	/* Waiting for TxStatus from MAC transmitter */
  #define ETH_MACDBGR_TFRS_READ           0x00100000	/* Read state (transferring data to the MAC transmitter) */
  #define ETH_MACDBGR_TFRS_IDLE           0x00000000	/* Idle state */
  #define ETH_MACDBGR_TPWA      0x00400000	/* Tx FIFO write active */
  #define ETH_MACDBGR_TFNE      0x01000000	/* Tx FIFO not empty */
  #define ETH_MACDBGR_TFF       0x02000000	/* Tx FIFO full */
#define TOFF_ETH_MACSR      0x0038		/* (R) Ethernet MAC interrupt status register */
  #define ETH_MACSR_PMTS        0x00000008	/* PMT status */
  #define ETH_MACSR_MMCS        0x00000010	/* MMC status */
  #define ETH_MACSR_MMMCRS      0x00000020	/* MMC receive status */
  #define ETH_MACSR_MMCTS       0x00000040	/* MMC transmit status */
  #define ETH_MACSR_TSTS        0x00000200	/* Time stamp trigger status */
#define TOFF_ETH_MACIMR     0x003C		/* (RW) Ethernet MAC interrupt mask register */
  #define ETH_MACIMR_PMTIM      0x00000008	/* PMT interrupt mask */
  #define ETH_MACIMR_TSTIM      0x00000200	/* Time stamp trigger interrupt mask */
#define TOFF_ETH_MACA0HR    0x0040		/* (RW) Ethernet MAC address 0 high register */
#define TOFF_ETH_MACA0LR    0x0044		/* (RW) Ethernet MAC address 0 low register */
#define TOFF_ETH_MACA1HR    0x0048		/* (RW) Ethernet MAC address 1 high register */
  #define ETH_MACA1HR_MACA1H    0x0000FFFF	/* MAC address1 high */
  #define ETH_MACA1HR_MBC       0x3F000000	/* Mask byte control: bits to mask for comparison of the MAC Address bytes */
  #define ETH_MACA1HR_MBC_HBits15_8       0x20000000	/* Mask MAC Address high reg bits [15:8] */
  #define ETH_MACA1HR_MBC_HBits7_0        0x10000000	/* Mask MAC Address high reg bits [7:0] */
  #define ETH_MACA1HR_MBC_LBits31_24      0x08000000	/* Mask MAC Address low reg bits [31:24] */
  #define ETH_MACA1HR_MBC_LBits23_16      0x04000000	/* Mask MAC Address low reg bits [23:16] */
  #define ETH_MACA1HR_MBC_LBits15_8       0x02000000	/* Mask MAC Address low reg bits [15:8] */
  #define ETH_MACA1HR_MBC_LBits7_0        0x01000000	/* Mask MAC Address low reg bits [7:0] */
  #define ETH_MACA1HR_SA                  0x40000000	/* Source address */
  #define ETH_MACA1HR_AE                  0x80000000	/* Address enable */
#define TOFF_ETH_MACA1LR    0x004C		/* (RW) Ethernet MAC address 1 low register */
#define TOFF_ETH_MACA2HR    0x0050		/* (RW) Ethernet MAC address 2 high register */
  #define ETH_MACA2HR_MACA2H    0x0000FFFF	/* MAC address1 high */
  #define ETH_MACA2HR_MBC       0x3F000000	/* Mask byte control */
  #define ETH_MACA2HR_MBC_HBits15_8       0x20000000	/* Mask MAC Address high reg bits [15:8] */
  #define ETH_MACA2HR_MBC_HBits7_0        0x10000000	/* Mask MAC Address high reg bits [7:0] */
  #define ETH_MACA2HR_MBC_LBits31_24      0x08000000	/* Mask MAC Address low reg bits [31:24] */
  #define ETH_MACA2HR_MBC_LBits23_16      0x04000000	/* Mask MAC Address low reg bits [23:16] */
  #define ETH_MACA2HR_MBC_LBits15_8       0x02000000	/* Mask MAC Address low reg bits [15:8] */
  #define ETH_MACA2HR_MBC_LBits7_0        0x01000000	/* Mask MAC Address low reg bits [70] */
  #define ETH_MACA2HR_SA        0x40000000	/* Source address */
  #define ETH_MACA2HR_AE        0x80000000	/* Address enable */
#define TOFF_ETH_MACA2LR    0x0054		/* (RW) Ethernet MAC address 2 low register */
#define TOFF_ETH_MACA3HR    0x0058		/* (RW) Ethernet MAC address 3 high register */
  #define ETH_MACA3HR_MACA3H    0x0000FFFF	/* MAC address3 high */
  #define ETH_MACA3HR_MBC       0x3F000000	/* Mask byte control */
  #define ETH_MACA3HR_MBC_HBits15_8       0x20000000	/* Mask MAC Address high reg bits [15:8] */
  #define ETH_MACA3HR_MBC_HBits7_0        0x10000000	/* Mask MAC Address high reg bits [7:0] */
  #define ETH_MACA3HR_MBC_LBits31_24      0x08000000	/* Mask MAC Address low reg bits [31:24] */
  #define ETH_MACA3HR_MBC_LBits23_16      0x04000000	/* Mask MAC Address low reg bits [23:16] */
  #define ETH_MACA3HR_MBC_LBits15_8       0x02000000	/* Mask MAC Address low reg bits [15:8] */
  #define ETH_MACA3HR_MBC_LBits7_0        0x01000000	/* Mask MAC Address low reg bits [70] */
  #define ETH_MACA3HR_SA        0x40000000	/* Source address */
  #define ETH_MACA3HR_AE        0x80000000	/* Address enable */
#define TOFF_ETH_MACA3LR    0x005C		/* (RW) Ethernet MAC address 3 low register */
#define TOFF_ETH_MMCCR      0x0100		/* (RW) Ethernet MMC control register */
  #define ETH_MMCCR_CR          0x00000001	/* Counters Reset */
  #define ETH_MMCCR_CSR         0x00000002	/* Counter Stop Rollover */
  #define ETH_MMCCR_ROR         0x00000004	/* Reset on Read */
  #define ETH_MMCCR_MCF         0x00000008	/* MMC Counter Freeze */
  #define ETH_MMCCR_MCP         0x00000010	/* MMC counter preset */
  #define ETH_MMCCR_MCFHP       0x00000020	/* MMC counter Full-Half preset */
#define TOFF_ETH_MMCRIR     0x0104		/* (R) Ethernet MMC receive interrupt register */
  #define ETH_MMCRIR_RFCES      0x00000020	/* Set when Rx crc error counter reaches half the maximum value */
  #define ETH_MMCRIR_RFAES      0x00000040	/* Set when Rx alignment error counter reaches half the maximum value */
  #define ETH_MMCRIR_RGUFS      0x00020000	/* Set when Rx good unicast frames counter reaches half the maximum value */
#define TOFF_ETH_MMCTIR     0x0108		/* (R) Ethernet MMC transmit interrupt register */
  #define ETH_MMCTIR_TGFSCS     0x00004000	/* Set when Tx good single col counter reaches half the maximum value */
  #define ETH_MMCTIR_TGFMSCS    0x00008000	/* Set when Tx good multi col counter reaches half the maximum value */
  #define ETH_MMCTIR_TGFS       0x00200000	/* Set when Tx good frame count counter reaches half the maximum value */
#define TOFF_ETH_MMCRIMR    0x010C		/* (RW) Ethernet MMC receive interrupt mask register */
  #define ETH_MMCRIMR_RFCEM     0x00000020	/* Mask the interrupt when Rx crc error counter reaches half the maximum value */
  #define ETH_MMCRIMR_RFAEM     0x00000040	/* Mask the interrupt when when Rx alignment error counter reaches half the maximum value */
  #define ETH_MMCRIMR_RGUFM     0x00020000	/* Mask the interrupt when Rx good unicast frames counter reaches half the maximum value */
#define TOFF_ETH_MMCTIMR    0x0110		/* (RW) Ethernet MMC transmit interrupt mask register */
  #define ETH_MMCTIMR_TGFSCM    0x00004000	/* Mask the interrupt when Tx good single col counter reaches half the maximum value */
  #define ETH_MMCTIMR_TGFMSCM   0x00008000	/* Mask the interrupt when Tx good multi col counter reaches half the maximum value */
  #define ETH_MMCTIMR_TGFM      0x00200000	/* Mask the interrupt when Tx good frame count counter reaches half the maximum value */
#define TOFF_ETH_MMCTGFSCCR 0x014C		/* (R) Ethernet MMC transmitted good frames after a single collision counter register */
#define TOFF_ETH_MMCTGFMSCCR 0x0150		/* (R) Ethernet MMC transmitted good frames after more than a single collision counter register */
#define TOFF_ETH_MMCTGFCR   0x0168		/* (R) Ethernet MMC transmitted good frames counter register */
#define TOFF_ETH_MMCRFCECR  0x0194		/* (R) Ethernet MMC received frames with CRC error counter register */
#define TOFF_ETH_MMCRFAECR  0x0198		/* (R) Ethernet MMC received frames with alignment error counter register */
#define TOFF_ETH_MMCRGUFCR  0x01C4		/* (R) MMC received good unicast frames counter register */
#define TOFF_ETH_PTPTSCR    0x0700		/* (RW) Ethernet PTP time stamp control register */
  #define ETH_PTPTSCR_TSE       0x00000001	/* Time stamp enable */
  #define ETH_PTPTSCR_TSFCU     0x00000002	/* Time stamp fine or coarse update */
  #define ETH_PTPTSCR_TSSTI     0x00000004	/* Time stamp initialize */
  #define ETH_PTPTSCR_TSSTU     0x00000008	/* Time stamp update */
  #define ETH_PTPTSCR_TSITE     0x00000010	/* Time stamp interrupt trigger enable */
  #define ETH_PTPTSCR_TSARU     0x00000020	/* Addend register update */
  #define ETH_PTPTSSR_TSSARFE   0x00000100	/* Time stamp snapshot for all received frames enable */
  #define ETH_PTPTSSR_TSSSR     0x00000200	/* Time stamp Sub-seconds rollover */
  #define ETH_PTPTSSR_TSPTPPSV2E 0x00000400	/* Time stamp PTP packet snooping for version2 format enable */
  #define ETH_PTPTSSR_TSSPTPOEFE 0x00000800	/* Time stamp snapshot for PTP over ethernet frames enable */
  #define ETH_PTPTSSR_TSSIPV6FE 0x00001000	/* Time stamp snapshot for IPv6 frames enable */
  #define ETH_PTPTSSR_TSSIPV4FE 0x00002000	/* Time stamp snapshot for IPv4 frames enable */
  #define ETH_PTPTSSR_TSSEME    0x00004000	/* Time stamp snapshot for event message enable */
  #define ETH_PTPTSSR_TSSMRME   0x00008000	/* Time stamp snapshot for message relevant to master enable */
  #define ETH_PTPTSCR_TSCNT     0x00030000	/* Time stamp clock node type */
#define TOFF_ETH_PTPSSIR    0x0704		/* (RW) Ethernet PTP subsecond increment register */
#define TOFF_ETH_PTPTSHR    0x0708		/* (R) Ethernet PTP time stamp high register */
#define TOFF_ETH_PTPTSLR    0x070C		/* (R) Ethernet PTP time stamp low register */
#define TOFF_ETH_PTPTSHUR   0x0710		/* (RW) Ethernet PTP time stamp high update register */
#define TOFF_ETH_PTPTSLUR   0x0714		/* (RW) Ethernet PTP time stamp low update register */
#define TOFF_ETH_PTPTSAR    0x0718		/* (RW) Ethernet PTP time stamp addend register */
#define TOFF_ETH_PTPTTHR    0x071C		/* (RW) Ethernet PTP target time high register */
#define TOFF_ETH_PTPTTLR    0x0720		/* (RW) Ethernet PTP target time low register */
#define TOFF_ETH_PTPTSSR    0x0728		/* (R) Ethernet PTP time stamp status register */
  #define ETH_PTPTSSR_TSSO      0x00000010	/* Time stamp seconds overflow */
  #define ETH_PTPTSSR_TSTTR     0x00000020	/* Time stamp target time reached */
#define TOFF_ETH_PTPPPSCR   0x072C		/* (RW) Ethernet PTP PPS control register */
#define TOFF_ETH_DMABMR     0x1000		/* Ethernet DMA bus mode register */
  #define ETH_DMABMR_SR         0x00000001	/* Software reset */
  #define ETH_DMABMR_DA         0x00000002	/* DMA arbitration scheme */
  #define ETH_DMABMR_DSL        0x0000007C	/* Descriptor Skip Length */
  #define ETH_DMABMR_EDE        0x00000080	/* Enhanced Descriptor Enable */
  #define ETH_DMABMR_PBL        0x00003F00	/* Programmable burst length */
  #define ETH_DMABMR_PBL_1Beat  0x00000100	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 1 */
  #define ETH_DMABMR_PBL_2Beat  0x00000200	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 2 */
  #define ETH_DMABMR_PBL_4Beat  0x00000400	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
  #define ETH_DMABMR_PBL_8Beat  0x00000800	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
  #define ETH_DMABMR_PBL_16Beat 0x00001000	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
  #define ETH_DMABMR_PBL_32Beat 0x00002000	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */
  #define ETH_DMABMR_RTPR       0x0000C000	/* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_1_1   0x00000000	/* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_2_1   0x00004000	/* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_3_1   0x00008000	/* Rx Tx priority ratio */
  #define ETH_DMABMR_RTPR_4_1   0x0000C000	/* Rx Tx priority ratio */
  #define ETH_DMABMR_FB         0x00010000	/* Fixed Burst */
  #define ETH_DMABMR_RDP        0x007E0000	/* RxDMA PBL */
  #define ETH_DMABMR_RDP_1Beat          0x00020000	/* maximum number of beats to be transferred in one RxDMA transaction is 1 */
  #define ETH_DMABMR_RDP_2Beat          0x00040000	/* maximum number of beats to be transferred in one RxDMA transaction is 2 */
  #define ETH_DMABMR_RDP_4Beat          0x00080000	/* maximum number of beats to be transferred in one RxDMA transaction is 4 */
  #define ETH_DMABMR_RDP_8Beat          0x00100000	/* maximum number of beats to be transferred in one RxDMA transaction is 8 */
  #define ETH_DMABMR_RDP_16Beat         0x00200000	/* maximum number of beats to be transferred in one RxDMA transaction is 16 */
  #define ETH_DMABMR_RDP_32Beat         0x00400000	/* maximum number of beats to be transferred in one RxDMA transaction is 32 */
  #define ETH_DMABMR_USP        0x00800000	/* Use separate PBL */
  #define ETH_DMABMR_FPM        0x01000000	/* 4xPBL mode */
  #define ETH_DMABMR_AAB        0x02000000	/* Address-Aligned beats */
  #define ETH_DMABMR_RDP_4xPBL_4Beat    0x01020000	/* maximum number of beats to be transferred in one RxDMA transaction is 4 */
  #define ETH_DMABMR_RDP_4xPBL_8Beat    0x01040000	/* maximum number of beats to be transferred in one RxDMA transaction is 8 */
  #define ETH_DMABMR_RDP_4xPBL_16Beat   0x01080000	/* maximum number of beats to be transferred in one RxDMA transaction is 16 */
  #define ETH_DMABMR_RDP_4xPBL_32Beat   0x01100000	/* maximum number of beats to be transferred in one RxDMA transaction is 32 */
  #define ETH_DMABMR_RDP_4xPBL_64Beat   0x01200000	/* maximum number of beats to be transferred in one RxDMA transaction is 64 */
  #define ETH_DMABMR_RDP_4xPBL_128Beat  0x01400000	/* maximum number of beats to be transferred in one RxDMA transaction is 128 */
  #define ETH_DMABMR_PBL_4xPBL_4Beat    0x01000100	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
  #define ETH_DMABMR_PBL_4xPBL_8Beat    0x01000200	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
  #define ETH_DMABMR_PBL_4xPBL_16Beat   0x01000400	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
  #define ETH_DMABMR_PBL_4xPBL_32Beat   0x01000800	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */
  #define ETH_DMABMR_PBL_4xPBL_64Beat   0x01001000	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 64 */
  #define ETH_DMABMR_PBL_4xPBL_128Beat  0x01002000	/* maximum number of beats to be transferred in one TxDMA (or both) transaction is 128 */
#define TOFF_ETH_DMATPDR    0x1004		/* (RW) Ethernet DMA transmit poll demain register */
#define TOFF_ETH_DMARPDR    0x1008		/* (RW) Ethernet DMA receive poll demain register */
#define TOFF_ETH_DMARDLAR   0x100C		/* (RW) Ethernet DMA receive descriptor list address register */
#define TOFF_ETH_DMATDLAR   0x1010		/* (RW) Ethernet DMA transmit descriptor list address register */
#define TOFF_ETH_DMASR      0x1014		/* (R) Ethernet DMA status register */
  #define ETH_DMASR_TS          0x00000001	/* Transmit status */
  #define ETH_DMASR_TPSS        0x00000002	/* Transmit process stopped status */
  #define ETH_DMASR_TBUS        0x00000004	/* Transmit buffer unavailable status */
  #define ETH_DMASR_TJTS        0x00000008	/* Transmit jabber timeout status */
  #define ETH_DMASR_ROS         0x00000010	/* Receive overflow status */
  #define ETH_DMASR_TUS         0x00000020	/* Transmit underflow status */
  #define ETH_DMASR_RS          0x00000040	/* Receive status */
  #define ETH_DMASR_RBUS        0x00000080	/* Receive buffer unavailable status */
  #define ETH_DMASR_RPSS        0x00000100	/* Receive process stopped status */
  #define ETH_DMASR_RWTS        0x00000200	/* Receive watchdog timeout status */
  #define ETH_DMASR_ETS         0x00000400	/* Early transmit status */
  #define ETH_DMASR_FBES        0x00002000	/* Fatal bus error status */
  #define ETH_DMASR_ERS         0x00004000	/* Early receive status */
  #define ETH_DMASR_AIS         0x00008000	/* Abnormal interrupt summary */
  #define ETH_DMASR_NIS         0x00010000	/* Normal interrupt summary */
  #define ETH_DMASR_RPS         0x000E0000	/* Receive process state */
  #define ETH_DMASR_RPS_Stopped           0x00000000	/* Stopped - Reset or Stop Rx Command issued */
  #define ETH_DMASR_RPS_Fetching          0x00020000	/* Running - fetching the Rx descriptor */
  #define ETH_DMASR_RPS_Waiting           0x00060000	/* Running - waiting for packet */
  #define ETH_DMASR_RPS_Suspended         0x00080000	/* Suspended - Rx Descriptor unavailable */
  #define ETH_DMASR_RPS_Closing           0x000A0000	/* Running - closing descriptor */
  #define ETH_DMASR_RPS_Queuing           0x000E0000	/* Running - queuing the recieve frame into host memory */
  #define ETH_DMASR_TPS         0x00700000	/* Transmit process state */
  #define ETH_DMASR_TPS_Stopped           0x00000000	/* Stopped - Reset or Stop Tx Command issued  */
  #define ETH_DMASR_TPS_Fetching          0x00100000	/* Running - fetching the Tx descriptor */
  #define ETH_DMASR_TPS_Waiting           0x00200000	/* Running - waiting for status */
  #define ETH_DMASR_TPS_Reading           0x00300000	/* Running - reading the data from host memory */
  #define ETH_DMASR_TPS_Suspended         0x00600000	/* Suspended - Tx Descriptor unavailabe */
  #define ETH_DMASR_TPS_Closing           0x00700000	/* Running - closing Rx descriptor */
  #define ETH_DMASR_EBS         0x03800000	/* Error bits status */
  #define ETH_DMASR_EBS_DataTransfTx      0x00800000	/* Error bits 0-Rx DMA, 1-Tx DMA */
  #define ETH_DMASR_EBS_ReadTransf        0x01000000	/* Error bits 0-write trnsf, 1-read transfr */
  #define ETH_DMASR_EBS_DescAccess        0x02000000	/* Error bits 0-data buffer, 1-desc. access */
  #define ETH_DMASR_MMCS        0x08000000	/* MMC status */
  #define ETH_DMASR_PMTS        0x10000000	/* PMT status */
  #define ETH_DMASR_TSTS        0x20000000	/* Time-stamp trigger status */
#define TOFF_ETH_DMAOMR     0x1018		/* (RW) Ethernet DMA operation mode register */
  #define ETH_DMAOMR_SR         0x00000002	/* Start/stop receive */
  #define ETH_DMAOMR_OSF        0x00000004	/* operate on second frame */
  #define ETH_DMAOMR_RTC        0x00000018	/* receive threshold control */
  #define ETH_DMAOMR_RTC_64Bytes          0x00000000	/* threshold level of the MTL Receive FIFO is 64 Bytes */
  #define ETH_DMAOMR_RTC_32Bytes          0x00000008	/* threshold level of the MTL Receive FIFO is 32 Bytes */
  #define ETH_DMAOMR_RTC_96Bytes          0x00000010	/* threshold level of the MTL Receive FIFO is 96 Bytes */
  #define ETH_DMAOMR_RTC_128Bytes         0x00000018	/* threshold level of the MTL Receive FIFO is 128 Bytes */
  #define ETH_DMAOMR_FUGF       0x00000040	/* Forward undersized good frames */
  #define ETH_DMAOMR_FEF        0x00000080	/* Forward error frames */
  #define ETH_DMAOMR_ST         0x00002000	/* Start/stop transmission command */
  #define ETH_DMAOMR_TTC        0x0001C000	/* Transmit threshold control */
  #define ETH_DMAOMR_TTC_64Bytes          0x00000000	/* threshold level of the MTL Transmit FIFO is 64 Bytes */
  #define ETH_DMAOMR_TTC_128Bytes         0x00004000	/* threshold level of the MTL Transmit FIFO is 128 Bytes */
  #define ETH_DMAOMR_TTC_192Bytes         0x00008000	/* threshold level of the MTL Transmit FIFO is 192 Bytes */
  #define ETH_DMAOMR_TTC_256Bytes         0x0000C000	/* threshold level of the MTL Transmit FIFO is 256 Bytes */
  #define ETH_DMAOMR_TTC_40Bytes          0x00010000	/* threshold level of the MTL Transmit FIFO is 40 Bytes */
  #define ETH_DMAOMR_TTC_32Bytes          0x00014000	/* threshold level of the MTL Transmit FIFO is 32 Bytes */
  #define ETH_DMAOMR_TTC_24Bytes          0x00018000	/* threshold level of the MTL Transmit FIFO is 24 Bytes */
  #define ETH_DMAOMR_TTC_16Bytes          0x0001C000	/* threshold level of the MTL Transmit FIFO is 16 Bytes */
  #define ETH_DMAOMR_FTF        0x00100000	/* Flush transmit FIFO */
  #define ETH_DMAOMR_TSF        0x00200000	/* Transmit store and forward */
  #define ETH_DMAOMR_DFRF       0x01000000	/* Disable flushing of received frames */
  #define ETH_DMAOMR_RSF        0x02000000	/* Receive store and forward */
  #define ETH_DMAOMR_DTCEFD     0x04000000	/* Disable Dropping of TCP/IP checksum error frames */
#define TOFF_ETH_DMAIER     0x101C		/* (RW) Ethernet DMA interrupt enable register */
  #define ETH_DMAIER_TIE        0x00000001	/* Transmit interrupt enable */
  #define ETH_DMAIER_TPSIE      0x00000002	/* Transmit process stopped interrupt enable */
  #define ETH_DMAIER_TBUIE      0x00000004	/* Transmit buffer unavailable interrupt enable */
  #define ETH_DMAIER_TJTIE      0x00000008	/* Transmit jabber timeout interrupt enable */
  #define ETH_DMAIER_ROIE       0x00000010	/* Receive Overflow interrupt enable */
  #define ETH_DMAIER_TUIE       0x00000020	/* Transmit Underflow interrupt enable */
  #define ETH_DMAIER_RIE        0x00000040	/* Receive interrupt enable */
  #define ETH_DMAIER_RBUIE      0x00000080	/* Receive buffer unavailable interrupt enable */
  #define ETH_DMAIER_RPSIE      0x00000100	/* Receive process stopped interrupt enable */
  #define ETH_DMAIER_RWTIE      0x00000200	/* Receive watchdog timeout interrupt enable */
  #define ETH_DMAIER_ETIE       0x00000400	/* Early transmit interrupt enable */
  #define ETH_DMAIER_FBEIE      0x00002000	/* Fatal bus error interrupt enable */
  #define ETH_DMAIER_ERIE       0x00004000	/* Early receive interrupt enable */
  #define ETH_DMAIER_AISE       0x00008000	/* Abnormal interrupt summary enable */
  #define ETH_DMAIER_NISE       0x00010000	/* Normal interrupt summary enable */
#define TOFF_ETH_DMAMFBOCR  0x1020		/* (R) Ethernet DMA messed frame and buffer overflow counter register */
  #define ETH_DMAMFBOCR_MFC     0x0000FFFF	/* Number of frames missed by the controller */
  #define ETH_DMAMFBOCR_OMFC    0x00010000	/* Overflow bit for missed frame counter */
  #define ETH_DMAMFBOCR_MFA     0x0FFE0000	/* Number of frames missed by the application */
  #define ETH_DMAMFBOCR_OFOC    0x10000000	/* Overflow bit for FIFO overflow counter */
#define TOFF_ETH_DMARSWTR   0x1024		/* (RW) Ethernet DMA recive status watchdog timer register */
#define TOFF_ETH_DMACHTDR   0x1048		/* (R) Ethernet DMA current host transmit descriptor register */
#define TOFF_ETH_DMACHRDR   0x104C		/* (R) Ethernet DMA current host receive descriptor register */
#define TOFF_ETH_DMACHTBAR  0x1050		/* (R) Ethernet DMA current host transmit buffer address register */
#define TOFF_ETH_DMACHRBAR  0x1054		/* (R) Ethernet DMA current host receive buffer address register */


/*
 *  SERIAL AUDIO INTERFACE
 */
#define TADR_SAI1_BASE      (APB2PERIPH_BASE + 0x5800)
#define TADR_SAI2_BASE      (APB2PERIPH_BASE + 0x5C00)
#define TOFF_SAI_GCR        0x0000		/* (RW) SAI global configuration register */
  #define SAI_GCR_SYNCIN      0x00000003	/* SYNCIN[1:0] bits (Synchronization Inputs)   */
  #define SAI_GCR_SYNCIN_0    0x00000001	/* Bit 0 */
  #define SAI_GCR_SYNCIN_1    0x00000002	/* Bit 1 */
  #define SAI_GCR_SYNCOUT     0x00000030	/* SYNCOUT[1:0] bits (Synchronization Outputs) */
  #define SAI_GCR_SYNCOUT_0   0x00000010	/* Bit 0 */
  #define SAI_GCR_SYNCOUT_1   0x00000020	/* Bit 1 */
#define SAI_WINDOW_SIZE     0x0020
#define TOFF_SAI_CR1        0x0000		/* (RW) SAI block x configuration register 1 */
  #define SAI_xCR1_MODE       0x00000003	/* MODE[1:0] bits (Audio Block Mode) */
  #define SAI_xCR1_MODE_0     0x00000001	/* Bit 0 */
  #define SAI_xCR1_MODE_1     0x00000002	/* Bit 1 */
  #define SAI_xCR1_PRTCFG     0x0000000C	/* PRTCFG[1:0] bits (Protocol Configuration)   */
  #define SAI_xCR1_PRTCFG_0   0x00000004	/* Bit 0 */
  #define SAI_xCR1_PRTCFG_1   0x00000008	/* Bit 1 */
  #define SAI_xCR1_DS         0x000000E0	/* DS[1:0] bits (Data Size) */
  #define SAI_xCR1_DS_0       0x00000020	/* Bit 0 */
  #define SAI_xCR1_DS_1       0x00000040	/* Bit 1 */
  #define SAI_xCR1_DS_2       0x00000080	/* Bit 2 */
  #define SAI_xCR1_LSBFIRST   0x00000100	/* LSB First Configuration  */
  #define SAI_xCR1_CKSTR      0x00000200	/* ClocK STRobing edge      */
  #define SAI_xCR1_SYNCEN     0x00000C00	/* SYNCEN[1:0](SYNChronization ENable) */
  #define SAI_xCR1_SYNCEN_0   0x00000400	/* Bit 0 */
  #define SAI_xCR1_SYNCEN_1   0x00000800	/* Bit 1 */
  #define SAI_xCR1_MONO       0x00001000	/* Mono mode */
  #define SAI_xCR1_OUTDRIV    0x00002000	/* Output Drive */
  #define SAI_xCR1_SAIEN      0x00010000	/* Audio Block enable */
  #define SAI_xCR1_DMAEN      0x00020000	/* DMA enable */
  #define SAI_xCR1_NODIV      0x00080000	/* No Divider Configuration */
  #define SAI_xCR1_MCKDIV     0x00F00000	/* MCKDIV[3:0] (Master ClocK Divider)  */
  #define SAI_xCR1_MCKDIV_0   0x00100000	/* Bit 0  */
  #define SAI_xCR1_MCKDIV_1   0x00200000	/* Bit 1  */
  #define SAI_xCR1_MCKDIV_2   0x00400000	/* Bit 2  */
  #define SAI_xCR1_MCKDIV_3   0x00800000	/* Bit 3  */
#define TOFF_SAI_CR2        0x0004		/* (RW) SAI block x configuration register 2 */
  #define SAI_xCR2_FTH        0x00000007	/* FTH[2:0](Fifo THreshold)  */
  #define SAI_xCR2_FTH_0      0x00000001	/* Bit 0 */
  #define SAI_xCR2_FTH_1      0x00000002	/* Bit 1 */
  #define SAI_xCR2_FTH_2      0x00000004	/* Bit 2 */
  #define SAI_xCR2_FFLUSH     0x00000008	/* Fifo FLUSH */
  #define SAI_xCR2_TRIS       0x00000010	/* TRIState Management on data line */
  #define SAI_xCR2_MUTE       0x00000020	/* Mute mode */
  #define SAI_xCR2_MUTEVAL    0x00000040	/* Mute value */
  #define SAI_xCR2_MUTECNT    0x00001F80	/* MUTECNT[5:0] (MUTE counter) */
  #define SAI_xCR2_MUTECNT_0  0x00000080	/* Bit 0 */
  #define SAI_xCR2_MUTECNT_1  0x00000100	/* Bit 1 */
  #define SAI_xCR2_MUTECNT_2  0x00000200	/* Bit 2 */
  #define SAI_xCR2_MUTECNT_3  0x00000400	/* Bit 3 */
  #define SAI_xCR2_MUTECNT_4  0x00000800	/* Bit 4 */
  #define SAI_xCR2_MUTECNT_5  0x00001000	/* Bit 5 */
  #define SAI_xCR2_CPL        0x00080000	/* Complement Bit */
  #define SAI_xCR2_COMP       0x0000C000	/* COMP[1:0] (Companding mode) */
  #define SAI_xCR2_COMP_0     0x00004000	/* Bit 0 */
  #define SAI_xCR2_COMP_1     0x00008000	/* Bit 1 */
#define TOFF_SAI_FRCR       0x0008		/* (RW) SAI block x frame configuration register */
  #define SAI_xFRCR_FRL       0x000000FF	/* FRL[1:0](Frame length)  */
  #define SAI_xFRCR_FRL_0     0x00000001	/* Bit 0 */
  #define SAI_xFRCR_FRL_1     0x00000002	/* Bit 1 */
  #define SAI_xFRCR_FRL_2     0x00000004	/* Bit 2 */
  #define SAI_xFRCR_FRL_3     0x00000008	/* Bit 3 */
  #define SAI_xFRCR_FRL_4     0x00000010	/* Bit 4 */
  #define SAI_xFRCR_FRL_5     0x00000020	/* Bit 5 */
  #define SAI_xFRCR_FRL_6     0x00000040	/* Bit 6 */
  #define SAI_xFRCR_FRL_7     0x00000080	/* Bit 7 */
  #define SAI_xFRCR_FSALL     0x00007F00	/* FRL[1:0] (Frame synchronization active level length)  */
  #define SAI_xFRCR_FSALL_0   0x00000100	/* Bit 0 */
  #define SAI_xFRCR_FSALL_1   0x00000200	/* Bit 1 */
  #define SAI_xFRCR_FSALL_2   0x00000400	/* Bit 2 */
  #define SAI_xFRCR_FSALL_3   0x00000800	/* Bit 3 */
  #define SAI_xFRCR_FSALL_4   0x00001000	/* Bit 4 */
  #define SAI_xFRCR_FSALL_5   0x00002000	/* Bit 5 */
  #define SAI_xFRCR_FSALL_6   0x00004000	/* Bit 6 */
  #define SAI_xFRCR_FSDEF     0x00010000	/* Frame Synchronization Definition */
  #define SAI_xFRCR_FSPO      0x00020000	/* Frame Synchronization POLarity */
  #define SAI_xFRCR_FSOFF     0x00040000	/* Frame Synchronization OFFset*/
#define TOFF_SAI_SLOTR      0x000C		/* (RW) SAI block x slot register */
  #define SAI_xSLOTR_FBOFF    0x0000001F	/* FRL[4:0](First Bit Offset)  */
  #define SAI_xSLOTR_FBOFF_0  0x00000001	/* Bit 0 */
  #define SAI_xSLOTR_FBOFF_1  0x00000002	/* Bit 1 */
  #define SAI_xSLOTR_FBOFF_2  0x00000004	/* Bit 2 */
  #define SAI_xSLOTR_FBOFF_3  0x00000008	/* Bit 3 */
  #define SAI_xSLOTR_FBOFF_4  0x00000010	/* Bit 4 */
  #define SAI_xSLOTR_SLOTSZ   0x000000C0	/* SLOTSZ[1:0] (Slot size)  */
  #define SAI_xSLOTR_SLOTSZ_0 0x00000040	/* Bit 0 */
  #define SAI_xSLOTR_SLOTSZ_1 0x00000080	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT   0x00000F00	/* NBSLOT[3:0] (Number of Slot in audio Frame)  */
  #define SAI_xSLOTR_NBSLOT_0 0x00000100	/* Bit 0 */
  #define SAI_xSLOTR_NBSLOT_1 0x00000200	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT_2 0x00000400	/* Bit 2 */
  #define SAI_xSLOTR_NBSLOT_3 0x00000800	/* Bit 3 */
  #define SAI_xSLOTR_SLOTEN   0xFFFF0000	/* SLOTEN[15:0] (Slot Enable)  */
#define TOFF_SAI_IMR        0x0010		/* (RW) SAI block x interrupt mask register */
  #define SAI_xIMR_OVRUDRIE   0x00000001	/* Overrun underrun interrupt enable                              */
  #define SAI_xIMR_MUTEDETIE  0x00000002	/* Mute detection interrupt enable                                */
  #define SAI_xIMR_WCKCFGIE   0x00000004	/* Wrong Clock Configuration interrupt enable                     */
  #define SAI_xIMR_FREQIE     0x00000008	/* FIFO request interrupt enable                                  */
  #define SAI_xIMR_CNRDYIE    0x00000010	/* Codec not ready interrupt enable                               */
  #define SAI_xIMR_AFSDETIE   0x00000020	/* Anticipated frame synchronization detection interrupt enable   */
  #define SAI_xIMR_LFSDETIE   0x00000040	/* Late frame synchronization detection interrupt enable          */
#define TOFF_SAI_SR         0x0014		/* (RW) SAI block x status register */
  #define SAI_xSR_OVRUDR      0x00000001	/* Overrun underrun */
  #define SAI_xSR_MUTEDET     0x00000002	/* Mute detection */
  #define SAI_xSR_WCKCFG      0x00000004	/* Wrong Clock Configuration */
  #define SAI_xSR_FREQ        0x00000008	/* FIFO request */
  #define SAI_xSR_CNRDY       0x00000010	/* Codec not ready */
  #define SAI_xSR_AFSDET      0x00000020	/* Anticipated frame synchronization detection */
  #define SAI_xSR_LFSDET      0x00000040	/* Late frame synchronization detection */
  #define SAI_xSR_FLVL        0x00070000	/* FLVL[2:0] (FIFO Level Threshold) */
  #define SAI_xSR_FLVL_0      0x00010000	/* Bit 0 */
  #define SAI_xSR_FLVL_1      0x00020000	/* Bit 1 */
  #define SAI_xSR_FLVL_2      0x00040000	/* Bit 2 */
#define TOFF_SAI_CLRFR      0x0018		/* (RW) SAI block x clear flag register */
#define TOFF_SAI_DR         0x001C		/* (RW) SAI block x data register */


/*
 *  LCD-TFT DISPLAY CONTROLLER
 */
#define TADR_LTDC_BASE      (APB2PERIPH_BASE + 0x6800)
#define TADR_LTDC_LAYER1    (TADR_LTDC_BASE + 0x84)
#define TADR_LTDC_LAYER2    (TADR_LTDC_BASE + 0x104)
#define TOFF_LTDC_SSCR      0x0008		/* (RW) LTDC Synchronization Size Configuration Register */
  #define LTDC_SSCR_VSH      0x000007FF	/* Vertical Synchronization Height  */
  #define LTDC_SSCR_HSW      0x0FFF0000	/* Horizontal Synchronization Width */
#define TOFF_LTDC_BPCR      0x000C		/* (RW) LTDC Back Porch Configuration Register */
  #define LTDC_BPCR_AVBP     0x000007FF	/* Accumulated Vertical Back Porch   */
  #define LTDC_BPCR_AHBP     0x0FFF0000	/* Accumulated Horizontal Back Porch */
#define TOFF_LTDC_AWCR      0x0010		/* (RW) LTDC Active Width Configuration Register */
  #define LTDC_AWCR_AAH      0x000007FF	/* Accumulated Active heigh */
  #define LTDC_AWCR_AAW      0x0FFF0000	/* Accumulated Active Width */
#define TOFF_LTDC_TWCR      0x0014		/* (RW) LTDC Total Width Configuration Register */
  #define LTDC_TWCR_TOTALH   0x000007FF	/* Total Heigh */
  #define LTDC_TWCR_TOTALW   0x0FFF0000	/* Total Width */
#define TOFF_LTDC_GCR       0x0018		/* (RW) LTDC Global Control Register */
  #define LTDC_GCR_LTDCEN    0x00000001	/* LCD-TFT controller enable bit */
  #define LTDC_GCR_DBW       0x00000070	/* Dither Blue Width */
  #define LTDC_GCR_DGW       0x00000700	/* Dither Green Width */
  #define LTDC_GCR_DRW       0x00007000	/* Dither Red Width */
  #define LTDC_GCR_DTEN      0x00010000	/* Dither Enable */
  #define LTDC_GCR_PCPOL     0x10000000	/* Pixel Clock Polarity */
  #define LTDC_GCR_DEPOL     0x20000000	/* Data Enable Polarity */
  #define LTDC_GCR_VSPOL     0x40000000	/* Vertical Synchronization Polarity */
  #define LTDC_GCR_HSPOL     0x80000000	/* Horizontal Synchronization Polarity */
#define TOFF_LTDC_SRCR      0x0024		/* (RW) LTDC Shadow Reload Configuration Register */
  #define LTDC_SRCR_IMR      0x00000001	/* Immediate Reload */
  #define LTDC_SRCR_VBR      0x00000002	/* Vertical Blanking Reload */
#define TOFF_LTDC_BCCR      0x002C		/* (RW) LTDC Background Color Configuration Register */
  #define LTDC_BCCR_BCBLUE   0x000000FF	/* Background Blue value  */
  #define LTDC_BCCR_BCGREEN  0x0000FF00	/* Background Green value */
  #define LTDC_BCCR_BCRED    0x00FF0000	/* Background Red value   */
#define TOFF_LTDC_IER       0x0034		/* (RW) LTDC Interrupt Enable Register */
  #define LTDC_IER_LIE       0x00000001	/* Line Interrupt Enable            */
  #define LTDC_IER_FUIE      0x00000002	/* FIFO Underrun Interrupt Enable   */
  #define LTDC_IER_TERRIE    0x00000004	/* Transfer Error Interrupt Enable  */
  #define LTDC_IER_RRIE      0x00000008	/* Register Reload interrupt enable */
#define TOFF_LTDC_ISR       0x0038		/* (RW) LTDC Interrupt Status Register */
  #define LTDC_ISR_LIF       0x00000001	/* Line Interrupt Flag */
  #define LTDC_ISR_FUIF      0x00000002	/* FIFO Underrun Interrupt Flag */
  #define LTDC_ISR_TERRIF    0x00000004	/* Transfer Error Interrupt Flag */
  #define LTDC_ISR_RRIF      0x00000008	/* Register Reload interrupt Flag */
#define TOFF_LTDC_ICR       0x003C		/* (RW) LTDC Interrupt Clear Register */
  #define LTDC_ICR_CLIF      0x00000001	/* Clears the Line Interrupt Flag */
  #define LTDC_ICR_CFUIF     0x00000002	/* Clears the FIFO Underrun Interrupt Flag */
  #define LTDC_ICR_CTERRIF   0x00000004	/* Clears the Transfer Error Interrupt Flag */
  #define LTDC_ICR_CRRIF     0x00000008	/* Clears Register Reload interrupt Flag */
#define TOFF_LTDC_LIPCR     0x0040		/* (RW) LTDC Line Interrupt Position Configuration Register */
#define TOFF_LTDC_CPSR      0x0044		/* (RW) LTDC Current Position Status Register */
#define TOFF_LTDC_CDSR      0x0048		/* (RW) LTDC Current Display Status Register */

/*
 *  LCD-TFT DISPLAY LAYER X CONTROLLER (WINDOW)
 */
#define LTDC_WINDOW_SIZE    128
#define TOFF_LTDCW_CR       0x0000		/* (RW) LTDC Layerx Control Register :0x84 */
  #define LTDC_CR_LEN        0x00000001	/* Layer Enable              */
  #define LTDC_CR_COLKEN     0x00000002	/* Color Keying Enable       */
  #define LTDC_CR_CLUTEN     0x00000010	/* Color Lockup Table Enable */
#define TOFF_LTDCW_WHPCR    0x0004		/* (RW) LTDC Layerx Window Horizontal :0x88 */
  #define LTDC_WHPCR_WHSTPOS 0x00000FFF	/* Window Horizontal Start Position */
  #define LTDC_WHPCR_WHSPPOS 0xFFFF0000	/* Window Horizontal Stop Position  */
#define TOFF_LTDCW_WVPCR    0x0008		/* (RW) LTDC Layerx Window Vertical Position Configuration Register :0x8C */
  #define LTDC_WVPCR_WVSTPOS 0x00000FFF	/* Window Vertical Start Position */
  #define LTDC_WVPCR_WVSPPOS 0xFFFF0000	/* Window Vertical Stop Position  */
#define TOFF_LTDCW_CKCR     0x000C		/* (RW) LTDC Layerx Color Keying Configuration Register :0x90 */
  #define LTDC_CKCR_CKBLUE   0x000000FF	/* Color Key Blue value  */
  #define LTDC_CKCR_CKGREEN  0x0000FF00	/* Color Key Green value */
  #define LTDC_CKCR_CKRED    0x00FF0000	/* Color Key Red value   */
#define TOFF_LTDCW_PFCR     0x0010		/* (RW) LTDC Layerx Pixel Format Configuration Register :0x94 */
  #define LTDC_PFCR_PF       0x00000007	/* Pixel Format */
#define TOFF_LTDCW_CACR     0x0014		/* (RW) LTDC Layerx Constant Alpha Configuration Register :0x98 */
  #define LTDC_CACR_CONSTA   0x000000FF	/* Constant Alpha */
#define TOFF_LTDCW_DCCR     0x0018		/* (RW) LTDC Layerx Default Color Configuration Register :0x9C */
  #define LTDC_DCCR_DCBLUE   0x000000FF	/* Default Color Blue  */
  #define LTDC_DCCR_DCGREEN  0x0000FF00	/* Default Color Green */
  #define LTDC_DCCR_DCRED    0x00FF0000	/* Default Color Red   */
  #define LTDC_DCCR_DCALPHA  0xFF000000	/* Default Color Alpha */
#define TOFF_LTDCW_BFCR     0x001C		/* (RW) LTDC Layerx Blending Factors Configuration Register :0xA0 */
  #define LTDC_BFCR_BF2      0x00000007	/* Blending Factor 2 */
  #define LTDC_BFCR_BF1      0x00000700	/* Blending Factor 1 */
#define TOFF_LTDCW_CFBAR    0x0028		/* (RW) LTDC Layerx Color Frame Buffer Address Register :0xAC */
  #define LTDC_CFBAR_CFBADD  0xFFFFFFFF	/* Color Frame Buffer Start Address */
#define TOFF_LTDCW_CFBLR    0x002C		/* (RW) LTDC Layerx Color Frame Buffer Length Register :0xB0 */
  #define LTDC_CFBLR_CFBLL   0x00001FFF	/* Color Frame Buffer Line Length    */
  #define LTDC_CFBLR_CFBP    0x1FFF0000	/* Color Frame Buffer Pitch in bytes */
#define TOFF_LTDCW_CFBLNR   0x0030		/* (RW) LTDC Layerx ColorFrame Buffer Line Number Register :0xB4 */
  #define LTDC_CFBLNR_CFBLNBR 0x000007FF	/* Frame Buffer Line Number */
#define TOFF_LTDCW_CLUTWR   0x003C		/* (RW) LTDC Layerx CLUT Write Register :0xC0 */


/*
 *  DCMI
 */
#define TADR_DCMI_BASE      (AHB2PERIPH_BASE + 0x50000)
#define TOFF_DCMI_CR        0x0000		/* (RW) DCMI control register 1 */
#define TOFF_DCMI_SR        0x0004		/* (R)  DCMI status register */
#define TOFF_DCMI_RISR      0x0008		/* (R)  DCMI raw interrupt status register */
#define TOFF_DCMI_IER       0x000C		/* (RW) DCMI interrupt enable register */
#define TOFF_DCMI_MISR      0x0010		/* (RW) DCMI masked interrupt status register */
#define TOFF_DCMI_ICR       0x0014		/* (RW) DCMI interrupt clear register */
#define TOFF_DCMI_ESCR      0x0018		/* (RW) DCMI embedded synchronization code register */
#define TOFF_DCMI_ESUR      0x001C		/* (RW) DCMI embedded synchronization unmask register */
#define TOFF_DCMI_CWSTRTR   0x0020		/* (RW) DCMI crop window start */
#define TOFF_DCMI_CWSIZER   0x0024		/* (RW) DCMI crop window size */
#define TOFF_DCMI_DR        0x0028		/* (RW) DCMI data register */

/*
 *  CRYPTO PROCESSER
 */
#define TADR_CRYP_BASE      (AHB2PERIPH_BASE + 0x60000)
#define TOFF_CRYP_CR        0x0000		/* (RW) CRYP control register */
#define TOFF_CRYP_SR        0x0004		/* (R)  CRYP status register */
#define TOFF_CRYP_DR        0x0008		/* (RW) CRYP data input register */
#define TOFF_CRYP_DOUT      0x000C		/* (RW) CRYP data output register */
#define TOFF_CRYP_DMACR     0x0010		/* (RW) CRYP DMA control register */
#define TOFF_CRYP_IMSCR     0x0014		/* (RW) CRYP interrupt mask set/clear register */
#define TOFF_CRYP_RISR      0x0018		/* (RW) CRYP raw interrupt status register */
#define TOFF_CRYP_MISR      0x001C		/* (RW) CRYP masked interrupt status register */
#define TOFF_CRYP_K0LR      0x0020		/* (RW) CRYP key left  register 0 */
#define TOFF_CRYP_K0RR      0x0024		/* (RW) CRYP key right register 0 */
#define TOFF_CRYP_K1LR      0x0028		/* (RW) CRYP key left  register 1 */
#define TOFF_CRYP_K1RR      0x002C		/* (RW) CRYP key right register 1 */
#define TOFF_CRYP_K2LR      0x0030		/* (RW) CRYP key left  register 2 */
#define TOFF_CRYP_K2RR      0x0034		/* (RW) CRYP key right register 2 */
#define TOFF_CRYP_K3LR      0x0038		/* (RW) CRYP key left  register 3 */
#define TOFF_CRYP_K3RR      0x003C		/* (RW) CRYP key right register 3 */
#define TOFF_CRYP_IV0LR     0x0040		/* (RW) CRYP initialization vector left-word  register 0 */
#define TOFF_CRYP_IV0RR     0x0044		/* (RW) CRYP initialization vector right-word register 0 */
#define TOFF_CRYP_IV1LR     0x0048		/* (RW) CRYP initialization vector left-word  register 1 */
#define TOFF_CRYP_IV1RR     0x004C		/* (RW) CRYP initialization vector right-word register 1 */
#define TOFF_CSGCMCCM0R     0x0050		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 0 */
#define TOFF_CSGCMCCM1R     0x0054		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 1 */
#define TOFF_CSGCMCCM2R     0x0058		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 2 */
#define TOFF_CSGCMCCM3R     0x005C		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 3 */
#define TOFF_CSGCMCCM4R     0x0060		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 4 */
#define TOFF_CSGCMCCM5R     0x0064		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 5 */
#define TOFF_CSGCMCCM6R     0x0068		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 6 */
#define TOFF_CSGCMCCM7R     0x006C		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 7 */
#define TOFF_CSGCM0R        0x0070		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM1R        0x0074		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM2R        0x0078		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM3R        0x007C		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM4R        0x0080		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM5R        0x0084		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM6R        0x0088		/* (RW) CRYP GCM/GMAC context swap register */
#define TOFF_CSGCM7R        0x008C		/* (RW) CRYP GCM/GMAC context swap register */

/*
 *  HASH
 */
#define TADR_HASH_BASE      (AHB2PERIPH_BASE + 0x60400)
#define TOFF_HASH_CR        0x0000		/* (RW) HASH control register */
#define TOFF_HASH_DIN       0x0004		/* (RW) HASH data input register */
#define TOFF_HASH_STR       0x0008		/* (RW) HASH start register */
#define TOFF_HASH_HR0       0x000C		/* (RW) HASH digest registers 0 */
#define TOFF_HASH_HR1       0x0010		/* (RW) HASH digest registers 1 */
#define TOFF_HASH_HR2       0x0014		/* (RW) HASH digest registers 2 */
#define TOFF_HASH_HR3       0x0018		/* (RW) HASH digest registers 3 */
#define TOFF_HASH_HR4       0x001C		/* (RW) HASH digest registers 4 */
#define TOFF_HASH_IMR       0x0020		/* (RW) HASH interrupt enable register */
#define TOFF_HASH_SR        0x0024		/* (R)  HASH status register */
#define TOFF_HASH_CSR0      0x00F8		/* (RW) HASH context swap registers 0 */
#define TOFF_HASH_CSR1      0x00FC		/* (RW) HASH context swap registers 1 */
#define TOFF_HASH_CSR2      0x0100		/* (RW) HASH context swap registers 2 */
#define TOFF_HASH_CSR3      0x0104		/* (RW) HASH context swap registers 3 */
#define TOFF_HASH_CSR4      0x0108		/* (RW) HASH context swap registers 4 */
#define TOFF_HASH_CSR5      0x010C		/* (RW) HASH context swap registers 5 */
#define TOFF_HASH_CSR6      0x0110		/* (RW) HASH context swap registers 6 */
#define TOFF_HASH_CSR7      0x0114		/* (RW) HASH context swap registers 7 */
#define TOFF_HASH_CSR8      0x0118		/* (RW) HASH context swap registers 8 */
#define TOFF_HASH_CSR9      0x011C		/* (RW) HASH context swap registers 9 */
#define TOFF_HASH_CSR10     0x0120		/* (RW) HASH context swap registers 10 */
#define TOFF_HASH_CSR11     0x0124		/* (RW) HASH context swap registers 11 */
#define TOFF_HASH_CSR12     0x0128		/* (RW) HASH context swap registers 12 */
#define TOFF_HASH_CSR13     0x012C		/* (RW) HASH context swap registers 13 */
#define TOFF_HASH_CSR14     0x0130		/* (RW) HASH context swap registers 14 */
#define TOFF_HASH_CSR15     0x0134		/* (RW) HASH context swap registers 15 */
#define TOFF_HASH_CSR16     0x0138		/* (RW) HASH context swap registers 16 */
#define TOFF_HASH_CSR17     0x013C		/* (RW) HASH context swap registers 17 */
#define TOFF_HASH_CSR18     0x0140		/* (RW) HASH context swap registers 18 */
#define TOFF_HASH_CSR19     0x0144		/* (RW) HASH context swap registers 19 */
#define TOFF_HASH_CSR20     0x0148		/* (RW) HASH context swap registers 20 */
#define TOFF_HASH_CSR21     0x014C		/* (RW) HASH context swap registers 21 */
#define TOFF_HASH_CSR22     0x0150		/* (RW) HASH context swap registers 22 */
#define TOFF_HASH_CSR23     0x0154		/* (RW) HASH context swap registers 23 */
#define TOFF_HASH_CSR24     0x0158		/* (RW) HASH context swap registers 24 */
#define TOFF_HASH_CSR25     0x015C		/* (RW) HASH context swap registers 25 */
#define TOFF_HASH_CSR26     0x0160		/* (RW) HASH context swap registers 26 */
#define TOFF_HASH_CSR27     0x0164		/* (RW) HASH context swap registers 27 */
#define TOFF_HASH_CSR28     0x0168		/* (RW) HASH context swap registers 28 */
#define TOFF_HASH_CSR29     0x016C		/* (RW) HASH context swap registers 29 */
#define TOFF_HASH_CSR30     0x0170		/* (RW) HASH context swap registers 30 */
#define TOFF_HASH_CSR31     0x0174		/* (RW) HASH context swap registers 31 */
#define TOFF_HASH_CSR32     0x0178		/* (RW) HASH context swap registers 32 */
#define TOFF_HASH_CSR33     0x017C		/* (RW) HASH context swap registers 33 */
#define TOFF_HASH_CSR34     0x0180		/* (RW) HASH context swap registers 34 */
#define TOFF_HASH_CSR35     0x0184		/* (RW) HASH context swap registers 35 */
#define TOFF_HASH_CSR36     0x0188		/* (RW) HASH context swap registers 36 */
#define TOFF_HASH_CSR37     0x018C		/* (RW) HASH context swap registers 37 */
#define TOFF_HASH_CSR38     0x0190		/* (RW) HASH context swap registers 38 */
#define TOFF_HASH_CSR39     0x0194		/* (RW) HASH context swap registers 39 */
#define TOFF_HASH_CSR40     0x0198		/* (RW) HASH context swap registers 40 */
#define TOFF_HASH_CSR41     0x019C		/* (RW) HASH context swap registers 41 */
#define TOFF_HASH_CSR42     0x01A0		/* (RW) HASH context swap registers 42 */
#define TOFF_HASH_CSR43     0x01A4		/* (RW) HASH context swap registers 43 */
#define TOFF_HASH_CSR44     0x01A8		/* (RW) HASH context swap registers 44 */
#define TOFF_HASH_CSR45     0x01AC		/* (RW) HASH context swap registers 45 */
#define TOFF_HASH_CSR46     0x01B0		/* (RW) HASH context swap registers 46 */
#define TOFF_HASH_CSR47     0x01B4		/* (RW) HASH context swap registers 47 */
#define TOFF_HASH_CSR48     0x01B8		/* (RW) HASH context swap registers 48 */
#define TOFF_HASH_CSR49     0x01BC		/* (RW) HASH context swap registers 49 */
#define TOFF_HASH_CSR50     0x01C0		/* (RW) HASH context swap registers 50 */

/*
 *  HASH DIGEST
 */
#define TADR_HASHDIGEST_BASE (AHB2PERIPH_BASE + 0x60710)
#define TOFF_HASHDIGEST_HR0 0x0000		/* (RW) HASH digest registers, Address offset: 0x310-0x32C */

/*
 *  RNG
 */
#define TADR_RNG_BASE       (AHB2PERIPH_BASE + 0x60800)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */

/*
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FMC_R_BASE    (FMC_R_BASE + 0x0000)

/*
 *  FLEXIBLE MEMORY CONTROLLER
 */
#define TOFF_FMC_R_BTCR0    0x0000		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 0 */
  #define FMC_BCR1_MBKEN     0x00000001	/* Memory bank enable bit */
  #define FMC_BCR1_MUXEN     0x00000002	/* Address/data multiplexing enable bit */
  #define FMC_BCR1_MTYP      0x0000000C	/* MTYP[1:0] bits (Memory type) */
  #define FMC_BCR1_MTYP_0    0x00000004
  #define FMC_BCR1_MTYP_1    0x00000008
  #define FMC_BCR1_MWID      0x00000030	/* MWID[1:0] bits (Memory data bus width) */
  #define FMC_BCR1_MWID_0    0x00000010
  #define FMC_BCR1_MWID_1    0x00000020
  #define FMC_BCR1_FACCEN    0x00000040	/* Flash access enable */
  #define FMC_BCR1_BURSTEN   0x00000100	/* Burst enable bit */
  #define FMC_BCR1_WAITPOL   0x00000200	/* Wait signal polarity bit */
  #define FMC_BCR1_WRAPMOD   0x00000400	/* Wrapped burst mode support */
  #define FMC_BCR1_WAITCFG   0x00000800	/* Wait timing configuration */
  #define FMC_BCR1_WREN      0x00001000	/* Write enable bit */
  #define FMC_BCR1_WAITEN    0x00002000	/* Wait enable bit */
  #define FMC_BCR1_EXTMOD    0x00004000	/* Extended mode enable */
  #define FMC_BCR1_ASYNCWAIT 0x00008000	/* Asynchronous wait */
  #define FMC_BCR1_CPSIZE    0x00070000	/* CRAM page size */
  #define FMC_BCR1_CPSIZE_0  0x00010000
  #define FMC_BCR1_CPSIZE_1  0x00020000
  #define FMC_BCR1_CPSIZE_2  0x00040000
  #define FMC_BCR1_CBURSTRW  0x00080000	/* Write burst enable */
  #define FMC_BCR1_CCLKEN    0x00100000	/* Continous clock enable */
  #define FMC_BCR1_WFDIS     0x00200000	/* Write FIFO Disable */
#define TOFF_FMC_R_BTCR1    0x0004		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 1 */
  #define FMC_BTR1_ADDSET    0x0000000F	/* ADDSET[3:0] bits (Address setup phase duration) */
  #define FMC_BTR1_ADDSET_0  0x00000001
  #define FMC_BTR1_ADDSET_1  0x00000002
  #define FMC_BTR1_ADDSET_2  0x00000004
  #define FMC_BTR1_ADDSET_3  0x00000008
  #define FMC_BTR1_ADDHLD    0x000000F0	/* ADDHLD[3:0] bits (Address-hold phase duration) */
  #define FMC_BTR1_ADDHLD_0  0x00000010
  #define FMC_BTR1_ADDHLD_1  0x00000020
  #define FMC_BTR1_ADDHLD_2  0x00000040
  #define FMC_BTR1_ADDHLD_3  0x00000080
  #define FMC_BTR1_DATAST    0x0000FF00/* DATAST [3:0] bits (Data-phase duration) */
  #define FMC_BTR1_DATAST_0  0x00000100
  #define FMC_BTR1_DATAST_1  0x00000200
  #define FMC_BTR1_DATAST_2  0x00000400
  #define FMC_BTR1_DATAST_3  0x00000800
  #define FMC_BTR1_DATAST_4  0x00001000
  #define FMC_BTR1_DATAST_5  0x00002000
  #define FMC_BTR1_DATAST_6  0x00004000
  #define FMC_BTR1_DATAST_7  0x00008000
  #define FMC_BTR1_BUSTURN   0x000F0000	/* BUSTURN[3:0] bits (Bus turnaround phase duration) */
  #define FMC_BTR1_BUSTURN_0 0x00010000
  #define FMC_BTR1_BUSTURN_1 0x00020000
  #define FMC_BTR1_BUSTURN_2 0x00040000
  #define FMC_BTR1_BUSTURN_3 0x00080000
  #define FMC_BTR1_CLKDIV    0x00F00000	/* CLKDIV[3:0] bits (Clock divide ratio) */
  #define FMC_BTR1_CLKDIV_0  0x00100000
  #define FMC_BTR1_CLKDIV_1  0x00200000
  #define FMC_BTR1_CLKDIV_2  0x00400000
  #define FMC_BTR1_CLKDIV_3  0x00800000
  #define FMC_BTR1_DATLAT    0x0F000000	/* DATLA[3:0] bits (Data latency) */
  #define FMC_BTR1_DATLAT_0  0x01000000
  #define FMC_BTR1_DATLAT_1  0x02000000
  #define FMC_BTR1_DATLAT_2  0x04000000
  #define FMC_BTR1_DATLAT_3  0x08000000
  #define FMC_BTR1_ACCMOD    0x30000000	/* ACCMOD[1:0] bits (Access mode) */
  #define FMC_BTR1_ACCMOD_0  0x10000000
  #define FMC_BTR1_ACCMOD_1  0x20000000
#define TOFF_FMC_R_BTCR2    0x0008		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 2 */
#define TOFF_FMC_R_BTCR3    0x000C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 3 */
#define TOFF_FMC_R_BTCR4    0x0010		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 4 */
#define TOFF_FMC_R_BTCR5    0x0014		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 5 */
#define TOFF_FMC_R_BTCR6    0x0018		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 6 */
#define TOFF_FMC_R_BTCR7    0x001C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 7 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK1E
 */
#define TOFF_FMC_R_BWTR0    0x0104		/* (RW) NOR/PSRAM write timing registers 0 */
#define TOFF_FMC_R_BWTR1    0x0108		/* (RW) NOR/PSRAM write timing registers 1 */
#define TOFF_FMC_R_BWTR2    0x010C		/* (RW) NOR/PSRAM write timing registers 2 */
#define TOFF_FMC_R_BWTR3    0x0110		/* (RW) NOR/PSRAM write timing registers 3 */
#define TOFF_FMC_R_BWTR4    0x0114		/* (RW) NOR/PSRAM write timing registers 4 */
#define TOFF_FMC_R_BWTR5    0x0118		/* (RW) NOR/PSRAM write timing registers 5 */
#define TOFF_FMC_R_BWTR6    0x011C		/* (RW) NOR/PSRAM write timing registers 6 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK3
 */
#define TOFF_FMC_R_PCR      0x0080		/* (RW) NAND Flash control register */
#define TOFF_FMC_R_SR       0x0084		/* (RW) NAND Flash FIFO status and interrupt register */
#define TOFF_FMC_R_PMEM     0x0088		/* (RW) NAND Flash Common memory space timing register */
#define TOFF_FMC_R_PATT     0x008C		/* (RW) NAND Flash Attribute memory space timing register */
#define TOFF_FMC_R_ECCR     0x0090		/* (RW) NAND Flash ECC result registers */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK5 6
 */
#define TOFF_FMC_R_SDCR0    0x0140		/* (RW) SDRAM Control registers 0 */
#define TOFF_FMC_R_SDCR1    0x0144		/* (RW) SDRAM Control registers 1 */
  #define FMC_SDCR1_NC       0x00000003	/* NC[1:0] bits (Number of column bits) */
  #define FMC_SDCR1_NC_0     0x00000001	/* Bit 0 */
  #define FMC_SDCR1_NC_1     0x00000002	/* Bit 1 */
  #define FMC_SDCR1_NR       0x0000000C	/* NR[1:0] bits (Number of row bits) */
  #define FMC_SDCR1_NR_0     0x00000004	/* Bit 0 */
  #define FMC_SDCR1_NR_1     0x00000008	/* Bit 1 */
  #define FMC_SDCR1_MWID     0x00000030	/* NR[1:0] bits (Number of row bits) */
  #define FMC_SDCR1_MWID_0   0x00000010	/* Bit 0 */
  #define FMC_SDCR1_MWID_1   0x00000020	/* Bit 1 */
  #define FMC_SDCR1_NB       0x00000040	/* Number of internal bank */
  #define FMC_SDCR1_CAS      0x00000180	/* CAS[1:0] bits (CAS latency) */
  #define FMC_SDCR1_CAS_0    0x00000080	/* Bit 0 */
  #define FMC_SDCR1_CAS_1    0x00000100	/* Bit 1 */
  #define FMC_SDCR1_WP       0x00000200	/* Write protection */
  #define FMC_SDCR1_SDCLK    0x00000C00	/* SDRAM clock configuration */
  #define FMC_SDCR1_SDCLK_0  0x00000400	/* Bit 0 */
  #define FMC_SDCR1_SDCLK_1  0x00000800	/* Bit 1 */
  #define FMC_SDCR1_RBURST   0x00001000	/* Read burst */
  #define FMC_SDCR1_RPIPE    0x00006000	/* Write protection */
  #define FMC_SDCR1_RPIPE_0  0x00002000	/* Bit 0 */
  #define FMC_SDCR1_RPIPE_1  0x00004000	/* Bit 1 */
#define TOFF_FMC_R_SDTR0    0x0148		/* (RW) SDRAM Timing registers 0 */
#define TOFF_FMC_R_SDTR1    0x014C		/* (RW) SDRAM Timing registers 1 */
  #define FMC_SDTR1_TMRD     0x0000000F	/* TMRD[3:0] bits (Load mode register to active) */
  #define FMC_SDTR1_TMRD_0   0x00000001	/* Bit 0 */
  #define FMC_SDTR1_TMRD_1   0x00000002	/* Bit 1 */
  #define FMC_SDTR1_TMRD_2   0x00000004	/* Bit 2 */
  #define FMC_SDTR1_TMRD_3   0x00000008	/* Bit 3 */
  #define FMC_SDTR1_TXSR     0x000000F0	/* TXSR[3:0] bits (Exit self refresh) */
  #define FMC_SDTR1_TXSR_0   0x00000010	/* Bit 0 */
  #define FMC_SDTR1_TXSR_1   0x00000020	/* Bit 1 */
  #define FMC_SDTR1_TXSR_2   0x00000040	/* Bit 2 */
  #define FMC_SDTR1_TXSR_3   0x00000080	/* Bit 3 */
  #define FMC_SDTR1_TRAS     0x00000F00	/* TRAS[3:0] bits (Self refresh time) */
  #define FMC_SDTR1_TRAS_0   0x00000100	/* Bit 0 */
  #define FMC_SDTR1_TRAS_1   0x00000200	/* Bit 1 */
  #define FMC_SDTR1_TRAS_2   0x00000400	/* Bit 2 */
  #define FMC_SDTR1_TRAS_3   0x00000800	/* Bit 3 */
  #define FMC_SDTR1_TRC      0x0000F000	/* TRC[2:0] bits (Row cycle delay) */
  #define FMC_SDTR1_TRC_0    0x00001000	/* Bit 0 */
  #define FMC_SDTR1_TRC_1    0x00002000	/* Bit 1 */
  #define FMC_SDTR1_TRC_2    0x00004000	/* Bit 2 */
  #define FMC_SDTR1_TWR      0x000F0000	/* TRC[2:0] bits (Write recovery delay) */
  #define FMC_SDTR1_TWR_0    0x00010000	/* Bit 0 */
  #define FMC_SDTR1_TWR_1    0x00020000	/* Bit 1 */
  #define FMC_SDTR1_TWR_2    0x00040000	/* Bit 2 */
  #define FMC_SDTR1_TRP      0x00F00000	/* TRP[2:0] bits (Row precharge delay) */
  #define FMC_SDTR1_TRP_0    0x00100000	/* Bit 0 */
  #define FMC_SDTR1_TRP_1    0x00200000	/* Bit 1 */
  #define FMC_SDTR1_TRP_2    0x00400000	/* Bit 2 */
  #define FMC_SDTR1_TRCD     0x0F000000	/* TRP[2:0] bits (Row to column delay) */
  #define FMC_SDTR1_TRCD_0   0x01000000	/* Bit 0 */
  #define FMC_SDTR1_TRCD_1   0x02000000	/* Bit 1 */
  #define FMC_SDTR1_TRCD_2   0x04000000	/* Bit 2 */
#define TOFF_FMC_R_SDCMR    0x0150		/* (RW) SDRAM Command Mode register */
  #define FMC_SDCMR_MODE     0x00000007	/* MODE[2:0] bits (Command mode) */
  #define FMC_SDCMR_MODE_0   0x00000001	/* Bit 0 */
  #define FMC_SDCMR_MODE_1   0x00000002	/* Bit 1 */
  #define FMC_SDCMR_MODE_2   0x00000003	/* Bit 2 */
  #define FMC_SDCMR_CTB2     0x00000008	/* Command target 2 */
  #define FMC_SDCMR_CTB1     0x00000010	/* Command target 1 */
  #define FMC_SDCMR_NRFS     0x000001E0	/* NRFS[3:0] bits (Number of auto-refresh) */
  #define FMC_SDCMR_NRFS_0   0x00000020	/* Bit 0 */
  #define FMC_SDCMR_NRFS_1   0x00000040	/* Bit 1 */
  #define FMC_SDCMR_NRFS_2   0x00000080	/* Bit 2 */
  #define FMC_SDCMR_NRFS_3   0x00000100	/* Bit 3 */
  #define FMC_SDCMR_MRD      0x003FFE00	/* MRD[12:0] bits (Mode register definition) */
#define TOFF_FMC_R_SDRTR    0x0154		/* (RW) SDRAM Refresh Timer register */
#define TOFF_FMC_R_SDSR     0x0158		/* (RW) SDRAM Status register */
  #define FMC_SDSR_RE        0x00000001	/* Refresh error flag */
  #define FMC_SDSR_MODES1    0x00000006	/* MODES1[1:0]bits (Status mode for bank 1) */
  #define FMC_SDSR_MODES1_0  0x00000002	/* Bit 0 */
  #define FMC_SDSR_MODES1_1  0x00000004	/* Bit 1 */
  #define FMC_SDSR_MODES2    0x00000018	/* MODES2[1:0]bits (Status mode for bank 2) */
  #define FMC_SDSR_MODES2_0  0x00000008	/* Bit 0 */
  #define FMC_SDSR_MODES2_1  0x00000010	/* Bit 1 */
  #define FMC_SDSR_BUSY      0x00000020	/* Busy status */


/*
 * QUAD SERIAL PERIPHERAL INTERFACE
 */
#define TADR_QSPI_R_BASE    (QSPI_R_BASE)
#define TOFF_QUADSPI_CR     0x0000		/* (RW) QUADSPI Control register */
  #define QUADSPI_CR_EN         0x00000001	/* Enable */
  #define QUADSPI_CR_ABORT      0x00000002	/* Abort request */
  #define QUADSPI_CR_DMAEN      0x00000004	/* DMA Enable */
  #define QUADSPI_CR_TCEN       0x00000008	/* Timeout Counter Enable */
  #define QUADSPI_CR_SSHIFT     0x00000010	/* Sample Shift */
  #define QUADSPI_CR_DFM        0x00000040	/* Dual Flash Mode */
  #define QUADSPI_CR_FSEL       0x00000080	/* Flash Select */
  #define QUADSPI_CR_FTHRES     0x00001F00	/* FTHRES[4:0] FIFO Level */
  #define QUADSPI_CR_TEIE       0x00010000	/* Transfer Error Interrupt Enable */
  #define QUADSPI_CR_TCIE       0x00020000	/* Transfer Complete Interrupt Enable */
  #define QUADSPI_CR_FTIE       0x00040000	/* FIFO Threshold Interrupt Enable */
  #define QUADSPI_CR_SMIE       0x00080000	/* Status Match Interrupt Enable */
  #define QUADSPI_CR_TOIE       0x00100000	/* TimeOut Interrupt Enable */
  #define QUADSPI_CR_APMS       0x00400000	/* Automatic Polling Mode Stop */
  #define QUADSPI_CR_PMM        0x00800000	/* Polling Match Mode */
  #define QUADSPI_CR_PRESCALER  0xFF000000	/* PRESCALER[7:0] Clock prescaler */
#define TOFF_QUADSPI_DCR    0x0004		/* (RW) QUADSPI Device Configuration register */
  #define QUADSPI_DCR_CKMODE    0x00000001	/* Mode 0 / Mode 3 */
  #define QUADSPI_DCR_CSHT      0x00000700	/* CSHT[2:0]: ChipSelect High Time */
  #define QUADSPI_DCR_CSHT_0    0x00000100
  #define QUADSPI_DCR_CSHT_1    0x00000200
  #define QUADSPI_DCR_CSHT_2    0x00000400
  #define QUADSPI_DCR_FSIZE     0x001F0000	/* FSIZE[4:0]: Flash Size */
#define TOFF_QUADSPI_SR     0x0008		/* (RW) QUADSPI Status register */
  #define QUADSPI_SR_TEF        0x00000001	/* Transfer Error Flag */
  #define QUADSPI_SR_TCF        0x00000002	/* Transfer Complete Flag */
  #define QUADSPI_SR_FTF        0x00000004	/* FIFO Threshlod Flag */
  #define QUADSPI_SR_SMF        0x00000008	/* Status Match Flag */
  #define QUADSPI_SR_TOF        0x00000010	/* Timeout Flag */
  #define QUADSPI_SR_BUSY       0x00000020	/* Busy */
  #define QUADSPI_SR_FLEVEL     0x00001F00	/* FIFO Threshlod Flag */
#define TOFF_QUADSPI_FCR    0x000C		/* (W)  QUADSPI Flag Clear register */
  #define QUADSPI_FCR_CTEF      0x00000001	/* Clear Transfer Error Flag */
  #define QUADSPI_FCR_CTCF      0x00000002	/* Clear Transfer Complete Flag */
  #define QUADSPI_FCR_CSMF      0x00000008	/* Clear Status Match Flag */
  #define QUADSPI_FCR_CTOF      0x00000010	/* Clear Timeout Flag */
#define TOFF_QUADSPI_DLR    0x0010		/* (RW) QUADSPI Data Length register */
#define TOFF_QUADSPI_CCR    0x0014		/* (RW) QUADSPI Communication Configuration register */
  #define QUADSPI_CCR_INSTRUCTION 0x000000FF	/* INSTRUCTION[7:0]: Instruction */
  #define QUADSPI_CCR_IMODE     0x00000300	/* IMODE[1:0]: Instruction Mode */
  #define QUADSPI_CCR_IMODE_0   0x00000100
  #define QUADSPI_CCR_IMODE_1   0x00000200
  #define QUADSPI_CCR_ADMODE    0x00000C00	/* ADMODE[1:0]: Address Mode */
  #define QUADSPI_CCR_ADMODE_0  0x00000400
  #define QUADSPI_CCR_ADMODE_1  0x00000800
  #define QUADSPI_CCR_ADSIZE    0x00003000	/* ADSIZE[1:0]: Address Size */
  #define QUADSPI_CCR_ADSIZE_0  0x00001000
  #define QUADSPI_CCR_ADSIZE_1  0x00002000
  #define QUADSPI_CCR_ABMODE    0x0000C000	/* ABMODE[1:0]: Alternate Bytes Mode */
  #define QUADSPI_CCR_ABMODE_0  0x00004000
  #define QUADSPI_CCR_ABMODE_1  0x00008000
  #define QUADSPI_CCR_ABSIZE    0x00030000	/* ABSIZE[1:0]: Instruction Mode */
  #define QUADSPI_CCR_ABSIZE_0  0x00010000
  #define QUADSPI_CCR_ABSIZE_1  0x00020000
  #define QUADSPI_CCR_DCYC      0x007C0000	/* DCYC[4:0]: Dummy Cycles */
  #define QUADSPI_CCR_DMODE     0x03000000	/* DMODE[1:0]: Data Mode */
  #define QUADSPI_CCR_DMODE_0   0x01000000
  #define QUADSPI_CCR_DMODE_1   0x02000000
  #define QUADSPI_CCR_FMODE     0x0C000000	/* FMODE[1:0]: Functional Mode */
  #define QUADSPI_CCR_FMODE_0   0x04000000
  #define QUADSPI_CCR_FMODE_1   0x08000000
  #define QUADSPI_CCR_SIOO      0x10000000	/* SIOO: Send Instruction Only Once Mode */
  #define QUADSPI_CCR_DHHC      0x40000000	/* DHHC: Delay Half Hclk Cycle           */
  #define QUADSPI_CCR_DDRM      0x80000000	/* DDRM: Double Data Rate Mode */
#define TOFF_QUADSPI_AR     0x0018		/* (RW) QUADSPI Address register */
#define TOFF_QUADSPI_ABR    0x001C		/* (RW) QUADSPI Alternate Bytes register */
#define TOFF_QUADSPI_DR     0x0020		/* (RW) QUADSPI Data register */
#define TOFF_QUADSPI_PSMKR  0x0024		/* (RW) QUADSPI Polling Status Mask register */
#define TOFF_QUADSPI_PSMAR  0x0028		/* (RW) QUADSPI Polling Status Match register */
#define TOFF_QUADSPI_PIR    0x002C		/* (RW) QUADSPI Polling Interval register */
  #define QUADSPI_PIR_INTERVAL  0x0000FFFF	/* INTERVAL[15:0]: Polling Interval */
#define TOFF_QUADSPI_LPTR   0x0030		/* (RW) QUADSPI Low Power Timeout register */
  #define QUADSPI_LPTR_TIMEOUT  0x0000FFFF	/* TIMEOUT[15:0]: Timeout period */


/*
 *  DEBUG MCU
 */
#define TADR_DBGMCU_BASE    0xE0042000
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
#define TOFF_DBGMCU_APB1FZ  0x0008		/* (RW) Debug MCU APB1 freeze register */
#define TOFF_DBGMCU_APB2FZ  0x000C		/* (RW) Debug MCU APB2 freeze register */


/*
 *  USB OTG REGISTERS BASE ADDRESS
 */
#define TADR_USB_OTGHS_BASE     USB_OTG_HS_PERIPH_BASE
#define TADR_USB_OTGFS_BASE     USB_OTG_FS_PERIPH_BASE
#define TOFF_USBO_GOTGCTL   0x0000		/* (RW) USB_OTG Control and Status Register */
  #define USB_OTG_GOTGCTL_SRQSCS    0x00000001	/* Session request success */
  #define USB_OTG_GOTGCTL_SRQ       0x00000002	/* Session request */
  #define USB_OTG_GOTGCTL_VBVALOEN  0x00000004	/* VBUS valid override enable */
  #define USB_OTG_GOTGCTL_VBVALOVAL 0x00000008	/* VBUS valid override value */
  #define USB_OTG_GOTGCTL_AVALOEN   0x00000010	/* A-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_AVALOVAL  0x00000020	/* A-peripheral session valid override value */
  #define USB_OTG_GOTGCTL_BVALOEN   0x00000040	/* B-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_BVALOVAL  0x00000080	/* B-peripheral session valid override value  */
  #define USB_OTG_GOTGCTL_HNGSCS    0x00000100	/* Host negotiation success */
  #define USB_OTG_GOTGCTL_HNPRQ     0x00000200	/* HNP request */
  #define USB_OTG_GOTGCTL_HSHNPEN   0x00000400	/* Host set HNP enable */
  #define USB_OTG_GOTGCTL_DHNPEN    0x00000800	/* Device HNP enabled */
  #define USB_OTG_GOTGCTL_EHEN      0x00001000	/* Embedded host enable */
  #define USB_OTG_GOTGCTL_CIDSTS    0x00010000	/* Connector ID status */
  #define USB_OTG_GOTGCTL_DBCT      0x00020000	/* Long/short debounce time */
  #define USB_OTG_GOTGCTL_ASVLD     0x00040000	/* A-session valid */
  #define USB_OTG_GOTGCTL_BSVLD     0x00080000	/* B-session valid */
  #define USB_OTG_GOTGCTL_OTGVER    0x00100000	/* OTG version  */
#define TOFF_USBO_GOTGINT   0x0004		/* (RW) USB_OTG Interrupt Register */
  #define USB_OTG_GOTGINT_SEDET     0x00000004	/* Session end detected */
  #define USB_OTG_GOTGINT_SRSSCHG   0x00000100	/* Session request success status change */
  #define USB_OTG_GOTGINT_HNSSCHG   0x00000200	/* Host negotiation success status change */
  #define USB_OTG_GOTGINT_HNGDET    0x00020000	/* Host negotiation detected */
  #define USB_OTG_GOTGINT_ADTOCHG   0x00040000	/* A-device timeout change */
  #define USB_OTG_GOTGINT_DBCDNE    0x00080000	/* Debounce done */
  #define USB_OTG_GOTGINT_IDCHNG    0x00100000	/* Change in ID pin input value */
#define TOFF_USBO_GAHBCFG   0x0008		/* (RW) Core AHB Configuration Register */
  #define USB_OTG_GAHBCFG_GINT      0x00000001	/* Global interrupt mask */
  #define USB_OTG_GAHBCFG_HBSTLEN   0x0000001E	/* Burst length/type */
  #define USB_OTG_GAHBCFG_HBSTLEN_0 0x00000002	/* Bit 0 */
  #define USB_OTG_GAHBCFG_HBSTLEN_1 0x00000004	/* Bit 1 */
  #define USB_OTG_GAHBCFG_HBSTLEN_2 0x00000008	/* Bit 2 */
  #define USB_OTG_GAHBCFG_HBSTLEN_3 0x00000010	/* Bit 3 */
  #define USB_OTG_GAHBCFG_DMAEN     0x00000020	/* DMA enable */
  #define USB_OTG_GAHBCFG_TXFELVL   0x00000080	/* TxFIFO empty level */
  #define USB_OTG_GAHBCFG_PTXFELVL  0x00000100	/* Periodic TxFIFO empty level */
#define TOFF_USBO_GUSBCFG   0x000C		/* (RW) Core USB Configuration Register */
  #define USB_OTG_GUSBCFG_TOCAL     0x00000007	/* FS timeout calibration */
  #define USB_OTG_GUSBCFG_TOCAL_0   0x00000001	/* Bit 0 */
  #define USB_OTG_GUSBCFG_TOCAL_1   0x00000002	/* Bit 1 */
  #define USB_OTG_GUSBCFG_TOCAL_2   0x00000004	/* Bit 2 */
  #define USB_OTG_GUSBCFG_PHYSEL    0x00000040	/* USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select */
  #define USB_OTG_GUSBCFG_SRPCAP    0x00000100	/* SRP-capable */
  #define USB_OTG_GUSBCFG_HNPCAP    0x00000200	/* HNP-capable */
  #define USB_OTG_GUSBCFG_TRDT      0x00003C00	/* USB turnaround time */
  #define USB_OTG_GUSBCFG_TRDT_0    0x00000400	/* Bit 0 */
  #define USB_OTG_GUSBCFG_TRDT_1    0x00000800	/* Bit 1 */
  #define USB_OTG_GUSBCFG_TRDT_2    0x00001000	/* Bit 2 */
  #define USB_OTG_GUSBCFG_TRDT_3    0x00002000	/* Bit 3 */
  #define USB_OTG_GUSBCFG_PHYLPCS   0x00008000	/* PHY Low-power clock select */
  #define USB_OTG_GUSBCFG_ULPIFSLS  0x00020000	/* ULPI FS/LS select */
  #define USB_OTG_GUSBCFG_ULPIAR    0x00040000	/* ULPI Auto-resume */
  #define USB_OTG_GUSBCFG_ULPICSM   0x00080000	/* ULPI Clock SuspendM */
  #define USB_OTG_GUSBCFG_ULPIEVBUSD 0x00100000	/* ULPI External VBUS Drive */
  #define USB_OTG_GUSBCFG_ULPIEVBUSI 0x00200000	/* ULPI external VBUS indicator */
  #define USB_OTG_GUSBCFG_TSDPS     0x00400000	/* TermSel DLine pulsing selection */
  #define USB_OTG_GUSBCFG_PCCI      0x00800000	/* Indicator complement */
  #define USB_OTG_GUSBCFG_PTCI      0x01000000	/* Indicator pass through */
  #define USB_OTG_GUSBCFG_ULPIIPD   0x02000000	/* ULPI interface protect disable */
  #define USB_OTG_GUSBCFG_FHMOD     0x20000000	/* Forced host mode */
  #define USB_OTG_GUSBCFG_FDMOD     0x40000000	/* Forced peripheral mode */
  #define USB_OTG_GUSBCFG_CTXPKT    0x80000000	/* Corrupt Tx packet */
#define TOFF_USBO_GRSTCTL   0x0010		/* (RW) Core Reset Register */
  #define USB_OTG_GRSTCTL_CSRST     0x00000001	/* Core soft reset */
  #define USB_OTG_GRSTCTL_HSRST     0x00000002	/* HCLK soft reset */
  #define USB_OTG_GRSTCTL_FCRST     0x00000004	/* Host frame counter reset */
  #define USB_OTG_GRSTCTL_RXFFLSH   0x00000010	/* RxFIFO flush */
  #define USB_OTG_GRSTCTL_TXFFLSH   0x00000020	/* TxFIFO flush */
  #define USB_OTG_GRSTCTL_TXFNUM    0x000007C0	/* TxFIFO number */
  #define USB_OTG_GRSTCTL_TXFNUM_0  0x00000040	/* Bit 0 */
  #define USB_OTG_GRSTCTL_TXFNUM_1  0x00000080	/* Bit 1 */
  #define USB_OTG_GRSTCTL_TXFNUM_2  0x00000100	/* Bit 2 */
  #define USB_OTG_GRSTCTL_TXFNUM_3  0x00000200	/* Bit 3 */
  #define USB_OTG_GRSTCTL_TXFNUM_4  0x00000400	/* Bit 4 */
  #define USB_OTG_GRSTCTL_DMAREQ    0x40000000	/* DMA request signal */
  #define USB_OTG_GRSTCTL_AHBIDL    0x80000000	/* AHB master idle */
#define TOFF_USBO_GINTSTS   0x0014		/* (RW)  Core Interrupt Register */
  #define USB_OTG_GINTSTS_CMOD      0x00000001	/* Current mode of operation */
  #define USB_OTG_GINTSTS_MMIS      0x00000002	/* Mode mismatch interrupt */
  #define USB_OTG_GINTSTS_OTGINT    0x00000004	/* OTG interrupt */
  #define USB_OTG_GINTSTS_SOF       0x00000008	/* Start of frame */
  #define USB_OTG_GINTSTS_RXFLVL    0x00000010	/* RxFIFO nonempty */
  #define USB_OTG_GINTSTS_NPTXFE    0x00000020	/* Nonperiodic TxFIFO empty */
  #define USB_OTG_GINTSTS_GINAKEFF  0x00000040	/* Global IN nonperiodic NAK effective */
  #define USB_OTG_GINTSTS_BOUTNAKEFF 0x00000080	/* Global OUT NAK effective */
  #define USB_OTG_GINTSTS_ESUSP     0x00000400	/* Early suspend */
  #define USB_OTG_GINTSTS_USBSUSP   0x00000800	/* USB suspend */
  #define USB_OTG_GINTSTS_USBRST    0x00001000	/* USB reset */
  #define USB_OTG_GINTSTS_ENUMDNE   0x00002000	/* Enumeration done */
  #define USB_OTG_GINTSTS_ISOODRP   0x00004000	/* Isochronous OUT packet dropped interrupt */
  #define USB_OTG_GINTSTS_EOPF      0x00008000	/* End of periodic frame interrupt */
  #define USB_OTG_GINTSTS_IEPINT    0x00040000	/* IN endpoint interrupt */
  #define USB_OTG_GINTSTS_OEPINT    0x00080000	/* OUT endpoint interrupt */
  #define USB_OTG_GINTSTS_IISOIXFR  0x00100000	/* Incomplete isochronous IN transfer */
  #define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT 0x00200000	/* Incomplete periodic transfer */
  #define USB_OTG_GINTSTS_DATAFSUSP 0x00400000	/* Data fetch suspended */
  #define USB_OTG_GINTSTS_HPRTINT   0x01000000	/* Host port interrupt */
  #define USB_OTG_GINTSTS_HCINT     0x02000000	/* Host channels interrupt */
  #define USB_OTG_GINTSTS_PTXFE     0x04000000	/* Periodic TxFIFO empty */
  #define USB_OTG_GINTSTS_LPMINT    0x08000000	/* LPM interrupt                                  */
  #define USB_OTG_GINTSTS_CIDSCHG   0x10000000	/* Connector ID status change */
  #define USB_OTG_GINTSTS_DISCINT   0x20000000	/* Disconnect detected interrupt */
  #define USB_OTG_GINTSTS_SRQINT    0x40000000	/* Session request/new session detected interrupt */
  #define USB_OTG_GINTSTS_WKUINT    0x80000000	/* Resume/remote wakeup detected interrupt */
#define TOFF_USBO_GINTMSK   0x0018		/* (RW)  Core Interrupt Mask Register */
  #define USB_OTG_GINTMSK_MMISM     0x00000002	/* Mode mismatch interrupt mask */
  #define USB_OTG_GINTMSK_OTGINT    0x00000004	/* OTG interrupt mask */
  #define USB_OTG_GINTMSK_SOFM      0x00000008	/* Start of frame mask */
  #define USB_OTG_GINTMSK_RXFLVLM   0x00000010	/* Receive FIFO nonempty mask */
  #define USB_OTG_GINTMSK_NPTXFEM   0x00000020	/* Nonperiodic TxFIFO empty mask */
  #define USB_OTG_GINTMSK_GINAKEFFM 0x00000040	/* Global nonperiodic IN NAK effective mask */
  #define USB_OTG_GINTMSK_GONAKEFFM 0x00000080	/* Global OUT NAK effective mask */
  #define USB_OTG_GINTMSK_ESUSPM    0x00000400	/* Early suspend mask */
  #define USB_OTG_GINTMSK_USBSUSPM  0x00000800	/* USB suspend mask */
  #define USB_OTG_GINTMSK_USBRST    0x00001000	/* USB reset mask */
  #define USB_OTG_GINTMSK_ENUMDNEM  0x00002000	/* Enumeration done mask */
  #define USB_OTG_GINTMSK_ISOODRPM  0x00004000	/* Isochronous OUT packet dropped interrupt mask */
  #define USB_OTG_GINTMSK_EOPFM     0x00008000	/* End of periodic frame interrupt mask */
  #define USB_OTG_GINTMSK_EPMISM    0x00020000	/* Endpoint mismatch interrupt mask */
  #define USB_OTG_GINTMSK_IEPINT    0x00040000	/* IN endpoints interrupt mask */
  #define USB_OTG_GINTMSK_OEPINT    0x00080000	/* OUT endpoints interrupt mask */
  #define USB_OTG_GINTMSK_IISOIXFRM 0x00100000	/* Incomplete isochronous IN transfer mask */
  #define USB_OTG_GINTMSK_PXFRM_IISOOXFRM 0x00200000	/* Incomplete periodic transfer mask */
  #define USB_OTG_GINTMSK_FSUSPM    0x00400000	/* Data fetch suspended mask */
  #define USB_OTG_GINTMSK_RSTDEM    0x00800000	/* Reset detected interrupt mask */
  #define USB_OTG_GINTMSK_PRTIM     0x01000000	/* Host port interrupt mask */
  #define USB_OTG_GINTMSK_HCIM      0x02000000	/* Host channels interrupt mask */
  #define USB_OTG_GINTMSK_PTXFEM    0x04000000	/* Periodic TxFIFO empty mask */
  #define USB_OTG_GINTMSK_LPMINTM   0x08000000	/* LPM interrupt Mask */
  #define USB_OTG_GINTMSK_CIDSCHGM  0x10000000	/* Connector ID status change mask */
  #define USB_OTG_GINTMSK_DISCINT   0x20000000	/* Disconnect detected interrupt mask */
  #define USB_OTG_GINTMSK_SRQIM     0x40000000	/* Session request/new session detected interrupt mask */
  #define USB_OTG_GINTMSK_WUIM      0x80000000	/* Resume/remote wakeup detected interrupt mask */
#define TOFF_USBO_GRXSTSR   0x001C		/* (RW) Receive Sts Q Read Register */
#define TOFF_USBO_GRXSTSP   0x0020		/* (RW) Receive Sts Q Read & POP Register */
  #define USB_OTG_GRXSTSP_EPNUM     0x0000000F	/* IN EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_BCNT      0x00007FF0	/* OUT EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_DPID      0x00018000	/* OUT EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_PKTSTS    0x001E0000	/* OUT EP interrupt mask bits */
#define TOFF_USBO_GRXFSIZ   0x0024		/* (RW) Receive FIFO Size Register */
  #define USB_OTG_GRXFSIZ_RXFD      0x0000FFFF	/* RxFIFO depth */
#define TOFF_USBO_DIEPTXF0_HNPTXFSIZ 0x0028	/* (RW) EP0 / Non Periodic Tx FIFO Size Register */
  #define USB_OTG_NPTXFSA           0x0000FFFF	/* Nonperiodic transmit RAM start address */
  #define USB_OTG_NPTXFD            0xFFFF0000	/* Nonperiodic TxFIFO depth */
  #define USB_OTG_TX0FSA            0x0000FFFF	/* Endpoint 0 transmit RAM start address */
  #define USB_OTG_TX0FD             0xFFFF0000	/* Endpoint 0 TxFIFO depth */
#define TOFF_USBO_HNPTXSTS  0x002C		/* (RW) Non Periodic Tx FIFO/Queue Sts Register */
#define TOFF_USBO_GCCFG     0x0038		/* (RW) General Purpose IO Register */
  #define USB_OTG_GCCFG_PWRDWN      0x00010000	/* Power down */
  #define USB_OTG_GCCFG_VBDEN       0x00200000	/* USB VBUS Detection Enable */
#define TOFF_USBO_CID       0x003C		/* (RW) User ID Register */
  #define USB_OTG_CID_PRODUCT_ID    0xFFFFFFFF	/* Product ID field */
#define TOFF_USBO_GHWCFG3   0x004C		/* (RW) User HW config3 */
#define TOFF_USBO_GLPMCFG   0x0054		/* (RW) LPM Register */
  #define USB_OTG_GLPMCFG_LPMEN     0x00000001	/* LPM support enable                                     */
  #define USB_OTG_GLPMCFG_LPMACK    0x00000002	/* LPM Token acknowledge enable                           */
  #define USB_OTG_GLPMCFG_BESL      0x0000003C	/* BESL value received with last ACKed LPM Token          */
  #define USB_OTG_GLPMCFG_REMWAKE   0x00000040	/* bRemoteWake value received with last ACKed LPM Token   */
  #define USB_OTG_GLPMCFG_L1SSEN    0x00000080	/* L1 shallow sleep enable                                */
  #define USB_OTG_GLPMCFG_BESLTHRS  0x00000F00	/* BESL threshold                                         */
  #define USB_OTG_GLPMCFG_L1DSEN    0x00001000	/* L1 deep sleep enable                                   */
  #define USB_OTG_GLPMCFG_LPMRSP    0x00006000	/* LPM response                                           */
  #define USB_OTG_GLPMCFG_SLPSTS    0x00008000	/* Port sleep status                                      */
  #define USB_OTG_GLPMCFG_L1RSMOK   0x00010000	/* Sleep State Resume OK                                  */
  #define USB_OTG_GLPMCFG_LPMCHIDX  0x001E0000	/* LPM Channel Index                                      */
  #define USB_OTG_GLPMCFG_LPMRCNT   0x00E00000	/* LPM retry count                                        */
  #define USB_OTG_GLPMCFG_SNDLPM    0x01000000	/* Send LPM transaction                                   */
  #define USB_OTG_GLPMCFG_LPMRCNTSTS 0x0E000000	/* LPM retry count status                                 */
  #define USB_OTG_GLPMCFG_ENBESL    0x10000000	/* Enable best effort service latency                     */
#define TOFF_USBO_GPWRDN    0x0058		/* (RW) Power Down Register */
  #define USB_OTG_GPWRDN_ADPMEN     0x00000001	/* ADP module enable */
  #define USB_OTG_GPWRDN_ADPIF      0x00800000	/* ADP Interrupt flag */
#define TOFF_USBO_GDFIFOCFG 0x005C		/* (RW) DFIFO Software Config Register */
#define TOFF_USBO_GADPCTL   0x0060		/* (RW) ADP Timer, Control and Status Register */
#define TOFF_USBO_HPTXFSIZ  0x0100		/* (RW) Host Periodic Tx FIFO Size Reg */
  #define USB_OTG_HPTXFSIZ_PTXSA    0x0000FFFF	/* Host periodic TxFIFO start address */
  #define USB_OTG_HPTXFSIZ_PTXFD    0xFFFF0000	/* Host periodic TxFIFO depth */
#define TOFF_USBO_DIEPTXF   0x0104		/* (RW) dev Periodic Transmit FIFO x 15 */
  #define USB_OTG_DIEPTXF_INEPTXSA  0x0000FFFF	/* IN endpoint FIFOx transmit RAM start address */
  #define USB_OTG_DIEPTXF_INEPTXFD  0xFFFF0000	/* IN endpoint TxFIFO depth */

/*
 *  USB DEVICE(OTG)
 */
#define TADR_USB_DEVICE_BASE (USB_OTG_FS_PERIPH_BASE+USB_OTG_DEVICE_BASE)
#define TOFF_USBD_DCFG      0x0000		/* (RW) dev Configuration Register */
  #define USB_OTG_DCFG_DSPD         0x00000003	/* Device speed */
  #define USB_OTG_DCFG_DSPD_0       0x00000001	/* Bit 0 */
  #define USB_OTG_DCFG_DSPD_1       0x00000002	/* Bit 1 */
  #define USB_OTG_DCFG_NZLSOHSK     0x00000004	/* Nonzero-length status OUT handshake */
  #define USB_OTG_DCFG_DAD          0x000007F0	/* Device address */
  #define USB_OTG_DCFG_DAD_0        0x00000010	/* Bit 0 */
  #define USB_OTG_DCFG_DAD_1        0x00000020	/* Bit 1 */
  #define USB_OTG_DCFG_DAD_2        0x00000040	/* Bit 2 */
  #define USB_OTG_DCFG_DAD_3        0x00000080	/* Bit 3 */
  #define USB_OTG_DCFG_DAD_4        0x00000100	/* Bit 4 */
  #define USB_OTG_DCFG_DAD_5        0x00000200	/* Bit 5 */
  #define USB_OTG_DCFG_DAD_6        0x00000400	/* Bit 6 */
  #define USB_OTG_DCFG_PFIVL        0x00001800	/* Periodic (micro)frame interval */
  #define USB_OTG_DCFG_PFIVL_0      0x00000800	/* Bit 0 */
  #define USB_OTG_DCFG_PFIVL_1      0x00001000	/* Bit 1 */
  #define USB_OTG_DCFG_PERSCHIVL    0x03000000	/* Periodic scheduling interval */
  #define USB_OTG_DCFG_PERSCHIVL_0  0x01000000	/* Bit 0 */
  #define USB_OTG_DCFG_PERSCHIVL_1  0x02000000	/* Bit 1 */
#define TOFF_USBD_DCTL      0x0004		/* (RW) dev Control Register */
  #define USB_OTG_DCTL_RWUSIG       0x00000001	/* Remote wakeup signaling */
  #define USB_OTG_DCTL_SDIS         0x00000002	/* Soft disconnect */
  #define USB_OTG_DCTL_GINSTS       0x00000004	/* Global IN NAK status */
  #define USB_OTG_DCTL_GONSTS       0x00000008	/* Global OUT NAK status */
  #define USB_OTG_DCTL_TCTL         0x00000070	/* Test control */
  #define USB_OTG_DCTL_TCTL_0       0x00000010	/* Bit 0 */
  #define USB_OTG_DCTL_TCTL_1       0x00000020	/* Bit 1 */
  #define USB_OTG_DCTL_TCTL_2       0x00000040	/* Bit 2 */
  #define USB_OTG_DCTL_SGINAK       0x00000080	/* Set global IN NAK */
  #define USB_OTG_DCTL_CGINAK       0x00000100	/* Clear global IN NAK */
  #define USB_OTG_DCTL_SGONAK       0x00000200	/* Set global OUT NAK */
  #define USB_OTG_DCTL_CGONAK       0x00000400	/* Clear global OUT NAK */
  #define USB_OTG_DCTL_POPRGDNE     0x00000800	/* Power-on programming done */
#define TOFF_USBD_DSTS      0x0008		/* (RO) dev Status Register (RO) */
  #define USB_OTG_DSTS_SUSPSTS      0x00000001	/* Suspend status */
  #define USB_OTG_DSTS_ENUMSPD      0x00000006	/* Enumerated speed */
  #define USB_OTG_DSTS_ENUMSPD_0    0x00000002	/* Bit 0 */
  #define USB_OTG_DSTS_ENUMSPD_1    0x00000004	/* Bit 1 */
  #define USB_OTG_DSTS_EERR         0x00000008	/* Erratic error */
  #define USB_OTG_DSTS_FNSOF        0x003FFF00	/* Frame number of the received SOF */
#define TOFF_USBD_DIEPMSK   0x0010		/* (RW) dev IN Endpoint Mask */
  #define USB_OTG_DIEPMSK_XFRCM     0x00000001	/* Transfer completed interrupt mask */
  #define USB_OTG_DIEPMSK_EPDM      0x00000002	/* Endpoint disabled interrupt mask */
  #define USB_OTG_DIEPMSK_TOM       0x00000008	/* Timeout condition mask (nonisochronous endpoints) */
  #define USB_OTG_DIEPMSK_ITTXFEMSK 0x00000010	/* IN token received when TxFIFO empty mask */
  #define USB_OTG_DIEPMSK_INEPNMM   0x00000020	/* IN token received with EP mismatch mask */
  #define USB_OTG_DIEPMSK_INEPNEM   0x00000040	/* IN endpoint NAK effective mask */
  #define USB_OTG_DIEPMSK_TXFURM    0x00000100	/* FIFO underrun mask */
  #define USB_OTG_DIEPMSK_BIM       0x00000200	/* BNA interrupt mask */
#define TOFF_USBD_DOEPMSK   0x0014		/* (RW) dev OUT Endpoint Mask */
  #define USB_OTG_DOEPMSK_XFRCM     0x00000001	/* Transfer completed interrupt mask */
  #define USB_OTG_DOEPMSK_EPDM      0x00000002	/* Endpoint disabled interrupt mask */
  #define USB_OTG_DOEPMSK_STUPM     0x00000008	/* SETUP phase done mask */
  #define USB_OTG_DOEPMSK_OTEPDM    0x00000010	/* OUT token received when endpoint disabled mask */
  #define USB_OTG_DOEPMSK_B2BSTUP   0x00000040	/* Back-to-back SETUP packets received mask */
  #define USB_OTG_DOEPMSK_OPEM      0x00000100	/* OUT packet error mask */
  #define USB_OTG_DOEPMSK_BOIM      0x00000200	/* BNA interrupt mask */
#define TOFF_USBD_DAINT     0x0018		/* (RW) dev All Endpoints Itr Register */
  #define USB_OTG_DAINT_IEPINT      0x0000FFFF	/* IN endpoint interrupt bits */
  #define USB_OTG_DAINT_OEPINT      0xFFFF0000	/* OUT endpoint interrupt bits */
#define TOFF_USBD_DAINTMSK  0x001C		/* (RW) dev All Endpoints Itr Mask */
  #define USB_OTG_DAINTMSK_IEPM     0x0000FFFF	/* IN EP interrupt mask bits */
  #define USB_OTG_DAINTMSK_OEPM     0xFFFF0000	/* OUT EP interrupt mask bits */
#define TOFF_USBD_DVBUSDIS  0x0028		/* (RW) dev VBUS discharge Register */
  #define USB_OTG_DVBUSDIS_VBUSDT   0x0000FFFF	/* Device VBUS discharge time */
#define TOFF_USBD_DVBUSPULSE 0x002C		/* (RW) dev VBUS Pulse Register */
  #define USB_OTG_DVBUSPULSE_DVBUSP 0x00000FFF	/* Device VBUS pulsing time */
#define TOFF_USBD_DTHRCTL   0x0030		/* (RW) dev thr */
  #define USB_OTG_DTHRCTL_NONISOTHREN 0x00000001	/* Nonisochronous IN endpoints threshold enable */
  #define USB_OTG_DTHRCTL_ISOTHREN    0x00000002	/* ISO IN endpoint threshold enable */
  #define USB_OTG_DTHRCTL_TXTHRLEN    0x000007FC	/* Transmit threshold length */
  #define USB_OTG_DTHRCTL_TXTHRLEN_0  0x00000004	/* Bit 0 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_1  0x00000008	/* Bit 1 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_2  0x00000010	/* Bit 2 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_3  0x00000020	/* Bit 3 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_4  0x00000040	/* Bit 4 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_5  0x00000080	/* Bit 5 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_6  0x00000100	/* Bit 6 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_7  0x00000200	/* Bit 7 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_8  0x00000400	/* Bit 8 */
  #define USB_OTG_DTHRCTL_RXTHREN     0x00010000	/* Receive threshold enable */
  #define USB_OTG_DTHRCTL_RXTHRLEN    0x03FE0000	/* Receive threshold length */
  #define USB_OTG_DTHRCTL_RXTHRLEN_0  0x00020000	/* Bit 0 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_1  0x00040000	/* Bit 1 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_2  0x00080000	/* Bit 2 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_3  0x00100000	/* Bit 3 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_4  0x00200000	/* Bit 4 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_5  0x00400000	/* Bit 5 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_6  0x00800000	/* Bit 6 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_7  0x01000000	/* Bit 7 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_8  0x02000000	/* Bit 8 */
  #define USB_OTG_DTHRCTL_ARPEN       0x08000000	/* Arbiter parking enable */
#define TOFF_USBD_DIEPEMPMSK 0x0034		/* (RW) dev empty msk */
  #define USB_OTG_DIEPEMPMSK_INEPTXFEM 0x0000FFFF	/* IN EP Tx FIFO empty interrupt mask bits */
#define TOFF_USBD_DEACHINT  0x0038		/* (RW) dedicated EP interrupt */
  #define USB_OTG_DEACHINT_IEP1INT  0x00000002	/* IN endpoint 1interrupt bit */
  #define USB_OTG_DEACHINT_OEP1INT  0x00020000	/* OUT endpoint 1 interrupt bit */
#define TOFF_USBD_DEACHMSK  0x003C		/* (RW) dedicated EP msk */
#define TOFF_USBD_DINEP1MSK 0x0044		/* (RW) dedicated EP mask */
#define TOFF_USBD_DOUTEP1MSK 0x0084		/* (RW) dedicated EP msk */

/*
 *  USB OTG IN ENDPOINT
 */
#define TADR_USBO_INEP_BASE     (USB_OTG_FS_PERIPH_BASE+USB_OTG_IN_ENDPOINT_BASE)
#define USBO_EP_REG_SIZE         0x20
#define TOFF_USBEI_DIEPCTL  0x0000		/* (RW) dev IN Endpoint Control Register */
  #define USB_OTG_DIEPCTL_MPSIZ     0x000007FF	/* Maximum packet size */
  #define USB_OTG_DIEPCTL_USBAEP    0x00008000	/* USB active endpoint */
  #define USB_OTG_DIEPCTL_EONUM_DPID 0x00010000	/* Even/odd frame */
  #define USB_OTG_DIEPCTL_NAKSTS    0x00020000	/* NAK status */
  #define USB_OTG_DIEPCTL_EPTYP     0x000C0000	/* Endpoint type */
  #define USB_OTG_DIEPCTL_EPTYP_0   0x00040000	/* Bit 0 */
  #define USB_OTG_DIEPCTL_EPTYP_1   0x00080000	/* Bit 1 */
  #define USB_OTG_DIEPCTL_STALL     0x00200000	/* STALL handshake */
  #define USB_OTG_DIEPCTL_TXFNUM    0x03C00000	/* TxFIFO number */
  #define USB_OTG_DIEPCTL_TXFNUM_0  0x00400000	/* Bit 0 */
  #define USB_OTG_DIEPCTL_TXFNUM_1  0x00800000	/* Bit 1 */
  #define USB_OTG_DIEPCTL_TXFNUM_2  0x01000000	/* Bit 2 */
  #define USB_OTG_DIEPCTL_TXFNUM_3  0x02000000	/* Bit 3 */
  #define USB_OTG_DIEPCTL_CNAK      0x04000000	/* Clear NAK */
  #define USB_OTG_DIEPCTL_SNAK      0x08000000	/* Set NAK */
  #define USB_OTG_DIEPCTL_SD0PID_SEVNFRM 0x10000000	/* Set DATA0 PID */
  #define USB_OTG_DIEPCTL_SODDFRM   0x20000000	/* Set odd frame */
  #define USB_OTG_DIEPCTL_EPDIS     0x40000000	/* Endpoint disable */
  #define USB_OTG_DIEPCTL_EPENA     0x80000000	/* Endpoint enable */
#define TOFF_USBEI_DIEPINT  0x0008		/* (RW) dev IN Endpoint Itr Register */
  #define USB_OTG_DIEPINT_XFRC      0x00000001	/* Transfer completed interrupt */
  #define USB_OTG_DIEPINT_EPDISD    0x00000002	/* Endpoint disabled interrupt */
  #define USB_OTG_DIEPINT_TOC       0x00000008	/* Timeout condition */
  #define USB_OTG_DIEPINT_ITTXFE    0x00000010	/* IN token received when TxFIFO is empty */
  #define USB_OTG_DIEPINT_INEPNE    0x00000040	/* IN endpoint NAK effective */
  #define USB_OTG_DIEPINT_TXFE      0x00000080	/* Transmit FIFO empty */
  #define USB_OTG_DIEPINT_TXFIFOUDRN 0x00000100	/* Transmit Fifo Underrun */
  #define USB_OTG_DIEPINT_BNA       0x00000200	/* Buffer not available interrupt */
  #define USB_OTG_DIEPINT_PKTDRPSTS 0x00000800	/* Packet dropped status */
  #define USB_OTG_DIEPINT_BERR      0x00001000	/* Babble error interrupt */
  #define USB_OTG_DIEPINT_NAK       0x00002000	/* NAK interrupt */
#define TOFF_USBEI_DIEPTSIZ 0x0010		/* (RW) IN Endpoint Txfer Size */
  #define USB_OTG_DIEPTSIZ_XFRSIZ   0x0007FFFF	/* Transfer size */
  #define USB_OTG_DIEPTSIZ_PKTCNT   0x1FF80000	/* Packet count */
  #define USB_OTG_DIEPTSIZ_MULCNT   0x60000000	/* Packet count */
#define TOFF_USBEI_DIEPDMA  0x0014		/* (RW) IN Endpoint DMA Address Register */
  #define USB_OTG_DIEPDMA_DMAADDR   0xFFFFFFFF	/* DMA address */
#define TOFF_USBEI_DTXFSTS  0x0018		/* (RW) IN Endpoint Tx FIFO Status Register */
  #define USB_OTG_DTXFSTS_INEPTFSAV 0x0000FFFF	/* IN endpoint TxFIFO space avail */

/*
 *  USB OTG OUTPUT ENDPOINT
 */
#define TADR_USBO_OUTEP_BASE    (USB_OTG_FS_PERIPH_BASE+USB_OTG_OUT_ENDPOINT_BASE)
#define TOFF_USBEO_DOEPCTL  0x0000		/* (RW) dev OUT Endpoint Control Register */
  #define USB_OTG_DOEPCTL_MPSIZ     0x000007FF	/* Maximum packet size */
  #define USB_OTG_DOEPCTL_USBAEP    0x00008000	/* USB active endpoint */
  #define USB_OTG_DOEPCTL_NAKSTS    0x00020000	/* NAK status */
  #define USB_OTG_DOEPCTL_SD0PID_SEVNFRM  0x10000000	/* Set DATA0 PID */
  #define USB_OTG_DOEPCTL_SODDFRM   0x20000000	/* Set odd frame */
  #define USB_OTG_DOEPCTL_EPTYP     0x000C0000	/* Endpoint type */
  #define USB_OTG_DOEPCTL_EPTYP_0   0x00040000	/* Bit 0 */
  #define USB_OTG_DOEPCTL_EPTYP_1   0x00080000	/* Bit 1 */
  #define USB_OTG_DOEPCTL_SNPM      0x00100000	/* Snoop mode */
  #define USB_OTG_DOEPCTL_STALL     0x00200000	/* STALL handshake */
  #define USB_OTG_DOEPCTL_CNAK      0x04000000	/* Clear NAK */
  #define USB_OTG_DOEPCTL_SNAK      0x08000000	/* Set NAK */
  #define USB_OTG_DOEPCTL_EPDIS     0x40000000	/* Endpoint disable */
  #define USB_OTG_DOEPCTL_EPENA     0x80000000	/* Endpoint enable */
#define TOFF_USBEO_DOEPINT  0x0008		/* (RW) dev OUT Endpoint Itr Register */
  #define USB_OTG_DOEPINT_XFRC      0x00000001	/* Transfer completed interrupt */
  #define USB_OTG_DOEPINT_EPDISD    0x00000002	/* Endpoint disabled interrupt */
  #define USB_OTG_DOEPINT_STUP      0x00000008	/* SETUP phase done */
  #define USB_OTG_DOEPINT_OTEPDIS   0x00000010	/* OUT token received when endpoint disabled */
  #define USB_OTG_DOEPINT_B2BSTUP   0x00000040	/* Back-to-back SETUP packets received */
  #define USB_OTG_DOEPINT_NYET      0x00004000	/* NYET interrupt */
#define TOFF_USBEO_DOEPTSIZ 0x0010		/* (RW) dev OUT Endpoint Txfer Size */
  #define USB_OTG_DOEPTSIZ_XFRSIZ   0x0007FFFF	/* Transfer size */
  #define USB_OTG_DOEPTSIZ_PKTCNT   0x1FF80000	/* Packet count */
  #define USB_OTG_DOEPTSIZ_STUPCNT  0x60000000	/* SETUP packet count */
  #define USB_OTG_DOEPTSIZ_STUPCNT_0 0x20000000	/* Bit 0 */
  #define USB_OTG_DOEPTSIZ_STUPCNT_1 0x40000000	/* Bit 1 */
#define TOFF_USBEO_DOEPDMA  0x0014		/* (RW) dev OUT Endpoint DMA Address */

/*
 *  USB OTG HOST
 */
#define TADR_USBO_HOST_BASE     (USB_OTG_FS_PERIPH_BASE+USB_OTG_HOST_BASE)
#define TOFF_USBH_HCFG      0x0000		/* (RW) Host Configuration Register */
  #define USB_OTG_HCFG_FSLSPCS      0x00000003	/* FS/LS PHY clock select */
  #define USB_OTG_HCFG_FSLSPCS_0    0x00000001	/* Bit 0 */
  #define USB_OTG_HCFG_FSLSPCS_1    0x00000002	/* Bit 1 */
  #define USB_OTG_HCFG_FSLSS        0x00000004	/* FS- and LS-only support */
#define TOFF_USBH_HFIR      0x0004		/* (RW) Host Frame Interval Register */
  #define USB_OTG_HFIR_FRIVL        0x0000FFFF	/* Frame interval */
#define TOFF_USBH_HFNUM     0x0008		/* (RW) Host Frame Nbr/Frame Remaining */
  #define USB_OTG_HFNUM_FRNUM       0x0000FFFF	/* Frame number */
  #define USB_OTG_HFNUM_FTREM       0xFFFF0000	/* Frame time remaining */
#define TOFF_USBH_HPTXSTS   0x0010		/* (RW) Host Periodic Tx FIFO/ Queue Status */
  #define USB_OTG_HPTXSTS_PTXFSAVL  0x0000FFFF	/* Periodic transmit data FIFO space available */
  #define USB_OTG_HPTXSTS_PTXQSAV   0x00FF0000	/* Periodic transmit request queue space available */
  #define USB_OTG_HPTXSTS_PTXQSAV_0 0x00010000	/* Bit 0 */
  #define USB_OTG_HPTXSTS_PTXQSAV_1 0x00020000	/* Bit 1 */
  #define USB_OTG_HPTXSTS_PTXQSAV_2 0x00040000	/* Bit 2 */
  #define USB_OTG_HPTXSTS_PTXQSAV_3 0x00080000	/* Bit 3 */
  #define USB_OTG_HPTXSTS_PTXQSAV_4 0x00100000	/* Bit 4 */
  #define USB_OTG_HPTXSTS_PTXQSAV_5 0x00200000	/* Bit 5 */
  #define USB_OTG_HPTXSTS_PTXQSAV_6 0x00400000	/* Bit 6 */
  #define USB_OTG_HPTXSTS_PTXQSAV_7 0x00800000	/* Bit 7 */
  #define USB_OTG_HPTXSTS_PTXQTOP   0xFF000000	/* Top of the periodic transmit request queue */
  #define USB_OTG_HPTXSTS_PTXQTOP_0 0x01000000	/* Bit 0 */
  #define USB_OTG_HPTXSTS_PTXQTOP_1 0x02000000	/* Bit 1 */
  #define USB_OTG_HPTXSTS_PTXQTOP_2 0x04000000	/* Bit 2 */
  #define USB_OTG_HPTXSTS_PTXQTOP_3 0x08000000	/* Bit 3 */
  #define USB_OTG_HPTXSTS_PTXQTOP_4 0x10000000	/* Bit 4 */
  #define USB_OTG_HPTXSTS_PTXQTOP_5 0x20000000	/* Bit 5 */
  #define USB_OTG_HPTXSTS_PTXQTOP_6 0x40000000	/* Bit 6 */
  #define USB_OTG_HPTXSTS_PTXQTOP_7 0x80000000	/* Bit 7 */
#define TOFF_USBH_HAINT     0x0014		/* (RW) Host All Channels Interrupt Register */
  #define USB_OTG_HAINT_HAINT       0x0000FFFF	/* Channel interrupts */
#define TOFF_USBH_HAINTMSK  0x0018		/* (RW) Host All Channels Interrupt Mask */
  #define USB_OTG_HAINTMSK_HAINTM   0x0000FFFF	/* Channel interrupt mask */

/*
 *  USB HOST CHANNEL SPECIFIC
 */
#define TADR_USBH_HC_BASE        (USB_OTG_FS_PERIPH_BASE+USB_OTG_HOST_CHANNEL_BASE)
#define USBO_HOST_CHANNEL_REG_SIZE    0x20
#define TOFF_USBHC_HCCHAR   0x0000
  #define USB_OTG_HCCHAR_MPSIZ      0x000007FF	/* Maximum packet size */
  #define USB_OTG_HCCHAR_EPNUM      0x00007800	/* Endpoint number */
  #define USB_OTG_HCCHAR_EPNUM_0    0x00000800	/* Bit 0 */
  #define USB_OTG_HCCHAR_EPNUM_1    0x00001000	/* Bit 1 */
  #define USB_OTG_HCCHAR_EPNUM_2    0x00002000	/* Bit 2 */
  #define USB_OTG_HCCHAR_EPNUM_3    0x00004000	/* Bit 3 */
  #define USB_OTG_HCCHAR_EPDIR      0x00008000	/* Endpoint direction */
  #define USB_OTG_HCCHAR_LSDEV      0x00020000	/* Low-speed device */
  #define USB_OTG_HCCHAR_EPTYP      0x000C0000	/* Endpoint type */
  #define USB_OTG_HCCHAR_EPTYP_0    0x00040000	/* Bit 0 */
  #define USB_OTG_HCCHAR_EPTYP_1    0x00080000	/* Bit 1 */
  #define USB_OTG_HCCHAR_MC         0x00300000	/* Multi Count (MC) / Error Count (EC) */
  #define USB_OTG_HCCHAR_MC_0       0x00100000	/* Bit 0 */
  #define USB_OTG_HCCHAR_MC_1       0x00200000	/* Bit 1 */
  #define USB_OTG_HCCHAR_DAD        0x1FC00000	/* Device address */
  #define USB_OTG_HCCHAR_DAD_0      0x00400000	/* Bit 0 */
  #define USB_OTG_HCCHAR_DAD_1      0x00800000	/* Bit 1 */
  #define USB_OTG_HCCHAR_DAD_2      0x01000000	/* Bit 2 */
  #define USB_OTG_HCCHAR_DAD_3      0x02000000	/* Bit 3 */
  #define USB_OTG_HCCHAR_DAD_4      0x04000000	/* Bit 4 */
  #define USB_OTG_HCCHAR_DAD_5      0x08000000	/* Bit 5 */
  #define USB_OTG_HCCHAR_DAD_6      0x10000000	/* Bit 6 */
  #define USB_OTG_HCCHAR_ODDFRM     0x20000000	/* Odd frame */
  #define USB_OTG_HCCHAR_CHDIS      0x40000000	/* Channel disable */
  #define USB_OTG_HCCHAR_CHENA      0x80000000	/* Channel enable */
#define TOFF_USBHC_HCSPLT   0x0004
  #define USB_OTG_HCSPLT_PRTADDR    0x0000007F	/* Port address */
  #define USB_OTG_HCSPLT_PRTADDR_0  0x00000001	/* Bit 0 */
  #define USB_OTG_HCSPLT_PRTADDR_1  0x00000002	/* Bit 1 */
  #define USB_OTG_HCSPLT_PRTADDR_2  0x00000004	/* Bit 2 */
  #define USB_OTG_HCSPLT_PRTADDR_3  0x00000008	/* Bit 3 */
  #define USB_OTG_HCSPLT_PRTADDR_4  0x00000010	/* Bit 4 */
  #define USB_OTG_HCSPLT_PRTADDR_5  0x00000020	/* Bit 5 */
  #define USB_OTG_HCSPLT_PRTADDR_6  0x00000040	/* Bit 6 */
  #define USB_OTG_HCSPLT_HUBADDR    0x00003F80	/* Hub address */
  #define USB_OTG_HCSPLT_HUBADDR_0  0x00000080	/* Bit 0 */
  #define USB_OTG_HCSPLT_HUBADDR_1  0x00000100	/* Bit 1 */
  #define USB_OTG_HCSPLT_HUBADDR_2  0x00000200	/* Bit 2 */
  #define USB_OTG_HCSPLT_HUBADDR_3  0x00000400	/* Bit 3 */
  #define USB_OTG_HCSPLT_HUBADDR_4  0x00000800	/* Bit 4 */
  #define USB_OTG_HCSPLT_HUBADDR_5  0x00001000	/* Bit 5 */
  #define USB_OTG_HCSPLT_HUBADDR_6  0x00002000	/* Bit 6 */
  #define USB_OTG_HCSPLT_XACTPOS    0x0000C000	/* XACTPOS */
  #define USB_OTG_HCSPLT_XACTPOS_0  0x00004000	/* Bit 0 */
  #define USB_OTG_HCSPLT_XACTPOS_1  0x00008000	/* Bit 1 */
  #define USB_OTG_HCSPLT_COMPLSPLT  0x00010000	/* Do complete split */
  #define USB_OTG_HCSPLT_SPLITEN    0x80000000	/* Split enable */
#define TOFF_USBHC_HCINT    0x0008
  #define USB_OTG_HCINT_XFRC        0x00000001	/* Transfer completed */
  #define USB_OTG_HCINT_CHH         0x00000002	/* Channel halted */
  #define USB_OTG_HCINT_AHBERR      0x00000004	/* AHB error */
  #define USB_OTG_HCINT_STALL       0x00000008	/* STALL response received interrupt */
  #define USB_OTG_HCINT_NAK         0x00000010	/* NAK response received interrupt */
  #define USB_OTG_HCINT_ACK         0x00000020	/* ACK response received/transmitted interrupt */
  #define USB_OTG_HCINT_NYET        0x00000040	/* Response received interrupt */
  #define USB_OTG_HCINT_TXERR       0x00000080	/* Transaction error */
  #define USB_OTG_HCINT_BBERR       0x00000100	/* Babble error */
  #define USB_OTG_HCINT_FRMOR       0x00000200	/* Frame overrun */
  #define USB_OTG_HCINT_DTERR       0x00000400	/* Data toggle error */
#define TOFF_USBHC_HCINTMSK 0x000C
  #define USB_OTG_HCINTMSK_XFRCM    0x00000001	/* Transfer completed mask */
  #define USB_OTG_HCINTMSK_CHHM     0x00000002	/* Channel halted mask */
  #define USB_OTG_HCINTMSK_AHBERR   0x00000004	/* AHB error */
  #define USB_OTG_HCINTMSK_STALLM   0x00000008	/* STALL response received interrupt mask */
  #define USB_OTG_HCINTMSK_NAKM     0x00000010	/* NAK response received interrupt mask */
  #define USB_OTG_HCINTMSK_ACKM     0x00000020	/* ACK response received/transmitted interrupt mask */
  #define USB_OTG_HCINTMSK_NYET     0x00000040	/* response received interrupt mask */
  #define USB_OTG_HCINTMSK_TXERRM   0x00000080	/* Transaction error mask */
  #define USB_OTG_HCINTMSK_BBERRM   0x00000100	/* Babble error mask */
  #define USB_OTG_HCINTMSK_FRMORM   0x00000200	/* Frame overrun mask */
  #define USB_OTG_HCINTMSK_DTERRM   0x00000400	/* Data toggle error mask */
#define TOFF_USBHC_HCTSIZ   0x0010
  #define USB_OTG_HCTSIZ_XFRSIZ     0x0007FFFF	/* Transfer size */
  #define USB_OTG_HCTSIZ_PKTCNT     0x1FF80000	/* Packet count */
  #define USB_OTG_HCTSIZ_DOPING     0x80000000	/* Do PING */
  #define USB_OTG_HCTSIZ_DPID       0x60000000	/* Data PID */
  #define USB_OTG_HCTSIZ_DPID_0     0x20000000	/* Bit 0 */
  #define USB_OTG_HCTSIZ_DPID_1     0x40000000	/* Bit 1 */
#define TOFF_USBHC_HCDMA    0x0014
  #define USB_OTG_HCDMA_DMAADDR     0xFFFFFFFF	/* DMA address */

/*
 *  USB OTG HPRT
 */
#define TADR_USBO_HPRT0_BASE         (USB_OTG_FS_PERIPH_BASE+USB_OTG_HOST_PORT_BASE)
  #define USB_OTG_HPRT_PCSTS        0x00000001	/* Port connect status */
  #define USB_OTG_HPRT_PCDET        0x00000002	/* Port connect detected */
  #define USB_OTG_HPRT_PENA         0x00000004	/* Port enable */
  #define USB_OTG_HPRT_PENCHNG      0x00000008	/* Port enable/disable change */
  #define USB_OTG_HPRT_POCA         0x00000010	/* Port overcurrent active */
  #define USB_OTG_HPRT_POCCHNG      0x00000020	/* Port overcurrent change */
  #define USB_OTG_HPRT_PRES         0x00000040	/* Port resume */
  #define USB_OTG_HPRT_PSUSP        0x00000080	/* Port suspend */
  #define USB_OTG_HPRT_PRST         0x00000100	/* Port reset */
  #define USB_OTG_HPRT_PLSTS        0x00000C00	/* Port line status */
  #define USB_OTG_HPRT_PLSTS_0      0x00000400	/* Bit 0 */
  #define USB_OTG_HPRT_PLSTS_1      0x00000800	/* Bit 1 */
  #define USB_OTG_HPRT_PPWR         0x00001000	/* Port power */
  #define USB_OTG_HPRT_PTCTL        0x0001E000	/* Port test control */
  #define USB_OTG_HPRT_PTCTL_0      0x00002000	/* Bit 0 */
  #define USB_OTG_HPRT_PTCTL_1      0x00004000	/* Bit 1 */
  #define USB_OTG_HPRT_PTCTL_2      0x00008000	/* Bit 2 */
  #define USB_OTG_HPRT_PTCTL_3      0x00010000	/* Bit 3 */
  #define USB_OTG_HPRT_PSPD         0x00060000	/* Port speed */
  #define USB_OTG_HPRT_PSPD_0       0x00020000	/* Bit 0 */
  #define USB_OTG_HPRT_PSPD_1       0x00040000	/* Bit 1 */

/*
 *  PCGCCTL BIT DEFINITIONS
 */
#define USB_OTG_PCGCCTL_STOPCLK     0x00000001	/* SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK     0x00000002	/* Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP     0x00000010	/* Bit 1 */

#if defined(TOPPERS_STM32F769_DISCOVERY)
/*
 *  DSI CONTROLLER REGISTERS BASE ADDRESS
 */
#define TADR_DSI_BASE      (APB2PERIPH_BASE + 0x6C00)
#define TOFF_DSI_VR        0x0000	/* (R)  DSI Host Version Register */
#define TOFF_DSI_CR        0x0004	/* (RW) DSI Host Control Register */
  #define DSI_CR_EN            0x00000001	/* DSI Host power up and reset */
#define TOFF_DSI_CCR       0x0008	/* (RW) DSI HOST Clock Control Register */
  #define DSI_CCR_TXECKDIV     0x000000FF	/* TX Escape Clock Division */
  #define DSI_CCR_TXECKDIV0    0x00000001
  #define DSI_CCR_TXECKDIV1    0x00000002
  #define DSI_CCR_TXECKDIV2    0x00000004
  #define DSI_CCR_TXECKDIV3    0x00000008
  #define DSI_CCR_TXECKDIV4    0x00000010
  #define DSI_CCR_TXECKDIV5    0x00000020
  #define DSI_CCR_TXECKDIV6    0x00000040
  #define DSI_CCR_TXECKDIV7    0x00000080
  #define DSI_CCR_TOCKDIV      0x0000FF00	/* Timeout Clock Division */
  #define DSI_CCR_TOCKDIV0     0x00000100
  #define DSI_CCR_TOCKDIV1     0x00000200
  #define DSI_CCR_TOCKDIV2     0x00000400
  #define DSI_CCR_TOCKDIV3     0x00000800
  #define DSI_CCR_TOCKDIV4     0x00001000
  #define DSI_CCR_TOCKDIV5     0x00002000
  #define DSI_CCR_TOCKDIV6     0x00004000
  #define DSI_CCR_TOCKDIV7     0x00008000
#define TOFF_DSI_LVCIDR    0x000C	/* (RW) DSI Host LTDC VCID Register */
  #define DSI_LVCIDR_VCID      0x00000003	/* Virtual Channel ID */
  #define DSI_LVCIDR_VCID0     0x00000001
  #define DSI_LVCIDR_VCID1     0x00000002
#define TOFF_DSI_LCOLCR    0x0010	/* (RW) DSI Host LTDC Color Coding Register */
  #define DSI_LCOLCR_COLC      0x0000000F	/* Color Coding */
  #define DSI_LCOLCR_COLC0     0x00000001
  #define DSI_LCOLCR_COLC1     0x00000020
  #define DSI_LCOLCR_COLC2     0x00000040
  #define DSI_LCOLCR_COLC3     0x00000080
  #define DSI_LCOLCR_LPE       0x00000100	/* Loosly Packet Enable */
#define TOFF_DSI_LPCR      0x0014	/* (RW) DSI Host LTDC Polarity Configuration Register */
  #define DSI_LPCR_DEP         0x00000001	/* Data Enable Polarity */
  #define DSI_LPCR_VSP         0x00000002	/* VSYNC Polarity */
  #define DSI_LPCR_HSP         0x00000004	/* HSYNC Polarity */
#define TOFF_DSI_LPMCR     0x0018	/* (RW) DSI Host Low-Power Mode Configuration Register */
  #define DSI_LPMCR_VLPSIZE    0x000000FF	/* VACT Largest Packet Size */
  #define DSI_LPMCR_VLPSIZE0   0x00000001
  #define DSI_LPMCR_VLPSIZE1   0x00000002
  #define DSI_LPMCR_VLPSIZE2   0x00000004
  #define DSI_LPMCR_VLPSIZE3   0x00000008
  #define DSI_LPMCR_VLPSIZE4   0x00000010
  #define DSI_LPMCR_VLPSIZE5   0x00000020
  #define DSI_LPMCR_VLPSIZE6   0x00000040
  #define DSI_LPMCR_VLPSIZE7   0x00000080
  #define DSI_LPMCR_LPSIZE     0x00FF0000	/* Largest Packet Size */
  #define DSI_LPMCR_LPSIZE0    0x00010000
  #define DSI_LPMCR_LPSIZE1    0x00020000
  #define DSI_LPMCR_LPSIZE2    0x00040000
  #define DSI_LPMCR_LPSIZE3    0x00080000
  #define DSI_LPMCR_LPSIZE4    0x00100000
  #define DSI_LPMCR_LPSIZE5    0x00200000
  #define DSI_LPMCR_LPSIZE6    0x00400000
  #define DSI_LPMCR_LPSIZE7    0x00800000
#define TOFF_DSI_PCR       0x002C	/* (RW) DSI Host Protocol Configuration Register */
  #define DSI_PCR_ETTXE        0x00000001	/* EoTp Transmission Enable */
  #define DSI_PCR_ETRXE        0x00000002	/* EoTp Reception Enable */
  #define DSI_PCR_BTAE         0x00000004	/* Bus Turn Around Enable */
  #define DSI_PCR_ECCRXE       0x00000008	/* ECC Reception Enable */
  #define DSI_PCR_CRCRXE       0x00000010	/* CRC Reception Enable */
#define TOFF_DSI_GVCIDR    0x0030	/* (RW) DSI Host Generic VCID Register */
  #define DSI_GVCIDR_VCID      0x00000003	/* Virtual Channel ID */
  #define DSI_GVCIDR_VCID0     0x00000001
  #define DSI_GVCIDR_VCID1     0x00000002
#define TOFF_DSI_MCR       0x0034	/* (RW) DSI Host Mode Configuration Register */
  #define DSI_MCR_CMDM         0x00000001	/* Command Mode */
#define TOFF_DSI_VMCR      0x0038	/* (RW) DSI Host Video Mode Configuration Register */
  #define DSI_VMCR_VMT         0x00000003	/* Video Mode Type */
  #define DSI_VMCR_VMT0        0x00000001
  #define DSI_VMCR_VMT1        0x00000002
  #define DSI_VMCR_LPVSAE      0x00000100	/* Low-Power Vertical Sync Active Enable */
  #define DSI_VMCR_LPVBPE      0x00000200	/* Low-power Vertical Back-Porch Enable */
  #define DSI_VMCR_LPVFPE      0x00000400	/* Low-power Vertical Front-porch Enable */
  #define DSI_VMCR_LPVAE       0x00000800	/* Low-Power Vertical Active Enable */
  #define DSI_VMCR_LPHBPE      0x00001000	/* Low-Power Horizontal Back-Porch Enable */
  #define DSI_VMCR_LPHFPE      0x00002000	/* Low-Power Horizontal Front-Porch Enable */
  #define DSI_VMCR_FBTAAE      0x00004000	/* Frame Bus-Turn-Around Acknowledge Enable */
  #define DSI_VMCR_LPCE        0x00008000	/* Low-Power Command Enable */
  #define DSI_VMCR_PGE         0x00010000	/* Pattern Generator Enable */
  #define DSI_VMCR_PGM         0x00100000	/* Pattern Generator Mode */
  #define DSI_VMCR_PGO         0x01000000	/* Pattern Generator Orientation */
#define TOFF_DSI_VPCR      0x003C	/* (RW) DSI Host Video Packet Configuration Register */
  #define DSI_VPCR_VPSIZE      0x00003FFF	/* Video Packet Size */
  #define DSI_VPCR_VPSIZE0     0x00000001
  #define DSI_VPCR_VPSIZE1     0x00000002
  #define DSI_VPCR_VPSIZE2     0x00000004
  #define DSI_VPCR_VPSIZE3     0x00000008
  #define DSI_VPCR_VPSIZE4     0x00000010
  #define DSI_VPCR_VPSIZE5     0x00000020
  #define DSI_VPCR_VPSIZE6     0x00000040
  #define DSI_VPCR_VPSIZE7     0x00000080
  #define DSI_VPCR_VPSIZE8     0x00000100
  #define DSI_VPCR_VPSIZE9     0x00000200
  #define DSI_VPCR_VPSIZE10    0x00000400
  #define DSI_VPCR_VPSIZE11    0x00000800
  #define DSI_VPCR_VPSIZE12    0x00001000
  #define DSI_VPCR_VPSIZE13    0x00002000
#define TOFF_DSI_VCCR      0x0040	/* (RW) DSI Host Video Chunks Configuration Register */
  #define DSI_VCCR_NUMC        0x00001FFF	/* Number of Chunks */
  #define DSI_VCCR_NUMC0       0x00000001
  #define DSI_VCCR_NUMC1       0x00000002
  #define DSI_VCCR_NUMC2       0x00000004
  #define DSI_VCCR_NUMC3       0x00000008
  #define DSI_VCCR_NUMC4       0x00000010
  #define DSI_VCCR_NUMC5       0x00000020
  #define DSI_VCCR_NUMC6       0x00000040
  #define DSI_VCCR_NUMC7       0x00000080
  #define DSI_VCCR_NUMC8       0x00000100
  #define DSI_VCCR_NUMC9       0x00000200
  #define DSI_VCCR_NUMC10      0x00000400
  #define DSI_VCCR_NUMC11      0x00000800
  #define DSI_VCCR_NUMC12      0x00001000
#define TOFF_DSI_VNPCR     0x0044	/* (RW) DSI Host Video Null Packet Configuration Register */
  #define DSI_VNPCR_NPSIZE     0x00001FFF	/* Null Packet Size */
  #define DSI_VNPCR_NPSIZE0    0x00000001
  #define DSI_VNPCR_NPSIZE1    0x00000002
  #define DSI_VNPCR_NPSIZE2    0x00000004
  #define DSI_VNPCR_NPSIZE3    0x00000008
  #define DSI_VNPCR_NPSIZE4    0x00000010
  #define DSI_VNPCR_NPSIZE5    0x00000020
  #define DSI_VNPCR_NPSIZE6    0x00000040
  #define DSI_VNPCR_NPSIZE7    0x00000080
  #define DSI_VNPCR_NPSIZE8    0x00000100
  #define DSI_VNPCR_NPSIZE9    0x00000200
  #define DSI_VNPCR_NPSIZE10   0x00000400
  #define DSI_VNPCR_NPSIZE11   0x00000800
  #define DSI_VNPCR_NPSIZE12   0x00001000
#define TOFF_DSI_VHSACR    0x0048	/* (RW) DSI Host Video HSA Configuration Register */
  #define DSI_VHSACR_HSA       0x00000FFF	/* Horizontal Synchronism Active duration */
  #define DSI_VHSACR_HSA0      0x00000001
  #define DSI_VHSACR_HSA1      0x00000002
  #define DSI_VHSACR_HSA2      0x00000004
  #define DSI_VHSACR_HSA3      0x00000008
  #define DSI_VHSACR_HSA4      0x00000010
  #define DSI_VHSACR_HSA5      0x00000020
  #define DSI_VHSACR_HSA6      0x00000040
  #define DSI_VHSACR_HSA7      0x00000080
  #define DSI_VHSACR_HSA8      0x00000100
  #define DSI_VHSACR_HSA9      0x00000200
  #define DSI_VHSACR_HSA10     0x00000400
  #define DSI_VHSACR_HSA11     0x00000800
#define TOFF_DSI_VHBPCR    0x004C	/* (RW) DSI Host Video HBP Configuration Register */
  #define DSI_VHBPCR_HBP       0x00000FFF	/* Horizontal Back-Porch duration */
  #define DSI_VHBPCR_HBP0      0x00000001
  #define DSI_VHBPCR_HBP1      0x00000002
  #define DSI_VHBPCR_HBP2      0x00000004
  #define DSI_VHBPCR_HBP3      0x00000008
  #define DSI_VHBPCR_HBP4      0x00000010
  #define DSI_VHBPCR_HBP5      0x00000020
  #define DSI_VHBPCR_HBP6      0x00000040
  #define DSI_VHBPCR_HBP7      0x00000080
  #define DSI_VHBPCR_HBP8      0x00000100
  #define DSI_VHBPCR_HBP9      0x00000200
  #define DSI_VHBPCR_HBP10     0x00000400
  #define DSI_VHBPCR_HBP11     0x00000800
#define TOFF_DSI_VLCR      0x0050	/* (RW) DSI Host Video Line Configuration Register */
  #define DSI_VLCR_HLINE       0x00007FFF	/* Horizontal Line duration */
  #define DSI_VLCR_HLINE0      0x00000001
  #define DSI_VLCR_HLINE1      0x00000002
  #define DSI_VLCR_HLINE2      0x00000004
  #define DSI_VLCR_HLINE3      0x00000008
  #define DSI_VLCR_HLINE4      0x00000010
  #define DSI_VLCR_HLINE5      0x00000020
  #define DSI_VLCR_HLINE6      0x00000040
  #define DSI_VLCR_HLINE7      0x00000080
  #define DSI_VLCR_HLINE8      0x00000100
  #define DSI_VLCR_HLINE9      0x00000200
  #define DSI_VLCR_HLINE10     0x00000400
  #define DSI_VLCR_HLINE11     0x00000800
  #define DSI_VLCR_HLINE12     0x00001000
  #define DSI_VLCR_HLINE13     0x00002000
  #define DSI_VLCR_HLINE14     0x00004000
#define TOFF_DSI_VVSACR    0x0054	/* (RW) DSI Host Video VSA Configuration Register */
  #define DSI_VVSACR_VSA       0x000003FF	/* Vertical Synchronism Active duration */
  #define DSI_VVSACR_VSA0      0x00000001
  #define DSI_VVSACR_VSA1      0x00000002
  #define DSI_VVSACR_VSA2      0x00000004
  #define DSI_VVSACR_VSA3      0x00000008
  #define DSI_VVSACR_VSA4      0x00000010
  #define DSI_VVSACR_VSA5      0x00000020
  #define DSI_VVSACR_VSA6      0x00000040
  #define DSI_VVSACR_VSA7      0x00000080
  #define DSI_VVSACR_VSA8      0x00000100
  #define DSI_VVSACR_VSA9      0x00000200
#define TOFF_DSI_VVBPCR    0x0058	/* (RW) DSI Host Video VBP Configuration Register */
  #define DSI_VVBPCR_VBP       0x000003FF	/* Vertical Back-Porch duration */
  #define DSI_VVBPCR_VBP0      0x00000001
  #define DSI_VVBPCR_VBP1      0x00000002
  #define DSI_VVBPCR_VBP2      0x00000004
  #define DSI_VVBPCR_VBP3      0x00000008
  #define DSI_VVBPCR_VBP4      0x00000010
  #define DSI_VVBPCR_VBP5      0x00000020
  #define DSI_VVBPCR_VBP6      0x00000040
  #define DSI_VVBPCR_VBP7      0x00000080
  #define DSI_VVBPCR_VBP8      0x00000100
  #define DSI_VVBPCR_VBP9      0x00000200
#define TOFF_DSI_VVFPCR    0x005C	/* (RW) DSI Host Video VFP Configuration Register */
  #define DSI_VVFPCR_VFP       0x000003FF	/* Vertical Front-Porch duration */
  #define DSI_VVFPCR_VFP0      0x00000001
  #define DSI_VVFPCR_VFP1      0x00000002
  #define DSI_VVFPCR_VFP2      0x00000004
  #define DSI_VVFPCR_VFP3      0x00000008
  #define DSI_VVFPCR_VFP4      0x00000010
  #define DSI_VVFPCR_VFP5      0x00000020
  #define DSI_VVFPCR_VFP6      0x00000040
  #define DSI_VVFPCR_VFP7      0x00000080
  #define DSI_VVFPCR_VFP8      0x00000100
  #define DSI_VVFPCR_VFP9      0x00000200
#define TOFF_DSI_VVACR     0x0060	/* (RW) DSI Host Video VA Configuration Register */
  #define DSI_VVACR_VA         0x00003FFF	/* Vertical Active duration */
  #define DSI_VVACR_VA0        0x00000001
  #define DSI_VVACR_VA1        0x00000002
  #define DSI_VVACR_VA2        0x00000004
  #define DSI_VVACR_VA3        0x00000008
  #define DSI_VVACR_VA4        0x00000010
  #define DSI_VVACR_VA5        0x00000020
  #define DSI_VVACR_VA6        0x00000040
  #define DSI_VVACR_VA7        0x00000080
  #define DSI_VVACR_VA8        0x00000100
  #define DSI_VVACR_VA9        0x00000200
  #define DSI_VVACR_VA10       0x00000400
  #define DSI_VVACR_VA11       0x00000800
  #define DSI_VVACR_VA12       0x00001000
  #define DSI_VVACR_VA13       0x00002000
#define TOFF_DSI_LCCR      0x0064	/* (RW) DSI Host LTDC Command Configuration Register */
  #define DSI_LCCR_CMDSIZE     0x0000FFFF	/* Command Size */
  #define DSI_LCCR_CMDSIZE0    0x00000001
  #define DSI_LCCR_CMDSIZE1    0x00000002
  #define DSI_LCCR_CMDSIZE2    0x00000004
  #define DSI_LCCR_CMDSIZE3    0x00000008
  #define DSI_LCCR_CMDSIZE4    0x00000010
  #define DSI_LCCR_CMDSIZE5    0x00000020
  #define DSI_LCCR_CMDSIZE6    0x00000040
  #define DSI_LCCR_CMDSIZE7    0x00000080
  #define DSI_LCCR_CMDSIZE8    0x00000100
  #define DSI_LCCR_CMDSIZE9    0x00000200
  #define DSI_LCCR_CMDSIZE10   0x00000400
  #define DSI_LCCR_CMDSIZE11   0x00000800
  #define DSI_LCCR_CMDSIZE12   0x00001000
  #define DSI_LCCR_CMDSIZE13   0x00002000
  #define DSI_LCCR_CMDSIZE14   0x00004000
  #define DSI_LCCR_CMDSIZE15   0x00008000
#define TOFF_DSI_CMCR      0x0068	/* (RW) DSI Host Command Mode Configuration Register */
  #define DSI_CMCR_TEARE       0x00000001	/* Tearing Effect Acknowledge Request Enable */
  #define DSI_CMCR_ARE         0x00000002	/* Acknowledge Request Enable */
  #define DSI_CMCR_GSW0TX      0x00000100	/* Generic Short Write Zero parameters Transmission */
  #define DSI_CMCR_GSW1TX      0x00000200	/* Generic Short Write One parameters Transmission */
  #define DSI_CMCR_GSW2TX      0x00000400	/* Generic Short Write Two parameters Transmission */
  #define DSI_CMCR_GSR0TX      0x00000800	/* Generic Short Read Zero parameters Transmission */
  #define DSI_CMCR_GSR1TX      0x00001000	/* Generic Short Read One parameters Transmission */
  #define DSI_CMCR_GSR2TX      0x00002000	/* Generic Short Read Two parameters Transmission */
  #define DSI_CMCR_GLWTX       0x00004000	/* Generic Long Write Transmission */
  #define DSI_CMCR_DSW0TX      0x00010000	/* DCS Short Write Zero parameter Transmission */
  #define DSI_CMCR_DSW1TX      0x00020000	/* DCS Short Read One parameter Transmission */
  #define DSI_CMCR_DSR0TX      0x00040000	/* DCS Short Read Zero parameter Transmission */
  #define DSI_CMCR_DLWTX       0x00080000	/* DCS Long Write Transmission */
  #define DSI_CMCR_MRDPS       0x01000000	/* Maximum Read Packet Size */
#define TOFF_DSI_GHCR      0x006C	/* (RW) DSI Host Generic Header Configuration Register */
  #define DSI_GHCR_DT          0x0000003F	/* Type */
  #define DSI_GHCR_DT0         0x00000001
  #define DSI_GHCR_DT1         0x00000002
  #define DSI_GHCR_DT2         0x00000004
  #define DSI_GHCR_DT3         0x00000008
  #define DSI_GHCR_DT4         0x00000010
  #define DSI_GHCR_DT5         0x00000020
  #define DSI_GHCR_VCID        0x000000C0	/* Channel */
  #define DSI_GHCR_VCID0       0x00000040
  #define DSI_GHCR_VCID1       0x00000080
  #define DSI_GHCR_WCLSB       0x0000FF00	/* WordCount LSB */
  #define DSI_GHCR_WCLSB0      0x00000100
  #define DSI_GHCR_WCLSB1      0x00000200
  #define DSI_GHCR_WCLSB2      0x00000400
  #define DSI_GHCR_WCLSB3      0x00000800
  #define DSI_GHCR_WCLSB4      0x00001000
  #define DSI_GHCR_WCLSB5      0x00002000
  #define DSI_GHCR_WCLSB6      0x00004000
  #define DSI_GHCR_WCLSB7      0x00008000
  #define DSI_GHCR_WCMSB       0x00FF0000	/* WordCount MSB */
  #define DSI_GHCR_WCMSB0      0x00010000
  #define DSI_GHCR_WCMSB1      0x00020000
  #define DSI_GHCR_WCMSB2      0x00040000
  #define DSI_GHCR_WCMSB3      0x00080000
  #define DSI_GHCR_WCMSB4      0x00100000
  #define DSI_GHCR_WCMSB5      0x00200000
  #define DSI_GHCR_WCMSB6      0x00400000
  #define DSI_GHCR_WCMSB7      0x00800000
#define TOFF_DSI_GPDR      0x0070	/* (RW) DSI Host Generic Payload Data Register */
  #define DSI_GPDR_DATA1       0x000000FF	/* Payload Byte 1 */
  #define DSI_GPDR_DATA1_0     0x00000001
  #define DSI_GPDR_DATA1_1     0x00000002
  #define DSI_GPDR_DATA1_2     0x00000004
  #define DSI_GPDR_DATA1_3     0x00000008
  #define DSI_GPDR_DATA1_4     0x00000010
  #define DSI_GPDR_DATA1_5     0x00000020
  #define DSI_GPDR_DATA1_6     0x00000040
  #define DSI_GPDR_DATA1_7     0x00000080
  #define DSI_GPDR_DATA2       0x0000FF00	/* Payload Byte 2 */
  #define DSI_GPDR_DATA2_0     0x00000100
  #define DSI_GPDR_DATA2_1     0x00000200
  #define DSI_GPDR_DATA2_2     0x00000400
  #define DSI_GPDR_DATA2_3     0x00000800
  #define DSI_GPDR_DATA2_4     0x00001000
  #define DSI_GPDR_DATA2_5     0x00002000
  #define DSI_GPDR_DATA2_6     0x00004000
  #define DSI_GPDR_DATA2_7     0x00008000
  #define DSI_GPDR_DATA3       0x00FF0000	/* Payload Byte 3 */
  #define DSI_GPDR_DATA3_0     0x00010000
  #define DSI_GPDR_DATA3_1     0x00020000
  #define DSI_GPDR_DATA3_2     0x00040000
  #define DSI_GPDR_DATA3_3     0x00080000
  #define DSI_GPDR_DATA3_4     0x00100000
  #define DSI_GPDR_DATA3_5     0x00200000
  #define DSI_GPDR_DATA3_6     0x00400000
  #define DSI_GPDR_DATA3_7     0x00800000
  #define DSI_GPDR_DATA4       0xFF000000	/* Payload Byte 4 */
  #define DSI_GPDR_DATA4_0     0x01000000
  #define DSI_GPDR_DATA4_1     0x02000000
  #define DSI_GPDR_DATA4_2     0x04000000
  #define DSI_GPDR_DATA4_3     0x08000000
  #define DSI_GPDR_DATA4_4     0x10000000
  #define DSI_GPDR_DATA4_5     0x20000000
  #define DSI_GPDR_DATA4_6     0x40000000
  #define DSI_GPDR_DATA4_7     0x80000000
#define TOFF_DSI_GPSR      0x0074	/* (RW) DSI Host Generic Packet Status Register */
  #define DSI_GPSR_CMDFE       0x00000001	/* Command FIFO Empty */
  #define DSI_GPSR_CMDFF       0x00000002	/* Command FIFO Full */
  #define DSI_GPSR_PWRFE       0x00000004	/* Payload Write FIFO Empty */
  #define DSI_GPSR_PWRFF       0x00000008	/* Payload Write FIFO Full */
  #define DSI_GPSR_PRDFE       0x00000010	/* Payload Read FIFO Empty */
  #define DSI_GPSR_PRDFF       0x00000020	/* Payload Read FIFO Full */
  #define DSI_GPSR_RCB         0x00000040	/* Read Command Busy */
#define TOFF_DSI_TCCR      0x0078	/* (RW) DSI Host Timeout Counter Configuration Register */
#define TOFF_DSI_TCCR0     0x0078	/* (RW) DSI Host Timeout Counter Configuration Register0 */
  #define DSI_TCCR0_LPRX_TOCNT    0x0000FFFF	/* Low-power Reception Timeout Counter */
  #define DSI_TCCR0_LPRX_TOCNT0   0x00000001
  #define DSI_TCCR0_LPRX_TOCNT1   0x00000002
  #define DSI_TCCR0_LPRX_TOCNT2   0x00000004
  #define DSI_TCCR0_LPRX_TOCNT3   0x00000008
  #define DSI_TCCR0_LPRX_TOCNT4   0x00000010
  #define DSI_TCCR0_LPRX_TOCNT5   0x00000020
  #define DSI_TCCR0_LPRX_TOCNT6   0x00000040
  #define DSI_TCCR0_LPRX_TOCNT7   0x00000080
  #define DSI_TCCR0_LPRX_TOCNT8   0x00000100
  #define DSI_TCCR0_LPRX_TOCNT9   0x00000200
  #define DSI_TCCR0_LPRX_TOCNT10  0x00000400
  #define DSI_TCCR0_LPRX_TOCNT11  0x00000800
  #define DSI_TCCR0_LPRX_TOCNT12  0x00001000
  #define DSI_TCCR0_LPRX_TOCNT13  0x00002000
  #define DSI_TCCR0_LPRX_TOCNT14  0x00004000
  #define DSI_TCCR0_LPRX_TOCNT15  0x00008000
  #define DSI_TCCR0_HSTX_TOCNT    0xFFFF0000	/* High-Speed Transmission Timeout Counter */
  #define DSI_TCCR0_HSTX_TOCNT0   0x00010000
  #define DSI_TCCR0_HSTX_TOCNT1   0x00020000
  #define DSI_TCCR0_HSTX_TOCNT2   0x00040000
  #define DSI_TCCR0_HSTX_TOCNT3   0x00080000
  #define DSI_TCCR0_HSTX_TOCNT4   0x00100000
  #define DSI_TCCR0_HSTX_TOCNT5   0x00200000
  #define DSI_TCCR0_HSTX_TOCNT6   0x00400000
  #define DSI_TCCR0_HSTX_TOCNT7   0x00800000
  #define DSI_TCCR0_HSTX_TOCNT8   0x01000000
  #define DSI_TCCR0_HSTX_TOCNT9   0x02000000
  #define DSI_TCCR0_HSTX_TOCNT10  0x04000000
  #define DSI_TCCR0_HSTX_TOCNT11  0x08000000
  #define DSI_TCCR0_HSTX_TOCNT12  0x10000000
  #define DSI_TCCR0_HSTX_TOCNT13  0x20000000
  #define DSI_TCCR0_HSTX_TOCNT14  0x40000000
  #define DSI_TCCR0_HSTX_TOCNT15  0x80000000
#define TOFF_DSI_TCCR1     0x007C	/* (RW) DSI Host Timeout Counter Configuration Register1 */
  #define DSI_TCCR1_HSRD_TOCNT    0x0000FFFF	/* High-Speed Read Timeout Counter */
  #define DSI_TCCR1_HSRD_TOCNT0   0x00000001
  #define DSI_TCCR1_HSRD_TOCNT1   0x00000002
  #define DSI_TCCR1_HSRD_TOCNT2   0x00000004
  #define DSI_TCCR1_HSRD_TOCNT3   0x00000008
  #define DSI_TCCR1_HSRD_TOCNT4   0x00000010
  #define DSI_TCCR1_HSRD_TOCNT5   0x00000020
  #define DSI_TCCR1_HSRD_TOCNT6   0x00000040
  #define DSI_TCCR1_HSRD_TOCNT7   0x00000080
  #define DSI_TCCR1_HSRD_TOCNT8   0x00000100
  #define DSI_TCCR1_HSRD_TOCNT9   0x00000200
  #define DSI_TCCR1_HSRD_TOCNT10  0x00000400
  #define DSI_TCCR1_HSRD_TOCNT11  0x00000800
  #define DSI_TCCR1_HSRD_TOCNT12  0x00001000
  #define DSI_TCCR1_HSRD_TOCNT13  0x00002000
  #define DSI_TCCR1_HSRD_TOCNT14  0x00004000
  #define DSI_TCCR1_HSRD_TOCNT15  0x00008000
#define TOFF_DSI_TCCR2     0x0080	/* (RW) DSI Host Timeout Counter Configuration Register2 */
  #define DSI_TCCR2_LPRD_TOCNT    0x0000FFFF	/* Low-Power Read Timeout Counter */
  #define DSI_TCCR2_LPRD_TOCNT0   0x00000001
  #define DSI_TCCR2_LPRD_TOCNT1   0x00000002
  #define DSI_TCCR2_LPRD_TOCNT2   0x00000004
  #define DSI_TCCR2_LPRD_TOCNT3   0x00000008
  #define DSI_TCCR2_LPRD_TOCNT4   0x00000010
  #define DSI_TCCR2_LPRD_TOCNT5   0x00000020
  #define DSI_TCCR2_LPRD_TOCNT6   0x00000040
  #define DSI_TCCR2_LPRD_TOCNT7   0x00000080
  #define DSI_TCCR2_LPRD_TOCNT8   0x00000100
  #define DSI_TCCR2_LPRD_TOCNT9   0x00000200
  #define DSI_TCCR2_LPRD_TOCNT10  0x00000400
  #define DSI_TCCR2_LPRD_TOCNT11  0x00000800
  #define DSI_TCCR2_LPRD_TOCNT12  0x00001000
  #define DSI_TCCR2_LPRD_TOCNT13  0x00002000
  #define DSI_TCCR2_LPRD_TOCNT14  0x00004000
  #define DSI_TCCR2_LPRD_TOCNT15  0x00008000
#define TOFF_DSI_TCCR3     0x0084	/* (RW) DSI Host Timeout Counter Configuration Register3 */
  #define DSI_TCCR3_HSWR_TOCNT    0x0000FFFF	/* High-Speed Write Timeout Counter */
  #define DSI_TCCR3_HSWR_TOCNT0   0x00000001
  #define DSI_TCCR3_HSWR_TOCNT1   0x00000002
  #define DSI_TCCR3_HSWR_TOCNT2   0x00000004
  #define DSI_TCCR3_HSWR_TOCNT3   0x00000008
  #define DSI_TCCR3_HSWR_TOCNT4   0x00000010
  #define DSI_TCCR3_HSWR_TOCNT5   0x00000020
  #define DSI_TCCR3_HSWR_TOCNT6   0x00000040
  #define DSI_TCCR3_HSWR_TOCNT7   0x00000080
  #define DSI_TCCR3_HSWR_TOCNT8   0x00000100
  #define DSI_TCCR3_HSWR_TOCNT9   0x00000200
  #define DSI_TCCR3_HSWR_TOCNT10  0x00000400
  #define DSI_TCCR3_HSWR_TOCNT11  0x00000800
  #define DSI_TCCR3_HSWR_TOCNT12  0x00001000
  #define DSI_TCCR3_HSWR_TOCNT13  0x00002000
  #define DSI_TCCR3_HSWR_TOCNT14  0x00004000
  #define DSI_TCCR3_HSWR_TOCNT15  0x00008000
  #define DSI_TCCR3_PM            0x01000000	/* Presp Mode */
#define TOFF_DSI_TCCR4     0x0088	/* (RW) DSI Host Timeout Counter Configuration Register4 */
  #define DSI_TCCR4_LPWR_TOCNT    0x0000FFFF	/* Low-Power Write Timeout Counter */
  #define DSI_TCCR4_LPWR_TOCNT0   0x00000001
  #define DSI_TCCR4_LPWR_TOCNT1   0x00000002
  #define DSI_TCCR4_LPWR_TOCNT2   0x00000004
  #define DSI_TCCR4_LPWR_TOCNT3   0x00000008
  #define DSI_TCCR4_LPWR_TOCNT4   0x00000010
  #define DSI_TCCR4_LPWR_TOCNT5   0x00000020
  #define DSI_TCCR4_LPWR_TOCNT6   0x00000040
  #define DSI_TCCR4_LPWR_TOCNT7   0x00000080
  #define DSI_TCCR4_LPWR_TOCNT8   0x00000100
  #define DSI_TCCR4_LPWR_TOCNT9   0x00000200
  #define DSI_TCCR4_LPWR_TOCNT10  0x00000400
  #define DSI_TCCR4_LPWR_TOCNT11  0x00000800
  #define DSI_TCCR4_LPWR_TOCNT12  0x00001000
  #define DSI_TCCR4_LPWR_TOCNT13  0x00002000
  #define DSI_TCCR4_LPWR_TOCNT14  0x00004000
  #define DSI_TCCR4_LPWR_TOCNT15  0x00008000
#define TOFF_DSI_TCCR5     0x008C	/* (RW) DSI Host Timeout Counter Configuration Register5 */
  #define DSI_TCCR5_BTA_TOCNT     0x0000FFFF	/* Bus-Turn-Around Timeout Counter */
  #define DSI_TCCR5_BTA_TOCNT0    0x00000001
  #define DSI_TCCR5_BTA_TOCNT1    0x00000002
  #define DSI_TCCR5_BTA_TOCNT2    0x00000004
  #define DSI_TCCR5_BTA_TOCNT3    0x00000008
  #define DSI_TCCR5_BTA_TOCNT4    0x00000010
  #define DSI_TCCR5_BTA_TOCNT5    0x00000020
  #define DSI_TCCR5_BTA_TOCNT6    0x00000040
  #define DSI_TCCR5_BTA_TOCNT7    0x00000080
  #define DSI_TCCR5_BTA_TOCNT8    0x00000100
  #define DSI_TCCR5_BTA_TOCNT9    0x00000200
  #define DSI_TCCR5_BTA_TOCNT10   0x00000400
  #define DSI_TCCR5_BTA_TOCNT11   0x00000800
  #define DSI_TCCR5_BTA_TOCNT12   0x00001000
  #define DSI_TCCR5_BTA_TOCNT13   0x00002000
  #define DSI_TCCR5_BTA_TOCNT14   0x00004000
  #define DSI_TCCR5_BTA_TOCNT15   0x00008000
#define TOFF_DSI_TDCR      0x0090	/* (RW) DSI Host 3D Configuration Register */
  #define DSI_TDCR_3DM         0x00000003	/* 3D Mode */
  #define DSI_TDCR_3DM0        0x00000001
  #define DSI_TDCR_3DM1        0x00000002
  #define DSI_TDCR_3DF         0x0000000C	/* 3D Format */
  #define DSI_TDCR_3DF0        0x00000004
  #define DSI_TDCR_3DF1        0x00000008
  #define DSI_TDCR_SVS         0x00000010	/* Second VSYNC */
  #define DSI_TDCR_RF          0x00000020	/* Right First */
  #define DSI_TDCR_S3DC        0x00010000	/* Send 3D Control */
#define TOFF_DSI_CLCR      0x0094	/* (RW) DSI Host Clock Lane Configuration Register */
  #define DSI_CLCR_DPCC        0x00000001	/* D-PHY Clock Control */
  #define DSI_CLCR_ACR         0x00000002	/* Automatic Clocklane Control */
#define TOFF_DSI_CLTCR     0x0098	/* (RW) DSI Host Clock Lane Timer Configuration Register */
  #define DSI_CLTCR_LP2HS_TIME  0x000003FF	/* Low-Power to High-Speed Time */
  #define DSI_CLTCR_LP2HS_TIME0 0x00000001
  #define DSI_CLTCR_LP2HS_TIME1 0x00000002
  #define DSI_CLTCR_LP2HS_TIME2 0x00000004
  #define DSI_CLTCR_LP2HS_TIME3 0x00000008
  #define DSI_CLTCR_LP2HS_TIME4 0x00000010
  #define DSI_CLTCR_LP2HS_TIME5 0x00000020
  #define DSI_CLTCR_LP2HS_TIME6 0x00000040
  #define DSI_CLTCR_LP2HS_TIME7 0x00000080
  #define DSI_CLTCR_LP2HS_TIME8 0x00000100
  #define DSI_CLTCR_LP2HS_TIME9 0x00000200
  #define DSI_CLTCR_HS2LP_TIME  0x03FF0000	/* High-Speed to Low-Power Time */
  #define DSI_CLTCR_HS2LP_TIME0 0x00010000
  #define DSI_CLTCR_HS2LP_TIME1 0x00020000
  #define DSI_CLTCR_HS2LP_TIME2 0x00040000
  #define DSI_CLTCR_HS2LP_TIME3 0x00080000
  #define DSI_CLTCR_HS2LP_TIME4 0x00100000
  #define DSI_CLTCR_HS2LP_TIME5 0x00200000
  #define DSI_CLTCR_HS2LP_TIME6 0x00400000
  #define DSI_CLTCR_HS2LP_TIME7 0x00800000
  #define DSI_CLTCR_HS2LP_TIME8 0x01000000
  #define DSI_CLTCR_HS2LP_TIME9 0x02000000
#define TOFF_DSI_DLTCR     0x009C	/* (RW) DSI Host Data Lane Timer Configuration Register */
  #define DSI_DLTCR_MRD_TIME    0x00007FFF	/* Maximum Read Time */
  #define DSI_DLTCR_MRD_TIME0   0x00000001
  #define DSI_DLTCR_MRD_TIME1   0x00000002
  #define DSI_DLTCR_MRD_TIME2   0x00000004
  #define DSI_DLTCR_MRD_TIME3   0x00000008
  #define DSI_DLTCR_MRD_TIME4   0x00000010
  #define DSI_DLTCR_MRD_TIME5   0x00000020
  #define DSI_DLTCR_MRD_TIME6   0x00000040
  #define DSI_DLTCR_MRD_TIME7   0x00000080
  #define DSI_DLTCR_MRD_TIME8   0x00000100
  #define DSI_DLTCR_MRD_TIME9   0x00000200
  #define DSI_DLTCR_MRD_TIME10  0x00000400
  #define DSI_DLTCR_MRD_TIME11  0x00000800
  #define DSI_DLTCR_MRD_TIME12  0x00001000
  #define DSI_DLTCR_MRD_TIME13  0x00002000
  #define DSI_DLTCR_MRD_TIME14  0x00004000
  #define DSI_DLTCR_LP2HS_TIME  0x00FF0000	/* Low-Power To High-Speed Time */
  #define DSI_DLTCR_LP2HS_TIME0 0x00010000
  #define DSI_DLTCR_LP2HS_TIME1 0x00020000
  #define DSI_DLTCR_LP2HS_TIME2 0x00040000
  #define DSI_DLTCR_LP2HS_TIME3 0x00080000
  #define DSI_DLTCR_LP2HS_TIME4 0x00100000
  #define DSI_DLTCR_LP2HS_TIME5 0x00200000
  #define DSI_DLTCR_LP2HS_TIME6 0x00400000
  #define DSI_DLTCR_LP2HS_TIME7 0x00800000
  #define DSI_DLTCR_HS2LP_TIME  0xFF000000	/* High-Speed To Low-Power Time */
  #define DSI_DLTCR_HS2LP_TIME0 0x01000000
  #define DSI_DLTCR_HS2LP_TIME1 0x02000000
  #define DSI_DLTCR_HS2LP_TIME2 0x04000000
  #define DSI_DLTCR_HS2LP_TIME3 0x08000000
  #define DSI_DLTCR_HS2LP_TIME4 0x10000000
  #define DSI_DLTCR_HS2LP_TIME5 0x20000000
  #define DSI_DLTCR_HS2LP_TIME6 0x40000000
  #define DSI_DLTCR_HS2LP_TIME7 0x80000000
#define TOFF_DSI_PCTLR     0x00A0	/* (RW) DSI Host PHY Control Register */
  #define DSI_PCTLR_DEN        0x00000002	/* Digital Enable */
  #define DSI_PCTLR_CKE        0x00000004	/* Clock Enable */
#define TOFF_DSI_PCONFR    0x00A4	/* (RW) DSI Host PHY Configuration Register */
  #define DSI_PCONFR_NL        0x00000003	/* Number of Lanes */
  #define DSI_PCONFR_NL0       0x00000001
  #define DSI_PCONFR_NL1       0x00000002
  #define DSI_PCONFR_SW_TIME   0x0000FF00	/* Stop Wait Time */
  #define DSI_PCONFR_SW_TIME0  0x00000100
  #define DSI_PCONFR_SW_TIME1  0x00000200
  #define DSI_PCONFR_SW_TIME2  0x00000400
  #define DSI_PCONFR_SW_TIME3  0x00000800
  #define DSI_PCONFR_SW_TIME4  0x00001000
  #define DSI_PCONFR_SW_TIME5  0x00002000
  #define DSI_PCONFR_SW_TIME6  0x00004000
  #define DSI_PCONFR_SW_TIME7  0x00008000
#define TOFF_DSI_PUCR      0x00A8	/* (RW) DSI Host PHY ULPS Control Register */
  #define DSI_PUCR_URCL        0x00000001	/* ULPS Request on Clock Lane */
  #define DSI_PUCR_UECL        0x00000002	/* ULPS Exit on Clock Lane */
  #define DSI_PUCR_URDL        0x00000004	/* ULPS Request on Data Lane */
  #define DSI_PUCR_UEDL        0x00000008	/* ULPS Exit on Data Lane */
#define TOFF_DSI_PTTCR     0x00AC	/* (RW) DSI Host PHY TX Triggers Configuration Register */
  #define DSI_PTTCR_TX_TRIG    0x0000000F	/* Transmission Trigger */
  #define DSI_PTTCR_TX_TRIG0   0x00000001
  #define DSI_PTTCR_TX_TRIG1   0x00000002
  #define DSI_PTTCR_TX_TRIG2   0x00000004
  #define DSI_PTTCR_TX_TRIG3   0x00000008
#define TOFF_DSI_PSR       0x00B0	/* (RW) DSI Host PHY Status Register */
  #define DSI_PSR_PD           0x00000002	/* PHY Direction */
  #define DSI_PSR_PSSC         0x00000004	/* PHY Stop State Clock lane */
  #define DSI_PSR_UANC         0x00000008	/* ULPS Active Not Clock lane */
  #define DSI_PSR_PSS0         0x00000010	/* PHY Stop State lane 0 */
  #define DSI_PSR_UAN0         0x00000020	/* ULPS Active Not lane 0 */
  #define DSI_PSR_RUE0         0x00000040	/* RX ULPS Escape lane 0 */
  #define DSI_PSR_PSS1         0x00000080	/* PHY Stop State lane 1 */
  #define DSI_PSR_UAN1         0x00000100	/* ULPS Active Not lane 1 */
#define TOFF_DSI_ISR       0x00BC	/* (RW) DSI Host Interrupt & Status Register */
#define TOFF_DSI_ISR0      0x00BC	/* (RW) DSI Host Interrupt & Status Register0 */
  #define DSI_ISR0_AE0         0x00000001	/* Acknowledge Error 0 */
  #define DSI_ISR0_AE1         0x00000002	/* Acknowledge Error 1 */
  #define DSI_ISR0_AE2         0x00000004	/* Acknowledge Error 2 */
  #define DSI_ISR0_AE3         0x00000008	/* Acknowledge Error 3 */
  #define DSI_ISR0_AE4         0x00000010	/* Acknowledge Error 4 */
  #define DSI_ISR0_AE5         0x00000020	/* Acknowledge Error 5 */
  #define DSI_ISR0_AE6         0x00000040	/* Acknowledge Error 6 */
  #define DSI_ISR0_AE7         0x00000080	/* Acknowledge Error 7 */
  #define DSI_ISR0_AE8         0x00000100	/* Acknowledge Error 8 */
  #define DSI_ISR0_AE9         0x00000200	/* Acknowledge Error 9 */
  #define DSI_ISR0_AE10        0x00000400	/* Acknowledge Error 10 */
  #define DSI_ISR0_AE11        0x00000800	/* Acknowledge Error 11 */
  #define DSI_ISR0_AE12        0x00001000	/* Acknowledge Error 12 */
  #define DSI_ISR0_AE13        0x00002000	/* Acknowledge Error 13 */
  #define DSI_ISR0_AE14        0x00004000	/* Acknowledge Error 14 */
  #define DSI_ISR0_AE15        0x00008000	/* Acknowledge Error 15 */
  #define DSI_ISR0_PE0         0x00010000	/* PHY Error 0 */
  #define DSI_ISR0_PE1         0x00020000	/* PHY Error 1 */
  #define DSI_ISR0_PE2         0x00040000	/* PHY Error 2 */
  #define DSI_ISR0_PE3         0x00080000	/* PHY Error 3 */
  #define DSI_ISR0_PE4         0x00100000	/* PHY Error 4 */
#define TOFF_DSI_ISR1      0x00C0	/* (RW) DSI Host Interrupt & Status Register1 */
  #define DSI_ISR1_TOHSTX      0x00000001	/* Timeout High-Speed Transmission */
  #define DSI_ISR1_TOLPRX      0x00000002	/* Timeout Low-Power Reception */
  #define DSI_ISR1_ECCSE       0x00000004	/* ECC Single-bit Error */
  #define DSI_ISR1_ECCME       0x00000008	/* ECC Multi-bit Error */
  #define DSI_ISR1_CRCE        0x00000010	/* CRC Error */
  #define DSI_ISR1_PSE         0x00000020	/* Packet Size Error */
  #define DSI_ISR1_EOTPE       0x00000040	/* EoTp Error */
  #define DSI_ISR1_LPWRE       0x00000080	/* LTDC Payload Write Error */
  #define DSI_ISR1_GCWRE       0x00000100	/* Generic Command Write Error */
  #define DSI_ISR1_GPWRE       0x00000200	/* Generic Payload Write Error */
  #define DSI_ISR1_GPTXE       0x00000400	/* Generic Payload Transmit Error */
  #define DSI_ISR1_GPRDE       0x00000800	/* Generic Payload Read Error */
  #define DSI_ISR1_GPRXE       0x00001000	/* Generic Payload Receive Error */
#define TOFF_DSI_IER       0x00C4	/* (RW) DSI Host Interrupt Enable Register */
#define TOFF_DSI_IER0      0x00C4	/* (RW) DSI Host Interrupt Enable Register0 */
  #define DSI_IER0_AE0IE       0x00000001	/* Acknowledge Error 0 Interrupt Enable */
  #define DSI_IER0_AE1IE       0x00000002	/* Acknowledge Error 1 Interrupt Enable */
  #define DSI_IER0_AE2IE       0x00000004	/* Acknowledge Error 2 Interrupt Enable */
  #define DSI_IER0_AE3IE       0x00000008	/* Acknowledge Error 3 Interrupt Enable */
  #define DSI_IER0_AE4IE       0x00000010	/* Acknowledge Error 4 Interrupt Enable */
  #define DSI_IER0_AE5IE       0x00000020	/* Acknowledge Error 5 Interrupt Enable */
  #define DSI_IER0_AE6IE       0x00000040	/* Acknowledge Error 6 Interrupt Enable */
  #define DSI_IER0_AE7IE       0x00000080	/* Acknowledge Error 7 Interrupt Enable */
  #define DSI_IER0_AE8IE       0x00000100	/* Acknowledge Error 8 Interrupt Enable */
  #define DSI_IER0_AE9IE       0x00000200	/* Acknowledge Error 9 Interrupt Enable */
  #define DSI_IER0_AE10IE      0x00000400	/* Acknowledge Error 10 Interrupt Enable */
  #define DSI_IER0_AE11IE      0x00000800	/* Acknowledge Error 11 Interrupt Enable */
  #define DSI_IER0_AE12IE      0x00001000	/* Acknowledge Error 12 Interrupt Enable */
  #define DSI_IER0_AE13IE      0x00002000	/* Acknowledge Error 13 Interrupt Enable */
  #define DSI_IER0_AE14IE      0x00004000	/* Acknowledge Error 14 Interrupt Enable */
  #define DSI_IER0_AE15IE      0x00008000	/* Acknowledge Error 15 Interrupt Enable */
  #define DSI_IER0_PE0IE       0x00010000	/* PHY Error 0 Interrupt Enable */
  #define DSI_IER0_PE1IE       0x00020000	/* PHY Error 1 Interrupt Enable */
  #define DSI_IER0_PE2IE       0x00040000	/* PHY Error 2 Interrupt Enable */
  #define DSI_IER0_PE3IE       0x00080000	/* PHY Error 3 Interrupt Enable */
  #define DSI_IER0_PE4IE       0x00100000	/* PHY Error 4 Interrupt Enable */
#define TOFF_DSI_IER1      0x00C8	/* (RW) DSI Host Interrupt Enable Register1 */
  #define DSI_IER1_TOHSTXIE    0x00000001	/* Timeout High-Speed Transmission Interrupt Enable */
  #define DSI_IER1_TOLPRXIE    0x00000002	/* Timeout Low-Power Reception Interrupt Enable */
  #define DSI_IER1_ECCSEIE     0x00000004	/* ECC Single-bit Error Interrupt Enable */
  #define DSI_IER1_ECCMEIE     0x00000008	/* ECC Multi-bit Error Interrupt Enable */
  #define DSI_IER1_CRCEIE      0x00000010	/* CRC Error Interrupt Enable */
  #define DSI_IER1_PSEIE       0x00000020	/* Packet Size Error Interrupt Enable */
  #define DSI_IER1_EOTPEIE     0x00000040	/* EoTp Error Interrupt Enable */
  #define DSI_IER1_LPWREIE     0x00000080	/* LTDC Payload Write Error Interrupt Enable */
  #define DSI_IER1_GCWREIE     0x00000100	/* Generic Command Write Error Interrupt Enable */
  #define DSI_IER1_GPWREIE     0x00000200	/* Generic Payload Write Error Interrupt Enable */
  #define DSI_IER1_GPTXEIE     0x00000400	/* Generic Payload Transmit Error Interrupt Enable */
  #define DSI_IER1_GPRDEIE     0x00000800	/* Generic Payload Read Error Interrupt Enable */
  #define DSI_IER1_GPRXEIE     0x00001000	/* Generic Payload Receive Error Interrupt Enable */
#define TOFF_DSI_FIR       0x00D8	/* (RW) DSI Host Force Interrupt Register */
#define TOFF_DSI_FIR0      0x00D8	/* (RW) DSI Host Force Interrupt Register0 */
  #define DSI_FIR0_FAE0        0x00000001	/* Force Acknowledge Error 0 */
  #define DSI_FIR0_FAE1        0x00000002	/* Force Acknowledge Error 1 */
  #define DSI_FIR0_FAE2        0x00000004	/* Force Acknowledge Error 2 */
  #define DSI_FIR0_FAE3        0x00000008	/* Force Acknowledge Error 3 */
  #define DSI_FIR0_FAE4        0x00000010	/* Force Acknowledge Error 4 */
  #define DSI_FIR0_FAE5        0x00000020	/* Force Acknowledge Error 5 */
  #define DSI_FIR0_FAE6        0x00000040	/* Force Acknowledge Error 6 */
  #define DSI_FIR0_FAE7        0x00000080	/* Force Acknowledge Error 7 */
  #define DSI_FIR0_FAE8        0x00000100	/* Force Acknowledge Error 8 */
  #define DSI_FIR0_FAE9        0x00000200	/* Force Acknowledge Error 9 */
  #define DSI_FIR0_FAE10       0x00000400	/* Force Acknowledge Error 10 */
  #define DSI_FIR0_FAE11       0x00000800	/* Force Acknowledge Error 11 */
  #define DSI_FIR0_FAE12       0x00001000	/* Force Acknowledge Error 12 */
  #define DSI_FIR0_FAE13       0x00002000	/* Force Acknowledge Error 13 */
  #define DSI_FIR0_FAE14       0x00004000	/* Force Acknowledge Error 14 */
  #define DSI_FIR0_FAE15       0x00008000	/* Force Acknowledge Error 15 */
  #define DSI_FIR0_FPE0        0x00010000	/* Force PHY Error 0 */
  #define DSI_FIR0_FPE1        0x00020000	/* Force PHY Error 1 */
  #define DSI_FIR0_FPE2        0x00040000	/* Force PHY Error 2 */
  #define DSI_FIR0_FPE3        0x00080000	/* Force PHY Error 3 */
  #define DSI_FIR0_FPE4        0x00100000	/* Force PHY Error 4 */
#define TOFF_DSI_FIR1      0x00DC	/* (RW) DSI Host Force Interrupt Register1 */
  #define DSI_FIR1_FTOHSTX     0x00000001	/* Force Timeout High-Speed Transmission */
  #define DSI_FIR1_FTOLPRX     0x00000002	/* Force Timeout Low-Power Reception */
  #define DSI_FIR1_FECCSE      0x00000004	/* Force ECC Single-bit Error */
  #define DSI_FIR1_FECCME      0x00000008	/* Force ECC Multi-bit Error */
  #define DSI_FIR1_FCRCE       0x00000010	/* Force CRC Error */
  #define DSI_FIR1_FPSE        0x00000020	/* Force Packet Size Error */
  #define DSI_FIR1_FEOTPE      0x00000040	/* Force EoTp Error */
  #define DSI_FIR1_FLPWRE      0x00000080	/* Force LTDC Payload Write Error */
  #define DSI_FIR1_FGCWRE      0x00000100	/* Force Generic Command Write Error */
  #define DSI_FIR1_FGPWRE      0x00000200	/* Force Generic Payload Write Error */
  #define DSI_FIR1_FGPTXE      0x00000400	/* Force Generic Payload Transmit Error */
  #define DSI_FIR1_FGPRDE      0x00000800	/* Force Generic Payload Read Error */
  #define DSI_FIR1_FGPRXE      0x00001000	/* Force Generic Payload Receive Error */
#define TOFF_DSI_VSCR      0x0100	/* (RW) DSI Host Video Shadow Control Register */
  #define DSI_VSCR_EN          0x00000001	/* Enable */
  #define DSI_VSCR_UR          0x00000100	/* Update Register */
#define TOFF_DSI_LCVCIDR   0x010C	/* (RW) DSI Host LTDC Current VCID Register */
  #define DSI_LCVCIDR_VCID     0x00000003	/* Virtual Channel ID */
  #define DSI_LCVCIDR_VCID0    0x00000001
  #define DSI_LCVCIDR_VCID1    0x00000002
#define TOFF_DSI_LCCCR     0x0110	/* (RW) DSI Host LTDC Current Color Coding Register */
  #define DSI_LCCCR_COLC       0x0000000F	/* Color Coding */
  #define DSI_LCCCR_COLC0      0x00000001
  #define DSI_LCCCR_COLC1      0x00000002
  #define DSI_LCCCR_COLC2      0x00000004
  #define DSI_LCCCR_COLC3      0x00000008
  #define DSI_LCCCR_LPE        0x00000100	/* Loosely Packed Enable */
#define TOFF_DSI_LPMCCR    0x0118	/* (RW) DSI Host Low-power Mode Current Configuration Register */
  #define DSI_LPMCCR_VLPSIZE   0x000000FF	/* VACT Largest Packet Size */
  #define DSI_LPMCCR_VLPSIZE0  0x00000001
  #define DSI_LPMCCR_VLPSIZE1  0x00000002
  #define DSI_LPMCCR_VLPSIZE2  0x00000004
  #define DSI_LPMCCR_VLPSIZE3  0x00000008
  #define DSI_LPMCCR_VLPSIZE4  0x00000010
  #define DSI_LPMCCR_VLPSIZE5  0x00000020
  #define DSI_LPMCCR_VLPSIZE6  0x00000040
  #define DSI_LPMCCR_VLPSIZE7  0x00000080
  #define DSI_LPMCCR_LPSIZE    0x00FF0000	/* Largest Packet Size */
  #define DSI_LPMCCR_LPSIZE0   0x00010000
  #define DSI_LPMCCR_LPSIZE1   0x00020000
  #define DSI_LPMCCR_LPSIZE2   0x00040000
  #define DSI_LPMCCR_LPSIZE3   0x00080000
  #define DSI_LPMCCR_LPSIZE4   0x00100000
  #define DSI_LPMCCR_LPSIZE5   0x00200000
  #define DSI_LPMCCR_LPSIZE6   0x00400000
  #define DSI_LPMCCR_LPSIZE7   0x00800000
#define TOFF_DSI_VMCCR     0x0138	/* (RW) DSI Host Video Mode Current Configuration Register */
  #define DSI_VMCCR_VMT        0x00000003	/* Video Mode Type */
  #define DSI_VMCCR_VMT0       0x00000001
  #define DSI_VMCCR_VMT1       0x00000002
  #define DSI_VMCCR_LPVSAE     0x00000100	/* Low-power Vertical Sync time Enable */
  #define DSI_VMCCR_LPVBPE     0x00000200	/* Low-power Vertical Back-porch Enable */
  #define DSI_VMCCR_LPVFPE     0x00000400	/* Low-power Vertical Front-porch Enable */
  #define DSI_VMCCR_LPVAE      0x00000800	/* Low-power Vertical Active Enable */
  #define DSI_VMCCR_LPHBPE     0x00001000	/* Low-power Horizontal Back-porch Enable */
  #define DSI_VMCCR_LPHFE      0x00002000	/* Low-power Horizontal Front-porch Enable */
  #define DSI_VMCCR_FBTAAE     0x00004000	/* Frame BTA Acknowledge Enable */
  #define DSI_VMCCR_LPCE       0x00008000	/* Low-power Command Enable */
#define TOFF_DSI_VPCCR     0x013C	/* (RW) DSI Host Video Packet Current Configuration Register */
  #define DSI_VPCCR_VPSIZE     0x00003FFF	/* Video Packet Size */
  #define DSI_VPCCR_VPSIZE0    0x00000001
  #define DSI_VPCCR_VPSIZE1    0x00000002
  #define DSI_VPCCR_VPSIZE2    0x00000004
  #define DSI_VPCCR_VPSIZE3    0x00000008
  #define DSI_VPCCR_VPSIZE4    0x00000010
  #define DSI_VPCCR_VPSIZE5    0x00000020
  #define DSI_VPCCR_VPSIZE6    0x00000040
  #define DSI_VPCCR_VPSIZE7    0x00000080
  #define DSI_VPCCR_VPSIZE8    0x00000100
  #define DSI_VPCCR_VPSIZE9    0x00000200
  #define DSI_VPCCR_VPSIZE10   0x00000400
  #define DSI_VPCCR_VPSIZE11   0x00000800
  #define DSI_VPCCR_VPSIZE12   0x00001000
  #define DSI_VPCCR_VPSIZE13   0x00002000
#define TOFF_DSI_VCCCR     0x0140	/* (RW) DSI Host Video Chuncks Current Configuration Register */
  #define DSI_VCCCR_NUMC       0x00001FFF	/* Number of Chunks */
  #define DSI_VCCCR_NUMC0      0x00000001
  #define DSI_VCCCR_NUMC1      0x00000002
  #define DSI_VCCCR_NUMC2      0x00000004
  #define DSI_VCCCR_NUMC3      0x00000008
  #define DSI_VCCCR_NUMC4      0x00000010
  #define DSI_VCCCR_NUMC5      0x00000020
  #define DSI_VCCCR_NUMC6      0x00000040
  #define DSI_VCCCR_NUMC7      0x00000080
  #define DSI_VCCCR_NUMC8      0x00000100
  #define DSI_VCCCR_NUMC9      0x00000200
  #define DSI_VCCCR_NUMC10     0x00000400
  #define DSI_VCCCR_NUMC11     0x00000800
  #define DSI_VCCCR_NUMC12     0x00001000
#define TOFF_DSI_VNPCCR    0x0144	/* (RW) DSI Host Video Null Packet Current Configuration Register */
  #define DSI_VNPCCR_NPSIZE    0x00001FFF	/* Number of Chunks */
  #define DSI_VNPCCR_NPSIZE0   0x00000001
  #define DSI_VNPCCR_NPSIZE1   0x00000002
  #define DSI_VNPCCR_NPSIZE2   0x00000004
  #define DSI_VNPCCR_NPSIZE3   0x00000008
  #define DSI_VNPCCR_NPSIZE4   0x00000010
  #define DSI_VNPCCR_NPSIZE5   0x00000020
  #define DSI_VNPCCR_NPSIZE6   0x00000040
  #define DSI_VNPCCR_NPSIZE7   0x00000080
  #define DSI_VNPCCR_NPSIZE8   0x00000100
  #define DSI_VNPCCR_NPSIZE9   0x00000200
  #define DSI_VNPCCR_NPSIZE10  0x00000400
  #define DSI_VNPCCR_NPSIZE11  0x00000800
  #define DSI_VNPCCR_NPSIZE12  0x00001000
#define TOFF_DSI_VHSACCR   0x0148	/* (RW) DSI Host Video HSA Current Configuration Register */
  #define DSI_VHSACCR_HSA      0x00000FFF	/* Horizontal Synchronism Active duration */
  #define DSI_VHSACCR_HSA0     0x00000001
  #define DSI_VHSACCR_HSA1     0x00000002
  #define DSI_VHSACCR_HSA2     0x00000004
  #define DSI_VHSACCR_HSA3     0x00000008
  #define DSI_VHSACCR_HSA4     0x00000010
  #define DSI_VHSACCR_HSA5     0x00000020
  #define DSI_VHSACCR_HSA6     0x00000040
  #define DSI_VHSACCR_HSA7     0x00000080
  #define DSI_VHSACCR_HSA8     0x00000100
  #define DSI_VHSACCR_HSA9     0x00000200
  #define DSI_VHSACCR_HSA10    0x00000400
  #define DSI_VHSACCR_HSA11    0x00000800
#define TOFF_DSI_VHBPCCR   0x014C	/* (RW) DSI Host Video HBP Current Configuration Register */
  #define DSI_VHBPCCR_HBP      0x00000FFF	/* Horizontal Back-Porch duration */
  #define DSI_VHBPCCR_HBP0     0x00000001
  #define DSI_VHBPCCR_HBP1     0x00000002
  #define DSI_VHBPCCR_HBP2     0x00000004
  #define DSI_VHBPCCR_HBP3     0x00000008
  #define DSI_VHBPCCR_HBP4     0x00000010
  #define DSI_VHBPCCR_HBP5     0x00000020
  #define DSI_VHBPCCR_HBP6     0x00000040
  #define DSI_VHBPCCR_HBP7     0x00000080
  #define DSI_VHBPCCR_HBP8     0x00000100
  #define DSI_VHBPCCR_HBP9     0x00000200
  #define DSI_VHBPCCR_HBP10    0x00000400
  #define DSI_VHBPCCR_HBP11    0x00000800
#define TOFF_DSI_VLCCR     0x0150	/* (RW) DSI Host Video Line Current Configuration Register */
  #define DSI_VLCCR_HLINE      0x00007FFF	/* Horizontal Line duration */
  #define DSI_VLCCR_HLINE0     0x00000001
  #define DSI_VLCCR_HLINE1     0x00000002
  #define DSI_VLCCR_HLINE2     0x00000004
  #define DSI_VLCCR_HLINE3     0x00000008
  #define DSI_VLCCR_HLINE4     0x00000010
  #define DSI_VLCCR_HLINE5     0x00000020
  #define DSI_VLCCR_HLINE6     0x00000040
  #define DSI_VLCCR_HLINE7     0x00000080
  #define DSI_VLCCR_HLINE8     0x00000100
  #define DSI_VLCCR_HLINE9     0x00000200
  #define DSI_VLCCR_HLINE10    0x00000400
  #define DSI_VLCCR_HLINE11    0x00000800
  #define DSI_VLCCR_HLINE12    0x00001000
  #define DSI_VLCCR_HLINE13    0x00002000
  #define DSI_VLCCR_HLINE14    0x00004000
#define TOFF_DSI_VVSACCR   0x0154	/* (RW) DSI Host Video VSA Current Configuration Register */
  #define DSI_VVSACCR_VSA      0x000003FF	/* Vertical Synchronism Active duration */
  #define DSI_VVSACCR_VSA0     0x00000001
  #define DSI_VVSACCR_VSA1     0x00000002
  #define DSI_VVSACCR_VSA2     0x00000004
  #define DSI_VVSACCR_VSA3     0x00000008
  #define DSI_VVSACCR_VSA4     0x00000010
  #define DSI_VVSACCR_VSA5     0x00000020
  #define DSI_VVSACCR_VSA6     0x00000040
  #define DSI_VVSACCR_VSA7     0x00000080
  #define DSI_VVSACCR_VSA8     0x00000100
  #define DSI_VVSACCR_VSA9     0x00000200
#define TOFF_DSI_VVBPCCR   0x0158	/* (RW) DSI Host Video VBP Current Configuration Register */
  #define DSI_VVBPCCR_VBP      0x000003FF	/* Vertical Back-Porch duration */
  #define DSI_VVBPCCR_VBP0     0x00000001
  #define DSI_VVBPCCR_VBP1     0x00000002
  #define DSI_VVBPCCR_VBP2     0x00000004
  #define DSI_VVBPCCR_VBP3     0x00000008
  #define DSI_VVBPCCR_VBP4     0x00000010
  #define DSI_VVBPCCR_VBP5     0x00000020
  #define DSI_VVBPCCR_VBP6     0x00000040
  #define DSI_VVBPCCR_VBP7     0x00000080
  #define DSI_VVBPCCR_VBP8     0x00000100
  #define DSI_VVBPCCR_VBP9     0x00000200
#define TOFF_DSI_VVFPCCR   0x015C	/* (RW) DSI Host Video VFP Current Configuration Register */
  #define DSI_VVFPCCR_VFP      0x000003FF	/* Vertical Front-Porch duration */
  #define DSI_VVFPCCR_VFP0     0x00000001
  #define DSI_VVFPCCR_VFP1     0x00000002
  #define DSI_VVFPCCR_VFP2     0x00000004
  #define DSI_VVFPCCR_VFP3     0x00000008
  #define DSI_VVFPCCR_VFP4     0x00000010
  #define DSI_VVFPCCR_VFP5     0x00000020
  #define DSI_VVFPCCR_VFP6     0x00000040
  #define DSI_VVFPCCR_VFP7     0x00000080
  #define DSI_VVFPCCR_VFP8     0x00000100
  #define DSI_VVFPCCR_VFP9     0x00000200
#define TOFF_DSI_VVACCR    0x0160	/* (RW) DSI Host Video VA Current Configuration Register */
  #define DSI_VVACCR_VA        0x00003FFF	/* Vertical Active duration */
  #define DSI_VVACCR_VA0       0x00000001
  #define DSI_VVACCR_VA1       0x00000002
  #define DSI_VVACCR_VA2       0x00000004
  #define DSI_VVACCR_VA3       0x00000008
  #define DSI_VVACCR_VA4       0x00000010
  #define DSI_VVACCR_VA5       0x00000020
  #define DSI_VVACCR_VA6       0x00000040
  #define DSI_VVACCR_VA7       0x00000080
  #define DSI_VVACCR_VA8       0x00000100
  #define DSI_VVACCR_VA9       0x00000200
  #define DSI_VVACCR_VA10      0x00000400
  #define DSI_VVACCR_VA11      0x00000800
  #define DSI_VVACCR_VA12      0x00001000
  #define DSI_VVACCR_VA13      0x00002000
#define TOFF_DSI_TDCCR     0x0190	/* (RW) DSI Host 3D Current Configuration Register */
  #define DSI_TDCCR_3DM        0x00000003	/* 3D Mode */
  #define DSI_TDCCR_3DM0       0x00000001
  #define DSI_TDCCR_3DM1       0x00000002
  #define DSI_TDCCR_3DF        0x0000000C	/* 3D Format */
  #define DSI_TDCCR_3DF0       0x00000004
  #define DSI_TDCCR_3DF1       0x00000008
  #define DSI_TDCCR_SVS        0x00000010	/* Second VSYNC */
  #define DSI_TDCCR_RF         0x00000020	/* Right First */
  #define DSI_TDCCR_S3DC       0x00010000	/* Send 3D Control */
#define TOFF_DSI_WCFGR     0x0400	/* (RW) DSI Wrapper Configuration Register */
  #define DSI_WCFGR_DSIM       0x00000001	/* DSI Mode */
  #define DSI_WCFGR_COLMUX     0x0000000E	/* Color Multiplexing */
  #define DSI_WCFGR_COLMUX0    0x00000002
  #define DSI_WCFGR_COLMUX1    0x00000004
  #define DSI_WCFGR_COLMUX2    0x00000008
  #define DSI_WCFGR_TESRC      0x00000010	/* Tearing Effect Source */
  #define DSI_WCFGR_TEPOL      0x00000020	/* Tearing Effect Polarity */
  #define DSI_WCFGR_AR         0x00000040	/* Automatic Refresh */
  #define DSI_WCFGR_VSPOL      0x00000080	/* VSync Polarity */
#define TOFF_DSI_WCR       0x0404	/* (RW) DSI Wrapper Control Register */
  #define DSI_WCR_COLM         0x00000001	/* Color Mode */
  #define DSI_WCR_SHTDN        0x00000002	/* Shutdown */
  #define DSI_WCR_LTDCEN       0x00000004	/* LTDC Enable */
  #define DSI_WCR_DSIEN        0x00000008	/* DSI Enable */
#define TOFF_DSI_WIER      0x0408	/* (RW) DSI Wrapper Interrupt Enable Register */
  #define DSI_WIER_TEIE        0x00000001	/* Tearing Effect Interrupt Enable */
  #define DSI_WIER_ERIE        0x00000002	/* End of Refresh Interrupt Enable */
  #define DSI_WIER_PLLLIE      0x00000200	/* PLL Lock Interrupt Enable */
  #define DSI_WIER_PLLUIE      0x00000400	/* PLL Unlock Interrupt Enable */
  #define DSI_WIER_RRIE        0x00002000	/* Regulator Ready Interrupt Enable */
#define TOFF_DSI_WISR      0x040C	/* (RW) DSI Wrapper Interrupt and Status Register */
  #define DSI_WISR_TEIF        0x00000001	/* Tearing Effect Interrupt Flag */
  #define DSI_WISR_ERIF        0x00000002	/* End of Refresh Interrupt Flag */
  #define DSI_WISR_BUSY        0x00000004	/* Busy Flag */
  #define DSI_WISR_PLLLS       0x00000100	/* PLL Lock Status */
  #define DSI_WISR_PLLLIF      0x00000200	/* PLL Lock Interrupt Flag */
  #define DSI_WISR_PLLUIF      0x00000400	/* PLL Unlock Interrupt Flag */
  #define DSI_WISR_RRS         0x00001000	/* Regulator Ready Flag */
  #define DSI_WISR_RRIF        0x00002000	/* Regulator Ready Interrupt Flag */
#define TOFF_DSI_WIFCR     0x0410	/* (RW) DSI Wrapper Interrupt Flag Clear Register */
  #define DSI_WIFCR_CTEIF      0x00000001	/* Clear Tearing Effect Interrupt Flag */
  #define DSI_WIFCR_CERIF      0x00000002	/* Clear End of Refresh Interrupt Flag */
  #define DSI_WIFCR_CPLLLIF    0x00000200	/* Clear PLL Lock Interrupt Flag */
  #define DSI_WIFCR_CPLLUIF    0x00000400	/* Clear PLL Unlock Interrupt Flag */
  #define DSI_WIFCR_CRRIF      0x00002000	/* Clear Regulator Ready Interrupt Flag */
#define TOFF_DSI_WPCR      0x0418	/* (RW) DSI Wrapper PHY Configuration Register 0-4 */
#define TOFF_DSI_WPCR0     0x0418	/* (RW) DSI Wrapper PHY Configuration Register0 */
  #define DSI_WPCR0_UIX4       0x0000003F	/* Unit Interval multiplied by 4 */
  #define DSI_WPCR0_UIX4_0     0x00000001
  #define DSI_WPCR0_UIX4_1     0x00000002
  #define DSI_WPCR0_UIX4_2     0x00000004
  #define DSI_WPCR0_UIX4_3     0x00000008
  #define DSI_WPCR0_UIX4_4     0x00000010
  #define DSI_WPCR0_UIX4_5     0x00000020
  #define DSI_WPCR0_SWCL       0x00000040	/* Swap pins on clock lane */
  #define DSI_WPCR0_SWDL0      0x00000080	/* Swap pins on data lane 1 */
  #define DSI_WPCR0_SWDL1      0x00000100	/* Swap pins on data lane 2 */
  #define DSI_WPCR0_HSICL      0x00000200	/* Invert the high-speed data signal on clock lane */
  #define DSI_WPCR0_HSIDL0     0x00000400	/* Invert the high-speed data signal on lane 1 */
  #define DSI_WPCR0_HSIDL1     0x00000800	/* Invert the high-speed data signal on lane 2 */
  #define DSI_WPCR0_FTXSMCL    0x00001000	/* Force clock lane in TX stop mode */
  #define DSI_WPCR0_FTXSMDL    0x00002000	/* Force data lanes in TX stop mode */
  #define DSI_WPCR0_CDOFFDL    0x00004000	/* Contention detection OFF */
  #define DSI_WPCR0_TDDL       0x00010000	/* Turn Disable Data Lanes */
  #define DSI_WPCR0_PDEN       0x00040000	/* Pull-Down Enable */
  #define DSI_WPCR0_TCLKPREPEN 0x00080000	/* Timer for t-CLKPREP Enable */
  #define DSI_WPCR0_TCLKZEROEN 0x00100000	/* Timer for t-CLKZERO Enable */
  #define DSI_WPCR0_THSPREPEN  0x00200000	/* Timer for t-HSPREP Enable */
  #define DSI_WPCR0_THSTRAILEN 0x00400000	/* Timer for t-HSTRAIL Enable */
  #define DSI_WPCR0_THSZEROEN  0x00800000	/* Timer for t-HSZERO Enable */
  #define DSI_WPCR0_TLPXDEN    0x01000000	/* Timer for t-LPXD Enable */
  #define DSI_WPCR0_THSEXITEN  0x02000000	/* Timer for t-HSEXIT Enable */
  #define DSI_WPCR0_TLPXCEN    0x04000000	/* Timer for t-LPXC Enable */
  #define DSI_WPCR0_TCLKPOSTEN 0x08000000	/* Timer for t-CLKPOST Enable */
#define TOFF_DSI_WPCR1     0x041C	/* (RW)DSI Wrapper PHY Configuration Register1 */
  #define DSI_WPCR1_HSTXDCL    0x00000003	/* High-Speed Transmission Delay on Clock Lane */
  #define DSI_WPCR1_HSTXDCL0   0x00000001
  #define DSI_WPCR1_HSTXDCL1   0x00000002
  #define DSI_WPCR1_HSTXDDL    0x0000000C	/* High-Speed Transmission Delay on Data Lane */
  #define DSI_WPCR1_HSTXDDL0   0x00000004
  #define DSI_WPCR1_HSTXDDL1   0x00000008
  #define DSI_WPCR1_LPSRCCL    0x000000C0	/* Low-Power transmission Slew Rate Compensation on Clock Lane */
  #define DSI_WPCR1_LPSRCCL0   0x00000040
  #define DSI_WPCR1_LPSRCCL1   0x00000080
  #define DSI_WPCR1_LPSRCDL    0x00000300	/* Low-Power transmission Slew Rate Compensation on Data Lane */
  #define DSI_WPCR1_LPSRCDL0   0x00000100
  #define DSI_WPCR1_LPSRCDL1   0x00000200
  #define DSI_WPCR1_SDDC       0x00001000	/* SDD Control */
  #define DSI_WPCR1_LPRXVCDL   0x0000C000	/* Low-Power Reception V-IL Compensation on Data Lanes */
  #define DSI_WPCR1_LPRXVCDL0  0x00004000
  #define DSI_WPCR1_LPRXVCDL1  0x00008000
  #define DSI_WPCR1_HSTXSRCCL  0x00030000	/* High-Speed Transmission Delay on Clock Lane */
  #define DSI_WPCR1_HSTXSRCCL0 0x00010000
  #define DSI_WPCR1_HSTXSRCCL1 0x00020000
  #define DSI_WPCR1_HSTXSRCDL  0x000C0000	/* High-Speed Transmission Delay on Data Lane */
  #define DSI_WPCR1_HSTXSRCDL0 0x00040000
  #define DSI_WPCR1_HSTXSRCDL1 0x00080000
  #define DSI_WPCR1_FLPRXLPM   0x00400000	/* Forces LP Receiver in Low-Power Mode */
  #define DSI_WPCR1_LPRXFT     0x06000000	/* Low-Power RX low-pass Filtering Tuning */
  #define DSI_WPCR1_LPRXFT0    0x02000000
  #define DSI_WPCR1_LPRXFT1    0x04000000
#define TOFF_DSI_WPCR2     0x0420	/* (RW)DSI Wrapper PHY Configuration Register2 */
  #define DSI_WPCR2_TCLKPREP   0x000000FF	/* t-CLKPREP */
  #define DSI_WPCR2_TCLKPREP0  0x00000001
  #define DSI_WPCR2_TCLKPREP1  0x00000002
  #define DSI_WPCR2_TCLKPREP2  0x00000004
  #define DSI_WPCR2_TCLKPREP3  0x00000008
  #define DSI_WPCR2_TCLKPREP4  0x00000010
  #define DSI_WPCR2_TCLKPREP5  0x00000020
  #define DSI_WPCR2_TCLKPREP6  0x00000040
  #define DSI_WPCR2_TCLKPREP7  0x00000080
  #define DSI_WPCR2_TCLKZERO   0x0000FF00	/* t-CLKZERO */
  #define DSI_WPCR2_TCLKZERO0  0x00000100
  #define DSI_WPCR2_TCLKZERO1  0x00000200
  #define DSI_WPCR2_TCLKZERO2  0x00000400
  #define DSI_WPCR2_TCLKZERO3  0x00000800
  #define DSI_WPCR2_TCLKZERO4  0x00001000
  #define DSI_WPCR2_TCLKZERO5  0x00002000
  #define DSI_WPCR2_TCLKZERO6  0x00004000
  #define DSI_WPCR2_TCLKZERO7  0x00008000
  #define DSI_WPCR2_THSPREP    0x00FF0000	/* t-HSPREP */
  #define DSI_WPCR2_THSPREP0   0x00010000
  #define DSI_WPCR2_THSPREP1   0x00020000
  #define DSI_WPCR2_THSPREP2   0x00040000
  #define DSI_WPCR2_THSPREP3   0x00080000
  #define DSI_WPCR2_THSPREP4   0x00100000
  #define DSI_WPCR2_THSPREP5   0x00200000
  #define DSI_WPCR2_THSPREP6   0x00400000
  #define DSI_WPCR2_THSPREP7   0x00800000
  #define DSI_WPCR2_THSTRAIL   0xFF000000	/* t-HSTRAIL */
  #define DSI_WPCR2_THSTRAIL0  0x01000000
  #define DSI_WPCR2_THSTRAIL1  0x02000000
  #define DSI_WPCR2_THSTRAIL2  0x04000000
  #define DSI_WPCR2_THSTRAIL3  0x08000000
  #define DSI_WPCR2_THSTRAIL4  0x10000000
  #define DSI_WPCR2_THSTRAIL5  0x20000000
  #define DSI_WPCR2_THSTRAIL6  0x40000000
  #define DSI_WPCR2_THSTRAIL7  0x80000000
#define TOFF_DSI_WPCR3     0x0424	/* (RW)DSI Wrapper PHY Configuration Register3 */
  #define DSI_WPCR3_THSZERO    0x000000FF	/* t-HSZERO */
  #define DSI_WPCR3_THSZERO0   0x00000001
  #define DSI_WPCR3_THSZERO1   0x00000002
  #define DSI_WPCR3_THSZERO2   0x00000004
  #define DSI_WPCR3_THSZERO3   0x00000008
  #define DSI_WPCR3_THSZERO4   0x00000010
  #define DSI_WPCR3_THSZERO5   0x00000020
  #define DSI_WPCR3_THSZERO6   0x00000040
  #define DSI_WPCR3_THSZERO7   0x00000080
  #define DSI_WPCR3_TLPXD      0x0000FF00	/* t-LPXD */
  #define DSI_WPCR3_TLPXD0     0x00000100
  #define DSI_WPCR3_TLPXD1     0x00000200
  #define DSI_WPCR3_TLPXD2     0x00000400
  #define DSI_WPCR3_TLPXD3     0x00000800
  #define DSI_WPCR3_TLPXD4     0x00001000
  #define DSI_WPCR3_TLPXD5     0x00002000
  #define DSI_WPCR3_TLPXD6     0x00004000
  #define DSI_WPCR3_TLPXD7     0x00008000
  #define DSI_WPCR3_THSEXIT    0x00FF0000	/* t-HSEXIT */
  #define DSI_WPCR3_THSEXIT0   0x00010000
  #define DSI_WPCR3_THSEXIT1   0x00020000
  #define DSI_WPCR3_THSEXIT2   0x00040000
  #define DSI_WPCR3_THSEXIT3   0x00080000
  #define DSI_WPCR3_THSEXIT4   0x00100000
  #define DSI_WPCR3_THSEXIT5   0x00200000
  #define DSI_WPCR3_THSEXIT6   0x00400000
  #define DSI_WPCR3_THSEXIT7   0x00800000
  #define DSI_WPCR3_TLPXC      0xFF000000	/* t-LPXC */
  #define DSI_WPCR3_TLPXC0     0x01000000
  #define DSI_WPCR3_TLPXC1     0x02000000
  #define DSI_WPCR3_TLPXC2     0x04000000
  #define DSI_WPCR3_TLPXC3     0x08000000
  #define DSI_WPCR3_TLPXC4     0x10000000
  #define DSI_WPCR3_TLPXC5     0x20000000
  #define DSI_WPCR3_TLPXC6     0x40000000
  #define DSI_WPCR3_TLPXC7     0x80000000
#define TOFF_DSI_WPCR4     0x0428	/* (RW)DSI Wrapper PHY Configuration Register4 */
  #define DSI_WPCR4_TCLKPOST   0x000000FF	/* t-CLKPOST */
  #define DSI_WPCR4_TCLKPOST0  0x00000001
  #define DSI_WPCR4_TCLKPOST1  0x00000002
  #define DSI_WPCR4_TCLKPOST2  0x00000004
  #define DSI_WPCR4_TCLKPOST3  0x00000008
  #define DSI_WPCR4_TCLKPOST4  0x00000010
  #define DSI_WPCR4_TCLKPOST5  0x00000020
  #define DSI_WPCR4_TCLKPOST6  0x00000040
  #define DSI_WPCR4_TCLKPOST7  0x00000080
#define TOFF_DSI_WRPCR     0x0430	/* (RW) DSI Wrapper Regulator and PLL Control Register */
  #define DSI_WRPCR_PLLEN      0x00000001	/* PLL Enable */
  #define DSI_WRPCR_PLL_NDIV   0x000001FC	/* PLL Loop Division Factor */
  #define DSI_WRPCR_PLL_NDIV0  0x00000004
  #define DSI_WRPCR_PLL_NDIV1  0x00000008
  #define DSI_WRPCR_PLL_NDIV2  0x00000010
  #define DSI_WRPCR_PLL_NDIV3  0x00000020
  #define DSI_WRPCR_PLL_NDIV4  0x00000040
  #define DSI_WRPCR_PLL_NDIV5  0x00000080
  #define DSI_WRPCR_PLL_NDIV6  0x00000100
  #define DSI_WRPCR_PLL_IDF    0x00007800	/* PLL Input Division Factor */
  #define DSI_WRPCR_PLL_IDF0   0x00000800
  #define DSI_WRPCR_PLL_IDF1   0x00001000
  #define DSI_WRPCR_PLL_IDF2   0x00002000
  #define DSI_WRPCR_PLL_IDF3   0x00004000
  #define DSI_WRPCR_PLL_ODF    0x00030000	/* PLL Output Division Factor */
  #define DSI_WRPCR_PLL_ODF0   0x00010000
  #define DSI_WRPCR_PLL_ODF1   0x00020000
  #define DSI_WRPCR_REGEN      0x01000000	/* Regulator Enable */

#endif

#if defined(TOPPERS_STM32F769_DISCOVERY) || defined(TOPPERS_STM32F767_NUCLEO144)
/*
 *  DFSDM MODULE REGISTERS
 */
#define TADR_DFSDM1_BASE            (APB2PERIPH_BASE + 0x7400)
#define TADR_DFSDM1_CHANNEL0_BASE   (TADR_DFSDM1_BASE + 0x0000)
#define TADR_DFSDM1_CHANNEL1_BASE   (TADR_DFSDM1_BASE + 0x0020)
#define TADR_DFSDM1_CHANNEL2_BASE   (TADR_DFSDM1_BASE + 0x0040)
#define TADR_DFSDM1_CHANNEL3_BASE   (TADR_DFSDM1_BASE + 0x0060)
#define TADR_DFSDM1_CHANNEL4_BASE   (TADR_DFSDM1_BASE + 0x0080)
#define TADR_DFSDM1_CHANNEL5_BASE   (TADR_DFSDM1_BASE + 0x00A0)
#define TADR_DFSDM1_CHANNEL6_BASE   (TADR_DFSDM1_BASE + 0x00C0)
#define TADR_DFSDM1_CHANNEL7_BASE   (TADR_DFSDM1_BASE + 0x00E0)
#define TOFF_DFSDM_CHCFGR1 0x0000	/* (RW) DFSDM channel configuration register1 */
  #define DFSDM_CHCFGR1_SITP       0x00000003	/* SITP[1:0] Serial interface type for channel y */
  #define DFSDM_CHCFGR1_SITP_0     0x00000001	/* Serial interface type for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_SITP_1     0x00000002	/* Serial interface type for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_SPICKSEL   0x0000000C	/* SPICKSEL[1:0] SPI clock select for channel y */
  #define DFSDM_CHCFGR1_SPICKSEL_0 0x00000004	/* SPI clock select for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_SPICKSEL_1 0x00000008	/* SPI clock select for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_SCDEN      0x00000020	/* Short circuit detector enable on channel y */
  #define DFSDM_CHCFGR1_CKABEN     0x00000040	/* Clock absence detector enable on channel y */
  #define DFSDM_CHCFGR1_CHEN       0x00000080	/* Channel y enable */
  #define DFSDM_CHCFGR1_CHINSEL    0x00000100	/* Serial inputs selection for channel y */
  #define DFSDM_CHCFGR1_DATMPX_0   0x00001000	/* Input data multiplexer for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_DATMPX_1   0x00002000	/* Input data multiplexer for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_DATMPX     0x00003000	/* DATMPX[1:0] Input data multiplexer for channel y */
  #define DFSDM_CHCFGR1_DATPACK    0x0000C000	/* DATPACK[1:0] Data packing mode */
  #define DFSDM_CHCFGR1_DATPACK_0  0x00004000	/* Data packing mode, Bit 0 */
  #define DFSDM_CHCFGR1_DATPACK_1  0x00008000	/* Data packing mode, Bit 1 */
  #define DFSDM_CHCFGR1_CKOUTDIV   0x00FF0000	/* CKOUTDIV[7:0] output serial clock divider */
  #define DFSDM_CHCFGR1_CKOUTSRC   0x40000000	/* Output serial clock source selection */
  #define DFSDM_CHCFGR1_DFSDMEN    0x80000000	/* Global enable for DFSDM interface */
#define TOFF_DFSDM_CHCFGR2 0x0004	/* (RW) DFSDM channel configuration register2 */
  #define DFSDM_CHCFGR2_DTRBS      0x000000F8	/* DTRBS[4:0] Data right bit-shift for channel y */
  #define DFSDM_CHCFGR2_OFFSET     0xFFFFFF00	/* OFFSET[23:0] 24-bit calibration offset for channel y */
#define TOFF_DFSDM_CHAWSCDR 0x0008	/* (RW) DFSDM channel analog watchdog and short circuit detector register */
  #define DFSDM_CHAWSCDR_SCDT      0x000000FF	/* SCDT[7:0] Short circuit detector threshold for channel y */
  #define DFSDM_CHAWSCDR_BKSCD     0x0000F000	/* BKSCD[3:0] Break signal assignment for short circuit detector on channel y */
  #define DFSDM_CHAWSCDR_AWFOSR    0x001F0000	/* AWFOSR[4:0] Analog watchdog filter oversampling ratio on channel y */
  #define DFSDM_CHAWSCDR_AWFORD    0x00C00000	/* AWFORD[1:0] Analog watchdog Sinc filter order on channel y */
  #define DFSDM_CHAWSCDR_AWFORD_0  0x00400000	/* Analog watchdog Sinc filter order on channel y, Bit 0 */
  #define DFSDM_CHAWSCDR_AWFORD_1  0x00800000	/* Analog watchdog Sinc filter order on channel y, Bit 1 */
#define TOFF_DFSDM_CHWDATAR 0x000C	/* (RW) DFSDM channel watchdog filter data register */
  #define DFSDM_CHWDATR_WDATA      0x0000FFFF	/* WDATA[15:0] Input channel y watchdog data */
#define TOFF_DFSDM_CHDATINR 0x0010	/* (RW) DFSDM channel data input register */
  #define DFSDM_CHDATINR_INDAT0    0x0000FFFF	/* INDAT0[31:16] Input data for channel y or channel (y+1) */
  #define DFSDM_CHDATINR_INDAT1    0xFFFF0000	/* INDAT0[15:0] Input data for channel y */

#define TADR_DFSDM1_FILTER0_BASE    (TADR_DFSDM1_BASE + 0x0100)
#define TADR_DFSDM1_FILTER1_BASE    (TADR_DFSDM1_BASE + 0x0180)
#define TADR_DFSDM1_FILTER2_BASE    (TADR_DFSDM1_BASE + 0x0200)
#define TADR_DFSDM1_FILTER3_BASE    (TADR_DFSDM1_BASE + 0x0280)
#define TOFF_DFSDM_FLTCR1  0x0000	/* (RW) DFSDM control register1 */
  #define DFSDM_FLTCR1_DFEN      0x00000001	/* DFSDM enable */
  #define DFSDM_FLTCR1_JSWSTART  0x00000002	/* Start the conversion of the injected group of channels */
  #define DFSDM_FLTCR1_JSYNC     0x00000008	/* Launch an injected conversion synchronously with DFSDMx JSWSTART trigger */
  #define DFSDM_FLTCR1_JSCAN     0x00000010	/* Scanning conversion in continuous mode selection for injected conversions */
  #define DFSDM_FLTCR1_JDMAEN    0x00000020	/* DMA channel enabled to read data for the injected channel group */
  #define DFSDM_FLTCR1_JEXTSEL   0x00001F00	/* JEXTSEL[4:0]Trigger signal selection for launching injected conversions */
  #define DFSDM_FLTCR1_JEXTSEL_0 0x00000100	/* Trigger signal selection for launching injected conversions, Bit 0 */
  #define DFSDM_FLTCR1_JEXTSEL_1 0x00000200	/* Trigger signal selection for launching injected conversions, Bit 1 */
  #define DFSDM_FLTCR1_JEXTSEL_2 0x00000400	/* Trigger signal selection for launching injected conversions, Bit 2 */
  #define DFSDM_FLTCR1_JEXTSEL_3 0x00000800	/* Trigger signal selection for launching injected conversions, Bit 3 */
  #define DFSDM_FLTCR1_JEXTSEL_4 0x00001000	/* Trigger signal selection for launching injected conversions, Bit 4 */
  #define DFSDM_FLTCR1_JEXTEN    0x00006000	/* JEXTEN[1:0] Trigger enable and trigger edge selection for injected conversions */
  #define DFSDM_FLTCR1_JEXTEN_1  0x00004000	/* Trigger enable and trigger edge selection for injected conversions, Bit 1 */
  #define DFSDM_FLTCR1_JEXTEN_0  0x00002000	/* Trigger enable and trigger edge selection for injected conversions, Bit 0 */
  #define DFSDM_FLTCR1_RSWSTART  0x00020000	/* Software start of a conversion on the regular channel */
  #define DFSDM_FLTCR1_RCONT     0x00040000	/* Continuous mode selection for regular conversions */
  #define DFSDM_FLTCR1_RSYNC     0x00080000	/* Launch regular conversion synchronously with DFSDMx */
  #define DFSDM_FLTCR1_RDMAEN    0x00200000	/* DMA channel enabled to read data for the regular conversion */
  #define DFSDM_FLTCR1_RCH       0x07000000	/* RCH[2:0] Regular channel selection */
  #define DFSDM_FLTCR1_FAST      0x20000000	/* Fast conversion mode selection */
  #define DFSDM_FLTCR1_AWFSEL    0x40000000	/* Analog watchdog fast mode select */
#define TOFF_DFSDM_FLTCR2  0x0004	/* (RW) DFSDM control register2 */
  #define DFSDM_FLTCR2_JEOCIE    0x00000001	/* Injected end of conversion interrupt enable */
  #define DFSDM_FLTCR2_REOCIE    0x00000002	/* Regular end of conversion interrupt enable */
  #define DFSDM_FLTCR2_JOVRIE    0x00000004	/* Injected data overrun interrupt enable */
  #define DFSDM_FLTCR2_ROVRIE    0x00000008	/* Regular data overrun interrupt enable */
  #define DFSDM_FLTCR2_AWDIE     0x00000010	/* Analog watchdog interrupt enable */
  #define DFSDM_FLTCR2_SCDIE     0x00000020	/* Short circuit detector interrupt enable */
  #define DFSDM_FLTCR2_CKABIE    0x00000040	/* Clock absence interrupt enable */
  #define DFSDM_FLTCR2_EXCH      0x0000FF00	/* EXCH[7:0] Extreme detector channel selection */
  #define DFSDM_FLTCR2_AWDCH     0x00FF0000	/* AWDCH[7:0] Analog watchdog channel selection */
#define TOFF_DFSDM_FLTISR  0x0008	/* (RW) DFSDM interrupt and status register */
  #define DFSDM_FLTISR_JEOCF     0x00000001	/* End of injected conversion flag */
  #define DFSDM_FLTISR_REOCF     0x00000002	/* End of regular conversion flag */
  #define DFSDM_FLTISR_JOVRF     0x00000004	/* Injected conversion overrun flag */
  #define DFSDM_FLTISR_ROVRF     0x00000008	/* Regular conversion overrun flag */
  #define DFSDM_FLTISR_AWDF      0x00000010	/* Analog watchdog */
  #define DFSDM_FLTISR_JCIP      0x00002000	/* Injected conversion in progress status */
  #define DFSDM_FLTISR_RCIP      0x00004000	/* Regular conversion in progress status */
  #define DFSDM_FLTISR_CKABF     0x00FF0000	/* CKABF[7:0] Clock absence flag */
  #define DFSDM_FLTISR_SCDF      0xFF000000	/* SCDF[7:0] Short circuit detector flag */
#define TOFF_DFSDM_FLTICR  0x000C	/* (RW) DFSDM interrupt flag clear register */
  #define DFSDM_FLTICR_CLRJOVRF  0x00000004	/* Clear the injected conversion overrun flag */
  #define DFSDM_FLTICR_CLRROVRF  0x00000008	/* Clear the regular conversion overrun flag */
  #define DFSDM_FLTICR_CLRCKABF  0x00FF0000	/* CLRCKABF[7:0] Clear the clock absence flag */
  #define DFSDM_FLTICR_CLRSCSDF  0xFF000000	/* CLRSCSDF[7:0] Clear the short circuit detector flag */
#define TOFF_DFSDM_FLTJCHGR 0x0010	/* (RW) DFSDM injected channel group selection register */
  #define DFSDM_FLTJCHGR_JCHG    0x000000FF	/* JCHG[7:0] Injected channel group selection */
#define TOFF_DFSDM_FLTFCR  0x0014	/* (RW) DFSDM filter control register */
  #define DFSDM_FLTFCR_IOSR      0x000000FF	/* IOSR[7:0] Integrator oversampling ratio (averaging length) */
  #define DFSDM_FLTFCR_FOSR      0x03FF0000	/* FOSR[9:0] Sinc filter oversampling ratio (decimation rate) */
  #define DFSDM_FLTFCR_FORD      0xE0000000	/* FORD[2:0] Sinc filter order */
  #define DFSDM_FLTFCR_FORD_2    0x80000000	/* Sinc filter order, Bit 2 */
  #define DFSDM_FLTFCR_FORD_1    0x40000000	/* Sinc filter order, Bit 1 */
  #define DFSDM_FLTFCR_FORD_0    0x20000000	/* Sinc filter order, Bit 0 */
#define TOFF_DFSDM_FLTJDATAR 0x0018	/* (RW) DFSDM data register for injected group */
  #define DFSDM_FLTJDATAR_JDATACH 0x00000007	/* JDATACH[2:0] Injected channel most recently converted */
  #define DFSDM_FLTJDATAR_JDATA   0xFFFFFF00	/* JDATA[23:0] Injected group conversion data */
#define TOFF_DFSDM_FLTRDATAR 0x001C	/* (RW) DFSDM data register for regular group */
  #define DFSDM_FLTRDATAR_RDATACH 0x00000007	/* RDATACH[2:0] Regular channel most recently converted */
  #define DFSDM_FLTRDATAR_RPEND   0x00000010	/* RPEND Regular channel pending data */
  #define DFSDM_FLTRDATAR_RDATA   0xFFFFFF00	/* RDATA[23:0] Regular channel conversion data */
#define TOFF_DFSDM_FLTAWHTR 0x0020	/* (RW) DFSDM analog watchdog high threshold register */
  #define DFSDM_FLTAWHTR_BKAWH   0x0000000F	/* BKAWH[3:0] Break signal assignment to analog watchdog high threshold event */
  #define DFSDM_FLTAWHTR_AWHT    0xFFFFFF00	/* AWHT[23:0] Analog watchdog high threshold */
#define TOFF_DFSDM_FLTAWLTR 0x0024	/* (RW) DFSDM analog watchdog low threshold register */
  #define DFSDM_FLTAWLTR_BKAWL   0x0000000F	/* BKAWL[3:0] Break signal assignment to analog watchdog low threshold event */
  #define DFSDM_FLTAWLTR_AWLT    0xFFFFFF00	/* AWLT[23:0] Analog watchdog low threshold */
#define TOFF_DFSDM_FLTAWSR  0x0028	/* (RW) DFSDM analog watchdog status register */
  #define DFSDM_FLTAWSR_AWLTF    0x000000FF	/* AWLTF[7:0] Analog watchdog low threshold error on given channels */
  #define DFSDM_FLTAWSR_AWHTF    0x0000FF00	/* AWHTF[15:8] Analog watchdog high threshold error on given channels */
#define TOFF_DFSDM_FLTAWCFR 0x002C	/* (RW) DFSDM analog watchdog clear flag register */
  #define DFSDM_FLTAWCFR_CLRAWLTF 0x000000FF	/* CLRAWLTF[7:0] Clear the Analog watchdog low threshold flag */
  #define DFSDM_FLTAWCFR_CLRAWHTF 0x0000FF00	/* CLRAWHTF[15:8] Clear the Analog watchdog high threshold flag */
#define TOFF_DFSDM_FLTEXMAX 0x0030	/* (RW) DFSDM extreme detector maximum register */
  #define DFSDM_FLTEXMAX_EXMAXCH 0x00000007	/* EXMAXCH[2:0] Extreme detector maximum data channel */
  #define DFSDM_FLTEXMAX_EXMAX   0xFFFFFF00	/* EXMAX[23:0] Extreme detector maximum value */
#define TOFF_DFSDM_FLTEXMIN 0x0034	/* (RW) DFSDM extreme detector minimum register */
  #define DFSDM_FLTEXMIN_EXMINCH 0x00000007	/* EXMINCH[2:0] Extreme detector minimum data channel */
  #define DFSDM_FLTEXMIN_EXMIN   0xFFFFFF00	/* EXMIN[23:0] Extreme detector minimum value */
#define TOFF_DFSDM_FLTCNVTIMR 0x0038/* (RW) DFSDM conversion timer */
  #define DFSDM_FLTCNVTIMR_CNVCNT 0xFFFFFFF0	/* CNVCNT[27:0]: 28-bit timer counting conversion time */

#endif

#endif  /* _STM32F7XX_H_ */

