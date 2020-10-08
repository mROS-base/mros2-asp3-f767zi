/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015      by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2016-2019 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: chip_serial.c 699 2019-07-26 21:59:22Z roi $
 */

/*
 *  シリアルI/Oデバイス（SIO）ドライバ（stm32f7xx用）
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_stddef.h"
#include "target_serial.h"
#include "target_syssvc.h"

/*
 * レジスタ設定値
 */
#define PORT2SIOPID(x)	((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

/*
 *  GPIOモードパラメータ
 */
#define GPIO_MODE_INPUT     0x00000000	/* Input Floating Mode */
#define GPIO_MODE_OUTPUT    0x00000001	/* Output Mode */
#define GPIO_MODE_AF        0x00000002	/* Alternate Function Mode */
#define GPIO_MODE_ANALOG    0x00000003	/* Analog Mode  */

/*
 *  GPIOアウトプット設定パラメータ
 */
#define GPIO_OTYPE_PP       0x0
#define GPIO_OTYPE_OD       0x1

/*
 *  GPIOアウトプット最大周波数パラメータ
 */
#define GPIO_SPEED_LOW      0x00000000	/* Low speed     */
#define GPIO_SPEED_MEDIUM   0x00000001	/* Medium speed  */
#define GPIO_SPEED_FAST     0x00000002	/* Fast speed    */
#define GPIO_SPEED_HIGH     0x00000003	/* High speed    */

/*
 *  GPIOプルアップダウンパラメータ
 */
#define GPIO_NOPULL         0x00000000	/* No Pull-up or Pull-down activation  */
#define GPIO_PULLUP         0x00000001	/* Pull-up activation                  */
#define GPIO_PULLDOWN       0x00000002	/* Pull-down activation                */

/*
 *  CLOCKソース
 */
#define SOURCE_PCLK2        0
#define SOURCE_SYSCLK       1
#define SOURCE_HSI          2
#define SOURCE_LSE          3

/*
 *  ビット長パラメータ
 */
#define USART_WordLength_8b 0x0000
#define USART_WordLength_9b USART_CR1_M

/*
 *  ストップビットパラメータ
 */ 
#define USART_StopBits_1    0x0000
#define USART_StopBits_0_5  USART_CR2_STOP_0
#define USART_StopBits_2    USART_CR2_STOP_1
#define USART_StopBits_1_5  USART_CR2_STOP

/*
 *  パリティパラメータ
 */
#define USART_Parity_No     0x0000
#define USART_Parity_Even   USART_CR1_PCE
#define USART_Parity_Odd    (USART_CR1_PCE | USART_CR1_PS) 

/*
 * ハードウェアフロー制御パラメータ
 */
#define USART_HardwareFlowControl_None       0x0000
#define USART_HardwareFlowControl_RTS        USART_CR3_RTSE
#define USART_HardwareFlowControl_CTS        USART_CR3_CTSE
#define USART_HardwareFlowControl_RTS_CTS    (USART_CR3_RTSE | USART_CR3_CTSE)

#define ISR_ACK             (USART_ISR_TEACK | USART_ISR_REACK)
#define CR1_CLEAR_MASK      (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | USART_CR1_RE | USART_CR1_OVER8)
#define CR3_CLEAR_MASK      (USART_CR3_RTSE | USART_CR3_CTSE | USART_CR3_ONEBIT)

#define UART_TIMEOUT_VALUE               0x1FFFFFF

/*
 *  シリアルI/Oポート初期化ブロックの定義
 */
typedef struct sio_port_initialization_block {
	uint32_t base;
	INTNO    intno_usart;
	uint32_t clock_shift;
} SIOPINIB;

/*
 *  兼用GPIOポート初期化ブロックの定義
 */
