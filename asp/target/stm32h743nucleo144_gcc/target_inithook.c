/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2019 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: target_inithook.c 698 2019-08-13 20:23:39Z roi $
 */

#include <math.h>
#include <sil.h>
#include "target_syssvc.h"

#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

/*
 *  初期化プログラム（stm32h743-nucleo144用）
 */

/*
 *  TIMEOUT VALUES
 */
#define CLOCKSWITCH_TIMEOUT_VALUE    (5000*1000)	/* 5 s    */ 
#define HSE_TIMEOUT_VALUE            (5000*1000)	/* Time out for HSE start up, in ms */
#define RCC_LSE_TIMEOUT_VALUE        (5000*1000)
#define PLL_TIMEOUT_VALUE            (2*1000)		/* 2 ms */
#define PLLSAI_TIMEOUT_VALUE         (100*1000)		/* Timeout value fixed to 100 ms  */
#define RCC_DBP_TIMEOUT_VALUE        (100*1000)		/* Timeout value fixed to 100 ms  */
#define HSI48_TIMEOUT_VALUE          (2*1000)		/* 2 ms */
#define PWR_OVERDRIVE_TIMEOUT_VALUE  (1000*1000)
#define PWR_FLAG_SETTING_DELAY_US    1000

/*
 *  RCCセットアップ値
 */
#define REQUEST_SYSCLOCK             RCC_CFGR_SW_PLL1
#define REQUEST_FLASH_LATENCY        FLASH_ACR_LATENCY_4WS
#define REQUEST_PWR_SUPPLY           PWR_CR3_LDOEN
#define REQUEST_SYSCLK_DIV           RCC_D1CFGR_D1CPRE_DIV1
#define REQUEST_HCLK_DIV             RCC_D1CFGR_HPRE_DIV2
#define REQUEST_APB1_DIV             RCC_D2CFGR_D2PPRE1_DIV2
#define REQUEST_APB2_DIV             RCC_D2CFGR_D2PPRE2_DIV2
#define REQUEST_APB3_DIV             RCC_D1CFGR_D1PPRE_DIV2
#define REQUEST_APB4_DIV             RCC_D3CFGR_D3PPRE_DIV2

#define REQUEST_PLL_SOURCE           RCC_PLLCKSELR_PLLSRC_HSE
#define REQUEST_PLLM                 4
#define REQUEST_PLLN                 400
#define REQUEST_PLLP                 2
#define REQUEST_PLLR                 2
#define REQUEST_PLLQ                 4
#define REQUEST_PLLFRACN             0
#define REQUEST_PLL1VCOWIDE          0x00000000
#define REQUEST_PLL1VCIRANGE         RCC_PLLCFGR_PLL1RGE_2

#define REQUEST_PLL3_PLL3M           8
#define REQUEST_PLL3_PLL3N           336
#define REQUEST_PLL3_PLL3FRACN       0
#define REQUEST_PLL3_PLL3P           2
#define REQUEST_PLL3_PLL3R           2
#define REQUEST_PLL3_PLL3Q           7
#ifdef USE_USB
#define REQUEST_USBCLOCK             RCC_USBCLKSOURCE_HSI48
#endif

#define CFGR_SWS_SHIFT               3
#define D1CFGR_HPRE_SHIFT            0
#define D1CFGR_D1CPRE_SHIFT          8
#define D2CFGR_D2PPRE1_SHIFT         4
#define D2CFGR_D2PPRE2_SHIFT         8

#define REQUEST_VOLTAGE_SCALE        (PWR_D3CR_VOS_1 | PWR_D3CR_VOS_0)
#define PWR_SUPPLY_CONFIG_MASK       (PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS)

/*
 *  USBクロック設定
 */
#define RCC_USBCLKSOURCE_PLL         RCC_D2CCIP2R_USBSEL_0
#define RCC_USBCLKSOURCE_PLL3        RCC_D2CCIP2R_USBSEL_1
#define RCC_USBCLKSOURCE_HSI48       RCC_D2CCIP2R_USBSEL

