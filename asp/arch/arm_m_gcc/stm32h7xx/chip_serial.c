/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by 3rd Designing Center
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
 *  @(#) $Id: chip_serial.c 698 2019-07-24 18:19:58Z roi $
 */

/*
 *  シリアルI/Oデバイス（SIO）ドライバ（stm32h7xx用）
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_stddef.h"
#include "target_serial.h"
#include "target_syssvc.h"

/*
 *  SIL関数のマクロ定義
 */
#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

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
#define SOURCE_PCLK         0x00000000
#define SOURCE_PLL2         0x00000001
#define SOURCE_PLL3         0x00000002
#define SOURCE_HSI          0x00000003
#define SOURCE_CSI          0x00000004
#define SOURCE_LSE          0x00000005

/*
 *  プレスケール設定
 */
#define UART_PRESCALER_DIV1 0x00000000				/* fclk_pres = fclk */

/*
 *  ビット長パラメータ
 */
#define UART_WordLength_7B  USART_CR1_M_1
#define UART_WordLength_8b  0x00000000
#define UART_WordLength_9b  USART_CR1_M

/*
 *  ストップビットパラメータ
 */ 
#define UART_StopBits_1     0x00000000
#define UART_StopBits_0_5   USART_CR2_STOP_0
#define UART_StopBits_2     USART_CR2_STOP_1
#define UART_StopBits_1_5   USART_CR2_STOP

/*
 *  パリティパラメータ
 */
#define UART_Parity_No      0x00000000
#define UART_Parity_Even    USART_CR1_PCE
#define UART_Parity_Odd     (USART_CR1_PCE | USART_CR1_PS) 

/*
 *  ハードウェアフロー制御パラメータ
 */
#define USART_HardwareFlowControl_None       0x00000000
#define USART_HardwareFlowControl_RTS        USART_CR3_RTSE
#define USART_HardwareFlowControl_CTS        USART_CR3_CTSE
#define USART_HardwareFlowControl_RTS_CTS    (USART_CR3_RTSE | USART_CR3_CTSE)

/*
 *  UART転送モード
 */
#define UART_MODE_RX        USART_CR1_RE			/* RX mode */
#define UART_MODE_TX        USART_CR1_TE			/* TX mode */
#define UART_MODE_TX_RX     (USART_CR1_TE |USART_CR1_RE)	/* RX and TX mode */


#define ISR_ACK             (USART_ISR_TEACK | USART_ISR_REACK)

#define LPUART_BRR_MIN      0x00000300U	/* LPUART BRR minimum authorized value */
#define LPUART_BRR_MAX      0x000FFFFFU	/* LPUART BRR maximum authorized value */

/*
 *  RXFIFOスレッシュホールド設定値
 */
#define UART_TXFIFO_THRESHOLD_1_8   0x00000000									/* TXFIFO reaches 1/8 of its depth */
#define UART_TXFIFO_THRESHOLD_1_4   USART_CR3_TXFTCFG_0							/* TXFIFO reaches 1/4 of its depth */
#define UART_TXFIFO_THRESHOLD_1_2   USART_CR3_TXFTCFG_1							/* TXFIFO reaches 1/2 of its depth */
#define UART_TXFIFO_THRESHOLD_3_4   (USART_CR3_TXFTCFG_0|USART_CR3_TXFTCFG_1)	/* TXFIFO reaches 3/4 of its depth */
#define UART_TXFIFO_THRESHOLD_7_8   USART_CR3_TXFTCFG_2							/* TXFIFO reaches 7/8 of its depth */
#define UART_TXFIFO_THRESHOLD_8_8   (USART_CR3_TXFTCFG_2|USART_CR3_TXFTCFG_0)	/* TXFIFO becomes empty            */

/*
 *  RXFIFOスレッシュホールド設定値
 */
#define UART_RXFIFO_THRESHOLD_1_8   0x00000000									/* RXFIFO FIFO reaches 1/8 of its depth */
#define UART_RXFIFO_THRESHOLD_1_4   USART_CR3_RXFTCFG_0							/* RXFIFO FIFO reaches 1/4 of its depth */
#define UART_RXFIFO_THRESHOLD_1_2   USART_CR3_RXFTCFG_1							/* RXFIFO FIFO reaches 1/2 of its depth */
#define UART_RXFIFO_THRESHOLD_3_4   (USART_CR3_RXFTCFG_0|USART_CR3_RXFTCFG_1)	/* RXFIFO FIFO reaches 3/4 of its depth */
#define UART_RXFIFO_THRESHOLD_7_8   USART_CR3_RXFTCFG_2							/* RXFIFO FIFO reaches 7/8 of its depth */
#define UART_RXFIFO_THRESHOLD_8_8   (USART_CR3_RXFTCFG_2|USART_CR3_RXFTCFG_0)	/* RXFIFO FIFO becomes full             */


#define UART_CR1_FIELDS     ((uint32_t)(USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | \
                            	USART_CR1_TE | USART_CR1_RE | USART_CR1_OVER8 | USART_CR1_FIFOEN))

