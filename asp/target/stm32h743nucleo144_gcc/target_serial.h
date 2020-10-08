/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2020 by TOPPERS PROJECT Educational Working Group.
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
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
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: target_serial.h 698 2020-02-23 16:36:50Z roi $
 */

/*
 *    シリアルI/Oデバイス（SIO）ドライバ
 */

#ifndef TOPPERS_TARGET_SERIAL_H
#define TOPPERS_TARGET_SERIAL_H

/*
 *  チップ依存モジュール（stm32h743-nucleo144用）
 */

/*
 *  SIO用GPIOの設定
 */
#define TADR_U1T_GPIO_BASE TADR_GPIOD_BASE
#define TADR_U1R_GPIO_BASE TADR_GPIOD_BASE
#define TADR_U2T_GPIO_BASE TADR_GPIOB_BASE
#define TADR_U2R_GPIO_BASE TADR_GPIOB_BASE
#define TOFF_U1_APBNER     TOFF_RCC_APB1LENR
#define TOFF_U2_APBNER     TOFF_RCC_APB4ENR
#define TOFF_U1_APBRSTR    TOFF_RCC_APB1LRSTR
#define TOFF_U2_APBRSTR    TOFF_RCC_APB4RSTR
#define GPIO_U1_AF         0x07
#define GPIO_U2_AF         0x08
#define ENABLE_U1_PORT     RCC_APB1LENR_USART3EN
#define ENABLE_U2_PORT     RCC_APB4ENR_LPUART1EN
#define ENABLE_U1T_GPIO    RCC_AHB4ENR_GPIODEN
#define ENABLE_U1R_GPIO    RCC_AHB4ENR_GPIODEN
#define ENABLE_U2T_GPIO    RCC_AHB4ENR_GPIOBEN
#define ENABLE_U2R_GPIO    RCC_AHB4ENR_GPIOBEN
#define RESET_U1_PORT      RCC_APB1LRSTR_USART3RST
#define RESET_U2_PORT      RCC_APB4RSTR_LPUART1RST
#define TX1_PINPOS         8
#define RX1_PINPOS         9
#define TX2_PINPOS         6
#define RX2_PINPOS         7


/*
 *  SIOのベースアドレス
 */
#define USART1_BASE        TADR_USART3_BASE
#define USART2_BASE        TADR_LPUART1_BASE

/*
 *  CLOCKソース指定
 */
#define TOFF_U1_CLOCK      TOFF_RCC_D2CCIP2R
#define TOFF_U2_CLOCK      TOFF_RCC_D3CCIPR
#define U1_CLOCK_SHIFT     0
#define U2_CLOCK_SHIFT     0

/*
 *  シリアルI/Oポート数の定義
 */
#ifndef TNUM_SIOP
#define TNUM_SIOP       2       /* サポートするシリアルI/Oポートの数 */
#endif

/*
 *  SIOの割込みハンドラのベクタ番号
 */
#define INHNO_SIO1      IRQ_VECTOR_USART3
#define INTNO_SIO1      IRQ_VECTOR_USART3
#define INHNO_SIO2      IRQ_VECTOR_LPUART1
#define INTNO_SIO2      IRQ_VECTOR_LPUART1

#define INTPRI_SIO       -3        /* 割込み優先度 */
#define INTATR_SIO       0         /* 割込み属性 */


#include "arm_m_gcc/stm32h7xx/chip_serial.h"

#endif /* TOPPERS_TARGET_SERIAL_H */