/*
 *  CORTEX MPU領域許可禁止
 */
#define MPU_REGION_ENABLE            0x01
#define MPU_REGION_DISABLE           0x00

/*
 *  CORTEX MPU インストラクションアクセス許可禁止
 */
#define MPU_INSTRUCTION_ACCESS_ENABLE   0x00
#define MPU_INSTRUCTION_ACCESS_DISABLE  0x01

/*
 *  CORTEX MPU インストラクションアクセスキャッシュ設定
 */
#define MPU_ACCESS_CACHEABLE         0x01
#define MPU_ACCESS_NOT_CACHEABLE     0x00

/*
 *  CORTEX MPU インストラクションアクセスバッファ設定
 */
#define MPU_ACCESS_BUFFERABLE        0x01
#define MPU_ACCESS_NOT_BUFFERABLE    0x00

/*
 *  CORTEX MPU インストラクションアクセス共有設定
 */
#define MPU_ACCESS_SHAREABLE         0x01
#define MPU_ACCESS_NOT_SHAREABLE     0x00

/*
 *  キャッシュサイズID レジスタマクロ
 */
#define CCSIDR_WAYS(x)         (((x) & SCB_CCSIDR_ASSOCIATIVITY_Msk) >> SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_SETS(x)         (((x) & SCB_CCSIDR_NUMSETS_Msk      ) >> SCB_CCSIDR_NUMSETS_Pos      )
#define CCSIDR_LSSHIFT(x)      (((x) & SCB_CCSIDR_LINESIZE_Msk     ) /*>> SCB_CCSIDR_LINESIZE_Pos*/ )

#define CR_RESET_VALUE         (RCC_CR_PLL3ON   | RCC_CR_PLL2ON | RCC_CR_PLL1ON  | \
                                RCC_CR_CSSHSEON | RCC_CR_HSEON  | RCC_CR_HSI48ON | \
                                RCC_CR_CSIKERON | RCC_CR_CSION)

#define get_sysclk_source()    (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS)
#define get_pll1n_divider()    (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1DIVR)) & RCC_PLL1DIVR_N1)
#define get_pll2n_divider()    (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2DIVR)) & RCC_PLL2DIVR_N2)
#define get_pll3n_divider()    (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3DIVR)) & RCC_PLL3DIVR_N3)
#define get_hsi_divider()      ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSIDIV) >> 3)

/*
 *  GPIOアウトプット設定パラメータ
 */
#define GPIO_OTYPE_PP       0x0
#define GPIO_OTYPE_OD       0x1

/*
 *  GPIOプルアップダウンパラメータ
 */
#define GPIO_NOPULL         0x00000000	/* No Pull-up or Pull-down activation  */
#define GPIO_PULLUP         0x00000001	/* Pull-up activation                  */
#define GPIO_PULLDOWN       0x00000002	/* Pull-down activation                */

/*
 *  GPIOモードパラメータ
 */
#define GPIO_MODE_INPUT     0x00000000	/* Input Floating Mode */
#define GPIO_MODE_OUTPUT    0x00000001	/* Output Push Pull Mode */
#define GPIO_MODE_AF        0x00000002	/* Alternate Function Push Pull Mode */
#define GPIO_MODE_ANALOG    0x00000003	/* Analog Mode  */

/*
 *  GPIOアウトプット最大周波数パラメータ
 */
#define GPIO_SPEED_LOW      0x00000000	/* Low speed     */
#define GPIO_SPEED_MEDIUM   0x00000001	/* Medium speed  */
#define GPIO_SPEED_FAST     0x00000002	/* Fast speed    */
#define GPIO_SPEED_HIGH     0x00000003	/* High speed    */


#define LEDR_POSITION       14



ER sysclock_config(int mode);

#ifndef TOPPERS_RAM_EXEC
/*
 *  メモリプロテクションユニットの設定
 */