#define UART_CR3_FIELDS     ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE | USART_CR3_ONEBIT| \
                            	USART_CR3_TXFTCFG | USART_CR3_RXFTCFG ))

#define UART_TIMEOUT_VALUE  0x1FFFFFF

/*
 *  シリアルI/Oポート初期化ブロックの定義
 */
typedef struct sio_port_initialization_block {
	uint32_t base;
	INTNO    intno_usart;
	uint32_t clock_offset;
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
	uint32_t rxportbase;
	uint32_t rxpinport;
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
	{(uint32_t)USART1_BASE, (INTNO)INTNO_SIO1, TOFF_U1_CLOCK, U1_CLOCK_SHIFT}
#if TNUM_SIOP > 1
   ,{(uint32_t)USART2_BASE, (INTNO)INTNO_SIO2, TOFF_U2_CLOCK, U2_CLOCK_SHIFT}
#endif
};

/*
 * 兼用GPIOポート初期化ブロック
 */
const GPIOINIB gpioinib_table[TNUM_SIOP] = {
	{(uint32_t)(TADR_RCC_BASE+TOFF_U1_APBNER), (uint32_t)ENABLE_U1_PORT,
     (uint32_t)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), (uint32_t)ENABLE_U1T_GPIO, (uint32_t)ENABLE_U1R_GPIO,
     (uint32_t)(TADR_RCC_BASE+TOFF_U1_APBRSTR), (uint32_t)RESET_U1_PORT,
	 (uint32_t)GPIO_U1_AF,
     (uint32_t)TADR_U1T_GPIO_BASE, (uint32_t)TX1_PINPOS,
     (uint32_t)TADR_U1R_GPIO_BASE, (uint32_t)RX1_PINPOS,
    }
#if TNUM_SIOP > 1
   ,{(uint32_t)(TADR_RCC_BASE+TOFF_U2_APBNER), (uint32_t)ENABLE_U2_PORT,
     (uint32_t)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), (uint32_t)ENABLE_U2T_GPIO, (uint32_t)ENABLE_U2R_GPIO,
     (uint32_t)(TADR_RCC_BASE+TOFF_U2_APBRSTR), (uint32_t)RESET_U2_PORT,
	 (uint32_t)GPIO_U2_AF,
     (uint32_t)TADR_U2T_GPIO_BASE, (uint32_t)TX2_PINPOS,
     (uint32_t)TADR_U2R_GPIO_BASE, (uint32_t)RX2_PINPOS,
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

