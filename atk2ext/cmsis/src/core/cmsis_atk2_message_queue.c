#include "cmsis_atk2_message_queue.h"
#include "cmsis_atk2_memory.h"
#include "cmsis_atk2_task_sync.h"
#include "cmsis_os.h"
#include <string.h>

Atk2MessageQueueType *Atk2MessageQueueCreate(Atk2MessageQueueConfigType *config)
{
	uint32_t i;
	uint32_t entry_total_size;
	uint32_t msg_data_total_size;
	char *top;
	char *entry_top;
	char *msg_top;
	Atk2MessageQueueType *qh;

	entry_total_size = sizeof(Atk2MessageQueueEntryType) * config->prealloc_num;
	msg_data_total_size = config->entry_size * config->prealloc_num;

	top = Atk2MemoryAlloc(sizeof(Atk2MessageQueueType) + entry_total_size + msg_data_total_size);
	if (top == NULL) {
		//TODO ERRLOG
		return NULL;
	}
	qh = (Atk2MessageQueueType *)top;
	qh->entry_size = config->entry_size;
	qh->prealloc_num = config->prealloc_num;
	qh->magicno = ATK2MESSAGE_QUEUE_HEAD_MAGICNO;
	Atk2QueueHeadInit(&qh->free);
	Atk2QueueHeadInit(&qh->used);
	Atk2QueueHeadInit(&qh->getter_waiting);
	Atk2QueueHeadInit(&qh->putter_waiting);

	entry_top = &top[sizeof(Atk2MessageQueueType)];
	msg_top = &entry_top[entry_total_size];
	/*
	 *  [ queue memory image ]
	 *
	 *     qh     entry0 entry1   .................  entryN    msg0     msg1      ...................     msgN
	 *   |------|------|------|------|------|------|------|----------|----------|----------|----------|----------|
	 */
	Atk2MessageQueueEntryType *entry = (Atk2MessageQueueEntryType*)entry_top;
	for (i = 0; i < qh->prealloc_num; i++) {
		entry->prio = 0;
		entry->data = &msg_top[i * qh->entry_size];
		Atk2QueueHeadAddTail(&qh->free,  &entry->queue);
		entry++;
	}
	return qh;
}

StatusType Atk2MessageQueueDelete(Atk2MessageQueueType *qh)
{
	if (qh == NULL) {
		return E_OS_ID;
	}
	else if (qh->magicno != ATK2MESSAGE_QUEUE_HEAD_MAGICNO) {
		return E_OS_ID;
	}
	Atk2MemoryFree(qh);
	return E_OK;
}

StatusType Atk2MessageQueueGet(Atk2MessageQueueType *qh, void *msg_ptr, uint8_t *msg_prio, uint32_t timeout)
{
	StatusType ercd = E_OK;
	Atk2MessageQueueEntryType *entry = NULL;
	TaskType taskID;

	if (qh->magicno != ATK2MESSAGE_QUEUE_HEAD_MAGICNO) {
		return E_OS_ID;
	}
	(void)GetTaskID(&taskID);

	SuspendOSInterrupts();
	entry = (Atk2MessageQueueEntryType*)Atk2QueueHeadRemoveFirst(&qh->used);
	if (entry == NULL) {
		if (timeout != 0) {
			entry = (Atk2MessageQueueEntryType *)Atk2TaskSyncWait(&qh->getter_waiting, timeout, NULL, taskID);
		}
	}
	if (entry != NULL) {
		memcpy(msg_ptr, entry->data, qh->entry_size);
		if (!Atk2TaskSyncWakeupFirstEntry(&qh->putter_waiting, entry, E_OK)) {
			Atk2QueueHeadAddTail(&qh->free, &entry->queue);
		}
		else {
			/* nothing to do */
		}
	}
	else {
		ercd = E_OS_LIMIT;
	}
	ResumeOSInterrupts();
	return ercd;
}

StatusType Atk2MessageQueuePut(Atk2MessageQueueType *qh, const void *msg_ptr, uint8_t msg_prio, uint32_t timeout)
{
	StatusType ercd = E_OK;
	Atk2MessageQueueEntryType *entry = NULL;
	TaskType taskID;

	if (qh->magicno != ATK2MESSAGE_QUEUE_HEAD_MAGICNO) {
		return E_OS_ID;
	}
	(void)GetTaskID(&taskID);

	SuspendOSInterrupts();
	entry = (Atk2MessageQueueEntryType*)Atk2QueueHeadRemoveFirst(&qh->free);
	if (entry == NULL) {
		if (timeout != 0) {
			entry = (Atk2MessageQueueEntryType*)Atk2TaskSyncWait(&qh->putter_waiting, timeout, NULL, taskID);
		}
	}
	if (entry != NULL) {
		memcpy(entry->data, msg_ptr, qh->entry_size);
		if (!Atk2TaskSyncWakeupFirstEntry(&qh->getter_waiting, entry, E_OK)) {
			(void)Atk2QueueHeadAddTail(&qh->used, &entry->queue);
		}
		else {
			/* nothing to do */
		}
	}
	else {
		ercd = E_OS_LIMIT;
	}
	ResumeOSInterrupts();
	return ercd;
}
