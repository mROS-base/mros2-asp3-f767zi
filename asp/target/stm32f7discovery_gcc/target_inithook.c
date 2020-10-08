/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2019 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
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
 *  @(#) $Id: target_inithook.c 698 2019-07-05 17:50:27Z roi $
 */

#include <sil.h>
#include "target_syssvc.h"

/*
 *  初期化プログラム（stm32f7-discovery用）
 */

#define PLL_M      (HSE_VALUE / 1000000)/* Possible value 0 and 63 */
#define PLL_N      432
#define PLL_Q      9

/*
 *  TIMEOUT VALUES
 */
#define CLOCKSWITCH_TIMEOUT_VALUE      (5000*1000)		/* 5秒 */
#define HSE_TIMEOUT_VALUE              (5000*1000)		/* 5秒 */
#define PLL_TIMEOUT_VALUE              (100*1000)		/* 100 ms */
#define PLLSAI_TIMEOUT_VALUE           (100*1000)		/* 100 ms  */
#define PWR_OVERDRIVE_TIMEOUT_VALUE    (1000*1000)		/* 1秒 */

/*
 *  RCC_PLLP_Clock_Divider PLLP Clock Divider
 */
#define RCC_PLLP_DIV2                   0x00000002
#define RCC_PLLP_DIV4                   0x00000004
#define RCC_PLLP_DIV6                   0x00000006
#define RCC_PLLP_DIV8                   0x00000008

/*
 *  RCC_APB1_APB2_Clock_Source RCC APB1/APB2 Clock Source
 */
#define RCC_HCLK_DIV1                   RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK_DIV2                   RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK_DIV4                   RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK_DIV8                   RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK_DIV16                  RCC_CFGR_PPRE1_DIV16

/*
 *  RCC_AHB_Clock_Source RCC AHB Clock Source
 */
#define RCC_SYSCLK_DIV1                 RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_DIV2                 RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_DIV4                 RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_DIV8                 RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_DIV16                RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_DIV64                RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_DIV128               RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_DIV256               RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_DIV512               RCC_CFGR_HPRE_DIV512

#define RCC_CLK48SOURCE_PLL              0x00000000
#define RCC_CLK48SOURCE_PLLSAIP          RCC_DCKCFGR2_CK48MSEL

#define RCC_PLLSAIP_DIV2                 0x00000000
#define RCC_PLLSAIP_DIV4                 0x00000001
#define RCC_PLLSAIP_DIV6                 0x00000002
#define RCC_PLLSAIP_DIV8                 0x00000003

/*
 *  CORTEX MPU領域許可禁止
 */
#define MPU_REGION_ENABLE               0x01
#define MPU_REGION_DISABLE              0x00

/*
 *  CORTEX MPU インストラクションアクセス許可禁止
 */
#define MPU_INSTRUCTION_ACCESS_ENABLE   0x00
#define MPU_INSTRUCTION_ACCESS_DISABLE  0x01

/*
 *  CORTEX MPU インストラクションアクセスキャッシュ設定
 */
#define MPU_ACCESS_CACHEABLE            0x01
#define MPU_ACCESS_NOT_CACHEABLE        0x00

/*
 *  CORTEX MPU インストラクションアクセスバッファ設定
 */
#define MPU_ACCESS_BUFFERABLE           0x01
#define MPU_ACCESS_NOT_BUFFERABLE       0x00

/*
 *  CORTEX MPU インストラクションアクセス共有設定
 */
#define MPU_ACCESS_SHAREABLE            0x01
#define MPU_ACCESS_NOT_SHAREABLE        0x00

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


#define LED1_POSITION                   1

/*
 *  キャッシュサイズID レジスタマクロ
 */
#define CCSIDR_WAYS(x)         (((x) & SCB_CCSIDR_ASSOCIATIVITY_Msk) >> SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_SETS(x)         (((x) & SCB_CCSIDR_NUMSETS_Msk      ) >> SCB_CCSIDR_NUMSETS_Pos      )
#define CCSIDR_LSSHIFT(x)      (((x) & SCB_CCSIDR_LINESIZE_Msk     ) /*>> SCB_CCSIDR_LINESIZE_Pos*/ )

#define sil_mdw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_anw_mem(addr, mask)			sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))

ER sysclock_config(int mode);

#ifndef TOPPERS_RAM_EXEC
static void mpu_config(void);
static void sysemclock_error(void);

/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void hardware_init_hook(void)
{
	uint32_t reg_value;
	uint32_t ccsidr, sshift, wshift, sw;
	uint32_t sets, ways;

	/*
	 * RCCのリセットとコンフィギュレーション
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00000000);
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), (RCC_CR_PLLON | RCC_CR_CSSON | RCC_CR_HSEON));
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR),
		(0x20000000 | RCC_PLLCFGR_PLLQ_2 | RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLN_6 | RCC_PLLCFGR_PLLM_4));
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	/*
	 *  全割込み禁止
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIR), 0x00000000);

	/*
	 *  メモリプロテクションユニットの初期化
	 */
	mpu_config();

	/*
	 *  キャッシュを有効化
	 */
	/* I-Cache有効化 */
	Asm("dsb 0xF":::"memory");
	Asm("isb 0xF":::"memory");
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_ICIALLU), 0);	/* invalidate I-Cache */
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCR), SCB_CCR_IC_Msk);	/* enable I-Cache */
	Asm("dsb 0xF":::"memory");
	Asm("isb 0xF":::"memory");

	/* D-Cache有効化 */
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CSSELR), ((0UL << 1) | 0UL));	/* Level 1 data cache */
	ccsidr  = sil_rew_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCSIDR));
    sets    = (uint32_t)(CCSIDR_SETS(ccsidr));
    sshift  = (uint32_t)(CCSIDR_LSSHIFT(ccsidr) + 4UL);
    ways    = (uint32_t)(CCSIDR_WAYS(ccsidr));
    wshift  = (uint32_t)((uint32_t)__builtin_clz(ways) & 0x1FUL);

    /* D-Chaheインバリデート */
	Asm("dsb 0xF":::"memory");
	do{
		uint32_t tmpways = ways;
		do {
			sw = ((tmpways << wshift) | (sets << sshift));
			sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_DCISW), sw);

        } while(tmpways--);
    }while(sets--);
	Asm("dsb 0xF":::"memory");

	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCR), SCB_CCR_DC_Msk);
	Asm("dsb 0xF":::"memory");
	Asm("isb 0xF":::"memory");


	/*
	 *  割込みグループ優先度設定
	 */
	reg_value = sil_rew_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_AIRCR));        /* read old register configuration    */
	reg_value &= ~((uint32_t)(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk));	/* clear bits to change               */
	reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << SCB_AIRCR_VECTKEY_Pos) |
                ((NVIC_PRIORITYGROUP_4 & 0x07L) << 8));							/* Insert write key and priorty group */
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_AIRCR), reg_value);

	/*
	 *  システムクロックを 216MHzに設定
	 */
	if(sysclock_config(0) != E_OK)
		sysemclock_error();
}
#endif