static void
mpu_config(void)
{
	/* Disable the MPU */
	sil_andw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_SHCSR), SCB_SHCSR_MEMFAULTENA_Msk);
	sil_andw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_CTRL), MPU_CTRL_ENABLE_Msk);

	/* Set the Region number */
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RNR), MPU_REGION_NUMBER0);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x30040000);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RASR),
				((MPU_INSTRUCTION_ACCESS_ENABLE << MPU_RASR_XN_Pos)   |
                 (MPU_REGION_FULL_ACCESS        << MPU_RASR_AP_Pos)   |
                 (MPU_TEX_LEVEL0                << MPU_RASR_TEX_Pos)  |
                 (MPU_ACCESS_NOT_SHAREABLE      << MPU_RASR_S_Pos)    |
                 (MPU_ACCESS_NOT_CACHEABLE      << MPU_RASR_C_Pos)    |
                 (MPU_ACCESS_BUFFERABLE         << MPU_RASR_B_Pos)    |
                 (0x00                          << MPU_RASR_SRD_Pos)  |
                 (MPU_REGION_SIZE_32KB          << MPU_RASR_SIZE_Pos) |
                 (MPU_REGION_ENABLE             << MPU_RASR_ENABLE_Pos)));

	/* Enable the MPU */
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_CTRL), (MPU_PRIVILEGED_DEFAULT | MPU_CTRL_ENABLE_Msk));
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_SHCSR), SCB_SHCSR_MEMFAULTENA_Msk);
}

/*
 *  システムクロック設定エラー
 */
void
sysemclock_error(void)
{
	volatile uint32_t temp = 0x00;
	uint32_t n = LEDR_POSITION;

	/*
	 *  GPIO LEDクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), RCC_AHB4ENR_GPIOBEN);
	temp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR));
	(void)(temp);

	/*
	 * LED GPIO設定
	 */
	sil_modw_mem((uint32_t *)(TADR_GPIOB_BASE+TOFF_GPIO_MODER), (3 << (n * 2)), (GPIO_MODE_OUTPUT << (n * 2)));
	sil_modw_mem((uint32_t *)(TADR_GPIOB_BASE+TOFF_GPIO_OSPEEDR), (3 << (n * 2)), (GPIO_SPEED_HIGH << (n * 2)));
	sil_modw_mem((uint32_t *)(TADR_GPIOB_BASE+TOFF_GPIO_OTYPER), (1 << n), (GPIO_OTYPE_PP<<n));
	sil_modw_mem((uint32_t *)(TADR_GPIOB_BASE+TOFF_GPIO_PUPDR), (3 << (n * 2)), (GPIO_PULLUP << (n * 2)));
	while(1){
		/* LED ON */
		sil_wrw_mem((uint32_t *)(TADR_GPIOB_BASE+TOFF_GPIO_BSRR), (1<<n));
		sil_dly_nse(200*1000*1000);
		/* LED OFF */
		sil_wrw_mem((uint32_t *)(TADR_GPIOB_BASE+TOFF_GPIO_BSRR), (1<<n)<<16);
		sil_dly_nse(200*1000*1000);
	}
}

