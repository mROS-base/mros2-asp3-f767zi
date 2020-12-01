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
		CMSIS_ERROR("ERROR:%s %s() %d attr must be null\n", __FILE__, __FUNCTION__, __LINE__);
		return NULL;
	}
	semp = (CmsisSemType *)Atk2MemoryAlloc(sizeof(CmsisSemType));
	if (semp == NULL) {
		CMSIS_ERROR("ERROR:%s %s() %d cannot allocate memory size=%d\n", __FILE__, __FUNCTION__, __LINE__, sizeof(CmsisSemType));
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
	osStatus_t err;
	StatusType ercd;
	bool_t is_ctx_isr = CurrentContextIsISR();

	if (semaphore_id == NULL) {
		return osErrorParameter;
	}
	semp = (CmsisSemType*)semaphore_id;
	if (semp->magicno != ATK2SEM_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	if (!is_ctx_isr) {
		ercd = GetTaskID(&taskID);
		if (ercd != E_OK) {
			return osErrorResource;
		}
	}
	else {
		if (timeout != 0) {
			return osErrorResource;
		}
	}

	SuspendOSInterrupts();
	err = osSemaphoreAcquire_nolock(semp, timeout, taskID);
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
		CMSIS_ERROR("ERROR:%s %s() %d semaphore_id is invalid value(0x%x)\n", __FILE__, __FUNCTION__, __LINE__, semaphore_id);
		return osErrorParameter;
	}
	semp = (CmsisSemType*)semaphore_id;
	if (semp->magicno != ATK2SEM_HEAD_MAGICNO) {
		CMSIS_ERROR("ERROR:%s %s() %d invalid magicno(0x%x)\n", __FILE__, __FUNCTION__, __LINE__, semp->magicno);
		return osErrorParameter;
	}
	SuspendOSInterrupts();
	if (semp->waiting.count == 0) {
		semp->magicno = 0;
		Atk2MemoryFree(semp);
	}
	else {
		err = osErrorResource;
	}
	ResumeOSInterrupts();
	return err;
}

osStatus_t osSemaphoreAcquire_nolock(CmsisSemType *semp, uint32_t timeout, TaskType taskID)
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
		CMSIS_ERROR("ERROR:%s %s() %d semaphore_def should not be null\n", __FILE__, __FUNCTION__, __LINE__);
		return NULL;
	}
	return (osSemaphoreId)osSemaphoreNew(count, count, NULL);
}

int32_t osSemaphoreWait(osSemaphoreId semaphore_id, uint32_t millisec)
{
	CmsisSemType *semp = (CmsisSemType*)semaphore_id;
	TaskType taskID;
	osStatus_t err;
	StatusType ercd;
	bool_t is_ctx_isr = CurrentContextIsISR();

	if (is_ctx_isr) {
		return -1;
	}
	if (semaphore_id == NULL) {
		return -1;
	}
	semp = (CmsisSemType*)semaphore_id;
	if (semp->magicno != ATK2SEM_HEAD_MAGICNO) {
		return -1;
	}
	ercd = GetTaskID(&taskID);
	if (ercd != E_OK) {
		return -1;
	}

	SuspendOSInterrupts();
	err = osSemaphoreAcquire_nolock(semp, millisec, taskID);
	ResumeOSInterrupts();
	if (err != osOK) {
		return 0;
	}
	/*
	 * Specification says:
	 *  return value number of available tokens, and 0 means no semaphore was available.
	 *
	 * Available tokens must be the value before decrementing,
	 * because user can not determine acquiring the token when previous value was 1.
	 *
	 * see following situation:
	 *  previous value          : 1 , 0
	 *  before decrementing case: 1 , 0
	 *  after decrementing case : 0 , 0 <--- same value(user can not determine acquiring)
	 *
	 *  ref:
	 *   https://github.com/ARMmbed/mbed-os/issues/4456
	 */
	return (int32_t)(semp->count + 1);
}
