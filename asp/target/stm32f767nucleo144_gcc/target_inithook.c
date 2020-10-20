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
 *  ╛х╡н├°║ю╕в╝╘д╧бд░╩▓╝д╬(1)б┴(4)д╬╛Є╖ядЄ╦■д┐д╣╛ь╣чд╦╕┬дъбд╦▄е╜е╒е╚ежез
 *  евб╩╦▄е╜е╒е╚ежезевдЄ▓■╩╤д╖д┐дтд╬дЄ┤▐дрбе░╩▓╝╞▒д╕б╦дЄ╗╚═╤бж╩г└╜бж▓■
 *  ╩╤бж║╞╟█╔█б╩░╩▓╝бд═°═╤д╚╕╞д╓б╦д╣дыд│д╚дЄ╠╡╜■д╟╡Ў┬·д╣дыбе
 *  (1) ╦▄е╜е╒е╚ежезевдЄе╜б╝е╣е│б╝е╔д╬╖┴д╟═°═╤д╣ды╛ь╣чд╦д╧бд╛х╡нд╬├°║ю
 *      ╕в╔╜╝ибдд│д╬═°═╤╛Є╖ядкдшд╙▓╝╡нд╬╠╡╩▌╛┌╡м─ъдмбдд╜д╬д▐д▐д╬╖┴д╟е╜б╝
 *      е╣е│б╝е╔├цд╦┤▐д▐дьд╞дддыд│д╚бе
 *  (2) ╦▄е╜е╒е╚ежезевдЄбдещеде╓ещеъ╖┴╝░д╩д╔бд┬╛д╬е╜е╒е╚ежезев│л╚пд╦╗╚
 *      ═╤д╟днды╖┴д╟║╞╟█╔█д╣ды╛ь╣чд╦д╧бд║╞╟█╔█д╦╚╝дже╔енехесеєе╚б╩═°═╤
 *      ╝╘е▐е╦ехевеыд╩д╔б╦д╦бд╛х╡нд╬├°║ю╕в╔╜╝ибдд│д╬═°═╤╛Є╖ядкдшд╙▓╝╡н
 *      д╬╠╡╩▌╛┌╡м─ъдЄ╖╟║▄д╣дыд│д╚бе
 *  (3) ╦▄е╜е╒е╚ежезевдЄбд╡б┤яд╦┴╚д▀╣■дрд╩д╔бд┬╛д╬е╜е╒е╚ежезев│л╚пд╦╗╚
 *      ═╤д╟днд╩дд╖┴д╟║╞╟█╔█д╣ды╛ь╣чд╦д╧бд╝бд╬ддд║дьдлд╬╛Є╖ядЄ╦■д┐д╣д│
 *      д╚бе
 *    (a) ║╞╟█╔█д╦╚╝дже╔енехесеєе╚б╩═°═╤╝╘е▐е╦ехевеыд╩д╔б╦д╦бд╛х╡нд╬├°
 *        ║ю╕в╔╜╝ибдд│д╬═°═╤╛Є╖ядкдшд╙▓╝╡нд╬╠╡╩▌╛┌╡м─ъдЄ╖╟║▄д╣дыд│д╚бе
 *    (b) ║╞╟█╔█д╬╖┴┬╓дЄбд╩╠д╦─ъдсды╩¤╦бд╦дшд├д╞бдTOPPERSе╫еэе╕езепе╚д╦
 *        ╩є╣Ёд╣дыд│д╚бе
 *  (4) ╦▄е╜е╒е╚ежезевд╬═°═╤д╦дшдъ─╛└▄┼кд▐д┐д╧┤╓└▄┼кд╦└╕д╕дыдддлд╩ды┬╗
 *      │▓длдщдтбд╛х╡н├°║ю╕в╝╘дкдшд╙TOPPERSе╫еэе╕езепе╚дЄ╠╚└╒д╣дыд│д╚бе
 *      д▐д┐бд╦▄е╜е╒е╚ежезевд╬ецб╝е╢д▐д┐д╧еиеєе╔ецб╝е╢длдщд╬дддлд╩ды═¤
 *      ═│д╦┤Ёд┼дп└┴╡сдлдщдтбд╛х╡н├°║ю╕в╝╘дкдшд╙TOPPERSе╫еэе╕езепе╚дЄ
 *      ╠╚└╒д╣дыд│д╚бе
 * 
 *  ╦▄е╜е╒е╚ежезевд╧бд╠╡╩▌╛┌д╟─є╢бд╡дьд╞дддыдтд╬д╟двдыбе╛х╡н├°║ю╕в╝╘дк
 *  дшд╙TOPPERSе╫еэе╕езепе╚д╧бд╦▄е╜е╒е╚ежезевд╦┤╪д╖д╞бд╞├─ъд╬╗╚═╤╠▄┼к
 *  д╦┬╨д╣ды┼м╣ч└ндт┤▐дсд╞бддддлд╩ды╩▌╛┌дт╣╘дяд╩ддбед▐д┐бд╦▄е╜е╒е╚ежез
 *  евд╬═°═╤д╦дшдъ─╛└▄┼кд▐д┐д╧┤╓└▄┼кд╦└╕д╕д┐дддлд╩ды┬╗│▓д╦┤╪д╖д╞дтбдд╜
 *  д╬└╒╟ддЄ╔щдяд╩ддбе
 * 
 *  @(#) $Id: target_inithook.c 698 2019-07-02 17:55:15Z roi $
 */

#include <sil.h>
#include "target_syssvc.h"

/*
 *  ╜щ┤№▓╜е╫еэе░ещерб╩stm32f767-nucleo144═╤б╦
 */

#define PLL_M      (HSE_VALUE / 1000000)/* Possible value 0 and 63 */
#define PLL_N      432
#define PLL_Q      9
#define PLL_R      7

/*
 *  TIMEOUT VALUES
 */
#define CLOCKSWITCH_TIMEOUT_VALUE      (5000*1000)		/* 5╔├ */
#define HSE_TIMEOUT_VALUE              (5000*1000)		/* 5╔├ */
#define PLL_TIMEOUT_VALUE              (100*1000)		/* 100 ms */
#define PLLSAI_TIMEOUT_VALUE           (100*1000)		/* 100 ms  */
#define PWR_OVERDRIVE_TIMEOUT_VALUE    (1000*1000)		/* 1╔├ */

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

#define RCC_PLLSAIP_DIV8                 0x00000003

/*
 *  CORTEX MPU╬╬░ш╡Ў▓─╢╪╗▀
 */
#define MPU_REGION_ENABLE               0x01
#define MPU_REGION_DISABLE              0x00

/*
 *  CORTEX MPU едеєе╣е╚ещепе╖ечеєевепе╗е╣╡Ў▓─╢╪╗▀
 */
#define MPU_INSTRUCTION_ACCESS_ENABLE   0x00
#define MPU_INSTRUCTION_ACCESS_DISABLE  0x01

/*
 *  CORTEX MPU едеєе╣е╚ещепе╖ечеєевепе╗е╣енеуе├е╖ех└▀─ъ
 */
#define MPU_ACCESS_CACHEABLE            0x01
#define MPU_ACCESS_NOT_CACHEABLE        0x00

/*
 *  CORTEX MPU едеєе╣е╚ещепе╖ечеєевепе╗е╣е╨е├е╒еб└▀─ъ
 */
#define MPU_ACCESS_BUFFERABLE           0x01
#define MPU_ACCESS_NOT_BUFFERABLE       0x00

/*
 *  CORTEX MPU едеєе╣е╚ещепе╖ечеєевепе╗е╣╢ж═н└▀─ъ
 */
#define MPU_ACCESS_SHAREABLE            0x01
#define MPU_ACCESS_NOT_SHAREABLE        0x00

/*
 *  GPIOевеже╚е╫е├е╚└▀─ъе╤ещесб╝е┐
 */
#define GPIO_OTYPE_PP       0x0
#define GPIO_OTYPE_OD       0x1

/*
 *  GPIOе╫еыеве├е╫е└ежеєе╤ещесб╝е┐
 */
#define GPIO_NOPULL         0x00000000	/* No Pull-up or Pull-down activation  */
#define GPIO_PULLUP         0x00000001	/* Pull-up activation                  */
#define GPIO_PULLDOWN       0x00000002	/* Pull-down activation                */

/*
 *  GPIOетб╝е╔е╤ещесб╝е┐
 */
#define GPIO_MODE_INPUT     0x00000000	/* Input Floating Mode */
#define GPIO_MODE_OUTPUT    0x00000001	/* Output Push Pull Mode */
#define GPIO_MODE_AF        0x00000002	/* Alternate Function Push Pull Mode */
#define GPIO_MODE_ANALOG    0x00000003	/* Analog Mode  */

/*
 *  GPIOевеже╚е╫е├е╚║╟┬ч╝■╟╚┐Їе╤ещесб╝е┐
 */
#define GPIO_SPEED_LOW      0x00000000	/* Low speed     */
#define GPIO_SPEED_MEDIUM   0x00000001	/* Medium speed  */
#define GPIO_SPEED_FAST     0x00000002	/* Fast speed    */
#define GPIO_SPEED_HIGH     0x00000003	/* High speed    */


#define LED1_POSITION                   1

/*
 *  енеуе├е╖ехе╡еде║ID еье╕е╣е┐е▐епеэ
 */
#define CCSIDR_WAYS(x)         (((x) & SCB_CCSIDR_ASSOCIATIVITY_Msk) >> SCB_CCSIDR_ASSOCIATIVITY_Pos)
#define CCSIDR_SETS(x)         (((x) & SCB_CCSIDR_NUMSETS_Msk      ) >> SCB_CCSIDR_NUMSETS_Pos      )
#define CCSIDR_LSSHIFT(x)      (((x) & SCB_CCSIDR_LINESIZE_Msk     ) /*>> SCB_CCSIDR_LINESIZE_Pos*/ )

#define sil_mdw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_anw_mem(addr, mask)			sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))

ER sysclock_config(int mode);
#if 0 /* not used */
static void mpu_config(void);
static void sysemclock_error(void);
#endif /* not used */

#ifndef TOPPERS_RAM_EXEC
/*
 *  ─уеье┘еыд╬е┐б╝е▓е├е╚░═┬╕д╬╜щ┤№▓╜
 *
 *  е╣е┐б╝е╚еве├е╫ете╕ехб╝еыд╬├цд╟бдесетеъд╬╜щ┤№▓╜д╬┴░д╦╕╞д╙╜╨д╡дьдыбе
 */
void hardware_init_hook(void)
{
	uint32_t reg_value;
	uint32_t ccsidr, sshift, wshift, sw;
	uint32_t sets, ways;

	/*
	 * RCCд╬еъе╗е├е╚д╚е│еєе╒егеоехеьб╝е╖ечеє
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00000000);
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), (RCC_CR_PLLON | RCC_CR_CSSON | RCC_CR_HSEON));
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR),
		(0x20000000 | RCC_PLLCFGR_PLLQ_2 | RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLN_6 | RCC_PLLCFGR_PLLM_4));
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	// ETHMACуБоуВпуГнуГГуВпцЬЙхК╣хМЦ
	__ETHMAC_CLK_ENABLE();
	__ETHMACRX_CLK_ENABLE();
	__ETHMACTX_CLK_ENABLE();

	//DMAцЬЙхК╣хМЦ
	sli_orw_mem((uint32_t *)(TADR_RCC_BASE + TOFF_RCC_AHB1ENR), (RCC_AHB1ENR_DMA1EN | RCCAHB1ENR_DMA2EN | RCC_AHB1ENR_DMA2DEN ) );
	/*
	 *  я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜▀╢╪╗я┐╜
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIR), 0x00000000);

	/*
	 *  я┐╜я┐╜я┐╜я┐╜╫ея┐╜я┐╜╞ея┐╜я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜╦е├е╚д╬╜я┐╜я┐╜я┐╜я┐╜
	 */
	mpu_config();

	/*
	 *  я┐╜я┐╜я┐╜я┐╜├ея┐╜я┐╜я┐╜я┐╜═ня┐╜я┐╜я┐╜я┐╜
	 */
	/* I-Cache═ня┐╜я┐╜я┐╜я┐╜ */
	Asm("dsb 0xF":::"memory");
	Asm("isb 0xF":::"memory");
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_ICIALLU), 0);	/* invalidate I-Cache */
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCR), SCB_CCR_IC_Msk);	/* enable I-Cache */
	Asm("dsb 0xF":::"memory");
	Asm("isb 0xF":::"memory");

	/* D-Cache═н╕·▓╜ */
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CSSELR), ((0UL << 1) | 0UL));	/* Level 1 data cache */
	ccsidr  = sil_rew_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CCSIDR));
    sets    = (uint32_t)(CCSIDR_SETS(ccsidr));
    sshift  = (uint32_t)(CCSIDR_LSSHIFT(ccsidr) + 4UL);
    ways    = (uint32_t)(CCSIDR_WAYS(ccsidr));
    wshift  = (uint32_t)((uint32_t)__builtin_clz(ways) & 0x1FUL);

    /* D-Chaheедеєе╨еъе╟б╝е╚ */
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
	 *  │ф╣■д▀е░еыб╝е╫═е└ш┼┘└▀─ъ
	 */
	reg_value = sil_rew_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_AIRCR));        /* read old register configuration    */
	reg_value &= ~((uint32_t)(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk));	/* clear bits to change               */
	reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << SCB_AIRCR_VECTKEY_Pos) |
                ((NVIC_PRIORITYGROUP_4 & 0x07L) << 8));							/* Insert write key and priorty group */
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_AIRCR), reg_value);

	/*
	 *  е╖е╣е╞ерепеэе├епдЄ 216MHzд╦└▀─ъ
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
	 * епеэе├еп48е╜б╝е╣└▀─ъ
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2), RCC_DCKCFGR2_CK48MSEL, RCC_CLK48SOURCE_PLLSAIP);

    /*
	 *  PLLSAIепеэе├епдЄ─ф╗▀
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
	 *  PLLSAIепеэе├еп└▀─ъ
	 */
	pllsaiq = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAICFGR)) & (RCC_PLLSAICFGR_PLLSAIQ | RCC_PLLSAICFGR_PLLSAIR);
	/* Configure the PLLSAI division factors */
	/* PLLSAI_VCO = f(VCO clock) = f(PLLSAI clock input) * (PLLI2SN/PLLSAIM) */
	/* 48CLK = f(PLLSAI clock output) = f(VCO clock) / PLLSAIP */
	pllsaiq |= (pllsan << 6)  | (pllsaip << 16);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAICFGR), pllsaiq);

    /*
	 *  PLLSAIепеэе├епдЄ║╞│л
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
 *  е╖е╣е╞ерепеэе├еп└▀─ъ
 *  └▀─ъ├═бз
 *    System Clock source            = PLL (HSE)
 *    SYSCLK(Hz)                     = 216000000
 *    HCLK(Hz)                       = 216000000
 *    AHB Prescaler                  = 1
 *    APB1 Prescaler                 = 4
 *    APB2 Prescaler                 = 2
 *    HSE Frequency(Hz)              = 8000000
 *    PLL_M                          = 8
 *    PLL_N                          = 432
 *    PLL_P                          = 2
 *    PLL_Q                          = 9
 *    PLL_R                          = 7
 *    VDD(V)                         = 3.3
 *    Main regulator output voltage  = Scale1 mode
 *    Flash Latency(WS)              = 7
 */
