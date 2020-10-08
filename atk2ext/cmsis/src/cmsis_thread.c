#include "cmsis_os.h"
#include "atk2ext_common.h"
#include "atk2ext_config.h"

osThreadId_t osThreadNew(osThreadFunc_t	func, void *argument, const osThreadAttr_t *attr)
{
	TaskType taskID;
	StatusType ercd;

	ercd = Atk2TaskConfigSet(func, argument);
	if (ercd != E_OK) {
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
		return osErrorParameter;
	}
	if (thread_id != NULL) {
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
	if ((thread_def == NULL) || (thread_def->pthread == NULL)) {
		return NULL;
	}
	return osThreadNew((osThreadFunc_t)thread_def->pthread, argument, NULL);
}
