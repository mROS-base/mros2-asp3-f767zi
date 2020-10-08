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
 *  @(#) $Id: stm32h7xx.h,v 1.4 2019/08/09 18:01:10 roi Exp $
 */

#ifndef _STM32H7XX_H_
#define _STM32H7XX_H_

/*
 *  Cortex-M7プロセッサとコアペイフェラル設定
 */
#include <sil.h>
#include "cmsis_h7.h"				/* Cortex-M7 processor and core peripherals      */

/*
 *  割込み番号の最大値
 */
#define TMAX_INTNO          (16 + 150)

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG             (16 + 0)	/* Window WatchDog Interrupt ( wwdg1_it, wwdg2_it) */
#define IRQ_VECTOR_PVD_AVD          (16 + 1)	/* PVD/AVD through EXTI Line detection Interrupt */
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
#define IRQ_VECTOR_ADC              (16 + 18)	/* ADC1 and ADC2 global Interrupts */
#define IRQ_VECTOR_FDCAN1_IT0       (16 + 19)	/* FDCAN1 Interrupt line 0 */
#define IRQ_VECTOR_FDCAN2_IT0       (16 + 20)	/* FDCAN2 Interrupt line 0 */
#define IRQ_VECTOR_FDCAN1_IT1       (16 + 21)	/* FDCAN1 Interrupt line 1 */
#define IRQ_VECTOR_FDCAN2_IT1       (16 + 22)	/* FDCAN2 Interrupt line 1 */
#define IRQ_VECTOR_EXTI9_5          (16 + 23)	/* External Line[9:5] Interrupts */
#define IRQ_VECTOR_TIM1_BRK         (16 + 24)	/* TIM1 Break Interrupt */
#define IRQ_VECTOR_TIM1_UP          (16 + 25)	/* TIM1 Update Interrupt */
#define IRQ_VECTOR_TIM1_TRG_COM     (16 + 26)	/* TIM1 Trigger and Commutation Interrupt */
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
#define IRQ_VECTOR_FDCAN_CAL        (16 + 63)	/* FDCAN Calibration unit Interrupt */
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
#define IRQ_VECTOR_CEC              (16 + 94)	/* HDMI-CEC global Interrupt */
#define IRQ_VECTOR_I2C4_EV          (16 + 95)	/* I2C4 Event Interrupt */
#define IRQ_VECTOR_I2C4_ER          (16 + 96)	/* I2C4 Error Interrupt */
#define IRQ_VECTOR_SPDIF_RX         (16 + 97)	/* SPDIF-RX global Interrupt */
#define IRQ_VECTOR_OTG_FS_EP1_OUT   (16 + 98)	/* USB OTG HS2 global interrupt                                      */
#define IRQ_VECTOR_OTG_FS_EP1_IN    (16 + 99)	/* USB OTG HS2 End Point 1 Out global interrupt */
#define IRQ_VECTOR_OTG_FS_WKUP      (16 + 100)	/* USB OTG HS2 End Point 1 In global interrupt */
#define IRQ_VECTOR_OTG_FS           (16 + 101)	/* USB OTG HS2 Wakeup through EXTI interrupt */
#define IRQ_VECTOR_DMAMUX1_OVR      (16 + 102)	/* DMAMUX1 Overrun interrupt */
#define IRQ_VECTOR_HRTIM1_Master    (16 + 103)	/* HRTIM Master Timer global Interrupts */
#define IRQ_VECTOR_HRTIM1_TIMA      (16 + 104)	/* HRTIM Timer A global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMB      (16 + 105)	/* HRTIM Timer B global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMC      (16 + 106)	/* HRTIM Timer C global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMD      (16 + 107)	/* HRTIM Timer D global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIME      (16 + 108)	/* HRTIM Timer E global Interrupt */
#define IRQ_VECTOR_HRTIM1_FLT       (16 + 109)	/* HRTIM Fault global Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT0      (16 + 110)	/* DFSDM Filter1 Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT1      (16 + 111)	/* DFSDM Filter2 Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT2      (16 + 112)	/* DFSDM Filter3 Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT3      (16 + 113)	/* DFSDM Filter4 Interrupt */
#define IRQ_VECTOR_SAI3             (16 + 114)	/* SAI3 global Interrupt */
#define IRQ_VECTOR_SWPMI1           (16 + 115)	/* Serial Wire Interface 1 global interrupt */
#define IRQ_VECTOR_TIM15            (16 + 116)	/* TIM15 global Interrupt */
#define IRQ_VECTOR_TIM16            (16 + 117)	/* TIM16 global Interrupt */
#define IRQ_VECTOR_TIM17            (16 + 118)	/* TIM17 global Interrupt */
#define IRQ_VECTOR_MDIOS_WKUP       (16 + 119)	/* MDIOS Wakeup  Interrupt */
#define IRQ_VECTOR_MDIOS            (16 + 120)	/* MDIOS global Interrupt */
#define IRQ_VECTOR_JPEG             (16 + 121)	/* JPEG global Interrupt */
#define IRQ_VECTOR_MDMA             (16 + 122)	/* MDMA global Interrupt */
#define IRQ_VECTOR_SDMMC2           (16 + 124)	/* SDMMC2 global Interrupt */
#define IRQ_VECTOR_HSEM1            (16 + 125)	/* HSEM1 global Interrupt */
#define IRQ_VECTOR_ADC3             (16 + 127)	/* ADC3 global Interrupt */
#define IRQ_VECTOR_DMAMUX2_OVR      (16 + 128)	/* DMAMUX2 Overrun interrupt */
#define IRQ_VECTOR_BDMA_Channel0    (16 + 129)	/* BDMA Channel 0 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel1    (16 + 130)	/* BDMA Channel 1 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel2    (16 + 131)	/* BDMA Channel 2 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel3    (16 + 132)	/* BDMA Channel 3 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel4    (16 + 133)	/* BDMA Channel 4 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel5    (16 + 134)	/* BDMA Channel 5 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel6    (16 + 135)	/* BDMA Channel 6 global Interrupt */
#define IRQ_VECTOR_BDMA_Channel7    (16 + 136)	/* BDMA Channel 7 global Interrupt */
#define IRQ_VECTOR_COMP             (16 + 137)	/* COMP global Interrupt */
#define IRQ_VECTOR_LPTIM2           (16 + 138)	/* LP TIM2 global interrupt */
#define IRQ_VECTOR_LPTIM3           (16 + 139)	/* LP TIM3 global interrupt */
#define IRQ_VECTOR_LPTIM4           (16 + 140)	/* LP TIM4 global interrupt */
#define IRQ_VECTOR_LPTIM5           (16 + 141)	/* LP TIM5 global interrupt */
#define IRQ_VECTOR_LPUART1          (16 + 142)	/* LP UART1 interrupt */
#define IRQ_VECTOR_CRS              (16 + 144)	/* Clock Recovery Global Interrupt */
#define IRQ_VECTOR_ECC              (16 + 145)	/* ECC diagnostic Global Interrupt */
#define IRQ_VECTOR_SAI4             (16 + 146)	/* SAI4 global interrupt */
#define IRQ_VECTOR_WAKEUP_PIN       (16 + 149)	/* Interrupt for all 6 wake-up pins */


/*
 *  PERIPHERAL MEMORY MAP
 */
#define D1_ITCMRAM_BASE     0x00000000	/* Base address of : 64KB RAM reserved for CPU execution/instruction accessible over ITCM  */
#define D1_ITCMICP_BASE     0x00100000	/* Base address of : (up to 128KB) embedded Test FLASH memory accessible over ITCM */
#define D1_DTCMRAM_BASE     0x20000000	/* Base address of : 128KB system data RAM accessible over DTCM */
#define D1_AXIFLASH_BASE    0x08000000	/* Base address of : (up to 2 MB) embedded FLASH memory accessible over AXI */
#define D1_AXIICP_BASE      0x1FF00000	/* Base address of : (up to 128KB) embedded Test FLASH memory accessible over AXI */
#define D1_AXISRAM_BASE     0x24000000	/* Base address of : (up to 512KB) system data RAM accessible over over AXI */
#define D2_AXISRAM_BASE     0x10000000	/* Base address of : (up to 288KB) system data RAM accessible over over AXI */
#define D2_AHBSRAM_BASE     0x30000000	/* Base address of : (up to 288KB) system data RAM accessible over over AXI->AHB Bridge */
#define D3_BKPSRAM_BASE     0x38800000	/* Base address of : Backup SRAM(4 KB) over AXI->AHB Bridge */
#define D3_SRAM_BASE        0x38000000	/* Base address of : Backup SRAM(64 KB) over AXI->AHB Bridge */

#define PERIPH_BASE         0x40000000	/* Base address of : AHB/ABP Peripherals */
#define QSPI_BASE           0x90000000	/* Base address of : QSPI memories  accessible over AXI */

#define FLASH_BANK1_BASE    0x08000000	/* Base address of : (up to 1 MB) Flash Bank1 accessible over AXI */
#define FLASH_BANK2_BASE    0x08100000	/* Base address of : (up to 1 MB) Flash Bank2 accessible over AXI */
#define FLASH_END           0x081FFFFF	/* FLASH end address */
#define FLASH_BASE          FLASH_BANK1_BASE	/* FLASH(up to 2 MB) base address in the alias region */

/* Device electronic signature memory map */
#define UID_BASE            0x1FF1E800	/* Unique device ID register base address */
#define FLASHSIZE_BASE      0x1FF1E880	/* FLASH Size register base address */


/* Peripheral memory map */
#define D2_APB1PERIPH_BASE  PERIPH_BASE
#define D2_APB2PERIPH_BASE  (PERIPH_BASE + 0x00010000)
#define D2_AHB1PERIPH_BASE  (PERIPH_BASE + 0x00020000)
#define D2_AHB2PERIPH_BASE  (PERIPH_BASE + 0x08020000)
#define D1_APB1PERIPH_BASE  (PERIPH_BASE + 0x10000000)
#define D1_AHB1PERIPH_BASE  (PERIPH_BASE + 0x12000000)
#define D3_APB1PERIPH_BASE  (PERIPH_BASE + 0x18000000)
#define D3_AHB1PERIPH_BASE  (PERIPH_BASE + 0x18020000)

#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x08000000)

/* USB registers base address */
#define USB_OTG_HS_PERIPH_BASE     0x40040000
#define USB_OTG_FS_PERIPH_BASE     0x40080000

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
 *  MDMA CONTROLLER
 */
#define TADR_MDMA_BASE      (D1_AHB1PERIPH_BASE + 0x0000)
#define TOFF_MDMA_GISR0     0x0000		/* MDMA Global Interrupt/Status Register 0 */
  #define MDMA_GISR0_GIF0    0x00000001	/* Channel 0 global interrupt flag */
  #define MDMA_GISR0_GIF1    0x00000002	/* Channel 1 global interrupt flag */
  #define MDMA_GISR0_GIF2    0x00000004	/* Channel 2 global interrupt flag */
  #define MDMA_GISR0_GIF3    0x00000008	/* Channel 3 global interrupt flag */
  #define MDMA_GISR0_GIF4    0x00000010	/* Channel 4 global interrupt flag */
  #define MDMA_GISR0_GIF5    0x00000020	/* Channel 5 global interrupt flag */
  #define MDMA_GISR0_GIF6    0x00000040	/* Channel 6 global interrupt flag */
  #define MDMA_GISR0_GIF7    0x00000080	/* Channel 7 global interrupt flag */
  #define MDMA_GISR0_GIF8    0x00000100	/* Channel 8 global interrupt flag */
  #define MDMA_GISR0_GIF9    0x00000200	/* Channel 9 global interrupt flag */
  #define MDMA_GISR0_GIF10   0x00000400	/* Channel 10 global interrupt flag */
  #define MDMA_GISR0_GIF11   0x00000800	/* Channel 11 global interrupt flag */
  #define MDMA_GISR0_GIF12   0x00001000	/* Channel 12 global interrupt flag */
  #define MDMA_GISR0_GIF13   0x00002000	/* Channel 13 global interrupt flag */
  #define MDMA_GISR0_GIF14   0x00004000	/* Channel 14 global interrupt flag */
  #define MDMA_GISR0_GIF15   0x00008000	/* Channel 15 global interrupt flag */

#define TADR_MDMA_CH0_BASE  (TADR_MDMA_BASE + 0x0040)
#define TADR_MDMA_CH1_BASE  (TADR_MDMA_BASE + 0x0080)
#define TADR_MDMA_CH2_BASE  (TADR_MDMA_BASE + 0x00C0)
#define TADR_MDMA_CH3_BASE  (TADR_MDMA_BASE + 0x0100)
#define TADR_MDMA_CH4_BASE  (TADR_MDMA_BASE + 0x0140)
#define TADR_MDMA_CH5_BASE  (TADR_MDMA_BASE + 0x0180)
#define TADR_MDMA_CH6_BASE  (TADR_MDMA_BASE + 0x01C0)
#define TADR_MDMA_CH7_BASE  (TADR_MDMA_BASE + 0x0200)
#define TADR_MDMA_CH8_BASE  (TADR_MDMA_BASE + 0x0240)
#define TADR_MDMA_CH9_BASE  (TADR_MDMA_BASE + 0x0280)
#define TADR_MDMA_CH10_BASE (TADR_MDMA_BASE + 0x02C0)
#define TADR_MDMA_CH11_BASE (TADR_MDMA_BASE + 0x0300)
#define TADR_MDMA_CH12_BASE (TADR_MDMA_BASE + 0x0340)
#define TADR_MDMA_CH13_BASE (TADR_MDMA_BASE + 0x0380)
#define TADR_MDMA_CH14_BASE (TADR_MDMA_BASE + 0x03C0)
#define TADR_MDMA_CH15_BASE (TADR_MDMA_BASE + 0x0400)
#define TADR_MDMA_CISR      0x0000		/* (RW) MDMA channel x interrupt/status register */
  #define MDMA_CISR_TEIF     0x00000001	/* Channel x transfer error interrupt flag */
  #define MDMA_CISR_CTCIF    0x00000002	/* Channel x Channel Transfer Complete interrupt flag */
  #define MDMA_CISR_BRTIF    0x00000004	/* Channel x block repeat transfer complete interrupt flag */
  #define MDMA_CISR_BTIF     0x00000008	/* Channel x block transfer complete interrupt flag */
  #define MDMA_CISR_TCIF     0x00000010	/* Channel x buffer transfer complete interrupt flag */
  #define MDMA_CISR_CRQA     0x00010000	/* Channel x ReQest Active flag */
#define TADR_MDMA_CIFCR     0x0004		/* (RW) MDMA channel x interrupt flag clear register */
  #define MDMA_CIFCR_CTEIF   0x00000001	/* Channel x clear transfer error interrupt flag */
  #define MDMA_CIFCR_CCTCIF  0x00000002	/* Clear Channel transfer complete interrupt flag for channel x */
  #define MDMA_CIFCR_CBRTIF  0x00000004	/* Channel x clear block repeat transfer complete interrupt flag */
  #define MDMA_CIFCR_CBTIF   0x00000008	/* Channel x Clear block transfer complete interrupt flag */
  #define MDMA_CIFCR_CLTCIF  0x00000010	/* CLear Transfer buffer Complete Interrupt Flag for channel */
#define TADR_MDMA_CESR      0x0008		/* (RW) MDMA Channel x error status register */
  #define MDMA_CESR_TEA      0x0000007F	/* Transfer Error Address */
  #define MDMA_CESR_TED      0x00000080	/* Transfer Error Direction */
  #define MDMA_CESR_TELD     0x00000100	/* Transfer Error Link Data */
  #define MDMA_CESR_TEMD     0x00000200	/* Transfer Error Mask Data */
  #define MDMA_CESR_ASE      0x00000400	/* Address/Size Error       */
  #define MDMA_CESR_BSE      0x00000800	/* Block Size Error         */
#define TADR_MDMA_CCR       0x000C		/* (RW) MDMA channel x control register */
  #define MDMA_CCR_EN        0x00000001	/* Channel enable / flag channel ready when read low */
  #define MDMA_CCR_TEIE      0x00000002	/* Transfer error interrupt enable */
  #define MDMA_CCR_CTCIE     0x00000004	/* Channel Transfer Complete interrupt enable */
  #define MDMA_CCR_BRTIE     0x00000008	/* Block Repeat transfer interrupt enable */
  #define MDMA_CCR_BTIE      0x00000010	/* Block Transfer interrupt enable */
  #define MDMA_CCR_TCIE      0x00000020	/* buffer Transfer Complete interrupt enable */
  #define MDMA_CCR_PL        0x000000C0	/* Priority level */
  #define MDMA_CCR_PL_0      0x00000040
  #define MDMA_CCR_PL_1      0x00000080
  #define MDMA_CCR_BEX       0x00001000	/* Byte Endianess eXchange */
  #define MDMA_CCR_HEX       0x00002000	/* Half word Endianess eXchange */
  #define MDMA_CCR_WEX       0x00004000	/* Word Endianess eXchange */
  #define MDMA_CCR_SWRQ      0x00010000	/* SW ReQuest */
#define TADR_MDMA_CTCR      0x0010		/* (RW) MDMA channel x Transfer Configuration register */
  #define MDMA_CTCR_SINC     0x00000003	/* Source increment mode */
  #define MDMA_CTCR_SINC_0   0x00000001
  #define MDMA_CTCR_SINC_1   0x00000002
  #define MDMA_CTCR_DINC     0x0000000C	/* Source increment mode */
  #define MDMA_CTCR_DINC_0   0x00000004
  #define MDMA_CTCR_DINC_1   0x00000008
  #define MDMA_CTCR_SSIZE    0x00000030	/* Source data size */
  #define MDMA_CTCR_SSIZE_0  0x00000010
  #define MDMA_CTCR_SSIZE_1  0x00000020
  #define MDMA_CTCR_DSIZE    0x000000C0	/* Destination data size */
  #define MDMA_CTCR_DSIZE_0  0x00000040
  #define MDMA_CTCR_DSIZE_1  0x00000080
  #define MDMA_CTCR_SINCOS   0x00000300	/* Source increment offset size */
  #define MDMA_CTCR_SINCOS_0 0x00000100
  #define MDMA_CTCR_SINCOS_1 0x00000200
  #define MDMA_CTCR_DINCOS   0x00000C00	/* Destination increment offset size */
  #define MDMA_CTCR_DINCOS_0 0x00000400
  #define MDMA_CTCR_DINCOS_1 0x00000800
  #define MDMA_CTCR_SBURST   0x00007000	/* Source burst transfer configuration */
  #define MDMA_CTCR_SBURST_0 0x00001000
  #define MDMA_CTCR_SBURST_1 0x00002000
  #define MDMA_CTCR_SBURST_2 0x00004000
  #define MDMA_CTCR_DBURST   0x00038000	/* Destination burst transfer configuration */
  #define MDMA_CTCR_DBURST_0 0x00008000
  #define MDMA_CTCR_DBURST_1 0x00010000
  #define MDMA_CTCR_DBURST_2 0x00020000
  #define MDMA_CTCR_TLEN     0x01FC0000	/* buffer Transfer Length (number of bytes - 1) */
  #define MDMA_CTCR_PKE      0x02000000	/* PacK Enable */
  #define MDMA_CTCR_PAM      0x0C000000	/* Padding/Alignement Mode */
  #define MDMA_CTCR_PAM_0    0x04000000
  #define MDMA_CTCR_PAM_1    0x08000000
  #define MDMA_CTCR_TRGM     0x30000000	/* Trigger Mode */
  #define MDMA_CTCR_TRGM_0   0x10000000
  #define MDMA_CTCR_TRGM_1   0x20000000
  #define MDMA_CTCR_SWRM     0x40000000	/* SW Request Mode */
  #define MDMA_CTCR_BWM      0x80000000	/* Bufferable Write Mode */
#define TADR_MDMA_CBNDTR    0x0014		/* (RW) MDMA Channel x block number of data register */
  #define MDMA_CBNDTR_BNDT   0x0001FFFF	/* Block Number of data bytes to transfer */
  #define MDMA_CBNDTR_BRSUM  0x00040000	/* Block Repeat Source address Update Mode */
  #define MDMA_CBNDTR_BRDUM  0x00080000	/* Block Repeat Destination address Update Mode */
  #define MDMA_CBNDTR_BRC    0xFFF00000	/* Block Repeat Count */
#define TADR_MDMA_CSAR      0x0018		/* (RW) MDMA channel x source address register */
#define TADR_MDMA_CDAR      0x001C		/* (RW) MDMA channel x destination address register */
#define TADR_MDMA_CBRUR     0x0020		/* (RW) MDMA channel x Block Repeat address Update register */
  #define MDMA_CBRUR_SUV     0x0000FFFF	/* Source address Update Value */
  #define MDMA_CBRUR_DUV     0xFFFF0000	/* Destination address Update Value */
#define TADR_MDMA_CLAR      0x0024		/* (RW) MDMA channel x Link Address register */
#define TADR_MDMA_CTBR      0x0028		/* (RW) MDMA channel x Trigger and Bus selection Register */
  #define MDMA_CTBR_TSEL     0x000000FF	/* Trigger SELection */
  #define MDMA_CTBR_SBUS     0x00010000	/* Source BUS select */
  #define MDMA_CTBR_DBUS     0x00020000	/* Destination BUS select */
#define TADR_MDMA_CMAR      0x0030		/* (RW) MDMA channel x Mask address register */
#define TADR_MDMA_CMDR      0x0034		/* (RW) MDMA channel x Mask Data register */


/*
 *  JPEG CODEC
 */
#define TADR_JPGDEC_BASE    (D1_AHB1PERIPH_BASE + 0x3000)
#define TOFF_JPEG_CONFR0    0x0000		/* (RW) JPEG Codec Control Register (JPEG_CONFR0) */
  #define JPEG_CONFR0_START  0x00000001/* Start/Stop bit */
#define TOFF_JPEG_CONFR1    0x0004		/* (RW) JPEG Codec Control Register (JPEG_CONFR1) */
  #define JPEG_CONFR1_NF     0x00000003	/* Number of color components */
  #define JPEG_CONFR1_NF_0   0x00000001
  #define JPEG_CONFR1_NF_1   0x00000002
  #define JPEG_CONFR1_DE     0x00000008	/* Decoding Enable */
  #define JPEG_CONFR1_COLORSPACE   0x00000030	/* Color Space */
  #define JPEG_CONFR1_COLORSPACE_0 0x00000010
  #define JPEG_CONFR1_COLORSPACE_1 0x00000020
  #define JPEG_CONFR1_NS     0x000000C0	/* Number of components for Scan */
  #define JPEG_CONFR1_NS_0   0x00000040
  #define JPEG_CONFR1_NS_1   0x00000080
  #define JPEG_CONFR1_HDR    0x00000100	/* Header Processing On/Off */
  #define JPEG_CONFR1_YSIZE  0xFFFF0000	/* Number of lines in source image */
#define TOFF_JPEG_CONFR2    0x0008		/* (RW) JPEG Codec Control Register (JPEG_CONFR2) */
  #define JPEG_CONFR2_NMCU   0x03FFFFFF	/* Number of MCU units minus 1 to encode */
#define TOFF_JPEG_CONFR3    0x000C		/* (RW) JPEG Codec Control Register (JPEG_CONFR3) */
  #define JPEG_CONFR3_XSIZE  0xFFFF0000	/* Number of pixels per line */
#define TOFF_JPEG_CONFR4    0x0010		/* (RW) JPEG Codec Control Register (JPEG_CONFR4) */
  #define JPEG_CONFR4_HD     0x00000001	/* Selects the Huffman table for encoding the DC coefficients */
  #define JPEG_CONFR4_HA     0x00000002	/* Selects the Huffman table for encoding the AC coefficients */
  #define JPEG_CONFR4_QT     0x0000000C	/* Selects quantization table associated with a color component */
  #define JPEG_CONFR4_QT_0   0x00000004
  #define JPEG_CONFR4_QT_1   0x00000008
  #define JPEG_CONFR4_NB     0x000000F0	/* Number of data units minus 1 that belong to a particular color in the MCU */
  #define JPEG_CONFR4_NB_0   0x00000010
  #define JPEG_CONFR4_NB_1   0x00000020
  #define JPEG_CONFR4_NB_2   0x00000040
  #define JPEG_CONFR4_NB_3   0x00000080
  #define JPEG_CONFR4_VSF    0x00000F00	/* Vertical sampling factor for component 1 */
  #define JPEG_CONFR4_VSF_0  0x00000100
  #define JPEG_CONFR4_VSF_1  0x00000200
  #define JPEG_CONFR4_VSF_2  0x00000400
  #define JPEG_CONFR4_VSF_3  0x00000800
  #define JPEG_CONFR4_HSF    0x0000F000	/* Horizontal sampling factor for component 1 */
  #define JPEG_CONFR4_HSF_0  0x00001000
  #define JPEG_CONFR4_HSF_1  0x00002000
  #define JPEG_CONFR4_HSF_2  0x00004000
  #define JPEG_CONFR4_HSF_3  0x00008000
#define TOFF_JPEG_CONFR5    0x0014		/* (RW) JPEG Codec Control Register (JPEG_CONFR5) */
  #define JPEG_CONFR5_HD     0x00000001	/* Selects the Huffman table for encoding the DC coefficients */
  #define JPEG_CONFR5_HA     0x00000002	/* Selects the Huffman table for encoding the AC coefficients */
  #define JPEG_CONFR5_QT     0x0000000C	/* Selects quantization table associated with a color component */
  #define JPEG_CONFR5_QT_0   0x00000004
  #define JPEG_CONFR5_QT_1   0x00000008
  #define JPEG_CONFR5_NB     0x000000F0	/* Number of data units minus 1 that belong to a particular color in the MCU */
  #define JPEG_CONFR5_NB_0   0x00000010
  #define JPEG_CONFR5_NB_1   0x00000020
  #define JPEG_CONFR5_NB_2   0x00000040
  #define JPEG_CONFR5_NB_3   0x00000080
  #define JPEG_CONFR5_VSF    0x00000F00	/* Vertical sampling factor for component 2 */
  #define JPEG_CONFR5_VSF_0  0x00000100
  #define JPEG_CONFR5_VSF_1  0x00000200
  #define JPEG_CONFR5_VSF_2  0x00000400
  #define JPEG_CONFR5_VSF_3  0x00000800
  #define JPEG_CONFR5_HSF    0x0000F000	/* Horizontal sampling factor for component 2 */
  #define JPEG_CONFR5_HSF_0  0x00001000
  #define JPEG_CONFR5_HSF_1  0x00002000
  #define JPEG_CONFR5_HSF_2  0x00004000
  #define JPEG_CONFR5_HSF_3  0x00008000
#define TOFF_JPEG_CONFR6    0x0018		/* (RW) JPEG Codec Control Register (JPEG_CONFR6) */
  #define JPEG_CONFR6_HD     0x00000001	/* Selects the Huffman table for encoding the DC coefficients */
  #define JPEG_CONFR6_HA     0x00000002	/* Selects the Huffman table for encoding the AC coefficients */
  #define JPEG_CONFR6_QT     0x0000000C	/* Selects quantization table associated with a color component */
  #define JPEG_CONFR6_QT_0   0x00000004
  #define JPEG_CONFR6_QT_1   0x00000008
  #define JPEG_CONFR6_NB     0x000000F0	/* Number of data units minus 1 that belong to a particular color in the MCU */
  #define JPEG_CONFR6_NB_0   0x00000010
  #define JPEG_CONFR6_NB_1   0x00000020
  #define JPEG_CONFR6_NB_2   0x00000040
  #define JPEG_CONFR6_NB_3   0x00000080
  #define JPEG_CONFR6_VSF    0x00000F00	/* Vertical sampling factor for component 2 */
  #define JPEG_CONFR6_VSF_0  0x00000100
  #define JPEG_CONFR6_VSF_1  0x00000200
  #define JPEG_CONFR6_VSF_2  0x00000400
  #define JPEG_CONFR6_VSF_3  0x00000800
  #define JPEG_CONFR6_HSF    0x0000F000	/* Horizontal sampling factor for component 2 */
  #define JPEG_CONFR6_HSF_0  0x00001000
  #define JPEG_CONFR6_HSF_1  0x00002000
  #define JPEG_CONFR6_HSF_2  0x00004000
  #define JPEG_CONFR6_HSF_3  0x00008000
#define TOFF_JPEG_CONFR7    0x001C		/* (RW) JPEG Codec Control Register (JPEG_CONFR7) */
  #define JPEG_CONFR7_HD     0x00000001	/* Selects the Huffman table for encoding the DC coefficients */
  #define JPEG_CONFR7_HA     0x00000002	/* Selects the Huffman table for encoding the AC coefficients */
  #define JPEG_CONFR7_QT     0x0000000C	/* Selects quantization table associated with a color component */
  #define JPEG_CONFR7_QT_0   0x00000004
  #define JPEG_CONFR7_QT_1   0x00000008
  #define JPEG_CONFR7_NB     0x000000F0	/* Number of data units minus 1 that belong to a particular color in the MCU */
  #define JPEG_CONFR7_NB_0   0x00000010
  #define JPEG_CONFR7_NB_1   0x00000020
  #define JPEG_CONFR7_NB_2   0x00000040
  #define JPEG_CONFR7_NB_3   0x00000080
  #define JPEG_CONFR7_VSF    0x00000F00	/* Vertical sampling factor for component 2 */
  #define JPEG_CONFR7_VSF_0  0x00000100
  #define JPEG_CONFR7_VSF_1  0x00000200
  #define JPEG_CONFR7_VSF_2  0x00000400
  #define JPEG_CONFR7_VSF_3  0x00000800
  #define JPEG_CONFR7_HSF    0x0000F000	/* Horizontal sampling factor for component 2 */
  #define JPEG_CONFR7_HSF_0  0x00001000
  #define JPEG_CONFR7_HSF_1  0x00002000
  #define JPEG_CONFR7_HSF_2  0x00004000
  #define JPEG_CONFR7_HSF_3  0x00008000
#define TOFF_JPEG_CR        0x0030		/* (RW) JPEG Control Register (JPEG_CR) */
  #define JPEG_CR_JCEN       0x00000001	/* Enable the JPEG Codec Core */
  #define JPEG_CR_IFTIE      0x00000002	/* Input FIFO Threshold Interrupt Enable */
  #define JPEG_CR_IFNFIE     0x00000004	/* Input FIFO Not Full Interrupt Enable */
  #define JPEG_CR_OFTIE      0x00000008	/* Output FIFO Threshold Interrupt Enable */
  #define JPEG_CR_OFNEIE     0x00000010	/* Output FIFO Not Empty Interrupt Enable */
  #define JPEG_CR_EOCIE      0x00000020	/* End of Conversion Interrupt Enable */
  #define JPEG_CR_HPDIE      0x00000040	/* Header Parsing Done Interrupt Enable */
  #define JPEG_CR_IFF        0x00002000	/* Flush the input FIFO */
  #define JPEG_CR_OFF        0x00004000	/* Flush the output FIFO */
#define TOFF_JPEG_SR        0x0034		/* (RW) JPEG Status Register (JPEG_SR) */
  #define JPEG_SR_IFTF       0x00000002	/* Input FIFO is not full and is bellow its threshold flag */
  #define JPEG_SR_IFNFF      0x00000004	/* Input FIFO Not Full Flag, a data can be written */
  #define JPEG_SR_OFTF       0x00000008	/* Output FIFO is not empty and has reach its threshold */
  #define JPEG_SR_OFNEF      0x00000010	/* Output FIFO is not empty, a data is available */
  #define JPEG_SR_EOCF       0x00000020	/* JPEG Codec core has finished the encoding or the decoding process and than last data has been sent to the output FIFO */
  #define JPEG_SR_HPDF       0x00000040	/* JPEG Codec has finished the parsing of the headers and the internal registers have been updated */
  #define JPEG_SR_COF        0x00000080	/* JPEG Codec operation on going flag */
#define TOFF_JPEG_CFR       0x0038		/* (RW) JPEG Clear Flag Register (JPEG_CFR) */
  #define JPEG_CFR_CEOCF     0x00000010	/* Clear End of Conversion Flag */
  #define JPEG_CFR_CHPDF     0x00000020	/* Clear Header Parsing Done Flag */
#define TOFF_JPEG_DIR       0x0040		/* (RW) JPEG Data Input Register (JPEG_DIR) */
#define TOFF_JPEG_DOR       0x0044		/* (RW) JPEG Data Output Register (JPEG_DOR) */
#define TOFF_JPEG_QMEM0     0x0050		/* (RW) JPEG quantization tables 0 [0-15] */
#define TOFF_JPEG_QMEM1     0x0090		/* (RW) JPEG quantization tables 1 [0-15] */
#define TOFF_JPEG_QMEM2     0x00D0		/* (RW) JPEG quantization tables 2 [0-15] */
#define TOFF_JPEG_QMEM3     0x0110		/* (RW) JPEG quantization tables 3 [0-15] */
#define TOFF_JPEG_HUFFMIN   0x0150		/* (RW) JPEG HuffMin tables [0-15] */
#define TOFF_JPEG_HUFFBASE  0x0190		/* (RW) JPEG HuffSymb tables [0-31] */
#define TOFF_JPEG_HUFFSYMB  0x0210		/* (RW) JPEG HUFFSYMB tables [0-83] */
#define TOFF_JPEG_DHTMEM    0x0360		/* (RW) JPEG DHTMem tables [0-102] */
#define TOFF_JPEG_HUFFENC_AC0 0x0500	/* (RW) JPEG encodor, AC Huffman table0 [0-87] */
#define TOFF_JPEG_HUFFENC_AC1 0x0660	/* (RW) JPEG encodor, AC Huffman table1 [0-87] */
#define TOFF_JPEG_HUFFENC_DC0 0x07C0	/* (RW) JPEG encodor, DC Huffman table 0 [0-7] */
#define TOFF_JPEG_HUFFENC_DC1 0x07E0	/* (RW) JPEG encodor, DC Huffman table 1 [0-7] */


/*
 *  DELAY Block DLYB
 */
#define TADR_DLYB_QSPI_BASE   (D1_AHB1PERIPH_BASE + 0x6000)
#define TADR_DLYB_SDMMC1_BASE (D1_AHB1PERIPH_BASE + 0x8000)
#define TADR_DLYB_SDMMC2_BASE (D2_AHB2PERIPH_BASE + 0x2800)
#define TOFF_DLYB_CR        0x0000		/* (RW) DELAY BLOCK control register */
  #define DLYB_CR_DEN        0x00000001	/* Delay Block enable */
  #define DLYB_CR_SEN        0x00000002	/* Sampler length enable */
#define TOFF_DLYB_CFGR      0x0004	/* (RW) DELAY BLOCK configuration register */
  #define DLYB_CFGR_SEL      0x0000000F	/* Select the phase for the Output clock[3:0] */
  #define DLYB_CFGR_SEL_0    0x00000001
  #define DLYB_CFGR_SEL_1    0x00000002
  #define DLYB_CFGR_SEL_2    0x00000003
  #define DLYB_CFGR_SEL_3    0x00000008
  #define DLYB_CFGR_UNIT     0x00007F00	/* Delay Defines the delay of a Unit delay cell[6:0] */
  #define DLYB_CFGR_UNIT_0   0x00000100
  #define DLYB_CFGR_UNIT_1   0x00000200
  #define DLYB_CFGR_UNIT_2   0x00000400
  #define DLYB_CFGR_UNIT_3   0x00000800
  #define DLYB_CFGR_UNIT_4   0x00001000
  #define DLYB_CFGR_UNIT_5   0x00002000
  #define DLYB_CFGR_UNIT_6   0x00004000
  #define DLYB_CFGR_LNG      0x0FFF0000	/* Delay line length value[11:0] */
  #define DLYB_CFGR_LNG_0    0x00010000
  #define DLYB_CFGR_LNG_1    0x00020000
  #define DLYB_CFGR_LNG_2    0x00040000
  #define DLYB_CFGR_LNG_3    0x00080000
  #define DLYB_CFGR_LNG_4    0x00100000
  #define DLYB_CFGR_LNG_5    0x00200000
  #define DLYB_CFGR_LNG_6    0x00400000
  #define DLYB_CFGR_LNG_7    0x00800000
  #define DLYB_CFGR_LNG_8    0x01000000
  #define DLYB_CFGR_LNG_9    0x02000000
  #define DLYB_CFGR_LNG_10   0x04000000
  #define DLYB_CFGR_LNG_11   0x08000000
  #define DLYB_CFGR_LNGF     0x80000000	/* Length valid flag */



/**
  * @brief RAM_ECC_Specific_Registers
  */

#define TADR_RAMECC1_BASE   (D1_AHB1PERIPH_BASE + 0x9000)
#define TADR_RAMECC2_BASE   (D2_AHB2PERIPH_BASE + 0x3000)
#define TADR_RAMECC3_BASE   (D3_AHB1PERIPH_BASE + 0x7000)
#define TOFF_RAMECC_IER     0x0000		/* (RW) RAMECC interrupt enable register */
  #define RAMECC_IER_GIE          0x00000001	/* Global interrupt enable */
  #define RAMECC_IER_GECCSEIE     0x00000002	/* Global ECC single error interrupt enable */
  #define RAMECC_IER_GECCDEIE     0x00000004	/* Global ECC double error interrupt enable */
  #define RAMECC_IER_GECCDEBWIE   0x00000008	/* Global ECC double error on byte write (BW) interrupt enable */
#define TADR_RAMECC1_Monitor1_BASE (TADR_RAMECC1_BASE + 0x20)
#define TADR_RAMECC1_Monitor2_BASE (TADR_RAMECC1_BASE + 0x40)
#define TADR_RAMECC1_Monitor3_BASE (TADR_RAMECC1_BASE + 0x60)
#define TADR_RAMECC1_Monitor4_BASE (TADR_RAMECC1_BASE + 0x80)
#define TADR_RAMECC1_Monitor5_BASE (TADR_RAMECC1_BASE + 0xA0)

#define TADR_RAMECC2_Monitor1_BASE (TADR_RAMECC2_BASE + 0x20)
#define TADR_RAMECC2_Monitor2_BASE (TADR_RAMECC2_BASE + 0x40)
#define TADR_RAMECC2_Monitor3_BASE (TADR_RAMECC2_BASE + 0x60)
#define TADR_RAMECC2_Monitor4_BASE (TADR_RAMECC2_BASE + 0x80)
#define TADR_RAMECC2_Monitor5_BASE (TADR_RAMECC2_BASE + 0xA0)

#define TADR_RAMECC3_Monitor1_BASE (TADR_RAMECC3_BASE + 0x20)
#define TADR_RAMECC3_Monitor2_BASE (TADR_RAMECC3_BASE + 0x40)
#define TOFF_RAMECC_CR      0x0000		/* (RW) RAMECC monitor configuration register */
  #define RAMECC_CR_ECCSEIE     0x00000004	/* ECC single error interrupt enable */
  #define RAMECC_CR_ECCDEIE     0x00000008	/* ECC double error interrupt enable */
  #define RAMECC_CR_ECCDEBWIE   0x00000010	/* ECC double error on byte write (BW) interrupt enable */
  #define RAMECC_CR_ECCELEN     0x00000020	/* ECC error latching enable */
#define TOFF_RAMECC_SR      0x0004		/* (RW) RAMECC monitor status register */
  #define RAMECC_SR_SEDCF       0x00000001	/* ECC single error detected and corrected flag */
  #define RAMECC_SR_DEDF        0x00000002	/* ECC double error detected flag */
  #define RAMECC_SR_DEBWDF      0x00000004	/* ECC double error on byte write (BW) detected flag */
#define TOFF_RAMECC_FAR     0x0008		/* (RW) RAMECC monitor failing address register */
#define TOFF_RAMECC_FDRL    0x000C		/* (RW) RAMECC monitor failing data low register       */
#define TOFF_RAMECC_FDRH    0x0010		/* (RW) RAMECC monitor failing data high register      */
#define TOFF_RAMECC_FECR    0x0014		/* (RW) RAMECC monitor failing ECC error code register */


/*
 *  TIM
 */
#define TADR_TIM1_BASE      (D2_APB2PERIPH_BASE + 0x0000)
#define TADR_TIM2_BASE      (D2_APB1PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (D2_APB1PERIPH_BASE + 0x0400)
#define TADR_TIM4_BASE      (D2_APB1PERIPH_BASE + 0x0800)
#define TADR_TIM5_BASE      (D2_APB1PERIPH_BASE + 0x0C00)
#define TADR_TIM6_BASE      (D2_APB1PERIPH_BASE + 0x1000)
#define TADR_TIM7_BASE      (D2_APB1PERIPH_BASE + 0x1400)
#define TADR_TIM8_BASE      (D2_APB2PERIPH_BASE + 0x0400)
#define TADR_TIM12_BASE     (D2_APB1PERIPH_BASE + 0x1800)
#define TADR_TIM13_BASE     (D2_APB1PERIPH_BASE + 0x1C00)
#define TADR_TIM14_BASE     (D2_APB1PERIPH_BASE + 0x2000)
#define TADR_TIM15_BASE     (D2_APB2PERIPH_BASE + 0x4000)
#define TADR_TIM16_BASE     (D2_APB2PERIPH_BASE + 0x4400)
#define TADR_TIM17_BASE     (D2_APB2PERIPH_BASE + 0x4800)
#define TOFF_TIM_CR1        0x0000		/* (RW) TIM control register 1 */
  #define TIM_CR1_CEN        0x00000001	/* Counter enable */
  #define TIM_CR1_UDIS       0x00000002	/* Update disable */
  #define TIM_CR1_URS        0x00000004	/* Update request source */
  #define TIM_CR1_OPM        0x00000008	/* One pulse mode */
  #define TIM_CR1_DIR        0x00000010	/* Direction */
  #define TIM_CR1_CMS_0      0x00000020	/* CMS[1:0] bit 0 */
  #define TIM_CR1_CMS_1      0x00000040	/* CMS[1:0] bit 1 */
  #define TIM_CR1_ARPE       0x00000080	/* Auto-reload preload enable */
  #define TIM_CR1_CKD_0      0x00000100	/* CKD[1:0] bit 0 */
  #define TIM_CR1_CKD_1      0x00000200	/* CKD[1:0] bit 1 */
  #define TIM_CR1_UIFREMAP   0x00000800	/* UIF status bit */
#define TOFF_TIM_CR2        0x0004		/* (RW) TIM control register 2 */
  #define TIM_CR2_CCPC       0x00000001	/* Capture/Compare Preloaded Control        */
  #define TIM_CR2_CCUS       0x00000004	/* Capture/Compare Control Update Selection */
  #define TIM_CR2_CCDS       0x00000008	/* Capture/Compare DMA Selection            */
  #define TIM_CR2_MMS        0x00000070	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS_0      0x00000010	/* Bit 0 */
  #define TIM_CR2_MMS_1      0x00000020	/* Bit 1 */
  #define TIM_CR2_MMS_2      0x00000040	/* Bit 2 */
  #define TIM_CR2_TI1S       0x00000080	/* TI1 Selection */
  #define TIM_CR2_OIS1       0x00000100	/* Output Idle state 1 (OC1 output)  */
  #define TIM_CR2_OIS1N      0x00000200	/* Output Idle state 1 (OC1N output) */
  #define TIM_CR2_OIS2       0x00000400	/* Output Idle state 2 (OC2 output)  */
  #define TIM_CR2_OIS2N      0x00000800	/* Output Idle state 2 (OC2N output) */
  #define TIM_CR2_OIS3       0x00001000	/* Output Idle state 3 (OC3 output)  */
  #define TIM_CR2_OIS3N      0x00002000	/* Output Idle state 3 (OC3N output) */
  #define TIM_CR2_OIS4       0x00004000	/* Output Idle state 4 (OC4 output)  */
  #define TIM_CR2_OIS5       0x00010000	/* Output Idle state 5 (OC5 output) */
  #define TIM_CR2_OIS6       0x00020000	/* Output Idle state 6 (OC6 output) */
  #define TIM_CR2_MMS2       0x00F00000	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS2_0     0x00100000
  #define TIM_CR2_MMS2_1     0x00200000
  #define TIM_CR2_MMS2_2     0x00400000
  #define TIM_CR2_MMS2_3     0x00800000
#define TOFF_TIM_SMCR       0x0008		/* (RW) TIM slave mode control register */
  #define TIM_SMCR_SMS       0x00010007	/* SMS[2:0] bits (Slave mode selection)    */
  #define TIM_SMCR_SMS_0     0x00000001	/* Bit 0 */
  #define TIM_SMCR_SMS_1     0x00000002	/* Bit 1 */
  #define TIM_SMCR_SMS_2     0x00000004	/* Bit 2 */
  #define TIM_SMCR_SMS_3     0x00010000	/* Bit 3 */
  #define TIM_SMCR_OCCS      0x00000008	/* OCREF clear selection */
  #define TIM_SMCR_TS        0x00300070	/* TS[2:0] bits (Trigger selection)        */
  #define TIM_SMCR_TS_0      0x00000010	/* Bit 0 */
  #define TIM_SMCR_TS_1      0x00000020	/* Bit 1 */
  #define TIM_SMCR_TS_2      0x00000040	/* Bit 2 */
  #define TIM_SMCR_TS_3      0x00100000
  #define TIM_SMCR_TS_4      0x00200000
  #define TIM_SMCR_MSM       0x00000080	/* Master/slave mode                       */
  #define TIM_SMCR_ETF       0x00000F00	/* ETF[3:0] bits (External trigger filter) */
  #define TIM_SMCR_ETF_0     0x00000100	/* Bit 0 */
  #define TIM_SMCR_ETF_1     0x00000200	/* Bit 1 */
  #define TIM_SMCR_ETF_2     0x00000400	/* Bit 2 */
  #define TIM_SMCR_ETF_3     0x00000800	/* Bit 3 */
  #define TIM_SMCR_ETPS      0x00003000	/* ETPS[1:0] bits (External trigger prescaler) */
  #define TIM_SMCR_ETPS_0    0x00001000	/* Bit 0 */
  #define TIM_SMCR_ETPS_1    0x00002000	/* Bit 1 */
  #define TIM_SMCR_ECE       0x00004000	/* External clock enable     */
  #define TIM_SMCR_ETP       0x00008000	/* External trigger polarity */
#define TOFF_TIM_DIER       0x000C		/* (RW) TIM DMA/interrupt enable register */
  #define TIM_DIER_UIE       0x00000001	/* Update interrupt enable */
  #define TIM_DIER_CC1IE     0x00000002	/* Capture/Compare 1 interrupt enable */
  #define TIM_DIER_CC2IE     0x00000004	/* Capture/Compare 2 interrupt enable */
  #define TIM_DIER_CC3IE     0x00000008	/* Capture/Compare 3 interrupt enable */
  #define TIM_DIER_CC4IE     0x00000010	/* Capture/Compare 4 interrupt enable */
  #define TIM_DIER_COMIE     0x00000020	/* COM interrupt enable */
  #define TIM_DIER_TIE       0x00000040	/* Trigger interrupt enable */
  #define TIM_DIER_BIE       0x00000080	/* Break interrupt enable */
  #define TIM_DIER_UDE       0x00000100	/* Update DMA request enable */
  #define TIM_DIER_CC1DE     0x00000200	/* Capture/Compare 1 DMA request enable */
  #define TIM_DIER_CC2DE     0x00000400	/* Capture/Compare 2 DMA request enable */
  #define TIM_DIER_CC3DE     0x00000800	/* Capture/Compare 3 DMA request enable */
  #define TIM_DIER_CC4DE     0x00001000	/* Capture/Compare 4 DMA request enable */
  #define TIM_DIER_COMDE     0x00002000	/* COM DMA request enable */
  #define TIM_DIER_TDE       0x00004000	/* Trigger DMA request enable */
#define TOFF_TIM_SR         0x0010		/* (RW) TIM status register */
  #define TIM_SR_UIF         0x00000001	/* Update interrupt Flag */
  #define TIM_SR_CC1IF       0x00000002	/* Capture/Compare 1 interrupt Flag */
  #define TIM_SR_CC2IF       0x00000004	/* Capture/Compare 2 interrupt Flag */
  #define TIM_SR_CC3IF       0x00000008	/* Capture/Compare 3 interrupt Flag */
  #define TIM_SR_CC4IF       0x00000010	/* Capture/Compare 4 interrupt Flag */
  #define TIM_SR_COMIF       0x00000020	/* COM interrupt Flag */
  #define TIM_SR_TIF         0x00000040	/* Trigger interrupt Flag */
  #define TIM_SR_BIF         0x00000080	/* Break interrupt Flag */
  #define TIM_SR_B2IF        0x00000100	/* Break2 interrupt Flag */
  #define TIM_SR_CC1OF       0x00000200	/* Capture/Compare 1 Overcapture Flag */
  #define TIM_SR_CC2OF       0x00000400	/* Capture/Compare 2 Overcapture Flag */
  #define TIM_SR_CC3OF       0x00000800	/* Capture/Compare 3 Overcapture Flag */
  #define TIM_SR_CC4OF       0x00001000	/* Capture/Compare 4 Overcapture Flag */
  #define TIM_SR_SBIF        0x00002000	/* System Break Flag */
  #define TIM_SR_CC5IF       0x00010000	/* Capture/Compare 5 interrupt Flag */
  #define TIM_SR_CC6IF       0x00020000	/* Capture/Compare 6 interrupt Flag */
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
  #define TIM_CCMR1_OC2CE    0x00008000	/* Output Compare 2 Clear Enable */

  #define TIM_CCMR1_IC1PSC   0x0000000C	/* IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
  #define TIM_CCMR1_IC1PSC_0 0x00000004	/* Bit 0 */
  #define TIM_CCMR1_IC1PSC_1 0x00000008	/* Bit 1 */
  #define TIM_CCMR1_IC1F     0x000000F0	/* IC1F[3:0] bits (Input Capture 1 Filter)      */
  #define TIM_CCMR1_IC1F_0   0x00000010	/* Bit 0 */
  #define TIM_CCMR1_IC1F_1   0x00000020	/* Bit 1 */
  #define TIM_CCMR1_IC1F_2   0x00000040	/* Bit 2 */
  #define TIM_CCMR1_IC1F_3   0x00000080	/* Bit 3 */
  #define TIM_CCMR1_IC2PSC   0x00000C00	/* IC2PSC[1:0] bits (Input Capture 2 Prescaler)  */
  #define TIM_CCMR1_IC2PSC_0 0x00000400	/* Bit 0 */
  #define TIM_CCMR1_IC2PSC_1 0x00000800	/* Bit 1 */
  #define TIM_CCMR1_IC2F     0x0000F000	/* IC2F[3:0] bits (Input Capture 2 Filter)       */
  #define TIM_CCMR1_IC2F_0   0x00001000	/* Bit 0 */
  #define TIM_CCMR1_IC2F_1   0x00002000	/* Bit 1 */
  #define TIM_CCMR1_IC2F_2   0x00004000	/* Bit 2 */
  #define TIM_CCMR1_IC2F_3   0x00008000	/* Bit 3 */
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
  #define TIM_CCMR2_OC4CE    0x00008000	/* Output Compare 4 Clear Enable */

  #define TIM_CCMR2_IC3PSC   0x0000000C	/* IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
  #define TIM_CCMR2_IC3PSC_0 0x00000004	/* Bit 0 */
  #define TIM_CCMR2_IC3PSC_1 0x00000008	/* Bit 1 */
  #define TIM_CCMR2_IC3F     0x000000F0	/* IC3F[3:0] bits (Input Capture 3 Filter) */
  #define TIM_CCMR2_IC3F_0   0x00000010	/* Bit 0 */
  #define TIM_CCMR2_IC3F_1   0x00000020	/* Bit 1 */
  #define TIM_CCMR2_IC3F_2   0x00000040	/* Bit 2 */
  #define TIM_CCMR2_IC3F_3   0x00000080	/* Bit 3 */
  #define TIM_CCMR2_IC4PSC   0x00000C00	/* IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
  #define TIM_CCMR2_IC4PSC_0 0x00000400	/* Bit 0 */
  #define TIM_CCMR2_IC4PSC_1 0x00000800	/* Bit 1 */
  #define TIM_CCMR2_IC4F     0x0000F000	/* IC4F[3:0] bits (Input Capture 4 Filter) */
  #define TIM_CCMR2_IC4F_0   0x00001000	/* Bit 0 */
  #define TIM_CCMR2_IC4F_1   0x00002000	/* Bit 1 */
  #define TIM_CCMR2_IC4F_2   0x00004000	/* Bit 2 */
  #define TIM_CCMR2_IC4F_3   0x00008000	/* Bit 3 */
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
  #define TIM_DCR_DBA        0x0000001F		/* DBA[4:0] bits (DMA Base Address) */
  #define TIM_DCR_DBA_0      0x00000001	/* Bit 0 */
  #define TIM_DCR_DBA_1      0x00000002	/* Bit 1 */
  #define TIM_DCR_DBA_2      0x00000004	/* Bit 2 */
  #define TIM_DCR_DBA_3      0x00000008	/* Bit 3 */
  #define TIM_DCR_DBA_4      0x00000010	/* Bit 4 */
  #define TIM_DCR_DBL        0x00001F00	/* DBL[4:0] bits (DMA Burst Length) */
  #define TIM_DCR_DBL_0      0x00000100	/* Bit 0 */
  #define TIM_DCR_DBL_1      0x00000200	/* Bit 1 */
  #define TIM_DCR_DBL_2      0x00000400	/* Bit 2 */
  #define TIM_DCR_DBL_3      0x00000800	/* Bit 3 */
  #define TIM_DCR_DBL_4      0x00001000	/* Bit 4 */
#define TOFF_TIM_DMAR       0x004C		/* (RW) TIM DMA address for full transfer */
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
#define TOFF_TIM_AF1        0x0060		/* (RW) TIM alternate function option register 1 */
  #define TIM1_AF1_BKINE     0x00000001	/* BKINE Break input enable bit */
  #define TIM1_AF1_BKCMP1E   0x00000002	/* BKCMP1E Break Compare1 Enable bit */
  #define TIM1_AF1_BKCMP2E   0x00000004	/* BKCMP1E Break Compare2 Enable bit */
  #define TIM1_AF1_BKDF1BK0E 0x00000100	/* BKDF1BK0E Break input DFSDM Break 0 */
  #define TIM1_AF1_BKINP     0x00000200	/* BRKINP Break input polarity */
  #define TIM1_AF1_BKCMP1P   0x00000400	/* BKCMP1P Break COMP1 input polarity */
  #define TIM1_AF1_BKCMP2P   0x00000800	/* BKCMP2P Break COMP2 input polarity */
  #define TIM1_AF1_ETRSEL    0x0003C000	/* ETRSEL[3:0] bits (TIM1 ETRSEL) */
  #define TIM1_AF1_ETRSEL_0  0x00004000
  #define TIM1_AF1_ETRSEL_1  0x00008000
  #define TIM1_AF1_ETRSEL_2  0x00010000
  #define TIM1_AF1_ETRSEL_3  0x00020000
#define TOFF_TIM_AF2        0x0064		/* (RW) TIM alternate function option register 2 */
  #define TIM1_AF2_BK2INE    0x00000001	/* BK2INE Break input 2 enable bit */
  #define TIM1_AF2_BK2CMP1E  0x00000002	/* BK2CMP1E Break2 Compare1 Enable bit */
  #define TIM1_AF2_BK2CMP2E  0x00000004	/* BK2CMP1E Break2 Compare2 Enable bit  */
  #define TIM1_AF2_BK2DFBK1E 0x00000100	/* BK2DFBK1E Break input2 DFSDM Break 1 */
  #define TIM1_AF2_BK2INP    0x00000200	/* BRKINP Break2 input polarity */
  #define TIM1_AF2_BK2CMP1P  0x00000400	/* BKCMP1P Break2 COMP1 input polarity */
  #define TIM1_AF2_BK2CMP2P  0x00000800	/* BKCMP2P Break2 COMP2 input polarity */
#define TOFF_TIM_TISEL      0x0068		/* (RW) TIM Input Selection register */
  #define TIM_TISEL_TI1SEL   0x0000000F	/* TI1SEL[3:0] bits (TIM TI1 SEL)*/
  #define TIM_TISEL_TI1SEL_0 0x00000001
  #define TIM_TISEL_TI1SEL_1 0x00000002
  #define TIM_TISEL_TI1SEL_2 0x00000004
  #define TIM_TISEL_TI1SEL_3 0x00000008
  #define TIM_TISEL_TI2SEL   0x00000F00	/* TI2SEL[3:0] bits (TIM TI2 SEL)*/
  #define TIM_TISEL_TI2SEL_0 0x00000100
  #define TIM_TISEL_TI2SEL_1 0x00000200
  #define TIM_TISEL_TI2SEL_2 0x00000400
  #define TIM_TISEL_TI2SEL_3 0x00000800
  #define TIM_TISEL_TI3SEL   0x000F0000	/* TI3SEL[3:0] bits (TIM TI3 SEL)*/
  #define TIM_TISEL_TI3SEL_0 0x00010000
  #define TIM_TISEL_TI3SEL_1 0x00020000
  #define TIM_TISEL_TI3SEL_2 0x00040000
  #define TIM_TISEL_TI3SEL_3 0x00080000
  #define TIM_TISEL_TI4SEL   0x0F000000	/* TI4SEL[3:0] bits (TIM TI4 SEL)*/
  #define TIM_TISEL_TI4SEL_0 0x01000000
  #define TIM_TISEL_TI4SEL_1 0x02000000
  #define TIM_TISEL_TI4SEL_2 0x04000000
  #define TIM_TISEL_TI4SEL_3 0x08000000


/*
 *  LPTIMIMER
 */
#define TADR_LPTIM1_BASE    (D2_APB1PERIPH_BASE + 0x2400)
#define TADR_LPTIM2_BASE    (D3_APB1PERIPH_BASE + 0x2400)
#define TADR_LPTIM3_BASE    (D3_APB1PERIPH_BASE + 0x2800)
#define TADR_LPTIM4_BASE    (D3_APB1PERIPH_BASE + 0x2C00)
#define TADR_LPTIM5_BASE    (D3_APB1PERIPH_BASE + 0x3000)
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
  #define LPTIM_CR_COUNTRST  0x00000008	/* Timer Counter reset in synchronous mode*/
  #define LPTIM_CR_RSTARE    0x00000010	/* Timer Counter reset after read enable (asynchronously)*/
#define TOFF_LPTIM_CMP      0x0014		/* (RW) LPTIM Compare register */
#define TOFF_LPTIM_ARR      0x0018		/* (RW) LPTIM Autoreload register */
#define TOFF_LPTIM_CNT      0x001C		/* (RW) LPTIM Counter register */
#define TOFF_LPTIMCFGR2     0x0024		/* (RW) LPTIM Configuration register */
  #define LPTIM_CFGR2_IN1SEL 0x00000003	/* IN1SEL[1:0] bits (Remap selection) */
  #define LPTIM_CFGR2_IN1SEL_0   0x00000001
  #define LPTIM_CFGR2_IN1SEL_1   0x00000002
  #define LPTIM_CFGR2_IN2SEL 0x00000030	/* IN2SEL[5:4] bits (Remap selection) */
  #define LPTIM_CFGR2_IN2SEL_0   0x00000010
  #define LPTIM_CFGR2_IN2SEL_1   0x00000020


/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (D3_APB1PERIPH_BASE + 0x4000)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_SU          0x0000000F
  #define RTC_TR_SU_0        0x00000001
  #define RTC_TR_SU_1        0x00000002
  #define RTC_TR_SU_2        0x00000004
  #define RTC_TR_SU_3        0x00000008
  #define RTC_TR_ST          0x00000070
  #define RTC_TR_ST_0        0x00000010
  #define RTC_TR_ST_1        0x00000020
  #define RTC_TR_ST_2        0x00000040
  #define RTC_TR_MNU         0x00000F00
  #define RTC_TR_MNU_0       0x00000100
  #define RTC_TR_MNU_1       0x00000200
  #define RTC_TR_MNU_2       0x00000400
  #define RTC_TR_MNU_3       0x00000800
  #define RTC_TR_MNT         0x00007000
  #define RTC_TR_MNT_0       0x00001000
  #define RTC_TR_MNT_1       0x00002000
  #define RTC_TR_MNT_2       0x00004000
  #define RTC_TR_HU          0x000F0000
  #define RTC_TR_HU_0        0x00010000
  #define RTC_TR_HU_1        0x00020000
  #define RTC_TR_HU_2        0x00040000
  #define RTC_TR_HU_3        0x00080000
  #define RTC_TR_HT          0x00300000
  #define RTC_TR_HT_0        0x00100000
  #define RTC_TR_HT_1        0x00200000
  #define RTC_TR_PM          0x00400000
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_DU          0x0000000F
  #define RTC_DR_DU_0        0x00000001
  #define RTC_DR_DU_1        0x00000002
  #define RTC_DR_DU_2        0x00000004
  #define RTC_DR_DU_3        0x00000008
  #define RTC_DR_DT          0x00000030
  #define RTC_DR_DT_0        0x00000010
  #define RTC_DR_DT_1        0x00000020
  #define RTC_DR_MU          0x00000F00
  #define RTC_DR_MU_0        0x00000100
  #define RTC_DR_MU_1        0x00000200
  #define RTC_DR_MU_2        0x00000400
  #define RTC_DR_MU_3        0x00000800
  #define RTC_DR_MT          0x00001000
  #define RTC_DR_WDU         0x0000E000
  #define RTC_DR_WDU_0       0x00002000
  #define RTC_DR_WDU_1       0x00004000
  #define RTC_DR_WDU_2       0x00008000
  #define RTC_DR_YU          0x000F0000
  #define RTC_DR_YU_0        0x00010000
  #define RTC_DR_YU_1        0x00020000
  #define RTC_DR_YU_2        0x00040000
  #define RTC_DR_YU_3        0x00080000
  #define RTC_DR_YT          0x00F00000
  #define RTC_DR_YT_0        0x00100000
  #define RTC_DR_YT_1        0x00200000
  #define RTC_DR_YT_2        0x00400000
  #define RTC_DR_YT_3        0x00800000
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
  #define RTC_CR_BKP         0x00040000
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
  #define RTC_ALRMAR_SU_0    0x00000001
  #define RTC_ALRMAR_SU_1    0x00000002
  #define RTC_ALRMAR_SU_2    0x00000004
  #define RTC_ALRMAR_SU_3    0x00000008
  #define RTC_ALRMAR_ST      0x00000070
  #define RTC_ALRMAR_ST_0    0x00000010
  #define RTC_ALRMAR_ST_1    0x00000020
  #define RTC_ALRMAR_ST_2    0x00000040
  #define RTC_ALRMAR_MSK1    0x00000080
  #define RTC_ALRMAR_MNU     0x00000F00
  #define RTC_ALRMAR_MNU_0   0x00000100
  #define RTC_ALRMAR_MNU_1   0x00000200
  #define RTC_ALRMAR_MNU_2   0x00000400
  #define RTC_ALRMAR_MNU_3   0x00000800
  #define RTC_ALRMAR_MNT     0x00007000
  #define RTC_ALRMAR_MNT_0   0x00001000
  #define RTC_ALRMAR_MNT_1   0x00002000
  #define RTC_ALRMAR_MNT_2   0x00004000
  #define RTC_ALRMAR_MSK2    0x00008000
  #define RTC_ALRMAR_HU      0x000F0000
  #define RTC_ALRMAR_HU_0    0x00010000
  #define RTC_ALRMAR_HU_1    0x00020000
  #define RTC_ALRMAR_HU_2    0x00040000
  #define RTC_ALRMAR_HU_3    0x00080000
  #define RTC_ALRMAR_HT      0x00300000
  #define RTC_ALRMAR_HT_0    0x00100000
  #define RTC_ALRMAR_HT_1    0x00200000
  #define RTC_ALRMAR_PM      0x00400000
  #define RTC_ALRMAR_MSK3    0x00800000
  #define RTC_ALRMAR_DU      0x0F000000
  #define RTC_ALRMAR_DU_0    0x01000000
  #define RTC_ALRMAR_DU_1    0x02000000
  #define RTC_ALRMAR_DU_2    0x04000000
  #define RTC_ALRMAR_DU_3    0x08000000
  #define RTC_ALRMAR_DT      0x30000000
  #define RTC_ALRMAR_DT_0    0x10000000
  #define RTC_ALRMAR_DT_1    0x20000000
  #define RTC_ALRMAR_WDSEL   0x40000000
  #define RTC_ALRMAR_MSK4    0x80000000
#define TOFF_RTC_ALRMBR     0x0020		/* (RW) RTC alarm B register */
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
#define TOFF_RTC_SSR        0x0028		/* (RW) RTC sub second register */
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
  #define RTC_SHIFTR_SUBFS   0x00007FFF
  #define RTC_SHIFTR_ADD1S   0x80000000
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
  #define RTC_TSTR_SU        0x00000001
  #define RTC_TSTR_SU_1      0x00000002
  #define RTC_TSTR_SU_2      0x00000004
  #define RTC_TSTR_SU_3      0x00000008
  #define RTC_TSTR_ST        0x00000070
  #define RTC_TSTR_ST_0      0x00000010
  #define RTC_TSTR_ST_1      0x00000020
  #define RTC_TSTR_ST_2      0x00000040
  #define RTC_TSTR_MNU       0x00000F00
  #define RTC_TSTR_MNU_0     0x00000100
  #define RTC_TSTR_MNU_1     0x00000200
  #define RTC_TSTR_MNU_2     0x00000400
  #define RTC_TSTR_MNU_3     0x00000800
  #define RTC_TSTR_MNT       0x00007000
  #define RTC_TSTR_MNT_0     0x00001000
  #define RTC_TSTR_MNT_1     0x00002000
  #define RTC_TSTR_MNT_2     0x00004000
  #define RTC_TSTR_HU        0x000F0000
  #define RTC_TSTR_HU_0      0x00010000
  #define RTC_TSTR_HU_1      0x00020000
  #define RTC_TSTR_HU_2      0x00040000
  #define RTC_TSTR_HU_3      0x00080000
  #define RTC_TSTR_HT        0x00300000
  #define RTC_TSTR_HT_0      0x00100000
  #define RTC_TSTR_HT_1      0x00200000
  #define RTC_TSTR_PM        0x00400000
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
  #define RTC_TSDR_DU        0x0000000F
  #define RTC_TSDR_DU_0      0x00000001
  #define RTC_TSDR_DU_1      0x00000002
  #define RTC_TSDR_DU_2      0x00000004
  #define RTC_TSDR_DU_3      0x00000008
  #define RTC_TSDR_DT        0x00000030
  #define RTC_TSDR_DT_0      0x00000010
  #define RTC_TSDR_DT_1      0x00000020
  #define RTC_TSDR_MU        0x00000F00
  #define RTC_TSDR_MU_0      0x00000100
  #define RTC_TSDR_MU_1      0x00000200
  #define RTC_TSDR_MU_2      0x00000400
  #define RTC_TSDR_MU_3      0x00000800
  #define RTC_TSDR_MT        0x00001000
  #define RTC_TSDR_WDU       0x0000E000
  #define RTC_TSDR_WDU_0     0x00002000
  #define RTC_TSDR_WDU_1     0x00004000
  #define RTC_TSDR_WDU_2     0x00008000
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_CALR       0x003C		/* (RW) RTC calibration register */
  #define RTC_CALR_CALM      0x000001FF
  #define RTC_CALR_CALW16    0x00002000
  #define RTC_CALR_CALW8     0x00004000
  #define RTC_CALR_CALP      0x00008000
#define TOFF_RTC_TAMPCR     0x0040		/* (RW) RTC tamper and alternate function configuration register */
  #define RTC_TAMPCR_TAMP1E  0x00000001
  #define RTC_TAMPCR_TAMP1TRG   0x00000002
  #define RTC_TAMPCR_TAMPIE     0x00000004
  #define RTC_TAMPCR_TAMP2E     0x00000008
  #define RTC_TAMPCR_TAMP2TRG   0x00000010
  #define RTC_TAMPCR_TAMP3E     0x00000020
  #define RTC_TAMPCR_TAMP3TRG   0x00000040
  #define RTC_TAMPCR_TAMPTS     0x00000080
  #define RTC_TAMPCR_TAMPFREQ   0x00000700
  #define RTC_TAMPCR_TAMPFREQ_0 0x00000100
  #define RTC_TAMPCR_TAMPFREQ_1 0x00000200
  #define RTC_TAMPCR_TAMPFREQ_2 0x00000400
  #define RTC_TAMPCR_TAMPFLT    0x00001800
  #define RTC_TAMPCR_TAMPFLT_0  0x00000800
  #define RTC_TAMPCR_TAMPFLT_1  0x00001000
  #define RTC_TAMPCR_TAMPPRCH   0x00006000
  #define RTC_TAMPCR_TAMPPRCH_0 0x00002000
  #define RTC_TAMPCR_TAMPPRCH_1 0x00004000
  #define RTC_TAMPCR_TAMPPUDIS  0x00008000
  #define RTC_TAMPCR_TAMP1IE    0x00010000
  #define RTC_TAMPCR_TAMP1NOERASE 0x00020000
  #define RTC_TAMPCR_TAMP1MF    0x00040000
  #define RTC_TAMPCR_TAMP2IE    0x00080000
  #define RTC_TAMPCR_TAMP2NOERASE 0x00100000
  #define RTC_TAMPCR_TAMP2MF    0x00200000
  #define RTC_TAMPCR_TAMP3IE    0x00400000
  #define RTC_TAMPCR_TAMP3NOERASE 0x00800000
  #define RTC_TAMPCR_TAMP3MF    0x01000000
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_SS    0x00007FFF
#define TOFF_RTC_ALRMBSSR   0x0048		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_SS    0x00007FFF
#define TOFF_RTC_OR         0x004C		/* (RW) RTC option register */
  #define RTC_OR_ALARMOUTTYPE   0x00000001
  #define RTC_OR_OUT_RMP        0x00000002
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
 *  BDMA
 */
#define TADR_BDMA_BASE      (D3_AHB1PERIPH_BASE + 0x5400)
#define TOFF_BDMA_ISR       0x0000		/* (RW) DMA interrupt status register */
  #define BDMA_ISR_GIF0      0x00000001	/* Channel 0 Global interrupt flag */
  #define BDMA_ISR_TCIF0     0x00000002	/* Channel 0 Transfer Complete flag */
  #define BDMA_ISR_HTIF0     0x00000004	/* Channel 0 Half Transfer flag */
  #define BDMA_ISR_TEIF0     0x00000008	/* Channel 0 Transfer Error flag */
  #define BDMA_ISR_GIF1      0x00000010	/* Channel 1 Global interrupt flag */
  #define BDMA_ISR_TCIF1     0x00000020	/* Channel 1 Transfer Complete flag */
  #define BDMA_ISR_HTIF1     0x00000040	/* Channel 1 Half Transfer flag */
  #define BDMA_ISR_TEIF1     0x00000080	/* Channel 1 Transfer Error flag */
  #define BDMA_ISR_GIF2      0x00000100	/* Channel 2 Global interrupt flag */
  #define BDMA_ISR_TCIF2     0x00000200	/* Channel 2 Transfer Complete flag */
  #define BDMA_ISR_HTIF2     0x00000400	/* Channel 2 Half Transfer flag */
  #define BDMA_ISR_TEIF2     0x00000800	/* Channel 2 Transfer Error flag */
  #define BDMA_ISR_GIF3      0x00001000	/* Channel 3 Global interrupt flag */
  #define BDMA_ISR_TCIF3     0x00002000	/* Channel 3 Transfer Complete flag */
  #define BDMA_ISR_HTIF3     0x00004000	/* Channel 3 Half Transfer flag */
  #define BDMA_ISR_TEIF3     0x00008000	/* Channel 3 Transfer Error flag */
  #define BDMA_ISR_GIF4      0x00010000	/* Channel 4 Global interrupt flag */
  #define BDMA_ISR_TCIF4     0x00020000	/* Channel 4 Transfer Complete flag */
  #define BDMA_ISR_HTIF4     0x00040000	/* Channel 4 Half Transfer flag */
  #define BDMA_ISR_TEIF4     0x00080000	/* Channel 4 Transfer Error flag */
  #define BDMA_ISR_GIF5      0x00100000	/* Channel 5 Global interrupt flag */
  #define BDMA_ISR_TCIF5     0x00200000	/* Channel 5 Transfer Complete flag */
  #define BDMA_ISR_HTIF5     0x00400000	/* Channel 5 Half Transfer flag */
  #define BDMA_ISR_TEIF5     0x00800000	/* Channel 5 Transfer Error flag */
  #define BDMA_ISR_GIF6      0x01000000	/* Channel 6 Global interrupt flag */
  #define BDMA_ISR_TCIF6     0x02000000	/* Channel 6 Transfer Complete flag */
  #define BDMA_ISR_HTIF6     0x04000000	/* Channel 6 Half Transfer flag */
  #define BDMA_ISR_TEIF6     0x08000000	/* Channel 6 Transfer Error flag */
  #define BDMA_ISR_GIF7      0x10000000	/* Channel 7 Global interrupt flag */
  #define BDMA_ISR_TCIF7     0x20000000	/* Channel 7 Transfer Complete flag */
  #define BDMA_ISR_HTIF7     0x40000000/* Channel 7 Half Transfer flag */
  #define BDMA_ISR_TEIF7     0x80000000	/* Channel 7 Transfer Error flag */
#define TOFF_BDMA_IFCR      0x0004		/* (RW) DMA interrupt flag clear register */
  #define BDMA_IFCR_CGIF0    0x00000001	/* Channel 0 Global interrupt clear */
  #define BDMA_IFCR_CTCIF0   0x00000002	/* Channel 0 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF0   0x00000004	/* Channel 0 Half Transfer clear */
  #define BDMA_IFCR_CTEIF0   0x00000008	/* Channel 0 Transfer Error clear */
  #define BDMA_IFCR_CGIF1    0x00000010	/* Channel 1 Global interrupt clear */
  #define BDMA_IFCR_CTCIF1   0x00000020	/* Channel 1 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF1   0x00000040	/* Channel 1 Half Transfer clear */
  #define BDMA_IFCR_CTEIF1   0x00000080	/* Channel 1 Transfer Error clear */
  #define BDMA_IFCR_CGIF2    0x00000100	/* Channel 2 Global interrupt clear */
  #define BDMA_IFCR_CTCIF2   0x00000200	/* Channel 2 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF2   0x00000400	/* Channel 2 Half Transfer clear */
  #define BDMA_IFCR_CTEIF2   0x00000800	/* Channel 2 Transfer Error clear */
  #define BDMA_IFCR_CGIF3    0x00001000	/* Channel 3 Global interrupt clear */
  #define BDMA_IFCR_CTCIF3   0x00002000	/* Channel 3 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF3   0x00004000	/* Channel 3 Half Transfer clear */
  #define BDMA_IFCR_CTEIF3   0x00008000	/* Channel 3 Transfer Error clear */
  #define BDMA_IFCR_CGIF4    0x00010000	/* Channel 4 Global interrupt clear */
  #define BDMA_IFCR_CTCIF4   0x00020000	/* Channel 4 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF4   0x00040000	/* Channel 4 Half Transfer clear */
  #define BDMA_IFCR_CTEIF4   0x00080000	/* Channel 4 Transfer Error clear */
  #define BDMA_IFCR_CGIF5    0x00100000	/* Channel 5 Global interrupt clear */
  #define BDMA_IFCR_CTCIF5   0x00200000	/* Channel 5 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF5   0x00400000	/* Channel 5 Half Transfer clear */
  #define BDMA_IFCR_CTEIF5   0x00800000	/* Channel 5 Transfer Error clear */
  #define BDMA_IFCR_CGIF6    0x01000000	/* Channel 6 Global interrupt clear */
  #define BDMA_IFCR_CTCIF6   0x02000000	/* Channel 6 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF6   0x04000000	/* Channel 6 Half Transfer clear */
  #define BDMA_IFCR_CTEIF6   0x08000000	/* Channel 6 Transfer Error clear */
  #define BDMA_IFCR_CGIF7    0x10000000	/* Channel 7 Global interrupt clear */
  #define BDMA_IFCR_CTCIF7   0x20000000	/* Channel 7 Transfer Complete clear */
  #define BDMA_IFCR_CHTIF7   0x40000000	/* Channel 7 Half Transfer clear */
  #define BDMA_IFCR_CTEIF7   0x80000000	/* Channel 7 Transfer Error clear */


#define TADR_BDMA_CH0_BASE  (TADR_BDMA_BASE + 0x0008)
#define TADR_BDMA_CH1_BASE  (TADR_BDMA_BASE + 0x001C)
#define TADR_BDMA_CH2_BASE  (TADR_BDMA_BASE + 0x0030)
#define TADR_BDMA_CH3_BASE  (TADR_BDMA_BASE + 0x0044)
#define TADR_BDMA_CH4_BASE  (TADR_BDMA_BASE + 0x0058)
#define TADR_BDMA_CH5_BASE  (TADR_BDMA_BASE + 0x006C)
#define TADR_BDMA_CH6_BASE  (TADR_BDMA_BASE + 0x0080)
#define TADR_BDMA_CH7_BASE  (TADR_BDMA_BASE + 0x0094)
#define TOFF_BDMA_CCR       0x0000		/* (RW) DMA channel x configuration register */
  #define BDMA_CCR_EN        0x00000001	/* Channel enable */
  #define BDMA_CCR_TCIE      0x00000002	/* Transfer complete interrupt enable  */
  #define BDMA_CCR_HTIE      0x00000004	/* Half Transfer interrupt enable */
  #define BDMA_CCR_TEIE      0x00000008	/* Transfer error interrupt enable */
  #define BDMA_CCR_DIR       0x00000010	/* Data transfer direction */
  #define BDMA_CCR_CIRC      0x00000020	/* Circular mode */
  #define BDMA_CCR_PINC      0x00000040	/* Peripheral increment mode */
  #define BDMA_CCR_MINC      0x00000080	/* Memory increment mode */
  #define BDMA_CCR_PSIZE     0x00000300	/* PSIZE[1:0] bits (Peripheral size) */
  #define BDMA_CCR_PSIZE_0   0x00000100
  #define BDMA_CCR_PSIZE_1   0x00000200
  #define BDMA_CCR_MSIZE     0x00000C00	/* MSIZE[1:0] bits (Memory size) */
  #define BDMA_CCR_MSIZE_0   0x00000400
  #define BDMA_CCR_MSIZE_1   0x00000800
  #define BDMA_CCR_PL        0x00003000	/* PL[1:0] bits(Channel Priority level)*/
  #define BDMA_CCR_PL_0      0x00001000
  #define BDMA_CCR_PL_1      0x00002000
  #define BDMA_CCR_MEM2MEM   0x00004000	/* Memory to memory mode */
  #define BDMA_CCR_DBM       0x00008000	/* Memory to memory mode */
  #define BDMA_CCR_CT        0x00010000	/* Memory to memory mode */
#define TOFF_BDMA_CNDTR     0x0004		/* (RW) DMA channel x number of data register */
#define TOFF_BDMA_CPAR      0x0008		/* (RW) DMA channel x peripheral address register */
#define TOFF_BDMA_CM0AR     0x000C		/* (RW) DMA channel x memory 0 address register */
#define TOFF_BDMA_CM1AR     0x0010		/* (RW) DMA channel x memory 1 address register */


/*
 *  WINDOW WATCHDOG
 */
#define TADR_WWDG_BASE      (D1_APB1PERIPH_BASE + 0x3000)
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
  #define WWDG_CFR_EWI        0x00000200	/* Early Wakeup Interrupt */
  #define WWDG_CFR_WDGTB      0x00003800	/* WDGTB[2:0] bits (Timer Base) */
  #define WWDG_CFR_WDGTB_0    0x00000800
  #define WWDG_CFR_WDGTB_1    0x00001000
  #define WWDG_CFR_WDGTB_2    0x00002000
  #define WWDG_CFR_WDGTB0     WWDG_CFR_WDGTB_0
  #define WWDG_CFR_WDGTB1     WWDG_CFR_WDGTB_1
  #define WWDG_CFR_WDGTB2     WWDG_CFR_WDGTB_2
#define TOFF_WWDG_SR        0x0008		/* (R)  WWDG Status register */
  #define WWDG_SR_EWIF        0x00000001	/* Early Wakeup Interrupt Flag */

/*
 *  INDEPENDENT WATCHDOG
 */
#define TADR_IWDG_BASE      (D3_APB1PERIPH_BASE + 0x4800)
#define TOFF_IWDG_KR        0x0000		/* (RW) IWDG Key register */
#define TOFF_IWDG_PR        0x0004		/* (RW) IWDG Prescaler register */
  #define IWDG_PR_PR         0x00000007
  #define IWDG_PR_PR_0       0x00000001
  #define IWDG_PR_PR_1       0x00000002
  #define IWDG_PR_PR_2       0x00000004
#define TOFF_IWDG_RLR       0x0008		/* (RW) IWDG Reload register */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */
  #define IWDG_SR_PVU        0x00000001	/* Watchdog prescaler value update */
  #define IWDG_SR_RVU        0x00000002	/* Watchdog counter reload value update */
  #define IWDG_SR_WVU        0x00000004	/* Watchdog counter window value update */
#define TOFF_IWDG_WINR      0x0010		/* (RW) IWDG Window register */


/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_SPI2_BASE      (D2_APB1PERIPH_BASE + 0x3800)
#define TADR_SPI3_BASE      (D2_APB1PERIPH_BASE + 0x3C00)
#define TADR_SPI1_BASE      (D2_APB2PERIPH_BASE + 0x3000)
#define TADR_SPI4_BASE      (D2_APB2PERIPH_BASE + 0x3400)
#define TADR_SPI5_BASE      (D2_APB2PERIPH_BASE + 0x5000)
#define TADR_SPI6_BASE      (D3_APB1PERIPH_BASE + 0x1400)
#define TOFF_SPI_CR1        0x0000		/* (RW) SPI/I2S Control register 1 */
  #define SPI_CR1_SPE        0x00000001	/* Serial Peripheral Enable */
  #define SPI_CR1_MASRX      0x00000100	/* Master automatic SUSP in Receive mode */
  #define SPI_CR1_CSTART     0x00000200	/* Master transfer start */
  #define SPI_CR1_CSUSP      0x00000400	/* Master SUSPend request */
  #define SPI_CR1_HDDIR      0x00000800	/* Rx/Tx direction at Half-duplex mode */
  #define SPI_CR1_SSI        0x00001000	/* Internal SS signal input level */
  #define SPI_CR1_CRC33_17   0x00002000	/* 32-bit CRC polynomial configuration */
  #define SPI_CR1_RCRCINI    0x00004000	/* CRC init pattern control for receiver */
  #define SPI_CR1_TCRCINI    0x00008000	/* CRC init pattern control for transmitter */
  #define SPI_CR1_IOLOCK     0x00010000	/* Locking the AF configuration of associated IOs   */
#define TOFF_SPI_CR2        0x0004		/* (RW) SPI Control register 2 */
  #define SPI_CR2_TSIZE      0x0000FFFF	/* Number of data at current transfer */
  #define SPI_CR2_TSER       0xFFFF0000	/* Number of data transfer extension */
#define TOFF_SPI_CFG1       0x0008	/* (RW) SPI Configuration register 1 */
  #define SPI_CFG1_DSIZE     0x0000001F	/* DSIZE[4:0]: Bits number in single SPI data frame */
  #define SPI_CFG1_DSIZE_0   0x00000001
  #define SPI_CFG1_DSIZE_1   0x00000002
  #define SPI_CFG1_DSIZE_2   0x00000004
  #define SPI_CFG1_DSIZE_3   0x00000008
  #define SPI_CFG1_DSIZE_4   0x00000010
  #define SPI_CFG1_FTHLV     0x000001E0	/* FTHVL [3:0]: FIFO threshold level*/
  #define SPI_CFG1_FTHLV_0   0x00000020
  #define SPI_CFG1_FTHLV_1   0x00000040
  #define SPI_CFG1_FTHLV_2   0x00000080
  #define SPI_CFG1_FTHLV_3   0x00000100
  #define SPI_CFG1_UDRCFG    0x00000600	/* UDRCFG[1:0]: Behavior of transmitter at underrun */
  #define SPI_CFG1_UDRCFG_0  0x00000200
  #define SPI_CFG1_UDRCFG_1  0x00000400
  #define SPI_CFG1_UDRDET    0x00001800	/* UDRDET[1:0]: Detection of underrun condition     */
  #define SPI_CFG1_UDRDET_0  0x00000800
  #define SPI_CFG1_UDRDET_1  0x00001000
  #define SPI_CFG1_RXDMAEN   0x00004000	/* Rx DMA stream enable */
  #define SPI_CFG1_TXDMAEN   0x00008000	/* Tx DMA stream enable */
  #define SPI_CFG1_CRCSIZE   0x001F0000	/* CRCSIZE [4:0]: Length of CRC frame */
  #define SPI_CFG1_CRCSIZE_0 0x00010000
  #define SPI_CFG1_CRCSIZE_1 0x00020000
  #define SPI_CFG1_CRCSIZE_2 0x00040000
  #define SPI_CFG1_CRCSIZE_3 0x00080000
  #define SPI_CFG1_CRCSIZE_4 0x00100000
  #define SPI_CFG1_CRCEN     0x00400000	/* Hardware CRC computation enable */
  #define SPI_CFG1_MBR       0x70000000	/* Master baud rate */
  #define SPI_CFG1_MBR_0     0x10000000
  #define SPI_CFG1_MBR_1     0x20000000
  #define SPI_CFG1_MBR_2     0x40000000
#define TOFF_SPI_CFG2       0x000C	/* (RW) SPI Configuration register 2 */
  #define SPI_CFG2_MSSI      0x0000000F	/* Master SS Idleness */
  #define SPI_CFG2_MSSI_0    0x00000001
  #define SPI_CFG2_MSSI_1    0x00000002
  #define SPI_CFG2_MSSI_2    0x00000004
  #define SPI_CFG2_MSSI_3    0x00000008
  #define SPI_CFG2_MIDI      0x000000F0	/* Master Inter-Data Idleness */
  #define SPI_CFG2_MIDI_0    0x00000010
  #define SPI_CFG2_MIDI_1    0x00000020
  #define SPI_CFG2_MIDI_2    0x00000040
  #define SPI_CFG2_MIDI_3    0x00000080
  #define SPI_CFG2_IOSWP     0x00008000	/* Swap functionality of MISO and MOSI pins */
  #define SPI_CFG2_COMM      0x00060000	/* COMM [1:0]: SPI Communication Mode */
  #define SPI_CFG2_COMM_0    0x00020000
  #define SPI_CFG2_COMM_1    0x00040000
  #define SPI_CFG2_SP        0x00380000	/* SP[2:0]: Serial Protocol */
  #define SPI_CFG2_SP_0      0x00080000
  #define SPI_CFG2_SP_1      0x00100000
  #define SPI_CFG2_SP_2      0x00200000
  #define SPI_CFG2_MASTER    0x00400000	/* SPI Master */
  #define SPI_CFG2_LSBFRST   0x00800000	/* Data frame format */
  #define SPI_CFG2_CPHA      0x01000000	/* Clock Phase */
  #define SPI_CFG2_CPOL      0x02000000	/* Clock Polarity */
  #define SPI_CFG2_SSM       0x04000000	/* Software slave management */
  #define SPI_CFG2_SSIOP     0x10000000	/* SS input/output polarity */
  #define SPI_CFG2_SSOE      0x20000000	/* SS output enable */
  #define SPI_CFG2_SSOM      0x40000000	/* SS output management in master mode */
  #define SPI_CFG2_AFCNTR    0x80000000	/* Alternate function GPIOs control */
#define TOFF_SPI_IER        0x0010	/* (RW) SPI/I2S Interrupt Enable register */
  #define SPI_IER_RXPIE      0x00000001	/* RXP Interrupt Enable */
  #define SPI_IER_TXPIE      0x00000002	/* TXP interrupt enable */
  #define SPI_IER_DXPIE      0x00000004	/* DXP interrupt enable */
  #define SPI_IER_EOTIE      0x00000008	/* EOT/SUSP/TXC interrupt enable */
  #define SPI_IER_TXTFIE     0x00000010	/* TXTF interrupt enable */
  #define SPI_IER_UDRIE      0x00000020	/* UDR interrupt enable */
  #define SPI_IER_OVRIE      0x00000040	/* OVR interrupt enable */
  #define SPI_IER_CRCEIE     0x00000080	/* CRCE interrupt enable */
  #define SPI_IER_TIFREIE    0x00000100	/* TI Frame Error interrupt enable */
  #define SPI_IER_MODFIE     0x00000200	/* MODF interrupt enable */
  #define SPI_IER_TSERFIE    0x00000400	/* TSERF interrupt enable */
#define TOFF_SPI_SR         0x0014	/* (RW) SPI/I2S Status register */
  #define SPI_SR_RXP         0x00000001	/* Rx-Packet available */
  #define SPI_SR_TXP         0x00000002	/* Tx-Packet space available */
  #define SPI_SR_DXP         0x00000004	/* Duplex Packet available */
  #define SPI_SR_EOT         0x00000008	/* Duplex Packet available */
  #define SPI_SR_TXTF        0x00000010	/* Transmission Transfer Filled */
  #define SPI_SR_UDR         0x00000020	/* UDR at Slave transmission */
  #define SPI_SR_OVR         0x00000040	/* Rx-Packet available */
  #define SPI_SR_CRCE        0x00000080	/* CRC Error Detected */
  #define SPI_SR_TIFRE       0x00000100	/* TI frame format error Detected  */
  #define SPI_SR_MODF        0x00000200	/* Mode Fault Detected */
  #define SPI_SR_TSERF       0x00000400	/* Number of SPI data to be transacted reloaded */
  #define SPI_SR_SUSP        0x00000800	/* SUSP is set by hardware  */
  #define SPI_SR_TXC         0x00001000	/* TxFIFO transmission complete */
  #define SPI_SR_RXPLVL      0x00006000	/* RxFIFO Packing Level */
  #define SPI_SR_RXPLVL_0    0x00002000
  #define SPI_SR_RXPLVL_1    0x00004000
  #define SPI_SR_RXWNE       0x00008000	/* Rx FIFO Word Not Empty */
  #define SPI_SR_CTSIZE      0xFFFF0000	/* Number of data frames remaining in TSIZE */
#define TOFF_SPI_IFCR       0x0018	/* (RW) SPI/I2S Interrupt/Status flags clear register */
  #define SPI_IFCR_EOTC      0x00000008	/* End Of Transfer flag clear */
  #define SPI_IFCR_TXTFC     0x00000010	/* Transmission Transfer Filled flag clear */
  #define SPI_IFCR_UDRC      0x00000020	/* Underrun flag clear */
  #define SPI_IFCR_OVRC      0x00000040	/* Overrun flag clear */
  #define SPI_IFCR_CRCEC     0x00000080	/* CRC Error flag clear */
  #define SPI_IFCR_TIFREC    0x00000100	/* TI frame format error flag clear */
  #define SPI_IFCR_MODFC     0x00000200	/* Mode Fault flag clear */
  #define SPI_IFCR_TSERFC    0x00000400	/* TSERFC flag clear */
  #define SPI_IFCR_SUSPC     0x00000800	/* SUSPend flag clear */
#define TOFF_SPI_TXDR       0x0020	/* (RW) SPI/I2S Transmit data register */
#define TOFF_SPI_RXDR       0x0030	/* (RW) SPI/I2S Receive data register */
#define TOFF_SPI_CRCPOLY    0x0040	/* (RW) SPI CRC Polynomial register */
#define TOFF_SPI_TXCRC      0x0044	/* (RW) SPI Transmitter CRC register */
#define TOFF_SPI_RXCRC      0x0048	/* (RW) SPI Receiver CRC register */
#define TOFF_SPI_UDRDR      0x004C	/* (RW) SPI Underrun data register */
#define TOFF_SPI_I2SCFGR    0x0050	/* (RW) I2S Configuration register */
  #define SPI_I2SCFGR_I2SMOD    0x00000001	/* I2S mode selection */
  #define SPI_I2SCFGR_I2SCFG    0x0000000E /* I2SCFG[2:0] I2S configuration mode */
  #define SPI_I2SCFGR_I2SCFG_0  0x00000002
  #define SPI_I2SCFGR_I2SCFG_1  0x00000004
  #define SPI_I2SCFGR_I2SCFG_2  0x00000008
  #define SPI_I2SCFGR_I2SSTD    0x00000030	/* I2SSTD[1:0] I2S standard selection */
  #define SPI_I2SCFGR_I2SSTD_0  0x00000010
  #define SPI_I2SCFGR_I2SSTD_1  0x00000020
  #define SPI_I2SCFGR_PCMSYNC   0x00000080	/* PCM frame synchronization */
  #define SPI_I2SCFGR_DATLEN    0x00000300	/* DATLEN[1:0] Data length to be transferred */
  #define SPI_I2SCFGR_DATLEN_0  0x00000100
  #define SPI_I2SCFGR_DATLEN_1  0x00000200
  #define SPI_I2SCFGR_CHLEN     0x00000400	/* Channel length (number of bits per audio channel) */
  #define SPI_I2SCFGR_CKPOL     0x00000800	/* Steady state clock polarity */
  #define SPI_I2SCFGR_FIXCH     0x00001000	/* Fixed channel length in SLAVE */
  #define SPI_I2SCFGR_WSINV     0x00002000	/* Word select inversion */
  #define SPI_I2SCFGR_DATFMT    0x00004000	/* Data format */
  #define SPI_I2SCFGR_I2SDIV    0x00FF0000	/* I2S Linear prescaler */
  #define SPI_I2SCFGR_ODD       0x01000000	/* Odd factor for the prescaler */
  #define SPI_I2SCFGR_MCKOE     0x02000000	/* Master Clock Output Enable */


/*
 *  SPDIF-RX INTERFACE
 */
#define TADR_SPDIFRX_BASE   (D2_APB1PERIPH_BASE + 0x4000)
#define TOFF_SPDIFRX_CR     0x0000		/* (RW) Control register */
  #define SPDIFRX_CR_SPDIFEN    0x00000003	/* Peripheral Block Enable */
  #define SPDIFRX_CR_RXDMAEN    0x00000004	/* Receiver DMA Enable for data flow */
  #define SPDIFRX_CR_RXSTEO     0x00000008	/* Stereo Mode */
  #define SPDIFRX_CR_DRFMT      0x00000030	/* RX Data format */
  #define SPDIFRX_CR_PMSK       0x00000040	/* Mask Parity error bit */
  #define SPDIFRX_CR_VMSK       0x00000080	/* Mask of Validity bit */
  #define SPDIFRX_CR_CUMSK      0x00000100	/* Mask of channel status and user bits */
  #define SPDIFRX_CR_PTMSK      0x00000200	/* Mask of Preamble Type bits */
  #define SPDIFRX_CR_CBDMAEN    0x00000400	/* Control Buffer DMA ENable for control flow */
  #define SPDIFRX_CR_CHSEL      0x00000800	/* Channel Selection */
  #define SPDIFRX_CR_NBTR       0x00003000	/* Maximum allowed re-tries during synchronization phase */
  #define SPDIFRX_CR_WFA        0x00004000	/* Wait For Activity */
  #define SPDIFRX_CR_INSEL      0x00070000	/* SPDIF input selection */
  #define SPDIFRX_CR_CKSEN      0x00100000	/* Symbol Clock Enable */
  #define SPDIFRX_CR_CKSBKPEN   0x00200000	/* Backup Symbol Clock Enable */
#define TOFF_SPDIFRX_IMR    0x0004		/* (RW) Interrupt mask register */
  #define SPDIFRX_IMR_RXNEIE    0x00000001	/* RXNE interrupt enable */
  #define SPDIFRX_IMR_CSRNEIE   0x00000002	/* Control Buffer Ready Interrupt Enable */
  #define SPDIFRX_IMR_PERRIE    0x00000004	/* Parity error interrupt enable */
  #define SPDIFRX_IMR_OVRIE     0x00000008	/* Overrun error Interrupt Enable */
  #define SPDIFRX_IMR_SBLKIE    0x00000010	/* Synchronization Block Detected Interrupt Enable */
  #define SPDIFRX_IMR_SYNCDIE   0x00000020	/* Synchronization Done */
  #define SPDIFRX_IMR_IFEIE     0x00000040	/* Serial Interface Error Interrupt Enable */
#define TOFF_SPDIFRX_SR     0x0008		/* (RW) Status register */
  #define SPDIFRX_SR_RXNE       0x00000001	/* Read data register not empty */
  #define SPDIFRX_SR_CSRNE      0x00000002	/* The Control Buffer register is not empty */
  #define SPDIFRX_SR_PERR       0x00000004	/* Parity error */
  #define SPDIFRX_SR_OVR        0x00000008	/* Overrun error */
  #define SPDIFRX_SR_SBD        0x00000010	/* Synchronization Block Detected */
  #define SPDIFRX_SR_SYNCD      0x00000020	/* Synchronization Done */
  #define SPDIFRX_SR_FERR       0x00000040	/* Framing error */
  #define SPDIFRX_SR_SERR       0x00000080	/* Synchronization error */
  #define SPDIFRX_SR_TERR       0x00000100	/* Time-out error */
  #define SPDIFRX_SR_WIDTH5     0x7FFF0000	/* Duration of 5 symbols counted with spdif_clk */
#define TOFF_SPDIFRX_IFCR   0x000C		/* (RW) Interrupt Flag Clear register */
  #define SPDIFRX_IFCR_PERRCF   0x00000004	/* Clears the Parity error flag */
  #define SPDIFRX_IFCR_OVRCF    0x00000008	/* Clears the Overrun error flag */
  #define SPDIFRX_IFCR_SBDCF    0x00000010	/* Clears the Synchronization Block Detected flag */
  #define SPDIFRX_IFCR_SYNCDCF  0x00000020	/* Clears the Synchronization Done flag */
#define TOFF_SPDIFRX_DR     0x0010		/* (RW) Data input register */
	/* (DRFMT = 0b00 case) */
  #define SPDIFRX_DR0_DR        0x00FFFFFF	/* Data value */
  #define SPDIFRX_DR0_PE        0x01000000	/* Parity Error bit */
  #define SPDIFRX_DR0_V         0x02000000	/* Validity bit */
  #define SPDIFRX_DR0_U         0x04000000	/* User bit */
  #define SPDIFRX_DR0_C         0x08000000	/* Channel Status bit */
  #define SPDIFRX_DR0_PT        0x30000000	/* Preamble Type */
	/* (DRFMT = 0b01 case) */
  #define SPDIFRX_DR1_PE        0x00000001	/* Parity Error bit */
  #define SPDIFRX_DR1_V         0x00000002	/* Validity bit */
  #define SPDIFRX_DR1_U         0x00000004	/* User bit */
  #define SPDIFRX_DR1_C         0x00000008	/* Channel Status bit */
  #define SPDIFRX_DR1_PT        0x00000030	/* Preamble Type */
  #define SPDIFRX_DR1_DR        0xFFFFFF00	/* Data value */
	/* (DRFMT = 0b10 case) */
  #define SPDIFRX_DR1_DRNL1     0xFFFF0000	/* Data value Channel B */
  #define SPDIFRX_DR1_DRNL2     0x0000FFFF	/* Data value Channel A      */
#define TOFF_SPDIFRX_CSR    0x0014		/* (RW) Channel Status register */
  #define SPDIFRX_CSR_USR       0x0000FFFF	/* User data information */
  #define SPDIFRX_CSR_CS        0x00FF0000	/* Channel A status information */
  #define SPDIFRX_CSR_SOB       0x01000000	/* Start Of Block */
#define TOFF_SPDIFRX_DIR    0x0018		/* (RW) Debug Information register */
  #define SPDIFRX_DIR_THI       0x00001FFF	/* Threshold LOW */
  #define SPDIFRX_DIR_TLO       0x1FFF0000	/* Threshold HIGH */


/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART1_BASE    (D2_APB2PERIPH_BASE + 0x1000)
#define TADR_USART6_BASE    (D2_APB2PERIPH_BASE + 0x1400)
#define TADR_USART2_BASE    (D2_APB1PERIPH_BASE + 0x4400)
#define TADR_USART3_BASE    (D2_APB1PERIPH_BASE + 0x4800)
#define TADR_UART4_BASE     (D2_APB1PERIPH_BASE + 0x4C00)
#define TADR_UART5_BASE     (D2_APB1PERIPH_BASE + 0x5000)
#define TADR_UART7_BASE     (D2_APB1PERIPH_BASE + 0x7800)
#define TADR_UART8_BASE     (D2_APB1PERIPH_BASE + 0x7C00)
#define TADR_LPUART1_BASE   (D3_APB1PERIPH_BASE + 0x0C00)
#define TOFF_USART_CR1      0x0000		/* (RW) USART Control register 1 */
  #define USART_CR1_UE       0x00000001	/* USART Enable */
  #define USART_CR1_UESM     0x00000002	/* USART Enable in STOP Mode */
  #define USART_CR1_RE       0x00000004	/* Receiver Enable */
  #define USART_CR1_TE       0x00000008	/* Transmitter Enable */
  #define USART_CR1_IDLEIE   0x00000010	/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE   0x00000020	/* RXNE Interrupt Enable */
  #define USART_CR1_RXNEIE_RXFNEIE USART_CR1_RXNEIE
  #define USART_CR1_TCIE     0x00000040	/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE    0x00000080	/* TXE Interrupt Enable */
  #define USART_CR1_TXEIE_TXFNFIE  USART_CR1_TXEIE
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
  #define USART_CR1_FIFOEN   0x20000000	/* FIFO mode enable */
  #define USART_CR1_TXFEIE   0x40000000	/* TXFIFO empty interrupt enable */
  #define USART_CR1_RXFFIE   0x80000000	/* RXFIFO Full interrupt enable */
#define TOFF_USART_CR2      0x0004		/* (RW) USART Control register 2 */
  #define USART_CR2_SLVEN    0x00000001	/* Synchronous Slave mode Enable */
  #define USART_CR2_DIS_NSS  0x00000008	/* Negative Slave Select (NSS) pin management */
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
  #define USART_CR3_WUS      0x00300000	/* WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
  #define USART_CR3_WUS_0    0x00100000
  #define USART_CR3_WUS_1    0x00200000
  #define USART_CR3_WUFIE    0x00400000	/* Wake Up Interrupt Enable */
  #define USART_CR3_TXFTIE   0x00800000	/* TXFIFO threshold interrupt enable */
  #define USART_CR3_TCBGTIE  0x01000000	/* Transmission Complete before guard time, interrupt enable */
  #define USART_CR3_RXFTCFG  0x0E000000	/* RXFTCFG [2:0]Receive FIFO threshold configuration */
  #define USART_CR3_RXFTCFG_0 0x02000000
  #define USART_CR3_RXFTCFG_1 0x04000000
  #define USART_CR3_RXFTCFG_2 0x08000000
  #define USART_CR3_RXFTIE   0x10000000	/* RXFIFO threshold interrupt enable */
  #define USART_CR3_TXFTCFG  0xE0000000	/* TXFIFO [2:0] threshold configuration */
  #define USART_CR3_TXFTCFG_0 0x20000000
  #define USART_CR3_TXFTCFG_1 0x40000000
  #define USART_CR3_TXFTCFG_2 0x80000000
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
  #define USART_ISR_RXNE_RXFNE  USART_ISR_RXNE
  #define USART_ISR_TC       0x00000040	/* Transmission Complete */
  #define USART_ISR_TXE      0x00000080	/* Transmit Data Register Empty */
  #define USART_ISR_TXE_TXFNF   USART_ISR_TXE
  #define USART_ISR_LBDF     0x00000100	/* LIN Break Detection Flag */
  #define USART_ISR_CTSIF    0x00000200	/* CTS interrupt flag */
  #define USART_ISR_CTS      0x00000400	/* CTS flag */
  #define USART_ISR_RTOF     0x00000800	/* Receiver Time Out */
  #define USART_ISR_EOBF     0x00001000	/* End Of Block Flag */
  #define USART_ISR_UDR      0x00002000	/* SPI slave underrun error flag */
  #define USART_ISR_ABRE     0x00004000	/* Auto-Baud Rate Error */
  #define USART_ISR_ABRF     0x00008000	/* Auto-Baud Rate Flag */
  #define USART_ISR_BUSY     0x00010000	/* Busy Flag */
  #define USART_ISR_CMF      0x00020000	/* Character Match Flag */
  #define USART_ISR_SBKF     0x00040000	/* Send Break Flag */
  #define USART_ISR_RWU      0x00080000	/* Receive Wake Up from mute mode Flag */
  #define USART_ISR_WUF      0x00100000	/* Wake Up from stop mode Flag */
  #define USART_ISR_TEACK    0x00200000	/* Transmit Enable Acknowledge Flag */
  #define USART_ISR_REACK    0x00400000	/* Receive Enable Acknowledge Flag */
  #define USART_ISR_TXFE     0x00800000	/* TXFIFO Empty */
  #define USART_ISR_RXFF     0x01000000	/* RXFIFO Full Flag */
  #define USART_ISR_TCBGT    0x02000000	/* Transmission complete before guard time Flag */
  #define USART_ISR_RXFT     0x04000000	/* RXFIFO threshold Flag */
  #define USART_ISR_TXFT     0x08000000	/* TXFIFO threshold Flag */
#define TOFF_USART_ICR      0x0020		/* (RW) USART Interrupt flag Clear register */
  #define USART_ICR_PECF     0x00000001	/* Parity Error Clear Flag */
  #define USART_ICR_FECF     0x00000002	/* Framing Error Clear Flag */
  #define USART_ICR_NCF      0x00000004	/* Noise detected Clear Flag */
  #define USART_ICR_ORECF    0x00000008	/* OverRun Error Clear Flag */
  #define USART_ICR_IDLECF   0x00000010	/* IDLE line detected Clear Flag */
  #define USART_ICR_TXFECF   0x00000020	/* TXFIFO empty clear flag */
  #define USART_ICR_TCCF     0x00000040	/* Transmission Complete Clear Flag */
  #define USART_ICR_TCBGTCF  0x00000080	/* Transmission complete before guard time Clear Flag */
  #define USART_ICR_LBDCF    0x00000100	/* LIN Break Detection Clear Flag */
  #define USART_ICR_CTSCF    0x00000200	/* CTS Interrupt Clear Flag */
  #define USART_ICR_RTOCF    0x00000800	/* Receiver Time Out Clear Flag */
  #define USART_ICR_EOBCF    0x00001000	/* End Of Block Clear Flag */
  #define USART_ICR_UDRCF    0x00002000	/* SPI slave underrun clear flag */
  #define USART_ICR_CMCF     0x00020000	/* Character Match Clear Flag */
  #define USART_ICR_WUCF     0x00100000	/* Wake Up from stop mode Clear Flag */
#define TOFF_USART_RDR      0x0024		/* (RW) USART Receive Data register */
#define TOFF_USART_TDR      0x0028		/* (RW) USART Transmit Data register */
#define TOFF_USART_PRESC    0x002C		/* (RW) USART clock Prescaler register */
  #define USART_PRESC_PRESCALER   0x0000000F	/* PRESCALER[3:0] bits (Clock prescaler) */
  #define USART_PRESC_PRESCALER_0 0x00000001
  #define USART_PRESC_PRESCALER_1 0x00000002
  #define USART_PRESC_PRESCALER_2 0x00000004
  #define USART_PRESC_PRESCALER_3 0x00000008


/*
 *  INTER-INTERATED CIRCUIT IINTERFACE
 */
#define TADR_I2C1_BASE      (D2_APB1PERIPH_BASE + 0x5400)
#define TADR_I2C2_BASE      (D2_APB1PERIPH_BASE + 0x5800)
#define TADR_I2C3_BASE      (D2_APB1PERIPH_BASE + 0x5C00)
#define TADR_I2C4_BASE      (D3_APB1PERIPH_BASE + 0x1C00)
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
 *  HRTIM
 */
#define TADR_HRTIM1_BASE    (D2_APB2PERIPH_BASE + 0x7400)
#define TOFF_HRTIM_MCR      0x0000		/* (RW) HRTIM Master Timer control register */
  #define HRTIM_MCR_CK_PSC          0x00000007	/* Prescaler mask */
  #define HRTIM_MCR_CK_PSC_0        0x00000001
  #define HRTIM_MCR_CK_PSC_1        0x00000002
  #define HRTIM_MCR_CK_PSC_2        0x00000004
  #define HRTIM_MCR_CONT            0x00000008	/* Continuous mode */
  #define HRTIM_MCR_RETRIG          0x00000010	/* Rettrigreable mode */
  #define HRTIM_MCR_HALF            0x00000020	/* Half mode */
  #define HRTIM_MCR_SYNC_IN         0x00000300	/* Synchronization input master */
  #define HRTIM_MCR_SYNC_IN_0       0x00000100
  #define HRTIM_MCR_SYNC_IN_1       0x00000200
  #define HRTIM_MCR_SYNCRSTM        0x00000400	/* Synchronization reset master */
  #define HRTIM_MCR_SYNCSTRTM       0x00000800	/* Synchronization start master */
  #define HRTIM_MCR_SYNC_OUT        0x00003000	/* Synchronization output master */
  #define HRTIM_MCR_SYNC_OUT_0      0x00001000
  #define HRTIM_MCR_SYNC_OUT_1      0x00002000
  #define HRTIM_MCR_SYNC_SRC        0x0000C000	/* Synchronization source */
  #define HRTIM_MCR_SYNC_SRC_0      0x00004000
  #define HRTIM_MCR_SYNC_SRC_1      0x00008000
  #define HRTIM_MCR_MCEN            0x00010000	/* Master counter enable */
  #define HRTIM_MCR_TACEN           0x00020000	/* Timer A counter enable */
  #define HRTIM_MCR_TBCEN           0x00040000	/* Timer B counter enable */
  #define HRTIM_MCR_TCCEN           0x00080000	/* Timer C counter enable */
  #define HRTIM_MCR_TDCEN           0x00100000	/* Timer D counter enable */
  #define HRTIM_MCR_TECEN           0x00200000	/* Timer E counter enable */
  #define HRTIM_MCR_DACSYNC         0x06000000	/* DAC sychronization mask */
  #define HRTIM_MCR_DACSYNC_0       0x02000000
  #define HRTIM_MCR_DACSYNC_1       0x04000000
  #define HRTIM_MCR_PREEN           0x08000000	/* Master preload enable */
  #define HRTIM_MCR_MREPU           0x20000000	/* Master repetition update */
  #define HRTIM_MCR_BRSTDMA         0xC0000000	/* Burst DMA update */
  #define HRTIM_MCR_BRSTDMA_0       0x40000000
  #define HRTIM_MCR_BRSTDMA_1       0x80000000
#define TOFF_HRTIM_MISR     0x0004		/* (RW) HRTIM Master Timer interrupt status register */
  #define HRTIM_MISR_MCMP1          0x00000001	/* Master compare 1 interrupt flag */
  #define HRTIM_MISR_MCMP2          0x00000002	/* Master compare 2 interrupt flag */
  #define HRTIM_MISR_MCMP3          0x00000004	/* Master compare 3 interrupt flag */
  #define HRTIM_MISR_MCMP4          0x00000008	/* Master compare 4 interrupt flag */
  #define HRTIM_MISR_MREP           0x00000010	/* Master Repetition interrupt flag */
  #define HRTIM_MISR_SYNC           0x00000020	/* Synchronization input interrupt flag */
  #define HRTIM_MISR_MUPD           0x00000040	/* Master update interrupt flag */
#define TOFF_HRTIM_MICR     0x0008		/* (RW) HRTIM Master Timer interupt clear register */
  #define HRTIM_MICR_MCMP1          0x00000001	/* Master compare 1 interrupt flag clear */
  #define HRTIM_MICR_MCMP2          0x00000002	/* Master compare 2 interrupt flag clear */
  #define HRTIM_MICR_MCMP3          0x00000004	/* Master compare 3 interrupt flag clear */
  #define HRTIM_MICR_MCMP4          0x00000008	/* Master compare 4 interrupt flag clear */
  #define HRTIM_MICR_MREP           0x00000010	/* Master Repetition interrupt flag clear */
  #define HRTIM_MICR_SYNC           0x00000020	/* Synchronization input interrupt flag clear */
  #define HRTIM_MICR_MUPD           0x00000040	/* Master update interrupt flag clear */
#define TOFF_HRTIM_MDIER    0x000C		/* (RW) HRTIM Master Timer DMA/interrupt enable register */
  #define HRTIM_MDIER_MCMP1IE       0x00000001	/* Master compare 1 interrupt enable */
  #define HRTIM_MDIER_MCMP2IE       0x00000002	/* Master compare 2 interrupt enable */
  #define HRTIM_MDIER_MCMP3IE       0x00000004	/* Master compare 3 interrupt enable */
  #define HRTIM_MDIER_MCMP4IE       0x00000008	/* Master compare 4 interrupt enable */
  #define HRTIM_MDIER_MREPIE        0x00000010	/* Master Repetition interrupt enable */
  #define HRTIM_MDIER_SYNCIE        0x00000020	/* Synchronization input interrupt enable */
  #define HRTIM_MDIER_MUPDIE        0x00000040	/* Master update interrupt enable */
  #define HRTIM_MDIER_MCMP1DE       0x00010000	/* Master compare 1 DMA enable */
  #define HRTIM_MDIER_MCMP2DE       0x00020000	/* Master compare 2 DMA enable */
  #define HRTIM_MDIER_MCMP3DE       0x00040000	/* Master compare 3 DMA enable */
  #define HRTIM_MDIER_MCMP4DE       0x00080000	/* Master compare 4 DMA enable */
  #define HRTIM_MDIER_MREPDE        0x00100000	/* Master Repetition DMA enable */
  #define HRTIM_MDIER_SYNCDE        0x00200000	/* Synchronization input DMA enable */
  #define HRTIM_MDIER_MUPDDE        0x00400000	/* Master update DMA enable */
#define TOFF_HRTIM_MCNTR    0x0010		/* (RW) HRTIM Master Timer counter register */
#define TOFF_HRTIM_MPER     0x0014		/* (RW) HRTIM Master Timer period register */
#define TOFF_HRTIM_MREP     0x0018		/* (RW) HRTIM Master Timer repetition register */
#define TOFF_HRTIM_MCMP1R   0x001C		/* (RW) HRTIM Master Timer compare 1 register */
#define TOFF_HRTIM_MCMP2R   0x0024		/* (RW) HRTIM Master Timer compare 2 register */
#define TOFF_HRTIM_MCMP3R   0x0028		/* (RW) HRTIM Master Timer compare 3 register */

#define TOFF_HRTIM_CR1      0x0380		/* (RW) HRTIM control register1 */
  #define HRTIM_CR1_MUDIS           0x00000001	/* Master update disable*/
  #define HRTIM_CR1_TAUDIS          0x00000002	/* Timer A update disable*/
  #define HRTIM_CR1_TBUDIS          0x00000004	/* Timer B update disable*/
  #define HRTIM_CR1_TCUDIS          0x00000008	/* Timer C update disable*/
  #define HRTIM_CR1_TDUDIS          0x00000010	/* Timer D update disable*/
  #define HRTIM_CR1_TEUDIS          0x00000020	/* Timer E update disable*/
  #define HRTIM_CR1_ADC1USRC        0x00070000	/* ADC Trigger 1 update source */
  #define HRTIM_CR1_ADC1USRC_0      0x00010000
  #define HRTIM_CR1_ADC1USRC_1      0x00020000
  #define HRTIM_CR1_ADC1USRC_2      0x00040000
  #define HRTIM_CR1_ADC2USRC        0x00380000	/* ADC Trigger 2 update source */
  #define HRTIM_CR1_ADC2USRC_0      0x00080000
  #define HRTIM_CR1_ADC2USRC_1      0x00100000
  #define HRTIM_CR1_ADC2USRC_2      0x00200000
  #define HRTIM_CR1_ADC3USRC        0x01C00000	/* ADC Trigger 3 update source */
  #define HRTIM_CR1_ADC3USRC_0      0x00400000
  #define HRTIM_CR1_ADC3USRC_1      0x00800000
  #define HRTIM_CR1_ADC3USRC_2      0x01000000
  #define HRTIM_CR1_ADC4USRC        0x0E000000	/* ADC Trigger 4 update source */
  #define HRTIM_CR1_ADC4USRC_0      0x02000000
  #define HRTIM_CR1_ADC4USRC_1      0x04000000
  #define HRTIM_CR1_ADC4USRC_2      0x08000000
#define TOFF_HRTIM_CR2      0x0384		/* (RW) HRTIM control register2 */
  #define HRTIM_CR2_MSWU            0x00000001	/* Master software update */
  #define HRTIM_CR2_TASWU           0x00000002	/* Timer A software update */
  #define HRTIM_CR2_TBSWU           0x00000004	/* Timer B software update */
  #define HRTIM_CR2_TCSWU           0x00000008	/* Timer C software update */
  #define HRTIM_CR2_TDSWU           0x00000010	/* Timer D software update */
  #define HRTIM_CR2_TESWU           0x00000020	/* Timer E software update */
  #define HRTIM_CR2_MRST            0x00000100	/* Master count software reset */
  #define HRTIM_CR2_TARST           0x00000200	/* Timer A count software reset */
  #define HRTIM_CR2_TBRST           0x00000400	/* Timer B count software reset */
  #define HRTIM_CR2_TCRST           0x00000800	/* Timer C count software reset */
  #define HRTIM_CR2_TDRST           0x00001000	/* Timer D count software reset */
  #define HRTIM_CR2_TERST           0x00002000	/* Timer E count software reset */
#define TOFF_HRTIM_ISR      0x0388		/* (RW) HRTIM interrupt status register */
  #define HRTIM_ISR_FLT1            0x00000001	/* Fault 1 interrupt flag */
  #define HRTIM_ISR_FLT2            0x00000002	/* Fault 2 interrupt flag */
  #define HRTIM_ISR_FLT3            0x00000004	/* Fault 3 interrupt flag */
  #define HRTIM_ISR_FLT4            0x00000008	/* Fault 4 interrupt flag */
  #define HRTIM_ISR_FLT5            0x00000010	/* Fault 5 interrupt flag */
  #define HRTIM_ISR_SYSFLT          0x00000020	/* System Fault interrupt flag */
  #define HRTIM_ISR_BMPER           0x00020000	/*  Burst mode period interrupt flag */
#define TOFF_HRTIM_ICR      0x038C		/* (RW) HRTIM interrupt clear register */
  #define HRTIM_ICR_FLT1C           0x00000001	/* Fault 1 interrupt flag clear */
  #define HRTIM_ICR_FLT2C           0x00000002	/* Fault 2 interrupt flag clear */
  #define HRTIM_ICR_FLT3C           0x00000004	/* Fault 3 interrupt flag clear */
  #define HRTIM_ICR_FLT4C           0x00000008	/* Fault 4 interrupt flag clear */
  #define HRTIM_ICR_FLT5C           0x00000010	/* Fault 5 interrupt flag clear */
  #define HRTIM_ICR_SYSFLTC         0x00000020	/* System Fault interrupt flag clear */
  #define HRTIM_ICR_BMPERC          0x00020000	/*  Burst mode period interrupt flag clear */
#define TOFF_HRTIM_IER      0x0390		/* (RW) HRTIM interrupt enable register */
  #define HRTIM_IER_FLT1            0x00000001	/* Fault 1 interrupt enable */
  #define HRTIM_IER_FLT2            0x00000002	/* Fault 2 interrupt enable */
  #define HRTIM_IER_FLT3            0x00000004	/* Fault 3 interrupt enable */
  #define HRTIM_IER_FLT4            0x00000008	/* Fault 4 interrupt enable */
  #define HRTIM_IER_FLT5            0x00000010	/* Fault 5 interrupt enable */
  #define HRTIM_IER_SYSFLT          0x00000020	/* System Fault interrupt enable */
  #define HRTIM_IER_BMPER           0x00020000	/*  Burst mode period interrupt enable */
#define TOFF_HRTIM_OENR     0x0394		/* (RW) HRTIM Output enable register */
  #define HRTIM_OENR_TA1OEN         0x00000001	/* Timer A Output 1 enable */
  #define HRTIM_OENR_TA2OEN         0x00000002	/* Timer A Output 2 enable */
  #define HRTIM_OENR_TB1OEN         0x00000004	/* Timer B Output 1 enable */
  #define HRTIM_OENR_TB2OEN         0x00000008	/* Timer B Output 2 enable */
  #define HRTIM_OENR_TC1OEN         0x00000010	/* Timer C Output 1 enable */
  #define HRTIM_OENR_TC2OEN         0x00000020	/* Timer C Output 2 enable */
  #define HRTIM_OENR_TD1OEN         0x00000040	/* Timer D Output 1 enable */
  #define HRTIM_OENR_TD2OEN         0x00000080	/* Timer D Output 2 enable */
  #define HRTIM_OENR_TE1OEN         0x00000100	/* Timer E Output 1 enable */
  #define HRTIM_OENR_TE2OEN         0x00000200	/* Timer E Output 2 enable */
#define TOFF_HRTIM_ODISR    0x0398		/* (RW) HRTIM Output disable register */
  #define HRTIM_ODISR_TA1ODIS       0x00000001	/* Timer A Output 1 disable */
  #define HRTIM_ODISR_TA2ODIS       0x00000002	/* Timer A Output 2 disable */
  #define HRTIM_ODISR_TB1ODIS       0x00000004	/* Timer B Output 1 disable */
  #define HRTIM_ODISR_TB2ODIS       0x00000008	/* Timer B Output 2 disable */
  #define HRTIM_ODISR_TC1ODIS       0x00000010	/* Timer C Output 1 disable */
  #define HRTIM_ODISR_TC2ODIS       0x00000020	/* Timer C Output 2 disable */
  #define HRTIM_ODISR_TD1ODIS       0x00000040	/* Timer D Output 1 disable */
  #define HRTIM_ODISR_TD2ODIS       0x00000080	/* Timer D Output 2 disable */
  #define HRTIM_ODISR_TE1ODIS       0x00000100	/* Timer E Output 1 disable */
  #define HRTIM_ODISR_TE2ODIS       0x00000200	/* Timer E Output 2 disable */
#define TOFF_HRTIM_ODSR     0x039C		/* (RW) HRTIM Output disable status register */
  #define HRTIM_ODSR_TA1ODS         0x00000001	/* Timer A Output 1 disable status */
  #define HRTIM_ODSR_TA2ODS         0x00000002	/* Timer A Output 2 disable status */
  #define HRTIM_ODSR_TB1ODS         0x00000004	/* Timer B Output 1 disable status */
  #define HRTIM_ODSR_TB2ODS         0x00000008	/* Timer B Output 2 disable status */
  #define HRTIM_ODSR_TC1ODS         0x00000010	/* Timer C Output 1 disable status */
  #define HRTIM_ODSR_TC2ODS         0x00000020	/* Timer C Output 2 disable status */
  #define HRTIM_ODSR_TD1ODS         0x00000040	/* Timer D Output 1 disable status */
  #define HRTIM_ODSR_TD2ODS         0x00000080	/* Timer D Output 2 disable status */
  #define HRTIM_ODSR_TE1ODS         0x00000100	/* Timer E Output 1 disable status */
  #define HRTIM_ODSR_TE2ODS         0x00000200	/* Timer E Output 2 disable status */
#define TOFF_HRTIM_BMCR     0x03A0		/* (RW) HRTIM Burst mode control register */
  #define HRTIM_BMCR_BME            0x00000001	/* Burst mode enbale */
  #define HRTIM_BMCR_BMOM           0x00000002	/* Burst mode operating mode */
  #define HRTIM_BMCR_BMCLK          0x0000003C	/* Burst mode clock source */
  #define HRTIM_BMCR_BMCLK_0        0x00000004
  #define HRTIM_BMCR_BMCLK_1        0x00000008
  #define HRTIM_BMCR_BMCLK_2        0x00000010
  #define HRTIM_BMCR_BMCLK_3        0x00000020
  #define HRTIM_BMCR_BMPRSC         0x000003C0	/* Burst mode prescaler */
  #define HRTIM_BMCR_BMPRSC_0       0x00000040
  #define HRTIM_BMCR_BMPRSC_1       0x00000080
  #define HRTIM_BMCR_BMPRSC_2       0x00000100
  #define HRTIM_BMCR_BMPRSC_3       0x00000200
  #define HRTIM_BMCR_BMPREN         0x00000400	/* Burst mode Preload bit */
  #define HRTIM_BMCR_MTBM           0x00010000	/* Master Timer Burst mode */
  #define HRTIM_BMCR_TABM           0x00020000	/* Timer A Burst mode */
  #define HRTIM_BMCR_TBBM           0x00040000	/* Timer B Burst mode */
  #define HRTIM_BMCR_TCBM           0x00080000	/* Timer C Burst mode */
  #define HRTIM_BMCR_TDBM           0x00100000	/* Timer D Burst mode */
  #define HRTIM_BMCR_TEBM           0x00200000	/* Timer E Burst mode */
  #define HRTIM_BMCR_BMSTAT         0x80000000	/* Burst mode status */
#define TOFF_HRTIM_BMTRGR   0x03A4		/* (RW) HRTIM Busrt mode trigger register */
  #define HRTIM_BMTRGR_SW           0x00000001	/* Software start */
  #define HRTIM_BMTRGR_MSTRST       0x00000002	/* Master reset */
  #define HRTIM_BMTRGR_MSTREP       0x00000004	/* Master repetition */
  #define HRTIM_BMTRGR_MSTCMP1      0x00000008	/* Master compare 1 */
  #define HRTIM_BMTRGR_MSTCMP2      0x00000010	/* Master compare 2  */
  #define HRTIM_BMTRGR_MSTCMP3      0x00000020	/* Master compare 3 */
  #define HRTIM_BMTRGR_MSTCMP4      0x00000040	/* Master compare 4 */
  #define HRTIM_BMTRGR_TARST        0x00000080	/* Timer A reset  */
  #define HRTIM_BMTRGR_TAREP        0x00000100	/* Timer A repetition  */
  #define HRTIM_BMTRGR_TACMP1       0x00000200	/* Timer A compare 1  */
  #define HRTIM_BMTRGR_TACMP2       0x00000400	/* Timer A compare 2  */
  #define HRTIM_BMTRGR_TBRST        0x00000800	/* Timer B reset  */
  #define HRTIM_BMTRGR_TBREP        0x00001000	/* Timer B repetition  */
  #define HRTIM_BMTRGR_TBCMP1       0x00002000	/* Timer B compare 1 */
  #define HRTIM_BMTRGR_TBCMP2       0x00004000	/* Timer B compare 2 */
  #define HRTIM_BMTRGR_TCRST        0x00008000	/* Timer C reset  */
  #define HRTIM_BMTRGR_TCREP        0x00010000	/* Timer C repetition */
  #define HRTIM_BMTRGR_TCCMP1       0x00020000	/* Timer C compare 1 */
  #define HRTIM_BMTRGR_TCCMP2       0x00040000	/* Timer C compare 2 */
  #define HRTIM_BMTRGR_TDRST        0x00080000	/* Timer D reset  */
  #define HRTIM_BMTRGR_TDREP        0x00100000	/* Timer D repetition  */
  #define HRTIM_BMTRGR_TDCMP1       0x00200000	/* Timer D compare 1 */
  #define HRTIM_BMTRGR_TDCMP2       0x00400000	/* Timer D compare 2 */
  #define HRTIM_BMTRGR_TERST        0x00800000	/* Timer E reset  */
  #define HRTIM_BMTRGR_TEREP        0x01000000	/* Timer E repetition  */
  #define HRTIM_BMTRGR_TECMP1       0x02000000	/* Timer E compare 1 */
  #define HRTIM_BMTRGR_TECMP2       0x04000000	/* Timer E compare 2 */
  #define HRTIM_BMTRGR_TAEEV7       0x08000000	/* Timer A period following External Event7  */
  #define HRTIM_BMTRGR_TDEEV8       0x10000000	/* Timer D period following External Event8  */
  #define HRTIM_BMTRGR_EEV7         0x20000000	/* External Event 7 */
  #define HRTIM_BMTRGR_EEV8         0x40000000	/* External Event 8 */
  #define HRTIM_BMTRGR_OCHPEV       0x80000000	/* on-chip Event */
#define TOFF_HRTIM_BMCMPR   0x03A8		/* (RW) HRTIM Burst mode compare register */
#define TOFF_HRTIM_BMPER    0x03AC		/* (RW) HRTIM Burst mode period register */
#define TOFF_HRTIM_EECR1    0x03B0		/* (RW) HRTIM Timer external event control register1 */
  #define HRTIM_EECR1_EE1SRC        0x00000003	/* External event 1 source */
  #define HRTIM_EECR1_EE1SRC_0      0x00000001
  #define HRTIM_EECR1_EE1SRC_1      0x00000002
  #define HRTIM_EECR1_EE1POL        0x00000004	/* External event 1 Polarity */
  #define HRTIM_EECR1_EE1SNS        0x00000018	/* External event 1 sensitivity */
  #define HRTIM_EECR1_EE1SNS_0      0x00000008
  #define HRTIM_EECR1_EE1SNS_1      0x00000010
  #define HRTIM_EECR1_EE1FAST       0x00000020	/* External event 1 Fast mode */
  #define HRTIM_EECR1_EE2SRC        0x000000C0	/* External event 2 source */
  #define HRTIM_EECR1_EE2SRC_0      0x00000040
  #define HRTIM_EECR1_EE2SRC_1      0x00000080
  #define HRTIM_EECR1_EE2POL        0x00000100	/* External event 2 Polarity */
  #define HRTIM_EECR1_EE2SNS        0x00000600	/* External event 2 sensitivity */
  #define HRTIM_EECR1_EE2SNS_0      0x00000200
  #define HRTIM_EECR1_EE2SNS_1      0x00000400
  #define HRTIM_EECR1_EE2FAST       0x00000800	/* External event 2 Fast mode */
  #define HRTIM_EECR1_EE3SRC        0x00003000	/* External event 3 source */
  #define HRTIM_EECR1_EE3SRC_0      0x00001000
  #define HRTIM_EECR1_EE3SRC_1      0x00002000
  #define HRTIM_EECR1_EE3POL        0x00004000	/* External event 3 Polarity */
  #define HRTIM_EECR1_EE3SNS        0x00018000	/* External event 3 sensitivity */
  #define HRTIM_EECR1_EE3SNS_0      0x00008000
  #define HRTIM_EECR1_EE3SNS_1      0x00010000
  #define HRTIM_EECR1_EE3FAST       0x00020000	/* External event 3 Fast mode */
  #define HRTIM_EECR1_EE4SRC        0x000C0000	/* External event 4 source */
  #define HRTIM_EECR1_EE4SRC_0      0x00040000
  #define HRTIM_EECR1_EE4SRC_1      0x00080000
  #define HRTIM_EECR1_EE4POL        0x00100000	/* External event 4 Polarity */
  #define HRTIM_EECR1_EE4SNS        0x00600000	/* External event 4 sensitivity */
  #define HRTIM_EECR1_EE4SNS_0      0x00200000
  #define HRTIM_EECR1_EE4SNS_1      0x00400000
  #define HRTIM_EECR1_EE4FAST       0x00800000	/* External event 4 Fast mode */
  #define HRTIM_EECR1_EE5SRC        0x03000000	/* External event 5 source */
  #define HRTIM_EECR1_EE5SRC_0      0x01000000
  #define HRTIM_EECR1_EE5SRC_1      0x02000000
  #define HRTIM_EECR1_EE5POL        0x04000000	/* External event 5 Polarity */
  #define HRTIM_EECR1_EE5SNS        0x18000000	/* External event 5 sensitivity */
  #define HRTIM_EECR1_EE5SNS_0      0x08000000
  #define HRTIM_EECR1_EE5SNS_1      0x10000000
  #define HRTIM_EECR1_EE5FAST       0x20000000	/* External event 5 Fast mode */
#define TOFF_HRTIM_EECR2    0x03B4		/* (RW) HRTIM Timer external event control register2 */
  #define HRTIM_EECR2_EE6SRC        0x00000003	/* External event 6 source */
  #define HRTIM_EECR2_EE6SRC_0      0x00000001
  #define HRTIM_EECR2_EE6SRC_1      0x00000002
  #define HRTIM_EECR2_EE6POL        0x00000004	/* External event 6 Polarity */
  #define HRTIM_EECR2_EE6SNS        0x00000018	/* External event 6 sensitivity */
  #define HRTIM_EECR2_EE6SNS_0      0x00000008
  #define HRTIM_EECR2_EE6SNS_1      0x00000010
  #define HRTIM_EECR2_EE7SRC        0x000000C0	/* External event 7 source */
  #define HRTIM_EECR2_EE7SRC_0      0x00000040
  #define HRTIM_EECR2_EE7SRC_1      0x00000080
  #define HRTIM_EECR2_EE7POL        0x00000100	/* External event 7 Polarity */
  #define HRTIM_EECR2_EE7SNS        0x00000600	/* External event 7 sensitivity */
  #define HRTIM_EECR2_EE7SNS_0      0x00000200
  #define HRTIM_EECR2_EE7SNS_1      0x00000400
  #define HRTIM_EECR2_EE8SRC        0x00003000	/* External event 8 source */
  #define HRTIM_EECR2_EE8SRC_0      0x00001000
  #define HRTIM_EECR2_EE8SRC_1      0x00002000
  #define HRTIM_EECR2_EE8POL        0x00004000	/* External event 8 Polarity */
  #define HRTIM_EECR2_EE8SNS        0x00018000	/* External event 8 sensitivity */
  #define HRTIM_EECR2_EE8SNS_0      0x00008000
  #define HRTIM_EECR2_EE8SNS_1      0x00010000
  #define HRTIM_EECR2_EE9SRC        0x000C0000	/* External event 9 source */
  #define HRTIM_EECR2_EE9SRC_0      0x00040000
  #define HRTIM_EECR2_EE9SRC_1      0x00080000
  #define HRTIM_EECR2_EE9POL        0x00100000	/* External event 9 Polarity */
  #define HRTIM_EECR2_EE9SNS        0x00600000	/* External event 9 sensitivity */
  #define HRTIM_EECR2_EE9SNS_0      0x00200000
  #define HRTIM_EECR2_EE9SNS_1      0x00400000
  #define HRTIM_EECR2_EE10SRC       0x03000000	/* External event 10 source */
  #define HRTIM_EECR2_EE10SRC_0     0x01000000
  #define HRTIM_EECR2_EE10SRC_1     0x02000000
  #define HRTIM_EECR2_EE10POL       0x04000000	/* External event 10 Polarity */
  #define HRTIM_EECR2_EE10SNS       0x18000000	/* External event 10 sensitivity */
  #define HRTIM_EECR2_EE10SNS_0     0x08000000
  #define HRTIM_EECR2_EE10SNS_1     0x10000000
#define TOFF_HRTIM_EECR3    0x03B8		/* (RW) HRTIM Timer external event control register3 */
  #define HRTIM_EECR3_EE6F          0x0000000F	/* External event 6 filter */
  #define HRTIM_EECR3_EE6F_0        0x00000001
  #define HRTIM_EECR3_EE6F_1        0x00000002
  #define HRTIM_EECR3_EE6F_2        0x00000004
  #define HRTIM_EECR3_EE6F_3        0x00000008
  #define HRTIM_EECR3_EE7F          0x000003C0	/* External event 7 filter */
  #define HRTIM_EECR3_EE7F_0        0x00000040
  #define HRTIM_EECR3_EE7F_1        0x00000080
  #define HRTIM_EECR3_EE7F_2        0x00000100
  #define HRTIM_EECR3_EE7F_3        0x00000200
  #define HRTIM_EECR3_EE8F          0x0000F000	/* External event 8 filter */
  #define HRTIM_EECR3_EE8F_0        0x00001000
  #define HRTIM_EECR3_EE8F_1        0x00002000
  #define HRTIM_EECR3_EE8F_2        0x00004000
  #define HRTIM_EECR3_EE8F_3        0x00008000
  #define HRTIM_EECR3_EE9F          0x003C0000	/* External event 9 filter */
  #define HRTIM_EECR3_EE9F_0        0x00040000
  #define HRTIM_EECR3_EE9F_1        0x00080000
  #define HRTIM_EECR3_EE9F_2        0x00100000
  #define HRTIM_EECR3_EE9F_3        0x00200000
  #define HRTIM_EECR3_EE10F         0x0F000000	/* External event 10 filter */
  #define HRTIM_EECR3_EE10F_0       0x01000000
  #define HRTIM_EECR3_EE10F_1       0x02000000
  #define HRTIM_EECR3_EE10F_2       0x04000000
  #define HRTIM_EECR3_EE10F_3       0x08000000
  #define HRTIM_EECR3_EEVSD         0xC0000000	/* External event sampling clock division */
  #define HRTIM_EECR3_EEVSD_0       0x40000000
  #define HRTIM_EECR3_EEVSD_1       0x80000000
#define TOFF_HRTIM_ADC1R    0x03BC		/* (RW) HRTIM ADC Trigger 1 register */
  #define HRTIM_ADC1R_AD1MC1        0x00000001	/* ADC Trigger 1 on master compare 1 */
  #define HRTIM_ADC1R_AD1MC2        0x00000002	/* ADC Trigger 1 on master compare 2 */
  #define HRTIM_ADC1R_AD1MC3        0x00000004	/* ADC Trigger 1 on master compare 3 */
  #define HRTIM_ADC1R_AD1MC4        0x00000008	/* ADC Trigger 1 on master compare 4 */
  #define HRTIM_ADC1R_AD1MPER       0x00000010	/* ADC Trigger 1 on master period */
  #define HRTIM_ADC1R_AD1EEV1       0x00000020	/* ADC Trigger 1 on external event 1 */
  #define HRTIM_ADC1R_AD1EEV2       0x00000040	/* ADC Trigger 1 on external event 2 */
  #define HRTIM_ADC1R_AD1EEV3       0x00000080	/* ADC Trigger 1 on external event 3 */
  #define HRTIM_ADC1R_AD1EEV4       0x00000100	/* ADC Trigger 1 on external event 4 */
  #define HRTIM_ADC1R_AD1EEV5       0x00000200	/* ADC Trigger 1 on external event 5 */
  #define HRTIM_ADC1R_AD1TAC2       0x00000400	/* ADC Trigger 1 on Timer A compare 2 */
  #define HRTIM_ADC1R_AD1TAC3       0x00000800	/* ADC Trigger 1 on Timer A compare 3 */
  #define HRTIM_ADC1R_AD1TAC4       0x00001000	/* ADC Trigger 1 on Timer A compare 4 */
  #define HRTIM_ADC1R_AD1TAPER      0x00002000	/* ADC Trigger 1 on Timer A period */
  #define HRTIM_ADC1R_AD1TARST      0x00004000	/* ADC Trigger 1 on Timer A reset */
  #define HRTIM_ADC1R_AD1TBC2       0x00008000	/* ADC Trigger 1 on Timer B compare 2 */
  #define HRTIM_ADC1R_AD1TBC3       0x00010000	/* ADC Trigger 1 on Timer B compare 3 */
  #define HRTIM_ADC1R_AD1TBC4       0x00020000	/* ADC Trigger 1 on Timer B compare 4 */
  #define HRTIM_ADC1R_AD1TBPER      0x00040000	/* ADC Trigger 1 on Timer B period */
  #define HRTIM_ADC1R_AD1TBRST      0x00080000	/* ADC Trigger 1 on Timer B reset */
  #define HRTIM_ADC1R_AD1TCC2       0x00100000	/* ADC Trigger 1 on Timer C compare 2 */
  #define HRTIM_ADC1R_AD1TCC3       0x00200000	/* ADC Trigger 1 on Timer C compare 3 */
  #define HRTIM_ADC1R_AD1TCC4       0x00400000	/* ADC Trigger 1 on Timer C compare 4 */
  #define HRTIM_ADC1R_AD1TCPER      0x00800000	/* ADC Trigger 1 on Timer C period */
  #define HRTIM_ADC1R_AD1TDC2       0x01000000	/* ADC Trigger 1 on Timer D compare 2 */
  #define HRTIM_ADC1R_AD1TDC3       0x02000000	/* ADC Trigger 1 on Timer D compare 3 */
  #define HRTIM_ADC1R_AD1TDC4       0x04000000	/* ADC Trigger 1 on Timer D compare 4 */
  #define HRTIM_ADC1R_AD1TDPER      0x08000000	/* ADC Trigger 1 on Timer D period */
  #define HRTIM_ADC1R_AD1TEC2       0x10000000	/* ADC Trigger 1 on Timer E compare 2 */
  #define HRTIM_ADC1R_AD1TEC3       0x20000000	/* ADC Trigger 1 on Timer E compare 3 */
  #define HRTIM_ADC1R_AD1TEC4       0x40000000	/* ADC Trigger 1 on Timer E compare 4 */
  #define HRTIM_ADC1R_AD1TEPER      0x80000000	/* ADC Trigger 1 on Timer E period */
#define TOFF_HRTIM_ADC2R    0x03C0		/* (RW) HRTIM ADC Trigger 2 register */
  #define HRTIM_ADC2R_AD2MC1        0x00000001	/* ADC Trigger 2 on master compare 1 */
  #define HRTIM_ADC2R_AD2MC2        0x00000002	/* ADC Trigger 2 on master compare 2 */
  #define HRTIM_ADC2R_AD2MC3        0x00000004	/* ADC Trigger 2 on master compare 3 */
  #define HRTIM_ADC2R_AD2MC4        0x00000008	/* ADC Trigger 2 on master compare 4 */
  #define HRTIM_ADC2R_AD2MPER       0x00000010	/* ADC Trigger 2 on master period */
  #define HRTIM_ADC2R_AD2EEV6       0x00000020	/* ADC Trigger 2 on external event 6 */
  #define HRTIM_ADC2R_AD2EEV7       0x00000040	/* ADC Trigger 2 on external event 7 */
  #define HRTIM_ADC2R_AD2EEV8       0x00000080	/* ADC Trigger 2 on external event 8 */
  #define HRTIM_ADC2R_AD2EEV9       0x00000100	/* ADC Trigger 2 on external event 9 */
  #define HRTIM_ADC2R_AD2EEV10      0x00000200	/* ADC Trigger 2 on external event 10 */
  #define HRTIM_ADC2R_AD2TAC2       0x00000400	/* ADC Trigger 2 on Timer A compare 2 */
  #define HRTIM_ADC2R_AD2TAC3       0x00000800	/* ADC Trigger 2 on Timer A compare 3 */
  #define HRTIM_ADC2R_AD2TAC4       0x00001000	/* ADC Trigger 2 on Timer A compare 4*/
  #define HRTIM_ADC2R_AD2TAPER      0x00002000	/* ADC Trigger 2 on Timer A period */
  #define HRTIM_ADC2R_AD2TBC2       0x00004000	/* ADC Trigger 2 on Timer B compare 2 */
  #define HRTIM_ADC2R_AD2TBC3       0x00008000	/* ADC Trigger 2 on Timer B compare 3 */
  #define HRTIM_ADC2R_AD2TBC4       0x00010000	/* ADC Trigger 2 on Timer B compare 4 */
  #define HRTIM_ADC2R_AD2TBPER      0x00020000	/* ADC Trigger 2 on Timer B period */
  #define HRTIM_ADC2R_AD2TCC2       0x00040000	/* ADC Trigger 2 on Timer C compare 2 */
  #define HRTIM_ADC2R_AD2TCC3       0x00080000	/* ADC Trigger 2 on Timer C compare 3 */
  #define HRTIM_ADC2R_AD2TCC4       0x00100000	/* ADC Trigger 2 on Timer C compare 4 */
  #define HRTIM_ADC2R_AD2TCPER      0x00200000	/* ADC Trigger 2 on Timer C period */
  #define HRTIM_ADC2R_AD2TCRST      0x00400000	/* ADC Trigger 2 on Timer C reset */
  #define HRTIM_ADC2R_AD2TDC2       0x00800000	/* ADC Trigger 2 on Timer D compare 2 */
  #define HRTIM_ADC2R_AD2TDC3       0x01000000	/* ADC Trigger 2 on Timer D compare 3 */
  #define HRTIM_ADC2R_AD2TDC4       0x02000000	/* ADC Trigger 2 on Timer D compare 4*/
  #define HRTIM_ADC2R_AD2TDPER      0x04000000	/* ADC Trigger 2 on Timer D period */
  #define HRTIM_ADC2R_AD2TDRST      0x08000000	/* ADC Trigger 2 on Timer D reset */
  #define HRTIM_ADC2R_AD2TEC2       0x10000000	/* ADC Trigger 2 on Timer E compare 2 */
  #define HRTIM_ADC2R_AD2TEC3       0x20000000	/* ADC Trigger 2 on Timer E compare 3 */
  #define HRTIM_ADC2R_AD2TEC4       0x40000000	/* ADC Trigger 2 on Timer E compare 4 */
  #define HRTIM_ADC2R_AD2TERST      0x80000000	/* ADC Trigger 2 on Timer E reset */
#define TOFF_HRTIM_ADC3R    0x03C4		/* (RW) HRTIM ADC Trigger 3 register */
  #define HRTIM_ADC3R_AD3MC1        0x00000001	/* ADC Trigger 3 on master compare 1 */
  #define HRTIM_ADC3R_AD3MC2        0x00000002	/* ADC Trigger 3 on master compare 2 */
  #define HRTIM_ADC3R_AD3MC3        0x00000004	/* ADC Trigger 3 on master compare 3 */
  #define HRTIM_ADC3R_AD3MC4        0x00000008	/* ADC Trigger 3 on master compare 4 */
  #define HRTIM_ADC3R_AD3MPER       0x00000010	/* ADC Trigger 3 on master period */
  #define HRTIM_ADC3R_AD3EEV1       0x00000020	/* ADC Trigger 3 on external event 1 */
  #define HRTIM_ADC3R_AD3EEV2       0x00000040	/* ADC Trigger 3 on external event 2 */
  #define HRTIM_ADC3R_AD3EEV3       0x00000080	/* ADC Trigger 3 on external event 3 */
  #define HRTIM_ADC3R_AD3EEV4       0x00000100	/* ADC Trigger 3 on external event 4 */
  #define HRTIM_ADC3R_AD3EEV5       0x00000200	/* ADC Trigger 3 on external event 5 */
  #define HRTIM_ADC3R_AD3TAC2       0x00000400	/* ADC Trigger 3 on Timer A compare 2 */
  #define HRTIM_ADC3R_AD3TAC3       0x00000800	/* ADC Trigger 3 on Timer A compare 3 */
  #define HRTIM_ADC3R_AD3TAC4       0x00001000	/* ADC Trigger 3 on Timer A compare 4 */
  #define HRTIM_ADC3R_AD3TAPER      0x00002000	/* ADC Trigger 3 on Timer A period */
  #define HRTIM_ADC3R_AD3TARST      0x00004000	/* ADC Trigger 3 on Timer A reset */
  #define HRTIM_ADC3R_AD3TBC2       0x00008000	/* ADC Trigger 3 on Timer B compare 2 */
  #define HRTIM_ADC3R_AD3TBC3       0x00010000	/* ADC Trigger 3 on Timer B compare 3 */
  #define HRTIM_ADC3R_AD3TBC4       0x00020000	/* ADC Trigger 3 on Timer B compare 4 */
  #define HRTIM_ADC3R_AD3TBPER      0x00040000	/* ADC Trigger 3 on Timer B period */
  #define HRTIM_ADC3R_AD3TBRST      0x00080000	/* ADC Trigger 3 on Timer B reset */
  #define HRTIM_ADC3R_AD3TCC2       0x00100000	/* ADC Trigger 3 on Timer C compare 2 */
  #define HRTIM_ADC3R_AD3TCC3       0x00200000	/* ADC Trigger 3 on Timer C compare 3 */
  #define HRTIM_ADC3R_AD3TCC4       0x00400000	/* ADC Trigger 3 on Timer C compare 4 */
  #define HRTIM_ADC3R_AD3TCPER      0x00800000	/* ADC Trigger 3 on Timer C period */
  #define HRTIM_ADC3R_AD3TDC2       0x01000000	/* ADC Trigger 3 on Timer D compare 2 */
  #define HRTIM_ADC3R_AD3TDC3       0x02000000	/* ADC Trigger 3 on Timer D compare 3 */
  #define HRTIM_ADC3R_AD3TDC4       0x04000000	/* ADC Trigger 3 on Timer D compare 4 */
  #define HRTIM_ADC3R_AD3TDPER      0x08000000	/* ADC Trigger 3 on Timer D period */
  #define HRTIM_ADC3R_AD3TEC2       0x10000000	/* ADC Trigger 3 on Timer E compare 2 */
  #define HRTIM_ADC3R_AD3TEC3       0x20000000	/* ADC Trigger 3 on Timer E compare 3 */
  #define HRTIM_ADC3R_AD3TEC4       0x40000000	/* ADC Trigger 3 on Timer E compare 4 */
  #define HRTIM_ADC3R_AD3TEPER      0x80000000	/* ADC Trigger 3 on Timer E period */
#define TOFF_HRTIM_ADC4R    0x03C8		/* (RW) HRTIM ADC Trigger 4 register */
  #define HRTIM_ADC4R_AD4MC1        0x00000001	/* ADC Trigger 4 on master compare 1 */
  #define HRTIM_ADC4R_AD4MC2        0x00000002	/* ADC Trigger 4 on master compare 2 */
  #define HRTIM_ADC4R_AD4MC3        0x00000004	/* ADC Trigger 4 on master compare 3 */
  #define HRTIM_ADC4R_AD4MC4        0x00000008	/* ADC Trigger 4 on master compare 4 */
  #define HRTIM_ADC4R_AD4MPER       0x00000010	/* ADC Trigger 4 on master period */
  #define HRTIM_ADC4R_AD4EEV6       0x00000020	/* ADC Trigger 4 on external event 6 */
  #define HRTIM_ADC4R_AD4EEV7       0x00000040	/* ADC Trigger 4 on external event 7 */
  #define HRTIM_ADC4R_AD4EEV8       0x00000080	/* ADC Trigger 4 on external event 8 */
  #define HRTIM_ADC4R_AD4EEV9       0x00000100	/* ADC Trigger 4 on external event 9 */
  #define HRTIM_ADC4R_AD4EEV10      0x00000200	/* ADC Trigger 4 on external event 10 */
  #define HRTIM_ADC4R_AD4TAC2       0x00000400	/* ADC Trigger 4 on Timer A compare 2 */
  #define HRTIM_ADC4R_AD4TAC3       0x00000800	/* ADC Trigger 4 on Timer A compare 3 */
  #define HRTIM_ADC4R_AD4TAC4       0x00001000	/* ADC Trigger 4 on Timer A compare 4*/
  #define HRTIM_ADC4R_AD4TAPER      0x00002000	/* ADC Trigger 4 on Timer A period */
  #define HRTIM_ADC4R_AD4TBC2       0x00004000	/* ADC Trigger 4 on Timer B compare 2 */
  #define HRTIM_ADC4R_AD4TBC3       0x00008000	/* ADC Trigger 4 on Timer B compare 3 */
  #define HRTIM_ADC4R_AD4TBC4       0x00010000	/* ADC Trigger 4 on Timer B compare 4 */
  #define HRTIM_ADC4R_AD4TBPER      0x00020000	/* ADC Trigger 4 on Timer B period */
  #define HRTIM_ADC4R_AD4TCC2       0x00040000	/* ADC Trigger 4 on Timer C compare 2 */
  #define HRTIM_ADC4R_AD4TCC3       0x00080000	/* ADC Trigger 4 on Timer C compare 3 */
  #define HRTIM_ADC4R_AD4TCC4       0x00100000	/* ADC Trigger 4 on Timer C compare 4 */
  #define HRTIM_ADC4R_AD4TCPER      0x00200000	/* ADC Trigger 4 on Timer C period */
  #define HRTIM_ADC4R_AD4TCRST      0x00400000	/* ADC Trigger 4 on Timer C reset */
  #define HRTIM_ADC4R_AD4TDC2       0x00800000	/* ADC Trigger 4 on Timer D compare 2 */
  #define HRTIM_ADC4R_AD4TDC3       0x01000000	/* ADC Trigger 4 on Timer D compare 3 */
  #define HRTIM_ADC4R_AD4TDC4       0x02000000	/* ADC Trigger 4 on Timer D compare 4*/
  #define HRTIM_ADC4R_AD4TDPER      0x04000000	/* ADC Trigger 4 on Timer D period */
  #define HRTIM_ADC4R_AD4TDRST      0x08000000	/* ADC Trigger 4 on Timer D reset */
  #define HRTIM_ADC4R_AD4TEC2       0x10000000	/* ADC Trigger 4 on Timer E compare 2 */
  #define HRTIM_ADC4R_AD4TEC3       0x20000000	/* ADC Trigger 4 on Timer E compare 3 */
  #define HRTIM_ADC4R_AD4TEC4       0x40000000	/* ADC Trigger 4 on Timer E compare 4 */
  #define HRTIM_ADC4R_AD4TERST      0x80000000	/* ADC Trigger 4 on Timer E reset */
#define TOFF_HRTIM_FLTINR1  0x03D0		/* (RW) HRTIM Fault input register1 */
  #define HRTIM_FLTINR1_FLT1E       0x00000001	/* Fault 1 enable */
  #define HRTIM_FLTINR1_FLT1P       0x00000002	/* Fault 1 polarity */
  #define HRTIM_FLTINR1_FLT1SRC     0x00000004	/* Fault 1 source */
  #define HRTIM_FLTINR1_FLT1F       0x00000078	/* Fault 1 filter */
  #define HRTIM_FLTINR1_FLT1F_0     0x00000008
  #define HRTIM_FLTINR1_FLT1F_1     0x00000010
  #define HRTIM_FLTINR1_FLT1F_2     0x00000020
  #define HRTIM_FLTINR1_FLT1F_3     0x00000040
  #define HRTIM_FLTINR1_FLT1LCK     0x00000080	/* Fault 1 lock */
  #define HRTIM_FLTINR1_FLT2E       0x00000100	/* Fault 2 enable */
  #define HRTIM_FLTINR1_FLT2P       0x00000200	/* Fault 2 polarity */
  #define HRTIM_FLTINR1_FLT2SRC     0x00000400	/* Fault 2 source */
  #define HRTIM_FLTINR1_FLT2F       0x00007800	/* Fault 2 filter */
  #define HRTIM_FLTINR1_FLT2F_0     0x00000800
  #define HRTIM_FLTINR1_FLT2F_1     0x00001000
  #define HRTIM_FLTINR1_FLT2F_2     0x00002000
  #define HRTIM_FLTINR1_FLT2F_3     0x00004000
  #define HRTIM_FLTINR1_FLT2LCK     0x00008000	/* Fault 2 lock */
  #define HRTIM_FLTINR1_FLT3E       0x00010000	/* Fault 3 enable */
  #define HRTIM_FLTINR1_FLT3P       0x00020000	/* Fault 3 polarity */
  #define HRTIM_FLTINR1_FLT3SRC     0x00040000	/* Fault 3 source */
  #define HRTIM_FLTINR1_FLT3F       0x00780000	/* Fault 3 filter */
  #define HRTIM_FLTINR1_FLT3F_0     0x00080000
  #define HRTIM_FLTINR1_FLT3F_1     0x00100000
  #define HRTIM_FLTINR1_FLT3F_2     0x00200000
  #define HRTIM_FLTINR1_FLT3F_3     0x00400000
  #define HRTIM_FLTINR1_FLT3LCK     0x00800000	/* Fault 3 lock */
  #define HRTIM_FLTINR1_FLT4E       0x01000000	/* Fault 4 enable */
  #define HRTIM_FLTINR1_FLT4P       0x02000000	/* Fault 4 polarity */
  #define HRTIM_FLTINR1_FLT4SRC     0x04000000	/* Fault 4 source */
  #define HRTIM_FLTINR1_FLT4F       0x78000000	/* Fault 4 filter */
  #define HRTIM_FLTINR1_FLT4F_0     0x08000000
  #define HRTIM_FLTINR1_FLT4F_1     0x10000000
  #define HRTIM_FLTINR1_FLT4F_2     0x20000000
  #define HRTIM_FLTINR1_FLT4F_3     0x40000000
  #define HRTIM_FLTINR1_FLT4LCK     0x80000000	/* Fault 4 lock */
#define TOFF_HRTIM_FLTINR2  0x03D4		/* (RW) HRTIM Fault input register2 */
  #define HRTIM_FLTINR2_FLT5E       0x00000001	/* Fault 5 enable */
  #define HRTIM_FLTINR2_FLT5P       0x00000002	/* Fault 5 polarity */
  #define HRTIM_FLTINR2_FLT5SRC     0x00000004	/* Fault 5 source */
  #define HRTIM_FLTINR2_FLT5F       0x00000078	/* Fault 5 filter */
  #define HRTIM_FLTINR2_FLT5F_0     0x00000008
  #define HRTIM_FLTINR2_FLT5F_1     0x00000010
  #define HRTIM_FLTINR2_FLT5F_2     0x00000020
  #define HRTIM_FLTINR2_FLT5F_3     0x00000040
  #define HRTIM_FLTINR2_FLT5LCK     0x00000080	/* Fault 5 lock */
  #define HRTIM_FLTINR2_FLTSD       0x03000000	/* Fault sampling clock division */
  #define HRTIM_FLTINR2_FLTSD_0     0x01000000
  #define HRTIM_FLTINR2_FLTSD_1     0x02000000
#define TOFF_HRTIM_BDMUPR   0x03D8		/* (RW) HRTIM Burst DMA Master Timer update register */
  #define HRTIM_BDMUPR_MCR          0x00000001	/* MCR register update enable */
  #define HRTIM_BDMUPR_MICR         0x00000002	/* MICR register update enable */
  #define HRTIM_BDMUPR_MDIER        0x00000004	/* MDIER register update enable */
  #define HRTIM_BDMUPR_MCNT         0x00000008	/* MCNT register update enable */
  #define HRTIM_BDMUPR_MPER         0x00000010	/* MPER register update enable */
  #define HRTIM_BDMUPR_MREP         0x00000020	/* MREP register update enable */
  #define HRTIM_BDMUPR_MCMP1        0x00000040	/* MCMP1 register update enable */
  #define HRTIM_BDMUPR_MCMP2        0x00000080	/* MCMP2 register update enable */
  #define HRTIM_BDMUPR_MCMP3        0x00000100	/* MCMP3 register update enable */
  #define HRTIM_BDMUPR_MCMP4        0x00000200	/* MPCMP4 register update enable */
#define TOFF_HRTIM_BDTAUPR  0x03DC		/* (RW) HRTIM Burst DMA Timerx update register */
  #define HRTIM_BDTUPR_TIMCR        0x00000001	/* TIMCR register update enable */
  #define HRTIM_BDTUPR_TIMICR       0x00000002	/* TIMICR register update enable */
  #define HRTIM_BDTUPR_TIMDIER      0x00000004	/* TIMDIER register update enable */
  #define HRTIM_BDTUPR_TIMCNT       0x00000008	/* TIMCNT register update enable */
  #define HRTIM_BDTUPR_TIMPER       0x00000010	/* TIMPER register update enable */
  #define HRTIM_BDTUPR_TIMREP       0x00000020	/* TIMREP register update enable */
  #define HRTIM_BDTUPR_TIMCMP1      0x00000040	/* TIMCMP1 register update enable */
  #define HRTIM_BDTUPR_TIMCMP2      0x00000080	/* TIMCMP2 register update enable */
  #define HRTIM_BDTUPR_TIMCMP3      0x00000100	/* TIMCMP3 register update enable */
  #define HRTIM_BDTUPR_TIMCMP4      0x00000200	/* TIMCMP4 register update enable */
  #define HRTIM_BDTUPR_TIMDTR       0x00000400	/* TIMDTR register update enable */
  #define HRTIM_BDTUPR_TIMSET1R     0x00000800	/* TIMSET1R register update enable */
  #define HRTIM_BDTUPR_TIMRST1R     0x00001000	/* TIMRST1R register update enable */
  #define HRTIM_BDTUPR_TIMSET2R     0x00002000	/* TIMSET2R register update enable */
  #define HRTIM_BDTUPR_TIMRST2R     0x00004000	/* TIMRST2R register update enable */
  #define HRTIM_BDTUPR_TIMEEFR1     0x00008000	/* TIMEEFR1 register update enable */
  #define HRTIM_BDTUPR_TIMEEFR2     0x00010000	/* TIMEEFR2 register update enable */
  #define HRTIM_BDTUPR_TIMRSTR      0x00020000	/* TIMRSTR register update enable */
  #define HRTIM_BDTUPR_TIMCHPR      0x00040000	/* TIMCHPR register update enable */
  #define HRTIM_BDTUPR_TIMOUTR      0x00080000	/* TIMOUTR register update enable */
  #define HRTIM_BDTUPR_TIMFLTR      0x00100000	/* TIMFLTR register update enable */
#define TOFF_HRTIM_BDTBUPR  0x03E0		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDTCUPR  0x03E4		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDTDUPR  0x03E8		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDTEUPR  0x03EC		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDMADR   0x03F0		/* (RW) HRTIM Burst DMA Master Data register */

#define TADR_HRTIM1_TIMA_BASE (TADR_HRTIM1_BASE + 0x00000080)
#define TADR_HRTIM1_TIMB_BASE (TADR_HRTIM1_BASE + 0x00000100)
#define TADR_HRTIM1_TIMC_BASE (TADR_HRTIM1_BASE + 0x00000180)
#define TADR_HRTIM1_TIMD_BASE (TADR_HRTIM1_BASE + 0x00000200)
#define TADR_HRTIM1_TIME_BASE (TADR_HRTIM1_BASE + 0x00000280)


/*
 *  HRTIM Timer A to E
 */
#define TOFF_HRTIM_TIMCR    0x0000		/* (RW) HRTIM Timerx control register */
  #define HRTIM_TIMCR_CK_PSC    0x00000007	/* Slave prescaler mask*/
  #define HRTIM_TIMCR_CK_PSC_0  0x00000001
  #define HRTIM_TIMCR_CK_PSC_1  0x00000002
  #define HRTIM_TIMCR_CK_PSC_2  0x00000004
  #define HRTIM_TIMCR_CONT      0x00000008	/* Slave continuous mode */
  #define HRTIM_TIMCR_RETRIG    0x00000010	/* Slave Retrigreable mode */
  #define HRTIM_TIMCR_HALF      0x00000020	/* Slave Half mode */
  #define HRTIM_TIMCR_PSHPLL    0x00000040	/* Slave push-pull mode */
  #define HRTIM_TIMCR_SYNCRST   0x00000400	/* Slave synchronization resets */
  #define HRTIM_TIMCR_SYNCSTRT  0x00000800	/* Slave synchronization starts */
  #define HRTIM_TIMCR_DELCMP2   0x00003000	/* Slave delayed compartor 2 mode mask */
  #define HRTIM_TIMCR_DELCMP2_0 0x00001000
  #define HRTIM_TIMCR_DELCMP2_1 0x00002000
  #define HRTIM_TIMCR_DELCMP4   0x0000C000	/* Slave delayed compartor 4 mode mask */
  #define HRTIM_TIMCR_DELCMP4_0 0x00004000
  #define HRTIM_TIMCR_DELCMP4_1 0x00008000
  #define HRTIM_TIMCR_TREPU     0x00020000	/* Slave repetition update */
  #define HRTIM_TIMCR_TRSTU     0x00040000	/* Slave reset update */
  #define HRTIM_TIMCR_TAU       0x00080000	/* Slave Timer A update reserved for TIM A */
  #define HRTIM_TIMCR_TBU       0x00100000	/* Slave Timer B update reserved for TIM B */
  #define HRTIM_TIMCR_TCU       0x00200000	/* Slave Timer C update reserved for TIM C */
  #define HRTIM_TIMCR_TDU       0x00400000	/* Slave Timer D update reserved for TIM D */
  #define HRTIM_TIMCR_TEU       0x00800000	/* Slave Timer E update reserved for TIM E */
  #define HRTIM_TIMCR_MSTU      0x01000000	/* Master Update */
  #define HRTIM_TIMCR_DACSYNC   0x06000000	/* DAC sychronization mask */
  #define HRTIM_TIMCR_DACSYNC_0 0x02000000
  #define HRTIM_TIMCR_DACSYNC_1 0x04000000
  #define HRTIM_TIMCR_PREEN     0x08000000	/* Slave preload enable */
  #define HRTIM_TIMCR_UPDGAT    0xF0000000	/* Slave update gating mask */
  #define HRTIM_TIMCR_UPDGAT_0  0x10000000
  #define HRTIM_TIMCR_UPDGAT_1  0x20000000
  #define HRTIM_TIMCR_UPDGAT_2  0x40000000
  #define HRTIM_TIMCR_UPDGAT_3  0x80000000
#define TOFF_HRTIM_TIMISR   0x0004		/* (RW) HRTIM Timerx interrupt status register */
  #define HRTIM_TIMISR_CMP1     0x00000001	/* Slave compare 1 interrupt flag */
  #define HRTIM_TIMISR_CMP2     0x00000002	/* Slave compare 2 interrupt flag */
  #define HRTIM_TIMISR_CMP3     0x00000004	/* Slave compare 3 interrupt flag */
  #define HRTIM_TIMISR_CMP4     0x00000008	/* Slave compare 4 interrupt flag */
  #define HRTIM_TIMISR_REP      0x00000010	/* Slave repetition interrupt flag */
  #define HRTIM_TIMISR_UPD      0x00000040	/* Slave update interrupt flag */
  #define HRTIM_TIMISR_CPT1     0x00000080	/* Slave capture 1 interrupt flag */
  #define HRTIM_TIMISR_CPT2     0x00000100	/* Slave capture 2 interrupt flag */
  #define HRTIM_TIMISR_SET1     0x00000200	/* Slave output 1 set interrupt flag */
  #define HRTIM_TIMISR_RST1     0x00000400	/* Slave output 1 reset interrupt flag */
  #define HRTIM_TIMISR_SET2     0x00000800	/* Slave output 2 set interrupt flag */
  #define HRTIM_TIMISR_RST2     0x00001000	/* Slave output 2 reset interrupt flag */
  #define HRTIM_TIMISR_RST      0x00002000	/* Slave reset interrupt flag */
  #define HRTIM_TIMISR_DLYPRT   0x00004000	/* Slave output 1 delay protection interrupt flag */
  #define HRTIM_TIMISR_CPPSTAT  0x00010000	/* Slave current push-pull flag */
  #define HRTIM_TIMISR_IPPSTAT  0x00020000	/* Slave idle push-pull flag */
  #define HRTIM_TIMISR_O1STAT   0x00040000	/* Slave output 1 state flag */
  #define HRTIM_TIMISR_O2STAT   0x00080000	/* Slave output 2 state flag */
  #define HRTIM_TIMISR_O1CPY    0x00100000	/* Slave output 1 copy flag */
  #define HRTIM_TIMISR_O2CPY    0x00200000	/* Slave output 2 copy flag */
#define TOFF_HRTIM_TIMICR   0x0008		/* (RW) HRTIM Timerx interrupt clear register */
  #define HRTIM_TIMICR_CMP1C    0x00000001	/* Slave compare 1 clear flag */
  #define HRTIM_TIMICR_CMP2C    0x00000002	/* Slave compare 2 clear flag */
  #define HRTIM_TIMICR_CMP3C    0x00000004	/* Slave compare 3 clear flag */
  #define HRTIM_TIMICR_CMP4C    0x00000008	/* Slave compare 4 clear flag */
  #define HRTIM_TIMICR_REPC     0x00000010	/* Slave repetition clear flag */
  #define HRTIM_TIMICR_UPDC     0x00000040	/* Slave update clear flag */
  #define HRTIM_TIMICR_CPT1C    0x00000080	/* Slave capture 1 clear flag */
  #define HRTIM_TIMICR_CPT2C    0x00000100	/* Slave capture 2 clear flag */
  #define HRTIM_TIMICR_SET1C    0x00000200	/* Slave output 1 set clear flag */
  #define HRTIM_TIMICR_RST1C    0x00000400	/* Slave output 1 reset clear flag */
  #define HRTIM_TIMICR_SET2C    0x00000800	/* Slave output 2 set clear flag */
  #define HRTIM_TIMICR_RST2C    0x00001000	/* Slave output 2 reset clear flag */
  #define HRTIM_TIMICR_RSTC     0x00002000	/* Slave reset clear flag */
  #define HRTIM_TIMICR_DLYPRTC  0x00004000	/* Slave output 1 delay protection clear flag */
#define TOFF_HRTIM_TIMDIER  0x000C		/* (RW) HRTIM Timerx DMA/interrupt enable register */
  #define HRTIM_TIMDIER_CMP1IE  0x00000001	/* Slave compare 1 interrupt enable */
  #define HRTIM_TIMDIER_CMP2IE  0x00000002	/* Slave compare 2 interrupt enable */
  #define HRTIM_TIMDIER_CMP3IE  0x00000004	/* Slave compare 3 interrupt enable */
  #define HRTIM_TIMDIER_CMP4IE  0x00000008	/* Slave compare 4 interrupt enable */
  #define HRTIM_TIMDIER_REPIE   0x00000010	/* Slave repetition interrupt enable */
  #define HRTIM_TIMDIER_UPDIE   0x00000040	/* Slave update interrupt enable */
  #define HRTIM_TIMDIER_CPT1IE  0x00000080	/* Slave capture 1 interrupt enable */
  #define HRTIM_TIMDIER_CPT2IE  0x00000100	/* Slave capture 2 interrupt enable */
  #define HRTIM_TIMDIER_SET1IE  0x00000200	/* Slave output 1 set interrupt enable */
  #define HRTIM_TIMDIER_RST1IE  0x00000400	/* Slave output 1 reset interrupt enable */
  #define HRTIM_TIMDIER_SET2IE  0x00000800	/* Slave output 2 set interrupt enable */
  #define HRTIM_TIMDIER_RST2IE  0x00001000	/* Slave output 2 reset interrupt enable */
  #define HRTIM_TIMDIER_RSTIE   0x00002000	/* Slave reset interrupt enable */
  #define HRTIM_TIMDIER_DLYPRTIE 0x00004000	/* Slave delay protection interrupt enable */
  #define HRTIM_TIMDIER_CMP1DE  0x00010000	/* Slave compare 1 request enable */
  #define HRTIM_TIMDIER_CMP2DE  0x00020000	/* Slave compare 2 request enable */
  #define HRTIM_TIMDIER_CMP3DE  0x00040000	/* Slave compare 3 request enable */
  #define HRTIM_TIMDIER_CMP4DE  0x00080000	/* Slave compare 4 request enable */
  #define HRTIM_TIMDIER_REPDE   0x00100000	/* Slave repetition request enable */
  #define HRTIM_TIMDIER_UPDDE   0x00400000	/* Slave update request enable */
  #define HRTIM_TIMDIER_CPT1DE  0x00800000	/* Slave capture 1 request enable */
  #define HRTIM_TIMDIER_CPT2DE  0x01000000	/* Slave capture 2 request enable */
  #define HRTIM_TIMDIER_SET1DE  0x02000000	/* Slave output 1 set request enable */
  #define HRTIM_TIMDIER_RST1DE  0x04000000	/* Slave output 1 reset request enable */
  #define HRTIM_TIMDIER_SET2DE  0x08000000	/* Slave output 2 set request enable */
  #define HRTIM_TIMDIER_RST2DE  0x10000000	/* Slave output 2 reset request enable */
  #define HRTIM_TIMDIER_RSTDE   0x20000000	/* Slave reset request enable */
  #define HRTIM_TIMDIER_DLYPRTDE 0x40000000	/* Slavedelay protection request enable */
#define TOFF_HRTIM_CNTR     0x0010		/* (RW) HRTIM Timerx counter register */
#define TOFF_HRTIM_PERR     0x0014		/* (RW) HRTIM Timerx period register */
#define TOFF_HRTIM_REPR     0x0018		/* (RW) HRTIM Timerx repetition register */
#define TOFF_HRTIM_CMP1R    0x001C		/* (RW) HRTIM Timerx compare 1 register */
#define TOFF_HRTIM_CMP1CR   0x0020		/* (RW) HRTIM Timerx compare 1 compound register */
#define TOFF_HRTIM_CMP2R    0x0024		/* (RW) HRTIM Timerx compare 2 register */
#define TOFF_HRTIM_CMP3R    0x0028		/* (RW) HRTIM Timerx compare 3 register */
#define TOFF_HRTIM_CMP4R    0x002C		/* (RW) HRTIM Timerx compare 4 register */
#define TOFF_HRTIM_CPT1R    0x0030		/* (RW) HRTIM Timerx capture 1 register */
#define TOFF_HRTIM_CPT2R    0x0034		/* (RW) HRTIM Timerx capture 2 register */
#define TOFF_HRTIM_DTR      0x0038		/* (RW) HRTIM Timerx dead time register */
  #define HRTIM_DTR_DTR         0x000001FF	/* Dead time rising value */
  #define HRTIM_DTR_DTR_0       0x00000001
  #define HRTIM_DTR_DTR_1       0x00000002
  #define HRTIM_DTR_DTR_2       0x00000004
  #define HRTIM_DTR_DTR_3       0x00000008
  #define HRTIM_DTR_DTR_4       0x00000010
  #define HRTIM_DTR_DTR_5       0x00000020
  #define HRTIM_DTR_DTR_6       0x00000040
  #define HRTIM_DTR_DTR_7       0x00000080
  #define HRTIM_DTR_DTR_8       0x00000100
  #define HRTIM_DTR_SDTR        0x00000200	/* Sign dead time rising value */
  #define HRTIM_DTR_DTPRSC      0x00001C00	/* Dead time prescaler */
  #define HRTIM_DTR_DTPRSC_0    0x00000400
  #define HRTIM_DTR_DTPRSC_1    0x00000800
  #define HRTIM_DTR_DTPRSC_2    0x00001000
  #define HRTIM_DTR_DTRSLK      0x00004000	/* Dead time rising sign lock */
  #define HRTIM_DTR_DTRLK       0x00008000	/* Dead time rising lock */
  #define HRTIM_DTR_DTF         0x01FF0000	/* Dead time falling value */
  #define HRTIM_DTR_DTF_0       0x00010000
  #define HRTIM_DTR_DTF_1       0x00020000
  #define HRTIM_DTR_DTF_2       0x00040000
  #define HRTIM_DTR_DTF_3       0x00080000
  #define HRTIM_DTR_DTF_4       0x00100000
  #define HRTIM_DTR_DTF_5       0x00200000
  #define HRTIM_DTR_DTF_6       0x00400000
  #define HRTIM_DTR_DTF_7       0x00800000
  #define HRTIM_DTR_DTF_8       0x01000000
  #define HRTIM_DTR_SDTF        0x02000000	/* Sign dead time falling value */
  #define HRTIM_DTR_DTFSLK      0x40000000	/* Dead time falling sign lock */
  #define HRTIM_DTR_DTFLK       0x80000000
#define TOFF_HRTIM_SET1R    0x003C		/* (RW) HRTIM Timerx output 1 set register */
  #define HRTIM_SET1R_SST       0x00000001	/* software set trigger */
  #define HRTIM_SET1R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_SET1R_PER       0x00000004	/* Timer A period */
  #define HRTIM_SET1R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_SET1R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_SET1R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_SET1R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_SET1R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_SET1R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_SET1R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_SET1R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_SET1R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_SET1R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_SET1R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_SET1R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_SET1R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_SET1R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_SET1R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_SET1R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_SET1R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_SET1R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_SET1R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_SET1R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_SET1R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_SET1R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_SET1R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_SET1R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_SET1R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_SET1R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_SET1R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_SET1R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_SET1R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_RST1R    0x0040		/* (RW) HRTIM Timerx output 1 reset register */
  #define HRTIM_RST1R_SRT       0x00000001	/* software reset trigger */
  #define HRTIM_RST1R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_RST1R_PER       0x00000004	/* Timer A period */
  #define HRTIM_RST1R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_RST1R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_RST1R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_RST1R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_RST1R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_RST1R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_RST1R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_RST1R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_RST1R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_RST1R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_RST1R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_RST1R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_RST1R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_RST1R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_RST1R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_RST1R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_RST1R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_RST1R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_RST1R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_RST1R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_RST1R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_RST1R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_RST1R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_RST1R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_RST1R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_RST1R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_RST1R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_RST1R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_RST1R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_SET2R    0x0044		/* (RW) HRTIM Timerx output 2 set register */
  #define HRTIM_SET2R_SST       0x00000001	/* software set trigger */
  #define HRTIM_SET2R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_SET2R_PER       0x00000004	/* Timer A period */
  #define HRTIM_SET2R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_SET2R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_SET2R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_SET2R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_SET2R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_SET2R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_SET2R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_SET2R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_SET2R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_SET2R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_SET2R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_SET2R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_SET2R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_SET2R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_SET2R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_SET2R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_SET2R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_SET2R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_SET2R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_SET2R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_SET2R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_SET2R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_SET2R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_SET2R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_SET2R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_SET2R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_SET2R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_SET2R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_SET2R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_RST2R    0x0048		/* (RW) HRTIM Timerx output 2 reset register */
  #define HRTIM_RST2R_SRT       0x00000001	/* software reset trigger */
  #define HRTIM_RST2R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_RST2R_PER       0x00000004	/* Timer A period */
  #define HRTIM_RST2R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_RST2R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_RST2R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_RST2R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_RST2R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_RST2R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_RST2R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_RST2R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_RST2R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_RST2R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_RST2R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_RST2R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_RST2R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_RST2R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_RST2R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_RST2R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_RST2R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_RST2R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_RST2R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_RST2R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_RST2R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_RST2R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_RST2R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_RST2R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_RST2R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_RST2R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_RST2R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_RST2R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_RST2R_UPDATE    0x80000000/* Register update (transfer preload to active) */
#define TOFF_HRTIM_EEFxR1   0x004C		/* (RW) HRTIM Timerx external event filtering 1 register */
  #define HRTIM_EEFR1_EE1LTCH   0x00000001	/* External Event 1 latch */
  #define HRTIM_EEFR1_EE1FLTR   0x0000001E	/* External Event 1 filter mask */
  #define HRTIM_EEFR1_EE1FLTR_0 0x00000002
  #define HRTIM_EEFR1_EE1FLTR_1 0x00000004
  #define HRTIM_EEFR1_EE1FLTR_2 0x00000008
  #define HRTIM_EEFR1_EE1FLTR_3 0x00000010
  #define HRTIM_EEFR1_EE2LTCH   0x00000040	/* External Event 2 latch */
  #define HRTIM_EEFR1_EE2FLTR   0x00000780	/* External Event 2 filter mask */
  #define HRTIM_EEFR1_EE2FLTR_0 0x00000080
  #define HRTIM_EEFR1_EE2FLTR_1 0x00000100
  #define HRTIM_EEFR1_EE2FLTR_2 0x00000200
  #define HRTIM_EEFR1_EE2FLTR_3 0x00000400
  #define HRTIM_EEFR1_EE3LTCH   0x00001000	/* External Event 3 latch */
  #define HRTIM_EEFR1_EE3FLTR   0x0001E000	/* External Event 3 filter mask */
  #define HRTIM_EEFR1_EE3FLTR_0 0x00002000
  #define HRTIM_EEFR1_EE3FLTR_1 0x00004000
  #define HRTIM_EEFR1_EE3FLTR_2 0x00008000
  #define HRTIM_EEFR1_EE3FLTR_3 0x00010000
  #define HRTIM_EEFR1_EE4LTCH   0x00040000	/* External Event 4 latch */
  #define HRTIM_EEFR1_EE4FLTR   0x00780000	/* External Event 4 filter mask */
  #define HRTIM_EEFR1_EE4FLTR_0 0x00080000
  #define HRTIM_EEFR1_EE4FLTR_1 0x00100000
  #define HRTIM_EEFR1_EE4FLTR_2 0x00200000
  #define HRTIM_EEFR1_EE4FLTR_3 0x00400000
  #define HRTIM_EEFR1_EE5LTCH   0x01000000	/* External Event 5 latch */
  #define HRTIM_EEFR1_EE5FLTR   0x1E000000	/* External Event 5 filter mask */
  #define HRTIM_EEFR1_EE5FLTR_0 0x02000000
  #define HRTIM_EEFR1_EE5FLTR_1 0x04000000
  #define HRTIM_EEFR1_EE5FLTR_2 0x08000000
  #define HRTIM_EEFR1_EE5FLTR_3 0x10000000
#define TOFF_HRTIM_EEFxR2   0x0050		/* (RW) HRTIM Timerx external event filtering 2 register */
  #define HRTIM_EEFR2_EE6LTCH   0x00000001	/* External Event 6 latch */
  #define HRTIM_EEFR2_EE6FLTR   0x0000001E	/* External Event 6 filter mask */
  #define HRTIM_EEFR2_EE6FLTR_0 0x00000002
  #define HRTIM_EEFR2_EE6FLTR_1 0x00000004
  #define HRTIM_EEFR2_EE6FLTR_2 0x00000008
  #define HRTIM_EEFR2_EE6FLTR_3 0x00000010
  #define HRTIM_EEFR2_EE7LTCH   0x00000040	/* External Event 7 latch */
  #define HRTIM_EEFR2_EE7FLTR   0x00000780	/* External Event 7 filter mask */
  #define HRTIM_EEFR2_EE7FLTR_0 0x00000080
  #define HRTIM_EEFR2_EE7FLTR_1 0x00000100
  #define HRTIM_EEFR2_EE7FLTR_2 0x00000200
  #define HRTIM_EEFR2_EE7FLTR_3 0x00000400
  #define HRTIM_EEFR2_EE8LTCH   0x00001000	/* External Event 8 latch */
  #define HRTIM_EEFR2_EE8FLTR   0x0001E000	/* External Event 8 filter mask */
  #define HRTIM_EEFR2_EE8FLTR_0 0x00002000
  #define HRTIM_EEFR2_EE8FLTR_1 0x00004000
  #define HRTIM_EEFR2_EE8FLTR_2 0x00008000
  #define HRTIM_EEFR2_EE8FLTR_3 0x00010000
  #define HRTIM_EEFR2_EE9LTCH   0x00040000	/* External Event 9 latch */
  #define HRTIM_EEFR2_EE9FLTR   0x00780000	/* External Event 9 filter mask */
  #define HRTIM_EEFR2_EE9FLTR_0 0x00080000
  #define HRTIM_EEFR2_EE9FLTR_1 0x00100000
  #define HRTIM_EEFR2_EE9FLTR_2 0x00200000
  #define HRTIM_EEFR2_EE9FLTR_3 0x00400000
  #define HRTIM_EEFR2_EE10LTCH  0x01000000	/* External Event 10 latch */
  #define HRTIM_EEFR2_EE10FLTR  0x1E000000	/* External Event 10 filter mask */
  #define HRTIM_EEFR2_EE10FLTR_0 0x02000000
  #define HRTIM_EEFR2_EE10FLTR_1 0x04000000
  #define HRTIM_EEFR2_EE10FLTR_2 0x08000000
  #define HRTIM_EEFR2_EE10FLTR_3 0x10000000
#define TOFF_HRTIM_RSTxR    0x0054		/* (RW) HRTIM Timerx Reset register */
  #define HRTIM_RSTR_UPDATE     0x00000002	/* Timer update */
  #define HRTIM_RSTR_CMP2       0x00000004	/* Timer compare2 */
  #define HRTIM_RSTR_CMP4       0x00000008	/* Timer compare4 */
  #define HRTIM_RSTR_MSTPER     0x00000010	/* Master period */
  #define HRTIM_RSTR_MSTCMP1    0x00000020	/* Master compare1 */
  #define HRTIM_RSTR_MSTCMP2    0x00000040	/* Master compare2 */
  #define HRTIM_RSTR_MSTCMP3    0x00000080	/* Master compare3 */
  #define HRTIM_RSTR_MSTCMP4    0x00000100	/* Master compare4 */
  #define HRTIM_RSTR_EXTEVNT1   0x00000200	/* External event 1 */
  #define HRTIM_RSTR_EXTEVNT2   0x00000400	/* External event 2 */
  #define HRTIM_RSTR_EXTEVNT3   0x00000800	/* External event 3 */
  #define HRTIM_RSTR_EXTEVNT4   0x00001000	/* External event 4 */
  #define HRTIM_RSTR_EXTEVNT5   0x00002000	/* External event 5 */
  #define HRTIM_RSTR_EXTEVNT6   0x00004000	/* External event 6 */
  #define HRTIM_RSTR_EXTEVNT7   0x00008000	/* External event 7 */
  #define HRTIM_RSTR_EXTEVNT8   0x00010000	/* External event 8 */
  #define HRTIM_RSTR_EXTEVNT9   0x00020000	/* External event 9 */
  #define HRTIM_RSTR_EXTEVNT10  0x00040000	/* External event 10 */
  #define HRTIM_RSTR_TIMBCMP1   0x00080000	/* Timer B compare 1 */
  #define HRTIM_RSTR_TIMBCMP2   0x00100000	/* Timer B compare 2 */
  #define HRTIM_RSTR_TIMBCMP4   0x00200000	/* Timer B compare 4 */
  #define HRTIM_RSTR_TIMCCMP1   0x00400000	/* Timer C compare 1 */
  #define HRTIM_RSTR_TIMCCMP2   0x00800000	/* Timer C compare 2 */
  #define HRTIM_RSTR_TIMCCMP4   0x01000000	/* Timer C compare 4 */
  #define HRTIM_RSTR_TIMDCMP1   0x02000000	/* Timer D compare 1 */
  #define HRTIM_RSTR_TIMDCMP2   0x04000000	/* Timer D compare 2 */
  #define HRTIM_RSTR_TIMDCMP4   0x08000000	/* Timer D compare 4 */
  #define HRTIM_RSTR_TIMECMP1   0x10000000	/* Timer E compare 1 */
  #define HRTIM_RSTR_TIMECMP2   0x20000000	/* Timer E compare 2 */
  #define HRTIM_RSTR_TIMECMP4   0x40000000	/* Timer E compare 4 */
#define TOFF_HRTIM_CHPxR    0x0058		/* (RW) HRTIM Timerx Chopper register */
  #define HRTIM_CHPR_CARFRQ     0x0000000F	/* Timer carrier frequency value */
  #define HRTIM_CHPR_CARFRQ_0   0x00000001
  #define HRTIM_CHPR_CARFRQ_1   0x00000002
  #define HRTIM_CHPR_CARFRQ_2   0x00000004
  #define HRTIM_CHPR_CARFRQ_3   0x00000008
  #define HRTIM_CHPR_CARDTY     0x00000070	/* Timer chopper duty cycle value */
  #define HRTIM_CHPR_CARDTY_0   0x00000010
  #define HRTIM_CHPR_CARDTY_1   0x00000020
  #define HRTIM_CHPR_CARDTY_2   0x00000040
  #define HRTIM_CHPR_STRPW      0x00000780	/* Timer start pulse width value */
  #define HRTIM_CHPR_STRPW_0    0x00000080
  #define HRTIM_CHPR_STRPW_1    0x00000100
  #define HRTIM_CHPR_STRPW_2    0x00000200
  #define HRTIM_CHPR_STRPW_3    0x00000400
#define TOFF_HRTIM_CPT1xCR  0x005C		/* (RW) HRTIM Timerx Capture 1 register */
  #define HRTIM_CPT1CR_SWCPT    0x00000001	/* Software capture */
  #define HRTIM_CPT1CR_UPDCPT   0x00000002	/* Update capture */
  #define HRTIM_CPT1CR_EXEV1CPT 0x00000004	/* External event 1 capture */
  #define HRTIM_CPT1CR_EXEV2CPT 0x00000008	/* External event 2 capture */
  #define HRTIM_CPT1CR_EXEV3CPT 0x00000010	/* External event 3 capture */
  #define HRTIM_CPT1CR_EXEV4CPT 0x00000020	/* External event 4 capture */
  #define HRTIM_CPT1CR_EXEV5CPT 0x00000040	/* External event 5 capture */
  #define HRTIM_CPT1CR_EXEV6CPT 0x00000080	/* External event 6 capture */
  #define HRTIM_CPT1CR_EXEV7CPT 0x00000100	/* External event 7 capture */
  #define HRTIM_CPT1CR_EXEV8CPT 0x00000200	/* External event 8 capture */
  #define HRTIM_CPT1CR_EXEV9CPT 0x00000400	/* External event 9 capture */
  #define HRTIM_CPT1CR_EXEV10CPT 0x00000800	/* External event 10 capture */
  #define HRTIM_CPT1CR_TA1SET   0x00001000	/* Timer A output 1 set */
  #define HRTIM_CPT1CR_TA1RST   0x00002000	/* Timer A output 1 reset */
  #define HRTIM_CPT1CR_TIMACMP1 0x00004000	/* Timer A compare 1 */
  #define HRTIM_CPT1CR_TIMACMP2 0x00008000	/* Timer A compare 2 */
  #define HRTIM_CPT1CR_TB1SET   0x00010000	/* Timer B output 1 set */
  #define HRTIM_CPT1CR_TB1RST   0x00020000	/* Timer B output 1 reset */
  #define HRTIM_CPT1CR_TIMBCMP1 0x00040000	/* Timer B compare 1 */
  #define HRTIM_CPT1CR_TIMBCMP2 0x00080000	/* Timer B compare 2 */
  #define HRTIM_CPT1CR_TC1SET   0x00100000	/* Timer C output 1 set */
  #define HRTIM_CPT1CR_TC1RST   0x00200000	/* Timer C output 1 reset */
  #define HRTIM_CPT1CR_TIMCCMP1 0x00400000	/* Timer C compare 1 */
  #define HRTIM_CPT1CR_TIMCCMP2 0x00800000	/* Timer C compare 2 */
  #define HRTIM_CPT1CR_TD1SET   0x01000000	/* Timer D output 1 set */
  #define HRTIM_CPT1CR_TD1RST   0x02000000	/* Timer D output 1 reset */
  #define HRTIM_CPT1CR_TIMDCMP1 0x04000000	/* Timer D compare 1 */
  #define HRTIM_CPT1CR_TIMDCMP2 0x08000000	/* Timer D compare 2 */
  #define HRTIM_CPT1CR_TE1SET   0x10000000	/* Timer E output 1 set */
  #define HRTIM_CPT1CR_TE1RST   0x20000000	/* Timer E output 1 reset */
  #define HRTIM_CPT1CR_TIMECMP1 0x40000000	/* Timer E compare 1 */
  #define HRTIM_CPT1CR_TIMECMP2 0x80000000	/* Timer E compare 2 */
#define TOFF_HRTIM_CPT2xCR  0x0060		/* (RW) HRTIM Timerx Capture 2 register */
  #define HRTIM_CPT2CR_SWCPT    0x00000001	/* Software capture */
  #define HRTIM_CPT2CR_UPDCPT   0x00000002	/* Update capture */
  #define HRTIM_CPT2CR_EXEV1CPT 0x00000004	/* External event 1 capture */
  #define HRTIM_CPT2CR_EXEV2CPT 0x00000008	/* External event 2 capture */
  #define HRTIM_CPT2CR_EXEV3CPT 0x00000010	/* External event 3 capture */
  #define HRTIM_CPT2CR_EXEV4CPT 0x00000020	/* External event 4 capture */
  #define HRTIM_CPT2CR_EXEV5CPT 0x00000040	/* External event 5 capture */
  #define HRTIM_CPT2CR_EXEV6CPT 0x00000080	/* External event 6 capture */
  #define HRTIM_CPT2CR_EXEV7CPT 0x00000100	/* External event 7 capture */
  #define HRTIM_CPT2CR_EXEV8CPT 0x00000200	/* External event 8 capture */
  #define HRTIM_CPT2CR_EXEV9CPT 0x00000400	/* External event 9 capture */
  #define HRTIM_CPT2CR_EXEV10CPT 0x00000800	/* External event 10 capture */
  #define HRTIM_CPT2CR_TA1SET   0x00001000	/* Timer A output 1 set */
  #define HRTIM_CPT2CR_TA1RST   0x00002000	/* Timer A output 1 reset */
  #define HRTIM_CPT2CR_TIMACMP1 0x00004000	/* Timer A compare 1 */
  #define HRTIM_CPT2CR_TIMACMP2 0x00008000	/* Timer A compare 2 */
  #define HRTIM_CPT2CR_TB1SET   0x00010000	/* Timer B output 1 set */
  #define HRTIM_CPT2CR_TB1RST   0x00020000	/* Timer B output 1 reset */
  #define HRTIM_CPT2CR_TIMBCMP1 0x00040000	/* Timer B compare 1 */
  #define HRTIM_CPT2CR_TIMBCMP2 0x00080000	/* Timer B compare 2 */
  #define HRTIM_CPT2CR_TC1SET   0x00100000	/* Timer C output 1 set */
  #define HRTIM_CPT2CR_TC1RST   0x00200000	/* Timer C output 1 reset */
  #define HRTIM_CPT2CR_TIMCCMP1 0x00400000	/* Timer C compare 1 */
  #define HRTIM_CPT2CR_TIMCCMP2 0x00800000	/* Timer C compare 2 */
  #define HRTIM_CPT2CR_TD1SET   0x01000000	/* Timer D output 1 set */
  #define HRTIM_CPT2CR_TD1RST   0x02000000	/* Timer D output 1 reset */
  #define HRTIM_CPT2CR_TIMDCMP1 0x04000000	/* Timer D compare 1 */
  #define HRTIM_CPT2CR_TIMDCMP2 0x08000000	/* Timer D compare 2 */
  #define HRTIM_CPT2CR_TE1SET   0x10000000	/* Timer E output 1 set */
  #define HRTIM_CPT2CR_TE1RST   0x20000000	/* Timer E output 1 reset */
  #define HRTIM_CPT2CR_TIMECMP1 0x40000000	/* Timer E compare 1 */
  #define HRTIM_CPT2CR_TIMECMP2 0x80000000	/* Timer E compare 2 */
#define TOFF_HRTIM_OUTxR    0x0064		/* (RW) HRTIM Timerx Output register */
  #define HRTIM_OUTR_POL1       0x00000002	/* Slave output 1 polarity */
  #define HRTIM_OUTR_IDLM1      0x00000004	/* Slave output 1 idle mode */
  #define HRTIM_OUTR_IDLES1     0x00000008	/* Slave output 1 idle state */
  #define HRTIM_OUTR_FAULT1     0x00000030	/* Slave output 1 fault state */
  #define HRTIM_OUTR_FAULT1_0   0x00000010
  #define HRTIM_OUTR_FAULT1_1   0x00000020
  #define HRTIM_OUTR_CHP1       0x00000040	/* Slave output 1 chopper enable */
  #define HRTIM_OUTR_DIDL1      0x00000080	/* Slave output 1 dead time idle */
  #define HRTIM_OUTR_DTEN       0x00000100	/* Slave output deadtime enable */
  #define HRTIM_OUTR_DLYPRTEN   0x00000200	/* Slave output delay protection enable */
  #define HRTIM_OUTR_DLYPRT     0x00001C00	/* Slave output delay protection */
  #define HRTIM_OUTR_DLYPRT_0   0x00000400
  #define HRTIM_OUTR_DLYPRT_1   0x00000800
  #define HRTIM_OUTR_DLYPRT_2   0x00001000
  #define HRTIM_OUTR_POL2       0x00020000	/* Slave output 2 polarity */
  #define HRTIM_OUTR_IDLM2      0x00040000	/* Slave output 2 idle mode */
  #define HRTIM_OUTR_IDLES2     0x00080000	/* Slave output 2 idle state */
  #define HRTIM_OUTR_FAULT2     0x00300000	/* Slave output 2 fault state */
  #define HRTIM_OUTR_FAULT2_0   0x00100000
  #define HRTIM_OUTR_FAULT2_1   0x00200000
  #define HRTIM_OUTR_CHP2       0x00400000	/* Slave output 2 chopper enable */
  #define HRTIM_OUTR_DIDL2      0x00800000	/* Slave output 2 dead time idle */
#define TOFF_HRTIM_FLTxR    0x0068		/* (RW) HRTIM Timerx Fault register */
  #define HRTIM_FLTR_FLT1EN     0x00000001	/* Fault 1 enable */
  #define HRTIM_FLTR_FLT2EN     0x00000002	/* Fault 2 enable */
  #define HRTIM_FLTR_FLT3EN     0x00000004	/* Fault 3 enable */
  #define HRTIM_FLTR_FLT4EN     0x00000008	/* Fault 4 enable */
  #define HRTIM_FLTR_FLT5EN     0x00000010	/* Fault 5 enable */
  #define HRTIM_FLTR_FLTLCK     0x80000000	/* Fault sources lock */


/*
 *  CLOCK Recovery SYSTEM
 */
#define TADR_CRS_BASE       (D2_APB1PERIPH_BASE + 0x8400)
#define TOFF_CRS_CR         0x0000		/* (RW) CRS ccontrol register */
  #define CRS_CR_SYNCOKIE    0x00000001	/* SYNC event OK interrupt enable */
  #define CRS_CR_SYNCWARNIE  0x00000002	/* SYNC warning interrupt enable */
  #define CRS_CR_ERRIE       0x00000004	/* SYNC error or trimming error interrupt enable */
  #define CRS_CR_ESYNCIE     0x00000008	/* Expected SYNC interrupt enable */
  #define CRS_CR_CEN         0x00000020	/* Frequency error counter enable */
  #define CRS_CR_AUTOTRIMEN  0x00000040	/* Automatic trimming enable */
  #define CRS_CR_SWSYNC      0x00000080	/* Generate software SYNC event */
  #define CRS_CR_TRIM        0x00003F00	/* HSI48 oscillator smooth trimming */
#define TOFF_CRS_CFGR       0x0004		/* (RW) CRS configuration register */
  #define CRS_CFGR_RELOAD    0x0000FFFF	/* Counter reload value */
  #define CRS_CFGR_FELIM     0x00FF0000	/* Frequency error limit */
  #define CRS_CFGR_SYNCDIV   0x07000000	/* SYNC divider */
  #define CRS_CFGR_SYNCDIV_0 0x01000000
  #define CRS_CFGR_SYNCDIV_1 0x02000000
  #define CRS_CFGR_SYNCDIV_2 0x04000000
  #define CRS_CFGR_SYNCSRC   0x30000000	/* SYNC signal source selection */
  #define CRS_CFGR_SYNCSRC_0 0x10000000
  #define CRS_CFGR_SYNCSRC_1 0x20000000
  #define CRS_CFGR_SYNCPOL   0x80000000	/* SYNC polarity selection */
#define TOFF_CRS_ISR        0x0008		/* (RW) CRS interrupt and status register */
  #define CRS_ISR_SYNCOKF    0x00000001	/* SYNC event OK flag */
  #define CRS_ISR_SYNCWARNF  0x00000002	/* SYNC warning flag */
  #define CRS_ISR_ERRF       0x00000004	/* Error flag */
  #define CRS_ISR_ESYNCF     0x00000008	/* Expected SYNC flag */
  #define CRS_ISR_SYNCERR    0x00000100	/* SYNC error */
  #define CRS_ISR_SYNCMISS   0x00000200	/* SYNC missed */
  #define CRS_ISR_TRIMOVF    0x00000400	/* Trimming overflow or underflow */
  #define CRS_ISR_FEDIR      0x00008000	/* Frequency error direction */
  #define CRS_ISR_FECAP      0xFFFF0000	/* Frequency error capture */
#define TOFF_CRS_ICR        0x000C		/* (RW) CRS interrupt flag clear register */
  #define CRS_ICR_SYNCOKC    0x00000001	/* SYNC event OK clear flag */
  #define CRS_ICR_SYNCWARNC  0x00000002	/* SYNC warning clear flag */
  #define CRS_ICR_ERRC       0x00000004	/* Error clear flag */
  #define CRS_ICR_ESYNCC     0x00000008	/* Expected SYNC clear flag */


/*
 *  SINGLE WIRE PROTOCOL Master Interface SPWMI
 */
#define TADR_SWPMI1_BASE    (D2_APB1PERIPH_BASE + 0x8800)
#define TOFF_SWPMI_CR       0x0000		/* (RW) SWPMI Configuration/Control register */
  #define SWPMI_CR_RXDMA     0x00000001	/* Reception DMA enable  */
  #define SWPMI_CR_TXDMA     0x00000002	/* Transmission DMA enable */
  #define SWPMI_CR_RXMODE    0x00000004	/* Reception buffering mode */
  #define SWPMI_CR_TXMODE    0x00000008	/* Transmission buffering mode */
  #define SWPMI_CR_LPBK      0x00000010	/* Loopback mode enable */
  #define SWPMI_CR_SWPACT    0x00000020	/* Single wire protocol master interface activate */
  #define SWPMI_CR_DEACT     0x00000400	/* Single wire protocol master interface deactivate */
  #define SWPMI_CR_SWPEN     0x00000800	/* Single wire protocol master transceiver enable */
#define TOFF_SWPMI_BRR      0x0004		/* (RW) SWPMI bitrate register */
#define TOFF_SWPMI_ISR      0x000C		/* (RW) SWPMI Interrupt and Status register */
  #define SWPMI_ISR_RXBFF    0x00000001	/* Receive buffer full flag */
  #define SWPMI_ISR_TXBEF    0x00000002	/* Transmit buffer empty flag */
  #define SWPMI_ISR_RXBERF   0x00000004	/* Receive CRC error flag */
  #define SWPMI_ISR_RXOVRF   0x00000008	/* Receive overrun error flag */
  #define SWPMI_ISR_TXUNRF   0x00000010	/* Transmit underrun error flag */
  #define SWPMI_ISR_RXNE     0x00000020	/* Receive data register not empty */
  #define SWPMI_ISR_TXE      0x00000040	/* Transmit data register empty */
  #define SWPMI_ISR_TCF      0x00000080	/* Transfer complete flag */
  #define SWPMI_ISR_SRF      0x00000100	/* Slave resume flag */
  #define SWPMI_ISR_SUSP     0x00000200	/* SUSPEND flag */
  #define SWPMI_ISR_DEACTF   0x00000400	/* DEACTIVATED flag */
  #define SWPMI_ISR_RDYF     0x00000800	/* Transceiver ready flag */
#define TOFF_SWPMI_ICR      0x0010		/* (RW) SWPMI Interrupt Flag Clear register */
  #define SWPMI_ICR_CRXBFF   0x00000001	/* Clear receive buffer full flag */
  #define SWPMI_ICR_CTXBEF   0x00000002	/* Clear transmit buffer empty flag */
  #define SWPMI_ICR_CRXBERF  0x00000004	/* Clear receive CRC error flag */
  #define SWPMI_ICR_CRXOVRF  0x00000008	/* Clear receive overrun error flag */
  #define SWPMI_ICR_CTXUNRF  0x00000010	/* Clear transmit underrun error flag */
  #define SWPMI_ICR_CTCF     0x00000080	/* Clear transfer complete flag */
  #define SWPMI_ICR_CSRF     0x00000100	/* Clear slave resume flag */
  #define SWPMI_ICR_CRDYF    0x00000800	/* Clear transceiver ready flag */
#define TOFF_SWPMI_IER      0x0014		/* (RW) SWPMI Interrupt Enable register */
  #define SWPMI_IER_RXBFIE   0x00000001	/* Receive buffer full interrupt enable */
  #define SWPMI_IER_TXBEIE   0x00000002	/* Transmit buffer empty interrupt enable */
  #define SWPMI_IER_RXBERIE  0x00000004	/* Receive CRC error interrupt enable */
  #define SWPMI_IER_RXOVRIE  0x00000008	/* Receive overrun error interrupt enable */
  #define SWPMI_IER_TXUNRIE  0x00000010	/* Transmit underrun error interrupt enable */
  #define SWPMI_IER_RIE      0x00000020	/* Receive interrupt enable */
  #define SWPMI_IER_TIE      0x00000040	/* Transmit interrupt enable */
  #define SWPMI_IER_TCIE     0x00000080	/* Transmit complete interrupt enable */
  #define SWPMI_IER_SRIE     0x00000100	/* Slave resume interrupt enable */
  #define SWPMI_IER_RDYIE    0x00000800	/* Transceiver ready interrupt enable */
#define TOFF_SWPMI_RFL      0x0018		/* (RW) SWPMI Receive Frame Length register */
  #define SWPMI_RFL_RFL      0x0000001F	/* RFL[4:0] bits (Receive Frame length) */
  #define SWPMI_RFL_RFL_0_1  0x00000003	/* RFL[1:0] bits (number of relevant bytes for the last SWPMI_RDR register read.) */
#define TOFF_SWPMI_TDR      0x001C		/* (RW) SWPMI Transmit data register */
#define TOFF_SWPMI_RDR      0x0020		/* (RW) SWPMI Receive data register */
#define TOFF_SWPMI_OR       0x0024		/* (RW) SWPMI Option register */
  #define SWPMI_OR_TBYP      0x00000001	/* SWP Transceiver Bypass */
  #define SWPMI_OR_CLASS     0x00000002	/* SWP CLASS selection */


/*
 *  OPERATION Amplifier (OPAMP)
 */
#define TADR_OPAMP_BASE     (D2_APB1PERIPH_BASE + 0x9000)
#define TADR_OPAMP1_BASE    (D2_APB1PERIPH_BASE + 0x9000)
#define TADR_OPAMP2_BASE    (D2_APB1PERIPH_BASE + 0x9010)
#define TOFF_OPAMP_CSR      0x0000		/* (RW) OPAMP control/status register */
  #define OPAMP_CSR_OPAMPxEN 0x00000001	/* OPAMP enable */
  #define OPAMP_CSR_FORCEVP  0x00000002	/* Force internal reference on VP */
  #define OPAMP_CSR_VPSEL    0x0000000C	/* Non inverted input selection */
  #define OPAMP_CSR_VPSEL_0  0x00000004
  #define OPAMP_CSR_VPSEL_1  0x00000008
  #define OPAMP_CSR_VMSEL    0x00000060	/* Inverting input selection */
  #define OPAMP_CSR_VMSEL_0  0x00000020
  #define OPAMP_CSR_VMSEL_1  0x00000040
  #define OPAMP_CSR_OPAHSM   0x00000100	/* Operational amplifier high speed mode */
  #define OPAMP_CSR_CALON    0x00000800	/* Calibration mode enable */
  #define OPAMP_CSR_CALSEL   0x00003000	/* Calibration selection */
  #define OPAMP_CSR_CALSEL_0 0x00001000
  #define OPAMP_CSR_CALSEL_1 0x00002000
  #define OPAMP_CSR_PGGAIN   0x0003C000	/* Operational amplifier Programmable amplifier gain value */
  #define OPAMP_CSR_PGGAIN_0 0x00004000
  #define OPAMP_CSR_PGGAIN_1 0x00008000
  #define OPAMP_CSR_PGGAIN_2 0x00010000
  #define OPAMP_CSR_PGGAIN_3 0x00020000
  #define OPAMP_CSR_USERTRIM 0x00040000	/* User trimming enable */
  #define OPAMP_CSR_TSTREF   0x20000000	/* OpAmp calibration reference voltage output control */
  #define OPAMP_CSR_CALOUT   0x40000000	/* Operational amplifier calibration output */

  #define OPAMP1_CSR_OPAEN   0x00000001	/* Operational amplifier1 Enable */
  #define OPAMP1_CSR_FORCEVP 0x00000002	/* Force internal reference on VP */
  #define OPAMP1_CSR_VPSEL   0x0000000C	/* Non inverted input selection */
  #define OPAMP1_CSR_VPSEL_0 0x00000004
  #define OPAMP1_CSR_VPSEL_1 0x00000008
  #define OPAMP1_CSR_VMSEL   0x00000060	/* Inverting input selection */
  #define OPAMP1_CSR_VMSEL_0 0x00000020
  #define OPAMP1_CSR_VMSEL_1 0x00000040
  #define OPAMP1_CSR_OPAHSM  0x00000100	/* Operational amplifier1 high speed mode */
  #define OPAMP1_CSR_CALON   0x00000800	/* Calibration mode enable */
  #define OPAMP1_CSR_CALSEL  0x00003000	/* Calibration selection */
  #define OPAMP1_CSR_CALSEL_0  0x00001000
  #define OPAMP1_CSR_CALSEL_1  0x00002000
  #define OPAMP1_CSR_PGGAIN  0x0003C000	/* Operational amplifier1 Programmable amplifier gain value */
  #define OPAMP1_CSR_PGGAIN_0  0x00004000
  #define OPAMP1_CSR_PGGAIN_1  0x00008000
  #define OPAMP1_CSR_PGGAIN_2  0x00010000
  #define OPAMP1_CSR_PGGAIN_3  0x00020000
  #define OPAMP1_CSR_USERTRIM  0x00040000	/* User trimming enable */
  #define OPAMP1_CSR_TSTREF  0x20000000	/* OpAmp calibration reference voltage output control */
  #define OPAMP1_CSR_CALOUT  0x40000000	/* Operational amplifier1 calibration output */

  #define OPAMP2_CSR_OPAEN   0x00000001	/* Operational amplifier2 Enable */
  #define OPAMP2_CSR_FORCEVP 0x00000002	/* Force internal reference on VP */
  #define OPAMP2_CSR_VPSEL   0x0000000C	/* Non inverted input selection */
  #define OPAMP2_CSR_VPSEL_0 0x00000004
  #define OPAMP2_CSR_VPSEL_1 0x00000008
  #define OPAMP2_CSR_VMSEL   0x00000060	/* Inverting input selection */
  #define OPAMP2_CSR_VMSEL_0 0x00000020
  #define OPAMP2_CSR_VMSEL_1 0x00000040
  #define OPAMP2_CSR_OPAHSM  0x00000100	/* Operational amplifier2 high speed mode */
  #define OPAMP2_CSR_CALON   0x00000800	/* Calibration mode enable */
  #define OPAMP2_CSR_CALSEL  0x00003000	/* Calibration selection */
  #define OPAMP2_CSR_CALSEL_0  0x00001000
  #define OPAMP2_CSR_CALSEL_1  0x00002000
  #define OPAMP2_CSR_PGGAIN  0x0003C000	/* Operational amplifier2 Programmable amplifier gain value */
  #define OPAMP2_CSR_PGGAIN_0  0x00004000
  #define OPAMP2_CSR_PGGAIN_1  0x00008000
  #define OPAMP2_CSR_PGGAIN_2  0x00010000
  #define OPAMP2_CSR_PGGAIN_3  0x00020000
  #define OPAMP2_CSR_USERTRIM  0x00040000	/* User trimming enable */
  #define OPAMP2_CSR_TSTREF  0x20000000	/* OpAmp calibration reference voltage output control */
  #define OPAMP2_CSR_CALOUT  0x40000000	/* Operational amplifier2 calibration output */
#define TOFF_OPAMP_OTR      0x0004		/* (RW) OPAMP offset trimming register for normal mode */
  #define OPAMP_OTR_TRIMOFFSETN      0x0000001F	/* Trim for NMOS differential pairs */
  #define OPAMP_OTR_TRIMOFFSETP      0x00001F00	/* Trim for PMOS differential pairs */
  #define OPAMP1_OTR_TRIMOFFSETN     0x0000001F	/* Trim for NMOS differential pairs */
  #define OPAMP1_OTR_TRIMOFFSETP     0x00001F00	/* Trim for PMOS differential pairs */
  #define OPAMP2_OTR_TRIMOFFSETN     0x0000001F	/* Trim for NMOS differential pairs */
  #define OPAMP2_OTR_TRIMOFFSETP     0x00001F00	/* Trim for PMOS differential pairs */
#define TOFF_OPAMP_HSOTR    0x0008		/* (RW) OPAMP offset trimming register for high speed mode */
  #define OPAMP_HSOTR_TRIMHSOFFSETN  0x0000001F	/* Trim for NMOS differential pairs */
  #define OPAMP_HSOTR_TRIMHSOFFSETP  0x00001F00	/* Trim for PMOS differential pairs */
  #define OPAMP1_HSOTR_TRIMHSOFFSETN 0x0000001F	/* Trim for NMOS differential pairs */
  #define OPAMP1_HSOTR_TRIMHSOFFSETP 0x00001F00	/* Trim for PMOS differential pairs */
  #define OPAMP2_HSOTR_TRIMHSOFFSETN 0x0000001F	/* Trim for NMOS differential pairs */
  #define OPAMP2_HSOTR_TRIMHSOFFSETP 0x00001F00	/* Trim for PMOS differential pairs */


/*
 *  MDIOS
 */
#define TADR_MDIOS_BASE     (D2_APB1PERIPH_BASE + 0x9400)
#define TOFF_MDIOS_CR       0x0000
  #define MDIOS_CR_EN        0x00000001	/* MDIOS slave peripheral enable */
  #define MDIOS_CR_WRIE      0x00000002	/* MDIOS slave register write interrupt enable. */
  #define MDIOS_CR_RDIE      0x00000004	/* MDIOS slave register read interrupt enable. */
  #define MDIOS_CR_EIE       0x00000008	/* MDIOS slave register error interrupt enable. */
  #define MDIOS_CR_DPC       0x00000080	/* MDIOS slave disable preamble check. */
  #define MDIOS_CR_PORT_ADDRESS    0x00001F00	/*  MDIOS slave port address mask. */
  #define MDIOS_CR_PORT_ADDRESS_0  0x00000100
  #define MDIOS_CR_PORT_ADDRESS_1  0x00000200
  #define MDIOS_CR_PORT_ADDRESS_2  0x00000400
  #define MDIOS_CR_PORT_ADDRESS_3  0x00000800
  #define MDIOS_CR_PORT_ADDRESS_4  0x00001000
#define TOFF_MDIOS_WRFR     0x0004
#define TOFF_MDIOS_CWRFR    0x0008
#define TOFF_MDIOS_RDFR     0x000C
#define TOFF_MDIOS_CRDFR    0x0010
#define TOFF_MDIOS_SR       0x0014
  #define MDIOS_SR_PERF      0x00000001	/* MDIOS slave turnaround error flag*/
  #define MDIOS_SR_SERF      0x00000002	/* MDIOS slave start error flag */
  #define MDIOS_SR_TERF      0x00000004	/* MDIOS slave preamble error flag */
#define TOFF_MDIOS_CLRFR    0x0018
  #define MDIOS_CLRFR_CPERF  0x00000001	/* MDIOS slave Clear the turnaround error flag */
  #define MDIOS_CLRFR_CSERF  0x00000002	/* MDIOS slave Clear the start error flag */
  #define MDIOS_CLRFR_CTERF  0x00000004	/* MDIOS slave Clear the preamble error flag */
#define TOFF_MDIOS_DINR0    0x0100
#define TOFF_MDIOS_DINR1    0x0104
#define TOFF_MDIOS_DINR2    0x0108
#define TOFF_MDIOS_DINR3    0x010C
#define TOFF_MDIOS_DINR4    0x0110
#define TOFF_MDIOS_DINR5    0x0114
#define TOFF_MDIOS_DINR6    0x0118
#define TOFF_MDIOS_DINR7    0x011C
#define TOFF_MDIOS_DINR8    0x0120
#define TOFF_MDIOS_DINR9    0x0124
#define TOFF_MDIOS_DINR10   0x0128
#define TOFF_MDIOS_DINR11   0x012C
#define TOFF_MDIOS_DINR12   0x0130
#define TOFF_MDIOS_DINR13   0x0134
#define TOFF_MDIOS_DINR14   0x0138
#define TOFF_MDIOS_DINR15   0x013C
#define TOFF_MDIOS_DINR16   0x0140
#define TOFF_MDIOS_DINR17   0x0144
#define TOFF_MDIOS_DINR18   0x0148
#define TOFF_MDIOS_DINR19   0x014C
#define TOFF_MDIOS_DINR20   0x0150
#define TOFF_MDIOS_DINR21   0x0154
#define TOFF_MDIOS_DINR22   0x0158
#define TOFF_MDIOS_DINR23   0x015C
#define TOFF_MDIOS_DINR24   0x0160
#define TOFF_MDIOS_DINR25   0x0164
#define TOFF_MDIOS_DINR26   0x0168
#define TOFF_MDIOS_DINR27   0x016C
#define TOFF_MDIOS_DINR28   0x0170
#define TOFF_MDIOS_DINR29   0x0174
#define TOFF_MDIOS_DINR30   0x0178
#define TOFF_MDIOS_DINR31   0x017C
#define TOFF_MDIOS_DOUTR0   0x0180
#define TOFF_MDIOS_DOUTR1   0x0184
#define TOFF_MDIOS_DOUTR2   0x0188
#define TOFF_MDIOS_DOUTR3   0x018C
#define TOFF_MDIOS_DOUTR4   0x0190
#define TOFF_MDIOS_DOUTR5   0x0194
#define TOFF_MDIOS_DOUTR6   0x0198
#define TOFF_MDIOS_DOUTR7   0x019C
#define TOFF_MDIOS_DOUTR8   0x01A0
#define TOFF_MDIOS_DOUTR9   0x01A4
#define TOFF_MDIOS_DOUTR10  0x01A8
#define TOFF_MDIOS_DOUTR11  0x01AC
#define TOFF_MDIOS_DOUTR12  0x01B0
#define TOFF_MDIOS_DOUTR13  0x01B4
#define TOFF_MDIOS_DOUTR14  0x01B8
#define TOFF_MDIOS_DOUTR15  0x01BC
#define TOFF_MDIOS_DOUTR16  0x01C0
#define TOFF_MDIOS_DOUTR17  0x01C4
#define TOFF_MDIOS_DOUTR18  0x01C8
#define TOFF_MDIOS_DOUTR19  0x01CC
#define TOFF_MDIOS_DOUTR20  0x01D0
#define TOFF_MDIOS_DOUTR21  0x01D4
#define TOFF_MDIOS_DOUTR22  0x01D8
#define TOFF_MDIOS_DOUTR23  0x01DC
#define TOFF_MDIOS_DOUTR24  0x01E0
#define TOFF_MDIOS_DOUTR25  0x01E4
#define TOFF_MDIOS_DOUTR26  0x01E8
#define TOFF_MDIOS_DOUTR27  0x01EC
#define TOFF_MDIOS_DOUTR28  0x01F0
#define TOFF_MDIOS_DOUTR29  0x01F4
#define TOFF_MDIOS_DOUTR30  0x01F8
#define TOFF_MDIOS_DOUTR31  0x01FC


/*
 *  FD CONTROLLER AREA NETWORK
 */
#define TADR_FDCAN1_BASE    (D2_APB1PERIPH_BASE + 0xA000)
#define TADR_FDCAN2_BASE    (D2_APB1PERIPH_BASE + 0xA400)
#define TOFF_FDCAN_CREL     0x0000		/* (RW) FDCAN Core Release register */
  #define FDCAN_CREL_DAY     0x000000FF	/* Timestamp Day */
  #define FDCAN_CREL_MON     0x0000FF00	/* Timestamp Month */
  #define FDCAN_CREL_YEAR    0x000F0000	/* Timestamp Year */
  #define FDCAN_CREL_SUBSTEP 0x00F00000	/* Sub-step of Core release */
  #define FDCAN_CREL_STEP    0x0F000000	/* Step of Core release */
  #define FDCAN_CREL_REL     0xF0000000	/* Core release */
#define TOFF_FDCAN_ENDN     0x0004		/* (RW) FDCAN Endian register */
#define TOFF_FDCAN_DBTP     0x000C		/* (RW) FDCAN Data Bit Timing & Prescaler register */
  #define FDCAN_DBTP_DSJW    0x0000000F	/* Synchronization Jump Width */
  #define FDCAN_DBTP_DTSEG2  0x000000F0	/* Data time segment after sample point */
  #define FDCAN_DBTP_DTSEG1  0x00001F00	/* Data time segment before sample point */
  #define FDCAN_DBTP_DBRP    0x001F0000	/* Data BIt Rate Prescaler */
  #define FDCAN_DBTP_TDC     0x00800000	/* Transceiver Delay Compensation */
#define TOFF_FDCAN_TEST     0x0010		/* (RW) FDCAN Test register */
  #define FDCAN_TEST_LBCK    0x00000010	/* Loop Back mode */
  #define FDCAN_TEST_TX      0x00000060	/* Control of Transmit Pin */
  #define FDCAN_TEST_RX      0x00000080	/* Receive Pin */
#define TOFF_FDCAN_RWD      0x0014		/* (RW) FDCAN RAM Watchdog register */
  #define FDCAN_RWD_WDC      0x000000FF	/* Watchdog configuration */
  #define FDCAN_RWD_WDV      0x0000FF00	/* Watchdog value */
#define TOFF_FDCAN_CCCR     0x0018		/* (RW) FDCAN CC Control register */
  #define FDCAN_CCCR_INIT    0x00000001	/* Initialization */
  #define FDCAN_CCCR_CCE     0x00000002	/* Configuration Change Enable */
  #define FDCAN_CCCR_ASM     0x00000004	/* ASM Restricted Operation Mode */
  #define FDCAN_CCCR_CSA     0x00000008	/* Clock Stop Acknowledge */
  #define FDCAN_CCCR_CSR     0x00000010	/* Clock Stop Request */
  #define FDCAN_CCCR_MON     0x00000020	/* Bus Monitoring Mode */
  #define FDCAN_CCCR_DAR     0x00000040	/* Disable Automatic Retransmission */
  #define FDCAN_CCCR_TEST    0x00000080	/* Test Mode Enable */
  #define FDCAN_CCCR_FDOE    0x00000100	/* FD Operation Enable */
  #define FDCAN_CCCR_BRSE    0x00000200	/* FDCAN Bit Rate Switching */
  #define FDCAN_CCCR_PXHD    0x00001000	/* Protocol Exception Handling Disable */
  #define FDCAN_CCCR_EFBI    0x00002000	/* Edge Filtering during Bus Integration */
  #define FDCAN_CCCR_TXP     0x00004000	/* Two CAN bit times Pause */
  #define FDCAN_CCCR_NISO    0x00008000	/* Non ISO Operation */
#define TOFF_FDCAN_NBTP     0x001C		/* (RW) FDCAN Nominal Bit Timing & Prescaler register */
  #define FDCAN_NBTP_NTSEG2  0x0000007F	/* Nominal Time segment after sample point */
  #define FDCAN_NBTP_NTSEG1  0x0000FF00	/* Nominal Time segment before sample point */
  #define FDCAN_NBTP_NBRP    0x01FF0000	/* Bit Rate Prescaler */
  #define FDCAN_NBTP_NSJW    0xFE000000	/* Nominal (Re)Synchronization Jump Width */
#define TOFF_FDCAN_TSCC     0x0020		/* (RW) FDCAN Timestamp Counter Configuration register */
  #define FDCAN_TSCC_TSS     0x00000003	/* Timestamp Select */
  #define FDCAN_TSCC_TCP     0x000F0000	/* Timestamp Counter Prescaler */
#define TOFF_FDCAN_TSCV     0x0024		/* (RW) FDCAN Timestamp Counter Value register */
#define TOFF_FDCAN_TOCC     0x0028		/* (RW) FDCAN Timeout Counter Configuration register */
  #define FDCAN_TOCC_ETOC    0x00000001	/* Enable Timeout Counter */
  #define FDCAN_TOCC_TOS     0x00000006	/* Timeout Select */
  #define FDCAN_TOCC_TOP     0xFFFF0000	/* Timeout Period */
#define TOFF_FDCAN_TOCV     0x002C		/* (RW) FDCAN Timeout Counter Value register */
#define TOFF_FDCAN_ECR      0x0040		/* (RW) FDCAN Error Counter register */
  #define FDCAN_ECR_TEC      0x0000000F	/* Transmit Error Counter */
  #define FDCAN_ECR_REC      0x00007F00	/* Receive Error Counter */
  #define FDCAN_ECR_RP       0x00008000	/* Receive Error Passive */
  #define FDCAN_ECR_CEL      0x00FF0000	/* CAN Error Logging */
#define TOFF_FDCAN_PSR      0x0044		/* (RW) FDCAN Protocol Status register */
  #define FDCAN_PSR_LEC      0x00000007	/* Last Error Code */
  #define FDCAN_PSR_ACT      0x00000018	/* Activity */
  #define FDCAN_PSR_EP       0x00000020	/* Error Passive */
  #define FDCAN_PSR_EW       0x00000040	/* Warning Status */
  #define FDCAN_PSR_BO       0x00000080	/* Bus_Off Status */
  #define FDCAN_PSR_DLEC     0x00000700	/* Data Last Error Code */
  #define FDCAN_PSR_RESI     0x00000800	/* ESI flag of last received FDCAN Message */
  #define FDCAN_PSR_RBRS     0x00001000	/* BRS flag of last received FDCAN Message */
  #define FDCAN_PSR_REDL     0x00002000	/* Received FDCAN Message */
  #define FDCAN_PSR_PXE      0x00004000	/* Protocol Exception Event */
  #define FDCAN_PSR_TDCV     0x007F0000	/* Transmitter Delay Compensation Value */
#define TOFF_FDCAN_TDCR     0x0048		/* (RW) FDCAN Transmitter Delay Compensation register */
  #define FDCAN_TDCR_TDCF    0x0000007F	/* Transmitter Delay Compensation Filter */
  #define FDCAN_TDCR_TDCO    0x00007F00	/* Transmitter Delay Compensation Offset */
#define TOFF_FDCAN_IR       0x0050		/* (RW) FDCAN Interrupt register */
  #define FDCAN_IR_RF0N      0x00000001	/* Rx FIFO 0 New Message */
  #define FDCAN_IR_RF0W      0x00000002	/* Rx FIFO 0 Watermark Reached */
  #define FDCAN_IR_RF0F      0x00000004	/* Rx FIFO 0 Full */
  #define FDCAN_IR_RF0L      0x00000008	/* Rx FIFO 0 Message Lost */
  #define FDCAN_IR_RF1N      0x00000010	/* Rx FIFO 1 New Message */
  #define FDCAN_IR_RF1W      0x00000020	/* Rx FIFO 1 Watermark Reached */
  #define FDCAN_IR_RF1F      0x00000040	/* Rx FIFO 1 Full */
  #define FDCAN_IR_RF1L      0x00000080	/* Rx FIFO 1 Message Lost */
  #define FDCAN_IR_HPM       0x00000100	/* High Priority Message */
  #define FDCAN_IR_TC        0x00000200	/* Transmission Completed */
  #define FDCAN_IR_TCF       0x00000400	/* Transmission Cancellation Finished */
  #define FDCAN_IR_TFE       0x00000800	/* Tx FIFO Empty */
  #define FDCAN_IR_TEFN      0x00001000	/* Tx Event FIFO New Entry */
  #define FDCAN_IR_TEFW      0x00002000	/* Tx Event FIFO Watermark Reached */
  #define FDCAN_IR_TEFF      0x00004000	/* Tx Event FIFO Full */
  #define FDCAN_IR_TEFL      0x00008000	/* Tx Event FIFO Element Lost */
  #define FDCAN_IR_TSW       0x00010000	/* Timestamp Wraparound */
  #define FDCAN_IR_MRAF      0x00020000	/* Message RAM Access Failure */
  #define FDCAN_IR_TOO       0x00040000	/* Timeout Occurred */
  #define FDCAN_IR_DRX       0x00080000	/* Message stored to Dedicated Rx Buffer */
  #define FDCAN_IR_ELO       0x00400000	/* Error Logging Overflow */
  #define FDCAN_IR_EP        0x00800000	/* Error Passive */
  #define FDCAN_IR_EW        0x01000000	/* Warning Status */
  #define FDCAN_IR_BO        0x02000000	/* Bus_Off Status */
  #define FDCAN_IR_WDI       0x04000000	/* Watchdog Interrupt */
  #define FDCAN_IR_PEA       0x08000000	/* Protocol Error in Arbitration Phase */
  #define FDCAN_IR_PED       0x10000000	/* Protocol Error in Data Phase */
  #define FDCAN_IR_ARA       0x20000000	/* Access to Reserved Address */
#define TOFF_FDCAN_IE       0x0054		/* (RW) FDCAN Interrupt Enable register */
  #define FDCAN_IE_RF0NE     0x00000001	/* Rx FIFO 0 New Message Enable */
  #define FDCAN_IE_RF0WE     0x00000002	/* Rx FIFO 0 Watermark Reached Enable */
  #define FDCAN_IE_RF0FE     0x00000004	/* Rx FIFO 0 Full Enable */
  #define FDCAN_IE_RF0LE     0x00000008	/* Rx FIFO 0 Message Lost Enable */
  #define FDCAN_IE_RF1NE     0x00000010	/* Rx FIFO 1 New Message Enable */
  #define FDCAN_IE_RF1WE     0x00000020	/* Rx FIFO 1 Watermark Reached Enable */
  #define FDCAN_IE_RF1FE     0x00000040	/* Rx FIFO 1 Full Enable */
  #define FDCAN_IE_RF1LE     0x00000080	/* Rx FIFO 1 Message Lost Enable */
  #define FDCAN_IE_HPME      0x00000100	/* High Priority Message Enable */
  #define FDCAN_IE_TCE       0x00000200	/* Transmission Completed Enable */
  #define FDCAN_IE_TCFE      0x00000400	/* Transmission Cancellation Finished Enable */
  #define FDCAN_IE_TFEE      0x00000800	/* Tx FIFO Empty Enable */
  #define FDCAN_IE_TEFNE     0x00001000	/* Tx Event FIFO New Entry Enable */
  #define FDCAN_IE_TEFWE     0x00002000	/* Tx Event FIFO Watermark Reached Enable */
  #define FDCAN_IE_TEFFE     0x00004000	/* Tx Event FIFO Full Enable */
  #define FDCAN_IE_TEFLE     0x00008000	/* Tx Event FIFO Element Lost Enable */
  #define FDCAN_IE_TSWE      0x00010000	/* Timestamp Wraparound Enable */
  #define FDCAN_IE_MRAFE     0x00020000	/* Message RAM Access Failure Enable */
  #define FDCAN_IE_TOOE      0x00040000	/* Timeout Occurred Enable */
  #define FDCAN_IE_DRXE      0x00080000	/* Message stored to Dedicated Rx Buffer Enable */
  #define FDCAN_IE_BECE      0x00100000	/* Bit Error Corrected Interrupt Enable */
  #define FDCAN_IE_BEUE      0x00200000	/* Bit Error Uncorrected Interrupt Enable */
  #define FDCAN_IE_ELOE      0x00400000	/* Error Logging Overflow Enable */
  #define FDCAN_IE_EPE       0x00800000	/* Error Passive Enable */
  #define FDCAN_IE_EWE       0x01000000	/* Warning Status Enable */
  #define FDCAN_IE_BOE       0x02000000	/* Bus_Off Status Enable */
  #define FDCAN_IE_WDIE      0x04000000	/* Watchdog Interrupt Enable */
  #define FDCAN_IE_PEAE      0x08000000	/* Protocol Error in Arbitration Phase Enable */
  #define FDCAN_IE_PEDE      0x10000000	/* Protocol Error in Data Phase Enable */
  #define FDCAN_IE_ARAE      0x20000000	/* Access to Reserved Address Enable */
#define TOFF_FDCAN_ILS      0x0058		/* (RW) FDCAN Interrupt Line Select register */
  #define FDCAN_ILS_RF0NL    0x00000001	/* Rx FIFO 0 New Message Line */
  #define FDCAN_ILS_RF0WL    0x00000002	/* Rx FIFO 0 Watermark Reached Line */
  #define FDCAN_ILS_RF0FL    0x00000004	/* Rx FIFO 0 Full Line */
  #define FDCAN_ILS_RF0LL    0x00000008	/* Rx FIFO 0 Message Lost Line */
  #define FDCAN_ILS_RF1NL    0x00000010	/* Rx FIFO 1 New Message Line */
  #define FDCAN_ILS_RF1WL    0x00000020	/* Rx FIFO 1 Watermark Reached Line */
  #define FDCAN_ILS_RF1FL    0x00000040	/* Rx FIFO 1 Full Line */
  #define FDCAN_ILS_RF1LL    0x00000080	/* Rx FIFO 1 Message Lost Line */
  #define FDCAN_ILS_HPML     0x00000100	/* High Priority Message Line */
  #define FDCAN_ILS_TCL      0x00000200	/* Transmission Completed Line */
  #define FDCAN_ILS_TCFL     0x00000400	/* Transmission Cancellation Finished Line */
  #define FDCAN_ILS_TFEL     0x00000800	/* Tx FIFO Empty Line */
  #define FDCAN_ILS_TEFN     0x00001000	/* Tx Event FIFO New Entry Line */
  #define FDCAN_ILS_TEFWL    0x00002000	/* Tx Event FIFO Watermark Reached Line */
  #define FDCAN_ILS_TEFFL    0x00004000	/* Tx Event FIFO Full Line */
  #define FDCAN_ILS_TEFLL    0x00008000	/* Tx Event FIFO Element Lost Line */
  #define FDCAN_ILS_TSWL     0x00010000	/* Timestamp Wraparound Line */
  #define FDCAN_ILS_MRAFE    0x00020000	/* Message RAM Access Failure Line */
  #define FDCAN_ILS_TOOE     0x00040000	/* Timeout Occurred Line */
  #define FDCAN_ILS_DRXE     0x00080000	/* Message stored to Dedicated Rx Buffer Line */
  #define FDCAN_ILS_BECE     0x00100000	/* Bit Error Corrected Interrupt Line */
  #define FDCAN_ILS_BEUE     0x00200000	/* Bit Error Uncorrected Interrupt Line */
  #define FDCAN_ILS_ELOE     0x00400000	/* Error Logging Overflow Line */
  #define FDCAN_ILS_EPE      0x00800000	/* Error Passive Line */
  #define FDCAN_ILS_EWE      0x01000000	/* Warning Status Line */
  #define FDCAN_ILS_BOE      0x02000000	/* Bus_Off Status Line */
  #define FDCAN_ILS_WDIE     0x04000000	/* Watchdog Interrupt Line */
  #define FDCAN_ILS_PEAE     0x08000000	/* Protocol Error in Arbitration Phase Line */
  #define FDCAN_ILS_PEDE     0x10000000	/* Protocol Error in Data Phase Line */
  #define FDCAN_ILS_ARAE     0x20000000	/* Access to Reserved Address Line */
#define TOFF_FDCAN_ILE      0x005C		/* (RW) FDCAN Interrupt Line Enable register */
  #define FDCAN_ILE_EINT0    0x00000001	/* Enable Interrupt Line 0 */
  #define FDCAN_ILE_EINT1    0x00000002	/* Enable Interrupt Line 1 */
#define TOFF_FDCAN_GFC      0x0080		/* (RW) FDCAN Global Filter Configuration register */
  #define FDCAN_GFC_RRFE     0x00000001	/* Reject Remote Frames Extended */
  #define FDCAN_GFC_RRFS     0x00000002	/* Reject Remote Frames Standard */
  #define FDCAN_GFC_ANFE     0x0000000C	/* Accept Non-matching Frames Extended */
  #define FDCAN_GFC_ANFS     0x00000030	/* Accept Non-matching Frames Standard       */
#define TOFF_FDCAN_SIDFC    0x0084		/* (RW) FDCAN Standard ID Filter Configuration register */
  #define FDCAN_SIDFC_FLSSA  0x0000FFFC	/* Filter List Standard Start Address */
  #define FDCAN_SIDFC_LSS    0x00FF0000	/* List Size Standard */
#define TOFF_FDCAN_XIDFC    0x0088		/* (RW) FDCAN Extended ID Filter Configuration register */
  #define FDCAN_XIDFC_FLESA  0x0000FFFC	/* Filter List Standard Start Address */
  #define FDCAN_XIDFC_LSE    0x007F0000	/* List Size Extended */
#define TOFF_FDCAN_XIDAM    0x008C		/* (RW) FDCAN Extended ID AND Mask register */
#define TOFF_FDCAN_HPMS     0x0094		/* (RW) FDCAN High Priority Message Status register */
  #define FDCAN_HPMS_BIDX    0x0000003F	/* Buffer Index */
  #define FDCAN_HPMS_MSI     0x000000C0	/* Message Storage Indicator */
  #define FDCAN_HPMS_FIDX    0x00007F00	/* Filter Index */
  #define FDCAN_HPMS_FLST    0x00008000	/* Filter List */
#define TOFF_FDCAN_NDAT1    0x0098		/* (RW) FDCAN New Data 1 register */
#define TOFF_FDCAN_NDAT2    0x009C		/* (RW) FDCAN New Data 2 register */
#define TOFF_FDCAN_RXF0C    0x00A0		/* (RW) FDCAN Rx FIFO 0 Configuration register */
  #define FDCAN_RXF0C_F0SA   0x0000FFFC	/* Rx FIFO 0 Start Address */
  #define FDCAN_RXF0C_F0S    0x007F0000	/* Number of Rx FIFO 0 elements */
  #define FDCAN_RXF0C_F0WM   0x7F000000	/* FIFO 0 Watermark */
  #define FDCAN_RXF0C_F0OM   0x80000000	/* FIFO 0 Operation Mode */
#define TOFF_FDCAN_RXF0S    0x00A4		/* (RW) FDCAN Rx FIFO 0 Status register */
  #define FDCAN_RXF0S_F0FL   0x0000007F	/* Rx FIFO 0 Fill Level */
  #define FDCAN_RXF0S_F0GI   0x00003F00	/* Rx FIFO 0 Get Index */
  #define FDCAN_RXF0S_F0PI   0x003F0000	/* Rx FIFO 0 Put Index */
  #define FDCAN_RXF0S_F0F    0x01000000	/* Rx FIFO 0 Full */
  #define FDCAN_RXF0S_RF0L   0x02000000	/* Rx FIFO 0 Message Lost */
#define TOFF_FDCAN_RXF0A    0x00A8		/* (RW) FDCAN Rx FIFO 0 Acknowledge register */
#define TOFF_FDCAN_RXBC     0x00AC		/* (RW) FDCAN Rx Buffer Configuration register */
#define TOFF_FDCAN_RXF1C    0x00B0		/* (RW) FDCAN Rx FIFO 1 Configuration register */
  #define FDCAN_RXF1C_F1SA   0x0000FFFC	/* Rx FIFO 1 Start Address */
  #define FDCAN_RXF1C_F1S    0x007F0000	/* Number of Rx FIFO 1 elements */
  #define FDCAN_RXF1C_F1WM   0x7F000000	/* Rx FIFO 1 Watermark */
  #define FDCAN_RXF1C_F1OM   0x80000000	/* FIFO 1 Operation Mode */
#define TOFF_FDCAN_RXF1S    0x00B4		/* (RW) FDCAN Rx FIFO 1 Status register */
  #define FDCAN_RXF1S_F1FL   0x0000007F	/* Rx FIFO 1 Fill Level */
  #define FDCAN_RXF1S_F1GI   0x00003F00	/* Rx FIFO 1 Get Index */
  #define FDCAN_RXF1S_F1PI   0x003F0000	/* Rx FIFO 1 Put Index */
  #define FDCAN_RXF1S_F1F    0x01000000	/* Rx FIFO 1 Full */
  #define FDCAN_RXF1S_RF1L   0x02000000	/* Rx FIFO 1 Message Lost */
#define TOFF_FDCAN_RXF1A    0x00B8		/* (RW) FDCAN Rx FIFO 1 Acknowledge register */
#define TOFF_FDCAN_RXESC    0x00BC		/* (RW) FDCAN Rx Buffer/FIFO Element Size Configuration register */
  #define FDCAN_RXESC_F0DS   0x00000007	/* Rx FIFO 1 Data Field Size */
  #define FDCAN_RXESC_F1DS   0x00000070	/* Rx FIFO 0 Data Field Size */
  #define FDCAN_RXESC_RBDS   0x00000700	/* Rx Buffer Data Field Size */
#define TOFF_FDCAN_TXBC     0x00C0		/* (RW) FDCAN Tx Buffer Configuration register */
  #define FDCAN_TXBC_TBSA    0x0000FFFC	/* Tx Buffers Start Address */
  #define FDCAN_TXBC_NDTB    0x003F0000	/* Number of Dedicated Transmit Buffers */
  #define FDCAN_TXBC_TFQS    0x3F000000	/* Transmit FIFO/Queue Size */
  #define FDCAN_TXBC_TFQM    0x40000000	/* Tx FIFO/Queue Mode */
#define TOFF_FDCAN_TXFQS    0x00C4		/* (RW) FDCAN Tx FIFO/Queue Status register */
  #define FDCAN_TXFQS_TFFL   0x0000003F	/* Tx FIFO Free Level */
  #define FDCAN_TXFQS_TFGI   0x00001F00	/* Tx FIFO Get Index */
  #define FDCAN_TXFQS_TFQPI  0x001F0000	/* Tx FIFO/Queue Put Index */
  #define FDCAN_TXFQS_TFQF   0x00200000	/* Tx FIFO/Queue Full */
#define TOFF_FDCAN_TXESC    0x00C8		/* (RW) FDCAN Tx Buffer Element Size Configuration register */
#define TOFF_FDCAN_TXBRP    0x00CC		/* (RW) FDCAN Tx Buffer Request Pending register */
#define TOFF_FDCAN_TXBAR    0x00D0		/* (RW) FDCAN Tx Buffer Add Request register */
#define TOFF_FDCAN_TXBCR    0x00D4		/* (RW) FDCAN Tx Buffer Cancellation Request register */
#define TOFF_FDCAN_TXBTO    0x00D8		/* (RW) FDCAN Tx Buffer Transmission Occurred register */
#define TOFF_FDCAN_TXBCF    0x00DC		/* (RW) FDCAN Tx Buffer Cancellation Finished register */
#define TOFF_FDCAN_TXBTIE   0x00E0		/* (RW) FDCAN Tx Buffer Transmission Interrupt Enable register */
#define TOFF_FDCAN_TXBCIE   0x00E4		/* (RW) FDCAN Tx Buffer Cancellation Finished Interrupt Enable register */
#define TOFF_FDCAN_TXEFC    0x00F0		/* (RW) FDCAN Tx Event FIFO Configuration register */
  #define FDCAN_TXEFC_EFSA   0x0000FFFC	/* Event FIFO Start Address */
  #define FDCAN_TXEFC_EFS    0x003F0000	/* Event FIFO Size */
  #define FDCAN_TXEFC_EFWM   0x3F000000	/* Event FIFO Watermark */
#define TOFF_FDCAN_TXEFS    0x00F4		/* (RW) FDCAN Tx Event FIFO Status register */
  #define FDCAN_TXEFS_EFFL   0x0000003F	/* Event FIFO Fill Level */
  #define FDCAN_TXEFS_EFGI   0x00001F00	/* Event FIFO Get Index */
  #define FDCAN_TXEFS_EFPI   0x001F0000	/* Event FIFO Put Index */
  #define FDCAN_TXEFS_EFF    0x01000000	/* Event FIFO Full */
  #define FDCAN_TXEFS_TEFL   0x02000000	/* Tx Event FIFO Element Lost */
#define TOFF_FDCAN_TXEFA    0x00F8		/* (RW) FDCAN Tx Event FIFO Acknowledge register */

#define TADR_FDCAN_CCU_BASE (D2_APB1PERIPH_BASE + 0xA800)
#define TOFF_FDCANCCU_CREL  0x0000		/* (RW) Clock Calibration Unit Core Release register */
  #define FDCANCCU_CREL_DAY  0x000000FF	/* Timestamp Day */
  #define FDCANCCU_CREL_MON  0x0000FF00	/* Timestamp Month */
  #define FDCANCCU_CREL_YEAR 0x000F0000	/* Timestamp Year */
  #define FDCANCCU_CREL_SUBSTEP 0x00F00000	/* Sub-step of Core release */
  #define FDCANCCU_CREL_STEP 0x0F000000	/* Step of Core release */
  #define FDCANCCU_CREL_REL  0xF0000000	/* Core release */
#define TOFF_FDCANCCU_CCFG  0x0004		/* (RW) Calibration Configuration register */
  #define FDCANCCU_CCFG_TQBT 0x0000001F	/* Time Quanta per Bit Time */
  #define FDCANCCU_CCFG_BCC  0x00000040	/* Bypass Clock Calibration */
  #define FDCANCCU_CCFG_CFL  0x00000080	/* Calibration Field Length */
  #define FDCANCCU_CCFG_OCPM 0x0000FF00	/* Oscillator Clock Periods Minimum */
  #define FDCANCCU_CCFG_CDIV 0x000F0000	/* Clock Divider */
  #define FDCANCCU_CCFG_SWR  0x80000000	/* Software Reset */
#define TOFF_FDCANCCU_CSTAT 0x0008		/* (RW) Calibration Status register */
  #define FDCANCCU_CSTAT_OCPC 0x0003FFFF	/* Oscillator Clock Period Counter */
  #define FDCANCCU_CSTAT_TQC  0x1FFC0000	/* Time Quanta Counter */
  #define FDCANCCU_CSTAT_CALS 0xC0000000	/* Calibration State */
#define TOFF_FDCANCCU_CWD   0x000C		/* (RW) Calibration Watchdog register */
  #define FDCANCCU_CWD_WDC   0x0000FFFF	/* Watchdog Configuration */
  #define FDCANCCU_CWD_WDV   0xFFFF0000	/* Watchdog Value */
#define TOFF_FDCANCCU_IR    0x0010		/* (RW) CCU Interrupt register */
  #define FDCANCCU_IR_CWE    0x00000001	/* Calibration Watchdog Event */
  #define FDCANCCU_IR_CSC    0x00000002	/* Calibration State Changed */
#define TOFF_FDCANCCU_IE    0x0014		/* (RW) CCU Interrupt Enable register */
  #define FDCANCCU_IE_CWEE   0x00000001	/* Calibration Watchdog Event Enable */
  #define FDCANCCU_IE_CSCEs  0x00000002	/* Calibration State Changed Enable */


/* 
 * HDMI-CEC 
 */
#define TADR_CEC_BASE      (D2_APB1PERIPH_BASE + 0x6C00)
#define TOFF_CEC_CR        0x0000		/* (RW) CEC control register */
#define TOFF_CEC_CFGR      0x0004		/* (RW) CEC configuration register */
#define TOFF_CEC_TXDR      0x0008		/* (RW) CEC Tx data register  */
#define TOFF_CEC_RXDR      0x000C		/* (RW) CEC Rx Data Register */
#define TOFF_CEC_ISR       0x0010		/* (RW) CEC Interrupt and Status Register */
#define TOFF_CEC_IER       0x0014		/* (RW) CEC interrupt enable register */


/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (D3_AHB1PERIPH_BASE + 0x4800)
#define TOFF_PWR_CR1        0x0000		/* (RW) PWR power control register */
  #define PWR_CR1_LPDS       0x00000001	/* Low-Power Deepsleep                 */
  #define PWR_CR1_PVDEN      0x00000010	/* Power Voltage Detector Enable       */
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
  #define PWR_CR1_DBP        0x00000100	/* Disable Backup Domain write protection */
  #define PWR_CR1_FPDS       0x00000200	/* Flash power down in Stop mode */
  #define PWR_CR1_SVOS       0x0000C000	/* System STOP mode Voltage Scaling selection. */
  #define PWR_CR1_SVOS_0     0x00004000
  #define PWR_CR1_SVOS_1     0x00008000
  #define PWR_CR1_AVDEN      0x00010000	/* Analog Voltage Detector Enable */
  #define PWR_CR1_ALS        0x00060000	/* Analog Voltage Detector level selection */
  #define PWR_CR1_ALS_0      0x00000000
  #define PWR_CR1_ALS_1      0x00040000
  #define PWR_CR1_ALS_LEV0   0x00020000	/* AVD level 0 */
  #define PWR_CR1_ALS_LEV1   0x00020000	/* AVD level 1 */
  #define PWR_CR1_ALS_LEV2   0x00040000	/* AVD level 2 */
  #define PWR_CR1_ALS_LEV3   0x00060000	/* AVD level 3 */
#define TOFF_PWR_CSR1       0x0004		/* (RW) PWR power control/status register */
  #define PWR_CSR1_PVDO      0x00000010	/* Programmable Voltage Detect Output */
  #define PWR_CSR1_ACTVOSRDY 0x00002000	/* Ready bit for current actual used VOS for VDD11 Voltage Scaling */
  #define PWR_CSR1_ACTVOS    0x0000C000	/* Current actual used VOS for VDD11 Voltage Scaling */
  #define PWR_CSR1_ACTVOS_0  0x00004000
  #define PWR_CSR1_ACTVOS_1  0x00008000
  #define PWR_CSR1_AVDO      0x00010000	/* Analog Voltage Detect Output */
#define TOFF_PWR_CR2        0x0008		/* (RW) PWR power control register 2 */
  #define PWR_CR2_BREN       0x00000001	/* Backup regulator enable */
  #define PWR_CR2_MONEN      0x00000010	/* VBAT and temperature monitoring enable */
  #define PWR_CR2_BRRDY      0x00010000	/* Backup regulator ready */
  #define PWR_CR2_VBATL      0x00100000	/* Monitored VBAT level above low threshold */
  #define PWR_CR2_VBATH      0x00200000	/* Monitored VBAT level above high threshold */
  #define PWR_CR2_TEMPL      0x00400000	/* Monitored temperature level above low threshold */
  #define PWR_CR2_TEMPH      0x00800000	/* Monitored temperature level above high threshold */
#define TOFF_PWR_CR3        0x000C		/* (RW) PWR power control register 3 */
  #define PWR_CR3_BYPASS     0x00000001	/* Power Management Unit bypass */
  #define PWR_CR3_LDOEN      0x00000002	/* Low Drop Output regulator enable */
  #define PWR_CR3_SCUEN      0x00000004	/* Supply configuration update enable */
  #define PWR_CR3_VBE        0x00000100	/* VBAT charging enable */
  #define PWR_CR3_VBRS       0x00000200	/* VBAT charging resistor selection */
  #define PWR_CR3_USB33DEN   0x01000000	/* VDD33_USB voltage level detector enable */
  #define PWR_CR3_USBREGEN   0x02000000	/* USB regulator enable */
  #define PWR_CR3_USB33RDY   0x04000000	/* USB supply ready */
#define TOFF_PWR_CPUCR      0x0010		/* (RW) PWR CPU control register */
  #define PWR_CPUCR_PDDS_D1  0x00000001	/* D1 domain Power Down Deepsleep selection */
  #define PWR_CPUCR_PDDS_D2  0x00000002	/* D2 domain Power Down Deepsleep */
  #define PWR_CPUCR_PDDS_D3  0x00000004	/* System D3 domain Power Down Deepsleep */
  #define PWR_CPUCR_STOPF    0x00000020	/* STOP Flag */
  #define PWR_CPUCR_SBF      0x00000040	/* System STANDBY Flag */
  #define PWR_CPUCR_SBF_D1   0x00000080	/* D1 domain DSTANDBY Flag */
  #define PWR_CPUCR_SBF_D2   0x00000100	/* D2 domain DSTANDBY Flag */
  #define PWR_CPUCR_CSSF     0x00000200	/* Clear D1 domain CPU1 STANDBY, STOP and HOLD flags */
  #define PWR_CPUCR_RUN_D3   0x00000800	/* Keep system D3 domain in RUN mode regardless of the CPU sub-systems modes */
#define TOFF_PWR_D3CR       0x0018		/* (RW) PWR D3 domain control register */
  #define PWR_D3CR_VOSRDY    0x00002000	/* VOS Ready bit for VDD11 Voltage Scaling output selection */
  #define PWR_D3CR_VOS       0x0000C000	/* Voltage Scaling selection according performance */
  #define PWR_D3CR_VOS_0     0x00004000
  #define PWR_D3CR_VOS_1     0x00008000
#define TOFF_PWR_WKUPCR     0x0020		/* (RW) PWR wakeup clear register */
  #define PWR_WKUPCR_WKUPC1  0x00000001	/* Clear Wakeup Pin Flag 1 */
  #define PWR_WKUPCR_WKUPC2  0x00000002	/* Clear Wakeup Pin Flag 2 */
  #define PWR_WKUPCR_WKUPC3  0x00000004	/* Clear Wakeup Pin Flag 3 */
  #define PWR_WKUPCR_WKUPC4  0x00000008	/* Clear Wakeup Pin Flag 4 */
  #define PWR_WKUPCR_WKUPC5  0x00000010	/* Clear Wakeup Pin Flag 5 */
  #define PWR_WKUPCR_WKUPC6  0x00000020	/* Clear Wakeup Pin Flag 6 */
#define TOFF_PWR_WKUPFR     0x0024		/* (RW) PWR wakeup flag register */
  #define PWR_WKUPFR_WKUPF1  0x00000001	/* Wakeup Pin Flag 1 */
  #define PWR_WKUPFR_WKUPF2  0x00000002	/* Wakeup Pin Flag 2 */
  #define PWR_WKUPFR_WKUPF3  0x00000004	/* Wakeup Pin Flag 3 */
  #define PWR_WKUPFR_WKUPF4  0x00000008	/* Wakeup Pin Flag 4 */
  #define PWR_WKUPFR_WKUPF5  0x00000010	/* Wakeup Pin Flag 5 */
  #define PWR_WKUPFR_WKUPF6  0x00000020	/* Wakeup Pin Flag 6 */
#define TOFF_PWR_WKUPEPR    0x0028		/* (RW) PWR wakeup enable and polarity register */
  #define PWR_WKUPEPR_WKUPEN    0x0000003F	/* Enable all Wakeup Pin */
  #define PWR_WKUPEPR_WKUPEN1   0x00000001	/* Enable Wakeup Pin WKUP1 */
  #define PWR_WKUPEPR_WKUPEN2   0x00000002	/* Enable Wakeup Pin WKUP2 */
  #define PWR_WKUPEPR_WKUPEN3   0x00000004	/* Enable Wakeup Pin WKUP3 */
  #define PWR_WKUPEPR_WKUPEN4   0x00000008	/* Enable Wakeup Pin WKUP4 */
  #define PWR_WKUPEPR_WKUPEN5   0x00000010	/* Enable Wakeup Pin WKUP5 */
  #define PWR_WKUPEPR_WKUPEN6   0x00000020	/* Enable Wakeup Pin WKUP6 */
  #define PWR_WKUPEPR_WKUPP1    0x00000100	/* Wakeup Pin Polarity for WKUP1 */
  #define PWR_WKUPEPR_WKUPP2    0x00000200	/* Wakeup Pin Polarity for WKUP2 */
  #define PWR_WKUPEPR_WKUPP3    0x00000400	/* Wakeup Pin Polarity for WKUP3 */
  #define PWR_WKUPEPR_WKUPP4    0x00000800	/* Wakeup Pin Polarity for WKUP4 */
  #define PWR_WKUPEPR_WKUPP5    0x00001000	/* Wakeup Pin Polarity for WKUP5 */
  #define PWR_WKUPEPR_WKUPP6    0x00002000	/* Wakeup Pin Polarity for WKUP6 */
  #define PWR_WKUPEPR_WKUPPUPD1 0x00030000	/* Wakeup Pin pull configuration for WKUP1 */
  #define PWR_WKUPEPR_WKUPPUPD1_0   0x00010000
  #define PWR_WKUPEPR_WKUPPUPD1_1   0x00020000
  #define PWR_WKUPEPR_WKUPPUPD2 0x000C0000	/* Wakeup Pin pull configuration for WKUP2 */
  #define PWR_WKUPEPR_WKUPPUPD2_0   0x00040000
  #define PWR_WKUPEPR_WKUPPUPD2_1   0x00080000
  #define PWR_WKUPEPR_WKUPPUPD3 0x00300000	/* Wakeup Pin pull configuration for WKUP3 */
  #define PWR_WKUPEPR_WKUPPUPD3_0   0x00100000
  #define PWR_WKUPEPR_WKUPPUPD3_1   0x00200000
  #define PWR_WKUPEPR_WKUPPUPD4 0x00C00000	/* Wakeup Pin pull configuration for WKUP4 */
  #define PWR_WKUPEPR_WKUPPUPD4_0   0x00400000
  #define PWR_WKUPEPR_WKUPPUPD4_1   0x00800000
  #define PWR_WKUPEPR_WKUPPUPD5 0x03000000	/* Wakeup Pin pull configuration for WKUP5 */
  #define PWR_WKUPEPR_WKUPPUPD5_0   0x01000000
  #define PWR_WKUPEPR_WKUPPUPD5_1   0x02000000
  #define PWR_WKUPEPR_WKUPPUPD6 0x0C000000	/* Wakeup Pin pull configuration for WKUP6 */
  #define PWR_WKUPEPR_WKUPPUPD6_0   0x04000000
  #define PWR_WKUPEPR_WKUPPUPD6_1   0x08000000


/*
 *  DIGITAL TO ANALOG CONVTER
 */
#define TADR_DAC_BASE       (D2_APB1PERIPH_BASE + 0x7400)
#define TOFF_DAC_CR         0x0000		/* (RW) DAC control register */
  #define DAC_CR_EN1         0x00000001	/* DAC channel1 enable */
  #define DAC_CR_TEN1        0x00000002	/* DAC channel1 Trigger enable */
  #define DAC_CR_TSEL1       0x0000003C	/* TSEL1[2:0] (DAC channel1 Trigger selection) */
  #define DAC_CR_TSEL1_0     0x00000004
  #define DAC_CR_TSEL1_1     0x00000008
  #define DAC_CR_TSEL1_2     0x00000010
  #define DAC_CR_TSEL1_3     0x00000020
  #define DAC_CR_WAVE1       0x000000C0	/* WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
  #define DAC_CR_WAVE1_0     0x00000040
  #define DAC_CR_WAVE1_1     0x00000080
  #define DAC_CR_MAMP1       0x00000F00	/* MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
  #define DAC_CR_MAMP1_0     0x00000100
  #define DAC_CR_MAMP1_1     0x00000200
  #define DAC_CR_MAMP1_2     0x00000400
  #define DAC_CR_MAMP1_3     0x00000800
  #define DAC_CR_DMAEN1      0x00001000	/* DAC channel1 DMA enable */
  #define DAC_CR_DMAUDRIE1   0x00002000	/* DAC channel 1 DMA underrun interrupt enable */
  #define DAC_CR_CEN1        0x00004000	/* DAC channel 1 calibration enable >*/
  #define DAC_CR_EN2         0x00010000	/* DAC channel2 enable */
  #define DAC_CR_TEN2        0x00020000	/* DAC channel2 Trigger enable */
  #define DAC_CR_TSEL2       0x003C0000	/* TSEL2[2:0] (DAC channel2 Trigger selection) */
  #define DAC_CR_TSEL2_0     0x00040000
  #define DAC_CR_TSEL2_1     0x00080000
  #define DAC_CR_TSEL2_2     0x00100000
  #define DAC_CR_TSEL2_3     0x00200000
  #define DAC_CR_WAVE2       0x00C00000	/* WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
  #define DAC_CR_WAVE2_0     0x00400000
  #define DAC_CR_WAVE2_1     0x00800000
  #define DAC_CR_MAMP2       0x0F000000	/* MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
  #define DAC_CR_MAMP2_0     0x01000000
  #define DAC_CR_MAMP2_1     0x02000000
  #define DAC_CR_MAMP2_2     0x04000000
  #define DAC_CR_MAMP2_3     0x08000000
  #define DAC_CR_DMAEN2      0x10000000	/* DAC channel2 DMA enabled */
  #define DAC_CR_DMAUDRIE2   0x20000000	/* DAC channel2 DMA underrun interrupt enable */
  #define DAC_CR_CEN2        0x40000000	/* DAC channel2 calibration enable */
#define TOFF_DAC_SWTRIGR	0x0004		/* (RW) DAC software trigger register */
  #define DAC_SWTRIGR_SWTRIG1   0x00000001	/*DAC channel1 software trigger */
  #define DAC_SWTRIGR_SWTRIG2   0x00000002	/* DAC channel2 software trigger */
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
  #define DAC_SR_DMAUDR1     0x00002000	/* DAC channel1 DMA underrun flag */
  #define DAC_SR_CAL_FLAG1   0x00004000	/* DAC channel1 calibration offset status */
  #define DAC_SR_BWST1       0x20008000	/* DAC channel1 busy writing sample time flag */
  #define DAC_SR_DMAUDR2     0x20000000	/* DAC channel2 DMA underrun flag */
  #define DAC_SR_CAL_FLAG2   0x40000000	/* DAC channel2 calibration offset status */
  #define DAC_SR_BWST2       0x80000000	/* DAC channel2 busy writing sample time flag */
#define TOFF_DAC_CCR        0x0038		/* (RW) DAC calibration control register */
  #define DAC_CCR_OTRIM1     0x0000001F	/* DAC channel1 offset trimming value */
  #define DAC_CCR_OTRIM2     0x001F0000	/* DAC channel2 offset trimming value */
#define TOFF_DAC_MCR        0x003C		/* (RW) DAC mode control register */
  #define DAC_MCR_MODE1      0x00000007	/* MODE1[2:0] (DAC channel1 mode) */
  #define DAC_MCR_MODE1_0    0x00000001
  #define DAC_MCR_MODE1_1    0x00000002
  #define DAC_MCR_MODE1_2    0x00000004
  #define DAC_MCR_MODE2      0x00070000	/* MODE2[2:0] (DAC channel2 mode) */
  #define DAC_MCR_MODE2_0    0x00010000
  #define DAC_MCR_MODE2_1    0x00020000
  #define DAC_MCR_MODE2_2    0x00040000
#define TOFF_DAC_SHSR1      0x0040		/* (RW) DAC Sample and Hold sample time register 1 */
#define TOFF_DAC_SHSR2      0x0044		/* (RW) DAC Sample and Hold sample time register 2 */
#define TOFF_DAC_SHHR       0x0048		/* (RW) DAC Sample and Hold hold time register */
  #define DAC_SHHR_THOLD1    0x000003FF	/* DAC channel1 hold time */
  #define DAC_SHHR_THOLD2    0x03FF0000	/* DAC channel2 hold time */
#define TOFF_DAC_SHRR       0x004C		/* (RW) DAC Sample and Hold refresh time register */
  #define DAC_SHRR_TREFRESH1 0x000000FF	/* DAC channel1 refresh time */
  #define DAC_SHRR_TREFRESH2 0x00FF0000	/* DAC channel2 refresh time */


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (D2_AHB1PERIPH_BASE + 0x2000)
#define TADR_ADC2_BASE      (D2_AHB1PERIPH_BASE + 0x2100)
#define TADR_ADC3_BASE      (D3_AHB1PERIPH_BASE + 0x6000)
#define TOFF_ADC_ISR        0x0000		/* (RW) ADC Interrupt and Status Register */
  #define ADC_ISR_ADRDY      0x00000001	/* ADC Ready (ADRDY) flag */
  #define ADC_ISR_EOSMP      0x00000002	/* ADC End of Sampling flag */
  #define ADC_ISR_EOC        0x00000004	/* ADC End of Regular Conversion flag */
  #define ADC_ISR_EOS        0x00000008	/* ADC End of Regular sequence of Conversions flag */
  #define ADC_ISR_OVR        0x00000010	/* ADC overrun flag */
  #define ADC_ISR_JEOC       0x00000020	/* ADC End of Injected Conversion flag */
  #define ADC_ISR_JEOS       0x00000040	/* ADC End of Injected sequence of Conversions flag */
  #define ADC_ISR_AWD1       0x00000080	/* ADC Analog watchdog 1 flag */
  #define ADC_ISR_AWD2       0x00000100	/* ADC Analog watchdog 2 flag */
  #define ADC_ISR_AWD3       0x00000200	/* ADC Analog watchdog 3 flag */
  #define ADC_ISR_JQOVF      0x00000400	/* ADC Injected Context Queue Overflow flag */
#define TOFF_ADC_IER        0x0004		/* (RW) ADC Interrupt Enable Register */
  #define ADC_IER_ADRDYIE    0x00000001	/* ADC Ready (ADRDY) interrupt source */
  #define ADC_IER_EOSMPIE    0x00000002	/* ADC End of Sampling interrupt source */
  #define ADC_IER_EOCIE      0x00000004	/* ADC End of Regular Conversion interrupt source */
  #define ADC_IER_EOSIE      0x00000008	/* ADC End of Regular sequence of Conversions interrupt source */
  #define ADC_IER_OVRIE      0x00000010	/* ADC overrun interrupt source */
  #define ADC_IER_JEOCIE     0x00000020	/* ADC End of Injected Conversion interrupt source */
  #define ADC_IER_JEOSIE     0x00000040	/* ADC End of Injected sequence of Conversions interrupt source */
  #define ADC_IER_AWD1IE     0x00000080	/* ADC Analog watchdog 1 interrupt source */
  #define ADC_IER_AWD2IE     0x00000100	/* ADC Analog watchdog 2 interrupt source */
  #define ADC_IER_AWD3IE     0x00000200	/* ADC Analog watchdog 3 interrupt source */
  #define ADC_IER_JQOVFIE    0x00000400	/* ADC Injected Context Queue Overflow interrupt source */
#define TOFF_ADC_CR         0x0008		/* (RW) ADC control register */
  #define ADC_CR_ADEN        0x00000001	/* ADC Enable control */
  #define ADC_CR_ADDIS       0x00000002	/* ADC Disable command */
  #define ADC_CR_ADSTART     0x00000004	/* ADC Start of Regular conversion */
  #define ADC_CR_JADSTART    0x00000008	/* ADC Start of injected conversion */
  #define ADC_CR_ADSTP       0x00000010	/* ADC Stop of Regular conversion */
  #define ADC_CR_JADSTP      0x00000020	/* ADC Stop of injected conversion */
  #define ADC_CR_BOOST       0x00000300	/* ADC Boost Mode configuration */
  #define ADC_CR_BOOST_0     0x00000100
  #define ADC_CR_BOOST_1     0x00000200
  #define ADC_CR_ADCALLIN    0x00010000	/* ADC Linearity calibration */
  #define ADC_CR_LINCALRDYW1 0x00400000	/* ADC Linearity calibration ready Word 1 */
  #define ADC_CR_LINCALRDYW2 0x00800000	/* ADC Linearity calibration ready Word 2 */
  #define ADC_CR_LINCALRDYW3 0x01000000	/* ADC Linearity calibration ready Word 3 */
  #define ADC_CR_LINCALRDYW4 0x02000000	/* ADC Linearity calibration ready Word 4 */
  #define ADC_CR_LINCALRDYW5 0x04000000	/* ADC Linearity calibration ready Word 5 */
  #define ADC_CR_LINCALRDYW6 0x08000000	/* ADC Linearity calibration ready Word 6 */
  #define ADC_CR_ADVREGEN    0x10000000	/* ADC Voltage regulator Enable */
  #define ADC_CR_DEEPPWD     0x20000000	/* ADC Deep power down Enable */
  #define ADC_CR_ADCALDIF    0x40000000	/* ADC Differential Mode for calibration */
  #define ADC_CR_ADCAL       0x80000000	/* ADC Calibration */
#define TOFF_ADC_CFGR       0x000C		/* (RW) ADC Configuration register */
  #define ADC_CFGR_DMNGT     0x00000003	/* ADC Data Management configuration */
  #define ADC_CFGR_DMNGT_0   0x00000001
  #define ADC_CFGR_DMNGT_1   0x00000002
  #define ADC_CFGR_RES       0x0000001C	/* ADC Data resolution */
  #define ADC_CFGR_RES_0     0x00000004
  #define ADC_CFGR_RES_1     0x00000008
  #define ADC_CFGR_RES_2     0x00000010
  #define ADC_CFGR_EXTSEL    0x000003E0	/* ADC External trigger selection for regular group */
  #define ADC_CFGR_EXTSEL_0  0x00000020
  #define ADC_CFGR_EXTSEL_1  0x00000040
  #define ADC_CFGR_EXTSEL_2  0x00000080
  #define ADC_CFGR_EXTSEL_3  0x00000100
  #define ADC_CFGR_EXTSEL_4  0x00000200
  #define ADC_CFGR_EXTEN     0x00000C00	/* ADC External trigger enable and polarity selection for regular channels */
  #define ADC_CFGR_EXTEN_0   0x00000400
  #define ADC_CFGR_EXTEN_1   0x00000800
  #define ADC_CFGR_OVRMOD    0x00001000	/* ADC overrun mode */
  #define ADC_CFGR_CONT      0x00002000	/* ADC Single/continuous conversion mode for regular conversion */
  #define ADC_CFGR_AUTDLY    0x00004000	/* ADC Delayed conversion mode */
  #define ADC_CFGR_DISCEN    0x00010000	/* ADC Discontinuous mode for regular channels */
  #define ADC_CFGR_DISCNUM   0x000E0000	/* ADC Discontinuous mode channel count */
  #define ADC_CFGR_DISCNUM_0 0x00020000
  #define ADC_CFGR_DISCNUM_1 0x00040000
  #define ADC_CFGR_DISCNUM_2 0x00080000
  #define ADC_CFGR_JDISCEN   0x00100000	/* ADC Discontinuous mode on injected channels */
  #define ADC_CFGR_JQM       0x00200000	/* ADC JSQR Queue mode */
  #define ADC_CFGR_AWD1SGL   0x00400000	/* Enable the watchdog 1 on a single channel or on all channels */
  #define ADC_CFGR_AWD1EN    0x00800000	/* ADC Analog watchdog 1 enable on regular Channels */
  #define ADC_CFGR_JAWD1EN   0x01000000	/* ADC Analog watchdog 1 enable on injected Channels */
  #define ADC_CFGR_JAUTO     0x02000000	/* ADC Automatic injected group conversion */
  #define ADC_CFGR_AWD1CH    0x7C000000	/* ADC Analog watchdog 1 Channel selection */
  #define ADC_CFGR_AWD1CH_0  0x04000000
  #define ADC_CFGR_AWD1CH_1  0x08000000
  #define ADC_CFGR_AWD1CH_2  0x10000000
  #define ADC_CFGR_AWD1CH_3  0x20000000
  #define ADC_CFGR_AWD1CH_4  0x40000000
  #define ADC_CFGR_JQDIS     0x80000000	/* ADC Injected queue disable */
#define TOFF_ADC_CFGR2      0x0010		/* (RW) ADC Configuration register 2 */
  #define ADC_CFGR2_ROVSE    0x00000001	/* ADC Regular group oversampler enable */
  #define ADC_CFGR2_JOVSE    0x00000002	/* ADC Injected group oversampler enable */
  #define ADC_CFGR2_OVSS     0x000001E0	/* ADC Regular Oversampling shift */
  #define ADC_CFGR2_OVSS_0   0x00000020
  #define ADC_CFGR2_OVSS_1   0x00000040
  #define ADC_CFGR2_OVSS_2   0x00000080
  #define ADC_CFGR2_OVSS_3   0x00000100
  #define ADC_CFGR2_TROVS    0x00000200	/* ADC Triggered regular Oversampling */
  #define ADC_CFGR2_ROVSM    0x00000400	/* ADC Regular oversampling mode */
  #define ADC_CFGR2_RSHIFT1  0x00000800	/* ADC Right-shift data after Offset 1 correction */
  #define ADC_CFGR2_RSHIFT2  0x00001000	/* ADC Right-shift data after Offset 2 correction */
  #define ADC_CFGR2_RSHIFT3  0x00002000	/* ADC Right-shift data after Offset 3 correction */
  #define ADC_CFGR2_RSHIFT4  0x00004000	/* ADC Right-shift data after Offset 4 correction */
  #define ADC_CFGR2_OVSR     0x03FF0000	/* ADC oversampling Ratio */
  #define ADC_CFGR2_OVSR_0   0x00010000
  #define ADC_CFGR2_OVSR_1   0x00020000
  #define ADC_CFGR2_OVSR_2   0x00040000
  #define ADC_CFGR2_OVSR_3   0x00080000
  #define ADC_CFGR2_OVSR_4   0x00100000
  #define ADC_CFGR2_OVSR_5   0x00200000
  #define ADC_CFGR2_OVSR_6   0x00400000
  #define ADC_CFGR2_OVSR_7   0x00800000
  #define ADC_CFGR2_OVSR_8   0x01000000
  #define ADC_CFGR2_OVSR_9   0x02000000
  #define ADC_CFGR2_LSHIFT   0xF0000000	/* ADC Left shift factor */
  #define ADC_CFGR2_LSHIFT_0 0x10000000
  #define ADC_CFGR2_LSHIFT_1 0x20000000
  #define ADC_CFGR2_LSHIFT_2 0x40000000
  #define ADC_CFGR2_LSHIFT_3 0x80000000
#define TOFF_ADC_SMPR1      0x0014		/* (RW) ADC sample time register 1 */
  #define ADC_SMPR1_SMP0     0x00000007	/* ADC Channel 0 Sampling time selection  */
  #define ADC_SMPR1_SMP0_0   0x00000001
  #define ADC_SMPR1_SMP0_1   0x00000002
  #define ADC_SMPR1_SMP0_2   0x00000004
  #define ADC_SMPR1_SMP1     0x00000038	/* ADC Channel 1 Sampling time selection  */
  #define ADC_SMPR1_SMP1_0   0x00000008
  #define ADC_SMPR1_SMP1_1   0x00000010
  #define ADC_SMPR1_SMP1_2   0x00000020
  #define ADC_SMPR1_SMP2     0x000001C0	/* ADC Channel 2 Sampling time selection  */
  #define ADC_SMPR1_SMP2_0   0x00000040
  #define ADC_SMPR1_SMP2_1   0x00000080
  #define ADC_SMPR1_SMP2_2   0x00000100
  #define ADC_SMPR1_SMP3     0x00000E00	/* ADC Channel 3 Sampling time selection  */
  #define ADC_SMPR1_SMP3_0   0x00000200
  #define ADC_SMPR1_SMP3_1   0x00000400
  #define ADC_SMPR1_SMP3_2   0x00000800
  #define ADC_SMPR1_SMP4     0x00007000	/* ADC Channel 4 Sampling time selection  */
  #define ADC_SMPR1_SMP4_0   0x00001000
  #define ADC_SMPR1_SMP4_1   0x00002000
  #define ADC_SMPR1_SMP4_2   0x00004000
  #define ADC_SMPR1_SMP5     0x00038000	/* ADC Channel 5 Sampling time selection  */
  #define ADC_SMPR1_SMP5_0   0x00008000
  #define ADC_SMPR1_SMP5_1   0x00010000
  #define ADC_SMPR1_SMP5_2   0x00020000
  #define ADC_SMPR1_SMP6     0x001C0000	/* ADC Channel 6 Sampling time selection  */
  #define ADC_SMPR1_SMP6_0   0x00040000
  #define ADC_SMPR1_SMP6_1   0x00080000
  #define ADC_SMPR1_SMP6_2   0x00100000
  #define ADC_SMPR1_SMP7     0x00E00000	/* ADC Channel 7 Sampling time selection  */
  #define ADC_SMPR1_SMP7_0   0x00200000
  #define ADC_SMPR1_SMP7_1   0x00400000
  #define ADC_SMPR1_SMP7_2   0x00800000
  #define ADC_SMPR1_SMP8     0x07000000	/* ADC Channel 8 Sampling time selection  */
  #define ADC_SMPR1_SMP8_0   0x01000000
  #define ADC_SMPR1_SMP8_1   0x02000000
  #define ADC_SMPR1_SMP8_2   0x04000000
  #define ADC_SMPR1_SMP9     0x38000000	/* ADC Channel 9 Sampling time selection  */
  #define ADC_SMPR1_SMP9_0   0x08000000
  #define ADC_SMPR1_SMP9_1   0x10000000
  #define ADC_SMPR1_SMP9_2   0x20000000
#define TOFF_ADC_SMPR2      0x0018		/* (RW) ADC sample time register 2 */
  #define ADC_SMPR2_SMP10    0x00000007	/* ADC Channel 10 Sampling time selection  */
  #define ADC_SMPR2_SMP10_0  0x00000001
  #define ADC_SMPR2_SMP10_1  0x00000002
  #define ADC_SMPR2_SMP10_2  0x00000004
  #define ADC_SMPR2_SMP11    0x00000038	/* ADC Channel 11 Sampling time selection  */
  #define ADC_SMPR2_SMP11_0  0x00000008
  #define ADC_SMPR2_SMP11_1  0x00000010
  #define ADC_SMPR2_SMP11_2  0x00000020
  #define ADC_SMPR2_SMP12    0x000001C0	/* ADC Channel 12 Sampling time selection  */
  #define ADC_SMPR2_SMP12_0  0x00000040
  #define ADC_SMPR2_SMP12_1  0x00000080
  #define ADC_SMPR2_SMP12_2  0x00000100
  #define ADC_SMPR2_SMP13    0x00000E00	/* ADC Channel 13 Sampling time selection  */
  #define ADC_SMPR2_SMP13_0  0x00000200
  #define ADC_SMPR2_SMP13_1  0x00000400
  #define ADC_SMPR2_SMP13_2  0x00000800
  #define ADC_SMPR2_SMP14    0x00007000	/* ADC Channel 14 Sampling time selection  */
  #define ADC_SMPR2_SMP14_0  0x00001000
  #define ADC_SMPR2_SMP14_1  0x00002000
  #define ADC_SMPR2_SMP14_2  0x00004000
  #define ADC_SMPR2_SMP15    0x00038000	/* ADC Channel 15 Sampling time selection  */
  #define ADC_SMPR2_SMP15_0  0x00008000
  #define ADC_SMPR2_SMP15_1  0x00010000
  #define ADC_SMPR2_SMP15_2  0x00020000
  #define ADC_SMPR2_SMP16    0x001C0000	/* ADC Channel 16 Sampling time selection  */
  #define ADC_SMPR2_SMP16_0  0x00040000
  #define ADC_SMPR2_SMP16_1  0x00080000
  #define ADC_SMPR2_SMP16_2  0x00100000
  #define ADC_SMPR2_SMP17    0x00E00000	/* ADC Channel 17 Sampling time selection  */
  #define ADC_SMPR2_SMP17_0  0x00200000
  #define ADC_SMPR2_SMP17_1  0x00400000
  #define ADC_SMPR2_SMP17_2  0x00800000
  #define ADC_SMPR2_SMP18    0x07000000	/* ADC Channel 18 Sampling time selection  */
  #define ADC_SMPR2_SMP18_0  0x01000000
  #define ADC_SMPR2_SMP18_1  0x02000000
  #define ADC_SMPR2_SMP18_2  0x04000000
  #define ADC_SMPR2_SMP19    0x38000000	/* ADC Channel 19 Sampling time selection  */
  #define ADC_SMPR2_SMP19_0  0x08000000
  #define ADC_SMPR2_SMP19_1  0x10000000
  #define ADC_SMPR2_SMP19_2  0x20000000
#define TOFF_ADC_PCSEL      0x001C		/* (RW) ADC pre-channel selection */
#define TOFF_ADC_LTR1       0x0020		/* (RW) ADC watchdog Lower threshold register 1 */
  #define ADC_LTR_LT         0x03FFFFFF	/* ADC Analog watchdog 1, 2 and 3 lower threshold */
#define TOFF_ADC_HTR1       0x0024		/* (RW) ADC watchdog higher threshold register 1 */
  #define ADC_HTR_HT         0x03FFFFFF	/* ADC Analog watchdog 1,2 and 3 higher threshold */
#define TOFF_ADC_SQR1       0x0030		/* (RW) ADC regular sequence register 1 */
  #define ADC_SQR1_L         0x0000000F	/* ADC regular channel sequence lenght */
  #define ADC_SQR1_L_0       0x00000001
  #define ADC_SQR1_L_1       0x00000002
  #define ADC_SQR1_L_2       0x00000004
  #define ADC_SQR1_L_3       0x00000008
  #define ADC_SQR1_SQ1       0x000007C0	/* ADC 1st conversion in regular sequence */
  #define ADC_SQR1_SQ1_0     0x00000040
  #define ADC_SQR1_SQ1_1     0x00000080
  #define ADC_SQR1_SQ1_2     0x00000100
  #define ADC_SQR1_SQ1_3     0x00000200
  #define ADC_SQR1_SQ1_4     0x00000400
  #define ADC_SQR1_SQ2       0x0001F000	/* ADC 2nd conversion in regular sequence */
  #define ADC_SQR1_SQ2_0     0x00001000
  #define ADC_SQR1_SQ2_1     0x00002000
  #define ADC_SQR1_SQ2_2     0x00004000
  #define ADC_SQR1_SQ2_3     0x00008000
  #define ADC_SQR1_SQ2_4     0x00010000
  #define ADC_SQR1_SQ3       0x007C0000	/* ADC 3rd conversion in regular sequence */
  #define ADC_SQR1_SQ3_0     0x00040000
  #define ADC_SQR1_SQ3_1     0x00080000
  #define ADC_SQR1_SQ3_2     0x00100000
  #define ADC_SQR1_SQ3_3     0x00200000
  #define ADC_SQR1_SQ3_4     0x00400000
  #define ADC_SQR1_SQ4       0x1F000000	/* ADC 4th conversion in regular sequence */
  #define ADC_SQR1_SQ4_0     0x01000000
  #define ADC_SQR1_SQ4_1     0x02000000
  #define ADC_SQR1_SQ4_2     0x04000000
  #define ADC_SQR1_SQ4_3     0x08000000
  #define ADC_SQR1_SQ4_4     0x10000000
#define TOFF_ADC_SQR2       0x0034		/* (RW) ADC regular sequence register 2 */
  #define ADC_SQR2_SQ5       0x0000001F	/* ADC 5th conversion in regular sequence */
  #define ADC_SQR2_SQ5_0     0x00000001
  #define ADC_SQR2_SQ5_1     0x00000002
  #define ADC_SQR2_SQ5_2     0x00000004
  #define ADC_SQR2_SQ5_3     0x00000008
  #define ADC_SQR2_SQ5_4     0x00000010
  #define ADC_SQR2_SQ6       0x000007C0	/* ADC 6th conversion in regular sequence */
  #define ADC_SQR2_SQ6_0     0x00000040
  #define ADC_SQR2_SQ6_1     0x00000080
  #define ADC_SQR2_SQ6_2     0x00000100
  #define ADC_SQR2_SQ6_3     0x00000200
  #define ADC_SQR2_SQ6_4     0x00000400
  #define ADC_SQR2_SQ7       0x0001F000	/* ADC 7th conversion in regular sequence */
  #define ADC_SQR2_SQ7_0     0x00001000
  #define ADC_SQR2_SQ7_1     0x00002000
  #define ADC_SQR2_SQ7_2     0x00004000
  #define ADC_SQR2_SQ7_3     0x00008000
  #define ADC_SQR2_SQ7_4     0x00010000
  #define ADC_SQR2_SQ8       0x007C0000	/* ADC 8th conversion in regular sequence */
  #define ADC_SQR2_SQ8_0     0x00040000
  #define ADC_SQR2_SQ8_1     0x00080000
  #define ADC_SQR2_SQ8_2     0x00100000
  #define ADC_SQR2_SQ8_3     0x00200000
  #define ADC_SQR2_SQ8_4     0x00400000
  #define ADC_SQR2_SQ9       0x1F000000	/* ADC 9th conversion in regular sequence */
  #define ADC_SQR2_SQ9_0     0x01000000
  #define ADC_SQR2_SQ9_1     0x02000000
  #define ADC_SQR2_SQ9_2     0x04000000
  #define ADC_SQR2_SQ9_3     0x08000000
  #define ADC_SQR2_SQ9_4     0x10000000
#define TOFF_ADC_SQR3       0x0038		/* (RW) ADC regular sequence register 3 */
  #define ADC_SQR3_SQ10      0x0000001F	/* ADC 10th conversion in regular sequence */
  #define ADC_SQR3_SQ10_0    0x00000001
  #define ADC_SQR3_SQ10_1    0x00000002
  #define ADC_SQR3_SQ10_2    0x00000004
  #define ADC_SQR3_SQ10_3    0x00000008
  #define ADC_SQR3_SQ10_4    0x00000010
  #define ADC_SQR3_SQ11      0x000007C0	/* ADC 11th conversion in regular sequence */
  #define ADC_SQR3_SQ11_0    0x00000040
  #define ADC_SQR3_SQ11_1    0x00000080
  #define ADC_SQR3_SQ11_2    0x00000100
  #define ADC_SQR3_SQ11_3    0x00000200
  #define ADC_SQR3_SQ11_4    0x00000400
  #define ADC_SQR3_SQ12      0x0001F000	/* ADC 12th conversion in regular sequence */
  #define ADC_SQR3_SQ12_0    0x00001000
  #define ADC_SQR3_SQ12_1    0x00002000
  #define ADC_SQR3_SQ12_2    0x00004000
  #define ADC_SQR3_SQ12_3    0x00008000
  #define ADC_SQR3_SQ12_4    0x00010000
  #define ADC_SQR3_SQ13      0x007C0000	/* ADC 13th conversion in regular sequence */
  #define ADC_SQR3_SQ13_0    0x00040000
  #define ADC_SQR3_SQ13_1    0x00080000
  #define ADC_SQR3_SQ13_2    0x00100000
  #define ADC_SQR3_SQ13_3    0x00200000
  #define ADC_SQR3_SQ13_4    0x00400000
  #define ADC_SQR3_SQ14      0x1F000000	/* ADC 14th conversion in regular sequence */
  #define ADC_SQR3_SQ14_0    0x01000000
  #define ADC_SQR3_SQ14_1    0x02000000
  #define ADC_SQR3_SQ14_2    0x04000000
  #define ADC_SQR3_SQ14_3    0x08000000
  #define ADC_SQR3_SQ14_4    0x10000000
#define TOFF_ADC_SQR4       0x003C		/* (RW) ADC regular sequence register 4 */
  #define ADC_SQR4_SQ15      0x0000001F	/* ADC 15th conversion in regular sequence */
  #define ADC_SQR4_SQ15_0    0x00000001
  #define ADC_SQR4_SQ15_1    0x00000002
  #define ADC_SQR4_SQ15_2    0x00000004
  #define ADC_SQR4_SQ15_3    0x00000008
  #define ADC_SQR4_SQ15_4    0x00000010
  #define ADC_SQR4_SQ16      0x000007C0	/* ADC 16th conversion in regular sequence */
  #define ADC_SQR4_SQ16_0    0x00000040
  #define ADC_SQR4_SQ16_1    0x00000080
  #define ADC_SQR4_SQ16_2    0x00000100
  #define ADC_SQR4_SQ16_3    0x00000200
  #define ADC_SQR4_SQ16_4    0x00000400
#define TOFF_ADC_DR         0x0040		/* (RW) ADC regular data register */
#define TOFF_ADC_JSQR       0x004C		/* (RW) ADC injected sequence register */
  #define ADC_JSQR_JL        0x00000003	/* ADC injected channel sequence length */
  #define ADC_JSQR_JL_0      0x00000001
  #define ADC_JSQR_JL_1      0x00000002
  #define ADC_JSQR_JEXTSEL   0x0000007C	/* ADC external trigger selection for injected group */
  #define ADC_JSQR_JEXTSEL_0 0x00000004
  #define ADC_JSQR_JEXTSEL_1 0x00000008
  #define ADC_JSQR_JEXTSEL_2 0x00000010
  #define ADC_JSQR_JEXTSEL_3 0x00000020
  #define ADC_JSQR_JEXTSEL_4 0x00000040
  #define ADC_JSQR_JEXTEN    0x00000180	/* ADC external trigger enable and polarity selection for injected channels */
  #define ADC_JSQR_JEXTEN_0  0x00000080
  #define ADC_JSQR_JEXTEN_1  0x00000100
  #define ADC_JSQR_JSQ1      0x00003E00	/* ADC 1st conversion in injected sequence */
  #define ADC_JSQR_JSQ1_0    0x00000200
  #define ADC_JSQR_JSQ1_1    0x00000400
  #define ADC_JSQR_JSQ1_2    0x00000800
  #define ADC_JSQR_JSQ1_3    0x00001000
  #define ADC_JSQR_JSQ1_4    0x00002000
  #define ADC_JSQR_JSQ2      0x000F8000	/* ADC 2nd conversion in injected sequence */
  #define ADC_JSQR_JSQ2_0    0x00008000
  #define ADC_JSQR_JSQ2_1    0x00010000
  #define ADC_JSQR_JSQ2_2    0x00020000
  #define ADC_JSQR_JSQ2_3    0x00040000
  #define ADC_JSQR_JSQ2_4    0x00080000
  #define ADC_JSQR_JSQ3      0x03E00000	/* ADC 3rd conversion in injected sequence */
  #define ADC_JSQR_JSQ3_0    0x00200000
  #define ADC_JSQR_JSQ3_1    0x00400000
  #define ADC_JSQR_JSQ3_2    0x00800000
  #define ADC_JSQR_JSQ3_3    0x01000000
  #define ADC_JSQR_JSQ3_4    0x02000000
  #define ADC_JSQR_JSQ4      0xF8000000	/* ADC 4th conversion in injected sequence */
  #define ADC_JSQR_JSQ4_0    0x08000000
  #define ADC_JSQR_JSQ4_1    0x10000000
  #define ADC_JSQR_JSQ4_2    0x20000000
  #define ADC_JSQR_JSQ4_3    0x40000000
  #define ADC_JSQR_JSQ4_4    0x80000000
#define TOFF_ADC_OFR1       0x0060		/* (RW) ADC offset register 1 */
  #define ADC_OFR1_OFFSET1      0x03FFFFFF	/* ADC data offset 1 for channel programmed into bits OFFSET1_CH[4:0] */
  #define ADC_OFR1_OFFSET1_0    0x00000001
  #define ADC_OFR1_OFFSET1_1    0x00000002
  #define ADC_OFR1_OFFSET1_2    0x00000004
  #define ADC_OFR1_OFFSET1_3    0x00000008
  #define ADC_OFR1_OFFSET1_4    0x00000010
  #define ADC_OFR1_OFFSET1_5    0x00000020
  #define ADC_OFR1_OFFSET1_6    0x00000040
  #define ADC_OFR1_OFFSET1_7    0x00000080
  #define ADC_OFR1_OFFSET1_8    0x00000100
  #define ADC_OFR1_OFFSET1_9    0x00000200
  #define ADC_OFR1_OFFSET1_10   0x00000400
  #define ADC_OFR1_OFFSET1_11   0x00000800
  #define ADC_OFR1_OFFSET1_12   0x00001000
  #define ADC_OFR1_OFFSET1_13   0x00002000
  #define ADC_OFR1_OFFSET1_14   0x00004000
  #define ADC_OFR1_OFFSET1_15   0x00008000
  #define ADC_OFR1_OFFSET1_16   0x00010000
  #define ADC_OFR1_OFFSET1_17   0x00020000
  #define ADC_OFR1_OFFSET1_18   0x00040000
  #define ADC_OFR1_OFFSET1_19   0x00080000
  #define ADC_OFR1_OFFSET1_20   0x00100000
  #define ADC_OFR1_OFFSET1_21   0x00200000
  #define ADC_OFR1_OFFSET1_22   0x00400000
  #define ADC_OFR1_OFFSET1_23   0x00800000
  #define ADC_OFR1_OFFSET1_24   0x01000000
  #define ADC_OFR1_OFFSET1_25   0x02000000
  #define ADC_OFR1_OFFSET1_CH   0x7C000000	/* ADC Channel selection for the data offset 1 */
  #define ADC_OFR1_OFFSET1_CH_0 0x04000000
  #define ADC_OFR1_OFFSET1_CH_1 0x08000000
  #define ADC_OFR1_OFFSET1_CH_2 0x10000000
  #define ADC_OFR1_OFFSET1_CH_3 0x20000000
  #define ADC_OFR1_OFFSET1_CH_4 0x40000000
  #define ADC_OFR1_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_OFR2       0x0064		/* (RW) ADC offset register 2 */
  #define ADC_OFR2_OFFSET2      0x03FFFFFF	/* ADC data offset 2 for channel programmed into bits OFFSET2_CH[4:0] */
  #define ADC_OFR2_OFFSET2_0    0x00000001
  #define ADC_OFR2_OFFSET2_1    0x00000002
  #define ADC_OFR2_OFFSET2_2    0x00000004
  #define ADC_OFR2_OFFSET2_3    0x00000008
  #define ADC_OFR2_OFFSET2_4    0x00000010
  #define ADC_OFR2_OFFSET2_5    0x00000020
  #define ADC_OFR2_OFFSET2_6    0x00000040
  #define ADC_OFR2_OFFSET2_7    0x00000080
  #define ADC_OFR2_OFFSET2_8    0x00000100
  #define ADC_OFR2_OFFSET2_9    0x00000200
  #define ADC_OFR2_OFFSET2_10   0x00000400
  #define ADC_OFR2_OFFSET2_11   0x00000800
  #define ADC_OFR2_OFFSET2_12   0x00001000
  #define ADC_OFR2_OFFSET2_13   0x00002000
  #define ADC_OFR2_OFFSET2_14   0x00004000
  #define ADC_OFR2_OFFSET2_15   0x00008000
  #define ADC_OFR2_OFFSET2_16   0x00010000
  #define ADC_OFR2_OFFSET2_17   0x00020000
  #define ADC_OFR2_OFFSET2_18   0x00040000
  #define ADC_OFR2_OFFSET2_19   0x00080000
  #define ADC_OFR2_OFFSET2_20   0x00100000
  #define ADC_OFR2_OFFSET2_21   0x00200000
  #define ADC_OFR2_OFFSET2_22   0x00400000
  #define ADC_OFR2_OFFSET2_23   0x00800000
  #define ADC_OFR2_OFFSET2_24   0x01000000
  #define ADC_OFR2_OFFSET2_25   0x02000000
  #define ADC_OFR2_OFFSET2_CH   0x7C000000	/* ADC Channel selection for the data offset 2 */
  #define ADC_OFR2_OFFSET2_CH_0 0x04000000
  #define ADC_OFR2_OFFSET2_CH_1 0x08000000
  #define ADC_OFR2_OFFSET2_CH_2 0x10000000
  #define ADC_OFR2_OFFSET2_CH_3 0x20000000
  #define ADC_OFR2_OFFSET2_CH_4 0x40000000
  #define ADC_OFR2_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_OFR3       0x0068		/* (RW) ADC offset register 3 */
  #define ADC_OFR3_OFFSET3      0x03FFFFFF	/* ADC data offset 3 for channel programmed into bits OFFSET3_CH[4:0] */
  #define ADC_OFR3_OFFSET3_0    0x00000001
  #define ADC_OFR3_OFFSET3_1    0x00000002
  #define ADC_OFR3_OFFSET3_2    0x00000004
  #define ADC_OFR3_OFFSET3_3    0x00000008
  #define ADC_OFR3_OFFSET3_4    0x00000010
  #define ADC_OFR3_OFFSET3_5    0x00000020
  #define ADC_OFR3_OFFSET3_6    0x00000040
  #define ADC_OFR3_OFFSET3_7    0x00000080
  #define ADC_OFR3_OFFSET3_8    0x00000100
  #define ADC_OFR3_OFFSET3_9    0x00000200
  #define ADC_OFR3_OFFSET3_10   0x00000400
  #define ADC_OFR3_OFFSET3_11   0x00000800
  #define ADC_OFR3_OFFSET3_12   0x00001000
  #define ADC_OFR3_OFFSET3_13   0x00002000
  #define ADC_OFR3_OFFSET3_14   0x00004000
  #define ADC_OFR3_OFFSET3_15   0x00008000
  #define ADC_OFR3_OFFSET3_16   0x00010000
  #define ADC_OFR3_OFFSET3_17   0x00020000
  #define ADC_OFR3_OFFSET3_18   0x00040000
  #define ADC_OFR3_OFFSET3_19   0x00080000
  #define ADC_OFR3_OFFSET3_20   0x00100000
  #define ADC_OFR3_OFFSET3_21   0x00200000
  #define ADC_OFR3_OFFSET3_22   0x00400000
  #define ADC_OFR3_OFFSET3_23   0x00800000
  #define ADC_OFR3_OFFSET3_24   0x01000000
  #define ADC_OFR3_OFFSET3_25   0x02000000
  #define ADC_OFR3_OFFSET3_CH   0x7C000000	/* ADC Channel selection for the data offset 3 */
  #define ADC_OFR3_OFFSET3_CH_0 0x04000000
  #define ADC_OFR3_OFFSET3_CH_1 0x08000000
  #define ADC_OFR3_OFFSET3_CH_2 0x10000000
  #define ADC_OFR3_OFFSET3_CH_3 0x20000000
  #define ADC_OFR3_OFFSET3_CH_4 0x40000000
  #define ADC_OFR3_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_OFR4       0x006C		/* (RW) ADC offset register 4 */
  #define ADC_OFR4_OFFSET4      0x03FFFFFF	/* ADC data offset 4 for channel programmed into bits OFFSET4_CH[4:0] */
  #define ADC_OFR4_OFFSET4_0    0x00000001
  #define ADC_OFR4_OFFSET4_1    0x00000002
  #define ADC_OFR4_OFFSET4_2    0x00000004
  #define ADC_OFR4_OFFSET4_3    0x00000008
  #define ADC_OFR4_OFFSET4_4    0x00000010
  #define ADC_OFR4_OFFSET4_5    0x00000020
  #define ADC_OFR4_OFFSET4_6    0x00000040
  #define ADC_OFR4_OFFSET4_7    0x00000080
  #define ADC_OFR4_OFFSET4_8    0x00000100
  #define ADC_OFR4_OFFSET4_9    0x00000200
  #define ADC_OFR4_OFFSET4_10   0x00000400
  #define ADC_OFR4_OFFSET4_11   0x00000800
  #define ADC_OFR4_OFFSET4_12   0x00001000
  #define ADC_OFR4_OFFSET4_13   0x00002000
  #define ADC_OFR4_OFFSET4_14   0x00004000
  #define ADC_OFR4_OFFSET4_15   0x00008000
  #define ADC_OFR4_OFFSET4_16   0x00010000
  #define ADC_OFR4_OFFSET4_17   0x00020000
  #define ADC_OFR4_OFFSET4_18   0x00040000
  #define ADC_OFR4_OFFSET4_19   0x00080000
  #define ADC_OFR4_OFFSET4_20   0x00100000
  #define ADC_OFR4_OFFSET4_21   0x00200000
  #define ADC_OFR4_OFFSET4_22   0x00400000
  #define ADC_OFR4_OFFSET4_23   0x00800000
  #define ADC_OFR4_OFFSET4_24   0x01000000
  #define ADC_OFR4_OFFSET4_25   0x02000000
  #define ADC_OFR4_OFFSET4_CH   0x7C000000	/* ADC Channel selection for the data offset 4 */
  #define ADC_OFR4_OFFSET4_CH_0 0x04000000
  #define ADC_OFR4_OFFSET4_CH_1 0x08000000
  #define ADC_OFR4_OFFSET4_CH_2 0x10000000
  #define ADC_OFR4_OFFSET4_CH_3 0x20000000
  #define ADC_OFR4_OFFSET4_CH_4 0x40000000
  #define ADC_OFR4_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_JDR1       0x0080		/* (RW) ADC injected data register 1 */
#define TOFF_ADC_JDR2       0x0084		/* (RW) ADC injected data register 2 */
#define TOFF_ADC_JDR3       0x0088		/* (RW) ADC injected data register 3 */
#define TOFF_ADC_JDR4       0x008C		/* (RW) ADC injected data register 4 */
#define TOFF_ADC_AWD2CR     0x00A0		/* (RW) ADC  Analog Watchdog 2 Configuration Register */
  #define ADC_AWD2CR_AWD2CH     0x000FFFFF	/* ADC Analog watchdog 2 channel selection */
  #define ADC_AWD2CR_AWD2CH_0   0x00000001
  #define ADC_AWD2CR_AWD2CH_1   0x00000002
  #define ADC_AWD2CR_AWD2CH_2   0x00000004
  #define ADC_AWD2CR_AWD2CH_3   0x00000008
  #define ADC_AWD2CR_AWD2CH_4   0x00000010
  #define ADC_AWD2CR_AWD2CH_5   0x00000020
  #define ADC_AWD2CR_AWD2CH_6   0x00000040
  #define ADC_AWD2CR_AWD2CH_7   0x00000080
  #define ADC_AWD2CR_AWD2CH_8   0x00000100
  #define ADC_AWD2CR_AWD2CH_9   0x00000200
  #define ADC_AWD2CR_AWD2CH_10  0x00000400
  #define ADC_AWD2CR_AWD2CH_11  0x00000800
  #define ADC_AWD2CR_AWD2CH_12  0x00001000
  #define ADC_AWD2CR_AWD2CH_13  0x00002000
  #define ADC_AWD2CR_AWD2CH_14  0x00004000
  #define ADC_AWD2CR_AWD2CH_15  0x00008000
  #define ADC_AWD2CR_AWD2CH_16  0x00010000
  #define ADC_AWD2CR_AWD2CH_17  0x00020000
  #define ADC_AWD2CR_AWD2CH_18  0x00040000
  #define ADC_AWD2CR_AWD2CH_19  0x00080000
#define TOFF_ADC_AWD3CR     0x00A4		/* (RW) ADC  Analog Watchdog 3 Configuration Register */
  #define ADC_AWD3CR_AWD3CH     0x000FFFFF	/* ADC Analog watchdog 2 channel selection */
  #define ADC_AWD3CR_AWD3CH_0   0x00000001
  #define ADC_AWD3CR_AWD3CH_1   0x00000002
  #define ADC_AWD3CR_AWD3CH_2   0x00000004
  #define ADC_AWD3CR_AWD3CH_3   0x00000008
  #define ADC_AWD3CR_AWD3CH_4   0x00000010
  #define ADC_AWD3CR_AWD3CH_5   0x00000020
  #define ADC_AWD3CR_AWD3CH_6   0x00000040
  #define ADC_AWD3CR_AWD3CH_7   0x00000080
  #define ADC_AWD3CR_AWD3CH_8   0x00000100
  #define ADC_AWD3CR_AWD3CH_9   0x00000200
  #define ADC_AWD3CR_AWD3CH_10  0x00000400
  #define ADC_AWD3CR_AWD3CH_11  0x00000800
  #define ADC_AWD3CR_AWD3CH_12  0x00001000
  #define ADC_AWD3CR_AWD3CH_13  0x00002000
  #define ADC_AWD3CR_AWD3CH_14  0x00004000
  #define ADC_AWD3CR_AWD3CH_15  0x00008000
  #define ADC_AWD3CR_AWD3CH_16  0x00010000
  #define ADC_AWD3CR_AWD3CH_17  0x00020000
  #define ADC_AWD3CR_AWD3CH_18  0x00040000
  #define ADC_AWD3CR_AWD3CH_19  0x00080000
#define TOFF_ADC_LTR2       0x00B0		/* (RW) ADC watchdog Lower threshold register 2 */
#define TOFF_ADC_HTR2       0x00B4		/* (RW) ADC watchdog Higher threshold register 2 */
#define TOFF_ADC_LTR3       0x00B8		/* (RW) ADC watchdog Lower threshold register 3 */
#define TOFF_ADC_HTR3       0x00BC		/* (RW) ADC watchdog Higher threshold register 3 */
#define TOFF_ADC_DIFSEL     0x00C0		/* (RW) ADC  Differential Mode Selection Register */
  #define ADC_DIFSEL_DIFSEL     0x000FFFFF	/* ADC differential modes for channels 1 to 18 */
#define TOFF_ADC_CALFACT    0x00C4		/* (RW) ADC  Calibration Factors */
  #define ADC_CALFACT_CALFACT_S      0x000007FF	/* ADC calibration factors in single-ended mode */
  #define ADC_CALFACT_CALFACT_S_0    0x00000001
  #define ADC_CALFACT_CALFACT_S_1    0x00000002
  #define ADC_CALFACT_CALFACT_S_2    0x00000004
  #define ADC_CALFACT_CALFACT_S_3    0x00000008
  #define ADC_CALFACT_CALFACT_S_4    0x00000010
  #define ADC_CALFACT_CALFACT_S_5    0x00000020
  #define ADC_CALFACT_CALFACT_S_6    0x00000040
  #define ADC_CALFACT_CALFACT_S_7    0x00000080
  #define ADC_CALFACT_CALFACT_S_8    0x00000100
  #define ADC_CALFACT_CALFACT_S_9    0x00000200
  #define ADC_CALFACT_CALFACT_S_10   0x00000400
  #define ADC_CALFACT_CALFACT_D      0x07FF0000	/* ADC calibration factors in differential mode */
  #define ADC_CALFACT_CALFACT_D_0    0x00010000
  #define ADC_CALFACT_CALFACT_D_1    0x00020000
  #define ADC_CALFACT_CALFACT_D_2    0x00040000
  #define ADC_CALFACT_CALFACT_D_3    0x00080000
  #define ADC_CALFACT_CALFACT_D_4    0x00100000
  #define ADC_CALFACT_CALFACT_D_5    0x00200000
  #define ADC_CALFACT_CALFACT_D_6    0x00400000
  #define ADC_CALFACT_CALFACT_D_7    0x00800000
  #define ADC_CALFACT_CALFACT_D_8    0x01000000
  #define ADC_CALFACT_CALFACT_D_9    0x02000000
  #define ADC_CALFACT_CALFACT_D_10   0x04000000
#define TOFF_ADC_CALFACT2   0x00C8		/* (RW) ADC  Linearity Calibration Factors */
  #define ADC_CALFACT2_LINCALFACT    0x3FFFFFFF	/* ADC Linearity calibration factors */
  #define ADC_CALFACT2_LINCALFACT_0  0x00000001
  #define ADC_CALFACT2_LINCALFACT_1  0x00000002
  #define ADC_CALFACT2_LINCALFACT_2  0x00000004
  #define ADC_CALFACT2_LINCALFACT_3  0x00000008
  #define ADC_CALFACT2_LINCALFACT_4  0x00000010
  #define ADC_CALFACT2_LINCALFACT_5  0x00000020
  #define ADC_CALFACT2_LINCALFACT_6  0x00000040
  #define ADC_CALFACT2_LINCALFACT_7  0x00000080
  #define ADC_CALFACT2_LINCALFACT_8  0x00000100
  #define ADC_CALFACT2_LINCALFACT_9  0x00000200
  #define ADC_CALFACT2_LINCALFACT_10 0x00000400
  #define ADC_CALFACT2_LINCALFACT_11 0x00000800
  #define ADC_CALFACT2_LINCALFACT_12 0x00001000
  #define ADC_CALFACT2_LINCALFACT_13 0x00002000
  #define ADC_CALFACT2_LINCALFACT_14 0x00004000
  #define ADC_CALFACT2_LINCALFACT_15 0x00008000
  #define ADC_CALFACT2_LINCALFACT_16 0x00010000
  #define ADC_CALFACT2_LINCALFACT_17 0x00020000
  #define ADC_CALFACT2_LINCALFACT_18 0x00040000
  #define ADC_CALFACT2_LINCALFACT_19 0x00080000
  #define ADC_CALFACT2_LINCALFACT_20 0x00100000
  #define ADC_CALFACT2_LINCALFACT_21 0x00200000
  #define ADC_CALFACT2_LINCALFACT_22 0x00400000
  #define ADC_CALFACT2_LINCALFACT_23 0x00800000
  #define ADC_CALFACT2_LINCALFACT_24 0x01000000
  #define ADC_CALFACT2_LINCALFACT_25 0x02000000
  #define ADC_CALFACT2_LINCALFACT_26 0x04000000
  #define ADC_CALFACT2_LINCALFACT_27 0x08000000
  #define ADC_CALFACT2_LINCALFACT_28 0x10000000
  #define ADC_CALFACT2_LINCALFACT_29 0x20000000


#define TADR_ADC12_COMMON_BASE  (D2_AHB1PERIPH_BASE + 0x2300)
#define TADR_ADC3_COMMON_BASE   (D3_AHB1PERIPH_BASE + 0x6300)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC Common status register */
  #define ADC_CSR_ADRDY_MST  0x00000001	/* Master ADC ready */
  #define ADC_CSR_EOSMP_MST  0x00000002	/* End of sampling phase flag of the master ADC */
  #define ADC_CSR_EOC_MST    0x00000004	/* End of regular conversion of the master ADC */
  #define ADC_CSR_EOS_MST    0x00000008	/* End of regular sequence flag of the master ADC */
  #define ADC_CSR_OVR_MST    0x00000010	/* Overrun flag of the master ADC */
  #define ADC_CSR_JEOC_MST   0x00000020	/* End of injected conversion of the master ADC */
  #define ADC_CSR_JEOS_MST   0x00000040	/* End of injected sequence flag of the master ADC */
  #define ADC_CSR_AWD1_MST   0x00000080	/* Analog watchdog 1 flag of the master ADC */
  #define ADC_CSR_AWD2_MST   0x00000100	/* Analog watchdog 2 flag of the master ADC */
  #define ADC_CSR_AWD3_MST   0x00000200	/* Analog watchdog 3 flag of the master ADC */
  #define ADC_CSR_JQOVF_MST  0x00000400	/* Injected context queue overflow flag of the master ADC */
  #define ADC_CSR_ADRDY_SLV  0x00010000	/* Slave ADC ready */
  #define ADC_CSR_EOSMP_SLV  0x00020000	/* End of sampling phase flag of the slave ADC */
  #define ADC_CSR_EOC_SLV    0x00040000	/* End of regular conversion of the slave ADC */
  #define ADC_CSR_EOS_SLV    0x00080000	/* End of regular sequence flag of the slave ADC */
  #define ADC_CSR_OVR_SLV    0x00100000	/* Overrun flag of the slave ADC */
  #define ADC_CSR_JEOC_SLV   0x00200000	/* End of injected conversion of the slave ADC */
  #define ADC_CSR_JEOS_SLV   0x00400000	/* End of injected sequence flag of the slave ADC */
  #define ADC_CSR_AWD1_SLV   0x00800000	/* Analog watchdog 1 flag of the slave ADC */
  #define ADC_CSR_AWD2_SLV   0x01000000	/* Analog watchdog 2 flag of the slave ADC */
  #define ADC_CSR_AWD3_SLV   0x02000000	/* Analog watchdog 3 flag of the slave ADC */
  #define ADC_CSR_JQOVF_SLV  0x04000000	/* Injected context queue overflow flag of the slave ADC */
#define TOFF_ADC_CCR        0x0008		/* (RW) ADC common control register */
  #define ADC_CCR_DUAL       0x0000001F	/* Dual ADC mode selection */
  #define ADC_CCR_DUAL_0     0x00000001
  #define ADC_CCR_DUAL_1     0x00000002
  #define ADC_CCR_DUAL_2     0x00000004
  #define ADC_CCR_DUAL_3     0x00000008
  #define ADC_CCR_DUAL_4     0x00000010
  #define ADC_CCR_DELAY      0x00000F00	/* Delay between 2 sampling phases */
  #define ADC_CCR_DELAY_0    0x00000100
  #define ADC_CCR_DELAY_1    0x00000200
  #define ADC_CCR_DELAY_2    0x00000400
  #define ADC_CCR_DELAY_3    0x00000800
  #define ADC_CCR_DAMDF      0x0000C000	/* Dual ADC mode Data format */
  #define ADC_CCR_DAMDF_0    0x00004000
  #define ADC_CCR_DAMDF_1    0x00008000
  #define ADC_CCR_CKMODE     0x00030000	/* ADC clock mode */
  #define ADC_CCR_CKMODE_0   0x00010000
  #define ADC_CCR_CKMODE_1   0x00020000
  #define ADC_CCR_PRESC      0x003C0000	/* ADC prescaler */
  #define ADC_CCR_PRESC_0    0x00040000
  #define ADC_CCR_PRESC_1    0x00080000
  #define ADC_CCR_PRESC_2    0x00100000
  #define ADC_CCR_PRESC_3    0x00200000
  #define ADC_CCR_VREFEN     0x00400000	/* VREFINT enable */
  #define ADC_CCR_TSEN       0x00800000	/* Temperature sensor enable */
  #define ADC_CCR_VBATEN     0x01000000	/* VBAT enable */
#define TOFF_ADC_CDR        0x000C		/* (RW) ADC common regular data register for dual AND triple modes */
  #define ADC_CDR_RDATA_MST  0x0000FFFF	/* ADC multimode master group regular conversion data */
  #define ADC_CDR_RDATA_SLV  0xFFFF0000	/* ADC multimode slave group regular conversion data */
#define TOFF_ADC_CDR2       0x0010		/* (RW) ADC common regular data register for 32-bit dual mode */


/*
 *  SD HOST INTERFACE
 */
#define TADR_SDMMC1_BASE    (D1_AHB1PERIPH_BASE + 0x7000)
#define TADR_SDMMC2_BASE    (D2_AHB2PERIPH_BASE + 0x2400)
#define TOFF_SDIO_POWER     0x0000		/* (RW) SDIO power control register */
  #define SDMMC_POWER_PWRCTRL   0x00000003	/* PWRCTRL[1:0] bits (Power supply control bits) */
  #define SDMMC_POWER_PWRCTRL_0 0x00000001	/* Bit 0 */
  #define SDMMC_POWER_PWRCTRL_1 0x00000002	/* Bit 1 */
  #define SDMMC_POWER_VSWITCH   0x00000004	/* Voltage switch sequence start */
  #define SDMMC_POWER_VSWITCHEN 0x00000008	/* Voltage switch procedure enable */
  #define SDMMC_POWER_DIRPOL    0x00000010	/* Data and Command direction signals polarity selection */
#define TOFF_SDIO_CLKCR     0x0004		/* (RW) SDI clock control register */
  #define SDMMC_CLKCR_CLKDIV    0x000003FF	/* Clock divide factor */
  #define SDMMC_CLKCR_PWRSAV    0x00001000	/* Power saving configuration bit*/
  #define SDMMC_CLKCR_WIDBUS    0x0000C000	/* WIDBUS[1:0] bits (Wide bus mode enable bit) */
  #define SDMMC_CLKCR_WIDBUS_0  0x00004000
  #define SDMMC_CLKCR_WIDBUS_1  0x00008000
  #define SDMMC_CLKCR_NEGEDGE   0x00010000	/* SDMMC_CK dephasing selection bit */
  #define SDMMC_CLKCR_HWFC_EN   0x00020000	/* HW Flow Control enable */
  #define SDMMC_CLKCR_DDR       0x00040000	/* Data rate signaling selection */
  #define SDMMC_CLKCR_BUSSPEED  0x00080000	/* Bus speed mode selection */
  #define SDMMC_CLKCR_SELCLKRX  0x00300000	/* SELCLKRX[1:0] bits (Receive clock selection) */
  #define SDMMC_CLKCR_SELCLKRX_0 0x00100000
  #define SDMMC_CLKCR_SELCLKRX_1 0x00200000
#define TOFF_SDIO_ARG       0x0008		/* (RW) SDIO argument register */
#define TOFF_SDIO_CMD       0x000C		/* (RW) SDIO command register */
  #define SDMMC_CMD_CMDINDEX    0x0000003F	/* Command Index */
  #define SDMMC_CMD_CMDTRANS    0x00000040	/* CPSM Treats command as a Data Transfer */
  #define SDMMC_CMD_CMDSTOP     0x00000080	/* CPSM Treats command as a Stop */
  #define SDMMC_CMD_WAITRESP    0x00000300	/* WAITRESP[1:0] bits (Wait for response bits) */
  #define SDMMC_CMD_WAITRESP_0  0x00000100
  #define SDMMC_CMD_WAITRESP_1  0x00000200
  #define SDMMC_CMD_WAITINT     0x00000400	/* CPSM Waits for Interrupt Request */
  #define SDMMC_CMD_WAITPEND    0x00000800	/* CPSM Waits for ends of data transfer (CmdPend internal signal) */
  #define SDMMC_CMD_CPSMEN      0x00001000	/* Command path state machine (CPSM) Enable bit */
  #define SDMMC_CMD_DTHOLD      0x00002000	/* Hold new data block transmission and reception in the DPSM */
  #define SDMMC_CMD_BOOTMODE    0x00004000	/* Boot mode */
  #define SDMMC_CMD_BOOTEN      0x00008000	/* Enable Boot mode procedure */
  #define SDMMC_CMD_CMDSUSPEND  0x00010000	/* CPSM Treats command as a Suspend or Resume command */
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
  #define SDMMC_DCTRL_DTMODE    0x0000000C	/* DTMODE[1:0] Data transfer mode selection */
  #define SDMMC_DCTRL_DTMODE_0  0x00000004
  #define SDMMC_DCTRL_DTMODE_1  0x00000008
  #define SDMMC_DCTRL_DBLOCKSIZE    0x000000F0	/* DBLOCKSIZE[3:0] bits (Data block size) */
  #define SDMMC_DCTRL_DBLOCKSIZE_0  0x00000010
  #define SDMMC_DCTRL_DBLOCKSIZE_1  0x00000020
  #define SDMMC_DCTRL_DBLOCKSIZE_2  0x00000040
  #define SDMMC_DCTRL_DBLOCKSIZE_3  0x00000080
  #define SDMMC_DCTRL_RWSTART   0x00000100	/* Read wait start */
  #define SDMMC_DCTRL_RWSTOP    0x00000200	/* Read wait stop */
  #define SDMMC_DCTRL_RWMOD     0x00000400	/* Read wait mode */
  #define SDMMC_DCTRL_SDIOEN    0x00000800	/* SD I/O enable functions */
  #define SDMMC_DCTRL_BOOTACKEN 0x00001000	/* Enable the reception of the Boot Acknowledgment */
  #define SDMMC_DCTRL_FIFORST   0x00002000	/* FIFO reset */
#define TOFF_SDIO_DCOUNT    0x0030		/* (R)  SDIO data counter register */
#define TOFF_SDIO_STA       0x0034		/* (R)  SDIO status register */
  #define SDMMC_STA_CCRCFAIL    0x00000001	/* Command response received (CRC check failed) */
  #define SDMMC_STA_DCRCFAIL    0x00000002	/* Data block sent/received (CRC check failed) */
  #define SDMMC_STA_CTIMEOUT    0x00000004	/* Command response timeout */
  #define SDMMC_STA_DTIMEOUT    0x00000008	/* Data timeout */
  #define SDMMC_STA_TXUNDERR    0x00000010	/* Transmit FIFO underrun error */
  #define SDMMC_STA_RXOVERR     0x00000020	/* Received FIFO overrun error */
  #define SDMMC_STA_CMDREND     0x00000040	/* Command response received (CRC check passed)  */
  #define SDMMC_STA_CMDSENT     0x00000080	/* Command sent (no response required) */
  #define SDMMC_STA_DATAEND     0x00000100	/* Data end (data counter, SDIDCOUNT, is zero)   */
  #define SDMMC_STA_DHOLD       0x00000200	/* Data transfer Hold */
  #define SDMMC_STA_DBCKEND     0x00000400	/* Data block sent/received (CRC check passed)   */
  #define SDMMC_STA_DABORT      0x00000800	/* Data transfer aborted by CMD12 */
  #define SDMMC_STA_DPSMACT     0x00001000	/* Data path state machine active */
  #define SDMMC_STA_CPSMACT     0x00002000	/* Command path state machine active */
  #define SDMMC_STA_TXFIFOHE    0x00004000	/* Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
  #define SDMMC_STA_RXFIFOHF    0x00008000	/* Receive FIFO Half Full: there are at least 8 words in the FIFO */
  #define SDMMC_STA_TXFIFOF     0x00010000	/* Transmit FIFO full */
  #define SDMMC_STA_RXFIFOF     0x00020000	/* Receive FIFO full */
  #define SDMMC_STA_TXFIFOE     0x00040000	/* Transmit FIFO empty */
  #define SDMMC_STA_RXFIFOE     0x00080000	/* Receive FIFO empty */
  #define SDMMC_STA_BUSYD0      0x00100000	/* Inverted value of SDMMC_D0 line (Busy) */
  #define SDMMC_STA_BUSYD0END   0x00200000	/* End of SDMMC_D0 Busy following a CMD response detected */
  #define SDMMC_STA_SDIOIT      0x00400000	/* SDIO interrupt received */
  #define SDMMC_STA_ACKFAIL     0x00800000	/* Boot Acknowledgment received (BootAck check fail) */
  #define SDMMC_STA_ACKTIMEOUT  0x01000000	/* Boot Acknowledgment timeout */
  #define SDMMC_STA_VSWEND      0x02000000	/* Voltage switch critical timing section completion */
  #define SDMMC_STA_CKSTOP      0x04000000	/* SDMMC_CK stopped in Voltage switch procedure */
  #define SDMMC_STA_IDMATE      0x08000000	/* IDMA transfer error */
  #define SDMMC_STA_IDMABTC     0x10000000	/* IDMA buffer transfer complete */
#define TOFF_SDIO_ICR       0x0038		/* (RW) SDIO interrupt clear register */
  #define SDMMC_ICR_CCRCFAILC   0x00000001	/* CCRCFAIL flag clear bit */
  #define SDMMC_ICR_DCRCFAILC   0x00000002	/* DCRCFAIL flag clear bit */
  #define SDMMC_ICR_CTIMEOUTC   0x00000004	/* CTIMEOUT flag clear bit */
  #define SDMMC_ICR_DTIMEOUTC   0x00000008	/* DTIMEOUT flag clear bit */
  #define SDMMC_ICR_TXUNDERRC   0x00000010	/* TXUNDERR flag clear bit */
  #define SDMMC_ICR_RXOVERRC    0x00000020	/* RXOVERR flag clear bit */
  #define SDMMC_ICR_CMDRENDC    0x00000040	/* CMDREND flag clear bit */
  #define SDMMC_ICR_CMDSENTC    0x00000080	/* CMDSENT flag clear bit */
  #define SDMMC_ICR_DATAENDC    0x00000100	/* DATAEND flag clear bit */
  #define SDMMC_ICR_DHOLDC      0x00000200	/* DHOLD flag clear bit */
  #define SDMMC_ICR_DBCKENDC    0x00000400	/* DBCKEND flag clear bit */
  #define SDMMC_ICR_DABORTC     0x00000800	/* DABORTC flag clear bit */
  #define SDMMC_ICR_BUSYD0ENDC  0x00200000	/* BUSYD0ENDC flag clear bit */
  #define SDMMC_ICR_SDIOITC     0x00400000	/* SDIOIT flag clear bit */
  #define SDMMC_ICR_ACKFAILC    0x00800000	/* ACKFAILC flag clear bit */
  #define SDMMC_ICR_ACKTIMEOUTC 0x01000000	/* ACKTIMEOUTC flag clear bit */
  #define SDMMC_ICR_VSWENDC     0x02000000	/* VSWENDC flag clear bit */
  #define SDMMC_ICR_CKSTOPC     0x04000000	/* CKSTOPC flag clear bit */
  #define SDMMC_ICR_IDMATEC     0x08000000	/* IDMATEC flag clear bit */
  #define SDMMC_ICR_IDMABTCC    0x10000000	/* IDMABTCC flag clear bit */
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
  #define SDMMC_MASK_DHOLDIE    0x00000200	/* Data Hold Interrupt Enable */
  #define SDMMC_MASK_DBCKENDIE  0x00000400	/* Data Block End Interrupt Enable */
  #define SDMMC_MASK_DABORTIE   0x00000800	/* Data transfer aborted interrupt enable */
  #define SDMMC_MASK_TXFIFOHEIE 0x00004000	/* Tx FIFO Half Empty interrupt Enable */
  #define SDMMC_MASK_RXFIFOHFIE 0x00008000	/* Rx FIFO Half Full interrupt Enable */
  #define SDMMC_MASK_RXFIFOFIE  0x00020000	/* Rx FIFO Full interrupt Enable */
  #define SDMMC_MASK_TXFIFOEIE  0x00040000	/* Tx FIFO Empty interrupt Enable */
  #define SDMMC_MASK_BUSYD0ENDIE 0x00200000	/* BUSYD0ENDIE interrupt Enable */
  #define SDMMC_MASK_SDIOITIE   0x00400000	/* SDMMC Mode Interrupt Received interrupt Enable */
  #define SDMMC_MASK_ACKFAILIE  0x00800000	/* Acknowledgment Fail Interrupt Enable */
  #define SDMMC_MASK_ACKTIMEOUTIE 0x01000000	/* Acknowledgment timeout Interrupt Enable */
  #define SDMMC_MASK_VSWENDIE   0x02000000	/* Voltage switch critical timing section completion Interrupt Enable */
  #define SDMMC_MASK_CKSTOPIE   0x04000000	/* Voltage Switch clock stopped Interrupt Enable */
  #define SDMMC_MASK_IDMABTCIE  0x10000000	/* IDMA buffer transfer complete Interrupt Enable */
#define TOFF_SDIO_ACKTIME   0x0040		/* (RW) SDMMC Acknowledgement timer register */
#define TOFF_SDIO_IDMACTRL  0x0044		/* (RW) SDMMC DMA control register */
  #define SDMMC_IDMA_IDMAEN     0x00000001	/* Enable the internal DMA of the SDMMC peripheral */
  #define SDMMC_IDMA_IDMABMODE  0x00000002	/* Enable double buffer mode for IDMA */
  #define SDMMC_IDMA_IDMABACT   0x00000004	/* Uses buffer 1 when double buffer mode is selected */
#define TOFF_SDIO_IDMABSIZE 0x0054		/* (RW) SDMMC DMA buffer size register */
  #define SDMMC_IDMABSIZE_IDMABNDT 0x00001FE0	/* Number of transfers per buffer */
#define TOFF_SDIO_IDMABASE0 0x0058		/* (RW) SDMMC DMA buffer 0 base address register */
#define TOFF_SDIO_IDMABASE1 0x005C		/* (RW) SDMMC DMA buffer 1 base address register */
#define TOFF_SDIO_FIFO      0x0080		/* (RW) SDIO data FIFO register */
#define TOFF_SDIO_IPVR      0x03FC		/* (RW) SDMMC data FIFO register */


/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (D3_APB1PERIPH_BASE + 0x0400)
#define TOFF_SYSCFG_PMCR    0x0004		/* (RW) SYSCFG peripheral mode configuration register */
  #define SYSCFG_PMCR_I2C1_FMP      0x00000001	/* I2C1 Fast mode plus */
  #define SYSCFG_PMCR_I2C2_FMP      0x00000002	/* I2C2 Fast mode plus */
  #define SYSCFG_PMCR_I2C3_FMP      0x00000004	/* I2C3 Fast mode plus */
  #define SYSCFG_PMCR_I2C4_FMP      0x00000008	/* I2C4 Fast mode plus */
  #define SYSCFG_PMCR_I2C_PB6_FMP   0x00000010	/* I2C PB6 Fast mode plus */
  #define SYSCFG_PMCR_I2C_PB7_FMP   0x00000020	/* I2C PB7 Fast mode plus */
  #define SYSCFG_PMCR_I2C_PB8_FMP   0x00000040	/* I2C PB8 Fast mode plus */
  #define SYSCFG_PMCR_I2C_PB9_FMP   0x00000080	/* I2C PB9 Fast mode plus */
  #define SYSCFG_PMCR_BOOSTEN       0x00000100	/* I/O analog switch voltage booster enable */
  #define SYSCFG_PMCR_BOOSTVDDSEL   0x00000200	/* Analog switch supply source selection : VDD/VDDA */
  #define SYSCFG_PMCR_EPIS_SEL      0x00E00000	/* Ethernet PHY Interface Selection */
  #define SYSCFG_PMCR_EPIS_SEL_0    0x00200000
  #define SYSCFG_PMCR_EPIS_SEL_1    0x00400000
  #define SYSCFG_PMCR_EPIS_SEL_2    0x00800000
  #define SYSCFG_PMCR_PA0SO         0x01000000	/* PA0 Switch Open */
  #define SYSCFG_PMCR_PA1SO         0x02000000	/* PA1 Switch Open */
  #define SYSCFG_PMCR_PC2SO         0x04000000	/* PC2 Switch Open */
  #define SYSCFG_PMCR_PC3SO         0x08000000	/* PC3 Switch Open */
#define TOFF_SYSCFG_EXTICR1 0x0008		/* (RW) SYSCFG external interrupt configuration registers 0 */
  #define SYSCFG_EXTICR1_EXTI0      0x0000000F	/* EXTI 0 configuration */
  #define SYSCFG_EXTICR1_EXTI1      0x000000F0	/* EXTI 1 configuration */
  #define SYSCFG_EXTICR1_EXTI2      0x00000F00	/* EXTI 2 configuration */
  #define SYSCFG_EXTICR1_EXTI3      0x0000F000	/* EXTI 3 configuration */
	/* EXTI0 configuration */
  #define SYSCFG_EXTICR1_EXTI0_PA   0x00000000	/* PA[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PB   0x00000001	/* PB[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PC   0x00000002	/* PC[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PD   0x00000003	/* PD[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PE   0x00000004	/* PE[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PF   0x00000005	/* PF[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PG   0x00000006	/* PG[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PH   0x00000007	/* PH[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PI   0x00000008	/* PI[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PJ   0x00000009	/* PJ[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PK   0x0000000A	/* PK[0] pin */
	/* EXTI1 configuration */
  #define SYSCFG_EXTICR1_EXTI1_PA   0x00000000	/* PA[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PB   0x00000010	/* PB[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PC   0x00000020	/* PC[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PD   0x00000030	/* PD[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PE   0x00000040	/* PE[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PF   0x00000050	/* PF[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PG   0x00000060	/* PG[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PH   0x00000070	/* PH[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PI   0x00000080	/* PI[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PJ   0x00000090	/* PJ[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PK   0x000000A0	/* PK[1] pin */
	/* EXTI2 configuration */
  #define SYSCFG_EXTICR1_EXTI2_PA   0x00000000	/* PA[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PB   0x00000100	/* PB[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PC   0x00000200	/* PC[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PD   0x00000300	/* PD[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PE   0x00000400	/* PE[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PF   0x00000500	/* PF[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PG   0x00000600	/* PG[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PH   0x00000700	/* PH[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PI   0x00000800	/* PI[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PJ   0x00000900	/* PJ[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PK   0x00000A00	/* PK[2] pin */
	/* EXTI3 configuration */
  #define SYSCFG_EXTICR1_EXTI3_PA   0x00000000	/* PA[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PB   0x00001000	/* PB[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PC   0x00002000	/* PC[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PD   0x00003000	/* PD[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PE   0x00004000	/* PE[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PF   0x00005000	/* PF[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PG   0x00006000	/* PG[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PH   0x00007000	/* PH[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PI   0x00008000	/* PI[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PJ   0x00009000	/* PJ[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PK   0x0000A000	/* PK[3] pin */
#define TOFF_SYSCFG_EXTICR2 0x000C		/* (RW) SYSCFG external interrupt configuration registers 1 */
  #define SYSCFG_EXTICR2_EXTI4      0x0000000F	/* EXTI 4 configuration */
  #define SYSCFG_EXTICR2_EXTI5      0x000000F0	/* EXTI 5 configuration */
  #define SYSCFG_EXTICR2_EXTI6      0x00000F00	/* EXTI 6 configuration */
  #define SYSCFG_EXTICR2_EXTI7      0x0000F000	/* EXTI 7 configuration */
	/* EXTI4 configuration */
  #define SYSCFG_EXTICR2_EXTI4_PA   0x00000000	/* PA[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PB   0x00000001	/* PB[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PC   0x00000002	/* PC[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PD   0x00000003	/* PD[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PE   0x00000004	/* PE[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PF   0x00000005	/* PF[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PG   0x00000006	/* PG[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PH   0x00000007	/* PH[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PI   0x00000008	/* PI[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PJ   0x00000009	/* PJ[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PK   0x0000000A	/* PK[4] pin */
	/* EXTI5 configuration */
  #define SYSCFG_EXTICR2_EXTI5_PA   0x00000000	/* PA[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PB   0x00000010	/* PB[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PC   0x00000020	/* PC[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PD   0x00000030	/* PD[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PE   0x00000040	/* PE[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PF   0x00000050	/* PF[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PG   0x00000060	/* PG[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PH   0x00000070	/* PH[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PI   0x00000080	/* PI[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PJ   0x00000090	/* PJ[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PK   0x000000A0	/* PK[5] pin */
	/* EXTI6 configuration */
  #define SYSCFG_EXTICR2_EXTI6_PA   0x00000000	/* PA[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PB   0x00000100	/* PB[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PC   0x00000200	/* PC[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PD   0x00000300	/* PD[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PE   0x00000400	/* PE[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PF   0x00000500	/* PF[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PG   0x00000600	/* PG[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PH   0x00000700	/* PH[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PI   0x00000800	/* PI[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PJ   0x00000900	/* PJ[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PK   0x00000A00	/* PK[6] pin */
	/* EXTI7 configuration */
  #define SYSCFG_EXTICR2_EXTI7_PA   0x00000000	/* PA[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PB   0x00001000	/* PB[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PC   0x00002000	/* PC[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PD   0x00003000	/* PD[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PE   0x00004000	/* PE[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PF   0x00005000	/* PF[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PG   0x00006000	/* PG[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PH   0x00007000	/* PH[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PI   0x00008000	/* PI[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PJ   0x00009000	/* PJ[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PK   0x0000A000	/* PK[7] pin */
#define TOFF_SYSCFG_EXTICR3 0x0010		/* (RW) SYSCFG external interrupt configuration registers 2 */
  #define SYSCFG_EXTICR3_EXTI8      0x0000000F	/* EXTI 8 configuration */
  #define SYSCFG_EXTICR3_EXTI9      0x000000F0	/* EXTI 9 configuration */
  #define SYSCFG_EXTICR3_EXTI10     0x00000F00	/* EXTI 10 configuration */
  #define SYSCFG_EXTICR3_EXTI11     0x0000F000	/* EXTI 11 configuration */
	/* EXTI8 configuration */
  #define SYSCFG_EXTICR3_EXTI8_PA   0x00000000	/* PA[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PB   0x00000001	/* PB[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PC   0x00000002	/* PC[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PD   0x00000003	/* PD[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PE   0x00000004	/* PE[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PF   0x00000005	/* PF[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PG   0x00000006	/* PG[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PH   0x00000007	/* PH[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PI   0x00000008	/* PI[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PJ   0x00000009	/* PJ[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PK   0x0000000A	/* PK[8] pin */
	/* EXTI9 configuration */
  #define SYSCFG_EXTICR3_EXTI9_PA   0x00000000	/* PA[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PB   0x00000010	/* PB[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PC   0x00000020	/* PC[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PD   0x00000030	/* PD[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PE   0x00000040	/* PE[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PF   0x00000050	/* PF[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PG   0x00000060	/* PG[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PH   0x00000070	/* PH[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PI   0x00000080	/* PI[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PJ   0x00000090	/* PJ[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PK   0x000000A0	/* PK[9] pin */
	/* EXTI10 configuration */
  #define SYSCFG_EXTICR3_EXTI10_PA  0x00000000	/* PA[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PB  0x00000100	/* PB[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PC  0x00000200	/* PC[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PD  0x00000300	/* PD[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PE  0x00000400	/* PE[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PF  0x00000500	/* PF[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PG  0x00000600	/* PG[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PH  0x00000700	/* PH[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PI  0x00000800	/* PI[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PJ  0x00000900	/* PJ[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PK  0x00000A00	/* PK[10] pin */
	/* EXTI11 configuration */
  #define SYSCFG_EXTICR3_EXTI11_PA  0x00000000	/* PA[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PB  0x00001000	/* PB[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PC  0x00002000	/* PC[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PD  0x00003000	/* PD[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PE  0x00004000	/* PE[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PF  0x00005000	/* PF[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PG  0x00006000	/* PG[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PH  0x00007000	/* PH[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PI  0x00008000	/* PI[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PJ  0x00009000	/* PJ[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PK  0x0000A000	/* PK[11] pin */
#define TOFF_SYSCFG_EXTICR4 0x0014		/* (RW) SYSCFG external interrupt configuration registers 3 */
  #define SYSCFG_EXTICR4_EXTI12     0x0000000F	/* EXTI 12 configuration */
  #define SYSCFG_EXTICR4_EXTI13     0x000000F0	/* EXTI 13 configuration */
  #define SYSCFG_EXTICR4_EXTI14     0x00000F00	/* EXTI 14 configuration */
  #define SYSCFG_EXTICR4_EXTI15     0x0000F000	/* EXTI 15 configuration */
	/* EXTI12 configuration */
  #define SYSCFG_EXTICR4_EXTI12_PA  0x00000000	/* PA[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PB  0x00000001	/* PB[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PC  0x00000002	/* PC[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PD  0x00000003	/* PD[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PE  0x00000004	/* PE[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PF  0x00000005	/* PF[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PG  0x00000006	/* PG[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PH  0x00000007	/* PH[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PI  0x00000008	/* PI[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PJ  0x00000009	/* PJ[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PK  0x0000000A	/* PK[12] pin */
	/* EXTI13 configuration */
  #define SYSCFG_EXTICR4_EXTI13_PA  0x00000000	/* PA[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PB  0x00000010	/* PB[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PC  0x00000020	/* PC[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PD  0x00000030	/* PD[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PE  0x00000040	/* PE[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PF  0x00000050	/* PF[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PG  0x00000060	/* PG[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PH  0x00000070	/* PH[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PI  0x00000080	/* PI[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PJ  0x00000090	/* PJ[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PK  0x000000A0	/* PK[13] pin */
	/* EXTI14 configuration */
  #define SYSCFG_EXTICR4_EXTI14_PA  0x00000000	/* PA[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PB  0x00000100	/* PB[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PC  0x00000200	/* PC[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PD  0x00000300	/* PD[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PE  0x00000400	/* PE[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PF  0x00000500	/* PF[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PG  0x00000600	/* PG[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PH  0x00000700	/* PH[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PI  0x00000800	/* PI[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PJ  0x00000900	/* PJ[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PK  0x00000A00	/* PK[14] pin */
	/* EXTI15 configuration */
  #define SYSCFG_EXTICR4_EXTI15_PA  0x00000000	/* PA[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PB  0x00001000	/* PB[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PC  0x00002000	/* PC[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PD  0x00003000	/* PD[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PE  0x00004000	/* PE[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PF  0x00005000	/* PF[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PG  0x00006000	/* PG[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PH  0x00007000	/* PH[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PI  0x00008000	/* PI[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PJ  0x00009000	/* PJ[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PK  0x0000A000	/* PK[15] pin */
#define TOFF_SYSCFG_CFGR    0x0018		/* (RW) SYSCFG configuration registers */
  #define SYSCFG_CFGR_PVDL   0x00000004	/* PVD lock enable bit */
  #define SYSCFG_CFGR_FLASHL 0x00000008	/* FLASH double ECC error lock bit */
  #define SYSCFG_CFGR_CM7L   0x00000040	/* Cortex-M7 LOCKUP (Hardfault) output enable bit */
  #define SYSCFG_CFGR_BKRAML 0x00000080	/* Backup SRAM double ECC error lock bit */
  #define SYSCFG_CFGR_SRAM4L 0x00000200	/* SRAM4 double ECC error lock bit */
  #define SYSCFG_CFGR_SRAM3L 0x00000400	/* SRAM3 double ECC error lock bit */
  #define SYSCFG_CFGR_SRAM2L 0x00000800	/* SRAM2 double ECC error lock bit */
  #define SYSCFG_CFGR_SRAM1L 0x00001000	/* SRAM1 double ECC error lock bit */
  #define SYSCFG_CFGR_DTCML  0x00002000	/* DTCM double ECC error lock bit */
  #define SYSCFG_CFGR_ITCML  0x00004000	/* ITCM double ECC error lock bit */
  #define SYSCFG_CFGR_AXISRAML 0x00008000	/* AXISRAM double ECC error lock bit */
#define TOFF_SYSCFG_CCCSR   0x0020		/* (RW) SYSCFG compensation cell control/status register */
  #define SYSCFG_CCCSR_EN    0x00000001	/* I/O compensation cell enable */
  #define SYSCFG_CCCSR_CS    0x00000002	/* I/O compensation cell code selection */
  #define SYSCFG_CCCSR_READY 0x00000100	/* I/O compensation cell ready flag */
  #define SYSCFG_CCCSR_HSLV  0x00010000	/* High-speed at low-voltage */
#define TOFF_SYSCFG_CCVR    0x0024		/* (RW) SYSCFG compensation cell value register */
  #define SYSCFG_CCVR_NCV    0x0000000F	/* NMOS compensation value */
  #define SYSCFG_CCVR_PCV    0x000000F0	/* PMOS compensation value */
#define TOFF_SYSCFG_CCCR    0x0028		/* (RW) SYSCFG compensation cell code register */
  #define SYSCFG_CCCR_NCC    0x0000000F	/* NMOS compensation code */
  #define SYSCFG_CCCR_PCC    0x000000F0	/* PMOS compensation code */
#define TOFF_SYSCFG_PWRCR   0x002C		/* (RW) PWR control register */
  #define SYSCFG_PWRCR_ODEN  0x00000001	/* PWR overdrive enable */
#define TOFF_SYSCFG_PKGR    0x0124		/* (RW) SYSCFG package register */
  #define SYSCFG_PKGR_PKG    0x0000000F	/* Package type */
#define TOFF_SYSCFG_UR0     0x0300		/* (RW) SYSCFG user register 0 */
#define TOFF_SYSCFG_UR1     0x0304		/* (RW) SYSCFG user register 1 */
#define TOFF_SYSCFG_UR2     0x0308		/* (RW) SYSCFG user register 2 */
#define TOFF_SYSCFG_UR3     0x030C		/* (RW) SYSCFG user register 3 */
#define TOFF_SYSCFG_UR4     0x0310		/* (RW) SYSCFG user register 4 */
#define TOFF_SYSCFG_UR5     0x0314		/* (RW) SYSCFG user register 5 */
#define TOFF_SYSCFG_UR6     0x0318		/* (RW) SYSCFG user register 6 */
#define TOFF_SYSCFG_UR7     0x031C		/* (RW) SYSCFG user register 7 */
#define TOFF_SYSCFG_UR8     0x0320		/* (RW) SYSCFG user register 8 */
#define TOFF_SYSCFG_UR9     0x0324		/* (RW) SYSCFG user register 9 */
#define TOFF_SYSCFG_UR10    0x0328		/* (RW) SYSCFG user register 10 */
#define TOFF_SYSCFG_UR11    0x032C		/* (RW) SYSCFG user register 11 */
#define TOFF_SYSCFG_UR12    0x0330		/* (RW) SYSCFG user register 12 */
#define TOFF_SYSCFG_UR13    0x0334		/* (RW) SYSCFG user register 13 */
#define TOFF_SYSCFG_UR14    0x0338		/* (RW) SYSCFG user register 14 */
#define TOFF_SYSCFG_UR15    0x033C		/* (RW) SYSCFG user register 15 */
#define TOFF_SYSCFG_UR16    0x0340		/* (RW) SYSCFG user register 16 */
#define TOFF_SYSCFG_UR17    0x0344		/* (RW) SYSCFG user register 17 */


/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (D3_APB1PERIPH_BASE + 0x0000)
#define TADR_EXTI_D1_BASE   (TADR_EXTI_BASE + 0x0080)
#define TADR_EXTI_D2_BASE   (TADR_EXTI_BASE + 0x00C0)
#define TOFF_EXTI_RTSR1     0x0000		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR1_TR      0x003FFFFF	/* Rising trigger event configuration bit */
  #define EXTI_RTSR1_TR0     0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR1_TR1     0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR1_TR2     0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR1_TR3     0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR1_TR4     0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR1_TR5     0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR1_TR6     0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR1_TR7     0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR1_TR8     0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR1_TR9     0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR1_TR10    0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR1_TR11    0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR1_TR12    0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR1_TR13    0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR1_TR14    0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR1_TR15    0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR1_TR16    0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR1_TR17    0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR1_TR18    0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR1_TR19    0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR1_TR20    0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR1_TR21    0x00200000	/* Rising trigger event configuration bit of line 21 */
#define TOFF_EXTI_FTSR1     0x0004		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR1_TR      0x003FFFFF	/* Falling trigger event configuration bit */
  #define EXTI_FTSR1_TR0     0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR1_TR1     0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR1_TR2     0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR1_TR3     0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR1_TR4     0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR1_TR5     0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR1_TR6     0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR1_TR7     0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR1_TR8     0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR1_TR9     0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR1_TR10    0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR1_TR11    0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR1_TR12    0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR1_TR13    0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR1_TR14    0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR1_TR15    0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR1_TR16    0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR1_TR17    0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR1_TR18    0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR1_TR19    0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR1_TR20    0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR1_TR21    0x00200000	/* Falling trigger event configuration bit of line 21 */
#define TOFF_EXTI_SWIER1    0x0008		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER1_SWIER0 0x00000001	/* Software Interrupt on line 0 */
  #define EXTI_SWIER1_SWIER1 0x00000002	/* Software Interrupt on line 1 */
  #define EXTI_SWIER1_SWIER2 0x00000004	/* Software Interrupt on line 2 */
  #define EXTI_SWIER1_SWIER3 0x00000008	/* Software Interrupt on line 3 */
  #define EXTI_SWIER1_SWIER4 0x00000010	/* Software Interrupt on line 4 */
  #define EXTI_SWIER1_SWIER5 0x00000020	/* Software Interrupt on line 5 */
  #define EXTI_SWIER1_SWIER6 0x00000040	/* Software Interrupt on line 6 */
  #define EXTI_SWIER1_SWIER7 0x00000080	/* Software Interrupt on line 7 */
  #define EXTI_SWIER1_SWIER8 0x00000100	/* Software Interrupt on line 8 */
  #define EXTI_SWIER1_SWIER9 0x00000200	/* Software Interrupt on line 9 */
  #define EXTI_SWIER1_SWIER10 0x00000400	/* Software Interrupt on line 10 */
  #define EXTI_SWIER1_SWIER11 0x00000800	/* Software Interrupt on line 11 */
  #define EXTI_SWIER1_SWIER12 0x00001000	/* Software Interrupt on line 12 */
  #define EXTI_SWIER1_SWIER13 0x00002000	/* Software Interrupt on line 13 */
  #define EXTI_SWIER1_SWIER14 0x00004000	/* Software Interrupt on line 14 */
  #define EXTI_SWIER1_SWIER15 0x00008000	/* Software Interrupt on line 15 */
  #define EXTI_SWIER1_SWIER16 0x00010000	/* Software Interrupt on line 16 */
  #define EXTI_SWIER1_SWIER17 0x00020000	/* Software Interrupt on line 17 */
  #define EXTI_SWIER1_SWIER18 0x00040000	/* Software Interrupt on line 18 */
  #define EXTI_SWIER1_SWIER19 0x00080000	/* Software Interrupt on line 19 */
  #define EXTI_SWIER1_SWIER20 0x00100000	/* Software Interrupt on line 20 */
  #define EXTI_SWIER1_SWIER21 0x00200000	/* Software Interrupt on line 21 */
#define TOFF_EXTI_D3PMR1    0x000C		/* (RW) EXTI D3 Pending mask register, (same register as to SRDPMR1) */
  #define EXTI_D3PMR1_MR0    0x00000001	/* Pending Mask Event for line 0  */
  #define EXTI_D3PMR1_MR1    0x00000002	/* Pending Mask Event for line 1  */
  #define EXTI_D3PMR1_MR2    0x00000004	/* Pending Mask Event for line 2  */
  #define EXTI_D3PMR1_MR3    0x00000008	/* Pending Mask Event for line 3  */
  #define EXTI_D3PMR1_MR4    0x00000010	/* Pending Mask Event for line 4  */
  #define EXTI_D3PMR1_MR5    0x00000020	/* Pending Mask Event for line 5  */
  #define EXTI_D3PMR1_MR6    0x00000040	/* Pending Mask Event for line 6  */
  #define EXTI_D3PMR1_MR7    0x00000080	/* Pending Mask Event for line 7  */
  #define EXTI_D3PMR1_MR8    0x00000100	/* Pending Mask Event for line 8  */
  #define EXTI_D3PMR1_MR9    0x00000200	/* Pending Mask Event for line 9  */
  #define EXTI_D3PMR1_MR10   0x00000400	/* Pending Mask Event for line 10 */
  #define EXTI_D3PMR1_MR11   0x00000800	/* Pending Mask Event for line 11 */
  #define EXTI_D3PMR1_MR12   0x00001000	/* Pending Mask Event for line 12 */
  #define EXTI_D3PMR1_MR13   0x00002000	/* Pending Mask Event for line 13 */
  #define EXTI_D3PMR1_MR14   0x00004000	/* Pending Mask Event for line 14 */
  #define EXTI_D3PMR1_MR15   0x00008000	/* Pending Mask Event for line 15 */
  #define EXTI_D3PMR1_MR19   0x00080000	/* Pending Mask Event for line 19 */
  #define EXTI_D3PMR1_MR20   0x00100000	/* Pending Mask Event for line 20 */
  #define EXTI_D3PMR1_MR21   0x00200000	/* Pending Mask Event for line 21 */
  #define EXTI_D3PMR1_MR25   0x01000000	/* Pending Mask Event for line 25 */
#define TOFF_EXTI_D3PCR1L   0x0010		/* (RW) EXTI D3 Pending clear selection register low, (same register as to SRDPCR1L) */
  #define EXTI_D3PCR1L_PCS0  0x00000003	/* D3 Pending request clear input signal selection on line 0 */
  #define EXTI_D3PCR1L_PCS1  0x000000C0	/* D3 Pending request clear input signal selection on line 1 */
  #define EXTI_D3PCR1L_PCS2  0x00000030	/* D3 Pending request clear input signal selection on line 2 */
  #define EXTI_D3PCR1L_PCS3  0x000000C0	/* D3 Pending request clear input signal selection on line 3 */
  #define EXTI_D3PCR1L_PCS4  0x00000300	/* D3 Pending request clear input signal selection on line 4 */
  #define EXTI_D3PCR1L_PCS5  0x00000C00	/* D3 Pending request clear input signal selection on line 5 */
  #define EXTI_D3PCR1L_PCS6  0x00003000	/* D3 Pending request clear input signal selection on line 6 */
  #define EXTI_D3PCR1L_PCS7  0x0000C000	/* D3 Pending request clear input signal selection on line 7 */
  #define EXTI_D3PCR1L_PCS8  0x00030000	/* D3 Pending request clear input signal selection on line 8 */
  #define EXTI_D3PCR1L_PCS9  0x000C0000	/* D3 Pending request clear input signal selection on line 9 */
  #define EXTI_D3PCR1L_PCS10 0x00300000	/* D3 Pending request clear input signal selection on line 10*/
  #define EXTI_D3PCR1L_PCS11 0x00C00000	/* D3 Pending request clear input signal selection on line 11*/
  #define EXTI_D3PCR1L_PCS12 0x03000000	/* D3 Pending request clear input signal selection on line 12*/
  #define EXTI_D3PCR1L_PCS13 0x0C000000	/* D3 Pending request clear input signal selection on line 13*/
  #define EXTI_D3PCR1L_PCS14 0x30000000	/* D3 Pending request clear input signal selection on line 14*/
  #define EXTI_D3PCR1L_PCS15 0xC0000000	/* D3 Pending request clear input signal selection on line 15*/
#define TOFF_EXTI_D3PCR1H   0x0014		/* (RW) EXTI D3 Pending clear selection register High, (same register as to SRDPCR1H) */
  #define EXTI_D3PCR1H_PCS19 0x000000C0	/* D3 Pending request clear input signal selection on line 19 */
  #define EXTI_D3PCR1H_PCS20 0x00000300	/* D3 Pending request clear input signal selection on line 20 */
  #define EXTI_D3PCR1H_PCS21 0x00000C00	/* D3 Pending request clear input signal selection on line 21 */
  #define EXTI_D3PCR1H_PCS25 0x000C0000	/* D3 Pending request clear input signal selection on line 25 */
#define TOFF_EXTI_RTSR2     0x0020		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR2_TR      0x000A0000	/* Rising trigger event configuration bit */
  #define EXTI_RTSR2_TR49    0x00020000	/* Rising trigger event configuration bit of line 49 */
  #define EXTI_RTSR2_TR51    0x00080000	/* Rising trigger event configuration bit of line 51 */
#define TOFF_EXTI_FTSR2     0x0024		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR2_TR      0x000A0000	/* Falling trigger event configuration bit */
  #define EXTI_FTSR2_TR49    0x00020000	/* Falling trigger event configuration bit of line 49 */
  #define EXTI_FTSR2_TR51    0x00080000	/* Falling trigger event configuration bit of line 51 */
#define TOFF_EXTI_SWIER2    0x0028		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER2_SWIER49 0x00020000	/* Software Interrupt on line 49 */
  #define EXTI_SWIER2_SWIER51 0x00080000	/* Software Interrupt on line 51 */
#define TOFF_EXTI_D3PMR2    0x002C		/* (RW) EXTI D3 Pending mask register, (same register as to SRDPMR2) */
  #define EXTI_D3PMR2_MR34   0x00000004	/* Pending Mask Event for line 34  */
  #define EXTI_D3PMR2_MR35   0x00000008	/* Pending Mask Event for line 35  */
  #define EXTI_D3PMR2_MR41   0x00000200	/* Pending Mask Event for line 41  */
  #define EXTI_D3PMR2_MR48   0x00010000	/* Pending Mask Event for line 48  */
  #define EXTI_D3PMR2_MR49   0x00020000	/* Pending Mask Event for line 49  */
  #define EXTI_D3PMR2_MR50   0x00040000	/* Pending Mask Event for line 50  */
  #define EXTI_D3PMR2_MR51   0x00080000	/* Pending Mask Event for line 51  */
  #define EXTI_D3PMR2_MR52   0x00100000	/* Pending Mask Event for line 52  */
  #define EXTI_D3PMR2_MR53   0x00200000	/* Pending Mask Event for line 53  */
#define TOFF_EXTI_D3PCR2L   0x0030		/* (RW) EXTI D3 Pending clear selection register low, (same register as to SRDPCR2L) */
  #define EXTI_D3PCR2L_PCS34 0x00000030	/* D3 Pending request clear input signal selection on line 34 */
  #define EXTI_D3PCR2L_PCS35 0x000000C0	/* D3 Pending request clear input signal selection on line 35 */
  #define EXTI_D3PCR2L_PCS41 0x000C0000	/* D3 Pending request clear input signal selection on line 41 */
#define TOFF_EXTI_D3PCR2H   0x0034		/* (RW) EXTI D3 Pending clear selection register High, (same register as to SRDPCR2H) */
  #define EXTI_D3PCR2H_PCS48 0x00000003	/* D3 Pending request clear input signal selection on line 48 */
  #define EXTI_D3PCR2H_PCS49 0x0000000C	/* D3 Pending request clear input signal selection on line 49 */
  #define EXTI_D3PCR2H_PCS50 0x00000030	/* D3 Pending request clear input signal selection on line 50 */
  #define EXTI_D3PCR2H_PCS51 0x000000C0	/* D3 Pending request clear input signal selection on line 51 */
  #define EXTI_D3PCR2H_PCS52 0x00000300	/* D3 Pending request clear input signal selection on line 52 */
  #define EXTI_D3PCR2H_PCS53 0x00000C00	/* D3 Pending request clear input signal selection on line 53 */
#define TOFF_EXTI_RTSR3     0x0040		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR3_TR      0x00740000	/* Rising trigger event configuration bit */
  #define EXTI_RTSR3_TR82    0x00040000	/* Rising trigger event configuration bit of line 82 */
  #define EXTI_RTSR3_TR84    0x00100000	/* Rising trigger event configuration bit of line 84 */
  #define EXTI_RTSR3_TR85    0x00200000	/* Rising trigger event configuration bit of line 85 */
  #define EXTI_RTSR3_TR86    0x00400000	/* Rising trigger event configuration bit of line 86 */
#define TOFF_EXTI_FTSR3     0x0044		/* (RW) EXTI Falling trigger selection register */
 #define EXTI_FTSR3_TR       0x00740000	/* Falling trigger event configuration bit */
  #define EXTI_FTSR3_TR82    0x00040000	/* Falling trigger event configuration bit of line 82 */
  #define EXTI_FTSR3_TR84    0x00100000	/* Falling trigger event configuration bit of line 84 */
  #define EXTI_FTSR3_TR85    0x00200000	/* Falling trigger event configuration bit of line 85 */
  #define EXTI_FTSR3_TR86    0x00400000	/* Falling trigger event configuration bit of line 86 */
#define TOFF_EXTI_SWIER3    0x0048		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER3_SWI     0x00740000	/* Software Interrupt event bit */
  #define EXTI_SWIER3_SWIER82 0x00040000	/* Software Interrupt on line 82 */
  #define EXTI_SWIER3_SWIER84 0x00100000	/* Software Interrupt on line 84 */
  #define EXTI_SWIER3_SWIER85 0x00200000	/* Software Interrupt on line 85 */
  #define EXTI_SWIER3_SWIER86 0x00400000	/* Software Interrupt on line 86 */
#define TOFF_EXTI_D3PMR3    0x004C		/* (RW) EXTI D3 Pending mask register, (same register as to SRDPMR3) */
#define TOFF_EXTI_D3PCR3L   0x0050		/* (RW) EXTI D3 Pending clear selection register low, (same register as to SRDPCR3L) */
#define TOFF_EXTI_D3PCR3H   0x0054		/* (RW) EXTI D3 Pending clear selection register High, (same register as to SRDPCR3H) */
#define TOFF_EXTI_IMR1      0x0080		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR1_IM       0xFFFFFFFF	/* Interrupt Mask */
  #define EXTI_IMR1_IM0      0x00000001	/* Interrupt Mask on line 0 */
  #define EXTI_IMR1_IM1      0x00000002	/* Interrupt Mask on line 1 */
  #define EXTI_IMR1_IM2      0x00000004	/* Interrupt Mask on line 2 */
  #define EXTI_IMR1_IM3      0x00000008	/* Interrupt Mask on line 3 */
  #define EXTI_IMR1_IM4      0x00000010	/* Interrupt Mask on line 4 */
  #define EXTI_IMR1_IM5      0x00000020	/* Interrupt Mask on line 5 */
  #define EXTI_IMR1_IM6      0x00000040	/* Interrupt Mask on line 6 */
  #define EXTI_IMR1_IM7      0x00000080	/* Interrupt Mask on line 7 */
  #define EXTI_IMR1_IM8      0x00000100	/* Interrupt Mask on line 8 */
  #define EXTI_IMR1_IM9      0x00000200	/* Interrupt Mask on line 9 */
  #define EXTI_IMR1_IM10     0x00000400	/* Interrupt Mask on line 10 */
  #define EXTI_IMR1_IM11     0x00000800	/* Interrupt Mask on line 11 */
  #define EXTI_IMR1_IM12     0x00001000	/* Interrupt Mask on line 12 */
  #define EXTI_IMR1_IM13     0x00002000	/* Interrupt Mask on line 13 */
  #define EXTI_IMR1_IM14     0x00004000	/* Interrupt Mask on line 14 */
  #define EXTI_IMR1_IM15     0x00008000	/* Interrupt Mask on line 15 */
  #define EXTI_IMR1_IM16     0x00010000	/* Interrupt Mask on line 16 */
  #define EXTI_IMR1_IM17     0x00020000	/* Interrupt Mask on line 17 */
  #define EXTI_IMR1_IM18     0x00040000	/* Interrupt Mask on line 18 */
  #define EXTI_IMR1_IM19     0x00080000	/* Interrupt Mask on line 19 */
  #define EXTI_IMR1_IM20     0x00100000	/* Interrupt Mask on line 20 */
  #define EXTI_IMR1_IM21     0x00200000	/* Interrupt Mask on line 21 */
  #define EXTI_IMR1_IM22     0x00400000	/* Interrupt Mask on line 22 */
  #define EXTI_IMR1_IM23     0x00800000	/* Interrupt Mask on line 23 */
  #define EXTI_IMR1_IM24     0x01000000	/* Interrupt Mask on line 24 */
  #define EXTI_IMR1_IM25     0x02000000	/* Interrupt Mask on line 25 */
  #define EXTI_IMR1_IM26     0x04000000	/* Interrupt Mask on line 26 */
  #define EXTI_IMR1_IM27     0x08000000	/* Interrupt Mask on line 27 */
  #define EXTI_IMR1_IM28     0x10000000	/* Interrupt Mask on line 28 */
  #define EXTI_IMR1_IM29     0x20000000	/* Interrupt Mask on line 29 */
  #define EXTI_IMR1_IM30     0x40000000	/* Interrupt Mask on line 30 */
  #define EXTI_IMR1_IM31     0x80000000	/* Interrupt Mask on line 31 */
#define TOFF_EXTI_EMR1      0x0084		/* (RW) EXTI Event mask register */
  #define EXTI_EMR1_EM       0xFFFFFFFF	/* Event Mask */
  #define EXTI_EMR1_EM0      0x00000001	/* Event Mask on line 0 */
  #define EXTI_EMR1_EM1      0x00000002	/* Event Mask on line 1 */
  #define EXTI_EMR1_EM2      0x00000004	/* Event Mask on line 2 */
  #define EXTI_EMR1_EM3      0x00000008	/* Event Mask on line 3 */
  #define EXTI_EMR1_EM4      0x00000010	/* Event Mask on line 4 */
  #define EXTI_EMR1_EM5      0x00000020	/* Event Mask on line 5 */
  #define EXTI_EMR1_EM6      0x00000040	/* Event Mask on line 6 */
  #define EXTI_EMR1_EM7      0x00000080	/* Event Mask on line 7 */
  #define EXTI_EMR1_EM8      0x00000100	/* Event Mask on line 8 */
  #define EXTI_EMR1_EM9      0x00000200	/* Event Mask on line 9 */
  #define EXTI_EMR1_EM10     0x00000400	/* Event Mask on line 10 */
  #define EXTI_EMR1_EM11     0x00000800	/* Event Mask on line 11 */
  #define EXTI_EMR1_EM12     0x00001000	/* Event Mask on line 12 */
  #define EXTI_EMR1_EM13     0x00002000	/* Event Mask on line 13 */
  #define EXTI_EMR1_EM14     0x00004000	/* Event Mask on line 14 */
  #define EXTI_EMR1_EM15     0x00008000	/* Event Mask on line 15 */
  #define EXTI_EMR1_EM16     0x00010000	/* Event Mask on line 16 */
  #define EXTI_EMR1_EM17     0x00020000	/* Event Mask on line 17 */
  #define EXTI_EMR1_EM18     0x00040000	/* Event Mask on line 18 */
  #define EXTI_EMR1_EM19     0x00080000	/* Event Mask on line 19 */
  #define EXTI_EMR1_EM20     0x00100000	/* Event Mask on line 20 */
  #define EXTI_EMR1_EM21     0x00200000	/* Event Mask on line 21 */
  #define EXTI_EMR1_EM22     0x00400000	/* Event Mask on line 22 */
  #define EXTI_EMR1_EM23     0x00800000	/* Event Mask on line 23 */
  #define EXTI_EMR1_EM24     0x01000000	/* Event Mask on line 24 */
  #define EXTI_EMR1_EM25     0x02000000	/* Event Mask on line 25 */
  #define EXTI_EMR1_EM26     0x04000000	/* Event Mask on line 26 */
  #define EXTI_EMR1_EM27     0x08000000	/* Event Mask on line 27 */
  #define EXTI_EMR1_EM28     0x10000000	/* Event Mask on line 28 */
  #define EXTI_EMR1_EM29     0x20000000	/* Event Mask on line 29 */
  #define EXTI_EMR1_EM30     0x40000000	/* Event Mask on line 30 */
  #define EXTI_EMR1_EM31     0x80000000	/* Event Mask on line 31 */
#define TOFF_EXTI_PR1       0x0088		/* (RW) EXTI Pending register */
  #define EXTI_PR1_PR        0x003FFFFF	/* Pending bit */
  #define EXTI_PR1_PR0       0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR1_PR1       0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR1_PR2       0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR1_PR3       0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR1_PR4       0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR1_PR5       0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR1_PR6       0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR1_PR7       0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR1_PR8       0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR1_PR9       0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR1_PR10      0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR1_PR11      0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR1_PR12      0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR1_PR13      0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR1_PR14      0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR1_PR15      0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR1_PR16      0x00010000	/* Pending bit for line 16 */
  #define EXTI_PR1_PR17      0x00020000	/* Pending bit for line 17 */
  #define EXTI_PR1_PR18      0x00040000	/* Pending bit for line 18 */
  #define EXTI_PR1_PR19      0x00080000	/* Pending bit for line 19 */
  #define EXTI_PR1_PR20      0x00100000	/* Pending bit for line 20 */
  #define EXTI_PR1_PR21      0x00200000	/* Pending bit for line 21 */
#define TOFF_EXTI_IMR2      0x0090		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR2_IM       0xFFFFDFFF	/* Interrupt Mask */
  #define EXTI_IMR2_IM32     0x00000001	/* Interrupt Mask on line 32 */
  #define EXTI_IMR2_IM33     0x00000002	/* Interrupt Mask on line 33 */
  #define EXTI_IMR2_IM34     0x00000004	/* Interrupt Mask on line 34 */
  #define EXTI_IMR2_IM35     0x00000008	/* Interrupt Mask on line 35 */
  #define EXTI_IMR2_IM36     0x00000010	/* Interrupt Mask on line 36 */
  #define EXTI_IMR2_IM37     0x00000020	/* Interrupt Mask on line 37 */
  #define EXTI_IMR2_IM38     0x00000040	/* Interrupt Mask on line 38 */
  #define EXTI_IMR2_IM39     0x00000080	/* Interrupt Mask on line 39 */
  #define EXTI_IMR2_IM40     0x00000100	/* Interrupt Mask on line 40 */
  #define EXTI_IMR2_IM41     0x00000200	/* Interrupt Mask on line 41 */
  #define EXTI_IMR2_IM42     0x00000400	/* Interrupt Mask on line 42 */
  #define EXTI_IMR2_IM43     0x00000800	/* Interrupt Mask on line 43 */
  #define EXTI_IMR2_IM44     0x00001000	/* Interrupt Mask on line 44 */
  #define EXTI_IMR2_IM46     0x00004000	/* Interrupt Mask on line 46 */
  #define EXTI_IMR2_IM47     0x00008000	/* Interrupt Mask on line 47 */
  #define EXTI_IMR2_IM48     0x00010000	/* Interrupt Mask on line 48 */
  #define EXTI_IMR2_IM49     0x00020000	/* Interrupt Mask on line 49 */
  #define EXTI_IMR2_IM50     0x00040000	/* Interrupt Mask on line 50 */
  #define EXTI_IMR2_IM51     0x00080000	/* Interrupt Mask on line 51 */
  #define EXTI_IMR2_IM52     0x00100000	/* Interrupt Mask on line 52 */
  #define EXTI_IMR2_IM53     0x00200000	/* Interrupt Mask on line 53 */
  #define EXTI_IMR2_IM54     0x00400000	/* Interrupt Mask on line 54 */
  #define EXTI_IMR2_IM55     0x00800000	/* Interrupt Mask on line 55 */
  #define EXTI_IMR2_IM56     0x01000000	/* Interrupt Mask on line 56 */
  #define EXTI_IMR2_IM57     0x02000000	/* Interrupt Mask on line 57 */
  #define EXTI_IMR2_IM58     0x04000000	/* Interrupt Mask on line 58 */
  #define EXTI_IMR2_IM59     0x08000000	/* Interrupt Mask on line 59 */
  #define EXTI_IMR2_IM60     0x10000000	/* Interrupt Mask on line 60 */
  #define EXTI_IMR2_IM61     0x20000000	/* Interrupt Mask on line 61 */
  #define EXTI_IMR2_IM62     0x40000000	/* Interrupt Mask on line 62 */
  #define EXTI_IMR2_IM63     0x80000000	/* Interrupt Mask on line 63 */
#define TOFF_EXTI_EMR2      0x0094		/* (RW) EXTI Event mask register */
  #define EXTI_EMR2_EM       0xFFFFDFFF	/* Event Mask */
  #define EXTI_EMR2_EM32     0x00000001	/* Event Mask on line 32 */
  #define EXTI_EMR2_EM33     0x00000002	/* Event Mask on line 33 */
  #define EXTI_EMR2_EM34     0x00000004	/* Event Mask on line 34 */
  #define EXTI_EMR2_EM35     0x00000008	/* Event Mask on line 35 */
  #define EXTI_EMR2_EM36     0x00000010	/* Event Mask on line 36 */
  #define EXTI_EMR2_EM37     0x00000020	/* Event Mask on line 37 */
  #define EXTI_EMR2_EM38     0x00000040	/* Event Mask on line 38 */
  #define EXTI_EMR2_EM39     0x00000080	/* Event Mask on line 39 */
  #define EXTI_EMR2_EM40     0x00000100	/* Event Mask on line 40 */
  #define EXTI_EMR2_EM41     0x00000200	/* Event Mask on line 41 */
  #define EXTI_EMR2_EM42     0x00000400	/* Event Mask on line 42 */
  #define EXTI_EMR2_EM43     0x00000800	/* Event Mask on line 43 */
  #define EXTI_EMR2_EM44     0x00001000	/* Event Mask on line 44 */
  #define EXTI_EMR2_EM46     0x00004000	/* Event Mask on line 46 */
  #define EXTI_EMR2_EM47     0x00008000	/* Event Mask on line 47 */
  #define EXTI_EMR2_EM48     0x00010000	/* Event Mask on line 48 */
  #define EXTI_EMR2_EM49     0x00020000	/* Event Mask on line 49 */
  #define EXTI_EMR2_EM50     0x00040000	/* Event Mask on line 50 */
  #define EXTI_EMR2_EM51     0x00080000	/* Event Mask on line 51 */
  #define EXTI_EMR2_EM52     0x00100000	/* Event Mask on line 52 */
  #define EXTI_EMR2_EM53     0x00200000	/* Event Mask on line 53 */
  #define EXTI_EMR2_EM54     0x00400000	/* Event Mask on line 54 */
  #define EXTI_EMR2_EM55     0x00800000	/* Event Mask on line 55 */
  #define EXTI_EMR2_EM56     0x01000000	/* Event Mask on line 56 */
  #define EXTI_EMR2_EM57     0x02000000	/* Event Mask on line 57 */
  #define EXTI_EMR2_EM58     0x04000000	/* Event Mask on line 58 */
  #define EXTI_EMR2_EM59     0x08000000	/* Event Mask on line 59 */
  #define EXTI_EMR2_EM60     0x10000000	/* Event Mask on line 60 */
  #define EXTI_EMR2_EM61     0x20000000	/* Event Mask on line 61 */
  #define EXTI_EMR2_EM62     0x40000000	/* Event Mask on line 62 */
  #define EXTI_EMR2_EM63     0x80000000	/* Event Mask on line 63 */
#define TOFF_EXTI_PR2       0x0098		/* (RW) EXTI Pending register */
  #define EXTI_PR2_PR        0x000A0000	/* Pending bit */
  #define EXTI_PR2_PR49      0x00020000	/* Pending bit for line 49 */
  #define EXTI_PR2_PR51      0x00080000	/* Pending bit for line 51 */
#define TOFF_EXTI_IMR3      0x00A0		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR3_IM       0x00F5FFFF	/* Interrupt Mask */
  #define EXTI_IMR3_IM64     0x00000001	/* Interrupt Mask on line 64 */
  #define EXTI_IMR3_IM65     0x00000002	/* Interrupt Mask on line 65 */
  #define EXTI_IMR3_IM66     0x00000004	/* Interrupt Mask on line 66 */
  #define EXTI_IMR3_IM67     0x00000008	/* Interrupt Mask on line 67 */
  #define EXTI_IMR3_IM68     0x00000010	/* Interrupt Mask on line 68 */
  #define EXTI_IMR3_IM69     0x00000020	/* Interrupt Mask on line 69 */
  #define EXTI_IMR3_IM70     0x00000040	/* Interrupt Mask on line 70 */
  #define EXTI_IMR3_IM71     0x00000080	/* Interrupt Mask on line 71 */
  #define EXTI_IMR3_IM72     0x00000100	/* Interrupt Mask on line 72 */
  #define EXTI_IMR3_IM73     0x00000200	/* Interrupt Mask on line 73 */
  #define EXTI_IMR3_IM74     0x00000400	/* Interrupt Mask on line 74 */
  #define EXTI_IMR3_IM75     0x00000800	/* Interrupt Mask on line 75 */
  #define EXTI_IMR3_IM76     0x00001000	/* Interrupt Mask on line 76 */
  #define EXTI_IMR3_IM77     0x00002000	/* Interrupt Mask on line 77 */
  #define EXTI_IMR3_IM78     0x00004000	/* Interrupt Mask on line 78 */
  #define EXTI_IMR3_IM79     0x00008000	/* Interrupt Mask on line 79 */
  #define EXTI_IMR3_IM80     0x00010000	/* Interrupt Mask on line 80 */
  #define EXTI_IMR3_IM82     0x00040000	/* Interrupt Mask on line 82 */
  #define EXTI_IMR3_IM84     0x00100000	/* Interrupt Mask on line 84 */
  #define EXTI_IMR3_IM85     0x00200000	/* Interrupt Mask on line 85 */
  #define EXTI_IMR3_IM86     0x00400000	/* Interrupt Mask on line 86 */
  #define EXTI_IMR3_IM87     0x00800000	/* Interrupt Mask on line 87 */
#define TOFF_EXTI_EMR3      0x00A4		/* (RW) EXTI Event mask register */
  #define EXTI_EMR3_EM       0x00F5FFFF	/* Event Mask */
  #define EXTI_EMR3_EM64     0x00000001	/* Event Mask on line 64 */
  #define EXTI_EMR3_EM65     0x00000002	/* Event Mask on line 65 */
  #define EXTI_EMR3_EM66     0x00000004	/* Event Mask on line 66 */
  #define EXTI_EMR3_EM67     0x00000008	/* Event Mask on line 67 */
  #define EXTI_EMR3_EM68     0x00000010	/* Event Mask on line 68 */
  #define EXTI_EMR3_EM69     0x00000020	/* Event Mask on line 69 */
  #define EXTI_EMR3_EM70     0x00000040	/* Event Mask on line 70 */
  #define EXTI_EMR3_EM71     0x00000080	/* Event Mask on line 71 */
  #define EXTI_EMR3_EM72     0x00000100	/* Event Mask on line 72 */
  #define EXTI_EMR3_EM73     0x00000200	/* Event Mask on line 73 */
  #define EXTI_EMR3_EM74     0x00000400	/* Event Mask on line 74 */
  #define EXTI_EMR3_EM75     0x00000800	/* Event Mask on line 75 */
  #define EXTI_EMR3_EM76     0x00001000	/* Event Mask on line 76 */
  #define EXTI_EMR3_EM77     0x00002000	/* Event Mask on line 77 */
  #define EXTI_EMR3_EM78     0x00004000	/* Event Mask on line 78 */
  #define EXTI_EMR3_EM79     0x00008000	/* Event Mask on line 79 */
  #define EXTI_EMR3_EM80     0x00010000	/* Event Mask on line 80 */
  #define EXTI_EMR3_EM81     0x00020000	/* Event Mask on line 81 */
  #define EXTI_EMR3_EM82     0x00040000	/* Event Mask on line 82 */
  #define EXTI_EMR3_EM84     0x00100000	/* Event Mask on line 84 */
  #define EXTI_EMR3_EM85     0x00200000	/* Event Mask on line 85 */
  #define EXTI_EMR3_EM86     0x00400000	/* Event Mask on line 86 */
  #define EXTI_EMR3_EM87     0x00800000	/* Event Mask on line 87 */
#define TOFF_EXTI_PR3       0x00A8		/* (RW) EXTI Pending register */
  #define EXTI_PR3_PR        0x00740000	/* Pending bit */
  #define EXTI_PR3_PR82      0x00040000	/* Pending bit for line 82 */
  #define EXTI_PR3_PR84      0x00100000	/* Pending bit for line 84 */
  #define EXTI_PR3_PR85      0x00200000	/* Pending bit for line 85 */
  #define EXTI_PR3_PR86      0x00400000	/* Pending bit for line 86 */


/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (D3_AHB1PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (D3_AHB1PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (D3_AHB1PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (D3_AHB1PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (D3_AHB1PERIPH_BASE + 0x1000)
#define TADR_GPIOF_BASE     (D3_AHB1PERIPH_BASE + 0x1400)
#define TADR_GPIOG_BASE     (D3_AHB1PERIPH_BASE + 0x1800)
#define TADR_GPIOH_BASE     (D3_AHB1PERIPH_BASE + 0x1C00)
#define TADR_GPIOI_BASE     (D3_AHB1PERIPH_BASE + 0x2000)
#define TADR_GPIOJ_BASE     (D3_AHB1PERIPH_BASE + 0x2400)
#define TADR_GPIOK_BASE     (D3_AHB1PERIPH_BASE + 0x2800)
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
 *  HW Semaphore HSEM
 */
#define TADR_HSEM_BASE      (D3_AHB1PERIPH_BASE + 0x6400)
#define TOFF_HSEM_R         0x0000		/* (RW) 2-step write lock and read back registers[0-31] */
  #define HSEM_R_PROCID      0x000000FF	/* Semaphore ProcessID */
  #define HSEM_R_COREID      0x0000FF00	/* Semaphore CoreID. */
  #define HSEM_R_LOCK        0x80000000	/* Lock indication. */
#define TOFF_HSEM_RLR       0x0080		/* (RW) 1-step read lock registers[0-31] */
  #define HSEM_RLR_PROCID    0x000000FF	/* Semaphore ProcessID */
  #define HSEM_RLR_COREID    0x0000FF00	/* Semaphore CoreID. */
  #define HSEM_RLR_LOCK      0x80000000	/* Lock indication. */
#define TOFF_HSEM_C1IER     0x0100		/* (RW) HSEM Interrupt enable register */
  #define HSEM_C1IER_ISE0    0x00000001	/* semaphore 0 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE1    0x00000002	/* semaphore 1 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE2    0x00000004	/* semaphore 2 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE3    0x00000008	/* semaphore 3 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE4    0x00000010	/* semaphore 4 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE5    0x00000020	/* semaphore 5 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE6    0x00000040	/* semaphore 6 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE7    0x00000080	/* semaphore 7 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE8    0x00000100	/* semaphore 8 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE9    0x00000200	/* semaphore 9 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE10   0x00000400	/* semaphore 10 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE11   0x00000800	/* semaphore 11 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE12   0x00001000	/* semaphore 12 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE13   0x00002000	/* semaphore 13 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE14   0x00004000	/* semaphore 14 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE15   0x00008000	/* semaphore 15 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE16   0x00010000	/* semaphore 16 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE17   0x00020000	/* semaphore 17 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE18   0x00040000	/* semaphore 18 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE19   0x00080000	/* semaphore 19 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE20   0x00100000	/* semaphore 20 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE21   0x00200000	/* semaphore 21 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE22   0x00400000	/* semaphore 22 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE23   0x00800000	/* semaphore 23 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE24   0x01000000	/* semaphore 24 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE25   0x02000000	/* semaphore 25 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE26   0x04000000	/* semaphore 26 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE27   0x08000000	/* semaphore 27 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE28   0x10000000	/* semaphore 28 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE29   0x20000000	/* semaphore 29 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE30   0x40000000	/* semaphore 30 interrupt 0 enable bit. */
  #define HSEM_C1IER_ISE31   0x80000000	/* semaphore 31 interrupt 0 enable bit. */
#define TOFF_HSEM_C1ICR     0x0104		/* (RW) HSEM Interrupt clear register */
  #define HSEM_C1ICR_ISC0    0x00000001	/* semaphore 0 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC1    0x00000002	/* semaphore 1 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC2    0x00000004	/* semaphore 2 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC3    0x00000008	/* semaphore 3 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC4    0x00000010	/* semaphore 4 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC5    0x00000020	/* semaphore 5 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC6    0x00000040	/* semaphore 6 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC7    0x00000080	/* semaphore 7 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC8    0x00000100	/* semaphore 8 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC9    0x00000200	/* semaphore 9 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC10   0x00000400	/* semaphore 10 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC11   0x00000800	/* semaphore 11 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC12   0x00001000	/* semaphore 12 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC13   0x00002000	/* semaphore 13 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC14   0x00004000	/* semaphore 14 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC15   0x00008000	/* semaphore 15 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC16   0x00010000	/* semaphore 16 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC17   0x00020000	/* semaphore 17 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC18   0x00040000	/* semaphore 18 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC19   0x00080000	/* semaphore 19 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC20   0x00100000	/* semaphore 20 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC21   0x00200000	/* semaphore 21 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC22   0x00400000	/* semaphore 22 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC23   0x00800000	/* semaphore 23 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC24   0x01000000	/* semaphore 24 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC25   0x02000000	/* semaphore 25 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC26   0x04000000	/* semaphore 26 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC27   0x08000000	/* semaphore 27 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC28   0x10000000	/* semaphore 28 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC29   0x20000000	/* semaphore 29 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC30   0x40000000	/* semaphore 30 interrupt 0 clear bit. */
  #define HSEM_C1ICR_ISC31   0x80000000	/* semaphore 31 interrupt 0 clear bit. */
#define TOFF_HSEM_C1ISR     0x0108		/* (RW) HSEM Interrupt Status register */
  #define HSEM_C1ISR_ISF0    0x00000001	/* semaphore 0 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF1    0x00000002	/* semaphore 1 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF2    0x00000004	/* semaphore 2 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF3    0x00000008	/* semaphore 3 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF4    0x00000010	/* semaphore 4 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF5    0x00000020	/* semaphore 5 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF6    0x00000040	/* semaphore 6 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF7    0x00000080	/* semaphore 7 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF8    0x00000100	/* semaphore 8 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF9    0x00000200	/* semaphore 9 interrupt 0 status bit.  */
  #define HSEM_C1ISR_ISF10   0x00000400	/* semaphore 10 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF11   0x00000800	/* semaphore 11 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF12   0x00001000	/* semaphore 12 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF13   0x00002000	/* semaphore 13 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF14   0x00004000	/* semaphore 14 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF15   0x00008000	/* semaphore 15 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF16   0x00010000	/* semaphore 16 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF17   0x00020000	/* semaphore 17 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF18   0x00040000	/* semaphore 18 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF19   0x00080000	/* semaphore 19 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF20   0x00100000	/* semaphore 20 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF21   0x00200000	/* semaphore 21 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF22   0x00400000	/* semaphore 22 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF23   0x00800000	/* semaphore 23 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF24   0x01000000	/* semaphore 24 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF25   0x02000000	/* semaphore 25 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF26   0x04000000	/* semaphore 26 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF27   0x08000000	/* semaphore 27 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF28   0x10000000	/* semaphore 28 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF29   0x20000000	/* semaphore 29 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF30   0x40000000	/* semaphore 30 interrupt 0 status bit. */
  #define HSEM_C1ISR_ISF31   0x80000000	/* semaphore 31 interrupt 0 status bit. */
#define TOFF_HSEM_C1MISR    0x010C		/* (RW) HSEM Interrupt Masked Status register */
  #define HSEM_C1MISR_MISF0  0x00000001	/* semaphore 0 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF1  0x00000002	/* semaphore 1 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF2  0x00000004	/* semaphore 2 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF3  0x00000008	/* semaphore 3 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF4  0x00000010	/* semaphore 4 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF5  0x00000020	/* semaphore 5 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF6  0x00000040	/* semaphore 6 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF7  0x00000080	/* semaphore 7 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF8  0x00000100	/* semaphore 8 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF9  0x00000200	/* semaphore 9 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF10 0x00000400	/* semaphore 10 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF11 0x00000800	/* semaphore 11 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF12 0x00001000	/* semaphore 12 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF13 0x00002000	/* semaphore 13 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF14 0x00004000	/* semaphore 14 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF15 0x00008000	/* semaphore 15 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF16 0x00010000	/* semaphore 16 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF17 0x00020000	/* semaphore 17 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF18 0x00040000	/* semaphore 18 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF19 0x00080000	/* semaphore 19 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF20 0x00100000	/* semaphore 20 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF21 0x00200000	/* semaphore 21 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF22 0x00400000	/* semaphore 22 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF23 0x00800000	/* semaphore 23 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF24 0x01000000	/* semaphore 24 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF25 0x02000000	/* semaphore 25 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF26 0x04000000	/* semaphore 26 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF27 0x08000000	/* semaphore 27 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF28 0x10000000	/* semaphore 28 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF29 0x20000000	/* semaphore 29 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF30 0x40000000	/* semaphore 30 interrupt 0 masked status bit. */
  #define HSEM_C1MISR_MISF31 0x80000000	/* semaphore 31 interrupt 0 masked status bit. */
#define TOFF_HSEM_CR        0x0140		/* (RW) HSEM Semaphore clear register */
  #define HSEM_CR_COREID     0x0000FF00	/* CoreID of semaphores to be cleared. */
  #define HSEM_CR_KEY        0xFFFF0000	/* semaphores clear key. */
#define TOFF_HSEM_KEYR      0x0144		/* (RW) HSEM Semaphore clear key register */
  #define HSEM_KEYR_KEY      0xFFFF0000	/* semaphores clear key. */


/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (D3_AHB1PERIPH_BASE + 0x4C00)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */
  #define CRC_CR_RESET       0x00000001	/* RESET the CRC computation unit bit */
  #define CRC_CR_POLYSIZE    0x00000018	/* Polynomial size bits */
  #define CRC_CR_POLYSIZE_0  0x00000008
  #define CRC_CR_POLYSIZE_1  0x00000010
  #define CRC_CR_REV_IN      0x00000060	/* REV_IN Reverse Input Data bits */
  #define CRC_CR_REV_IN_0    0x00000020
  #define CRC_CR_REV_IN_1    0x00000040
  #define CRC_CR_REV_OUT     0x00000080	/* REV_OUT Reverse Output Data bits */
#define TOFF_CRC_INIT       0x0010		/* (RW) Initial CRC value register */
#define TOFF_CRC_POL        0x0014		/* (RW) CRC polynomial register */


/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (D3_AHB1PERIPH_BASE + 0x4400)
#define TOFF_RCC_CR         0x0000	/* (RW) RCC clock control register */
  #define RCC_CR_HSION              0x00000001	/* Internal High Speed clock enable */
  #define RCC_CR_HSIKERON           0x00000002	/* Internal High Speed clock enable for some IPs Kernel */
  #define RCC_CR_HSIRDY             0x00000004	/* Internal High Speed clock ready flag */
  #define RCC_CR_HSIDIV             0x00000018	/* Internal High Speed clock divider selection */
  #define RCC_CR_HSIDIV_1           0x00000000
  #define RCC_CR_HSIDIV_2           0x00000008
  #define RCC_CR_HSIDIV_4           0x00000010
  #define RCC_CR_HSIDIV_8           0x00000018
  #define RCC_CR_HSIDIVF            0x00000020	/* HSI Divider flag */
  #define RCC_CR_CSION              0x00000080	/* The Internal RC 4MHz oscillator clock enable */
  #define RCC_CR_CSIRDY             0x00000100	/* The Internal RC 4MHz oscillator clock ready */
  #define RCC_CR_CSIKERON           0x00000200	/* Internal RC 4MHz oscillator clock enable for some IPs Kernel */
  #define RCC_CR_HSI48ON            0x00001000	/* HSI48 clock enable clock enable  */
  #define RCC_CR_HSI48RDY           0x00002000	/* HSI48 clock ready */
  #define RCC_CR_D1CKRDY            0x00004000	/* D1 domain clocks ready flag  */
  #define RCC_CR_D2CKRDY            0x00008000	/* D2 domain clocks ready flag */
  #define RCC_CR_HSEON              0x00010000	/* External High Speed clock enable */
  #define RCC_CR_HSERDY             0x00020000	/* External High Speed clock ready */
  #define RCC_CR_HSEBYP             0x00040000	/* External High Speed clock Bypass */
  #define RCC_CR_CSSHSEON           0x00080000	/* HSE Clock security System enable */
  #define RCC_CR_PLL1ON             0x01000000	/* System PLL1 clock enable */
  #define RCC_CR_PLL1RDY            0x02000000	/* System PLL1 clock ready */
  #define RCC_CR_PLL2ON             0x04000000	/* System PLL2 clock enable */
  #define RCC_CR_PLL2RDY            0x08000000	/* System PLL2 clock ready */
  #define RCC_CR_PLL3ON             0x10000000	/* System PLL3 clock enable */
  #define RCC_CR_PLL3RDY            0x20000000	/* System PLL3 clock ready */
  #define RCC_CR_PLLON              RCC_CR_PLL1ON	/* System PLL clock enable */
  #define RCC_CR_PLLRDY             RCC_CR_PLL1RDY	/* System PLL clock ready */
#define TOFF_RCC_HSICFGR    0x0004	/* (RW) HSI Clock Calibration Register */
  #define RCC_HSICFGR_HSICAL        0x00000FFF	/* HSICAL[11:0] bits */
  #define RCC_HSICFGR_HSICAL_0      0x00000001
  #define RCC_HSICFGR_HSICAL_1      0x00000002
  #define RCC_HSICFGR_HSICAL_2      0x00000004
  #define RCC_HSICFGR_HSICAL_3      0x00000008
  #define RCC_HSICFGR_HSICAL_4      0x00000010
  #define RCC_HSICFGR_HSICAL_5      0x00000020
  #define RCC_HSICFGR_HSICAL_6      0x00000040
  #define RCC_HSICFGR_HSICAL_7      0x00000080
  #define RCC_HSICFGR_HSICAL_8      0x00000100
  #define RCC_HSICFGR_HSICAL_9      0x00000200
  #define RCC_HSICFGR_HSICAL_10     0x00000400
  #define RCC_HSICFGR_HSICAL_11     0x00000800
  #define RCC_HSICFGR_HSITRIM       0x7F000000	/* HSITRIM[6:0] bits */
  #define RCC_HSICFGR_HSITRIM_0     0x01000000
  #define RCC_HSICFGR_HSITRIM_1     0x02000000
  #define RCC_HSICFGR_HSITRIM_2     0x04000000
  #define RCC_HSICFGR_HSITRIM_3     0x08000000
  #define RCC_HSICFGR_HSITRIM_4     0x10000000
  #define RCC_HSICFGR_HSITRIM_5     0x20000000
  #define RCC_HSICFGR_HSITRIM_6     0x40000000
#define TOFF_RCC_CRRCR      0x0008	/* (RW) Clock Recovery RC  Register */
  #define RCC_CRRCR_HSI48CAL        0x000003FF	/* HSI48CAL[9:0] bits */
  #define RCC_CRRCR_HSI48CAL_0      0x00000001
  #define RCC_CRRCR_HSI48CAL_1      0x00000002
  #define RCC_CRRCR_HSI48CAL_2      0x00000004
  #define RCC_CRRCR_HSI48CAL_3      0x00000008
  #define RCC_CRRCR_HSI48CAL_4      0x00000010
  #define RCC_CRRCR_HSI48CAL_5      0x00000020
  #define RCC_CRRCR_HSI48CAL_6      0x00000040
  #define RCC_CRRCR_HSI48CAL_7      0x00000080
  #define RCC_CRRCR_HSI48CAL_8      0x00000100
  #define RCC_CRRCR_HSI48CAL_9      0x00000200
#define TOFF_RCC_CSICFGR    0x000C	/* (RW) CSI Clock Calibration Register */
  #define RCC_CSICFGR_CSICAL        0x000000FF	/* CSICAL[7:0] bits */
  #define RCC_CSICFGR_CSICAL_0      0x00000001
  #define RCC_CSICFGR_CSICAL_1      0x00000002
  #define RCC_CSICFGR_CSICAL_2      0x00000004
  #define RCC_CSICFGR_CSICAL_3      0x00000008
  #define RCC_CSICFGR_CSICAL_4      0x00000010
  #define RCC_CSICFGR_CSICAL_5      0x00000020
  #define RCC_CSICFGR_CSICAL_6      0x00000040
  #define RCC_CSICFGR_CSICAL_7      0x00000080
  #define RCC_CSICFGR_CSITRIM       0x3F000000	/* CSITRIM[5:0] bits */
  #define RCC_CSICFGR_CSITRIM_0     0x01000000
  #define RCC_CSICFGR_CSITRIM_1     0x02000000
  #define RCC_CSICFGR_CSITRIM_2     0x04000000
  #define RCC_CSICFGR_CSITRIM_3     0x08000000
  #define RCC_CSICFGR_CSITRIM_4     0x10000000
  #define RCC_CSICFGR_CSITRIM_5     0x20000000
#define TOFF_RCC_CFGR       0x0010	/* (RW) RCC clock configuration register */
  #define RCC_CFGR_SW               0x00000007	/* SW[2:0] bits (System clock Switch) */
  #define RCC_CFGR_SW_0             0x00000001
  #define RCC_CFGR_SW_1             0x00000002
  #define RCC_CFGR_SW_2             0x00000004
  #define RCC_CFGR_SW_HSI           0x00000000	/* HSI selection as system clock */
  #define RCC_CFGR_SW_CSI           0x00000001	/* CSI selection as system clock */
  #define RCC_CFGR_SW_HSE           0x00000002	/* HSE selection as system clock */
  #define RCC_CFGR_SW_PLL1          0x00000003	/* PLL1 selection as system clock */
  #define RCC_CFGR_SWS              0x00000038	/* SWS[2:0] bits (System Clock Switch Status) */
  #define RCC_CFGR_SWS_0            0x00000008
  #define RCC_CFGR_SWS_1            0x00000010
  #define RCC_CFGR_SWS_2            0x00000020
  #define RCC_CFGR_SWS_HSI          0x00000000	/* HSI used as system clock */
  #define RCC_CFGR_SWS_CSI          0x00000008	/* CSI used as system clock */
  #define RCC_CFGR_SWS_HSE          0x00000010	/* HSE used as system clock */
  #define RCC_CFGR_SWS_PLL1         0x00000018	/* PLL1 used as system clock */
  #define RCC_CFGR_STOPWUCK         0x00000040	/* Wake Up from stop and CSS backup clock selection */
  #define RCC_CFGR_STOPKERWUCK      0x00000080	/* Kernel Clock Selection after a Wake Up from STOP */
  #define RCC_CFGR_RTCPRE           0x00003F00	/* RTCPRE configuration */
  #define RCC_CFGR_RTCPRE_0         0x00000100
  #define RCC_CFGR_RTCPRE_1         0x00000200
  #define RCC_CFGR_RTCPRE_2         0x00000400
  #define RCC_CFGR_RTCPRE_3         0x00000800
  #define RCC_CFGR_RTCPRE_4         0x00001000
  #define RCC_CFGR_RTCPRE_5         0x00002000
  #define RCC_CFGR_HRTIMSEL         0x00004000	/* HRTIMSEL configuration */
  #define RCC_CFGR_TIMPRE           0x00008000	/* TIMPRE configuration */
  #define RCC_CFGR_MCO1             0x01C00000	/* MCO1 configuration */
  #define RCC_CFGR_MCO1_0           0x00400000
  #define RCC_CFGR_MCO1_1           0x00800000
  #define RCC_CFGR_MCO1_2           0x01000000
  #define RCC_CFGR_MCO1PRE          0x003C0000
  #define RCC_CFGR_MCO1PRE_0        0x00040000
  #define RCC_CFGR_MCO1PRE_1        0x00080000
  #define RCC_CFGR_MCO1PRE_2        0x00100000
  #define RCC_CFGR_MCO1PRE_3        0x00200000
  #define RCC_CFGR_MCO2PRE          0x1E000000
  #define RCC_CFGR_MCO2PRE_0        0x02000000
  #define RCC_CFGR_MCO2PRE_1        0x04000000
  #define RCC_CFGR_MCO2PRE_2        0x08000000
  #define RCC_CFGR_MCO2PRE_3        0x10000000
  #define RCC_CFGR_MCO2             0xE0000000
  #define RCC_CFGR_MCO2_0           0x20000000
  #define RCC_CFGR_MCO2_1           0x40000000
  #define RCC_CFGR_MCO2_2           0x80000000
#define TOFF_RCC_D1CFGR     0x0018	/* (RW) RCC Domain 1 configuration register */
  #define RCC_D1CFGR_HPRE           0x0000000F	/* HPRE[3:0] bits (AHB3 prescaler) */
  #define RCC_D1CFGR_HPRE_0         0x00000001
  #define RCC_D1CFGR_HPRE_1         0x00000002
  #define RCC_D1CFGR_HPRE_2         0x00000004
  #define RCC_D1CFGR_HPRE_3         0x00000008
  #define RCC_D1CFGR_HPRE_DIV1      0x00000000	/* AHB3 Clock not divided */
  #define RCC_D1CFGR_HPRE_DIV2      0x00000008	/* AHB3 Clock divided by 2 */
  #define RCC_D1CFGR_HPRE_DIV4      0x00000009	/* AHB3 Clock divided by 4 */
  #define RCC_D1CFGR_HPRE_DIV8      0x0000000A	/* AHB3 Clock divided by 8 */
  #define RCC_D1CFGR_HPRE_DIV16     0x0000000B	/* AHB3 Clock divided by 16 */
  #define RCC_D1CFGR_HPRE_DIV64     0x0000000C	/* AHB3 Clock divided by 64 */
  #define RCC_D1CFGR_HPRE_DIV128    0x0000000D	/* AHB3 Clock divided by 128 */
  #define RCC_D1CFGR_HPRE_DIV256    0x0000000E	/* AHB3 Clock divided by 256 */
  #define RCC_D1CFGR_HPRE_DIV512    0x0000000F	/* AHB3 Clock divided by 512 */
  #define RCC_D1CFGR_D1PPRE         0x00000070	/* D1PRE[2:0] bits (APB3 prescaler) */
  #define RCC_D1CFGR_D1PPRE_0       0x00000010
  #define RCC_D1CFGR_D1PPRE_1       0x00000020
  #define RCC_D1CFGR_D1PPRE_2       0x00000040
  #define RCC_D1CFGR_D1PPRE_DIV1    0x00000000	/* APB3 clock not divided */
  #define RCC_D1CFGR_D1PPRE_DIV2    0x00000040	/* APB3 clock divided by 2 */
  #define RCC_D1CFGR_D1PPRE_DIV4    0x00000050	/* APB3 clock divided by 4 */
  #define RCC_D1CFGR_D1PPRE_DIV8    0x00000060	/* APB3 clock divided by 8 */
  #define RCC_D1CFGR_D1PPRE_DIV16   0x00000070	/* APB3 clock divided by 16 */
  #define RCC_D1CFGR_D1CPRE         0x00000F00	/* D1CPRE[2:0] bits (Domain 1 Core prescaler) */
  #define RCC_D1CFGR_D1CPRE_0       0x00000100
  #define RCC_D1CFGR_D1CPRE_1       0x00000200
  #define RCC_D1CFGR_D1CPRE_2       0x00000400
  #define RCC_D1CFGR_D1CPRE_3       0x00000800
  #define RCC_D1CFGR_D1CPRE_DIV1    0x00000000	/* Domain 1 Core clock not divided */
  #define RCC_D1CFGR_D1CPRE_DIV2    0x00000800	/* Domain 1 Core clock divided by 2 */
  #define RCC_D1CFGR_D1CPRE_DIV4    0x00000900	/* Domain 1 Core clock divided by 4 */
  #define RCC_D1CFGR_D1CPRE_DIV8    0x00000A00	/* Domain 1 Core clock divided by 8 */
  #define RCC_D1CFGR_D1CPRE_DIV16   0x00000B00	/* Domain 1 Core clock divided by 16 */
  #define RCC_D1CFGR_D1CPRE_DIV64   0x00000C00	/* Domain 1 Core clock divided by 64 */
  #define RCC_D1CFGR_D1CPRE_DIV128  0x00000D00	/* Domain 1 Core clock divided by 128 */
  #define RCC_D1CFGR_D1CPRE_DIV256  0x00000E00	/* Domain 1 Core clock divided by 256 */
  #define RCC_D1CFGR_D1CPRE_DIV512  0x00000F00	/* Domain 1 Core clock divided by 512 */
#define TOFF_RCC_D2CFGR     0x001C	/* (RW) RCC Domain 2 configuration register */
  #define RCC_D2CFGR_D2PPRE1        0x00000070	/* D1PPRE1[2:0] bits (APB1 prescaler) */
  #define RCC_D2CFGR_D2PPRE1_0      0x00000010
  #define RCC_D2CFGR_D2PPRE1_1      0x00000020
  #define RCC_D2CFGR_D2PPRE1_2      0x00000040
  #define RCC_D2CFGR_D2PPRE1_DIV1   0x00000000	/* APB1 clock not divided */
  #define RCC_D2CFGR_D2PPRE1_DIV2   0x00000040	/* APB1 clock divided by 2 */
  #define RCC_D2CFGR_D2PPRE1_DIV4   0x00000050	/* APB1 clock divided by 4 */
  #define RCC_D2CFGR_D2PPRE1_DIV8   0x00000060	/* APB1 clock divided by 8 */
  #define RCC_D2CFGR_D2PPRE1_DIV16  0x00000070	/* APB1 clock divided by 16 */
  #define RCC_D2CFGR_D2PPRE2        0x00000700	/* D2PPRE2[2:0] bits (APB2 prescaler) */
  #define RCC_D2CFGR_D2PPRE2_0      0x00000100
  #define RCC_D2CFGR_D2PPRE2_1      0x00000200
  #define RCC_D2CFGR_D2PPRE2_2      0x00000400
  #define RCC_D2CFGR_D2PPRE2_DIV1   0x00000000	/* APB2 clock not divided */
  #define RCC_D2CFGR_D2PPRE2_DIV2   0x00000400	/* APB2 clock divided by 2 */
  #define RCC_D2CFGR_D2PPRE2_DIV4   0x00000500	/* APB2 clock divided by 4 */
  #define RCC_D2CFGR_D2PPRE2_DIV8   0x00000600	/* APB2 clock divided by 8 */
  #define RCC_D2CFGR_D2PPRE2_DIV16  0x00000700	/* APB2 clock divided by 16 */
#define TOFF_RCC_D3CFGR     0x0020	/* (RW) RCC Domain 3 configuration register */
  #define RCC_D3CFGR_D3PPRE         0x00000070	/* D3PPRE1[2:0] bits (APB4 prescaler) */
  #define RCC_D3CFGR_D3PPRE_0       0x00000010
  #define RCC_D3CFGR_D3PPRE_1       0x00000020
  #define RCC_D3CFGR_D3PPRE_2       0x00000040
  #define RCC_D3CFGR_D3PPRE_DIV1    0x00000000	/* APB4 clock not divided */
  #define RCC_D3CFGR_D3PPRE_DIV2    0x00000040	/* APB4 clock divided by 2 */
  #define RCC_D3CFGR_D3PPRE_DIV4    0x00000050	/* APB4 clock divided by 4 */
  #define RCC_D3CFGR_D3PPRE_DIV8    0x00000060	/* APB4 clock divided by 8 */
  #define RCC_D3CFGR_D3PPRE_DIV16   0x00000070	/* APB4 clock divided by 16 */
#define TOFF_RCC_PLLCKSELR  0x0028	/* (RW) RCC PLLs Clock Source Selection Register */
  #define RCC_PLLCKSELR_PLLSRC      0x00000003
  #define RCC_PLLCKSELR_PLLSRC_HSI  0x00000000	/* HSI source clock selected */
  #define RCC_PLLCKSELR_PLLSRC_CSI  0x00000001	/* CSI source clock selected */
  #define RCC_PLLCKSELR_PLLSRC_HSE  0x00000002	/* HSE source clock selected */
  #define RCC_PLLCKSELR_PLLSRC_NONE 0x00000003	/* No source clock selected  */
  #define RCC_PLLCKSELR_DIVM1       0x000003F0
  #define RCC_PLLCKSELR_DIVM1_0     0x00000010
  #define RCC_PLLCKSELR_DIVM1_1     0x00000020
  #define RCC_PLLCKSELR_DIVM1_2     0x00000040
  #define RCC_PLLCKSELR_DIVM1_3     0x00000080
  #define RCC_PLLCKSELR_DIVM1_4     0x00000100
  #define RCC_PLLCKSELR_DIVM1_5     0x00000200
  #define RCC_PLLCKSELR_DIVM2       0x0003F000
  #define RCC_PLLCKSELR_DIVM2_0     0x00001000
  #define RCC_PLLCKSELR_DIVM2_1     0x00002000
  #define RCC_PLLCKSELR_DIVM2_2     0x00004000
  #define RCC_PLLCKSELR_DIVM2_3     0x00008000
  #define RCC_PLLCKSELR_DIVM2_4     0x00010000
  #define RCC_PLLCKSELR_DIVM2_5     0x00020000
  #define RCC_PLLCKSELR_DIVM3       0x03F00000
  #define RCC_PLLCKSELR_DIVM3_0     0x00100000
  #define RCC_PLLCKSELR_DIVM3_1     0x00200000
  #define RCC_PLLCKSELR_DIVM3_2     0x00400000
  #define RCC_PLLCKSELR_DIVM3_3     0x00800000
  #define RCC_PLLCKSELR_DIVM3_4     0x01000000
  #define RCC_PLLCKSELR_DIVM3_5     0x02000000
#define TOFF_RCC_PLLCFGR    0x002C	/* (RW) RCC PLLs  Configuration Register */
  #define RCC_PLLCFGR_PLL1FRACEN    0x00000001
  #define RCC_PLLCFGR_PLL1VCOSEL    0x00000002
  #define RCC_PLLCFGR_PLL1RGE       0x0000000C
  #define RCC_PLLCFGR_PLL1RGE_0     0x00000000
  #define RCC_PLLCFGR_PLL1RGE_1     0x00000004
  #define RCC_PLLCFGR_PLL1RGE_2     0x00000008
  #define RCC_PLLCFGR_PLL1RGE_3     0x0000000C
  #define RCC_PLLCFGR_PLL2FRACEN    0x00000010
  #define RCC_PLLCFGR_PLL2VCOSEL    0x00000020
  #define RCC_PLLCFGR_PLL2RGE       0x000000C0
  #define RCC_PLLCFGR_PLL2RGE_0     0x00000000
  #define RCC_PLLCFGR_PLL2RGE_1     0x00000040
  #define RCC_PLLCFGR_PLL2RGE_2     0x00000080
  #define RCC_PLLCFGR_PLL2RGE_3     0x000000C0
  #define RCC_PLLCFGR_PLL3FRACEN    0x00000100
  #define RCC_PLLCFGR_PLL3VCOSEL    0x00000200
  #define RCC_PLLCFGR_PLL3RGE       0x00000C00
  #define RCC_PLLCFGR_PLL3RGE_0     0x00000000
  #define RCC_PLLCFGR_PLL3RGE_1     0x00000400
  #define RCC_PLLCFGR_PLL3RGE_2     0x00000800
  #define RCC_PLLCFGR_PLL3RGE_3     0x00000C00
  #define RCC_PLLCFGR_DIVP1EN       0x00010000
  #define RCC_PLLCFGR_DIVQ1EN       0x00020000
  #define RCC_PLLCFGR_DIVR1EN       0x00040000
  #define RCC_PLLCFGR_DIVP2EN       0x00080000
  #define RCC_PLLCFGR_DIVQ2EN       0x00100000
  #define RCC_PLLCFGR_DIVR2EN       0x00200000
  #define RCC_PLLCFGR_DIVP3EN       0x00400000
  #define RCC_PLLCFGR_DIVQ3EN       0x00800000
  #define RCC_PLLCFGR_DIVR3EN       0x01000000
#define TOFF_RCC_PLL1DIVR   0x0030	/* (RW) RCC PLL1 Dividers Configuration Register */
  #define RCC_PLL1DIVR_N1           0x000001FF
  #define RCC_PLL1DIVR_P1           0x0000FE00
  #define RCC_PLL1DIVR_Q1           0x007F0000
  #define RCC_PLL1DIVR_R1           0x7F000000
#define TOFF_RCC_PLL1FRACR  0x0034	/* (RW) RCC PLL1 Fractional Divider Configuration Register */
  #define RCC_PLL1FRACR_FRACN1      0x0000FFF8
#define TOFF_RCC_PLL2DIVR   0x0038	/* (RW) RCC PLL2 Dividers Configuration Register */
  #define RCC_PLL2DIVR_N2           0x000001F
  #define RCC_PLL2DIVR_P2           0x0000FE00
  #define RCC_PLL2DIVR_Q2           0x007F0000
  #define RCC_PLL2DIVR_R2           0x7F000000
#define TOFF_RCC_PLL2FRACR  0x003C	/* (RW) RCC PLL2 Fractional Divider Configuration Register */
  #define RCC_PLL2FRACR_FRACN2      0x0000FFF8
#define TOFF_RCC_PLL3DIVR   0x0040	/* (RW) RCC PLL3 Dividers Configuration Register */
  #define RCC_PLL3DIVR_N3           0x000001FF
  #define RCC_PLL3DIVR_P3           0x0000FE00
  #define RCC_PLL3DIVR_Q3           0x007F0000
  #define RCC_PLL3DIVR_R3           0x7F000000
#define TOFF_RCC_PLL3FRACR  0x0044	/* (RW) RCC PLL3 Fractional Divider Configuration Register */
  #define RCC_PLL3FRACR_FRACN3      0x0000FFF8
#define TOFF_RCC_D1CCIPR    0x004C	/* (RW) RCC Domain 1 Kernel Clock Configuration Register  */
  #define RCC_D1CCIPR_FMCSEL        0x00000003
  #define RCC_D1CCIPR_FMCSEL_0      0x00000001
  #define RCC_D1CCIPR_FMCSEL_1      0x00000002
  #define RCC_D1CCIPR_QSPISEL       0x00000030
  #define RCC_D1CCIPR_QSPISEL_0     0x00000010
  #define RCC_D1CCIPR_QSPISEL_1     0x00000020
  #define RCC_D1CCIPR_SDMMCSEL      0x00010000
  #define RCC_D1CCIPR_CKPERSEL      0x30000000
  #define RCC_D1CCIPR_CKPERSEL_0    0x10000000
  #define RCC_D1CCIPR_CKPERSEL_1    0x20000000
#define TOFF_RCC_D2CCIP1R   0x0050	/* (RW) RCC Domain 2 Kernel Clock Configuration Register  */
  #define RCC_D2CCIP1R_SAI1SEL      0x00000007
  #define RCC_D2CCIP1R_SAI1SEL_0    0x00000001
  #define RCC_D2CCIP1R_SAI1SEL_1    0x00000002
  #define RCC_D2CCIP1R_SAI1SEL_2    0x00000004
  #define RCC_D2CCIP1R_SAI23SEL     0x000001C0
  #define RCC_D2CCIP1R_SAI23SEL_0   0x00000040
  #define RCC_D2CCIP1R_SAI23SEL_1   0x00000080
  #define RCC_D2CCIP1R_SAI23SEL_2   0x00000100
  #define RCC_D2CCIP1R_SPI123SEL    0x00007000
  #define RCC_D2CCIP1R_SPI123SEL_0  0x00001000
  #define RCC_D2CCIP1R_SPI123SEL_1  0x00002000
  #define RCC_D2CCIP1R_SPI123SEL_2  0x00004000
  #define RCC_D2CCIP1R_SPI45SEL     0x00070000
  #define RCC_D2CCIP1R_SPI45SEL_0   0x00010000
  #define RCC_D2CCIP1R_SPI45SEL_1   0x00020000
  #define RCC_D2CCIP1R_SPI45SEL_2   0x00040000
  #define RCC_D2CCIP1R_SPDIFSEL     0x00300000
  #define RCC_D2CCIP1R_SPDIFSEL_0   0x00100000
  #define RCC_D2CCIP1R_SPDIFSEL_1   0x00200000
  #define RCC_D2CCIP1R_DFSDM1SEL    0x01000000
  #define RCC_D2CCIP1R_FDCANSEL     0x30000000
  #define RCC_D2CCIP1R_FDCANSEL_0   0x10000000
  #define RCC_D2CCIP1R_FDCANSEL_1   0x20000000
  #define RCC_D2CCIP1R_SWPSEL       0x80000000
#define TOFF_RCC_D2CCIP2R   0x0054	/* (RW) RCC Domain 2 Kernel Clock Configuration Register  */
  #define RCC_D2CCIP2R_USART28SEL   0x00000007
  #define RCC_D2CCIP2R_USART28SEL_0 0x00000001
  #define RCC_D2CCIP2R_USART28SEL_1 0x00000002
  #define RCC_D2CCIP2R_USART28SEL_2 0x00000004
  #define RCC_D2CCIP2R_USART16SEL   0x00000038
  #define RCC_D2CCIP2R_USART16SEL_0 0x00000008
  #define RCC_D2CCIP2R_USART16SEL_1 0x00000010
  #define RCC_D2CCIP2R_USART16SEL_2 0x00000020
  #define RCC_D2CCIP2R_RNGSEL       0x00000300
  #define RCC_D2CCIP2R_RNGSEL_0     0x00000100
  #define RCC_D2CCIP2R_RNGSEL_1     0x00000200
  #define RCC_D2CCIP2R_I2C123SEL    0x00003000
  #define RCC_D2CCIP2R_I2C123SEL_0  0x00001000
  #define RCC_D2CCIP2R_I2C123SEL_1  0x00002000
  #define RCC_D2CCIP2R_USBSEL       0x00300000
  #define RCC_D2CCIP2R_USBSEL_0     0x00100000
  #define RCC_D2CCIP2R_USBSEL_1     0x00200000
  #define RCC_D2CCIP2R_CECSEL       0x00C00000
  #define RCC_D2CCIP2R_CECSEL_0     0x00400000
  #define RCC_D2CCIP2R_CECSEL_1     0x00800000
  #define RCC_D2CCIP2R_LPTIM1SEL    0x70000000
  #define RCC_D2CCIP2R_LPTIM1SEL_0  0x10000000
  #define RCC_D2CCIP2R_LPTIM1SEL_1  0x20000000
  #define RCC_D2CCIP2R_LPTIM1SEL_2  0x40000000
#define TOFF_RCC_D3CCIPR    0x0058	/* (RW) RCC Domain 3 Kernel Clock Configuration Register  */
  #define RCC_D3CCIPR_LPUART1SEL    0x00000007
  #define RCC_D3CCIPR_LPUART1SEL_0  0x00000001
  #define RCC_D3CCIPR_LPUART1SEL_1  0x00000002
  #define RCC_D3CCIPR_LPUART1SEL_2  0x00000004
  #define RCC_D3CCIPR_I2C4SEL       0x00000300
  #define RCC_D3CCIPR_I2C4SEL_0     0x00000100
  #define RCC_D3CCIPR_I2C4SEL_1     0x00000200
  #define RCC_D3CCIPR_LPTIM2SEL     0x00001C00
  #define RCC_D3CCIPR_LPTIM2SEL_0   0x00000400
  #define RCC_D3CCIPR_LPTIM2SEL_1   0x00000800
  #define RCC_D3CCIPR_LPTIM2SEL_2   0x00001000
  #define RCC_D3CCIPR_LPTIM345SEL   0x0000E000
  #define RCC_D3CCIPR_LPTIM345SEL_0 0x00002000
  #define RCC_D3CCIPR_LPTIM345SEL_1 0x00004000
  #define RCC_D3CCIPR_LPTIM345SEL_2 0x00008000
  #define RCC_D3CCIPR_SAI4ASEL      0x00E00000
  #define RCC_D3CCIPR_SAI4ASEL_0    0x00200000
  #define RCC_D3CCIPR_SAI4ASEL_1    0x00400000
  #define RCC_D3CCIPR_SAI4ASEL_2    0x00800000
  #define RCC_D3CCIPR_SAI4BSEL      0x07000000
  #define RCC_D3CCIPR_SAI4BSEL_0    0x01000000
  #define RCC_D3CCIPR_SAI4BSEL_1    0x02000000
  #define RCC_D3CCIPR_SAI4BSEL_2    0x04000000
  #define RCC_D3CCIPR_ADCSEL        0x00030000
  #define RCC_D3CCIPR_ADCSEL_0      0x00010000
  #define RCC_D3CCIPR_ADCSEL_1      0x00020000
  #define RCC_D3CCIPR_SPI6SEL       0x70000000
  #define RCC_D3CCIPR_SPI6SEL_0     0x10000000
  #define RCC_D3CCIPR_SPI6SEL_1     0x20000000
  #define RCC_D3CCIPR_SPI6SEL_2     0x40000000
#define TOFF_RCC_CIER       0x0060	/* (RW) RCC Clock Source Interrupt Enable Register */
  #define RCC_CIER_LSIRDYIE         0x00000001
  #define RCC_CIER_LSERDYIE         0x00000002
  #define RCC_CIER_HSIRDYIE         0x00000004
  #define RCC_CIER_HSERDYIE         0x00000008
  #define RCC_CIER_CSIRDYIE         0x00000010
  #define RCC_CIER_HSI48RDYIE       0x00000020
  #define RCC_CIER_PLL1RDYIE        0x00000040
  #define RCC_CIER_PLL2RDYIE        0x00000080
  #define RCC_CIER_PLL3RDYIE        0x00000100
  #define RCC_CIER_LSECSSIE         0x00000200
#define TOFF_RCC_CIFR       0x0064	/* (RW) RCC Clock Source Interrupt Flag Register */
  #define RCC_CIFR_LSIRDYF          0x00000001
  #define RCC_CIFR_LSERDYF          0x00000002
  #define RCC_CIFR_HSIRDYF          0x00000004
  #define RCC_CIFR_HSERDYF          0x00000008
  #define RCC_CIFR_CSIRDYF          0x00000010
  #define RCC_CIFR_HSI48RDYF        0x00000020
  #define RCC_CIFR_PLLRDYF          0x00000040
  #define RCC_CIFR_PLL2RDYF         0x00000080
  #define RCC_CIFR_PLL3RDYF         0x00000100
  #define RCC_CIFR_LSECSSF          0x00000200
  #define RCC_CIFR_HSECSSF          0x00000400
#define TOFF_RCC_CICR       0x0068	/* (RW) RCC Clock Source Interrupt Clear Register */
  #define RCC_CICR_LSIRDYC          0x00000001
  #define RCC_CICR_LSERDYC          0x00000002
  #define RCC_CICR_HSIRDYC          0x00000004
  #define RCC_CICR_HSERDYC          0x00000008
  #define RCC_CICR_CSIRDYC          0x00000010
  #define RCC_CICR_HSI48RDYC        0x00000020
  #define RCC_CICR_PLLRDYC          0x00000040
  #define RCC_CICR_PLL2RDYC         0x00000080
  #define RCC_CICR_PLL3RDYC         0x00000100
  #define RCC_CICR_LSECSSC          0x00000200
  #define RCC_CICR_HSECSSC          0x00000400
#define TOFF_RCC_BDCR       0x0070	/* (RW) RCC Vswitch Backup Domain Control Register */
  #define RCC_BDCR_LSEON            0x00000001
  #define RCC_BDCR_LSERDY           0x00000002
  #define RCC_BDCR_LSEBYP           0x00000004
  #define RCC_BDCR_LSEDRV           0x00000018
  #define RCC_BDCR_LSEDRV_0         0x00000008
  #define RCC_BDCR_LSEDRV_1         0x00000010
  #define RCC_BDCR_LSECSSON         0x00000020
  #define RCC_BDCR_LSECSSD          0x00000040
  #define RCC_BDCR_RTCSEL           0x00000300
  #define RCC_BDCR_RTCSEL_0         0x00000100
  #define RCC_BDCR_RTCSEL_1         0x00000200
  #define RCC_BDCR_RTCEN            0x00008000
  #define RCC_BDCR_BDRST            0x00010000
#define TOFF_RCC_CSR        0x0074	/* (RW) RCC clock control & status register */
  #define RCC_CSR_LSION             0x00000001
  #define RCC_CSR_LSIRDY            0x00000002
#define TOFF_RCC_AHB3RSTR   0x007C	/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_MDMARST      0x00000001
  #define RCC_AHB3RSTR_DMA2DRST     0x00000010
  #define RCC_AHB3RSTR_JPGDECRST    0x00000020
  #define RCC_AHB3RSTR_FMCRST       0x00001000
  #define RCC_AHB3RSTR_QSPIRST      0x00004000
  #define RCC_AHB3RSTR_SDMMC1RST    0x00010000
#define TOFF_RCC_AHB1RSTR   0x0080	/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_DMA1RST      0x00000001
  #define RCC_AHB1RSTR_DMA2RST      0x00000002
  #define RCC_AHB1RSTR_ADC12RST     0x00000020
  #define RCC_AHB1RSTR_ETH1MACRST   0x00008000
  #define RCC_AHB1RSTR_USB1OTGHSRST 0x02000000
  #define RCC_AHB1RSTR_USB2OTGFSRST 0x08000000
  #define RCC_AHB1RSTR_USB2OTGHSRST RCC_AHB1RSTR_USB2OTGFSRST
#define TOFF_RCC_AHB2RSTR   0x0084	/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_DCMIRST      0x00000001
  #define RCC_AHB2RSTR_CRYPRST      0x00000010
  #define RCC_AHB2RSTR_HASHRST      0x00000020
  #define RCC_AHB2RSTR_RNGRST       0x00000040
  #define RCC_AHB2RSTR_SDMMC2RST    0x00000200
#define TOFF_RCC_AHB4RSTR   0x0088	/* (RW) RCC AHB4 peripheral reset register */
  #define RCC_AHB4RSTR_GPIOARST     0x00000001
  #define RCC_AHB4RSTR_GPIOBRST     0x00000002
  #define RCC_AHB4RSTR_GPIOCRST     0x00000004
  #define RCC_AHB4RSTR_GPIODRST     0x00000008
  #define RCC_AHB4RSTR_GPIOERST     0x00000010
  #define RCC_AHB4RSTR_GPIOFRST     0x00000020
  #define RCC_AHB4RSTR_GPIOGRST     0x00000040
  #define RCC_AHB4RSTR_GPIOHRST     0x00000080
  #define RCC_AHB4RSTR_GPIOIRST     0x00000100
  #define RCC_AHB4RSTR_GPIOJRST     0x00000200
  #define RCC_AHB4RSTR_GPIOKRST     0x00000400
  #define RCC_AHB4RSTR_CRCRST       0x00080000
  #define RCC_AHB4RSTR_BDMARST      0x00200000
  #define RCC_AHB4RSTR_ADC3RST      0x01000000
  #define RCC_AHB4RSTR_HSEMRST      0x02000000
#define TOFF_RCC_APB3RSTR   0x008C	/* (RW) RCC APB3 peripheral reset register */
  #define RCC_APB3RSTR_LTDCRST      0x00000008
#define TOFF_RCC_APB1LRSTR  0x0090	/* (RW) RCC APB1 peripheral reset Low Word register */
  #define RCC_APB1LRSTR_TIM2RST     0x00000001
  #define RCC_APB1LRSTR_TIM3RST     0x00000002
  #define RCC_APB1LRSTR_TIM4RST     0x00000004
  #define RCC_APB1LRSTR_TIM5RST     0x00000008
  #define RCC_APB1LRSTR_TIM6RST     0x00000010
  #define RCC_APB1LRSTR_TIM7RST     0x00000020
  #define RCC_APB1LRSTR_TIM12RST    0x00000040
  #define RCC_APB1LRSTR_TIM13RST    0x00000080
  #define RCC_APB1LRSTR_TIM14RST    0x00000100
  #define RCC_APB1LRSTR_LPTIM1RST   0x00000200
  #define RCC_APB1LRSTR_SPI2RST     0x00004000
  #define RCC_APB1LRSTR_SPI3RST     0x00008000
  #define RCC_APB1LRSTR_SPDIFRXRST  0x00010000
  #define RCC_APB1LRSTR_USART2RST   0x00020000
  #define RCC_APB1LRSTR_USART3RST   0x00040000
  #define RCC_APB1LRSTR_UART4RST    0x00080000
  #define RCC_APB1LRSTR_UART5RST    0x00100000
  #define RCC_APB1LRSTR_I2C1RST     0x00200000
  #define RCC_APB1LRSTR_I2C2RST     0x00400000
  #define RCC_APB1LRSTR_I2C3RST     0x00800000
  #define RCC_APB1LRSTR_CECRST      0x08000000
  #define RCC_APB1LRSTR_DAC12RST    0x20000000
  #define RCC_APB1LRSTR_UART7RST    0x40000000
  #define RCC_APB1LRSTR_UART8RST    0x80000000
#define TOFF_RCC_APB1HRSTR  0x0094	/* (RW) RCC APB1 peripheral reset High Word register */
  #define RCC_APB1HRSTR_CRSRST      0x00000002
  #define RCC_APB1HRSTR_SWPMIRST    0x00000004
  #define RCC_APB1HRSTR_OPAMPRST    0x00000010
  #define RCC_APB1HRSTR_MDIOSRST    0x00000020
  #define RCC_APB1HRSTR_FDCANRST    0x00000100
#define TOFF_RCC_APB2RSTR   0x0098	/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_TIM1RST      0x00000001
  #define RCC_APB2RSTR_TIM8RST      0x00000002
  #define RCC_APB2RSTR_USART1RST    0x00000010
  #define RCC_APB2RSTR_USART6RST    0x00000020
  #define RCC_APB2RSTR_SPI1RST      0x00001000
  #define RCC_APB2RSTR_SPI4RST      0x00002000
  #define RCC_APB2RSTR_TIM15RST     0x00010000
  #define RCC_APB2RSTR_TIM16RST     0x00020000
  #define RCC_APB2RSTR_TIM17RST     0x00040000
  #define RCC_APB2RSTR_SPI5RST      0x00100000
  #define RCC_APB2RSTR_SAI1RST      0x00400000
  #define RCC_APB2RSTR_SAI2RST      0x00800000
  #define RCC_APB2RSTR_SAI3RST      0x01000000
  #define RCC_APB2RSTR_DFSDM1RST    0x10000000
  #define RCC_APB2RSTR_HRTIMRST     0x20000000 
#define TOFF_RCC_APB4RSTR   0x009C	/* (RW) RCC APB4 peripheral reset register */
  #define RCC_APB4RSTR_SYSCFGRST    0x00000002
  #define RCC_APB4RSTR_LPUART1RST   0x00000008
  #define RCC_APB4RSTR_SPI6RST      0x00000020
  #define RCC_APB4RSTR_I2C4RST      0x00000080
  #define RCC_APB4RSTR_LPTIM2RST    0x00000200
  #define RCC_APB4RSTR_LPTIM3RST    0x00000400
  #define RCC_APB4RSTR_LPTIM4RST    0x00000800
  #define RCC_APB4RSTR_LPTIM5RST    0x00001000
  #define RCC_APB4RSTR_COMP12RST    0x00004000
  #define RCC_APB4RSTR_VREFRST      0x00008000
  #define RCC_APB4RSTR_SAI4RST      0x00200000
#define TOFF_RCC_GCR        0x00A0	/* (RW) RCC RCC Global Control  Register */
  #define RCC_GCR_WW1RSC            0x00000001
#define TOFF_RCC_D3AMR      0x00A8	/* (RW) RCC Domain 3 Autonomous Mode Register */
  #define RCC_D3AMR_BDMAAMEN        0x00000001
  #define RCC_D3AMR_LPUART1AMEN     0x00000008
  #define RCC_D3AMR_SPI6AMEN        0x00000020
  #define RCC_D3AMR_I2C4AMEN        0x00000080
  #define RCC_D3AMR_LPTIM2AMEN      0x00000200
  #define RCC_D3AMR_LPTIM3AMEN      0x00000400
  #define RCC_D3AMR_LPTIM4AMEN      0x00000800
  #define RCC_D3AMR_LPTIM5AMEN      0x00001000
  #define RCC_D3AMR_COMP12AMEN      0x00004000
  #define RCC_D3AMR_VREFAMEN        0x00008000
  #define RCC_D3AMR_RTCAMEN         0x00010000
  #define RCC_D3AMR_CRCAMEN         0x00080000
  #define RCC_D3AMR_SAI4AMEN        0x00200000
  #define RCC_D3AMR_ADC3AMEN        0x01000000
  #define RCC_D3AMR_BKPRAMAMEN      0x10000000
  #define RCC_D3AMR_SRAM4AMEN       0x20000000
#define TOFF_RCC_RSR        0x00D0	/* (RW) RCC Reset status register */
  #define RCC_RSR_RMVF              0x00010000
  #define RCC_RSR_CPURSTF           0x00020000
  #define RCC_RSR_D1RSTF            0x00080000
  #define RCC_RSR_D2RSTF            0x00100000
  #define RCC_RSR_BORRSTF           0x00200000
  #define RCC_RSR_PINRSTF           0x00400000
  #define RCC_RSR_PORRSTF           0x00800000
  #define RCC_RSR_SFTRSTF           0x01000000
  #define RCC_RSR_IWDG1RSTF         0x04000000
  #define RCC_RSR_WWDG1RSTF         0x10000000
  #define RCC_RSR_LPWRRSTF          0x40000000
#define TOFF_RCC_AHB3ENR    0x00D4	/* (RW) RCC AHB3 peripheral clock  register */
  #define RCC_AHB3ENR_MDMAEN        0x00000001
  #define RCC_AHB3ENR_DMA2DEN       0x00000010
  #define RCC_AHB3ENR_JPGDECEN      0x00000020
  #define RCC_AHB3ENR_FMCEN         0x00001000
  #define RCC_AHB3ENR_QSPIEN        0x00004000
  #define RCC_AHB3ENR_SDMMC1EN      0x00010000
#define TOFF_RCC_AHB1ENR    0x00D8	/* (RW) RCC AHB1 peripheral clock  register */
  #define RCC_AHB1ENR_DMA1EN        0x00000001
  #define RCC_AHB1ENR_DMA2EN        0x00000002
  #define RCC_AHB1ENR_ADC12EN       0x00000020
  #define RCC_AHB1ENR_ETH1MACEN     0x00008000
  #define RCC_AHB1ENR_ETH1TXEN      0x00010000
  #define RCC_AHB1ENR_ETH1RXEN      0x00020000
  #define RCC_AHB1ENR_USB1OTGHSEN   0x02000000
  #define RCC_AHB1ENR_USB1OTGHSULPIEN 0x04000000
  #define RCC_AHB1ENR_USB2OTGFSEN   0x08000000
  #define RCC_AHB1ENR_USB2OTGFSULPIEN 0x10000000
  #define RCC_AHB1ENR_USB2OTGHSEN     RCC_AHB1ENR_USB2OTGFSEN
  #define RCC_AHB1ENR_USB2OTGHSULPIEN RCC_AHB1ENR_USB2OTGFSULPIEN
#define TOFF_RCC_AHB2ENR    0x00DC	/* (RW) RCC AHB2 peripheral clock  register */
  #define RCC_AHB2ENR_DCMIEN        0x00000001
  #define RCC_AHB2ENR_CRYPEN        0x00000010
  #define RCC_AHB2ENR_HASHEN        0x00000020
  #define RCC_AHB2ENR_RNGEN         0x00000040
  #define RCC_AHB2ENR_SDMMC2EN      0x00000200
  #define RCC_AHB2ENR_D2SRAM1EN     0x20000000
  #define RCC_AHB2ENR_D2SRAM2EN     0x40000000
  #define RCC_AHB2ENR_D2SRAM3EN     0x80000000
#define TOFF_RCC_AHB4ENR    0x00E0	/* (RW) RCC AHB4 peripheral clock  register */
  #define RCC_AHB4ENR_GPIOAEN       0x00000001
  #define RCC_AHB4ENR_GPIOBEN       0x00000002
  #define RCC_AHB4ENR_GPIOCEN       0x00000004
  #define RCC_AHB4ENR_GPIODEN       0x00000008
  #define RCC_AHB4ENR_GPIOEEN       0x00000010
  #define RCC_AHB4ENR_GPIOFEN       0x00000020
  #define RCC_AHB4ENR_GPIOGEN       0x00000040
  #define RCC_AHB4ENR_GPIOHEN       0x00000080
  #define RCC_AHB4ENR_GPIOIEN       0x00000100
  #define RCC_AHB4ENR_GPIOJEN       0x00000200
  #define RCC_AHB4ENR_GPIOKEN       0x00000400
  #define RCC_AHB4ENR_CRCEN         0x00080000
  #define RCC_AHB4ENR_BDMAEN        0x00200000
  #define RCC_AHB4ENR_ADC3EN        0x01000000
  #define RCC_AHB4ENR_HSEMEN        0x02000000
  #define RCC_AHB4ENR_BKPRAMEN      0x10000000
  #define RCC_AHB4ENR_D3SRAM1EN     0x20000000
#define TOFF_RCC_APB3ENR    0x00E4	/* (RW) RCC APB3 peripheral clock  register */
  #define RCC_APB3ENR_LTDCEN        0x00000008
  #define RCC_APB3ENR_WWDG1EN       0x00000040
#define TOFF_RCC_APB1LENR   0x00E8	/* (RW) RCC APB1 peripheral clock  Low Word register */
  #define RCC_APB1LENR_TIM2EN       0x00000001
  #define RCC_APB1LENR_TIM3EN       0x00000002
  #define RCC_APB1LENR_TIM4EN       0x00000004
  #define RCC_APB1LENR_TIM5EN       0x00000008
  #define RCC_APB1LENR_TIM6EN       0x00000010
  #define RCC_APB1LENR_TIM7EN       0x00000020
  #define RCC_APB1LENR_TIM12EN      0x00000040
  #define RCC_APB1LENR_TIM13EN      0x00000080
  #define RCC_APB1LENR_TIM14EN      0x00000100
  #define RCC_APB1LENR_LPTIM1EN     0x00000200
  #define RCC_APB1LENR_SPI2EN       0x00004000
  #define RCC_APB1LENR_SPI3EN       0x00008000
  #define RCC_APB1LENR_SPDIFRXEN    0x00010000
  #define RCC_APB1LENR_USART2EN     0x00020000
  #define RCC_APB1LENR_USART3EN     0x00040000
  #define RCC_APB1LENR_UART4EN      0x00080000
  #define RCC_APB1LENR_UART5EN      0x00100000
  #define RCC_APB1LENR_I2C1EN       0x00200000
  #define RCC_APB1LENR_I2C2EN       0x00400000
  #define RCC_APB1LENR_I2C3EN       0x00800000
  #define RCC_APB1LENR_CECEN        0x08000000
  #define RCC_APB1LENR_DAC12EN      0x20000000
  #define RCC_APB1LENR_UART7EN      0x40000000
  #define RCC_APB1LENR_UART8EN      0x80000000
#define TOFF_RCC_APB1HENR   0x00EC	/* (RW) RCC APB1 peripheral clock  High Word register */
  #define RCC_APB1HENR_CRSEN        0x00000002
  #define RCC_APB1HENR_SWPMIEN      0x00000004
  #define RCC_APB1HENR_OPAMPEN      0x00000010
  #define RCC_APB1HENR_MDIOSEN      0x00000020
  #define RCC_APB1HENR_FDCANEN      0x00000100
#define TOFF_RCC_APB2ENR    0x00F0	/* (RW) RCC APB2 peripheral clock  register */
  #define RCC_APB2ENR_TIM1EN        0x00000001
  #define RCC_APB2ENR_TIM8EN        0x00000002
  #define RCC_APB2ENR_USART1EN      0x00000010
  #define RCC_APB2ENR_USART6EN      0x00000020
  #define RCC_APB2ENR_SPI1EN        0x00001000
  #define RCC_APB2ENR_SPI4EN        0x00002000
  #define RCC_APB2ENR_TIM15EN       0x00010000
  #define RCC_APB2ENR_TIM16EN       0x00020000
  #define RCC_APB2ENR_TIM17EN       0x00040000
  #define RCC_APB2ENR_SPI5EN        0x00100000
  #define RCC_APB2ENR_SAI1EN        0x00400000
  #define RCC_APB2ENR_SAI2EN        0x00800000
  #define RCC_APB2ENR_SAI3EN        0x01000000
  #define RCC_APB2ENR_DFSDM1EN      0x10000000
  #define RCC_APB2ENR_HRTIMEN       0x20000000
#define TOFF_RCC_APB4ENR    0x00F4	/* (RW) RCC APB4 peripheral clock  register */
  #define RCC_APB4ENR_SYSCFGEN      0x00000002
  #define RCC_APB4ENR_LPUART1EN     0x00000008
  #define RCC_APB4ENR_SPI6EN        0x00000020
  #define RCC_APB4ENR_I2C4EN        0x00000080
  #define RCC_APB4ENR_LPTIM2EN      0x00000200
  #define RCC_APB4ENR_LPTIM3EN      0x00000400
  #define RCC_APB4ENR_LPTIM4EN      0x00000800
  #define RCC_APB4ENR_LPTIM5EN      0x00001000
  #define RCC_APB4ENR_COMP12EN      0x00004000
  #define RCC_APB4ENR_VREFEN        0x00008000
  #define RCC_APB4ENR_RTCAPBEN      0x00010000
  #define RCC_APB4ENR_SAI4EN        0x00200000
#define TOFF_RCC_AHB3LPENR  0x00FC	/* (RW) RCC AHB3 peripheral sleep clock  register */
  #define RCC_AHB3LPENR_MDMALPEN    0x00000001
  #define RCC_AHB3LPENR_DMA2DLPEN   0x00000010
  #define RCC_AHB3LPENR_JPGDECLPEN  0x00000020
  #define RCC_AHB3LPENR_FLASHLPEN   0x00000100
  #define RCC_AHB3LPENR_FMCLPEN     0x00001000
  #define RCC_AHB3LPENR_QSPILPEN    0x00004000
  #define RCC_AHB3LPENR_SDMMC1LPEN  0x00010000
  #define RCC_AHB3LPENR_DTCM1LPEN   0x10000000
  #define RCC_AHB3LPENR_DTCM2LPEN   0x20000000
  #define RCC_AHB3LPENR_ITCMLPEN    0x40000000
  #define RCC_AHB3LPENR_AXISRAMLPEN 0x80000000
#define TOFF_RCC_AHB1LPENR  0x0100	/* (RW) RCC AHB1 peripheral sleep clock  register */
  #define RCC_AHB1LPENR_DMA1LPEN    0x00000001
  #define RCC_AHB1LPENR_DMA2LPEN    0x00000002
  #define RCC_AHB1LPENR_ADC12LPEN   0x00000020
  #define RCC_AHB1LPENR_ETH1MACLPEN 0x00008000
  #define RCC_AHB1LPENR_ETH1TXLPEN  0x00010000
  #define RCC_AHB1LPENR_ETH1RXLPEN  0x00020000
  #define RCC_AHB1LPENR_USB1OTGHSLPEN     0x02000000
  #define RCC_AHB1LPENR_USB1OTGHSULPILPEN 0x04000000
  #define RCC_AHB1LPENR_USB2OTGFSLPEN     0x08000000
  #define RCC_AHB1LPENR_USB2OTGFSULPILPEN 0x10000000
  #define RCC_AHB1LPENR_USB2OTGHSLPEN     RCC_AHB1LPENR_USB2OTGFSLPEN
  #define RCC_AHB1LPENR_USB2OTGHSULPILPEN RCC_AHB1LPENR_USB2OTGFSULPILPEN
#define TOFF_RCC_AHB2LPENR  0x0104	/* (RW) RCC AHB2 peripheral sleep clock  register */
  #define RCC_AHB2LPENR_DCMILPEN    0x00000001
  #define RCC_AHB2LPENR_CRYPLPEN    0x00000010
  #define RCC_AHB2LPENR_HASHLPEN    0x00000020
  #define RCC_AHB2LPENR_RNGLPEN     0x00000040
  #define RCC_AHB2LPENR_SDMMC2LPEN  0x00000200
  #define RCC_AHB2LPENR_D2SRAM1LPEN 0x40000000
  #define RCC_AHB2LPENR_D2SRAM2LPEN 0x40000000
  #define RCC_AHB2LPENR_D2SRAM3LPEN 0x80000000
#define TOFF_RCC_AHB4LPENR  0x0108	/* (RW) RCC AHB4 peripheral sleep clock  register */
  #define RCC_AHB4LPENR_GPIOALPEN   0x00000001
  #define RCC_AHB4LPENR_GPIOBLPEN   0x00000002
  #define RCC_AHB4LPENR_GPIOCLPEN   0x00000004
  #define RCC_AHB4LPENR_GPIODLPEN   0x00000008
  #define RCC_AHB4LPENR_GPIOELPEN   0x00000010
  #define RCC_AHB4LPENR_GPIOFLPEN   0x00000020
  #define RCC_AHB4LPENR_GPIOGLPEN   0x00000040
  #define RCC_AHB4LPENR_GPIOHLPEN   0x00000080
  #define RCC_AHB4LPENR_GPIOILPEN   0x00000100
  #define RCC_AHB4LPENR_GPIOJLPEN   0x00000200
  #define RCC_AHB4LPENR_GPIOKLPEN   0x00000400
  #define RCC_AHB4LPENR_CRCLPEN     0x00080000
  #define RCC_AHB4LPENR_BDMALPEN    0x00200000
  #define RCC_AHB4LPENR_ADC3LPEN    0x01000000
  #define RCC_AHB4LPENR_BKPRAMLPEN  0x10000000
  #define RCC_AHB4LPENR_D3SRAM1LPEN 0x20000000
#define TOFF_RCC_APB3LPENR  0x010C	/* (RW) RCC APB3 peripheral sleep clock  register */
  #define RCC_APB3LPENR_LTDCLPEN    0x00000008
  #define RCC_APB3LPENR_WWDG1LPEN   0x00000040
#define TOFF_RCC_APB1LLPENR 0x0110	/* (RW) RCC APB1 peripheral sleep clock  Low Word register */
  #define RCC_APB1LLPENR_TIM2LPEN   0x00000001
  #define RCC_APB1LLPENR_TIM3LPEN   0x00000002
  #define RCC_APB1LLPENR_TIM4LPEN   0x00000004
  #define RCC_APB1LLPENR_TIM5LPEN   0x00000008
  #define RCC_APB1LLPENR_TIM6LPEN   0x00000010
  #define RCC_APB1LLPENR_TIM7LPEN   0x00000020
  #define RCC_APB1LLPENR_TIM12LPEN  0x00000040
  #define RCC_APB1LLPENR_TIM13LPEN  0x00000080
  #define RCC_APB1LLPENR_TIM14LPEN  0x00000100
  #define RCC_APB1LLPENR_LPTIM1LPEN 0x00000200
  #define RCC_APB1LLPENR_SPI2LPEN   0x00004000
  #define RCC_APB1LLPENR_SPI3LPEN   0x00008000
  #define RCC_APB1LLPENR_SPDIFRXLPEN 0x00010000
  #define RCC_APB1LLPENR_USART2LPEN 0x00020000
  #define RCC_APB1LLPENR_USART3LPEN 0x00040000
  #define RCC_APB1LLPENR_UART4LPEN  0x00080000
  #define RCC_APB1LLPENR_UART5LPEN  0x00100000
  #define RCC_APB1LLPENR_I2C1LPEN   0x00200000
  #define RCC_APB1LLPENR_I2C2LPEN   0x00400000
  #define RCC_APB1LLPENR_I2C3LPEN   0x00800000
  #define RCC_APB1LLPENR_CECLPEN    0x08000000
  #define RCC_APB1LLPENR_DAC12LPEN  0x20000000
  #define RCC_APB1LLPENR_UART7LPEN  0x40000000
  #define RCC_APB1LLPENR_UART8LPEN  0x80000000
#define TOFF_RCC_APB1HLPENR 0x0114	/* (RW) RCC APB1 peripheral sleep clock  High Word regist */
  #define RCC_APB1HLPENR_CRSLPEN    0x00000002
  #define RCC_APB1HLPENR_SWPMILPEN  0x00000004
  #define RCC_APB1HLPENR_OPAMPLPEN  0x00000010
  #define RCC_APB1HLPENR_MDIOSLPEN  0x00000020
  #define RCC_APB1HLPENR_FDCANLPEN  0x00000100
#define TOFF_RCC_APB2LPENR  0x0118	/* (RW) RCC APB2 peripheral sleep clock  register */
  #define RCC_APB2LPENR_TIM1LPEN    0x00000001
  #define RCC_APB2LPENR_TIM8LPEN    0x00000002
  #define RCC_APB2LPENR_USART1LPEN  0x00000010
  #define RCC_APB2LPENR_USART6LPEN  0x00000020
  #define RCC_APB2LPENR_SPI1LPEN    0x00001000
  #define RCC_APB2LPENR_SPI4LPEN    0x00002000
  #define RCC_APB2LPENR_TIM15LPEN   0x00010000
  #define RCC_APB2LPENR_TIM16LPEN   0x00020000
  #define RCC_APB2LPENR_TIM17LPEN   0x00040000
  #define RCC_APB2LPENR_SPI5LPEN    0x00100000
  #define RCC_APB2LPENR_SAI1LPEN    0x00400000
  #define RCC_APB2LPENR_SAI2LPEN    0x00800000
  #define RCC_APB2LPENR_SAI3LPEN    0x01000000
  #define RCC_APB2LPENR_DFSDM1LPEN  0x10000000
  #define RCC_APB2LPENR_HRTIMLPEN   0x20000000
#define TOFF_RCC_APB4LPENR  0x011C	/* (RW) RCC APB4 peripheral sleep clock  register */
  #define RCC_APB4LPENR_SYSCFGLPEN  0x00000002
  #define RCC_APB4LPENR_LPUART1LPEN 0x00000008
  #define RCC_APB4LPENR_SPI6LPEN    0x00000020
  #define RCC_APB4LPENR_I2C4LPEN    0x00000080
  #define RCC_APB4LPENR_LPTIM2LPEN  0x00000200
  #define RCC_APB4LPENR_LPTIM3LPEN  0x00000400
  #define RCC_APB4LPENR_LPTIM4LPEN  0x00000800
  #define RCC_APB4LPENR_LPTIM5LPEN  0x00001000
  #define RCC_APB4LPENR_COMP12LPEN  0x00004000
  #define RCC_APB4LPENR_VREFLPEN    0x00008000
  #define RCC_APB4LPENR_RTCAPBLPEN  0x00010000
  #define RCC_APB4LPENR_SAI4LPEN    0x00200000


/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (D1_AHB1PERIPH_BASE + 0x2000)


#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
  #define FLASH_ACR_LATENCY             0x0000000F
  #define FLASH_ACR_LATENCY_0WS         0x00000000
  #define FLASH_ACR_LATENCY_1WS         0x00000001
  #define FLASH_ACR_LATENCY_2WS         0x00000002
  #define FLASH_ACR_LATENCY_3WS         0x00000003
  #define FLASH_ACR_LATENCY_4WS         0x00000004
  #define FLASH_ACR_LATENCY_5WS         0x00000005
  #define FLASH_ACR_LATENCY_6WS         0x00000006
  #define FLASH_ACR_LATENCY_7WS         0x00000007
  #define FLASH_ACR_LATENCY_8WS         0x00000008
  #define FLASH_ACR_LATENCY_9WS         0x00000009
  #define FLASH_ACR_LATENCY_10WS        0x0000000A
  #define FLASH_ACR_LATENCY_11WS        0x0000000B
  #define FLASH_ACR_LATENCY_12WS        0x0000000C
  #define FLASH_ACR_LATENCY_13WS        0x0000000D
  #define FLASH_ACR_LATENCY_14WS        0x0000000E
  #define FLASH_ACR_LATENCY_15WS        0x0000000F
  #define FLASH_ACR_WRHIGHFREQ          0x00000030
  #define FLASH_ACR_WRHIGHFREQ_0        0x00000010
  #define FLASH_ACR_WRHIGHFREQ_1        0x00000020
#define TOFF_FLASH_KEYR1    0x0004		/* (RW) Flash Key Register for bank1 */
#define TOFF_FLASH_OPTKEYR  0x0008		/* (RW) Flash Option Key Register */
#define TOFF_FLASH_CR1      0x000C		/* (RW) Flash Control Register for bank1 */
  #define FLASH_CR_LOCK                 0x00000001
  #define FLASH_CR_PG                   0x00000002
  #define FLASH_CR_SER                  0x00000004
  #define FLASH_CR_BER                  0x00000008
  #define FLASH_CR_PSIZE                0x00000030
  #define FLASH_CR_PSIZE_0              0x00000010
  #define FLASH_CR_PSIZE_1              0x00000020
  #define FLASH_CR_FW                   0x00000040
  #define FLASH_CR_START                0x00000080
  #define FLASH_CR_SNB                  0x00000700
  #define FLASH_CR_SNB_0                0x00000100
  #define FLASH_CR_SNB_1                0x00000200
  #define FLASH_CR_SNB_2                0x00000400
  #define FLASH_CR_CRC_EN               0x00008000
  #define FLASH_CR_EOPIE                0x00010000
  #define FLASH_CR_WRPERRIE             0x00020000
  #define FLASH_CR_PGSERRIE             0x00040000
  #define FLASH_CR_STRBERRIE            0x00080000
  #define FLASH_CR_INCERRIE             0x00200000
  #define FLASH_CR_OPERRIE              0x00400000
  #define FLASH_CR_RDPERRIE             0x00800000
  #define FLASH_CR_RDSERRIE             0x01000000
  #define FLASH_CR_SNECCERRIE           0x02000000
  #define FLASH_CR_DBECCERRIE           0x04000000
  #define FLASH_CR_CRCENDIE             0x08000000
  #define FLASH_CR_CRCRDERRIE           0x10000000
#define TOFF_FLASH_SR1      0x0010		/* (RW) Flash Status Register for bank1 */
  #define FLASH_SR_BSY                  0x00000001
  #define FLASH_SR_WBNE                 0x00000002
  #define FLASH_SR_QW                   0x00000004
  #define FLASH_SR_CRC_BUSY             0x00000008
  #define FLASH_SR_EOP                  0x00010000
  #define FLASH_SR_WRPERR               0x00020000
  #define FLASH_SR_PGSERR               0x00040000
  #define FLASH_SR_STRBERR              0x00080000
  #define FLASH_SR_INCERR               0x00200000
  #define FLASH_SR_OPERR                0x00400000
  #define FLASH_SR_RDPERR               0x00800000
  #define FLASH_SR_RDSERR               0x01000000
  #define FLASH_SR_SNECCERR             0x02000000
  #define FLASH_SR_DBECCERR             0x04000000
  #define FLASH_SR_CRCEND               0x08000000
  #define FLASH_SR_CRCRDERR             0x10000000
#define TOFF_FLASH_CCR      0x0014		/* (RW) Flash Control Register for bank1 */
  #define FLASH_CCR_CLR_EOP             0x00010000
  #define FLASH_CCR_CLR_WRPERR          0x00020000
  #define FLASH_CCR_CLR_PGSERR          0x00040000
  #define FLASH_CCR_CLR_STRBERR         0x00080000
  #define FLASH_CCR_CLR_INCERR          0x00200000
  #define FLASH_CCR_CLR_OPERR           0x00400000
  #define FLASH_CCR_CLR_RDPERR          0x00800000
  #define FLASH_CCR_CLR_RDSERR          0x01000000
  #define FLASH_CCR_CLR_SNECCERR        0x02000000
  #define FLASH_CCR_CLR_DBECCERR        0x04000000
  #define FLASH_CCR_CLR_CRCEND          0x08000000
  #define FLASH_CCR_CLR_CRCRDERR        0x10000000
#define TOFF_FLASH_OPTCR    0x0018		/* (RW) Flash Option Control Register */
  #define FLASH_OPTCR_OPTLOCK           0x00000001
  #define FLASH_OPTCR_OPTSTART          0x00000002
  #define FLASH_OPTCR_MER               0x00000010
  #define FLASH_OPTCR_OPTCHANGEERRIE    0x40000000
  #define FLASH_OPTCR_SWAP_BANK         0x80000000
#define TOFF_FLASH_OPTSR_CUR 0x001C		/* (RW) Flash Option Status Current Register */
  #define FLASH_OPTSR_OPT_BUSY          0x00000001
  #define FLASH_OPTSR_BOR_LEV           0x0000000C
  #define FLASH_OPTSR_BOR_LEV_0         0x00000004
  #define FLASH_OPTSR_BOR_LEV_1         0x00000008
  #define FLASH_OPTSR_IWDG1_SW          0x00000010
  #define FLASH_OPTSR_NRST_STOP_D1      0x00000040
  #define FLASH_OPTSR_NRST_STBY_D1      0x00000080
  #define FLASH_OPTSR_RDP               0x0000FF00
  #define FLASH_OPTSR_FZ_IWDG_STOP      0x00020000
  #define FLASH_OPTSR_FZ_IWDG_SDBY      0x00040000
  #define FLASH_OPTSR_ST_RAM_SIZE       0x00180000
  #define FLASH_OPTSR_ST_RAM_SIZE_0     0x00080000
  #define FLASH_OPTSR_ST_RAM_SIZE_1     0x00100000
  #define FLASH_OPTSR_SECURITY          0x00200000
  #define FLASH_OPTSR_IO_HSLV           0x20000000
  #define FLASH_OPTSR_OPTCHANGEERR      0x40000000
  #define FLASH_OPTSR_SWAP_BANK_OPT     0x80000000
#define TOFF_FLASH_OPTSR_PRG 0x0020		/* (RW) Flash Option Status to Program Register */
#define TOFF_FLASH_OPTCCR   0x0024		/* (RW) Flash Option Clear Control Register */
  #define FLASH_OPTCCR_CLR_OPTCHANGEERR 0x40000000
#define TOFF_FLASH_PRAR_CUR1 0x0028		/* (RW) Flash Current Protection Address Register for bank1 */
  #define FLASH_PRAR_PROT_AREA_START    0x00000FFF
  #define FLASH_PRAR_PROT_AREA_END      0x0FFF0000
  #define FLASH_PRAR_DMEP               0x80000000
#define TOFF_FLASH_PRAR_PRG1 0x002C		/* (RW) Flash Protection Address to Program Register for bank1 */
#define TOFF_FLASH_SCAR_CUR1 0x0030		/* (RW) Flash Current Secure Address Register for bank1 */
  #define FLASH_SCAR_SEC_AREA_START     0x00000FFF
  #define FLASH_SCAR_SEC_AREA_END       0x0FFF0000
  #define FLASH_SCAR_DMES               0x80000000
#define TOFF_FLASH_SCAR_PRG1 0x0034		/* (RW) Flash Secure Address to Program Register for bank1 */
#define TOFF_FLASH_WPSN_CUR1 0x0038		/* (RW) Flash Current Write Protection Register on bank1 */
  #define FLASH_WPSN_WRPSN              0x000000FF
#define TOFF_FLASH_WPSN_PRG1 0x003C		/* (RW) Flash Write Protection to Program Register on bank1 */
#define TOFF_FLASH_BOOT_CUR 0x0040		/* (RW) Flash Current Boot Address for Pelican Core Register */
  #define FLASH_BOOT_ADD0               0x0000FFFF
  #define FLASH_BOOT_ADD1               0xFFFF0000
#define TOFF_FLASH_BOOT_PRG 0x0044		/* (RW) Flash Boot Address to Program for Pelican Core Register */
#define TOFF_FLASH_CRCCR    0x0050		/* (RW) Flash CRC Control register For Bank1 Register */
  #define FLASH_CRCCR_CRC_SECT          0x00000007
  #define FLASH_CRCCR_CRC_BY_SECT       0x00000100
  #define FLASH_CRCCR_ADD_SECT          0x00000200
  #define FLASH_CRCCR_CLEAN_SECT        0x00000400
  #define FLASH_CRCCR_START_CRC         0x00010000
  #define FLASH_CRCCR_CLEAN_CRC         0x00020000
  #define FLASH_CRCCR_CRC_BURST         0x00300000
  #define FLASH_CRCCR_CRC_BURST_0       0x00100000
  #define FLASH_CRCCR_CRC_BURST_1       0x00200000
  #define FLASH_CRCCR_ALL_BANK          0x00400000
#define TOFF_FLASH_CRCSADD1 0x0054		/* (RW) Flash CRC Start Address Register for Bank1 */
#define TOFF_FLASH_CRCEADD1 0x0058		/* (RW) Flash CRC End Address Register for Bank1 */
#define TOFF_FLASH_CRCDATA1 0x005C		/* (RW) Flash CRC Data Register for Bank1 */
#define TOFF_FLASH_ECC_FA1  0x0060		/* (RW) Flash ECC Fail Address For Bank1 Register */
  #define FLASH_ECC_FA_FAIL_ECC_ADDR    0x00007FFF
#define TOFF_FLASH_KEYR2    0x0104		/* (RW) Flash Key Register for bank2 */
#define TOFF_FLASH_CR2      0x010C		/* (RW) Flash Control Register for bank2 */
#define TOFF_FLASH_SR2      0x0110		/* (RW) Flash Status Register for bank2 */
#define TOFF_FLASH_CCR2     0x0114		/* (RW) Flash Status Register for bank2 */
#define TOFF_FLASH_PRAR_CUR2 0x0128		/* (RW) Flash Current Protection Address Register for bank2 */
#define TOFF_FLASH_PRAR_PRG2 0x012C		/* (RW) Flash Protection Address to Program Register for bank2 */
#define TOFF_FLASH_SCAR_CUR2 0x0130		/* (RW) Flash Current Secure Address Register for bank2 */
#define TOFF_FLASH_SCAR_PRG2 0x0134		/* (RW) Flash Secure Address Register for bank2 */
#define TOFF_FLASH_WPSN_CUR2 0x0138		/* (RW) Flash Current Write Protection Register on bank2 */
#define TOFF_FLASH_WPSN_PRG2 0x013C		/* (RW) Flash Write Protection to Program Register on bank2 */
#define TOFF_FLASH_CRCCR2   0x0150		/* (RW) Flash CRC Control register For Bank2 Register */
#define TOFF_FLASH_CRCSADD2 0x0154		/* (RW) Flash CRC Start Address Register for Bank2 */
#define TOFF_FLASH_CRCEADD2 0x0158		/* (RW) Flash CRC End Address Register for Bank2 */
#define TOFF_FLASH_CRCDATA2 0x015C		/* (RW) Flash CRC Data Register for Bank2 */
#define TOFF_FLASH_ECC_FA2  0x0160		/* (RW) Flash ECC Fail Address For Bank2 Register */


/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (D2_AHB1PERIPH_BASE + 0x0000)
#define TADR_DMA2_BASE      (D2_AHB1PERIPH_BASE + 0x0400)
#define TOFF_DMAI_LISR      0x0000		/* (RW) DMA low interrupt status register */
  #define DMA_LISR_FEIF0           0x00000001	/* Stream 0 FIFO error interrupt flag */
  #define DMA_LISR_DMEIF0          0x00000004	/* Stream 0 direct mode error interrupt flag */
  #define DMA_LISR_TEIF0           0x00000008	/* Stream 0 transfer error interrupt flag */
  #define DMA_LISR_HTIF0           0x00000010	/* Stream 0 half transfer interrupt flag */
  #define DMA_LISR_TCIF0           0x00000020	/* Stream 0 transfer complete interrupt flag */
  #define DMA_LISR_FEIF1           0x00000040	/* Stream 1 FIFO error interrupt flag */
  #define DMA_LISR_DMEIF1          0x00000100	/* Stream 1 direct mode error interrupt flag */
  #define DMA_LISR_TEIF1           0x00000200	/* Stream 1 transfer error interrupt flag */
  #define DMA_LISR_HTIF1           0x00000400	/* Stream 1 half transfer interrupt flag */
  #define DMA_LISR_TCIF1           0x00000800	/* Stream 1 transfer complete interrupt flag */
  #define DMA_LISR_FEIF2           0x00010000	/* Stream 2 FIFO error interrupt flag */
  #define DMA_LISR_DMEIF2          0x00040000	/* Stream 2 direct mode error interrupt flag */
  #define DMA_LISR_TEIF2           0x00080000	/* Stream 2 transfer error interrupt flag */
  #define DMA_LISR_HTIF2           0x00100000	/* Stream 2 half transfer interrupt flag */
  #define DMA_LISR_TCIF2           0x00200000	/* Stream 2 transfer complete interrupt flag */
  #define DMA_LISR_FEIF3           0x00400000	/* Stream 3 FIFO error interrupt flag */
  #define DMA_LISR_DMEIF3          0x01000000	/* Stream 3 direct mode error interrupt flag */
  #define DMA_LISR_TEIF3           0x02000000	/* Stream 3 transfer error interrupt flag */
  #define DMA_LISR_HTIF3           0x04000000	/* Stream 3 half transfer interrupt flag */
  #define DMA_LISR_TCIF3           0x08000000	/* Stream 3 transfer complete interrupt flag */
#define TOFF_DMAI_HISR      0x0004		/* (RW) DMA high interrupt status register */
  #define DMA_HISR_FEIF4           0x00000001	/* Stream 4 FIFO error interrupt flag */
  #define DMA_HISR_DMEIF4          0x00000004	/* Stream 4 direct mode error interrupt flag */
  #define DMA_HISR_TEIF4           0x00000008	/* Stream 4 transfer error interrupt flag */
  #define DMA_HISR_HTIF4           0x00000010	/* Stream 4 half transfer interrupt flag */
  #define DMA_HISR_TCIF4           0x00000020	/* Stream 4 transfer complete interrupt flag */
  #define DMA_HISR_FEIF5           0x00000040	/* Stream 5 FIFO error interrupt flag */
  #define DMA_HISR_DMEIF5          0x00000100	/* Stream 5 direct mode error interrupt flag */
  #define DMA_HISR_TEIF5           0x00000200	/* Stream 5 transfer error interrupt flag */
  #define DMA_HISR_HTIF5           0x00000400	/* Stream 5 half transfer interrupt flag */
  #define DMA_HISR_TCIF5           0x00000800	/* Stream 5 transfer complete interrupt flag */
  #define DMA_HISR_FEIF6           0x00010000	/* Stream 6 FIFO error interrupt flag */
  #define DMA_HISR_DMEIF6          0x00040000	/* Stream 6 direct mode error interrupt flag */
  #define DMA_HISR_TEIF6           0x00080000	/* Stream 6 transfer error interrupt flag */
  #define DMA_HISR_HTIF6           0x00100000	/* Stream 6 half transfer interrupt flag */
  #define DMA_HISR_TCIF6           0x00200000	/* Stream 6 transfer complete interrupt flag */
  #define DMA_HISR_FEIF7           0x00400000	/* Stream 7 FIFO error interrupt flag */
  #define DMA_HISR_DMEIF7          0x01000000	/* Stream 7 direct mode error interrupt flag */
  #define DMA_HISR_TEIF7           0x02000000	/* Stream 7 transfer error interrupt flag */
  #define DMA_HISR_HTIF7           0x04000000	/* Stream 7 half transfer interrupt flag */
  #define DMA_HISR_TCIF7           0x08000000	/* Stream 7 transfer complete interrupt flag */
#define TOFF_DMAI_LIFCR     0x0008		/* (RW) DMA low interrupt flag clear register */
  #define DMA_LIFCR_CFEIF0         0x00000001	/* Stream 0 clear FIFO error interrupt flag */
  #define DMA_LIFCR_CDMEIF0        0x00000004	/* Stream 0 clear direct mode error interrupt flag */
  #define DMA_LIFCR_CTEIF0         0x00000008	/* Stream 0 clear transfer error interrupt flag */
  #define DMA_LIFCR_CHTIF0         0x00000010	/* Stream 0 clear half transfer interrupt flag */
  #define DMA_LIFCR_CTCIF0         0x00000020	/* Stream 0 clear transfer complete interrupt flag */
  #define DMA_LIFCR_CFEIF1         0x00000040	/* Stream 1 clear FIFO error interrupt flag */
  #define DMA_LIFCR_CDMEIF1        0x00000100	/* Stream 1 clear direct mode error interrupt flag */
  #define DMA_LIFCR_CTEIF1         0x00000200	/* Stream 1 clear transfer error interrupt flag */
  #define DMA_LIFCR_CHTIF1         0x00000400	/* Stream 1 clear half transfer interrupt flag */
  #define DMA_LIFCR_CTCIF1         0x00000800	/* Stream 1 clear transfer complete interrupt flag */
  #define DMA_LIFCR_CFEIF2         0x00010000	/* Stream 2 clear FIFO error interrupt flag */
  #define DMA_LIFCR_CDMEIF2        0x00040000	/* Stream 2 clear direct mode error interrupt flag */
  #define DMA_LIFCR_CTEIF2         0x00080000	/* Stream 2 clear transfer error interrupt flag */
  #define DMA_LIFCR_CHTIF2         0x00100000	/* Stream 2 clear half transfer interrupt flag */
  #define DMA_LIFCR_CTCIF2         0x00200000	/* Stream 2 clear transfer complete interrupt flag */
  #define DMA_LIFCR_CFEIF3         0x00400000	/* Stream 3 clear FIFO error interrupt flag */
  #define DMA_LIFCR_CDMEIF3        0x01000000	/* Stream 3 clear direct mode error interrupt flag */
  #define DMA_LIFCR_CTEIF3         0x02000000	/* Stream 3 clear transfer error interrupt flag */
  #define DMA_LIFCR_CHTIF3         0x04000000	/* Stream 3 clear half transfer interrupt flag */
  #define DMA_LIFCR_CTCIF3         0x08000000	/* Stream 3 clear transfer complete interrupt flag */
#define TOFF_DMAI_HIFCR     0x000C		/* (RW) DMA high interrupt flag clear register */
  #define DMA_HIFCR_CFEIF4         0x00000001	/* Stream 4 clear FIFO error interrupt flag */
  #define DMA_HIFCR_CDMEIF4        0x00000004	/* Stream 4 clear direct mode error interrupt flag */
  #define DMA_HIFCR_CTEIF4         0x00000008	/* Stream 4 clear transfer error interrupt flag */
  #define DMA_HIFCR_CHTIF4         0x00000010	/* Stream 4 clear half transfer interrupt flag */
  #define DMA_HIFCR_CTCIF4         0x00000020	/* Stream 4 clear transfer complete interrupt flag */
  #define DMA_HIFCR_CFEIF5         0x00000040	/* Stream 5 clear FIFO error interrupt flag */
  #define DMA_HIFCR_CDMEIF5        0x00000100	/* Stream 5 clear direct mode error interrupt flag */
  #define DMA_HIFCR_CTEIF5         0x00000200	/* Stream 5 clear transfer error interrupt flag */
  #define DMA_HIFCR_CHTIF5         0x00000400	/* Stream 5 clear half transfer interrupt flag */
  #define DMA_HIFCR_CTCIF5         0x00000800	/* Stream 5 clear transfer complete interrupt flag */
  #define DMA_HIFCR_CFEIF6         0x00010000	/* Stream 6 clear FIFO error interrupt flag */
  #define DMA_HIFCR_CDMEIF6        0x00040000	/* Stream 6 clear direct mode error interrupt flag */
  #define DMA_HIFCR_CTEIF6         0x00080000	/* Stream 6 clear transfer error interrupt flag */
  #define DMA_HIFCR_CHTIF6         0x00100000	/* Stream 6 clear half transfer interrupt flag */
  #define DMA_HIFCR_CTCIF6         0x00200000	/* Stream 6 clear transfer complete interrupt flag */
  #define DMA_HIFCR_CFEIF7         0x00400000	/* Stream 7 clear FIFO error interrupt flag */
  #define DMA_HIFCR_CDMEIF7        0x01000000	/* Stream 7 clear direct mode error interrupt flag */
  #define DMA_HIFCR_CTEIF7         0x02000000	/* Stream 7 clear transfer error interrupt flag */
  #define DMA_HIFCR_CHTIF7         0x04000000	/* Stream 7 clear half transfer interrupt flag */
  #define DMA_HIFCR_CTCIF7         0x08000000	/* Stream 7 clear transfer complete interrupt flag */


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
  #define DMA_SxCR_EN              0x00000001	/* Stream enable / flag stream ready when read low */
  #define DMA_SxCR_DMEIE           0x00000002	/* Direct mode error interrupt enable */
  #define DMA_SxCR_TEIE            0x00000004	/* Transfer error interrupt enable */
  #define DMA_SxCR_HTIE            0x00000008	/* Half transfer interrupt enable */
  #define DMA_SxCR_TCIE            0x00000010	/* Transfer complete interrupt enable */
  #define DMA_SxCR_PFCTRL          0x00000020	/* Peripheral flow controller */
  #define DMA_SxCR_DIR             0x000000C0	/* Data transfer direction */
  #define DMA_SxCR_DIR_0           0x00000040
  #define DMA_SxCR_DIR_1           0x00000080
  #define DMA_SxCR_CIRC            0x00000100	/* Circular mode */
  #define DMA_SxCR_PINC            0x00000200	/* Peripheral increment mode */
  #define DMA_SxCR_MINC            0x00000400	/* Memory increment mode */
  #define DMA_SxCR_PSIZE           0x00001800	/* Peripheral data size */
  #define DMA_SxCR_PSIZE_0         0x00000800
  #define DMA_SxCR_PSIZE_1         0x00001000
  #define DMA_SxCR_MSIZE           0x00006000	/* Memory data size */
  #define DMA_SxCR_MSIZE_0         0x00002000
  #define DMA_SxCR_MSIZE_1         0x00004000
  #define DMA_SxCR_PINCOS          0x00008000	/* Peripheral increment offset size */
  #define DMA_SxCR_PL              0x00030000	/* Priority level */
  #define DMA_SxCR_PL_0            0x00010000
  #define DMA_SxCR_PL_1            0x00020000
  #define DMA_SxCR_DBM             0x00040000	/* Double buffer mode */
  #define DMA_SxCR_CT              0x00080000	/* Current target (only in double buffer mode) */
  #define DMA_SxCR_PBURST          0x00600000	/* Peripheral burst transfer configuration */
  #define DMA_SxCR_PBURST_0        0x00200000
  #define DMA_SxCR_PBURST_1        0x00400000
  #define DMA_SxCR_MBURST          0x01800000	/* Memory burst transfer configuration */
  #define DMA_SxCR_MBURST_0        0x00800000
  #define DMA_SxCR_MBURST_1        0x01000000
#define TOFF_DMAS_NDTR      0x0004		/* (RW) DMA stream x number of data register     */
#define TOFF_DMAS_PAR       0x0008		/* (RW) DMA stream x peripheral address register */
#define TOFF_DMAS_M0AR      0x000C		/* (RW) DMA stream x memory 0 address register   */
#define TOFF_DMAS_M1AR      0x0010		/* (RW) DMA stream x memory 1 address register   */
#define TOFF_DMAS_FCR       0x0014		/* (RW) DMA stream x FIFO control register       */
  #define DMA_SxFCR_FTH            0x00000003	/* FIFO threshold selection */
  #define DMA_SxFCR_FTH_0          0x00000001
  #define DMA_SxFCR_FTH_1          0x00000002
  #define DMA_SxFCR_DMDIS          0x00000004	/* Direct mode disable */
  #define DMA_SxFCR_FS             0x00000038	/* FIFO status */
  #define DMA_SxFCR_FS_0           0x00000008
  #define DMA_SxFCR_FS_1           0x00000010
  #define DMA_SxFCR_FS_2           0x00000020
  #define DMA_SxFCR_FEIE           0x00000080	/* FIFO error interrupt enable */


/*
 *  DMAMUTEX
 */
#define TADR_DMAMUX1_BASE   (D2_AHB1PERIPH_BASE + 0x0800)
#define TADR_DMAMUX2_BASE   (D3_AHB1PERIPH_BASE + 0x5800)
#define TOFF_DMAMUX_CHANNEL_CR      0x0000
  #define DMAMUX_CxCR_DMAREQ_ID     0x000000FF	/* DMA request identification */
  #define DMAMUX_CxCR_DMAREQ_ID_0   0x00000001
  #define DMAMUX_CxCR_DMAREQ_ID_1   0x00000002
  #define DMAMUX_CxCR_DMAREQ_ID_2   0x00000004
  #define DMAMUX_CxCR_DMAREQ_ID_3   0x00000008
  #define DMAMUX_CxCR_DMAREQ_ID_4   0x00000010
  #define DMAMUX_CxCR_DMAREQ_ID_5   0x00000020
  #define DMAMUX_CxCR_DMAREQ_ID_6   0x00000040
  #define DMAMUX_CxCR_DMAREQ_ID_7   0x00000080
  #define DMAMUX_CxCR_SOIE          0x00000100	/* Synchronization overrun interrupt enable */
  #define DMAMUX_CxCR_EGE           0x00000200	/* Event generation enable */
  #define DMAMUX_CxCR_SE            0x00010000	/* Synchronization enable */
  #define DMAMUX_CxCR_SPOL          0x00060000	/* Synchronization polarity */
  #define DMAMUX_CxCR_SPOL_0        0x00020000
  #define DMAMUX_CxCR_SPOL_1        0x00040000
  #define DMAMUX_CxCR_NBREQ         0x00F80000	/* Number of DMA requests minus 1 to forward */
  #define DMAMUX_CxCR_NBREQ_0       0x00080000
  #define DMAMUX_CxCR_NBREQ_1       0x00100000
  #define DMAMUX_CxCR_NBREQ_2       0x00200000
  #define DMAMUX_CxCR_NBREQ_3       0x00400000
  #define DMAMUX_CxCR_NBREQ_4       0x00800000
  #define DMAMUX_CxCR_SYNC_ID       0x1F000000	/* Synchronization identification */
  #define DMAMUX_CxCR_SYNC_ID_0     0x01000000
  #define DMAMUX_CxCR_SYNC_ID_1     0x02000000
  #define DMAMUX_CxCR_SYNC_ID_2     0x04000000
  #define DMAMUX_CxCR_SYNC_ID_3     0x08000000
  #define DMAMUX_CxCR_SYNC_ID_4     0x10000000
#define TOFF_DMAMUX_REQUEST_GEN     0x0100
  #define DMAMUX_RGxCR_SIG_ID       0x0000001F	/* Signal identification */
  #define DMAMUX_RGxCR_SIG_ID_0     0x00000001
  #define DMAMUX_RGxCR_SIG_ID_1     0x00000002
  #define DMAMUX_RGxCR_SIG_ID_2     0x00000004
  #define DMAMUX_RGxCR_SIG_ID_3     0x00000008
  #define DMAMUX_RGxCR_SIG_ID_4     0x00000010
  #define DMAMUX_RGxCR_OIE          0x00000100	/* Trigger overrun interrupt enable */
  #define DMAMUX_RGxCR_GE           0x00010000	/* DMA request generator enable */
  #define DMAMUX_RGxCR_GPOL         0x00060000	/* DMA request generator trigger polarity */
  #define DMAMUX_RGxCR_GPOL_0       0x00020000
  #define DMAMUX_RGxCR_GPOL_1       0x00040000
  #define DMAMUX_RGxCR_GNBREQ       0x00F80000	/* Number of DMA requests to be generated */
  #define DMAMUX_RGxCR_GNBREQ_0     0x00080000
  #define DMAMUX_RGxCR_GNBREQ_1     0x00100000
  #define DMAMUX_RGxCR_GNBREQ_2     0x00200000
  #define DMAMUX_RGxCR_GNBREQ_3     0x00400000
  #define DMAMUX_RGxCR_GNBREQ_4     0x00800000
#define TOFF_DMAMUX_CHANNEL_STS     0x0080
#define TOFF_DMAMUX_CHANNEL_STS_CSR TOFF_DMAMUX_CHANNEL_STS
#define TOFF_DMAMUX_CHANNEL_STS_CFR (TOFF_DMAMUX_CHANNEL_STS+4)
#define TOFF_DMAMUX_REQUEST_GENSTS  0x1400
#define TOFF_DMAMUX_REQUEST_GENSTS_RGSR  TOFF_DMAMUX_REQUEST_GENSTS
#define TOFF_DMAMUX_REQUEST_GENSTS_RGCFR (TOFF_DMAMUX_REQUEST_GENSTS+4)


/*
 *  DMA2D CONTROLLER
 */
#define TADR_DMA2D_BASE     (D1_AHB1PERIPH_BASE + 0x1000)
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
  #define DMA2D_CR_MODE_0    0x00010000
  #define DMA2D_CR_MODE_1    0x00020000
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
  #define DMA2D_BGPFCCR_CM_0  0x00000001
  #define DMA2D_BGPFCCR_CM_1  0x00000002
  #define DMA2D_BGPFCCR_CM_2  0x00000004
  #define DMA2D_BGPFCCR_CM_3  0x00000008
  #define DMA2D_BGPFCCR_CCM   0x00000010	/* CLUT Color mode */
  #define DMA2D_BGPFCCR_START 0x00000020	/* Start */
  #define DMA2D_BGPFCCR_CS    0x0000FF00	/* CLUT size */
  #define DMA2D_BGPFCCR_AM    0x00030000	/* Alpha Mode */
  #define DMA2D_BGPFCCR_AM_0  0x00010000
  #define DMA2D_BGPFCCR_AM_1  0x00020000
  #define DMA2D_BGPFCCR_ALPHA 0xFF000000	/* Alpha value */
#define TOFF_DMA2D_BGCOLR   0x0028	/* (RW) DMA2D Background Color Register */
  #define DMA2D_BGCOLR_BLUE   0x000000FF	/* Blue Value  */
  #define DMA2D_BGCOLR_GREEN  0x0000FF00	/* Green Value */
  #define DMA2D_BGCOLR_RED    0x00FF0000	/* Red Value   */
#define TOFF_DMA2D_FGCMAR   0x002C	/* (RW) DMA2D Foreground CLUT Memory Address Register */
#define TOFF_DMA2D_BGCMAR   0x0030	/* (RW) DMA2D Background CLUT Memory Address Register */
#define TOFF_DMA2D_OPFCCR   0x0034	/* (RW) DMA2D Output PFC Control Register */
  #define DMA2D_OPFCCR_CM    0x00000007	/* Color mode */
  #define DMA2D_OPFCCR_CM_0  0x00000001
  #define DMA2D_OPFCCR_CM_1  0x00000002
  #define DMA2D_OPFCCR_CM_2  0x00000004
  #define DMA2D_OPFCCR_AI    0x00100000	/* Output Alpha Inverted */
  #define DMA2D_OPFCCR_RBS   0x00200000	/* Output Red Blue Swap */
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
  #define DMA2D_AMTCR_EN     0x00000001	/* Enable */
  #define DMA2D_AMTCR_DT     0x0000FF00	/* Dead Time */
#define TOFF_DMA2D_FGCLUT   0x0400	/* (RW) DMA2D Foreground CLUT 400-7FF */
#define TOFF_DMA2D_BGCLUT   0x0800	/* (RW) DMA2D Background CLUT 800-BFF */


/*
 *  ETHERNET MAC
 */
#define TADR_ETH_BASE       (D2_AHB1PERIPH_BASE + 0x8000)
#define ETH_MAC_BASE        (ETH_BASE)
#define TOFF_ETH_MACCR      0x0000		/* (RW) Ethernet MAC configuration register */
  #define ETH_MACCR_RE          0x00000001	/* Receiver enable */
  #define ETH_MACCR_TE          0x00000002	/* Transmitter enable */
  #define ETH_MACCR_PRELEN      0x0000000C	/* Preamble Length for Transmit packets */
  #define ETH_MACCR_PRELEN_7    0x00000000
  #define ETH_MACCR_PRELEN_5    0x00000004
  #define ETH_MACCR_PRELEN_3    0x00000008
  #define ETH_MACCR_DC          0x00000010	/* Defferal check */
  #define ETH_MACCR_BL          0x00000060	/* Back-off limit: random integer number (r) of slot time delays before rescheduling
                                          	    a transmission attempt during retries after a collision: 0 =< r <2^k */
  #define ETH_MACCR_BL_10       0x00000000	/* k = min (n, 10) */
  #define ETH_MACCR_BL_8        0x00000020	/* k = min (n, 8) */
  #define ETH_MACCR_BL_4        0x00000040	/* k = min (n, 4) */
  #define ETH_MACCR_BL_1        0x00000060	/* k = min (n, 1) */
  #define ETH_MACCR_DR          0x00000100	/* Disable Retry */
  #define ETH_MACCR_DCRS        0x00000200	/* Disable Carrier Sense During Transmission */
  #define ETH_MACCR_DO          0x00000400	/* Disable Receive own  */
  #define ETH_MACCR_ECRSFD      0x00000800	/* Enable Carrier Sense Before Transmission in Full-Duplex Mode */
  #define ETH_MACCR_LM          0x00001000	/* loopback mode */
  #define ETH_MACCR_DM          0x00002000	/* Duplex mode */
  #define ETH_MACCR_FES         0x00004000	/* Fast ethernet speed */
  #define ETH_MACCR_JE          0x00010000	/* Jumbo Packet Enable */
  #define ETH_MACCR_JD          0x00020000	/* Jabber disable */
  #define ETH_MACCR_WD          0x00080000	/* Watchdog disable */
  #define ETH_MACCR_ACS         0x00100000	/* Automatic Pad or CRC Stripping */
  #define ETH_MACCR_CST         0x00200000	/* CRC stripping for Type packets */
  #define ETH_MACCR_S2KP        0x00400000	/* IEEE 802.3as Support for 2K Packets */
  #define ETH_MACCR_GPSLCE      0x00800000	/* Giant Packet Size Limit Control Enable */
  #define ETH_MACCR_IPG         0x07000000	/* Inter-Packet Gap */
  #define ETH_MACCR_IPG_96BIT   0x00000000	/* Minimum IFG between Packets during transmission is 96Bit */
  #define ETH_MACCR_IPG_88BIT   0x01000000	/* Minimum IFG between Packets during transmission is 88Bit */
  #define ETH_MACCR_IPG_80BIT   0x02000000	/* Minimum IFG between Packets during transmission is 80Bit */
  #define ETH_MACCR_IPG_72BIT   0x03000000	/* Minimum IFG between Packets during transmission is 72Bit */
  #define ETH_MACCR_IPG_64BIT   0x04000000	/* Minimum IFG between Packets during transmission is 64Bit */
  #define ETH_MACCR_IPG_56BIT   0x05000000	/* Minimum IFG between Packets during transmission is 56Bit */
  #define ETH_MACCR_IPG_48BIT   0x06000000	/* Minimum IFG between Packets during transmission is 48Bit */
  #define ETH_MACCR_IPG_40BIT   0x07000000	/* Minimum IFG between Packets during transmission is 40Bit */
  #define ETH_MACCR_IPC         0x08000000	/* Checksum Offload */
  #define ETH_MACCR_SARC        0x70000000	/* Source Address Insertion or Replacement Control */
  #define ETH_MACCR_SARC_MTIATI     0x00000000	/* The mti_sa_ctrl_i and ati_sa_ctrl_i input signals control the SA field generation. */
  #define ETH_MACCR_SARC_INSADDR0   0x20000000	/* Insert MAC Address0 in the SA field of all transmitted packets. */
  #define ETH_MACCR_SARC_INSADDR1   0x60000000	/* Insert MAC Address1 in the SA field of all transmitted packets. */
  #define ETH_MACCR_SARC_REPADDR0   0x30000000	/* Replace MAC Address0 in the SA field of all transmitted packets. */
  #define ETH_MACCR_SARC_REPADDR1   0x70000000	/* Replace MAC Address1 in the SA field of all transmitted packets. */
  #define ETH_MACCR_ARP         0x80000000	/* ARP Offload Enable */
#define TOFF_ETH_MACECR		0x0004		/* (RW) Ethernet MAC Extended Configuration Register register */
  #define ETH_MACECR_GPSL       0x00003FFF	/* Giant Packet Size Limit */
  #define ETH_MACECR_DCRCC      0x00010000	/* Disable CRC Checking for Received Packets */
  #define ETH_MACECR_SPEN       0x00020000	/* Slow Protocol Detection Enable */
  #define ETH_MACECR_USP        0x00040000	/* Unicast Slow Protocol Packet Detect */
  #define ETH_MACECR_EIPGEN     0x01000000	/* Extended Inter-Packet Gap Enable */
  #define ETH_MACECR_EIPG       0x3E000000	/* Extended Inter-Packet Gap */
#define TOFF_ETH_MACPFR     0x0008		/* (RW) Ethernet MAC Packet Filter Register */
  #define ETH_MACPFR_PR         0x00000001	/* Promiscuous mode */
  #define ETH_MACPFR_HUC        0x00000002	/* Hash unicast */
  #define ETH_MACPFR_HMC        0x00000004	/* Hash multicast */
  #define ETH_MACPFR_DAIF       0x00000008	/* DA Inverse filtering */
  #define ETH_MACPFR_PM         0x00000010	/* Pass all mutlicast */
  #define ETH_MACPFR_DBF        0x00000020	/* Disable Broadcast Packets */
  #define ETH_MACPFR_PCF        0x000000C0	/* Pass control frames: 4 cases */
  #define ETH_MACPFR_PCF_BLOCKALL                0x00000000	/* MAC filters all control frames from reaching the application */
  #define ETH_MACPFR_PCF_FORWARDALLEXCEPTPA      0x00000040	/* MAC forwards all control frames except Pause packets to application even if they fail the Address Filter */
  #define ETH_MACPFR_PCF_FORWARDALL              0x00000080	/* MAC forwards all control frames to application even if they fail the Address Filter */
  #define ETH_MACPFR_PCF_FORWARDPASSEDADDRFILTER 0x000000C0	/* MAC forwards control frames that pass the Address Filter. */
  #define ETH_MACPFR_SAIF       0x00000100	/* SA inverse filtering */
  #define ETH_MACPFR_SAF        0x00000200	/* Source address filter enable */
  #define ETH_MACPFR_HPF        0x00000400	/* Hash or perfect filter */
  #define ETH_MACPFR_VTFE       0x00010000	/* VLAN Tag Filter Enable */
  #define ETH_MACPFR_IPFE       0x00100000	/* Layer 3 and Layer 4 Filter Enable */
  #define ETH_MACPFR_DNTU       0x00200000	/* Drop Non-TCP/UDP over IP Packets */
  #define ETH_MACPFR_RA         0x80000000	/* Receive all */
#define TOFF_ETH_MACWTR     0x000C		/* (RW) Ethernet MAC Watchdog Timeout Register */
  #define ETH_MACWTR_WTO        0x0000000F	/* Watchdog Timeout */
  #define ETH_MACWTR_WTO_2KB    0x00000000	/* Maximum received packet length 2KB*/
  #define ETH_MACWTR_WTO_3KB    0x00000001	/* Maximum received packet length 3KB */
  #define ETH_MACWTR_WTO_4KB    0x00000002	/* Maximum received packet length 4KB */
  #define ETH_MACWTR_WTO_5KB    0x00000003	/* Maximum received packet length 5KB */
  #define ETH_MACWTR_WTO_6KB    0x00000004	/* Maximum received packet length 6KB */
  #define ETH_MACWTR_WTO_7KB    0x00000005	/* Maximum received packet length 7KB */
  #define ETH_MACWTR_WTO_8KB    0x00000006	/* Maximum received packet length 8KB */
  #define ETH_MACWTR_WTO_9KB    0x00000007	/* Maximum received packet length 9KB */
  #define ETH_MACWTR_WTO_10KB   0x00000008	/* Maximum received packet length 10KB */
  #define ETH_MACWTR_WTO_11KB   0x00000009	/* Maximum received packet length 11KB */
  #define ETH_MACWTR_WTO_12KB   0x0000000A	/* Maximum received packet length 12KB */
  #define ETH_MACWTR_WTO_13KB   0x0000000B	/* Maximum received packet length 13KB */
  #define ETH_MACWTR_WTO_14KB   0x0000000C	/* Maximum received packet length 14KB */
  #define ETH_MACWTR_WTO_15KB   0x0000000D	/* Maximum received packet length 15KB */
  #define ETH_MACWTR_WTO_16KB   0x0000000E	/* Maximum received packet length 16KB */
  #define ETH_MACWTR_PWE        0x00000100	/* Programmable Watchdog Enable */
#define TOFF_ETH_MACHT0R    0x0010		/* (RW) Ethernet MAC Hash Table High Register */
#define TOFF_ETH_MACHT1R    0x0014		/* (RW) Ethernet MAC Hash Table Low Register */
#define TOFF_ETH_MACVTR     0x0050		/* (RW) Ethernet MAC VLAN Tag Register */
  #define ETH_MACVTR_VL         0x0000FFFF	/* VLAN Tag Identifier for Receive Packets */
  #define ETH_MACVTR_VL_VID     0x00000FFF	/* VLAN Identifier field of VLAN tag */
  #define ETH_MACVTR_VL_CFIDEI  0x00001000	/* Canonical Format Indicator or Drop Eligible Indicator */
  #define ETH_MACVTR_VL_UP      0x0000E000	/* User Priority */
  #define ETH_MACVTR_ETV        0x00010000	/* Enable 12-Bit VLAN Tag Comparison */
  #define ETH_MACVTR_VTIM       0x00020000	/* VLAN Tag Inverse Match Enable */
  #define ETH_MACVTR_ESVL       0x00040000	/* Enable S-VLAN */
  #define ETH_MACVTR_ERSVLM     0x00080000	/* Enable Receive S-VLAN Match */
  #define ETH_MACVTR_DOVLTC     0x00100000	/* Disable VLAN Type Check */
  #define ETH_MACVTR_EVLS       0x00600000	/* Enable VLAN Tag Stripping on Receive */
  #define ETH_MACVTR_EVLS_DONOTSTRIP      0x00000000	/* Do not strip */
  #define ETH_MACVTR_EVLS_STRIPIFPASS     0x00200000	/* Strip if VLAN filter passes */
  #define ETH_MACVTR_EVLS_STRIPIFFAILS    0x00400000	/* Strip if VLAN filter fails */
  #define ETH_MACVTR_EVLS_ALWAYSSTRIP     0x00600000	/* Always strip */
  #define ETH_MACVTR_EVLRXS     0x01000000	/* Enable VLAN Tag in Rx status */
  #define ETH_MACVTR_VTHM       0x02000000	/* VLAN Tag Hash Table Match Enable */
  #define ETH_MACVTR_EDVLP      0x04000000	/* Enable Double VLAN Processing */
  #define ETH_MACVTR_ERIVLT     0x08000000	/* Enable Inner VLAN Tag */
  #define ETH_MACVTR_EIVLS      0x30000000	/* Enable Inner VLAN Tag Stripping on Receive */
  #define ETH_MACVTR_EIVLS_DONOTSTRIP     0x00000000	/* Do not strip */
  #define ETH_MACVTR_EIVLS_STRIPIFPASS    0x10000000	/* Strip if VLAN filter passes */
  #define ETH_MACVTR_EIVLS_STRIPIFFAILS   0x20000000	/* Strip if VLAN filter fails */
  #define ETH_MACVTR_EIVLS_ALWAYSSTRIP    0x30000000	/* Always strip */
  #define ETH_MACVTR_EIVLRXS    0x80000000	/* Enable Inner VLAN Tag in Rx Status */
#define TOFF_ETH_MACVHTR    0x0058		/* (RW) Ethernet MAC VLAN Hash Table Register */
  #define ETH_MACVHTR_VLHT      0x0000FFFF	/* VLAN Hash Table */
#define TOFF_ETH_MACVIR     0x0060		/* (RW) Ethernet MAC VLAN Incl Register */
  #define ETH_MACVIR_VLT        0x0000FFFF	/* VLAN Tag for Transmit Packets */
  #define ETH_MACVIR_VLT_UP     0x0000E000	/* User Priority */
  #define ETH_MACVIR_VLT_CFIDEI 0x00001000	/* Canonical Format Indicator or Drop Eligible Indicator */
  #define ETH_MACVIR_VLT_VID    0x00000FFF	/* VLAN Identifier field of VLAN tag */
  #define ETH_MACVIR_VLC        0x00030000	/* VLAN Tag Control in Transmit Packets */
  #define ETH_MACVIR_VLC_NOVLANTAG        0x00000000	/* No VLAN tag deletion, insertion, or replacement */
  #define ETH_MACVIR_VLC_VLANTAGDELETE    0x00010000	/* VLAN tag deletion */
  #define ETH_MACVIR_VLC_VLANTAGINSERT    0x00020000	/* VLAN tag insertion */
  #define ETH_MACVIR_VLC_VLANTAGREPLACE   0x00030000	/* VLAN tag replacement */
  #define ETH_MACVIR_VLP        0x00040000	/* VLAN Priority Control */
  #define ETH_MACVIR_CSVL       0x00080000	/* C-VLAN or S-VLAN */
  #define ETH_MACVIR_VLTI       0x00100000	/* VLAN Tag Input */
#define TOFF_ETH_MACIVIR    0x0064		/* (RW) Ethernet MAC Inner_VLAN Incl Register */
  #define ETH_MACIVIR_VLT       0x0000FFFF	/* VLAN Tag for Transmit Packets */
  #define ETH_MACIVIR_VLT_UP    0x0000E000	/* User Priority */
  #define ETH_MACIVIR_VLT_CFIDEI 0x00001000	/* Canonical Format Indicator or Drop Eligible Indicator */
  #define ETH_MACIVIR_VLT_VID   0x00000FFF	/* VLAN Identifier field of VLAN tag */
  #define ETH_MACIVIR_VLC       0x00030000	/* VLAN Tag Control in Transmit Packets */
  #define ETH_MACIVIR_VLC_NOVLANTAG       0x00000000	/* No VLAN tag deletion, insertion, or replacement */
  #define ETH_MACIVIR_VLC_VLANTAGDELETE   0x00010000	/* VLAN tag deletion */
  #define ETH_MACIVIR_VLC_VLANTAGINSERT   0x00020000	/* VLAN tag insertion */
  #define ETH_MACIVIR_VLC_VLANTAGREPLACE  0x00030000	/* VLAN tag replacement */
  #define ETH_MACIVIR_VLP       0x00040000	/* VLAN Priority Control */
  #define ETH_MACIVIR_CSVL      0x00080000	/* C-VLAN or S-VLAN */
  #define ETH_MACIVIR_VLTI      0x00100000	/* VLAN Tag Input */
#define TOFF_ETH_MACTFCR    0x0070		/* (RW) Ethernet MAC Tx Flow Ctrl Register */
  #define ETH_MACTFCR_FCB       0x00000001	/* Flow Control Busy or Backpressure Activate */
  #define ETH_MACTFCR_TFE       0x00000002	/* Transmit Flow Control Enable */
  #define ETH_MACTFCR_PLT       0x00000070	/* Pause Low Threshold */
  #define ETH_MACTFCR_PLT_MINUS4          0x00000000	/* Pause time minus 4 slot times */
  #define ETH_MACTFCR_PLT_MINUS28         0x00000010	/* Pause time minus 28 slot times */
  #define ETH_MACTFCR_PLT_MINUS36         0x00000020	/* Pause time minus 36 slot times */
  #define ETH_MACTFCR_PLT_MINUS144        0x00000030	/* Pause time minus 144 slot times */
  #define ETH_MACTFCR_PLT_MINUS256        0x00000040	/* Pause time minus 256 slot times */
  #define ETH_MACTFCR_PLT_MINUS512        0x00000050	/* Pause time minus 512 slot times */
  #define ETH_MACTFCR_DZPQ      0x00000080	/* Disable Zero-Quanta Pause */
  #define ETH_MACTFCR_PT        0xFFFF0000	/* Pause Time */
#define TOFF_ETH_MACRFCR    0x0090		/* (RW) Ethernet MAC Rx Flow Ctrl Register */
  #define ETH_MACRFCR_RFE       0x00000001	/* Receive Flow Control Enable */
  #define ETH_MACRFCR_UP        0x00000002	/* Unicast Pause Packet Detect */
#define TOFF_ETH_MACISR     0x00B0		/* (RW) Ethernet MAC Interrupt Status Register */
  #define ETH_MACISR_PHYIS      0x00000008	/* PHY Interrupt */
  #define ETH_MACISR_PMTIS      0x00000010	/* PMT Interrupt Status */
  #define ETH_MACISR_LPIIS      0x00000020	/* LPI Interrupt Status */
  #define ETH_MACISR_MMCIS      0x00000100	/* MMC Interrupt Status */
  #define ETH_MACISR_MMCRXIS    0x00000200	/* MMC Receive Interrupt Status */
  #define ETH_MACISR_MMCTXIS    0x00000400	/* MMC Transmit Interrupt Status */
  #define ETH_MACISR_TSIS       0x00001000	/* Timestamp Interrupt Status */
  #define ETH_MACISR_TXSTSIS    0x00002000	/* Transmit Status Interrupt */
  #define ETH_MACISR_RXSTSIS    0x00004000	/* Receive Status Interrupt */
#define TOFF_ETH_MACIER     0x00B4		/* (RW) Ethernet MAC Interrupt Enable Register */
  #define ETH_MACIER_PHYIE      0x00000008	/* PHY Interrupt Enable */
  #define ETH_MACIER_PMTIE      0x00000010	/* PMT Interrupt Enable */
  #define ETH_MACIER_LPIIE      0x00000020	/* LPI Interrupt Enable */
  #define ETH_MACIER_TSIE       0x00001000	/* Timestamp Interrupt Enable */
  #define ETH_MACIER_TXSTSIE    0x00002000	/* Transmit Status Interrupt Enable */
  #define ETH_MACIER_RXSTSIE    0x00004000	/* Receive Status Interrupt Enable */
#define TOFF_ETH_MACRXTXSR  0x00B8		/* (RW) Ethernet MAC Rx Tx Status Register */
  #define ETH_MACRXTXSR_TJT     0x00000001	/* Transmit Jabber Timeout */
  #define ETH_MACRXTXSR_NCARR   0x00000002	/* No Carrier */
  #define ETH_MACRXTXSR_LCARR   0x00000004	/* Loss of Carrier */
  #define ETH_MACRXTXSR_EXDEF   0x00000008	/* Excessive Deferral */
  #define ETH_MACRXTXSR_LCOL    0x00000010	/* Late Collision */
  #define ETH_MACRXTXSR_EXCOL   0x00000020	/* Excessive Collisions */
  #define ETH_MACRXTXSR_RWT     0x00000100	/* Receive Watchdog Timeout */
#define TOFF_ETH_MACPCSR    0x00C0		/* (RW) Ethernet MAC PMT Control Status Register */
  #define ETH_MACPCSR_PWRDWN    0x00000001	/* Power Down */
  #define ETH_MACPCSR_MGKPKTEN  0x00000002	/* Magic Packet Enable */
  #define ETH_MACPCSR_RWKPKTEN  0x00000004	/* Remote Wake-Up Packet Enable */
  #define ETH_MACPCSR_MGKPRCVD  0x00000020	/* Magic Packet Received */
  #define ETH_MACPCSR_RWKPRCVD  0x00000040	/* Remote Wake-Up Packet Received */
  #define ETH_MACPCSR_GLBLUCAST 0x00000200	/* Global Unicast */
  #define ETH_MACPCSR_RWKPFE    0x00000400	/* Remote Wake-up Packet Forwarding Enable */
  #define ETH_MACPCSR_RWKPTR    0x1F000000	/* Remote Wake-up FIFO Pointer */
  #define ETH_MACPCSR_RWKFILTRST 0x80000000	/* Remote Wake-Up Packet Filter Register Pointer Reset */
#define TOFF_ETH_MACRWKPFR  0x00C4		/* (RW) Ethernet MAC Remote Wake-Up Packet Filter Register */
#define TOFF_ETH_MACLCSR    0x00D0		/* (RW) Ethernet MAC LPI Control Status Register */
  #define ETH_MACLCSR_TLPIEN    0x00000001	/* Transmit LPI Entry */
  #define ETH_MACLCSR_TLPIEX    0x00000002	/* Transmit LPI Exit */
  #define ETH_MACLCSR_RLPIEN    0x00000004	/* Receive LPI Entry */
  #define ETH_MACLCSR_RLPIEX    0x00000008	/* Receive LPI Exit */
  #define ETH_MACLCSR_TLPIST    0x00000100	/* Transmit LPI State */
  #define ETH_MACLCSR_RLPIST    0x00000200	/* Receive LPI State */
  #define ETH_MACLCSR_LPIEN     0x00010000	/* LPI Enable */
  #define ETH_MACLCSR_PLS       0x00020000	/* PHY Link Status */
  #define ETH_MACLCSR_LPITXA    0x00080000	/* LPI Tx Automate */
  #define ETH_MACLCSR_LPITE     0x00100000	/* LPI Timer Enable */
  #define ETH_MACLCSR_LPITCSE   0x00200000	/* LPI Tx Clock Stop Enable */
#define TOFF_ETH_MACLTCR    0x00D4		/* (RW) Ethernet MAC LPI Timers Control Register */
  #define ETH_MACLTCR_TWT       0x0000FFFF	/* LPI TW TIMER */
  #define ETH_MACLTCR_LST       0x03FF0000	/* LPI LS TIMER */
#define TOFF_ETH_MACLETR    0x00D8		/* (RW) Ethernet MAC LPI Entry Timer Register */
#define TOFF_ETH_MAC1USTCR  0x00DC		/* (RW) Ethernet MAC 1US Tic Counter Register */
#define TOFF_ETH_MACVR      0x0110		/* (RW) Ethernet MAC Version Register */
  #define ETH_MACVR_SNPSVER     0x000000FF	/* Synopsys-defined Version */
  #define ETH_MACVR_USERVER     0x0000FF00	/* User-defined Version */
#define TOFF_ETH_MACDR      0x0114		/* (RW) Ethernet MAC Debug Register */
  #define ETH_MACDR_RPESTS      0x00000001	/* MAC MII Receive Protocol Engine Status */
  #define ETH_MACDR_RFCFCSTS    0x00000006	/* MAC MII Transmit Protocol Engine Status */
  #define ETH_MACDR_TPESTS      0x00010000	/* MAC Receive Packet Controller FIFO Status */
  #define ETH_MACDR_TFCSTS      0x00060000	/* MAC Transmit Packet Controller Status */
  #define ETH_MACDR_TFCSTS_IDLE         0x00000000	/* Idle state */
  #define ETH_MACDR_TFCSTS_WAIT         0x00020000	/* Waiting for status of the previous packet, IPG or backoff period to be over */
  #define ETH_MACDR_TFCSTS_GENERATEPCP  0x00040000	/* Generating and transmitting a Pause control packet */
  #define ETH_MACDR_TFCSTS_TRASFERIP    0x00060000	/* Transferring input packet for transmission */
#define TOFF_ETH_MACHWF0R   0x011C		/* (RW) Ethernet MAC HW Feature0 Register */
  #define ETH_MACHWF0R_MIISEL            0x00000001	/* 10 or 100 Mbps Support */
  #define ETH_MACHWF0R_GMIISEL           0x00000002	/* 1000 Mbps Support */
  #define ETH_MACHWF0R_HDSEL             0x00000004	/* Half-duplex Support */
  #define ETH_MACHWF0R_PCSSEL            0x00000008	/* PCS Registers (TBI, SGMII, or RTBI PHY interface) */
  #define ETH_MACHWF0R_VLHASH            0x00000010	/* VLAN Hash Filter Selected */
  #define ETH_MACHWF0R_SMASEL            0x00000020	/* SMA (MDIO) Interface */
  #define ETH_MACHWF0R_RWKSEL            0x00000040	/* PMT Remote Wake-up Packet Enable */
  #define ETH_MACHWF0R_MGKSEL            0x00000080	/* PMT Magic Packet Enable */
  #define ETH_MACHWF0R_MMCSEL            0x00000100	/* RMON Module Enable */
  #define ETH_MACHWF0R_ARPOFFSEL         0x00000200	/* ARP Offload Enabled */
  #define ETH_MACHWF0R_TSSEL             0x00001000	/* IEEE 1588-2008 Timestamp Enabled */
  #define ETH_MACHWF0R_EEESEL            0x00002000	/* Energy Efficient Ethernet Enabled */
  #define ETH_MACHWF0R_TXCOESEL          0x00004000	/* Transmit Checksum Offload Enabled */
  #define ETH_MACHWF0R_RXCOESEL          0x00010000	/* Receive Checksum Offload Enabled */
  #define ETH_MACHWF0R_ADDMACADRSEL      0x007C0000	/* MAC Addresses 1- 31 Selected */
  #define ETH_MACHWF0R_MACADR32SEL       0x00800000	/* MAC Addresses 32-63 Selected */
  #define ETH_MACHWF0R_MACADR64SEL       0x01000000	/* MAC Addresses 64-127 Selected */
  #define ETH_MACHWF0R_TSSTSSEL_BOTH     0x06000000	/* Timestamp System Time Source: Internal & External */
  #define ETH_MACHWF0R_TSSTSSEL_EXTERNAL 0x04000000	/* Timestamp System Time Source: External */
  #define ETH_MACHWF0R_TSSTSSEL_INTERNAL 0x02000000	/* Timestamp System Time Source: Internal */
  #define ETH_MACHWF0R_TSSTSSEL          0x06000000	/* Timestamp System Time Source */
  #define ETH_MACHWF0R_SAVLANINS         0x08000000	/* Source Address or VLAN Insertion Enable */
  #define ETH_MACHWF0R_ACTPHYSEL         0x70000000	/* Active PHY Selected */
  #define ETH_MACHWF0R_ACTPHYSEL_MII     0x00000000	/* MII */
  #define ETH_MACHWF0R_ACTPHYSEL_RMII    0x40000000	/* RMII */
  #define ETH_MACHWF0R_ACTPHYSEL_REVMII  0x70000000	/* RevMII */
#define TOFF_ETH_MACHWF1R   0x0120		/* (RW) Ethernet MAC HW Feature1 Register */
  #define ETH_MACHWF1R_RXFIFOSIZE 0x0000001F	/* MTL Receive FIFO Size */
  #define ETH_MACHWF1R_TXFIFOSIZE 0x000007C0	/* MTL Transmit FIFO Size */
  #define ETH_MACHWF1R_OSTEN      0x00000800	/* One-Step Timestamping Enable */
  #define ETH_MACHWF1R_PTOEN      0x00001000	/* PTP Offload Enable */
  #define ETH_MACHWF1R_ADVTHWORD  0x00002000	/* IEEE 1588 High Word Register Enable */
  #define ETH_MACHWF1R_ADDR64     0x0000C000	/* Address Width */
  #define ETH_MACHWF1R_ADDR64_32  0x00000000
  #define ETH_MACHWF1R_ADDR64_40  0x00004000
  #define ETH_MACHWF1R_ADDR64_48  0x00008000
  #define ETH_MACHWF1R_DCBEN      0x00010000	/* DCB Feature Enable */
  #define ETH_MACHWF1R_SPHEN      0x00020000	/* Split Header Feature Enable */
  #define ETH_MACHWF1R_TSOEN      0x00040000	/* TCP Segmentation Offload Enable */
  #define ETH_MACHWF1R_DBGMEMA    0x00080000	/* Debug Memory Interface Enabled */
  #define ETH_MACHWF1R_AVSEL      0x00100000	/* AV Feature Enabled */
  #define ETH_MACHWF1R_HASHTBLSZ  0x03000000	/* Hash Table Size */
  #define ETH_MACHWF1R_L3L4FNUM   0x78000000	/* Total number of L3 or L4 Filters */
#define TOFF_ETH_MACHWF2R   0x0124		/* (RW) Ethernet MAC HW Feature2 Register */
  #define ETH_MACHWF2R_RXQCNT   0x0000000F	/* Number of MTL Receive Queues */
  #define ETH_MACHWF2R_TXQCNT   0x000003C0	/* Number of MTL Transmit Queues */
  #define ETH_MACHWF2R_RXCHCNT  0x0000E000	/* Number of DMA Receive Channels */
  #define ETH_MACHWF2R_TXCHCNT  0x003C0000	/* Number of DMA Transmit Channels */
  #define ETH_MACHWF2R_PPSOUTNUM  0x07000000	/*  Number of PPS Outputs */
  #define ETH_MACHWF2R_AUXSNAPNUM 0x70000000	/* Number of Auxiliary Snapshot Inputs */
#define TOFF_ETH_MACMDIOAR  0x0200		/* (RW) Ethernet MAC MDIO Address Register */
  #define ETH_MACMDIOAR_MB      0x00000001	/* MII Busy */
  #define ETH_MACMDIOAR_C45E    0x00000002	/* Clause 45 PHY Enable */
  #define ETH_MACMDIOAR_MOC     0x0000000C	/* MII Operation Command */
  #define ETH_MACMDIOAR_MOC_WR  0x00000004	/* Write */
  #define ETH_MACMDIOAR_MOC_PRDIA 0x00000008	/* Post Read Increment Address for Clause 45 PHY */
  #define ETH_MACMDIOAR_MOC_RD  0x0000000C	/* Read */
  #define ETH_MACMDIOAR_SKAP    0x00000010	/* Skip Address Packet */
  #define ETH_MACMDIOAR_CR      0x00000F00	/* CSR Clock Range */
  #define ETH_MACMDIOAR_CR_DIV42    0x00000000	/* CSR clock/42 */
  #define ETH_MACMDIOAR_CR_DIV62    0x00000100	/* CSR clock/62 */
  #define ETH_MACMDIOAR_CR_DIV16    0x00000200	/* CSR clock/16 */
  #define ETH_MACMDIOAR_CR_DIV26    0x00000300	/* CSR clock/26 */
  #define ETH_MACMDIOAR_CR_DIV102   0x00000400	/* CSR clock/102 */
  #define ETH_MACMDIOAR_CR_DIV124   0x00000500	/* CSR clock/124 */
  #define ETH_MACMDIOAR_CR_DIV4AR   0x00000800	/* CSR clock/4: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV6AR   0x00000900	/* CSR clock/6: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV8AR   0x00000A00	/* CSR clock/8: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV10AR  0x00000B00	/* CSR clock/10: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV12AR  0x00000C00	/* CSR clock/12: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV14AR  0x00000D00	/* CSR clock/14: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV16AR  0x00000E00	/* CSR clock/16: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_CR_DIV18AR  0x00000F00	/* CSR clock/18: MDC clock above range specified in IEEE */
  #define ETH_MACMDIOAR_NTC     0x00007000	/* Number of Trailing Clocks */
  #define ETH_MACMDIOAR_RDA     0x001F0000	/* Register/Device Address */
  #define ETH_MACMDIOAR_PA      0x03E00000	/* Physical Layer Address */
  #define ETH_MACMDIOAR_BTB     0x04000000	/* Back to Back transactions */
  #define ETH_MACMDIOAR_PSE     0x08000000	/* Preamble Suppression Enable */
#define TOFF_ETH_MACMDIODR  0x0204		/* (RW) Ethernet MAC MDIO Data Register */
  #define ETH_MACMDIODR_MD      0x0000FFFF	/* MII Data */
  #define ETH_MACMDIODR_RA      0xFFFF0000	/* Register Address */
#define TOFF_ETH_MACARPAR   0x0210		/* (RW) Ethernet ARP Address Register */
#define TOFF_ETH_MACA0HR    0x0300		/* (RW) Ethernet MAC Address 0 High Register */
  #define ETH_MACA0HR_ADDRHI    0x0000FFFF	/* MAC Address 0 */
  #define ETH_MACA0HR_AE        0x80000000	/* Address Enable */
#define TOFF_ETH_MACA0LR    0x0304		/* (RW) Ethernet MAC Address 0 Low Register */
#define TOFF_ETH_MACA1HR    0x0308		/* (RW) Ethernet MAC Address 1 High Register */
  #define ETH_MACA1HR_ADDRHI    0x0000FFFF	/* MAC Address 1*/
  #define ETH_MACA1HR_MBC       0x3F000000	/* Mask Byte Control */
  #define ETH_MACA1HR_SA        0x40000000	/* Source Address */
  #define ETH_MACA1HR_AE        0x80000000	/* Address Enable*/
#define TOFF_ETH_MACA1LR    0x030C		/* (RW) Ethernet MAC Address 1 Low Register */
#define TOFF_ETH_MACA2HR    0x0310		/* (RW) Ethernet MAC Address 2 High Register */
  #define ETH_MACA2HR_ADDRHI    0x0000FFFF	/* MAC Address 1*/
  #define ETH_MACA2HR_MBC       0x3F000000	/* Mask Byte Control */
  #define ETH_MACA2HR_SA        0x40000000	/* Source Address */
  #define ETH_MACA2HR_AE        0x80000000	/* Address Enable*/
#define TOFF_ETH_MACA2LR    0x0314		/* (RW) Ethernet MAC Address 2 Low Register */
#define TOFF_ETH_MACA3HR    0x0318
  #define ETH_MACA3HR_ADDRHI    0x0000FFFF	/* MAC Address 1*/
  #define ETH_MACA3HR_MBC       0x3F000000	/* Mask Byte Control */
  #define ETH_MACA3HR_SA        0x40000000	/* Source Address */
  #define ETH_MACA3HR_AE        0x80000000	/* Address Enable*/
#define TOFF_ETH_MACA3LR    0x031C
#define TOFF_ETH_MMCCR      0x0700
  #define ETH_MMCCR_CNTRST      0x00000001	/* Counters Reset */
  #define ETH_MMCCR_CNTSTOPRO   0x00000002	/* Counter Stop Rollover */
  #define ETH_MMCCR_RSTONRD     0x00000004	/* Reset On Read */
  #define ETH_MMCCR_CNTFREEZ    0x00000008	/* MMC Counter Freeze */
  #define ETH_MMCCR_CNTPRST     0x00000010	/* Counters Reset */
  #define ETH_MMCCR_CNTPRSTLVL  0x00000020	/* Full-Half Preset */
  #define ETH_MMCCR_UCDBC       0x00000100	/* Update MMC Counters for Dropped Broadcast Packets */
#define TOFF_ETH_MMCRIR     0x0704
  #define ETH_MMCRIR_RXCRCERPIS 0x00000020	/* MMC Receive CRC Error Packet Counter Interrupt Status */
  #define ETH_MMCRIR_RXALGNERPIS 0x00000040	/* MMC Receive Alignment Error Packet Counter Interrupt Status */
  #define ETH_MMCRIR_RXUCGPIS   0x00020000	/* MMC Receive Unicast Good Packet Counter Interrupt Status */
  #define ETH_MMCRIR_RXLPIUSCIS 0x04000000	/* MMC Receive LPI microsecond counter interrupt status */
  #define ETH_MMCRIR_RXLPITRCIS 0x08000000	/* MMC Receive LPI transition counter interrupt status */
#define TOFF_ETH_MMCTIR     0x0708
  #define ETH_MMCTIR_TXSCOLGPIS 0x00004000	/* MMC Transmit Single Collision Good Packet Counter Interrupt Status */
  #define ETH_MMCTIR_TXMCOLGPIS 0x00008000	/* MMC Transmit Multiple Collision Good Packet Counter Interrupt Status */
  #define ETH_MMCTIR_TXGPKTIS   0x00200000	/* MMC Transmit Good Packet Counter Interrupt Status */
  #define ETH_MMCTIR_TXLPIUSCIS 0x04000000	/* MMC Transmit LPI microsecond counter interrupt status */
  #define ETH_MMCTIR_TXLPITRCIS 0x08000000	/* MMC Transmit LPI transition counter interrupt status */
#define TOFF_ETH_MMCRIMR    0x070C
  #define ETH_MMCRIMR_RXCRCERPIM  0x00000020	/* MMC Receive CRC Error Packet Counter Interrupt Mask */
  #define ETH_MMCRIMR_RXALGNERPIM 0x00000040	/* MMC Receive Alignment Error Packet Counter Interrupt Mask */
  #define ETH_MMCRIMR_RXUCGPIM    0x00020000	/* MMC Receive Unicast Good Packet Counter Interrupt Mask */
  #define ETH_MMCRIMR_RXLPIUSCIM  0x04000000	/* MMC Receive LPI microsecond counter interrupt Mask */
  #define ETH_MMCRIMR_RXLPITRCIM  0x08000000	/* MMC Receive LPI transition counter interrupt Mask */
#define TOFF_ETH_MMCTIMR    0x0710
  #define ETH_MMCTIMR_TXSCOLGPIM  0x00004000	/* MMC Transmit Single Collision Good Packet Counter Interrupt Mask */
  #define ETH_MMCTIMR_TXMCOLGPIM  0x00008000	/* MMC Transmit Multiple Collision Good Packet Counter Interrupt Mask */
  #define ETH_MMCTIMR_TXGPKTIM    0x00200000	/* MMC Transmit Good Packet Counter Interrupt Mask*/
  #define ETH_MMCTIMR_TXLPIUSCIM  0x04000000	/* MMC Transmit LPI microsecond counter interrupt Mask*/
  #define ETH_MMCTIMR_TXLPITRCIM  0x08000000	/* MMC Transmit LPI transition counter interrupt Mask*/
#define TOFF_ETH_MMCTSCGPR  0x074C		/* (RW) Ethernet MMC Tx Single Collision Good Packets Register */
#define TOFF_ETH_MMCTMCGPR  0x0750		/* (RW) Ethernet MMC Tx Multiple Collision Good Packets Register */
#define TOFF_ETH_MMCTPCGR   0x0768		/* (RW) Ethernet MMC Tx Packet Count Good Register */
#define TOFF_ETH_MMCRCRCEPR 0x0794		/* (RW) Ethernet MMC Rx CRC Error Packets Register */
#define TOFF_ETH_MMCRAEPR   0x0798		/* (RW) Ethernet MMC Rx alignment error packets register */
#define TOFF_ETH_MMCRUPGR   0x07C4		/* (RW) Ethernet MMC Rx Unicast Packets Good Register */
#define TOFF_ETH_MMCTLPIMSTR 0x07EC		/* (RW) Ethernet MMC Tx LPI Microsecond Timer Register */
#define TOFF_ETH_MMCTLPITCR 0x07F0		/* (RW) Ethernet MMC Tx LPI Transition Counter Register */
#define TOFF_ETH_MMCRLPIMSTR 0x07F4		/* (RW) Ethernet MMC Rx LPI Microsecond Counter Register */
#define TOFF_ETH_MMCRLPITCR 0x07F8		/* (RW) Ethernet MMC Rx LPI Transition Counter Register */
#define TOFF_ETH_MACL3L4C0R 0x0900
#define TOFF_ETH_MACL4A0R   0x0904
#define TOFF_ETH_MACL3A0R0R 0x0910
#define TOFF_ETH_MACL3A1R0R 0x0914
#define TOFF_ETH_MACL3A2R0R 0x0918
#define TOFF_ETH_MACL3A3R0R 0x091C
#define TOFF_ETH_MACL3L4C1R 0x0930
#define TOFF_ETH_MACL4A1R   0x0934
#define TOFF_ETH_MACL3A0R1R 0x0940		/* (RW) Ethernet MAC L3 Address0 Register */
#define TOFF_ETH_MACL3A1R1R 0x0944		/* (RW) Ethernet MAC L4 Address1 Register */
#define TOFF_ETH_MACL3A2R1R 0x0948		/* (RW) Ethernet MAC L4 Address2 Register */
#define TOFF_ETH_MACL3A3R1R 0x094C		/* (RW) Ethernet MAC L4 Address3 Register */
#define TOFF_ETH_MACTSCR    0x0B00		/* (RW) Ethernet MAC Timestamp Control Register */
  #define ETH_MACTSCR_TSENA     0x00000001	/* Enable Timestamp */
  #define ETH_MACTSCR_TSCFUPDT  0x00000002	/* Fine or Coarse Timestamp Update*/
  #define ETH_MACTSCR_TSINIT    0x00000004	/* Initialize Timestamp */
  #define ETH_MACTSCR_TSUPDT    0x00000008	/* Update Timestamp */
  #define ETH_MACTSCR_TSADDREG  0x00000020	/* Update Addend Register */
  #define ETH_MACTSCR_TSENALL   0x00000100	/* Enable Timestamp for All Packets */
  #define ETH_MACTSCR_TSCTRLSSR 0x00000200	/* Timestamp Digital or Binary Rollover Control */
  #define ETH_MACTSCR_TSVER2ENA 0x00000400	/* Enable PTP Packet Processing for Version 2 Format */
  #define ETH_MACTSCR_TSIPENA   0x00000800	/* Enable Processing of PTP over Ethernet Packets */
  #define ETH_MACTSCR_TSIPV6ENA 0x00001000	/* Enable Processing of PTP Packets Sent over IPv6-UDP */
  #define ETH_MACTSCR_TSIPV4ENA 0x00002000	/* Enable Processing of PTP Packets Sent over IPv4-UDP */
  #define ETH_MACTSCR_TSEVNTENA 0x00004000	/* Enable Timestamp Snapshot for Event Messages */
  #define ETH_MACTSCR_TSMSTRENA 0x00008000	/* Enable Snapshot for Messages Relevant to Master */
  #define ETH_MACTSCR_SNAPTYPSEL  0x00030000	/* Select PTP packets for Taking Snapshots */
  #define ETH_MACTSCR_TSENMACADDR 0x00040000	/* Enable MAC Address for PTP Packet Filtering */
  #define ETH_MACTSCR_CSC       0x00080000	/* Enable checksum correction during OST for PTP over UDP/IPv4 packets */
  #define ETH_MACTSCR_TXTSSTSM  0x01000000	/* Transmit Timestamp Status Mode */
#define TOFF_ETH_MACSSIR    0x0B04		/* (RW) Ethernet MAC Sub-second Increment Register */
#define TOFF_ETH_MACSTSR    0x0B08		/* (RW) Ethernet MAC System Time Seconds Register */
#define TOFF_ETH_MACSTNR    0x0B0C		/* (RW) Ethernet MAC System Time Nanoseconds Register */
#define TOFF_ETH_MACSTSUR   0x0B10		/* (RW) Ethernet MAC System Time Seconds Update Register */
#define TOFF_ETH_MACSTNUR   0x0B14		/* (RW) Ethernet MAC System Time Nanoseconds Update Register */
  #define ETH_MACSTNUR_TSSS     0x7FFFFFFF	/* Timestamp Sub-seconds */
  #define ETH_MACSTNUR_ADDSUB   0x80000000	/* Add or Subtract Time */
#define TOFF_ETH_MACTSAR    0x0B18		/* (RW) Ethernet MAC Timestamp Addend Register */
#define TOFF_ETH_MACTSSR    0x0B20		/* (RW) Ethernet MAC Timestamp Status Register */
  #define ETH_MACTSSR_TSSOVF    0x00000001	/* Timestamp Seconds Overflow */
  #define ETH_MACTSSR_TSTARGT0  0x00000002	/* Timestamp Target Time Reached */
  #define ETH_MACTSSR_AUXTSTRIG 0x00000004	/* Auxiliary Timestamp Trigger Snapshot*/
  #define ETH_MACTSSR_TSTRGTERR0  0x00000008	/* Timestamp Target Time Error */
  #define ETH_MACTSSR_TXTSSIS   0x00008000	/* Tx Timestamp Status Interrupt Status */
  #define ETH_MACTSSR_ATSSTN    0x000F0000	/* Auxiliary Timestamp Snapshot Trigger Identifier */
  #define ETH_MACTSSR_ATSSTM    0x01000000	/* Auxiliary Timestamp Snapshot Trigger Missed */
  #define ETH_MACTSSR_ATSNS     0x3E000000	/* Number of Auxiliary Timestamp Snapshots */
#define TOFF_ETH_MACTTSSNR  0x0B30		/* (RW) Ethernet MAC Tx Timestamp Status Nanoseconds Register */
  #define ETH_MACTTSSNR_TXTSSLO  0x7FFFFFFF	/* Transmit Timestamp Status Low */
  #define ETH_MACTTSSNR_TXTSSMIS 0x80000000	/* Transmit Timestamp Status Missed */
#define TOFF_ETH_MACTTSSSR  0x0B34		/* (RW) Ethernet MAC Tx Timestamp Status Seconds Register */
#define TOFF_ETH_MACACR     0x0B40		/* (RW) Ethernet MAC Auxiliary Control Register */
  #define ETH_MACACR_ATSFC      0x00000001	/* Auxiliary Snapshot FIFO Clear */
  #define ETH_MACACR_ATSEN0     0x00000010	/* Auxiliary Snapshot 0 Enable */
  #define ETH_MACACR_ATSEN1     0x00000020	/* Auxiliary Snapshot 1 Enable */
  #define ETH_MACACR_ATSEN2     0x00000040	/* Auxiliary Snapshot 2 Enable */
  #define ETH_MACACR_ATSEN3     0x00000080	/* Auxiliary Snapshot 3 Enable */
#define TOFF_ETH_MACATSNR   0x0B48		/* (RW) Ethernet MAC Auxiliary Timestamp Nanoseconds Register */
#define TOFF_ETH_MACATSSR   0x0B4C		/* (RW) Ethernet MAC Auxiliary Timestamp Seconds Register */
#define TOFF_ETH_MACTSIACR  0x0B50		/* (RW) Ethernet MAC Timestamp Ingress Asymmetric Correction Register */
#define TOFF_ETH_MACTSEACR  0x0B54		/* (RW) Ethernet MAC Timestamp Egress Asymmetric Correction Register */
#define TOFF_ETH_MACTSICNR  0x0B58		/* (RW) Ethernet MAC Timestamp Ingress Correction Nanosecond Register */
#define TOFF_ETH_MACTSECNR  0x0B5C		/* (RW) Ethernet MAC Timestamp Egress correction Nanosecond Register */
#define TOFF_ETH_MACPPSCR   0x0B70		/* (RW) Ethernet MAC PPS Control Register */
  #define ETH_MACPPSCR_PPSCTRL      0x0000000F	/* PPS Output Frequency Control */
  #define ETH_MACPPSCR_PPSEN0       0x00000010	/* Flexible PPS Output Mode Enable */
  #define ETH_MACPPSCR_TRGTMODSEL0  0x00000060	/* Target Time Register Mode for PPS Output */
#define TOFF_ETH_MACPPSTTSR 0x0B80		/* (RW) Ethernet MAC PPS Target Time Seconds Register */
#define TOFF_ETH_MACPPSTTNR 0x0B84		/* (RW) for Ethernet MAC PPS Target Time Nanoseconds Register */
  #define ETH_MACPPSTTNR_TTSL0      0x7FFFFFFF	/* Target Time Low for PPS Register */
  #define ETH_MACPPSTTNR_TRGTBUSY0  0x80000000	/* PPS Target Time Register Busy */
#define TOFF_ETH_MACPPSIR   0x0B88		/* (RW) Ethernet MAC PPS Interval Register */
#define TOFF_ETH_MACPPSWR   0x0B8C		/* (RW) Ethernet MAC PPS Width Register */
#define TOFF_ETH_MACPOCR    0x0BC0		/* (RW) Ethernet MAC PTP Offload Control Register */
  #define ETH_MACPOCR_PTOEN     0x00000001	/* PTP Offload Enable */
  #define ETH_MACPOCR_ASYNCEN   0x00000002	/* Automatic PTP SYNC message Enable */
  #define ETH_MACPOCR_APDREQEN  0x00000004	/* Automatic PTP Pdelay_Req message Enable */
  #define ETH_MACPOCR_ASYNCTRIG 0x00000010	/* Automatic PTP SYNC message Trigger */
  #define ETH_MACPOCR_APDREQTRIG 0x00000020	/* Automatic PTP Pdelay_Req message Trigger */
  #define ETH_MACPOCR_DRRDIS    0x00000040	/* Disable PTO Delay Request/Response response generation */
  #define ETH_MACPOCR_DN        0x0000FF00	/* Domain Number */
#define TOFF_ETH_MACSPI0R   0x0BC4		/* (RW) Ethernet MAC PTP Source Port Identity 0 Register */
#define TOFF_ETH_MACSPI1R   0x0BC8		/* (RW) Ethernet MAC PTP Source Port Identity 1 Register */
#define TOFF_ETH_MACSPI2R   0x0BCC		/* (RW) Ethernet MAC PTP Source Port Identity 2 Register */
#define TOFF_ETH_MACLMIR    0x0BD0		/* (RW) Ethernet MAC Log Message Interval Register */
  #define ETH_MACLMIR_LSI       0x000000FF	/* Log Sync Interval */
  #define ETH_MACLMIR_DRSYNCR   0x00000700	/* Delay_Req to SYNC Ratio */
  #define ETH_MACLMIR_LMPDRI    0xFF000000	/* Log Min Pdelay_Req Interval */
#define TOFF_ETH_MTLOMR     0x0C00		/* (RW) Ethernet MTL Operation Mode Register */
  #define ETH_MTLOMR_DTXSTS     0x00000002	/* Drop Transmit Status */
  #define ETH_MTLOMR_CNTPRST    0x00000100	/* Counters Preset */
  #define ETH_MTLOMR_CNTCLR     0x00000200	/* Counters Reset */
#define TOFF_ETH_MTLISR     0x0C20		/* (RW) Ethernet MTL Interrupt Status Register */
  #define ETH_MTLISR_QIS        0x00000001	/* Queue Interrupt status */
  #define ETH_MTLISR_MACIS      0x00010000	/* MAC Interrupt Status */
#define TOFF_ETH_MTLTQOMR   0x0D00		/* (RW) Ethernet MTL Tx Queue Operation Mode Register */
  #define ETH_MTLTQOMR_FTQ      0x00000001	/* Flush Transmit Queue */
  #define ETH_MTLTQOMR_TSF      0x00000002	/* Transmit Store and Forward */
  #define ETH_MTLTQOMR_TTC      0x00000070	/* Transmit Threshold Control */
  #define ETH_MTLTQOMR_TTC_32BITS  0x00000000	/* 32 bits Threshold */
  #define ETH_MTLTQOMR_TTC_64BITS  0x00000010	/* 64  bits Threshold */
  #define ETH_MTLTQOMR_TTC_96BITS  0x00000020	/* 96 bits Threshold */
  #define ETH_MTLTQOMR_TTC_128BITS 0x00000030	/* 128 bits Threshold */
  #define ETH_MTLTQOMR_TTC_192BITS 0x00000040	/* 192 bits Threshold */
  #define ETH_MTLTQOMR_TTC_256BITS 0x00000050	/* 256 bits Threshold */
  #define ETH_MTLTQOMR_TTC_384BITS 0x00000060	/* 384 bits Threshold */
  #define ETH_MTLTQOMR_TTC_512BITS 0x00000070	/* 512 bits Threshold */
#define TOFF_ETH_MTLTQUR    0x0D04		/* (RW) Ethernet MTL Tx Queue Underflow Register */
  #define ETH_MTLTQUR_UFPKTCNT     0x000007FF	/* Underflow Packet Counter */
  #define ETH_MTLTQUR_UFCNTOVF     0x00000800	/* Overflow Bit for Underflow Packet Counter */
#define TOFF_ETH_MTLTQDR    0x0D08		/* (RW) Ethernet MTL Tx Queue Debug Register */
  #define ETH_MTLTQDR_TXQPAUSED 0x00000001	/* Transmit Queue in Pause */
  #define ETH_MTLTQDR_TRCSTS    0x00000006/* MTL Tx Queue Read Controller Status */
  #define ETH_MTLTQDR_TRCSTS_IDLE     0x00000000	/* Idle state */
  #define ETH_MTLTQDR_TRCSTS_READ     0x00000002	/* Read state (transferring data to the MAC transmitter) */
  #define ETH_MTLTQDR_TRCSTS_WAITING  0x00000004	/* Waiting for pending Tx Status from the MAC transmitter */
  #define ETH_MTLTQDR_TRCSTS_FLUSHING 0x00000006	/* Flushing the Tx queue because of the Packet Abort request from the MAC */
  #define ETH_MTLTQDR_TWCSTS    0x00000008	/* MTL Tx Queue Write Controller Status */
  #define ETH_MTLTQDR_TXQSTS    0x00000010	/* MTL Tx Queue Not Empty Status */
  #define ETH_MTLTQDR_TXSTSFSTS 0x00000020	/* MTL Tx Status FIFO Full Status */
  #define ETH_MTLTQDR_PTXQ      0x00070000	/* Number of Packets in the Transmit Queue */
  #define ETH_MTLTQDR_STXSTSF   0x00700000	/* Number of Status Words in the Tx Status FIFO of Queue */
#define TOFF_ETH_MTLQICSR   0x0D2C		/* (RW) Ethernet MTL Queue Interrupt Control Status Register */
  #define ETH_MTLQICSR_TXUNFIS  0x00000001	/* Transmit Queue Underflow Interrupt Status */
  #define ETH_MTLQICSR_TXUIE    0x00000100	/* Transmit Queue Underflow Interrupt Enable */
  #define ETH_MTLQICSR_RXOVFIS  0x00010000	/* Receive Queue Overflow Interrupt Status */
  #define ETH_MTLQICSR_RXOIE    0x01000000	/* Receive Queue Overflow Interrupt Enable */
#define TOFF_ETH_MTLRQOMR   0x0D30		/* (RW) Ethernet MTL Rx Queue Operation Mode Register */
  #define ETH_MTLRQOMR_RTC      0x00000003	/* Receive Queue Threshold Control */
  #define ETH_MTLRQOMR_RTC_64BITS  0x00000000	/* 64 bits Threshold */
  #define ETH_MTLRQOMR_RTC_32BITS  0x00000001	/* 32 bits Threshold */
  #define ETH_MTLRQOMR_RTC_96BITS  0x00000002	/* 96 bits Threshold */
  #define ETH_MTLRQOMR_RTC_128BITS 0x00000003	/* 128 bits Threshold */
  #define ETH_MTLRQOMR_FUP      0x00000008	/* Forward Undersized Good Packets */
  #define ETH_MTLRQOMR_FEP      0x00000010	/* Forward Error Packets */
  #define ETH_MTLRQOMR_RSF      0x00000020	/* Receive Queue Store and Forward */
  #define ETH_MTLRQOMR_DISTCPEF 0x00000040	/* Disable Dropping of TCP/IP Checksum Error Packets */
  #define ETH_MTLRQOMR_EHFC     0x00000080	/* DEnable Hardware Flow Control */
  #define ETH_MTLRQOMR_RFA      0x00000700	/* Threshold for Activating Flow Control (in half-duplex and full-duplex */
  #define ETH_MTLRQOMR_RFD      0x0001C000	/* Threshold for Deactivating Flow Control (in half-duplex and full-duplex modes) */
  #define ETH_MTLRQOMR_RQS      0x00700000	/* Receive Queue Size */
#define TOFF_ETH_MTLRQMPOCR 0x0D34		/* (RW) Ethernet MTL Rx Queue Missed Packet Overflow Cnt Register */
  #define ETH_MTLRQMPOCR_OVFPKTCNT 0x000007FF	/* Overflow Packet Counter */
  #define ETH_MTLRQMPOCR_OVFCNTOVF 0x00000800	/* Overflow Counter Overflow Bit */
  #define ETH_MTLRQMPOCR_MISPKTCNT 0x07FF0000	/* Missed Packet Counter */
  #define ETH_MTLRQMPOCR_MISCNTOVF 0x08000000	/* Missed Packet Counter Overflow Bit */
#define TOFF_ETH_MTLRQDR    0x0D38		/* (RW) for Ethernet MTL Rx Queue Debug Register */
  #define ETH_MTLRQDR_RWCSTS    0x00000001	/* MTL Rx Queue Write Controller Active Status */
  #define ETH_MTLRQDR_RRCSTS    0x00000006	/* MTL Rx Queue Read Controller State */
  #define ETH_MTLRQDR_RRCSTS_IDLE           0x00000000	/* Idle state */
  #define ETH_MTLRQDR_RRCSTS_READINGDATA    0x00000002	/* Reading packet data */
  #define ETH_MTLRQDR_RRCSTS_READINGSTATUS  0x00000004	/* Reading packet status (or timestamp) */
  #define ETH_MTLRQDR_RRCSTS_FLUSHING       0x00000006	/* Flushing the packet data and status */
  #define ETH_MTLRQDR_RXQSTS    0x00000030	/* MTL Rx Queue Fill-Level Status */
  #define ETH_MTLRQDR_RXQSTS_EMPTY          0x00000000	/* Rx Queue empty */
  #define ETH_MTLRQDR_RXQSTS_BELOWTHRESHOLD 0x00000010	/* Rx Queue fill-level below flow-control deactivate threshold */
  #define ETH_MTLRQDR_RXQSTS_ABOVETHRESHOLD 0x00000020	/* Rx Queue fill-level above flow-control activate threshold */
  #define ETH_MTLRQDR_RXQSTS_FULL           0x00000030	/* Rx Queue full */
  #define ETH_MTLRQDR_PRXQ      0x3FFF0000	/* Number of Packets in Receive Queue */
#define TOFF_ETH_DMAMR      0x1000		/* (RW) Ethernet DMA Mode Register */
  #define ETH_DMAMR_SWR         0x00000001	/* Software Reset */
  #define ETH_DMAMR_DA          0x00000002	/* DMA Tx or Rx Arbitration Scheme */
  #define ETH_DMAMR_TXPR        0x00000800	/* Transmit Priority */
  #define ETH_DMAMR_PR          0x00007000	/* Priority Ratio */
  #define ETH_DMAMR_PR_1_1      0x00000000	/* The priority ratio is 1:1 */
  #define ETH_DMAMR_PR_2_1      0x00001000	/* The priority ratio is 2:1 */
  #define ETH_DMAMR_PR_3_1      0x00002000	/* The priority ratio is 3:1 */
  #define ETH_DMAMR_PR_4_1      0x00003000	/* The priority ratio is 4:1 */
  #define ETH_DMAMR_PR_5_1      0x00004000	/* The priority ratio is 5:1 */
  #define ETH_DMAMR_PR_6_1      0x00005000	/* The priority ratio is 6:1 */
  #define ETH_DMAMR_PR_7_1      0x00006000	/* The priority ratio is 7:1 */
  #define ETH_DMAMR_PR_8_1      0x00007000	/* The priority ratio is 8:1 */
  #define ETH_DMAMR_INTM        0x00030000	/* This field defines the interrupt mode */
  #define ETH_DMAMR_INTM_0      0x00000000
  #define ETH_DMAMR_INTM_1      0x00010000
  #define ETH_DMAMR_INTM_2      0x00020000
#define TOFF_ETH_DMASBMR    0x1004		/* (RW) Ethernet DMA SysBus Mode Register */
  #define ETH_DMASBMR_FB        0x00000001	/* Fixed Burst Length */
  #define ETH_DMASBMR_AAL       0x00001000	/* Address-Aligned Beats */
  #define ETH_DMASBMR_MB        0x00004000	/* Mixed Burst */
  #define ETH_DMASBMR_RB        0x00008000	/* Rebuild INCRx Burst */
#define TOFF_ETH_DMAISR     0x1008		/* (RW) Ethernet DMA Interrupt Status Register */
  #define ETH_DMAISR_DMACIS     0x00000001	/* DMA Channel Interrupt Status */
  #define ETH_DMAISR_MTLIS      0x00010000	/* MAC Interrupt Status */
  #define ETH_DMAISR_MACIS      0x00020000	/* MAC Interrupt Status */
#define TOFF_ETH_DMADSR     0x100C		/* (RW) Ethernet DMA Debug Status Register */
  #define ETH_DMADSR_RPS        0x00000F00	/* DMA Channel Receive Process State */
  #define ETH_DMADSR_RPS_STOPPED       0x00000000	/* Stopped (Reset or Stop Receive Command issued) */
  #define ETH_DMADSR_RPS_FETCHING      0x00000100	/* Running (Fetching Rx Transfer Descriptor) */
  #define ETH_DMADSR_RPS_WAITING       0x00000300	/* Running (Waiting for status) */
  #define ETH_DMADSR_RPS_SUSPENDED     0x00000400	/* Suspended (Rx Descriptor Unavailable) */
  #define ETH_DMADSR_RPS_CLOSING       0x00000500	/* Running (Closing the Rx Descriptor) */
  #define ETH_DMADSR_RPS_TIMESTAMP_WR  0x00000600	/* Timestamp write state */
  #define ETH_DMADSR_RPS_TRANSFERRING  0x00000700	/* Running (Transferring the received packet data from the Rx buffer to the system memory) */
  #define ETH_DMADSR_TPS        0x0000F000	/* DMA Channel Transmit Process State */
  #define ETH_DMADSR_TPS_STOPPED       0x00000000	/* Stopped (Reset or Stop Transmit Command issued) */
  #define ETH_DMADSR_TPS_FETCHING      0x00001000	/* Running (Fetching Tx Transfer Descriptor) */
  #define ETH_DMADSR_TPS_WAITING       0x00002000	/* Running (Waiting for status) */
  #define ETH_DMADSR_TPS_READING       0x00003000	/* Running (Reading Data from system memory buffer and queuing it to the Tx buffer (Tx FIFO)) */
  #define ETH_DMADSR_TPS_TIMESTAMP_WR  0x00004000	/* Timestamp write state */
  #define ETH_DMADSR_TPS_SUSPENDED     0x00006000	/* Suspended (Tx Descriptor Unavailable or Tx Buffer Underflow) */
  #define ETH_DMADSR_TPS_CLOSING       0x00007000	/* Running (Closing Tx Descriptor) */
#define TOFF_ETH_DMACCR     0x1100		/* (RW) Ethernet DMA Channel Control Register */
  #define ETH_DMACCR_MSS        0x00003FFF	/* Maximum Segment Size */
  #define ETH_DMACCR_8PBL       0x00010000	/* 8xPBL mode */
  #define ETH_DMACCR_DSL        0x001C0000	/* Descriptor Skip Length */
  #define ETH_DMACCR_DSL_0BIT   0x00000000
  #define ETH_DMACCR_DSL_32BIT  0x00040000
  #define ETH_DMACCR_DSL_64BIT  0x00080000
  #define ETH_DMACCR_DSL_128BIT 0x00100000
#define TOFF_ETH_DMACTCR    0x1104		/* (RW) Ethernet DMA Channel Tx Control Register */
  #define ETH_DMACTCR_ST        0x00000001	/* Start or Stop Transmission Command */
  #define ETH_DMACTCR_OSP       0x00000010	/* Operate on Second Packet */
  #define ETH_DMACTCR_TSE       0x00001000	/* TCP Segmentation Enabled */
  #define ETH_DMACTCR_TPBL      0x003F0000	/* Transmit Programmable Burst Length */
  #define ETH_DMACTCR_TPBL_1PBL  0x00010000	/* Transmit Programmable Burst Length 1 */
  #define ETH_DMACTCR_TPBL_2PBL  0x00020000	/* Transmit Programmable Burst Length 2 */
  #define ETH_DMACTCR_TPBL_4PBL  0x00040000	/* Transmit Programmable Burst Length 4 */
  #define ETH_DMACTCR_TPBL_8PBL  0x00080000	/* Transmit Programmable Burst Length 8 */
  #define ETH_DMACTCR_TPBL_16PBL 0x00100000	/* Transmit Programmable Burst Length 16 */
  #define ETH_DMACTCR_TPBL_32PBL 0x00200000	/* Transmit Programmable Burst Length 32 */
#define TOFF_ETH_DMACRCR    0x1108		/* (RW) Ethernet DMA Channel Rx Control Register */
  #define ETH_DMACRCR_SR        0x00000001	/* Start or Stop Receive */
  #define ETH_DMACRCR_RBSZ      0x00007FFE	/* Receive Buffer size */
  #define ETH_DMACRCR_RPBL      0x003F0000	/* Receive Programmable Burst Length */
  #define ETH_DMACRCR_RPBL_1PBL  0x00010000	/* Receive Programmable Burst Length 1 */
  #define ETH_DMACRCR_RPBL_2PBL  0x00020000	/* Receive Programmable Burst Length 2 */
  #define ETH_DMACRCR_RPBL_4PBL  0x00040000	/* Receive Programmable Burst Length 4 */
  #define ETH_DMACRCR_RPBL_8PBL  0x00080000	/* Receive Programmable Burst Length 8 */
  #define ETH_DMACRCR_RPBL_16PBL 0x00100000	/* Receive Programmable Burst Length 16 */
  #define ETH_DMACRCR_RPBL_32PBL 0x00200000	/* Receive Programmable Burst Length 32 */
  #define ETH_DMACRCR_RPF       0x80000000	/* Rx Packet Flush */
#define TOFF_ETH_DMACTDLAR  0x1114		/* (RW) Ethernet DMA CH Tx Desc List Address Register */
#define TOFF_ETH_DMACRDLAR  0x111C		/* (RW) Ethernet DMA CH Rx Desc List Address Register */
#define TOFF_ETH_DMACTDTPR  0x1120		/* (RW) Ethernet DMA CH Tx Desc Tail Pointer Register */
#define TOFF_ETH_DMACRDTPR  0x1128		/* (RW) Ethernet DMA CH Rx Desc Tail Pointer Register */
#define TOFF_ETH_DMACTDRLR  0x112C		/* (RW) Ethernet DMA CH Tx Desc Ring Length Register */
#define TOFF_ETH_DMACRDRLR  0x1130		/* (RW) Ethernet DMA CH Rx Desc Ring Length Register */
#define TOFF_ETH_DMACIER    0x1134		/* (RW) Ethernet DMA Channel Interrupt Enable Register */
  #define ETH_DMACIER_TIE       0x00000001	/* Transmit Interrupt Enable */
  #define ETH_DMACIER_TXSE      0x00000002	/* Transmit Stopped Enable */
  #define ETH_DMACIER_TBUE      0x00000004	/* Transmit Buffer Unavailable Enable */
  #define ETH_DMACIER_RIE       0x00000040	/* Receive Interrupt Enable */
  #define ETH_DMACIER_RBUE      0x00000080	/* Receive Buffer Unavailable Enable */
  #define ETH_DMACIER_RSE       0x00000100	/* Receive Stopped Enable */
  #define ETH_DMACIER_RWTE      0x00000200	/* Receive Watchdog Timeout Enable */
  #define ETH_DMACIER_ETIE      0x00000400	/* Early Transmit Interrupt Enable */
  #define ETH_DMACIER_ERIE      0x00000800	/* Early Receive Interrupt Enable */
  #define ETH_DMACIER_FBEE      0x00001000	/* Fatal Bus Error Enable */
  #define ETH_DMACIER_CDEE      0x00002000	/* Context Descriptor Error Enable */
  #define ETH_DMACIER_AIE       0x00004000	/* Abnormal Interrupt Summary Enable */
  #define ETH_DMACIER_NIE       0x00008000	/* Normal Interrupt Summary Enable */
#define TOFF_ETH_DMACRIWTR  0x1138		/* (RW) Ethernet DMA Channel Rx Interrupt Watchdog Timer Register */
#define TOFF_ETH_DMACSFCSR  0x113C
#define TOFF_ETH_DMACCATDR  0x1144		/* (RW) Ethernet DMA Channel Current App Tx Desc Register */
#define TOFF_ETH_DMACCARDR  0x114C		/* (RW) Ethernet DMA Channel Current App Rx Desc Register */
#define TOFF_ETH_DMACCATBR  0x1154		/* (RW) Ethernet DMA Channel Current App Tx Buffer Register */
#define TOFF_ETH_DMACCARBR  0x115C		/* (RW) Ethernet DMA Channel Current App Rx Buffer Register */
#define TOFF_ETH_DMACSR     0x1160		/* (RW) Ethernet DMA Channel Status Register */
  #define ETH_DMACSR_TI         0x00000001	/* Transmit Interrupt */
  #define ETH_DMACSR_TPS        0x00000002	/* Transmit Process Stopped */
  #define ETH_DMACSR_TBU        0x00000004	/* Transmit Buffer Unavailable */
  #define ETH_DMACSR_RI         0x00000040	/* Receive Interrupt */
  #define ETH_DMACSR_RBU        0x00000080	/* Receive Buffer Unavailable */
  #define ETH_DMACSR_RPS        0x00000100	/* Receive Process Stopped */
  #define ETH_DMACSR_RWT        0x00000200	/* Receive Watchdog Timeout */
  #define ETH_DMACSR_ETI        0x00000400	/* Early Transmit Interrupt */
  #define ETH_DMACSR_ERI        0x00000800	/* Early Receive Interrupt */
  #define ETH_DMACSR_FBE        0x00001000	/* Fatal Bus Error */
  #define ETH_DMACSR_CDE        0x00002000	/* Context Descriptor Error */
  #define ETH_DMACSR_AIS        0x00004000	/* Abnormal Interrupt Summary */
  #define ETH_DMACSR_NIS        0x00008000	/* Normal Interrupt Summary */
  #define ETH_DMACSR_TEB        0x00070000	/* Tx DMA Error Bits */
  #define ETH_DMACSR_REB        0x00380000	/* Rx DMA Error Bits */
#define TOFF_ETH_DMACMFCR   0x116C		/* (RW) Ethernet DMA Channel missed frame count register */
  #define ETH_DMACMFCR_MFC      0x000007FF	/* The number of packet counters dropped by the DMA */
  #define ETH_DMACMFCR_MFCO     0x00008000	/* Overflow status of the MFC Counter */


/*
 *  SERIAL AUDIO INTERFACE
 */
#define TADR_SAI1_BASE      (D2_APB2PERIPH_BASE + 0x5800)
#define TADR_SAI2_BASE      (D2_APB2PERIPH_BASE + 0x5C00)
#define TADR_SAI3_BASE      (D2_APB2PERIPH_BASE + 0x6000)
#define TADR_SAI4_BASE      (D3_APB1PERIPH_BASE + 0x5400)
#define TOFF_SAI_GCR        0x0000		/* (RW) SAI global configuration register */
  #define SAI_GCR_SYNCIN      0x00000003	/* SYNCIN[1:0] bits (Synchronization Inputs)   */
  #define SAI_GCR_SYNCIN_0    0x00000001	/* Bit 0 */
  #define SAI_GCR_SYNCIN_1    0x00000002	/* Bit 1 */
  #define SAI_GCR_SYNCOUT     0x00000030	/* SYNCOUT[1:0] bits (Synchronization Outputs) */
  #define SAI_GCR_SYNCOUT_0   0x00000010	/* Bit 0 */
  #define SAI_GCR_SYNCOUT_1   0x00000020	/* Bit 1 */
#define TOFF_SAI_PDMCR      0x0044		/* (RW) SAI PDM control register */
  #define SAI_PDMCR_PDMEN     0x00000001	/* PDM Enable */
  #define SAI_PDMCR_MICNBR    0x00000030	/* Number of microphones */
  #define SAI_PDMCR_MICNBR_0  0x00000010
  #define SAI_PDMCR_MICNBR_1  0x00000020
  #define SAI_PDMCR_CKEN1     0x00000100	/* Clock enable of bitstream clock number 1 */
  #define SAI_PDMCR_CKEN2     0x00000200	/* Clock enable of bitstream clock number 2 */
  #define SAI_PDMCR_CKEN3     0x00000400	/* Clock enable of bitstream clock number 3 */
  #define SAI_PDMCR_CKEN4     0x00000800	/* Clock enable of bitstream clock number 4 */
#define TOFF_SAI_PDMDLY     0x0048		/* (RW) SAI PDM delay register */
  #define SAI_PDMDLY_DLYM1L   0x00000007	/* DLYM1L[2:0] (Delay line adjust for left microphone of pair 1) */
  #define SAI_PDMDLY_DLYM1L_0 0x00000001
  #define SAI_PDMDLY_DLYM1L_1 0x00000002
  #define SAI_PDMDLY_DLYM1L_2 0x00000004
  #define SAI_PDMDLY_DLYM1R   0x00000070	/* DLYM1R[2:0] (Delay line adjust for right microphone of pair 1) */
  #define SAI_PDMDLY_DLYM1R_0 0x00000010
  #define SAI_PDMDLY_DLYM1R_1 0x00000020
  #define SAI_PDMDLY_DLYM1R_2 0x00000040
  #define SAI_PDMDLY_DLYM2L   0x00000700	/* DLYM2L[2:0] (Delay line adjust for left microphone of pair 2) */
  #define SAI_PDMDLY_DLYM2L_0 0x00000100
  #define SAI_PDMDLY_DLYM2L_1 0x00000200
  #define SAI_PDMDLY_DLYM2L_2 0x00000400
  #define SAI_PDMDLY_DLYM2R   0x00007000	/* DLYM2R[2:0] (Delay line adjust for right microphone of pair 2)*/
  #define SAI_PDMDLY_DLYM2R_0 0x00001000
  #define SAI_PDMDLY_DLYM2R_1 0x00002000
  #define SAI_PDMDLY_DLYM2R_2 0x00004000
  #define SAI_PDMDLY_DLYM3L   0x00070000	/* DLYM3L[2:0] (Delay line adjust for left microphone of pair 3)*/
  #define SAI_PDMDLY_DLYM3L_0 0x00010000
  #define SAI_PDMDLY_DLYM3L_1 0x00020000
  #define SAI_PDMDLY_DLYM3L_2 0x00040000
  #define SAI_PDMDLY_DLYM3R   0x00700000	/* DLYM3R[2:0] (Delay line adjust for right microphone of pair 3)*/
  #define SAI_PDMDLY_DLYM3R_0 0x00100000
  #define SAI_PDMDLY_DLYM3R_1 0x00200000
  #define SAI_PDMDLY_DLYM3R_2 0x00400000
  #define SAI_PDMDLY_DLYM4L   0x07000000	/* DLYM4L[2:0] (Delay line adjust for left microphone of pair 4)*/
  #define SAI_PDMDLY_DLYM4L_0 0x01000000
  #define SAI_PDMDLY_DLYM4L_1 0x02000000
  #define SAI_PDMDLY_DLYM4L_2 0x04000000
  #define SAI_PDMDLY_DLYM4R   0x70000000	/* DLYM4R[2:0] (Delay line adjust for right microphone of pair 4)*/
  #define SAI_PDMDLY_DLYM4R_0 0x10000000
  #define SAI_PDMDLY_DLYM4R_1 0x20000000
  #define SAI_PDMDLY_DLYM4R_2 0x40000000

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
  #define SAI_xCR1_MCKDIV_4   0x01000000	/* Bit 4 */
  #define SAI_xCR1_MCKDIV_5   0x02000000	/* Bit 5 */
  #define SAI_xCR1_OSR        0x04000000	/* OverSampling Ratio for master clock  */
  #define SAI_xCR1_MCKEN      0x08000000	/* Master ClocK enable */
  #define SAI_xCR1_NOMCK      SAI_xCR1_NODIV
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
  #define SAI_xFRCR_FSPOL     0x00020000	/* Frame Synchronization POLarity */
  #define SAI_xFRCR_FSOFF     0x00040000	/* Frame Synchronization OFFset*/
  #define SAI_xFRCR_FSPO      SAI_xFRCR_FSPOL
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
  #define SAI_xCLRFR_COVRUDR  0x00000001	/* Clear Overrun underrun */
  #define SAI_xCLRFR_CMUTEDET 0x00000002	/* Clear Mute detection */
  #define SAI_xCLRFR_CWCKCFG  0x00000004	/* Clear Wrong Clock Configuration */
  #define SAI_xCLRFR_CFREQ    0x00000008	/* Clear FIFO request */
  #define SAI_xCLRFR_CCNRDY   0x00000010	/* Clear Codec not ready */
  #define SAI_xCLRFR_CAFSDET  0x00000020	/* Clear Anticipated frame synchronization detection */
  #define SAI_xCLRFR_CLFSDET  0x00000040	/* Clear Late frame synchronization detection           */
#define TOFF_SAI_DR         0x001C		/* (RW) SAI block x data register */


/*
 *  COMPARATOR
 */
#define TADR_COMP12_BASE    (D3_APB1PERIPH_BASE + 0x3800)
#define TOFF_COMP_SR        0x0000		/* (RW) Comparator status register */
  #define COMP_SR_C1VAL      0x00000001
  #define COMP_SR_C2VAL      0x00000002
  #define COMP_SR_C1IF       0x00010000
  #define COMP_SR_C2IF       0x00020000
#define TOFF_COMP_ICFR      0x0004		/* (RW) Comparator interrupt clear flag register */
  #define COMP_ICFR_C1IF     0x00010000
  #define COMP_ICFR_C2IF     0x00020000
#define TOFF_COMP_OR        0x0008		/* (RW) Comparator option register */
  #define COMP_OR_AFOPA6     0x00000001
  #define COMP_OR_AFOPA8     0x00000002
  #define COMP_OR_AFOPB12    0x00000004
  #define COMP_OR_AFOPE6     0x00000008
  #define COMP_OR_AFOPE15    0x00000010
  #define COMP_OR_AFOPG2     0x00000020
  #define COMP_OR_AFOPG3     0x00000040
  #define COMP_OR_AFOPG4     0x00000080
  #define COMP_OR_AFOPI1     0x00000100
  #define COMP_OR_AFOPI4     0x00000200
  #define COMP_OR_AFOPK2     0x00000400

#define TADR_COMP1_BASE     (TADR_COMP12_BASE + 0x0C)
#define TADR_COMP2_BASE     (TADR_COMP12_BASE + 0x10)
#define TOFF_COP_CFGR       0x0000		/* (RW) Comparator configuration register */
  #define COMP_CFGR_EN          0x00000001	/* COMPx enable bit */
  #define COMP_CFGR_BRGEN       0x00000002	/* COMPx Scaler bridge enable */
  #define COMP_CFGRx_SCALEN     0x00000004	/* COMPx Voltage scaler enable bit */
  #define COMP_CFGRx_POLARITY   0x00000008	/* COMPx  polarity selection bit */
  #define COMP_CFGRx_WINMODE    0x00000010	/* COMPx Windows mode selection bit */
  #define COMP_CFGRx_ITEN       0x00000040	/* COMPx  interrupt enable */
  #define COMP_CFGRx_HYST       0x00000300	/* COMPx  hysteresis selection bits */
  #define COMP_CFGRx_HYST_0     0x00000100
  #define COMP_CFGRx_HYST_1     0x00000200
  #define COMP_CFGRx_PWRMODE    0x00003000	/* COMPx Power Mode of the comparator */
  #define COMP_CFGRx_PWRMODE_0  0x00001000
  #define COMP_CFGRx_PWRMODE_1  0x00002000
  #define COMP_CFGRx_INMSEL     0x00070000	/* COMPx  input minus selection bit  */
  #define COMP_CFGRx_INMSEL_0   0x00010000
  #define COMP_CFGRx_INMSEL_1   0x00020000
  #define COMP_CFGRx_INMSEL_2   0x00040000
  #define COMP_CFGRx_INPSEL     0x00100000	/* COMPx  input plus selection bit */
  #define COMP_CFGRx_BLANKING   0x0F000000	/* COMPx  blanking source selection bits */
  #define COMP_CFGRx_BLANKING_0 0x01000000
  #define COMP_CFGRx_BLANKING_1 0x02000000
  #define COMP_CFGRx_BLANKING_2 0x04000000
  #define COMP_CFGRx_LOCK       0x80000000	/* COMPx Lock Bit */


/*
 *  VREFBUF
 */
#define TADR_VREFBUF_BASE   (D3_APB1PERIPH_BASE + 0x3C00)
#define TOFF_VREFBUF_CSR    0x0000		/* (RW) VREFBUF control and status register */
  #define VREFBUF_CSR_ENVR      0x00000001	/* Voltage reference buffer enable */
  #define VREFBUF_CSR_HIZ       0x00000002	/* High impedance mode */
  #define VREFBUF_CSR_VRR       0x00000008	/* Voltage reference buffer ready  */
  #define VREFBUF_CSR_VRS       0x00000070	/* Voltage reference scale */
  #define VREFBUF_CSR_VRS_OUT1  0x00000000	/* Voltage reference VREF_OUT1 */
  #define VREFBUF_CSR_VRS_OUT2  0x00000010	/* Voltage reference VREF_OUT2 */
  #define VREFBUF_CSR_VRS_OUT3  0x00000020	/* Voltage reference VREF_OUT3 */
  #define VREFBUF_CSR_VRS_OUT4  0x00000030	/* Voltage reference VREF_OUT4     */
#define TOFF_VREFBUF_CCR    0x0004		/* (RW) VREFBUF calibration and control register */
  #define VREFBUF_CCR_TRIM      0x0000003F	/* TRIM[5:0] bits (Trimming code)  */


/*
 *  LCD-TFT DISPLAY CONTROLLER
 */
#define TADR_LTDC_BASE      (D1_APB1PERIPH_BASE + 0x1000)
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
  #define LTDC_GCR_DEN       LTDC_GCR_DTEN
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
  #define LTDC_CDSR_VDES     0x00000001	/* Vertical Data Enable Status */
  #define LTDC_CDSR_HDES     0x00000002	/* Horizontal Data Enable Status */
  #define LTDC_CDSR_VSYNCS   0x00000004	/* Vertical Synchronization Status */
  #define LTDC_CDSR_HSYNCS   0x00000008	/* Horizontal Synchronization Status */


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
#define TADR_DCMI_BASE      (D2_AHB2PERIPH_BASE + 0x0000)
#define TOFF_DCMI_CR        0x0000		/* (RW) DCMI control register 1 */
  #define DCMI_CR_CAPTURE     0x00000001
  #define DCMI_CR_CM          0x00000002
  #define DCMI_CR_CROP        0x00000004
  #define DCMI_CR_JPEG        0x00000008
  #define DCMI_CR_ESS         0x00000010
  #define DCMI_CR_PCKPOL      0x00000020
  #define DCMI_CR_HSPOL       0x00000040
  #define DCMI_CR_VSPOL       0x00000080
  #define DCMI_CR_FCRC_0      0x00000100
  #define DCMI_CR_FCRC_1      0x00000200
  #define DCMI_CR_EDM_0       0x00000400
  #define DCMI_CR_EDM_1       0x00000800
  #define DCMI_CR_CRE         0x00001000
  #define DCMI_CR_ENABLE      0x00004000
  #define DCMI_CR_BSM         0x00030000
  #define DCMI_CR_BSM_0       0x00010000
  #define DCMI_CR_BSM_1       0x00020000
  #define DCMI_CR_OEBS        0x00040000
  #define DCMI_CR_LSM         0x00080000
  #define DCMI_CR_OELS        0x00100000
#define TOFF_DCMI_SR        0x0004		/* (R)  DCMI status register */
  #define DCMI_SR_HSYNC       0x00000001
  #define DCMI_SR_VSYNC       0x00000002
  #define DCMI_SR_FNE         0x00000004
#define TOFF_DCMI_RISR      0x0008		/* (R)  DCMI raw interrupt status register */
  #define DCMI_RIS_FRAME_RIS  0x00000001
  #define DCMI_RIS_OVR_RIS    0x00000002
  #define DCMI_RIS_ERR_RIS    0x00000004
  #define DCMI_RIS_VSYNC_RIS  0x00000008
  #define DCMI_RIS_LINE_RIS   0x00000010
#define TOFF_DCMI_IER       0x000C		/* (RW) DCMI interrupt enable register */
  #define DCMI_IER_FRAME_IE   0x00000001
  #define DCMI_IER_OVR_IE     0x00000002
  #define DCMI_IER_ERR_IE     0x00000004
  #define DCMI_IER_VSYNC_IE   0x00000008
  #define DCMI_IER_LINE_IE    0x00000010
#define TOFF_DCMI_MISR      0x0010		/* (RW) DCMI masked interrupt status register */
  #define DCMI_MIS_FRAME_MIS  0x00000001
  #define DCMI_MIS_OVR_MIS    0x00000002
  #define DCMI_MIS_ERR_MIS    0x00000004
  #define DCMI_MIS_VSYNC_MIS  0x00000008
  #define DCMI_MIS_LINE_MIS   0x00000010
#define TOFF_DCMI_ICR       0x0014		/* (RW) DCMI interrupt clear register */
  #define DCMI_ICR_FRAME_ISC  0x00000001
  #define DCMI_ICR_OVR_ISC    0x00000002
  #define DCMI_ICR_ERR_ISC    0x00000004
  #define DCMI_ICR_VSYNC_ISC  0x00000008
  #define DCMI_ICR_LINE_ISC   0x00000010
#define TOFF_DCMI_ESCR      0x0018		/* (RW) DCMI embedded synchronization code register */
  #define DCMI_ESCR_FSC       0x000000FF
  #define DCMI_ESCR_LSC       0x0000FF00
  #define DCMI_ESCR_LEC       0x00FF0000
  #define DCMI_ESCR_FEC       0xFF000000
#define TOFF_DCMI_ESUR      0x001C		/* (RW) DCMI embedded synchronization unmask register */
  #define DCMI_ESUR_FSU       0x000000FF
  #define DCMI_ESUR_LSU       0x0000FF00
  #define DCMI_ESUR_LEU       0x00FF0000
  #define DCMI_ESUR_FEU       0xFF000000
#define TOFF_DCMI_CWSTRTR   0x0020		/* (RW) DCMI crop window start */
  #define DCMI_CWSTRT_HOFFCNT 0x00003FFF
  #define DCMI_CWSTRT_VST     0x1FFF0000
#define TOFF_DCMI_CWSIZER   0x0024		/* (RW) DCMI crop window size */
  #define DCMI_CWSIZE_CAPCNT  0x00003FFF
  #define DCMI_CWSIZE_VLINE   0x3FFF0000
#define TOFF_DCMI_DR        0x0028		/* (RW) DCMI data register */
  #define DCMI_DR_BYTE0       0x000000FF
  #define DCMI_DR_BYTE1       0x0000FF00
  #define DCMI_DR_BYTE2       0x00FF0000
  #define DCMI_DR_BYTE3       0xFF000000


/*
 *  RNG
 */
#define TADR_RNG_BASE       (D2_AHB2PERIPH_BASE + 0x1800)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */


/*
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FMC_R_BASE    (D1_AHB1PERIPH_BASE + 0x4000)

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
  #define FMC_BCR1_BMAP      0x03000000	/* BMAP[1:0] FMC bank mapping */
  #define FMC_BCR1_BMAP_0    0x01000000
  #define FMC_BCR1_BMAP_1    0x02000000
  #define FMC_BCR1_FMCEN     0x80000000	/* FMC controller Enable */
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
 *  FLEXIBLE MEMORY CONTROLLER BANK2
 */
#define TOFF_FMC_PSR2       0x0060		/* (RW) NAND Flash control register 2 */
#define TOFF_FMC_SR2        0x0064		/* (RW) NAND Flash FIFO status and interrupt register 2 */
#define TOFF_FMC_PMEM2      0x0068		/* (RW) NAND Flash Common memory space timing register 2 */
#define TOFF_FMC_PATT2      0x006C		/* (RW) NAND Flash Attribute memory space timing register 2 */
#define TOFF_FMC_ECCR2      0x0074		/* (RW) NAND Flash ECC result registers 2 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK3
 */
#define TOFF_FMC_R_PCR      0x0080		/* (RW) NAND Flash control register */
  #define FMC_PCR_PWAITEN    0x00000002	/* Wait feature enable bit                   */
  #define FMC_PCR_PBKEN      0x00000004	/* NAND Flash memory bank enable bit */
  #define FMC_PCR_PWID       0x00000030	/* PWID[1:0] bits (NAND Flash databus width) */
  #define FMC_PCR_PWID_0     0x00000010
  #define FMC_PCR_PWID_1     0x00000020
  #define FMC_PCR_ECCEN      0x00000040	/* ECC computation logic enable bit */
  #define FMC_PCR_TCLR       0x00001E00	/* TCLR[3:0] bits (CLE to RE delay) */
  #define FMC_PCR_TCLR_0     0x00000200
  #define FMC_PCR_TCLR_1     0x00000400
  #define FMC_PCR_TCLR_2     0x00000800
  #define FMC_PCR_TCLR_3     0x00001000
  #define FMC_PCR_TAR        0x0001E000	/* TAR[3:0] bits (ALE to RE delay) */
  #define FMC_PCR_TAR_0      0x00002000
  #define FMC_PCR_TAR_1      0x00004000
  #define FMC_PCR_TAR_2      0x00008000
  #define FMC_PCR_TAR_3      0x00010000
  #define FMC_PCR_ECCPS      0x000E0000	/* ECCPS[1:0] bits (ECC page size) */
  #define FMC_PCR_ECCPS_0    0x00020000
  #define FMC_PCR_ECCPS_1    0x00040000
  #define FMC_PCR_ECCPS_2    0x00080000
#define TOFF_FMC_R_SR       0x0084		/* (RW) NAND Flash FIFO status and interrupt register */
  #define FMC_SR_IRS         0x00000001	/* Interrupt Rising Edge status */
  #define FMC_SR_ILS         0x00000002	/* Interrupt Level status */
  #define FMC_SR_IFS         0x00000004	/* Interrupt Falling Edge status */
  #define FMC_SR_IREN        0x00000008	/* Interrupt Rising Edge detection Enable bit  */
  #define FMC_SR_ILEN        0x00000010	/* Interrupt Level detection Enable bit */
  #define FMC_SR_IFEN        0x00000020	/* Interrupt Falling Edge detection Enable bit */
  #define FMC_SR_FEMPT       0x00000040	/* FIFO empty */
#define TOFF_FMC_R_PMEM     0x0088		/* (RW) NAND Flash Common memory space timing register */
  #define FMC_PMEM_MEMSET    0x000000FF	/* MEMSET[7:0] bits (Common memory setup time) */
  #define FMC_PMEM_MEMSET_0  0x00000001
  #define FMC_PMEM_MEMSET_1  0x00000002
  #define FMC_PMEM_MEMSET_2  0x00000004
  #define FMC_PMEM_MEMSET_3  0x00000008
  #define FMC_PMEM_MEMSET_4  0x00000010
  #define FMC_PMEM_MEMSET_5  0x00000020
  #define FMC_PMEM_MEMSET_6  0x00000040
  #define FMC_PMEM_MEMSET_7  0x00000080
  #define FMC_PMEM_MEMWAIT   0x0000FF00	/* MEMWAIT[7:0] bits (Common memory wait time) */
  #define FMC_PMEM_MEMWAIT_0 0x00000100
  #define FMC_PMEM_MEMWAIT_1 0x00000200
  #define FMC_PMEM_MEMWAIT_2 0x00000400
  #define FMC_PMEM_MEMWAIT_3 0x00000800
  #define FMC_PMEM_MEMWAIT_4 0x00001000
  #define FMC_PMEM_MEMWAIT_5 0x00002000
  #define FMC_PMEM_MEMWAIT_6 0x00004000
  #define FMC_PMEM_MEMWAIT_7 0x00008000
  #define FMC_PMEM_MEMHOLD   0x00FF0000	/* MEMHOLD[7:0] bits (Common memory hold time) */
  #define FMC_PMEM_MEMHOLD_0 0x00010000
  #define FMC_PMEM_MEMHOLD_1 0x00020000
  #define FMC_PMEM_MEMHOLD_2 0x00040000
  #define FMC_PMEM_MEMHOLD_3 0x00080000
  #define FMC_PMEM_MEMHOLD_4 0x00100000
  #define FMC_PMEM_MEMHOLD_5 0x00200000
  #define FMC_PMEM_MEMHOLD_6 0x00400000
  #define FMC_PMEM_MEMHOLD_7 0x00800000
  #define FMC_PMEM_MEMHIZ    0xFF000000	/* MEMHIZ[7:0] bits (Common memory databus HiZ time) */
  #define FMC_PMEM_MEMHIZ_0  0x01000000
  #define FMC_PMEM_MEMHIZ_1  0x02000000
  #define FMC_PMEM_MEMHIZ_2  0x04000000
  #define FMC_PMEM_MEMHIZ_3  0x08000000
  #define FMC_PMEM_MEMHIZ_4  0x10000000
  #define FMC_PMEM_MEMHIZ_5  0x20000000
  #define FMC_PMEM_MEMHIZ_6  0x40000000
  #define FMC_PMEM_MEMHIZ_7  0x80000000
#define TOFF_FMC_R_PATT     0x008C		/* (RW) NAND Flash Attribute memory space timing register */
  #define FMC_PATT_ATTSET    0x000000FF	/* ATTSET[7:0] bits (Attribute memory setup time) */
  #define FMC_PATT_ATTSET_0  0x00000001
  #define FMC_PATT_ATTSET_1  0x00000002
  #define FMC_PATT_ATTSET_2  0x00000004
  #define FMC_PATT_ATTSET_3  0x00000008
  #define FMC_PATT_ATTSET_4  0x00000010
  #define FMC_PATT_ATTSET_5  0x00000020
  #define FMC_PATT_ATTSET_6  0x00000040
  #define FMC_PATT_ATTSET_7  0x00000080
  #define FMC_PATT_ATTWAIT   0x0000FF00	/* ATTWAIT[7:0] bits (Attribute memory wait time) */
  #define FMC_PATT_ATTWAIT_0 0x00000100
  #define FMC_PATT_ATTWAIT_1 0x00000200
  #define FMC_PATT_ATTWAIT_2 0x00000400
  #define FMC_PATT_ATTWAIT_3 0x00000800
  #define FMC_PATT_ATTWAIT_4 0x00001000
  #define FMC_PATT_ATTWAIT_5 0x00002000
  #define FMC_PATT_ATTWAIT_6 0x00004000
  #define FMC_PATT_ATTWAIT_7 0x00008000
  #define FMC_PATT_ATTHOLD   0x00FF0000	/* ATTHOLD[7:0] bits (Attribute memory hold time) */
  #define FMC_PATT_ATTHOLD_0 0x00010000
  #define FMC_PATT_ATTHOLD_1 0x00020000
  #define FMC_PATT_ATTHOLD_2 0x00040000
  #define FMC_PATT_ATTHOLD_3 0x00080000
  #define FMC_PATT_ATTHOLD_4 0x00100000
  #define FMC_PATT_ATTHOLD_5 0x00200000
  #define FMC_PATT_ATTHOLD_6 0x00400000
  #define FMC_PATT_ATTHOLD_7 0x00800000
  #define FMC_PATT_ATTHIZ    0xFF000000	/* ATTHIZ[7:0] bits (Attribute memory databus HiZ time) */
  #define FMC_PATT_ATTHIZ_0  0x01000000
  #define FMC_PATT_ATTHIZ_1  0x02000000
  #define FMC_PATT_ATTHIZ_2  0x04000000
  #define FMC_PATT_ATTHIZ_3  0x08000000
  #define FMC_PATT_ATTHIZ_4  0x10000000
  #define FMC_PATT_ATTHIZ_5  0x20000000
  #define FMC_PATT_ATTHIZ_6  0x40000000
  #define FMC_PATT_ATTHIZ_7  0x80000000
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


/*
 * QUAD SERIAL PERIPHERAL INTERFACE
 */
#define TADR_QSPI_R_BASE    (D1_AHB1PERIPH_BASE + 0x5000)
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
#define TADR_DBGMCU_BASE    0x5C001000
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
#define TOFF_DBGMCU_APB3FZ1 0x0034		/* (RW) Debug MCU APB3FZ1 freeze register */
#define TOFF_DBGMCU_APB1LFZ1 0x003C		/* (RW) Debug MCU APB1LFZ1 freeze register */
#define TOFF_DBGMCU_APB1HFZ1 0x0044		/* (RW) Debug MCU APB1LFZ1 freeze register */
#define TOFF_DBGMCU_APB2FZ1 0x004C		/* (RW) Debug MCU APB2FZ1 freeze register */
#define TOFF_DBGMCU_APB4FZ1 0x0054		/* (RW) Debug MCU APB4FZ1 freeze register */


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
  #define USB_OTG_GINTSTS_RSTDET    0x00800000	/* Reset detected interrupt */
  #define USB_OTG_GINTSTS_HPRTINT   0x01000000	/* Host port interrupt */
  #define USB_OTG_GINTSTS_HCINT     0x02000000	/* Host channels interrupt */
  #define USB_OTG_GINTSTS_PTXFE     0x04000000	/* Periodic TxFIFO empty */
  #define USB_OTG_GINTSTS_LPMINT    0x08000000	/* LPM interrupt */
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
  #define USB_OTG_GCCFG_DCDET       0x00000001	/* Data contact detection (DCD) status */
  #define USB_OTG_GCCFG_PDET        0x00000002	/* Primary detection (PD) status */
  #define USB_OTG_GCCFG_SDET        0x00000004	/* Secondary detection (SD) status */
  #define USB_OTG_GCCFG_PS2DET      0x00000008	/* DM pull-up detection status */
  #define USB_OTG_GCCFG_PWRDWN      0x00010000	/* Power down */
  #define USB_OTG_GCCFG_BCDEN       0x00020000	/* Battery charging detector (BCD) enable */
  #define USB_OTG_GCCFG_DCDEN       0x00040000	/* Data contact detection (DCD) mode enable*/
  #define USB_OTG_GCCFG_PDEN        0x00080000	/* Primary detection (PD) mode enable*/
  #define USB_OTG_GCCFG_SDEN        0x00100000	/* Secondary detection (SD) mode enable */
  #define USB_OTG_GCCFG_VBDEN       0x00200000	/* USB VBUS Detection Enable */
#define TOFF_USBO_CID       0x003C		/* (RW) User ID Register */
  #define USB_OTG_CID_PRODUCT_ID    0xFFFFFFFF	/* Product ID field */
#define TOFF_USBO_GSNPSID   0x0040		/* (R)  USB_OTG core ID */
#define TOFF_USBO_GHWCFG1   0x0044		/* (R)  User HW config1 */
#define TOFF_USBO_GHWCFG2   0x0048		/* (R)  User HW config2 */
#define TOFF_USBO_GHWCFG3   0x004C		/* (R)  User HW config3 */
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

/*
 *  DFSDM MODULE REGISTERS
 */
#define TADR_DFSDM1_BASE            (D2_APB2PERIPH_BASE + 0x7000)
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


#endif  /* _STM32H7XX_H_ */