typedef struct gpio_port_initialization_block {
	uint32_t clockbase;
	uint32_t clock_set;
	uint32_t portbase;
	uint32_t txport_set;
	uint32_t rxport_set;
	uint32_t resetbase;
	uint32_t reset_set;
	uint32_t gpio_af;

	uint32_t txportbase;
	uint32_t txpinport;
	uint32_t txmode_msk;
	uint32_t txmode_set;
	uint32_t txspeed_msk;
	uint32_t txspeed_set;
	uint32_t txtype_msk;
	uint32_t txtype_set;
	uint32_t txpupd_msk;
	uint32_t txpupd_set;

	uint32_t rxportbase;
	uint32_t rxpinport;
	uint32_t rxmode_msk;
	uint32_t rxmode_set;
	uint32_t rxspeed_msk;
	uint32_t rxspeed_set;
	uint32_t rxtype_msk;
	uint32_t rxtype_set;
	uint32_t rxpupd_msk;
	uint32_t rxpupd_set;
} GPIOINIB;

/*
 *  シリアルI/Oポート管理ブロックの定義
 */
struct sio_port_control_block {
	const SIOPINIB  *p_siopinib;  /* シリアルI/Oポート初期化ブロック */
	const GPIOINIB  *p_gpioinib;  /* 兼用GPIOポート初期化ブロック */
	intptr_t        exinf;        /* 拡張情報 */
	bool_t          opnflg;       /* オープン済みフラグ */
};

/*
 * シリアルI/Oポート初期化ブロック
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{(uint32_t)USART1_BASE, (INTNO)INTNO_SIO1, U1_CLOCK_SHIFT}
#if TNUM_SIOP > 1
   ,{(uint32_t)USART2_BASE, (INTNO)INTNO_SIO2, U2_CLOCK_SHIFT}
#endif
};

/*
 * 兼用GPIOポート初期化ブロック
 */
const GPIOINIB gpioinib_table[TNUM_SIOP] = {
	{(uint32_t)(TADR_RCC_BASE+TOFF_U1_APBNER), (uint32_t)ENABLE_U1_PORT,
     (uint32_t)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), (uint32_t)ENABLE_U1T_GPIO, (uint32_t)ENABLE_U1R_GPIO,
     (uint32_t)(TADR_RCC_BASE+TOFF_U1_APBRSTR), (uint32_t)RESET_U1_PORT,
	 (uint32_t)GPIO_U1_AF,
     (uint32_t)TADR_U1T_GPIO_BASE, (uint32_t)TX1_PINPOS,
     (uint32_t)~(GPIO_MODER_MODER2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_MODE_AF << (TX1_PINPOS*2)),
     (uint32_t)~(GPIO_OSPEEDER_OSPEEDR2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_SPEED_HIGH << (TX1_PINPOS*2)),
     (uint32_t)~(GPIO_OTYPER_OT << TX1_PINPOS), (uint32_t)(GPIO_OTYPE_PP << TX1_PINPOS),
     (uint32_t)~(GPIO_PUPDR_PUPDR2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_PULLUP << (TX1_PINPOS*2)),
     (uint32_t)TADR_U1R_GPIO_BASE, (uint32_t)RX1_PINPOS,
     (uint32_t)~(GPIO_MODER_MODER2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_MODE_AF << (RX1_PINPOS*2)),
     (uint32_t)~(GPIO_OSPEEDER_OSPEEDR2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_SPEED_HIGH << (RX1_PINPOS*2)),
     (uint32_t)~(GPIO_OTYPER_OT << RX1_PINPOS), (uint32_t)(GPIO_MODE_AF << RX1_PINPOS),
     (uint32_t)~(GPIO_PUPDR_PUPDR2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_PULLUP << (RX1_PINPOS*2))
    }
