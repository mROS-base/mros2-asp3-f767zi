#include "cmsis_os.h"
#include "cmsis_semaphores_private.h"
#include "cmsis_atk2_task_sync.h"
#include "cmsis_atk2_memory.h"

osSemaphoreId_t osSemaphoreNew(uint32_t max_count, uint32_t initial_count, const osSemaphoreAttr_t * attr)
{
	CmsisSemType *semp = NULL;

	if (CurrentContextIsISR()) {
		return NULL;
	}
	else if (attr != NULL) {
		//TODO ERRLOG
		return NULL;
	}
	semp = (CmsisSemType *)Atk2MemoryAlloc(sizeof(CmsisSemType));
	if (semp == NULL) {
		//TODO ERRLOG
		return NULL;
	}
	semp->count = initial_count;
	semp->max_count = max_count;
	semp->magicno = ATK2SEM_HEAD_MAGICNO;
	Atk2QueueHeadInit(&semp->waiting);
	return (osSemaphoreId_t)semp;
}


osStatus_t osSemaphoreAcquire(osSemaphoreId_t semaphore_id, uint32_t timeout)
{
	CmsisSemType *semp;
	TaskType taskID;
	osStatus_t err = osOK;
	bool_t is_ctx_isr = CurrentContextIsISR();

	if (semaphore_id == NULL) {
		return osErrorParameter;
	}
	semp = (CmsisSemType*)semaphore_id;
	if (semp->magicno != ATK2SEM_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	(void)GetTaskID(&taskID);

	SuspendOSInterrupts();
	err = osSemaphoreAcquire_nolock(semp, timeout, taskID, is_ctx_isr);
	ResumeOSInterrupts();
	return err;
}

osStatus_t osSemaphoreRelease(osSemaphoreId_t semaphore_id)
{
	CmsisSemType *semp;
	osStatus_t err = osOK;

	if (semaphore_id == NULL) {
		return osErrorParameter;
	}
	semp = (CmsisSemType*)semaphore_id;
	if (semp->magicno != ATK2SEM_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	SuspendOSInterrupts();
	err = osSemaphoreRelease_nolock(semp);
	ResumeOSInterrupts();
	return err;
}
osStatus_t osSemaphoreDelete(osSemaphoreId_t semaphore_id)
{
	CmsisSemType *semp;
	osStatus_t err = osOK;

	if (CurrentContextIsISR()) {
		return osErrorISR;
	}
	else if (semaphore_id == NULL) {
		return osErrorParameter;
	}
	semp = (CmsisSemType*)semaphore_id;
	if (semp->magicno != ATK2SEM_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	SuspendOSInterrupts();
	if (semp->waiting.count == 0) {
		Atk2MemoryFree(semp);
	}
	else {
		err = osErrorResource;
	}
	ResumeOSInterrupts();
	return err;
}

osStatus_t osSemaphoreAcquire_nolock(CmsisSemType *semp, uint32_t timeout, TaskType taskID, bool_t is_ctx_isr)
{
	osStatus_t err = osOK;
	StatusType ercd;

	if (semp->count > 0) {
		semp->count--;
	}
	else {
		if (timeout == 0) {
			err = osErrorResource;
		}
		else if (is_ctx_isr) {
			err = osErrorResource;
		}
		else {
			if (timeout == osWaitForever) {
				timeout = ATK2_TASK_SYNC_WAIT_FOREVER;
			}
			(void)Atk2TaskSyncWait(&semp->waiting, timeout, &ercd, taskID);
			if (ercd != E_OK) {
				err = osErrorTimeout;
			}
		}
	}
	return err;
}

osStatus_t osSemaphoreRelease_nolock(CmsisSemType *semp)
{
	osStatus_t err = osOK;
	if (semp->waiting.count > 0) {
		(void)Atk2TaskSyncWakeupFirstEntry(&semp->waiting, NULL, E_OK);
	}
	else if (semp->count < semp->max_count) {
		semp->count++;
	}
	else {
		err = osErrorResource;
	}
	return err;
}


/*
 * Version 1
 */
osSemaphoreId osSemaphoreCreate(const osSemaphoreDef_t *semaphore_def, int32_t count)
{
	if (semaphore_def != NULL) {
		//TODO ERROR LOG
		return NULL;
	}
	return (osSemaphoreId)osSemaphoreNew(count, count, NULL);
}