/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void
hardware_init_hook(void)
{
	uint32_t ccsidr, sets, ways;

	/*
	 *  HSIを有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);

	/*
	 *  CFGRレジスタを初期化
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00000000);

	/*
	 *  HSI以外のクロックを停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), CR_RESET_VALUE);

	/*
	 *  他のRCCレジスタのリセット
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_D1CFGR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_D2CFGR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_D3CFGR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCKSELR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1DIVR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1FRACR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2DIVR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2FRACR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3DIVR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3FRACR), 0x00000000);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	/*
	 *  RCC割込みを禁止
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIER), 0x00000000);

	/* Change  the switch matrix read issuing capability to 1 for the AXI SRAM target (Target 7) */
	if((sil_rew_mem((uint32_t *)(TADR_DBGMCU_BASE+TOFF_DBGMCU_IDCODE)) & 0xFFFF0000U) < 0x20000000U){
		/* if stm32h7 revY*/
		/* Change  the switch matrix read issuing capability to 1 for the AXI SRAM target (Target 7) */
		sil_wrw_mem((uint32_t *)0x51008108, 0x000000001);
	}

	/*
	 *  メモリプロテクションユニットの初期化
	 */
	mpu_config();

	/*
	 *  I-Cache有効化
	 */
	asm volatile ("dsb 0xF":::"memory");
	asm volatile ("isb 0xF":::"memory");
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_ICIALLU), 0);	/* invalidate I-Cache */
	asm volatile ("dsb 0xF":::"memory");
	asm volatile ("isb 0xF":::"memory");
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCR), SCB_CCR_IC_Msk);	/* enable I-Cache */
	asm volatile ("dsb 0xF":::"memory");
	asm volatile ("isb 0xF":::"memory");

	/*
	 *  D-Cache有効化
	 */
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CSSELR), ((0 << 1) | 0));	/* Level 1 data cache */
	ccsidr  = sil_rew_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCSIDR));
    sets    = (uint32_t)(CCSIDR_SETS(ccsidr));
	asm volatile ("dsb 0xF":::"memory");

	do{                                   // invalidate D-Cache
		ways = (uint32_t)(CCSIDR_WAYS(ccsidr));
		do{
			sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_DCISW),
				(((sets << SCB_DCISW_SET_Pos) & SCB_DCISW_SET_Msk) | \
				((ways << SCB_DCISW_WAY_Pos) & SCB_DCISW_WAY_Msk)));
        }while(ways--);
    }while(sets--);

	asm volatile ("dsb 0xF":::"memory");

	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCR), SCB_CCR_DC_Msk);	/* enable D-Cache */
	asm volatile ("dsb 0xF":::"memory");
	asm volatile ("isb 0xF":::"memory");

	/*
	 *  システムクロックを 400MHzに設定
	 */
	if(sysclock_config(0) != E_OK)
		sysemclock_error();
}
#endif

/*
 *  FLASH-ROMのLatencyを設定する
 */
static int
Set_Flash_latency(uint32_t latency)
{
	sil_modw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, latency);

	/*
	 *  Latencyの設定を判定
	 */
	if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != latency)
		return -1;
	else
		return 0;
}

/*
 *  システムクロック設定
 *  設定値：
 *            System Clock source            = PLL (HSE BYPASS)
 *            SYSCLK(Hz)                     = 400000000 (CPU Clock)
 *            HCLK(Hz)                       = 200000000 (AXI and AHBs Clock)
 *            AHB Prescaler                  = 2
 *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
 *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
 *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
 *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 4
 *            PLL_N                          = 400
 *            PLL_P                          = 2
 *            PLL_Q                          = 4
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Flash Latency(WS)              = 4
 */