#if 1
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
#endif

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
	uint32_t base, txbase, rxbase, tick, n, tmp;

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
	 *  USART/GPIOクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), p_gpioinib->txport_set);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR));
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), p_gpioinib->rxport_set);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR));

	/*
	 *  USART/LPUART/UARTクロック設定
	 */
	sil_orw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);
	tmp = sil_rew_mem((uint32_t *)p_gpioinib->clockbase);

	/*
	 *  TX-GPIO設定
	 */
	n = p_gpioinib->txpinport;
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), (GPIO_MODER_MODER0 << (n * 2)), (GPIO_MODE_AF << (n * 2)));
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), (GPIO_OSPEEDER_OSPEEDR0 << (n * 2)), (GPIO_SPEED_HIGH << (n * 2)));
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), (1 << n), (GPIO_OTYPE_PP << n));
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), (GPIO_PUPDR_PUPDR0 << (n * 2)), ((GPIO_PULLUP) << (n * 2)));
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);

	/*
	 *  RX-GPIO設定
	 */
	n = p_gpioinib->rxpinport;
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), (GPIO_MODER_MODER0 << (n * 2)), (GPIO_MODE_AF << (n * 2)));
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), (GPIO_OSPEEDER_OSPEEDR0 << (n * 2)), (GPIO_SPEED_HIGH << (n * 2)));
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), (1 << n), (GPIO_OTYPE_PP << n));
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), (GPIO_PUPDR_PUPDR0 << (n * 2)), ((GPIO_PULLUP) << (n * 2)));
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	/*
	 *  UART無効化
	 */
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), 0x0);
	sil_orw_mem((uint32_t *)p_gpioinib->resetbase, p_gpioinib->reset_set);
	sil_andw_mem((uint32_t *)p_gpioinib->resetbase, p_gpioinib->reset_set);
	tmp = sil_rew_mem((uint32_t *)p_gpioinib->resetbase);

	/*
	 *  USART データ長、パリティ、通信モード設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR1), UART_CR1_FIELDS, (UART_WordLength_8b | UART_Parity_No | UART_MODE_TX_RX));

	/*
	 *  USART STOPビット設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR2), USART_CR2_STOP, UART_StopBits_1);

	/*
	 *  USART フロー制御設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), UART_CR3_FIELDS, USART_HardwareFlowControl_None);

	/*
	 *  プレスケーラー設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_PRESC), USART_PRESC_PRESCALER, UART_PRESCALER_DIV1);

	switch((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+p_siopinib->clock_offset)) >> p_siopinib->clock_shift) & 7){
	case SOURCE_HSI:
		tmp = HSI_VALUE;
		break;
	case SOURCE_LSE:
		tmp = LSE_VALUE;
		break;
	case SOURCE_CSI:
		tmp = CSI_VALUE;
		break;
	case SOURCE_PCLK:
	default:
		if(base == TADR_LPUART1_BASE)
			tmp = SysFreD3PCLK1;
		else if(p_siopinib->clock_shift == 3)	/* USART6,1の場合 PCLK2 */
			tmp = SysFrePCLK2;
		else
			tmp = SysFrePCLK1;
		break;
	}
	if(base == TADR_LPUART1_BASE){
		uint32_t usartdiv = ((((uint64_t)tmp)*256) + (BPS_SETTING/2)) / BPS_SETTING;

        /*
		 *  BRR最大、最小チェック
		 */
        if(usartdiv < LPUART_BRR_MIN)
			usartdiv = LPUART_BRR_MIN;
		else if(usartdiv > LPUART_BRR_MAX)
			usartdiv = LPUART_BRR_MAX;
		tmp = usartdiv;
	}
	else if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_OVER8) != 0){
		uint32_t usartdiv = ((tmp/2) + (BPS_SETTING/2)) / BPS_SETTING;
		tmp = usartdiv & 0xFFF0U;
		tmp |= (unsigned short)((usartdiv & 0x0000000F) >> 1);
	}
	else{
		tmp = (tmp + (BPS_SETTING/2)) / BPS_SETTING;
	}
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), tmp);

	/*
	 *  FIFO設定処理
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_TXFTCFG, UART_TXFIFO_THRESHOLD_1_8);
#ifdef USE_USART_FIFO
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTCFG, UART_RXFIFO_THRESHOLD_8_8);
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#else
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTCFG, UART_RXFIFO_THRESHOLD_1_8);
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#endif

	/* In asynchronous mode, the following bits must be kept cleared:
	- LINEN and CLKEN bits in the USART_CR2 register,
	- SCEN, HDSEL and IREN  bits in the USART_CR3 register.*/
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR2), (USART_CR2_LINEN | USART_CR2_CLKEN));
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

    /*
	 *  USART 有効化
	 */
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);

	/*
	 * RX/TX ACKがセットされるまで待つ
	 */
	tick = 0;
    while((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & ISR_ACK) != ISR_ACK){
		/* Check for the Timeout */
		if(tick++ >=  UART_TIMEOUT_VALUE){
			/* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts for the interrupt process */
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), (USART_CR1_TXEIE | USART_CR1_RXNEIE | USART_CR1_PEIE));
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_EIE);
			goto sio_opn_exit;
		}
		sil_dly_nse(1000);
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
sio_putiready(SIOPCB* p_siopcb)
{
	uint32_t cr1 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR));
	uint32_t cr3 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3));

	if (((cr1 & USART_CR1_TXEIE_TXFNFIE) != 0 && (isr & USART_ISR_TC) != 0) || (cr3 & USART_CR3_TXFTIE) != 0) {
		return 1;
	}
	return 0;
}

