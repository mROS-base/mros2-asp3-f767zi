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

extern int sample_lwip_scene1(void);
/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);
	MX_LWIP_Init();
	ena_int(77);
	dev_timer_init();
	osThreadNew((void *)(sample_lwip_scene1), NULL, NULL);
  
	while(true){
		tslp_tsk(100);
		(void)NVIC_GetPriority(ETH_IRQn);
	}
	SVC_PERROR(serial_ctl_por(TASK_PORTID,
							(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));
	ext_tsk();
}


void  dev_timer_init( void )
{

  /* set clock enable */
  RCC->APB1ENR |= ( RCC_APB1ENR_TIM2EN
                  ) ;

  /* counter disable */
  TIM2->CR1 &= ~TIM_CR1_CEN;

  /* clk/4, Auto-reload preload enable, downcounter, Update request source */
  TIM2->CR1  =  TIM_CR1_CKD_1 | TIM_CR1_ARPE | TIM_CR1_DIR | TIM_CR1_URS;
  TIM2->DIER =  TIM_DIER_UIE;
  TIM2->EGR  =  TIM_EGR_UG;

  TIM2->PSC = 10-1;

  /*  45000/9000000 = 1/200   ->   5msec */
  /*   9000/9000000 = 1/1000  ->   1msec */
  /*    900/9000000 = 1/10000 -> 100usec */
  TIM2->ARR = 900;
  TIM2->CNT = 900;

  TIM2->SR &= ~TIM_SR_UIF;
  TIM2->SR &= ~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF);

  TIM2->CR1 |=  TIM_CR1_CEN;   /* counter enable */

}


unsigned short int  dev_timer_clr_int( void )
{
  TIM2->SR &= ~TIM_SR_UIF; /* clear update interrupt */

  return  0;
}

void  main_timer_handler(void *p_excinf)
{
  (void)dev_timer_clr_int();
}