ER
sysclock_config(int mode)
{
	uint32_t rccbase = TADR_RCC_BASE;
	uint32_t tick = 0, tmp;

	/*
	 *  パワーサプライ コンフィギュレーションアップデートチェック
	 */
	if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR3)) & PWR_CR3_SCUEN) == 0){
		if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR3)) & PWR_SUPPLY_CONFIG_MASK) != REQUEST_PWR_SUPPLY){
			/* ロック状態ならば終了 */
			return E_SYS;
		}
	}

	/*
	 *  パワーサプライ コンフィギュレーション
	 */
	sil_modw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR3), PWR_SUPPLY_CONFIG_MASK, REQUEST_PWR_SUPPLY);

	/*
	 *  VOLTAGEレベルフラグオンまで待ち
	 */
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR1)) & PWR_CSR1_ACTVOSRDY) == 0){
		if(tick++ > PWR_FLAG_SETTING_DELAY_US){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  最大クロック可能レベル用の VOLTAGE SCALE設定を行う
	 */
	sil_andw_mem((uint32_t *)(TADR_SYSCFG_BASE+TOFF_SYSCFG_PWRCR), SYSCFG_PWRCR_ODEN);
	tmp  = sil_rew_mem((uint32_t *)(TADR_SYSCFG_BASE+TOFF_SYSCFG_PWRCR));

	sil_modw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_D3CR), PWR_D3CR_VOS, REQUEST_VOLTAGE_SCALE);
	tmp = sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_D3CR));
	(void)(tmp);

	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_D3CR)) & PWR_D3CR_VOSRDY) == 0){}

	/*
	 *  HSE設定
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_HSEBYP);
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_HSEON);

	/*
	 *  HSEレディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_HSERDY) == 0){
		if(tick++ > HSE_TIMEOUT_VALUE)
			return E_TMOUT;
		sil_dly_nse(1000);
	}

#if REQUEST_USBCLOCK == RCC_USBCLKSOURCE_HSI48
	/*
	 *  HSI48クロックを起動
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_HSI48ON);

	/*
	 *  HSI48レディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_HSI48RDY) == 0){
		if(tick++ > HSI48_TIMEOUT_VALUE)
			return -2;
		sil_dly_nse(1000);
	}
#endif	/* USE_USB */

	/*
	 *  PLL設定
	 */
    /*
	 *  PLLがシステムクロック設定済みの場合、エラー
	 */
	if(get_sysclk_source() == RCC_CFGR_SWS_PLL1)
		return E_SYS;

	/*
	 *  PLL DISABLE
	 */
	sil_andw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_PLL1ON);

	/*
	 *  PLL NOT-READY待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_PLL1RDY) != 0){
		if( tick++ > PLL_TIMEOUT_VALUE)
			return E_TMOUT;
		sil_dly_nse(1000);
	}

	/*
	 *  PLLM,N,P,R,Q設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCKSELR),
				(RCC_PLLCKSELR_PLLSRC | RCC_PLLCKSELR_DIVM1), (REQUEST_PLL_SOURCE | (REQUEST_PLLM<<4)));
	sil_wrw_mem((uint32_t *)(rccbase+TOFF_RCC_PLL1DIVR),
				((REQUEST_PLLN-1) | ((REQUEST_PLLP-1) << 9) | ((REQUEST_PLLR-1) << 24) | ((REQUEST_PLLQ-1) << 16)));

	/*
	 *  PLLFRACN無効化
	 */
	sil_andw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL1FRACEN);

	/* Configure PLL  PLL1FRACN */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLL1FRACR), RCC_PLL1FRACR_FRACN1, REQUEST_PLLFRACN);

	/* Select PLL1 input reference frequency range: VCI */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL1RGE, REQUEST_PLL1VCIRANGE);

	/* Select PLL1 output frequency range : VCO */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL1VCOSEL, REQUEST_PLL1VCOWIDE);

	/*
	 *  PLL1Pクロック分周有効化
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_DIVP1EN);

	/*
	 *  PLL1Qクロック分周有効化
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_DIVQ1EN);

	/*
	 *  PLL1Rクロック分周有効化
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_DIVR1EN);

	/*
	 *  PLL1FRACN有効化
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL1FRACEN);

	/*
	 *  PLLクロック有効化
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_PLL1ON);

	/*
	 *  PLLレディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_PLL1RDY) == 0){
		if( tick++ > PLL_TIMEOUT_VALUE)
			return E_TMOUT;
		sil_dly_nse(1000);
	}

#ifdef REQUEST_USBCLOCK
#if REQUEST_USBCLOCK == RCC_USBCLKSOURCE_PLL3
	/*
	 *  USBクロック設定
	 *  PLL3停止
	 */
	sil_andw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_PLL3ON);
	tick = 0;
	while((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_PLL3RDY) != 0){
		if(tick++ > PLL_TIMEOUT_VALUE)
			return -2;
		sil_dly_nse(1000);
	}

    /*
	 *  PLL3のコンフィギュレーション設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCKSELR), RCC_PLLCKSELR_DIVM3, (REQUEST_PLL3_PLL3M << 20));
	sil_wrw_mem((uint32_t *)(rccbase+TOFF_RCC_PLL3DIVR), ((REQUEST_PLL3_PLL3N-1) & RCC_PLL3DIVR_N3) | \
						(((REQUEST_PLL3_PLL3P-1) << 9) & RCC_PLL3DIVR_P3) | (((REQUEST_PLL3_PLL3Q-1) << 16) & RCC_PLL3DIVR_Q3) | \
						(((REQUEST_PLL3_PLL3R-1) << 24) & RCC_PLL3DIVR_R3));

	/*
	 *  PLL3 VCI設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL3RGE, 2<<10);

    /*
	 *  PLL3 VCO設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL3VCOSEL, 0<<9);

	/*
	 *  PLL3FRACN停止
	 */
	sil_andw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL3FRACEN);

	/*
	 *  PLL3クロック Fractional Part Of The Multiplication Factor設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_PLL3FRACR), RCC_PLL3FRACR_FRACN3, REQUEST_PLL3_PLL3FRACN);

	/*
	 *  PLL3FRACN再開
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLL3FRACEN);

	/*
	 *  PLL3-Qクロック出力
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_DIVQ3EN);

	/*
	 *  PLL3有効化
	 */
	sil_orw_mem((uint32_t *)(rccbase+TOFF_RCC_CR), RCC_CR_PLL3ON);
	tick = 0;
	while((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_PLL3RDY) == 0){
		if(tick++ > PLL_TIMEOUT_VALUE)
			return -2;
		sil_dly_nse(1000);
	}
