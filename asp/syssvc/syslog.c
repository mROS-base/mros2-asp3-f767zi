/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2015 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  $Id: syslog.c 2679 2015-07-31 10:16:55Z ertl-hiro $
 */

/*
 *		е╖е╣е╞ереэе░╡б╟╜
 */

#include <sil.h>
#undef TOPPERS_OMIT_SYSLOG
#include <t_syslog.h>
#include <log_output.h>
#include "target_syssvc.h"
#include "syslog.h"

/*
 *  е╚еьб╝е╣еэе░е▐епеэд╬е╟е╒ейеые╚─ъ╡┴
 */
#ifndef LOG_SYSLOG_WRI_LOG_ENTER
#define LOG_SYSLOG_WRI_LOG_ENTER(prio, p_syslog)
#endif /* LOG_SYSLOG_WRI_LOG_ENTER */

#ifndef LOG_SYSLOG_WRI_LOG_LEAVE
#define LOG_SYSLOG_WRI_LOG_LEAVE(ercd)
#endif /* LOG_SYSLOG_WRI_LOG_LEAVE */

#ifndef LOG_SYSLOG_REA_LOG_ENTER
#define LOG_SYSLOG_REA_LOG_ENTER(p_syslog)
#endif /* LOG_SYSLOG_REA_LOG_ENTER */

#ifndef LOG_SYSLOG_REA_LOG_LEAVE
#define LOG_SYSLOG_REA_LOG_LEAVE(ercd, p_syslog)
#endif /* LOG_SYSLOG_REA_LOG_LEAVE */

#ifndef LOG_SYSLOG_MSK_LOG_ENTER
#define LOG_SYSLOG_MSK_LOG_ENTER(logmask, lowmask)
#endif /* LOG_SYSLOG_MSK_LOG_ENTER */

#ifndef LOG_SYSLOG_MSK_LOG_LEAVE
#define LOG_SYSLOG_MSK_LOG_LEAVE(ercd)
#endif /* LOG_SYSLOG_MSK_LOG_LEAVE */

#ifndef LOG_SYSLOG_REF_LOG_ENTER
#define LOG_SYSLOG_REF_LOG_ENTER(pk_rlog)
#endif /* LOG_SYSLOG_REF_LOG_ENTER */

#ifndef LOG_SYSLOG_REF_LOG_LEAVE
#define LOG_SYSLOG_REF_LOG_LEAVE(ercd, pk_rlog)
#endif /* LOG_SYSLOG_REF_LOG_LEAVE */

/*
 *  ╕╜║▀д╬е╖е╣е╞ер╗■╣я
 *
 *  еэе░╗■╣ядЄ╝шдъ╜╨д╣д┐дсд╦бддфдрд╩дпбделб╝е═еыд╬╞т╔Ї╩╤┐ЇдЄ╗▓╛╚д╖д╞дд
 *  дыбе
 */
extern ulong_t	_kernel_current_time;

/*
 *  еэе░е╨е├е╒ебд╚д╜дьд╦евепе╗е╣д╣дыд┐дсд╬е▌едеєе┐
 */
static SYSLOG	syslog_buffer[TCNT_SYSLOG_BUFFER];	/* еэе░е╨е├е╒еб */
static uint_t	syslog_count;			/* еэе░е╨е├е╒еб├цд╬еэе░д╬┐Ї */
static uint_t	syslog_head;			/* └ш╞мд╬еэе░д╬│╩╟╝░╠├╓ */
static uint_t	syslog_tail;			/* ╝бд╬еэе░д╬│╩╟╝░╠├╓ */
static uint_t	syslog_lost;			/* ╝║дядьд┐еэе░д╬┐Ї */

/*
 *  ╜╨╬╧д╣д┘днеэе░╛Ё╩єд╬╜┼═╫┼┘б╩е╙е├е╚е▐е├е╫б╦
 */
static uint_t	syslog_logmask;			/* еэе░е╨е├е╒ебд╦╡н╧┐д╣д┘дн╜┼═╫┼┘ */
static uint_t	syslog_lowmask_not;		/* ─уеье┘еы╜╨╬╧д╣д┘дн╜┼═╫┼┘б╩╚┐┼╛б╦*/

/*
 *  е╖е╣е╞ереэе░╡б╟╜д╬╜щ┤№▓╜
 */
