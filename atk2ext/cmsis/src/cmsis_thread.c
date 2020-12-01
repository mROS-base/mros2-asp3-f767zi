#include "cmsis_os.h"
#include "atk2ext_common.h"
#include "atk2ext_sys_config.h"

osThreadId_t osThreadNew(osThreadFunc_t	func, void *argument, const osThreadAttr_t *attr)
{
	TaskType taskID;
	StatusType ercd;

	if (CurrentContextIsISR()) {
		return NULL;
	}
	ercd = Atk2TaskConfigSet(func, argument);
	if (ercd != E_OK) {
		CMSIS_ERROR("ERROR:%s %s() %d unrecognized func=0x%x\n", __FILE__, __FUNCTION__, __LINE__, func);
		return NULL;
	}
	ercd = Atk2TaskConfigGetTaskID(func, &taskID);
	if (ercd != E_OK) {
		return NULL;
	}
	ercd = ActivateTask(taskID);
	if (ercd != E_OK) {
		return NULL;
	}
	return (osThreadId_t)taskID;
}

osStatus_t osThreadTerminate(osThreadId_t thread_id)
{
	TaskType taskID;

	if (CurrentContextIsISR()) {
		return osErrorISR;
	}

	StatusType ercd = GetTaskID(&taskID);
	if (ercd != E_OK) {
		CMSIS_ERROR("ERROR:%s %s() %d GetTaskID() ercd =%d\n", __FILE__, __FUNCTION__, __LINE__, ercd);
		return osErrorParameter;
	}
	if (thread_id != NULL) {
		CMSIS_ERROR("ERROR:%s %s() %d thread_id must be NULL\n", __FILE__, __FUNCTION__, __LINE__);
		return osErrorParameter;
	}
	(void)TerminateTask();
	return E_OK;
}

/*
 * Version 1
 */
osThreadId osThreadCreate(const osThreadDef_t *thread_def, void *argument)
{
	if (thread_def == NULL) {
		CMSIS_ERROR("ERROR:%s %s() %d thread_def should not be NULL\n", __FILE__, __FUNCTION__, __LINE__);
		return NULL;
	}
	else if (thread_def->pthread == NULL) {
		CMSIS_ERROR("ERROR:%s %s() %d thread_def->pthread should not be NULL\n", __FILE__, __FUNCTION__, __LINE__);
	}
	return osThreadNew((osThreadFunc_t)thread_def->pthread, argument, NULL);
}