/*
 *  USB CLOCK CONFIGURATION
 */
ER USB_RCC_PeriphCLKConfig(unsigned int pllsan, unsigned int pllsaip)
{
	unsigned int tickstart = 0U;
	unsigned int pllsaiq = 0U;

    /*
	 * クロック48ソース設定
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2), RCC_DCKCFGR2_CK48MSEL, RCC_CLK48SOURCE_PLLSAIP);

    /*
	 *  PLLSAIクロックを停止
	 */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLSAION);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLSAIRDY) != 0){
		if(tickstart  > PLLSAI_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
    }

    /*
	 *  PLLSAIクロック設定
	 */
	pllsaiq = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAICFGR)) & (RCC_PLLSAICFGR_PLLSAIQ | RCC_PLLSAICFGR_PLLSAIR);
	/* Configure the PLLSAI division factors */
	/* PLLSAI_VCO = f(VCO clock) = f(PLLSAI clock input) * (PLLI2SN/PLLSAIM) */
	/* 48CLK = f(PLLSAI clock output) = f(VCO clock) / PLLSAIP */
	pllsaiq |= (pllsan << 6)  | (pllsaip << 16);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAICFGR), pllsaiq);

    /*
	 *  PLLSAIクロックを再開
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLSAION);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & (RCC_CR_PLLSAIRDY)) == 0){
		if( tickstart > PLLSAI_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}
	return E_OK;
}

/*
 *  システムクロック設定
 *  設定値：
 *    System Clock source            = PLL (HSE)
 *    SYSCLK(Hz)                     = 216000000
 *    HCLK(Hz)                       = 216000000
 *    AHB Prescaler                  = 1
 *    APB1 Prescaler                 = 4
 *    APB2 Prescaler                 = 2
 *    HSE Frequency(Hz)              = 25000000
 *    PLL_M                          = 25
 *    PLL_N                          = 432
 *    PLL_P                          = 2
 *    PLL_Q                          = 9
 *    VDD(V)                         = 3.3
 *    Main regulator output voltage  = Scale1 mode
 *    Flash Latency(WS)              = 7
 */