ER sysclock_config(int mode)
{
	uint32_t tickstart = 0;
	volatile uint32_t tmpreg;

	/*
	 *  HSEд╬╜щ┤№└▀─ъ
	 */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);

	/* HSEд╬╠╡╕·▓╜┬╘д┴ */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) != 0){
		if(tickstart > HSE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

	/* HSEд╬║╞└▀─ъ */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);

	tickstart = 0;
	/* HSEд╬║╞╡п╞░┬╘д┴ */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) == 0){
		if(tickstart > HSE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

	/*
	 *  PLLд╬╜щ┤№└▀─ъ
	 */
	/*  еседеєPLLд╬╠╡╕·▓╜. */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

	/*  PLLд╬еье╟ег┬╘д┴ */
	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
		if(tickstart > PLL_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}
	/*  PLLеье╕е╣е┐└▀─ъ */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), (0x20000000 | PLL_M | (PLL_N << 6) | ((RCC_PLLP_DIV2 >> 1) -1) << 16)
			 | RCC_PLLCFGR_PLLSRC_HSE | (PLL_Q << 24) | (PLL_R << 28));

	/*  еседеєPLLд╬═н╕·▓╜┬╘д┴ */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);
	tickstart = 0;

	/*  PLLд╬═н╕·▓╜┬╘д┴ */
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

	/* 216MHz═╤д╬екб╝е╨б╝е╔ещеде╓└▀─ъ */
	sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_ODEN);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR1)) & PWR_CSR1_ODRDY) != PWR_CSR1_ODRDY){
		if(tickstart > PWR_OVERDRIVE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
    	tickstart++;
	}

	/* екб╝е╨б╝е╔ещеде╓е╣еде├е┴дЄ═н╕·▓╜ */
	sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_ODSWEN);

	/* екб╝е╨б╝е╔ещеде╓еье╟ег┬╘д┴ */
	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR1)) & PWR_CSR1_ODSWRDY) != PWR_CSR1_ODSWRDY){
		if(tickstart > PWR_OVERDRIVE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

	/*
	 *  USBепеэе├еп└▀─ъ
	 */
	USB_RCC_PeriphCLKConfig(384, RCC_PLLSAIP_DIV8);

	/*
	 *  е╒еще├е╖ехесетеъдлдщ└╡д╖дпе╟б╝е┐дЄ╞╔д▀╣■дсдыдшджд╦╝┬╣╘╝■╟╚┐Їд╦╣чдяд╗д╞
	 *  HCLKеьеде╞еєе╖егд╚е╟е╨еде╣д╬┼┼╕╗┼┼░╡─┤└сд╣ды╔м═╫дмдвды
	 */
	/*  CPU╝■╟╚┐Їд╬┴¤┬че▒б╝е╣ */
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
	/*  CPU╝■╟╚┐Їд╬─у▓╝е▒б╝е╣ */
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
	 *  PCLK1╜щ┤№└▀─ъ
	 */ 
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_HCLK_DIV4);

	/*
	 *  PCLK2╜щ┤№└▀─ъ
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, (RCC_HCLK_DIV2 << 3));
	return E_OK;
}

#if 0 /* not used */
/*
 *  есетеъе╫еэе╞епе╖ечеєеце╦е├е╚д╬└▀─ъ
 */
static void mpu_config(void)
{
	/* Disable the MPU */
	sil_anw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_SHCSR), SCB_SHCSR_MEMFAULTENA_Msk);
	sil_anw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_CTRL), MPU_CTRL_ENABLE_Msk);

	/* Set the Region number */
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RNR), MPU_REGION_NUMBER0);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x20020000);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RASR),
				((MPU_INSTRUCTION_ACCESS_ENABLE << MPU_RASR_XN_Pos)   |
                 (MPU_REGION_FULL_ACCESS        << MPU_RASR_AP_Pos)   |
                 (MPU_TEX_LEVEL0                << MPU_RASR_TEX_Pos)  |
                 (MPU_ACCESS_NOT_SHAREABLE      << MPU_RASR_S_Pos)    |
                 (MPU_ACCESS_CACHEABLE          << MPU_RASR_C_Pos)    |
                 (MPU_ACCESS_NOT_BUFFERABLE     << MPU_RASR_B_Pos)    |
                 (0x00                          << MPU_RASR_SRD_Pos)  |
                 (MPU_REGION_SIZE_512KB         << MPU_RASR_SIZE_Pos) |
                 (MPU_REGION_ENABLE             << MPU_RASR_ENABLE_Pos)));

	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RNR), MPU_REGION_NUMBER1);
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x20078000);
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
	sil_wrw_mem((uint32_t *)(TADR_MPU_BASE+TOFF_MPU_RBAR), 0x20078000);
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
 *  е╖е╣е╞ерепеэе├еп└▀─ъеиещб╝
 */
static void sysemclock_error(void)
{
	volatile uint32_t temp = 0x00;
	uint32_t n = LED1_POSITION;

	/*
	 *  GPIO LEDепеэе├еп└▀─ъ
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), RCC_AHB1ENR_GPIOIEN);
	temp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR));
	(void)(temp);

	/*
	 * LED GPIO└▀─ъ
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

#endif /* not used */