#if TNUM_SIOP > 1
   ,{(uint32_t)(TADR_RCC_BASE+TOFF_U2_APBNER), (uint32_t)ENABLE_U2_PORT,
     (uint32_t)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), (uint32_t)ENABLE_U2T_GPIO, (uint32_t)ENABLE_U2R_GPIO,
     (uint32_t)(TADR_RCC_BASE+TOFF_U2_APBRSTR), (uint32_t)RESET_U2_PORT,
	 (uint32_t)GPIO_U2_AF,
     (uint32_t)TADR_U2T_GPIO_BASE, (uint32_t)TX2_PINPOS,
     (uint32_t)~(GPIO_MODER_MODER2 << (TX2_PINPOS*2)), (uint32_t)(GPIO_MODE_AF << (TX2_PINPOS*2)),
     (uint32_t)~(GPIO_OSPEEDER_OSPEEDR2 << (TX2_PINPOS*2)), (uint32_t)(GPIO_SPEED_HIGH << (TX2_PINPOS*2)),
     (uint32_t)~(GPIO_OTYPER_OT << TX2_PINPOS), (uint32_t)(GPIO_OTYPE_PP << TX2_PINPOS),
     (uint32_t)~(GPIO_PUPDR_PUPDR2 << (TX2_PINPOS*2)), (uint32_t)(GPIO_PULLUP << (TX2_PINPOS*2)),
     (uint32_t)TADR_U2R_GPIO_BASE, (uint32_t)RX2_PINPOS,
     (uint32_t)~(GPIO_MODER_MODER2 << (RX2_PINPOS*2)), (uint32_t)(GPIO_MODE_AF << (RX2_PINPOS*2)),
     (uint32_t)~(GPIO_OSPEEDER_OSPEEDR2 << (RX2_PINPOS*2)), (uint32_t)(GPIO_SPEED_HIGH << (RX2_PINPOS*2)),
     (uint32_t)~(GPIO_OTYPER_OT << RX2_PINPOS), (uint32_t)(GPIO_MODE_AF << RX2_PINPOS),
     (uint32_t)~(GPIO_PUPDR_PUPDR2 << (RX2_PINPOS*2)), (uint32_t)(GPIO_PULLUP << (RX2_PINPOS*2))
    }
#endif
};

/*
 *  シリアルI/Oポート管理ブロックのエリア
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  シリアルI/OポートIDから管理ブロックを取り出すためのマクロ
 */
#define INDEX_SIOP(siopid)	((uint_t)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

static void setup_gpio_source(uint32_t base, uint8_t source, uint8_t select)
{
	uint32_t tmpreg, regoff;
	regoff = TOFF_GPIO_AFR0+((source>>3) * 4);
	tmpreg = (sil_rew_mem((uint32_t *)(base+regoff)) & ~(0xF << ((source & 0x07) * 4)))
			    | (select << ((source & 0x07) * 4));
	sil_wrw_mem((uint32_t *)(base+regoff), tmpreg);
}

void put_hex(char a, int val)
{
	int i, j;
	target_fput_log(a);
	target_fput_log(' ');
	for(i = 28 ; i >= 0 ; i-= 4){
		j = (val >> i) & 0xf;;
		if(j > 9)
			j += ('A'-10);
		else
			j += '0';
		target_fput_log(j);
	}
	target_fput_log('\n');
}

/*
 *  SIOドライバの初期化
 */
void
sio_initialize(intptr_t exinf)
{
	SIOPCB	*p_siopcb;
	uint_t	i;

	/*
	 *  シリアルI/Oポート管理ブロックの初期化
	 */
	for (p_siopcb = siopcb_table, i = 0; i < TNUM_SIOP; p_siopcb++, i++) {
		p_siopcb->p_siopinib = &(siopinib_table[i]);
		p_siopcb->p_gpioinib = &(gpioinib_table[i]);
		p_siopcb->opnflg = false;
	}
}