ER sysclock_config(int mode)
{
	uint32_t tickstart = 0;
	volatile uint32_t tmpreg;

	/*
	 *  HSEの初期設定
	 */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);

	/* HSEの無効化待ち */  
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) != 0){
		if(tickstart > HSE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

	/* HSEの再設定 */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);

	tickstart = 0;
	/* HSEの再起動待ち */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) == 0){
		if(tickstart > HSE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

	/*
	 *  PLLの初期設定
	 */
	/*  メインPLLの無効化. */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

	/*  PLLのレディ待ち */
	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
		if(tickstart > PLL_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}
	/*  PLLレジスタ設定 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), (0x20000000 | PLL_M | (PLL_N << 6) | ((RCC_PLLP_DIV2 >> 1) -1) << 16)
			 | RCC_PLLCFGR_PLLSRC_HSE | (PLL_Q << 24));

	/*  メインPLLの有効化待ち */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);
	tickstart = 0;

	/*  PLLの有効化待ち */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
		if(tickstart > PLL_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}


	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR), RCC_APB1ENR_PWREN);
	tmpreg = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR)) & RCC_APB1ENR_PWREN;
	(void)(tmpreg);

	/* 216MHz用のオーバードライブ設定 */
	sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_ODEN);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR1)) & PWR_CSR1_ODRDY) != PWR_CSR1_ODRDY){
		if(tickstart > PWR_OVERDRIVE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
    	tickstart++;
	}

	/* オーバードライブスイッチを有効化 */
	sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_ODSWEN);

	/* オーバードライブレディ待ち */
	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR1)) & PWR_CSR1_ODSWRDY) != PWR_CSR1_ODSWRDY){
		if(tickstart > PWR_OVERDRIVE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

	/*
	 *  USBクロック設定
	 */
	USB_RCC_PeriphCLKConfig(192, RCC_PLLSAIP_DIV4);

	/*
	 *  フラッシュメモリから正しくデータを読み込めるように実行周波数に合わせて
	 *  HCLKレイテンシィとデバイスの電源電圧調節する必要がある
	 */
	/*  CPU周波数の増大ケース */
	if(FLASH_ACR_LATENCY_7WS > (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){

		sil_mdw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_7WS);
		if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_7WS){
			while(1) { ; }
		}

		sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, RCC_SYSCLK_DIV1);
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
			return E_SYS;
		}

		sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_SW, RCC_CFGR_SW_PLL);
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL){
			if(tickstart > CLOCKSWITCH_TIMEOUT_VALUE){
				return E_TMOUT;
			}
			sil_dly_nse(1000);
			tickstart++;
		}
	}
	/*  CPU周波数の低下ケース */
	else{
		sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, RCC_SYSCLK_DIV1);
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
			return E_SYS;
		}

		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL){
			if(tickstart > CLOCKSWITCH_TIMEOUT_VALUE){
				return E_TMOUT;
			}
			sil_dly_nse(1000);
			tickstart++;
		}

		sil_mdw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_7WS);
		if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_7WS){
			return E_SYS;
		}
	}

	/*
	 *  PCLK1初期設定
	 */ 
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_HCLK_DIV4);

	/*
	 *  PCLK2初期設定
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, (RCC_HCLK_DIV2 << 3));
	return E_OK;
}

#ifndef TOPPERS_RAM_EXEC
/*
 *  メモリプロテクションユニットの設定
 */
