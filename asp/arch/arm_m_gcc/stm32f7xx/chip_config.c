/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015      by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
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
 *  @(#) $Id: chip_config.c 698 2015-07-27 14:49:48Z roi $
 */

/*
 * е┐б╝е▓е├е╚░═┬╕ете╕ехб╝еыб╩stm32f7xx═╤б╦
 */
#include "stm32f7xx_hal.h"
#include "kernel_impl.h"
#include <sil.h>

#include "stm32f7xx.h"
#include "chip_serial.h"

/*
 *  е┐б╝е▓е├е╚░═┬╕д╬╜щ┤№▓╜
 */

extern UART_HandleTypeDef huart3;
const char char_return = '\r';

void
target_initialize(void){

	/*
	 * е│ев░═┬╕д╬╜щ┤№▓╜
	 */
	core_initialize();

	/*
	 *  е╨е╩б╝╜╨╬╧═╤д╬е╖еъевеы╜щ┤№▓╜
	 */
	chip_uart_init(SIO_PORTID);

	/*
	 *  е┐еде▐д╬│ф╣■д▀еье┘еыд╬└▀─ъ
	 */
	sil_wrb_mem((uint8_t *)(TADR_SCB_BASE+TOFF_SCB_SHP15), (14 << (8 - 4)) & 0xff);

	initUSART3();
} 

/*
 *  я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜├е╚░я┐╜┬╕я┐╜╬╜я┐╜╬╗я┐╜я┐╜я┐╜я┐╜
 */
void
target_exit(void)
{
	/*
	 *  я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜┬╕я┐╜╬╜я┐╜╬╗я┐╜я┐╜я┐╜я┐╜
	 */
	core_terminate();

	/*
	 *  я┐╜я┐╜╚пя┐╜─╢я┐╜я┐╜я┐╜┬╕я┐╜╬╜я┐╜╬╗я┐╜я┐╜я┐╜я┐╜
	 */
	while(1);
}


/*
 *  я┐╜я┐╜я┐╜я┐╜я┐╜╞ея┐╜я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜┘ея┐╜я┐╜я┐╜╧д╬дя┐╜я┐╜я┐╜я┐╜╩╕я┐╜я┐╜я┐╜я┐╜я┐╜я┐╜
 */
/*
void
target_fput_log(char c)
{
	if (c == '\n') {
		sio_pol_snd_chr('\r', SIO_PORTID);
	}
	sio_pol_snd_chr(c, SIO_PORTID);
}
*/
void target_fput_log(char c)
{
	if (c == '\n') {
		HAL_UART_Transmit(&huart3,(uint8_t *)&char_return, 1, 0xFFFF);
	}
	HAL_UART_Transmit(&huart3,(uint8_t *)&c, 1, 0xFFFF);
}

void initUSART3() 
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_USART3_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
	PeriphClkInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK){
		//Error_Handler();
	}

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart3) != HAL_OK)
	{
		//Error_Handler();
	}
}