#endif	/* RCC_USBCLKSOURCE_PLL3 */

	/*
	 *  USB設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D2CCIP2R), RCC_D2CCIP2R_USBSEL, REQUEST_USBCLOCK);

	/*
	 *  USBV3.3レギュレータ
	 */
	sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR3), PWR_CR3_USBREGEN);

	/*
	 *  レディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR3)) & PWR_CR3_USB33RDY) == 0){
		if(tick++ > (PWR_FLAG_SETTING_DELAY_US*50))
			return -2;
		sil_dly_nse(1000);
	}
#endif	/* USE_USB */

	/*
	 *  FLASHアクセスウェイト設定(現在値より遅い場合)
	 */
	if(REQUEST_FLASH_LATENCY > (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		if(Set_Flash_latency(FLASH_ACR_LATENCY) != 0)
			return E_SYS;
	}

	/*
	 *  D1PCLK1分周設定
	 */
    if(REQUEST_APB3_DIV > (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR)) & RCC_D1CFGR_D1PPRE))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR), RCC_D1CFGR_D1PPRE, REQUEST_APB3_DIV);

	/*
	 *  PCLK1分周設定
	 */
	if(REQUEST_APB1_DIV > (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR)) & RCC_D2CFGR_D2PPRE1))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR), RCC_D2CFGR_D2PPRE1, REQUEST_APB1_DIV);

	/*
	 *  PCLK2分周設定
	 */
	if(REQUEST_APB2_DIV > (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR)) & RCC_D2CFGR_D2PPRE2))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR), RCC_D2CFGR_D2PPRE2, REQUEST_APB2_DIV);

	/*
	 *  D3PCLK1分周設定
	 */
	if(REQUEST_APB4_DIV > (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D3CFGR)) & RCC_D3CFGR_D3PPRE))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D3CFGR), RCC_D3CFGR_D3PPRE, REQUEST_APB4_DIV);

	/*
	 *  HCLK分周設定
	 */
	if(REQUEST_HCLK_DIV > (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR)) & RCC_D1CFGR_HPRE))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR), RCC_D1CFGR_HPRE, REQUEST_HCLK_DIV);

	/*
	 *  SYSCLK分周設定
	 */
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR), RCC_D1CFGR_D1CPRE, REQUEST_SYSCLK_DIV);

	/* HSE is selected as System Clock Source */
	/* PLL is selected as System Clock Source */
	/* Check the PLL ready flag */
	if((sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_CR)) & RCC_CR_PLL1RDY) == 0)
		return -1;
	sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_CFGR), RCC_CFGR_SW, REQUEST_SYSCLOCK);

	/*
	 *  システムクロック設定反映待ち
	 */
	tick = 0;
	while(get_sysclk_source() != (REQUEST_SYSCLOCK << CFGR_SWS_SHIFT)){
		if( tick++ > CLOCKSWITCH_TIMEOUT_VALUE){
			return E_SYS;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  HCLK分周設定
	 */
	if(REQUEST_HCLK_DIV < (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR)) & RCC_D1CFGR_HPRE))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR), RCC_D1CFGR_HPRE, REQUEST_HCLK_DIV);

	/*
	 *  FLASHアクセスウェイト設定(現在値より速い場合)
	 */
	if(REQUEST_FLASH_LATENCY < (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		if(Set_Flash_latency(FLASH_ACR_LATENCY) != 0)
			return -3;
	}

	/*
	 *  D1PCLK1分周設定
	 */
	if(REQUEST_APB3_DIV < (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR)) & RCC_D1CFGR_D1PPRE))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D1CFGR), RCC_D1CFGR_D1PPRE, REQUEST_APB3_DIV);

	/*
	 *  PCLK1分周設定
	 */
	if(REQUEST_APB1_DIV < (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR)) & RCC_D2CFGR_D2PPRE1))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR), RCC_D2CFGR_D2PPRE1, REQUEST_APB1_DIV);

	/*
	 *  PCLK2分周設定
	 */
	if(REQUEST_APB2_DIV < (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR)) & RCC_D2CFGR_D2PPRE2))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D2CFGR), RCC_D2CFGR_D2PPRE2, REQUEST_APB2_DIV);

	/*
	 *  D3PCLK1分周設定
	 */
	if(REQUEST_APB4_DIV < (sil_rew_mem((uint32_t *)(rccbase+TOFF_RCC_D3CFGR)) & RCC_D3CFGR_D3PPRE))
		sil_modw_mem((uint32_t *)(rccbase+TOFF_RCC_D3CFGR), RCC_D3CFGR_D3PPRE, REQUEST_APB4_DIV);
	return E_OK;
}

