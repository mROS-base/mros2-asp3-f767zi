#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "lwip.h"
#include "sample1.h"
#include "stm32f7xx_hal.h"

UART_HandleTypeDef huart3;
ETH_HandleTypeDef heth;

/*
 *  サービスコールのエラーのログ出力
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))


/*
 *  メインタスク
 */

void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
	syslog(LOG_NOTICE,"recv: %s", p->payload);
	pbuf_free(p);		// Free the p buffer

   //udp_transmit(upcb, addr, udp2_tx_data, udp2_tx_len);
}

void main_task(intptr_t exinf)
{
	ER ercd;

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);
	MX_LWIP_Init();
	/*
	 *  シリアルポートの初期化
	 *
	 *  システムログタスクと同じシリアルポートを使う場合など，シリアル
	 *  ポートがオープン済みの場合にはここでE_OBJエラーになるが，支障は
	 *  ない．
	 */
	/*
	ercd = serial_opn_por(TASK_PORTID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ) {
		syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
									itron_strerror(ercd), SERCD(ercd));
	}
	*/
	struct udp_pcb *pcb;
	struct pbuf *p;
	err_t err;
	ip4_addr_t dst_addr;
	const unsigned short src_port = 12345;
	const unsigned short dst_port = 8080;
	//UDPパケット宛先IPアドレス
	IP4_ADDR(&dst_addr,192,168,11,3);

	pcb = udp_new();
	err = udp_bind(pcb, IP_ADDR_ANY, src_port);

	uint32_t cnt = 0;

	if (pcb)
	{
		err = udp_bind(pcb, IP_ADDR_ANY, 1234);

		if(err == ERR_OK)
		{
		udp_recv(pcb, udp_receive_callback, NULL);
		}
	}

	while(true){
		syslog(LOG_NOTICE, "send udp packet");
		p = pbuf_alloc(PBUF_TRANSPORT, sizeof(4), PBUF_RAM);
		*(uint32_t *)p->payload = cnt++;
		p->len = 4;
		err = udp_sendto(pcb, p, &dst_addr, dst_port);
		pbuf_free(p);
#ifdef MROS2_USE_ASP3
		tslp_tsk(1000000);
#else
		tslp_tsk(1000);
#endif
	}
	SVC_PERROR(serial_ctl_por(TASK_PORTID,
							(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));
	ext_tsk();
}