/*
 *  シリアルI/Oポートのオープン
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB          *p_siopcb;
	const SIOPINIB  *p_siopinib;
	const GPIOINIB  *p_gpioinib;
	bool_t   opnflg;
	ER       ercd;
	uint32_t base, txbase, rxbase, tmp;

	p_siopcb = get_siopcb(siopid);
	p_siopinib = p_siopcb->p_siopinib;
	p_gpioinib = p_siopcb->p_gpioinib;

	/*
	 *  オープンしたポートがあるかをopnflgに読んでおく．
	 */
	opnflg = p_siopcb->opnflg;

	p_siopcb->exinf = exinf;
	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;
	base   = p_siopinib->base;

	if(txbase == 0 || rxbase == 0)	/* no usart port */
		goto sio_opn_exit;

	/*
	 *  USART停止
	 */
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), 0xFFFFFFFF);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~USART_CR1_UE);

	/*
	 *  ハードウェアの初期化
	 */
	if(p_siopinib->clock_shift == 0){	/* USART1の場合、SYSLOCKを設定 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2),
			(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2)) & RCC_DCKCFGR2_USART1SEL) | RCC_DCKCFGR2_USART1SEL_0);
	}
	else if(p_siopinib->clock_shift == 10 && siopid == 1){	/* F723/USART6の場合、SYSLOCKを設定 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2),
			(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2)) & RCC_DCKCFGR2_USART6SEL) | RCC_DCKCFGR2_USART6SEL_0);
	}
	sil_wrw_mem((uint32_t *)p_gpioinib->clockbase, sil_rew_mem((uint32_t *)p_gpioinib->clockbase) | p_gpioinib->clock_set);
	sil_wrw_mem((uint32_t *)p_gpioinib->portbase, sil_rew_mem((uint32_t *)p_gpioinib->portbase) | p_gpioinib->txport_set);
	sil_wrw_mem((uint32_t *)p_gpioinib->portbase, sil_rew_mem((uint32_t *)p_gpioinib->portbase) | p_gpioinib->rxport_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_MODER)) & p_gpioinib->txmode_msk) | p_gpioinib->txmode_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR)) & p_gpioinib->txspeed_msk) | p_gpioinib->txspeed_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER)) & p_gpioinib->txtype_msk) | p_gpioinib->txtype_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR)) & p_gpioinib->txpupd_msk) | p_gpioinib->txpupd_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), (sil_rew_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER)) & p_gpioinib->rxmode_msk) | p_gpioinib->rxmode_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), (sil_rew_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR)) & p_gpioinib->rxspeed_msk) | p_gpioinib->rxspeed_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), (sil_rew_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER)) & p_gpioinib->rxtype_msk) | p_gpioinib->rxtype_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR)) & p_gpioinib->rxpupd_msk) | p_gpioinib->rxpupd_set);
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	tmp = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR2)) & ~USART_CR2_STOP;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), tmp | USART_StopBits_1);
	tmp = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~CR1_CLEAR_MASK;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), tmp | USART_WordLength_8b | USART_Parity_No | USART_CR1_RE | USART_CR1_TE);
	tmp = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3)) & ~CR3_CLEAR_MASK;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), tmp | USART_HardwareFlowControl_None);

	switch((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2)) >> p_siopinib->clock_shift) & 3){
	case SOURCE_HSI:
		tmp = HSI_VALUE;
		break;
	case SOURCE_SYSCLK:
		tmp = SysFreHCLK;
		break;
	case SOURCE_LSE:
		tmp = LSE_VALUE;
		break;
	case SOURCE_PCLK2:
	default:
		if(p_siopinib->clock_shift == 10)	/* USART6,1の場合 PCLK2 */
			tmp = SysFrePCLK2;
		else
			tmp = SysFrePCLK1;
		break;
	}
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), tmp/BPS_SETTING);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR2)) & ~(USART_CR2_LINEN | USART_CR2_CLKEN));
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3)) & ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) | USART_CR1_UE);

	/*
	 * RX/TX ACKがセットされるまで待つ
	 */
	tmp = 0;
    while((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & ISR_ACK) != ISR_ACK){
		/* Check for the Timeout */
		if(tmp >=  UART_TIMEOUT_VALUE){
			/* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts for the interrupt process */
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1),
				sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~(USART_CR1_TXEIE | USART_CR1_RXNEIE | USART_CR1_PEIE));
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3),
				sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3)) & ~USART_CR3_EIE);
			goto sio_opn_exit;
		}
		sil_dly_nse(1000);
		tmp++;
	}

	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) | USART_CR1_PEIE);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3)) | USART_CR3_EIE);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) | USART_CR1_RXNEIE);
	p_siopcb->opnflg = true;

	/*
	 *  シリアルI/O割込みのマスクを解除する．
	 */
	if (!opnflg) {
		ercd = ena_int(p_siopinib->intno_usart);
		assert(ercd == E_OK);
	}

sio_opn_exit:;
	return(p_siopcb);
}