/*
 *  PLL2クロック取得
 *  0-P, 1-Q, 2-R
 *  PLL_VCO = (HSE_VALUE or HSI_VALUE or CSI_VALUE/ PLL2M) * PLL2N
 *  PLL2xCLK = PLL2_VCO / PLL2x
 */
void
RCC_GetPLL2ClockFreq(uint32_t *PLL2_Clocks)
{
	uint32_t  pllsource, pll2m,  pll2fracen, hsivalue, pll2divr;
	float_t fracn2, pll2vco;
	uint32_t pllckselr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCKSELR));

	pllsource = pllckselr & RCC_PLLCKSELR_PLLSRC;
	pll2m = (pllckselr & RCC_PLLCKSELR_DIVM2)>> 12;
	pll2fracen = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR)) & RCC_PLLCFGR_PLL2FRACEN;
	fracn2 =(float_t)(uint32_t)(pll2fracen * ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2FRACR)) & RCC_PLL2FRACR_FRACN2) >> 3));

	if(pll2m != 0U){
		switch (pllsource){
		case RCC_PLLCKSELR_PLLSRC_HSI:	/* HSI used as PLL clock source */
			if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSIDIVF) != 0){
				hsivalue = HSI_VALUE >> get_hsi_divider();
				pll2vco = ((float_t)hsivalue / (float_t)pll2m) * ((float_t)get_pll2n_divider() + (fracn2/8192.0) + 1.0);
			}
			else
				pll2vco = ((float_t)HSI_VALUE / (float_t)pll2m) * ((float_t)get_pll2n_divider() + (fracn2/8192.0) + 1.0);
			break;
		case RCC_PLLCKSELR_PLLSRC_HSE:	/* HSE used as PLL clock source */
			pll2vco = ((float_t)HSE_VALUE / (float_t)pll2m) * ((float_t)get_pll2n_divider() + (fracn2/8192.0) + 1.0);
			break;
		default:
			pll2vco = ((float_t)CSI_VALUE / (float_t)pll2m) * ((float_t)get_pll2n_divider() + (fracn2/8192.0) + 1.0);
			break;
		}
		pll2divr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2DIVR));
		PLL2_Clocks[0] = (uint32_t)(float_t)(pll2vco/((float_t)(uint32_t)((pll2divr & RCC_PLL2DIVR_P2) >>9)  + 1.0));
		PLL2_Clocks[1] = (uint32_t)(float_t)(pll2vco/((float_t)(uint32_t)((pll2divr & RCC_PLL2DIVR_Q2) >>16) + 1.0));
		PLL2_Clocks[2] = (uint32_t)(float_t)(pll2vco/((float_t)(uint32_t)((pll2divr & RCC_PLL2DIVR_R2) >>24) + 1.0));
	}
	else{
		PLL2_Clocks[0] = 0;
		PLL2_Clocks[1] = 0;
		PLL2_Clocks[2] = 0;
	}
}

