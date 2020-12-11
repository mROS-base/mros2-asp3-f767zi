/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2017-2017 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: target_serial.h 698 2017-02-11 16:54:58Z roi $
 */

/*
 *    シリアルI/Oデバイス（SIO）ドライバ
 */

#ifndef TOPPERS_TARGET_SERIAL_H
#define TOPPERS_TARGET_SERIAL_H

/*
 *  チップ依存モジュール（stm32f769-discovery用）
 */

/*
 *  SIO用GPIOの設定
 */
#define TADR_U1T_GPIO_BASE TADR_GPIOA_BASE
#define TADR_U1R_GPIO_BASE TADR_GPIOA_BASE
#define TADR_U2T_GPIO_BASE TADR_GPIOC_BASE
#define TADR_U2R_GPIO_BASE TADR_GPIOC_BASE
#define TOFF_U1_APBNER     TOFF_RCC_APB2ENR
#define TOFF_U2_APBNER     TOFF_RCC_APB2ENR
#define TOFF_U1_APBRSTR    TOFF_RCC_APB2RSTR
#define TOFF_U2_APBRSTR    TOFF_RCC_APB2RSTR
#define GPIO_U1_AF         0x07
#define GPIO_U2_AF         0x08
#define ENABLE_U1_PORT     RCC_APB2ENR_USART1EN
#define ENABLE_U2_PORT     RCC_APB2ENR_USART6EN
#define ENABLE_U1T_GPIO    RCC_AHB1ENR_GPIOAEN
#define ENABLE_U1R_GPIO    RCC_AHB1ENR_GPIOAEN
#define ENABLE_U2T_GPIO    RCC_AHB1ENR_GPIOCEN
#define ENABLE_U2R_GPIO    RCC_AHB1ENR_GPIOCEN
#define RESET_U1_PORT      RCC_APB2RSTR_USART1RST
#define RESET_U2_PORT      RCC_APB2RSTR_USART6RST
#define TX1_PINPOS         9
#define RX1_PINPOS         10
#define TX2_PINPOS         6
#define RX2_PINPOS         7

/*
 *  SIOのベースアドレス
 */
#define USART1_BASE        TADR_USART1_BASE
#define USART2_BASE        TADR_USART6_BASE

/*
 *  CLOCKソース指定
 */
#define U1_CLOCK_SHIFT     0
#define U2_CLOCK_SHIFT     10

/*
 *  シリアルI/Oポート数の定義
 */
#define TNUM_SIOP       2       /* サポートするシリアルI/Oポートの数 */

/*
 *  SIOの割込みハンドラのベクタ番号
 */
#define INHNO_SIO1      IRQ_VECTOR_USART1
#define INTNO_SIO1      IRQ_VECTOR_USART1
#define INHNO_SIO2      IRQ_VECTOR_USART6
#define INTNO_SIO2      IRQ_VECTOR_USART6

#define INTPRI_SIO       -3        /* 割込み優先度 */
#define INTATR_SIO       0         /* 割込み属性 */


#include "arm_m_gcc/stm32f7xx/chip_serial.h"

#endif /* TOPPERS_TARGET_SERIAL_H */