/*
 *  シリアルI/Oポートのクローズ
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	const SIOPINIB  *p_siopinib;
	const GPIOINIB  *p_gpioinib;
	uint32_t base, tmp;

	/*
	 *  シリアルI/O割込みをマスクする．
	 */
	if ((p_siopcb->opnflg)) {
		dis_int(p_siopcb->p_siopinib->intno_usart);
	}

	/*
	 *  ハードウェアのリセット
	 */
	p_siopinib = p_siopcb->p_siopinib;
	p_gpioinib = p_siopcb->p_gpioinib;
	base = p_siopinib->base;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), 0xFFFFFFFF);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~USART_CR1_UE);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), 0x0);
	tmp = sil_rew_mem((uint32_t *)p_gpioinib->resetbase);
	sil_wrw_mem((uint32_t *)p_gpioinib->resetbase, tmp | p_gpioinib->reset_set);
	sil_wrw_mem((uint32_t *)p_gpioinib->resetbase, tmp & ~(p_gpioinib->reset_set));
	p_siopcb->opnflg = false;
}

/*
 *  SIOの割込みサービスルーチン
 */

Inline bool_t
sio_putready(SIOPCB* p_siopcb)
{
	uint32_t cr1 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR));

	if ((cr1 & USART_CR1_TXEIE) != 0 && (isr & USART_ISR_TXE) != 0)
	{
		return 1;
	}
	return 0;
}

Inline bool_t
sio_getready(SIOPCB* p_siopcb)
{
	uint32_t base = p_siopcb->p_siopinib->base;
	uint32_t cr1, cr3, isr;

	cr1 = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1));
	cr3 = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3));
	isr = sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR));

	if((isr & USART_ISR_PE) != 0 && (cr3 & USART_CR3_EIE) != 0){
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_PECF);
	}
	if((isr & USART_ISR_FE) != 0 && (cr3 & USART_CR3_EIE) != 0){
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_FECF);
	}
	if((isr & USART_ISR_NE) != 0 && (cr3 & USART_CR3_EIE) != 0){
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_NCF);
	}
	if((isr & USART_ISR_ORE) != 0 && (cr3 & USART_CR3_EIE) != 0){
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_ORECF);
	}
	if ((cr1 & USART_CR1_RXNEIE) != 0 && (isr & USART_ISR_RXNE) != 0)
	{
		return 1;
	}
	return 0;
}

void
sio_usart_isr(intptr_t exinf)
{
	SIOPCB *p_siopcb = get_siopcb(exinf);
	if (sio_getready(p_siopcb)) {
		sio_irdy_rcv(p_siopcb->exinf);
	}
	if (sio_putready(p_siopcb)) {
		sio_irdy_snd(p_siopcb->exinf);
	}
}

/*
 *  シリアルI/Oポートへの文字送信
 */
bool_t
sio_snd_chr(SIOPCB *p_siopcb, char c)
{
	uint32_t base = p_siopcb->p_siopinib->base;

	if (sio_putready(p_siopcb)) {
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_TDR), (uint32_t)c);
		return true;
	}
	return false;
}

/*
 *  シリアルI/Oポートからの文字受信
 */
int_t
sio_rcv_chr(SIOPCB *p_siopcb)
{
	uint32_t base = p_siopcb->p_siopinib->base;
	int_t c = -1;

	if (sio_getready(p_siopcb)) {
		c = sil_rew_mem((uint32_t *)(base+TOFF_USART_RDR)) & 0xFF;
	}
	return c;
}

/*
 *  シリアルI/Oポートからのコールバックの許可
 */
void
sio_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint32_t base = p_siopcb->p_siopinib->base;

	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) | USART_CR1_TXEIE);
		break;
	case SIO_RDY_RCV:
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) | USART_CR1_RXNEIE);
		break;
	}
}

/*
 *  シリアルI/Oポートからのコールバックの禁止
 */
void
sio_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint32_t base = p_siopcb->p_siopinib->base;

	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~USART_CR1_TXEIE);
		break;
	case SIO_RDY_RCV:
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~USART_CR1_RXNEIE);
		break;
	}
}

/*
 *  1文字出力（ポーリングでの出力）
 */