/*
 *  PLL3クロック取得
 *  0-P, 1-Q, 2-R
 *  PLL3_VCO = (HSE_VALUE or HSI_VALUE or CSI_VALUE/ PLL3M) * PLL3N
 *  PLL3xCLK = PLL3_VCO / PLLxR
 */
void
RCC_GetPLL3ClockFreq(uint32_t *PLL3_Clocks)
{
	uint32_t pllsource, pll3m, pll3fracen, hsivalue, pll3divr;
	float_t fracn3, pll3vco;
	uint32_t pllckselr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCKSELR));

	pllsource = pllckselr & RCC_PLLCKSELR_PLLSRC;
	pll3m = (pllckselr & RCC_PLLCKSELR_DIVM3) >> 20;
	pll3fracen = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR)) & RCC_PLLCFGR_PLL3FRACEN;
	fracn3 = (float_t)(uint32_t)(pll3fracen* ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3FRACR)) & RCC_PLL3FRACR_FRACN3) >> 3));

	if(pll3m != 0){
		switch (pllsource){
		case RCC_PLLCKSELR_PLLSRC_HSI:	/* HSI used as PLL clock source */
			if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSIDIVF) != 0){
				hsivalue = HSI_VALUE >> get_hsi_divider();
				pll3vco = ((float_t)hsivalue / (float_t)pll3m) * ((float_t)get_pll3n_divider() + (fracn3/8192.0) + 1.0);
			}
			else
				pll3vco = ((float_t)HSI_VALUE / (float_t)pll3m) * ((float_t)get_pll3n_divider() + (fracn3/8192.0) + 1.0);
			break;
		case RCC_PLLCKSELR_PLLSRC_HSE:	/* HSE used as PLL clock source */
			pll3vco = ((float_t)HSE_VALUE / (float_t)pll3m) * ((float_t)get_pll3n_divider() + (fracn3/8192.0) + 1.0);
			break;
		default:
			pll3vco = ((float_t)CSI_VALUE / (float_t)pll3m) * ((float_t)get_pll3n_divider() + (fracn3/8192.0) + 1.0);
			break;
		}
		pll3divr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3DIVR));
		PLL3_Clocks[0] = (uint32_t)(float_t)(pll3vco/((float_t)(uint32_t)((pll3divr & RCC_PLL3DIVR_P3) >>9)  + 1.0));
		PLL3_Clocks[1] = (uint32_t)(float_t)(pll3vco/((float_t)(uint32_t)((pll3divr & RCC_PLL3DIVR_Q3) >>16) + 1.0));
		PLL3_Clocks[2] = (uint32_t)(float_t)(pll3vco/((float_t)(uint32_t)((pll3divr & RCC_PLL3DIVR_R3) >>24) + 1.0));
	}
	else{
		PLL3_Clocks[0] = 0;
		PLL3_Clocks[1] = 0;
		PLL3_Clocks[2] = 0;
	}
}