void
syslog_initialize(intptr_t exinf)
{
	syslog_count = 0U;
	syslog_head = 0U;
	syslog_tail = 0U;
	syslog_lost = 0U;
	syslog_logmask = 0U;
	syslog_lowmask_not = 0U;
}     

/* 
 *  еэе░╛Ё╩єд╬╜╨╬╧
 *
 *  CPUеэе├еп╛ї┬╓дф╝┬╣╘е│еєе╞ене╣е╚д╦дшдщд║╞░║юд╟дндыдшджд╦╝┬┴їд╖д╞двдыбе
 */
ER
syslog_wri_log(uint_t prio, const SYSLOG *p_syslog)
{
	SIL_PRE_LOC;

	LOG_SYSLOG_WRI_LOG_ENTER(prio, p_syslog);
	SIL_LOC_INT();

	/*
	 *  еэе░╗■╣яд╬└▀─ъ
	 */
	((SYSLOG *) p_syslog)->logtim = _kernel_current_time;

	/*
	 *  еэе░е╨е├е╒ебд╦╡н╧┐
	 */
	if ((syslog_logmask & LOG_MASK(prio)) != 0U) {
		syslog_buffer[syslog_tail] = *p_syslog;
		syslog_tail++;
		if (syslog_tail >= TCNT_SYSLOG_BUFFER) {
			syslog_tail = 0U;
		}
		if (syslog_count < TCNT_SYSLOG_BUFFER) {
			syslog_count++;
		}
		else {
			syslog_head = syslog_tail;
			syslog_lost++;
		}
	}

	/*
	 *  я┐╜я┐╜я┐╜┘ея┐╜я┐╜я┐╜я┐╜?
	 */
	if (true){//(((~syslog_lowmask_not) & LOG_MASK(prio)) != 0U) {
		syslog_print(p_syslog, target_fput_log);
		target_fput_log('\n');
	}

	SIL_UNL_INT();
	LOG_SYSLOG_WRI_LOG_LEAVE(E_OK);
	return(E_OK);
}

/*
 *  еэе░е╨е├е╒ебдлдщд╬╞╔╜╨д╖
 *
 *  CPUеэе├еп╛ї┬╓дф╝┬╣╘е│еєе╞ене╣е╚д╦дшдщд║╞░║юд╟дндыдшджд╦╝┬┴їд╖д╞двдыбе
 */
ER_UINT
syslog_rea_log(SYSLOG *p_syslog)
{
	ER_UINT	ercd;
	SIL_PRE_LOC;

	LOG_SYSLOG_REA_LOG_ENTER(p_syslog);
	SIL_LOC_INT();

	/*
	 *  еэе░е╨е├е╒ебдлдщд╬╝ш╜╨д╖
	 */
	if (syslog_count > 0U) {
		*p_syslog = syslog_buffer[syslog_head];
		syslog_count--;
		syslog_head++;
		if (syslog_head >= TCNT_SYSLOG_BUFFER) {
			syslog_head = 0U;
		}
		ercd = (ER_UINT) syslog_lost;
		syslog_lost = 0U;
	}
	else {
		ercd = E_OBJ;
	}

	SIL_UNL_INT();
	LOG_SYSLOG_REA_LOG_LEAVE(ercd, p_syslog);
	return(ercd);
}

/* 
 *  ╜╨╬╧д╣д┘днеэе░╛Ё╩єд╬╜┼═╫┼┘д╬└▀─ъ
 */
ER
syslog_msk_log(uint_t logmask, uint_t lowmask)
{
	LOG_SYSLOG_MSK_LOG_ENTER(logmask, lowmask);
	syslog_logmask = logmask;
	syslog_lowmask_not = ~lowmask;
	LOG_SYSLOG_MSK_LOG_LEAVE(E_OK);
	return(E_OK);
}

/*
 *  еэе░е╨е├е╒ебд╬╛ї┬╓╗▓╛╚
 */
ER
syslog_ref_log(T_SYSLOG_RLOG *pk_rlog)
{
	SIL_PRE_LOC;

	LOG_SYSLOG_REF_LOG_ENTER(pk_rlog);
	SIL_LOC_INT();

	pk_rlog->count = syslog_count;
	pk_rlog->lost = syslog_lost;
	pk_rlog->logmask = syslog_logmask;
	pk_rlog->lowmask = ~syslog_lowmask_not;

	SIL_UNL_INT();
	LOG_SYSLOG_REF_LOG_LEAVE(E_OK, pk_rlog);
	return(E_OK);
}