void sio_pol_snd_chr(int8_t c, ID siopid)
{
	uint32_t base = siopinib_table[INDEX_PORT(siopid)].base;

	sil_wrw_mem((uint32_t *)(base+TOFF_USART_TDR), (uint32_t)c);
	while(0 == (sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & USART_ISR_TXE));

	/*
	 *  出力が完全に終わるまで待つ
	 */
	volatile int n = 300000000/BPS_SETTING;
	while(n--);
}

/*
 *  ターゲットのシリアル初期化
 */
void chip_uart_init(ID siopid)
{
	const GPIOINIB  *p_gpioinib = &gpioinib_table[INDEX_PORT(siopid)];
	const SIOPINIB  *p_siopinib = &siopinib_table[INDEX_PORT(siopid)];
	uint32_t base, txbase, rxbase, tmp;

	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;
	base = p_siopinib->base;

	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~USART_CR1_UE);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), 0x0);
	tmp = sil_rew_mem((uint32_t *)p_gpioinib->resetbase);
	sil_wrw_mem((uint32_t *)p_gpioinib->resetbase, tmp | p_gpioinib->reset_set);
	sil_wrw_mem((uint32_t *)p_gpioinib->resetbase, tmp & ~(p_gpioinib->reset_set));

	if(p_siopinib->clock_shift == 0){	/* USART1の場合、SYSLOCKを設定 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2),
			(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2)) & RCC_DCKCFGR2_USART1SEL) | RCC_DCKCFGR2_USART1SEL_0);
	}
	else if(p_siopinib->clock_shift == 10){	/* F723/USART6の場合、SYSLOCKを設定 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2),
			(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2)) & RCC_DCKCFGR2_USART6SEL) | RCC_DCKCFGR2_USART6SEL_0);
	}

	sil_wrw_mem((uint32_t *)p_gpioinib->clockbase, sil_rew_mem((uint32_t *)p_gpioinib->clockbase) | p_gpioinib->clock_set);
	sil_wrw_mem((uint32_t *)p_gpioinib->portbase, sil_rew_mem((uint32_t *)p_gpioinib->portbase) | p_gpioinib->txport_set);
	sil_wrw_mem((uint32_t *)p_gpioinib->portbase, sil_rew_mem((uint32_t *)p_gpioinib->portbase) | p_gpioinib->rxport_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_MODER)) & p_gpioinib->txmode_msk) | p_gpioinib->txmode_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR)) & p_gpioinib->txspeed_msk) | p_gpioinib->txspeed_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER)) & p_gpioinib->txtype_msk) | p_gpioinib->txtype_set);
	sil_wrw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR)) & p_gpioinib->txpupd_msk) | p_gpioinib->txpupd_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), (sil_rew_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER)) & p_gpioinib->rxmode_msk) | p_gpioinib->rxmode_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), (sil_rew_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR)) & p_gpioinib->rxspeed_msk) | p_gpioinib->rxspeed_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), (sil_rew_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER)) & p_gpioinib->rxtype_msk) | p_gpioinib->rxtype_set);
	sil_wrw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), (sil_rew_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR)) & p_gpioinib->rxpupd_msk) | p_gpioinib->rxpupd_set);
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	tmp = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR2)) & ~USART_CR2_STOP;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), tmp | USART_StopBits_1);
	tmp = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & ~CR1_CLEAR_MASK;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), tmp | USART_WordLength_8b | USART_Parity_No | USART_CR1_RE | USART_CR1_TE);
	tmp = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3)) & ~CR3_CLEAR_MASK;
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), tmp | USART_HardwareFlowControl_None);

	switch((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2)) >> p_siopinib->clock_shift) & 3){
	case SOURCE_HSI:
		tmp = HSI_VALUE;
		break;
	case SOURCE_SYSCLK:
		tmp = SysFreHCLK;
		break;
	case SOURCE_LSE:
		tmp = LSE_VALUE;
		break;
	case SOURCE_PCLK2:
	default:
		if(p_siopinib->clock_shift == 10)	/* USART6,1の場合 PCLK2 */
			tmp = SysFrePCLK2;
		else
			tmp = SysFrePCLK1;
		break;
	}
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), tmp/BPS_SETTING);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) | USART_CR1_UE);
}