static void mpu_config(void)
{
	/* Disable the MPU */
	sil_anw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_SHCSR), SCB_SHCSR_MEMFAULTENA_Msk);
	sil_anw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_CTRL), MPU_CTRL_ENABLE_Msk);

	/* Set the Region number */
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RNR), MPU_REGION_NUMBER0);

	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x20010000);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RASR),
				((MPU_INSTRUCTION_ACCESS_ENABLE << MPU_RASR_XN_Pos)   |
                 (MPU_REGION_FULL_ACCESS        << MPU_RASR_AP_Pos)   |
                 (MPU_TEX_LEVEL0                << MPU_RASR_TEX_Pos)  |
                 (MPU_ACCESS_NOT_SHAREABLE      << MPU_RASR_S_Pos)    |
                 (MPU_ACCESS_CACHEABLE          << MPU_RASR_C_Pos)    |
                 (MPU_ACCESS_NOT_BUFFERABLE     << MPU_RASR_B_Pos)    |
                 (0x00                          << MPU_RASR_SRD_Pos)  |
                 (MPU_REGION_SIZE_256KB         << MPU_RASR_SIZE_Pos) |
                 (MPU_REGION_ENABLE             << MPU_RASR_ENABLE_Pos)));

	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RNR), MPU_REGION_NUMBER1);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x20048000);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RASR),
				((MPU_INSTRUCTION_ACCESS_ENABLE << MPU_RASR_XN_Pos)   |
                 (MPU_REGION_FULL_ACCESS        << MPU_RASR_AP_Pos)   |
                 (MPU_TEX_LEVEL1                << MPU_RASR_TEX_Pos)  |
                 (MPU_ACCESS_SHAREABLE          << MPU_RASR_S_Pos)    |
                 (MPU_ACCESS_NOT_CACHEABLE      << MPU_RASR_C_Pos)    |
                 (MPU_ACCESS_NOT_BUFFERABLE     << MPU_RASR_B_Pos)    |
                 (0x00                          << MPU_RASR_SRD_Pos)  |
                 (MPU_REGION_SIZE_32KB          << MPU_RASR_SIZE_Pos) |
                 (MPU_REGION_ENABLE             << MPU_RASR_ENABLE_Pos)));

	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RNR), MPU_REGION_NUMBER2);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x20048000);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RASR),
				((MPU_INSTRUCTION_ACCESS_ENABLE << MPU_RASR_XN_Pos)   |
                 (MPU_REGION_FULL_ACCESS        << MPU_RASR_AP_Pos)   |
                 (MPU_TEX_LEVEL0                << MPU_RASR_TEX_Pos)  |
                 (MPU_ACCESS_SHAREABLE          << MPU_RASR_S_Pos)    |
                 (MPU_ACCESS_NOT_CACHEABLE      << MPU_RASR_C_Pos)    |
                 (MPU_ACCESS_BUFFERABLE         << MPU_RASR_B_Pos)    |
                 (0x00                          << MPU_RASR_SRD_Pos)  |
                 (MPU_REGION_SIZE_512B          << MPU_RASR_SIZE_Pos) |
                 (MPU_REGION_ENABLE             << MPU_RASR_ENABLE_Pos)));

	/* Enable the MPU */
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_CTRL), (MPU_PRIVILEGED_DEFAULT | MPU_CTRL_ENABLE_Msk));
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_SHCSR), SCB_SHCSR_MEMFAULTENA_Msk);
}

/*
 *  システムクロック設定エラー
 */
static void sysemclock_error(void)
{
	volatile uint32_t temp = 0x00;
	uint32_t n = LED1_POSITION;

	/*
	 *  GPIO LEDクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), RCC_AHB1ENR_GPIOIEN);
	temp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR));
	(void)(temp);

	/*
	 * LED GPIO設定
	 */
	sil_mdw_mem((uint32_t *)(TADR_GPIOI_BASE+TOFF_GPIO_MODER), (3 << (n * 2)), (GPIO_MODE_OUTPUT << (n * 2)));
	sil_mdw_mem((uint32_t *)(TADR_GPIOI_BASE+TOFF_GPIO_OSPEEDR), (3 << (n * 2)), (GPIO_SPEED_HIGH << (n * 2)));
	sil_mdw_mem((uint32_t *)(TADR_GPIOI_BASE+TOFF_GPIO_OTYPER), (1 << n), (GPIO_OTYPE_PP<<n));
	sil_mdw_mem((uint32_t *)(TADR_GPIOI_BASE+TOFF_GPIO_PUPDR), (3 << (n * 2)), (GPIO_PULLUP << (n * 2)));
	while(1){
		/* LED ON */
		sil_wrw_mem((uint32_t *)(TADR_GPIOI_BASE+TOFF_GPIO_BSRR), (1<<n));
		sil_dly_nse(200*1000*1000);
		/* LED OFF */
		sil_wrw_mem((uint32_t *)(TADR_GPIOI_BASE+TOFF_GPIO_BSRR), (1<<n)<<16);
		sil_dly_nse(200*1000*1000);
	}
}
#endif

