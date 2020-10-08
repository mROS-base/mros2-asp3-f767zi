#include "cmsis_os.h"
#include "cmsis_atk2_memory.h"
#include "cmsis_semaphores_private.h"

#define ATK2MUTEX_HEAD_MAGICNO		0xDEADEEEB
typedef struct {
	TaskType			owner;
	uint32_t			count;
	uint32_t			magicno;
	osSemaphoreId_t		*sem;
	bool_t				is_recursive;
} CmsisMutexType;

osMutexId_t osMutexNew(const osMutexAttr_t *attr)
{
	CmsisMutexType *mutex = NULL;

	if (CurrentContextIsISR()) {
		return NULL;
	}
	mutex = (CmsisMutexType *)Atk2MemoryAlloc(sizeof(CmsisMutexType));
	if (mutex == NULL) {
		//TODO ERRLOG
		return NULL;
	}
	mutex->sem = osSemaphoreNew(1, 1, NULL);
	if (mutex->sem == NULL) {
		Atk2MemoryFree(mutex);
		//TODO ERRLOG
		return NULL;
	}
	mutex->magicno = ATK2MUTEX_HEAD_MAGICNO;
	mutex->owner = 0;
	mutex->count = 0;
	mutex->is_recursive = false;
	if (attr != NULL) {
		if ((attr->attr_bits & osMutexRecursive) != 0) {
			mutex->is_recursive = true;
		}
	}
	return (osMutexId_t)mutex;
}

osStatus_t osMutexAcquire(osMutexId_t mutex_id, uint32_t timeout)
{
	CmsisMutexType *mutex;
	TaskType taskID;
	osStatus_t err = osOK;
	bool_t is_ctx_isr = CurrentContextIsISR();

	if (mutex_id == NULL) {
		return osErrorParameter;
	}
	else if (is_ctx_isr) {
		return osErrorISR;
	}
	mutex = (CmsisMutexType*)mutex_id;
	if (mutex->magicno != ATK2MUTEX_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	(void)GetTaskID(&taskID);
	SuspendOSInterrupts();
	if ((mutex->is_recursive) && (mutex->count > 0) && (mutex->owner == taskID)) {
		mutex->count++;
	}
	else {
		err = osSemaphoreAcquire_nolock((CmsisSemType*)mutex->sem, timeout, taskID, is_ctx_isr);
		if (err == osOK) {
			mutex->owner = taskID;
			mutex->count = 1;
		}
	}
	ResumeOSInterrupts();
	return err;
}

osStatus_t osMutexRelease(osMutexId_t mutex_id)
{
	CmsisMutexType *mutex;
	TaskType taskID;
	osStatus_t err = osOK;
	bool_t is_ctx_isr = CurrentContextIsISR();

	if (mutex_id == NULL) {
		return osErrorParameter;
	}
	else if (is_ctx_isr) {
		return osErrorISR;
	}
	mutex = (CmsisMutexType*)mutex_id;
	if (mutex->magicno != ATK2MUTEX_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	(void)GetTaskID(&taskID);
	SuspendOSInterrupts();
	if (mutex->owner == taskID) {
		if ((mutex->is_recursive) && (mutex->count > 1)) {
			mutex->count--;
		}
		else {
			err = osSemaphoreRelease_nolock((CmsisSemType*)mutex->sem);
			if (err == osOK) {
				mutex->owner = 0;
				mutex->count = 0;
			}
		}
	}
	else {
		err = osErrorResource;
	}
	ResumeOSInterrupts();
	return err;
}
osStatus_t osMutexDelete(osMutexId_t mutex_id)
{
	CmsisMutexType *mutex;
	osStatus_t err = osOK;

	if (CurrentContextIsISR()) {
		return osErrorISR;
	}
	else if (mutex_id == NULL) {
		return osErrorParameter;
	}
	mutex = (CmsisMutexType*)mutex_id;
	if (mutex->magicno != ATK2MUTEX_HEAD_MAGICNO) {
		return osErrorParameter;
	}
	SuspendOSInterrupts();
	if (mutex->count == 0) {
		err = osSemaphoreDelete(mutex->sem);
		if (err == osOK) {
			Atk2MemoryFree(mutex);
		}
	}
	else {
		err = osErrorResource;
	}
	ResumeOSInterrupts();
	return err;
}

/*
 * Version 1
 */
osMutexId osMutexCreate(const osMutexDef_t *mutex_def)
{
	if (mutex_def != NULL) {
		//TODO ERROR LOG
		return NULL;
	}
	return (osMutexId)osMutexNew(NULL);
}