Inline bool_t
sio_getiready(SIOPCB* p_siopcb)
{
	uint32_t cr1 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR));
	uint32_t cr3 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3));
	uint16_t temp;

	if((isr & (USART_ISR_ORE | USART_ISR_NE | USART_ISR_FE | USART_ISR_PE)) != 0) {
		temp = 0;
		sil_dly_nse(100*1000);
		syslog_2(LOG_INFO, "sio_usart_isr error (%d) isr[%04x] !", p_siopcb->p_siopinib->intno_usart, isr);
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3), USART_CR3_EIE);
		temp = sil_reh_mem((uint16_t *)(p_siopcb->p_siopinib->base+TOFF_USART_RDR));
		(void)(temp);
		return 0;
	}
	if(((cr1 & USART_CR1_RXNEIE_RXFNEIE) != 0 && (isr & USART_ISR_RXNE_RXFNE) != 0) || (cr3 & USART_CR3_RXFTIE) != 0) {
		return 1;
	}
	return 0;
}

void
sio_usart_isr(intptr_t exinf)
{
	SIOPCB *p_siopcb = get_siopcb(exinf);
	if (sio_getiready(p_siopcb)) {
		sio_irdy_rcv(p_siopcb->exinf);
	}
	if (sio_putiready(p_siopcb)) {
		sio_irdy_snd(p_siopcb->exinf);
	}
}

Inline bool_t
sio_putready(SIOPCB* p_siopcb)
{
#ifdef USE_USART_FIFO
	while ((sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR)) & USART_ISR_TXE_TXFNF) == 0);
#else
	while ((sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR)) & USART_ISR_TC) == 0);
#endif
	return 1;
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
	return sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_RDR)) & 0xFF;
}

/*
 *  シリアルI/Oポートからのコールバックの許可
 */
void
sio_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
#ifdef USE_USART_FIFO
		sil_orw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3), USART_CR3_TXFTIE);
#else
		sil_orw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_TXEIE_TXFNFIE);
#endif
		break;
	case SIO_RDY_RCV:
		sil_orw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_RXNEIE_RXFNEIE);
		break;
	}
}

/*
 *  シリアルI/Oポートからのコールバックの禁止
 */
void
sio_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_TXEIE_TXFNFIE);
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3), USART_CR3_TXFTIE);
		break;
	case SIO_RDY_RCV:
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_RXNEIE_RXFNEIE);
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
#ifdef USE_USART_FIFO
	while ((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & USART_ISR_TXE_TXFNF) == 0);
#else
	while ((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & USART_ISR_TC) == 0);
