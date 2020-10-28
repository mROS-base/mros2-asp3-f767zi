#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"
#include "stm32f7xx_hal.h"

UART_HandleTypeDef huart3;

/*
 *  ¥µ¡¼¥Ó¥¹¥³¡¼¥ë¤Î¥¨¥é¡¼¤Î¥í¥°½ÐÎÏ
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
 *  ¥á¥¤¥ó¥¿¥¹¥¯
 */
void main_task(intptr_t exinf)
{
	ER ercd;

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);

	/*
	 *  ï¿½ï¿½ï¿½ê¥¢ï¿½ï¿½Ý¡ï¿½ï¿½È¤Î½ï¿½ï¿½ï¿½ï¿½
	 *
	 *  ï¿½ï¿½ï¿½ï¿½ï¿½Æ¥ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½?ï¿½ï¿½Ý¡ï¿½ï¿½È¤ï¿½È¤ï¿½ï¿½ï¿½ï¿½Ê¤É¡ï¿½ï¿½ï¿½ï¿½ê¥¢ï¿½ï¿½
	 *  ï¿½Ý¡ï¿½ï¿½È¤ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½×¥ï¿½Ñ¤ß¤Î¾ï¿½ï¿½Ë¤Ï¤ï¿½ï¿½ï¿½ï¿½ï¿½?E_OBJï¿½ï¿½ï¿½é¡¼ï¿½Ë¤Ê¤ë¤¬ï¿½ï¿½ï¿½Ù¾ï¿½ï¿½?
	 *  ï¿½Ê¤ï¿½ï¿½ï¿½
	 */
	/*
	ercd = serial_opn_por(TASK_PORTID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ) {
		syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
									itron_strerror(ercd), SERCD(ercd));
	}
	*/
	SVC_PERROR(serial_ctl_por(TASK_PORTID,
							(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));
	while(true) {
		syslog(LOG_NOTICE, "hogehoge");
	}
	ext_tsk();
}
