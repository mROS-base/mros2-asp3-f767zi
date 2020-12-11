#include "atk2ext_common.h"
#include "atk2ext_asp_config.h"

static uint8_t      sus_all_cnt = 0U;
static uint8_t      sus_os_cnt = 0U;
static SIL_PRE_LOC;

StatusType GetTaskID(TaskRefType TaskID)
{
	ID tskid;
	ER ercd = get_tid(&tskid);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_CALLEVEL;
	}
	*TaskID = tskid;
	return E_OK;
}
StatusType ActivateTask(TaskType TaskID)
{
	ER ercd = act_tsk((ID)TaskID);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_ID;
	}
	return E_OK;
}
StatusType TerminateTask(void)
{
	ext_tsk();
	return E_OK;
}

StatusType SetEvent(TaskType TaskID, EventMaskType Mask)
{
	ID flgid;
	ER ercd = Atk2ExtTask2EventFlag(TaskID, &flgid);

	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d taskid=%d err=%d", __FUNCTION__, __LINE__, TaskID, ercd);
		return ercd;
	}


	if (CurrentContextIsISR()) {
		ercd = iset_flg(flgid, (FLGPTN)Mask);
	}
	else{
		ercd = set_flg(flgid, (FLGPTN)Mask);
	}

	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_ID;
	}
	return E_OK;
}

StatusType ClearEvent(EventMaskType Mask)
{
	ID flgid;
	ID tskid;
	ER ercd = get_tid(&tskid);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_CALLEVEL;
	}
	ercd = Atk2ExtTask2EventFlag(tskid, &flgid);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return ercd;
	}
	ercd = clr_flg(flgid, ~((FLGPTN)Mask));
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_ID;
	}
	return E_OK;
}

StatusType WaitEvent(EventMaskType Mask)
{
	ID flgid;
	ID tskid;
	FLGPTN flgptn;
	ER ercd = get_tid(&tskid);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_CALLEVEL;
	}
	ercd = Atk2ExtTask2EventFlag(tskid, &flgid);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return ercd;
	}
	ercd = wai_flg(flgid, (FLGPTN)Mask, TWF_ORW, &flgptn);
	if (ercd != E_OK) {
		syslog(LOG_NOTICE, "%s() %d err=%d", __FUNCTION__, __LINE__, ercd);
		return E_OS_ID;
	}
	return E_OK;
}
void ResumeAllInterrupts(void)
{
	sus_all_cnt--;
	if (sus_all_cnt == 0) {
		SIL_UNL_INT();
	}
	return;
}

void SuspendAllInterrupts(void)
{
	if (sus_all_cnt == 0) {
		SIL_LOC_INT();
	}
	sus_all_cnt++;
	return;
}

void ResumeOSInterrupts(void)
{
	sus_os_cnt--;
	if (sus_os_cnt == 0) {
		unl_cpu();
	}
	return;
}

void SuspendOSInterrupts(void)
{
	if (sus_os_cnt == 0) {
		loc_cpu();
	}
	sus_os_cnt++;
	return;
}

ALARMCALLBACK(Atk2ExtCyclicHandler)
{
	iact_tsk(Atk2ExtCyclicTask);
	return;
}

bool_t CurrentContextIsISR(void)
{
	return sns_ctx();
}