#endif

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
	uint32_t n, tick;

	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;
	base = p_siopinib->base;

	/*
	 *  USART/GPIOクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), p_gpioinib->txport_set);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR));
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR), p_gpioinib->rxport_set);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB4ENR));

	/*
	 *  USART/LPUART/UARTクロック設定
	 */
	sil_orw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);
	tmp = sil_rew_mem((uint32_t *)p_gpioinib->clockbase);

	/*
	 *  TX-GPIO設定
	 */
	n = p_gpioinib->txpinport;
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), (GPIO_MODER_MODER0 << (n * 2)), (GPIO_MODE_AF << (n * 2)));
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), (GPIO_OSPEEDER_OSPEEDR0 << (n * 2)), (GPIO_SPEED_HIGH << (n * 2)));
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), (1 << n), (GPIO_OTYPE_PP << n));
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), (GPIO_PUPDR_PUPDR0 << (n * 2)), ((GPIO_PULLUP) << (n * 2)));
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);

	/*
	 *  RX-GPIO設定
	 */
	n = p_gpioinib->rxpinport;
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), (GPIO_MODER_MODER0 << (n * 2)), (GPIO_MODE_AF << (n * 2)));
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), (GPIO_OSPEEDER_OSPEEDR0 << (n * 2)), (GPIO_SPEED_HIGH << (n * 2)));
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), (1 << n), (GPIO_OTYPE_PP << n));
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), (GPIO_PUPDR_PUPDR0 << (n * 2)), ((GPIO_PULLUP) << (n * 2)));
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	/*
	 *  UART無効化
	 */
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR1), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR2), 0x0);
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_CR3), 0x0);
	sil_orw_mem((uint32_t *)p_gpioinib->resetbase, p_gpioinib->reset_set);
	sil_andw_mem((uint32_t *)p_gpioinib->resetbase, p_gpioinib->reset_set);
	tmp = sil_rew_mem((uint32_t *)p_gpioinib->resetbase);

	/*
	 *  USART データ長、パリティ、通信モード設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR1), UART_CR1_FIELDS, (UART_WordLength_8b | UART_Parity_No | UART_MODE_TX_RX));

	/*
	 *  USART STOPビット設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR2), USART_CR2_STOP, UART_StopBits_1);

	/*
	 *  USART フロー制御設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), UART_CR3_FIELDS, USART_HardwareFlowControl_None);

	/*
	 *  プレスケーラー設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_PRESC), USART_PRESC_PRESCALER, UART_PRESCALER_DIV1);

	switch((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+p_siopinib->clock_offset)) >> p_siopinib->clock_shift) & 7){
	case SOURCE_HSI:
		tmp = HSI_VALUE;
		break;
	case SOURCE_LSE:
		tmp = LSE_VALUE;
		break;
	case SOURCE_CSI:
		tmp = CSI_VALUE;
		break;
	case SOURCE_PCLK:
	default:
		if(p_siopinib->clock_shift == 3)	/* USART6,1の場合 PCLK2 */
			tmp = SysFrePCLK2;
		else
			tmp = SysFrePCLK1;
	}
	if(base == TADR_LPUART1_BASE){
		uint64_t usartdiv = ((tmp*256) + (BPS_SETTING/2)) / BPS_SETTING;

        /*
		 *  BRR最大、最小チェック
		 */
 		if(usartdiv < LPUART_BRR_MIN)
			usartdiv = LPUART_BRR_MIN;
		else if(usartdiv > LPUART_BRR_MAX)
			usartdiv = LPUART_BRR_MAX;
		tmp = usartdiv;
	}
	else if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_OVER8) != 0){
		uint32_t usartdiv = ((tmp/2) + (BPS_SETTING/2)) / BPS_SETTING;
		tmp = usartdiv & 0xFFF0U;
		tmp |= (unsigned short)((usartdiv & 0x0000000F) >> 1);
	}
	else{
		tmp = (tmp + (BPS_SETTING/2)) / BPS_SETTING;
	}
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), tmp);

	/*
	 *  FIFO設定処理
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_TXFTCFG, UART_TXFIFO_THRESHOLD_1_8);
#ifdef USE_USART_FIFO
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTCFG, UART_RXFIFO_THRESHOLD_8_8);
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#else
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTCFG, UART_RXFIFO_THRESHOLD_1_8);
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#endif


	/* In asynchronous mode, the following bits must be kept cleared:
	- LINEN and CLKEN bits in the USART_CR2 register,
	- SCEN, HDSEL and IREN  bits in the USART_CR3 register.*/
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR2), (USART_CR2_LINEN | USART_CR2_CLKEN));
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

    /*
	 *  USART 有効化
	 */
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);

	/*
	 * RX/TX ACKがセットされるまで待つ
	 */
	tick = 0;
    while((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & ISR_ACK) != ISR_ACK){
		/* Check for the Timeout */
		if(tick++ >=  UART_TIMEOUT_VALUE){
			/* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts for the interrupt process */
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), (USART_CR1_TXEIE | USART_CR1_RXNEIE | USART_CR1_PEIE));
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_EIE);
			return;
		}
		sil_dly_nse(1000);
	}
}

