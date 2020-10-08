#include "cmsis_os.h"
#include "atk2ext_config.h"
#include "cmsis_atk2_message_queue.h"
#include "cmsis_atk2_task_sync.h"
#include <string.h>

osMessageQueueId_t osMessageQueueNew(
		uint32_t 	msg_count,
		uint32_t 	msg_size,
		const osMessageQueueAttr_t *attr)
{
	uint32_t aligned_msg_size;
	Atk2MessageQueueConfigType config;

	if (CurrentContextIsISR()) {
		return NULL;
	}
	else if (attr != NULL) {
		//TODO ERROR LOG
		return NULL;
	}
	else if (msg_count == 0) {
		//TODO ERROR LOG
		return NULL;
	}
	else if (msg_size == 0) {
		//TODO ERROR LOG
		return NULL;
	}
	aligned_msg_size = MESSAGE_QUEUE_ENTRY_ALIGNED_SIZE(msg_size);
	config.entry_size = aligned_msg_size;
	config.prealloc_num = msg_count;
	config.control_datap = NULL;
	config.entries_datap = NULL;

	return (osMessageQueueId_t*)Atk2MessageQueueCreate(&config);
}

osStatus_t osMessageQueueDelete(osMessageQueueId_t mq_id)
{
	osStatus_t err = osOK;
	Atk2MessageQueueType *qh = (Atk2MessageQueueType*)mq_id;

	if (CurrentContextIsISR()) {
		return osErrorISR;
	}
	else if (qh == NULL) {
		//TODO ERROR LOG
		return osErrorParameter;
	}
	SuspendOSInterrupts();
	if ((qh->used.count == 0) && (qh->getter_waiting.count == 0) && (qh->putter_waiting.count == 0)) {
		StatusType ercd = Atk2MessageQueueDelete((Atk2MessageQueueType*)mq_id);
		if (ercd != E_OK) {
			err = osErrorParameter;
		}
	}
	else {
		err = osErrorResource;
	}
	ResumeOSInterrupts();
	return err;
}

osStatus_t osMessageQueueGet(
		osMessageQueueId_t mq_id,
		void *msg_ptr,
		uint8_t *msg_prio,
		uint32_t timeout)
{
	uint32_t arg_timeout = timeout;
	osStatus_t err = osErrorParameter;
	StatusType ercd;
	Atk2MessageQueueType *qh = (Atk2MessageQueueType*)mq_id;
	if (CurrentContextIsISR() && (timeout != 0)) {
		return osErrorParameter;
	}
	else if (qh == NULL) {
		//TODO ERROR LOG
		return osErrorParameter;
	}
	else if (msg_prio != NULL) {
		//TODO ERROR LOG
		//not supported.
		return osErrorParameter;
	}
	if (timeout == 0) {
		err = osErrorResource;
	}
	else {
		if (timeout == osWaitForever) {
			arg_timeout = ATK2_TASK_SYNC_WAIT_FOREVER;
		}
		err = osErrorTimeout;
	}
	ercd = Atk2MessageQueueGet(qh, msg_ptr, msg_prio, arg_timeout);
	if (ercd == E_OK) {
		err = osOK;
	}
	return err;
}

uint32_t osMessageQueueGetCount(osMessageQueueId_t mq_id)
{
	Atk2MessageQueueType *qh = (Atk2MessageQueueType*)mq_id;
	if (qh == NULL) {
		//TODO ERROR LOG
		return 0;
	}
	return qh->used.count;
}

osStatus_t osMessageQueuePut(
		osMessageQueueId_t 	mq_id,
		const void *msg_ptr,
		uint8_t msg_prio,
		uint32_t timeout)
{
	uint32_t arg_timeout = timeout;
	osStatus_t err = osErrorParameter;
	StatusType ercd;
	Atk2MessageQueueType *qh = (Atk2MessageQueueType*)mq_id;

	if (CurrentContextIsISR() && (timeout != 0)) {
		return osErrorParameter;
	}
	else if (qh == NULL) {
		//TODO ERROR LOG
		return osErrorParameter;
	}
	else if (msg_prio != 0) {
		//TODO ERROR LOG
		//not supported.
		return osErrorParameter;
	}
	if (timeout == 0) {
		err = osErrorResource;
	}
	else {
		if (timeout == osWaitForever) {
			arg_timeout = ATK2_TASK_SYNC_WAIT_FOREVER;
		}
		err = osErrorTimeout;
	}
	ercd = Atk2MessageQueuePut(qh, msg_ptr, msg_prio, arg_timeout);
	if (ercd == E_OK) {
		err = osOK;
	}
	return err;
}
/*
 * Version 1
 */
osMessageQId osMessageCreate(
	const osMessageQDef_t *queue_def,
	osThreadId thread_id)
{
	if (queue_def == NULL) {
		//TODO ERROR LOG
		return NULL;
	}
	return osMessageQueueNew(queue_def->queue_sz, sizeof(uint32_t), NULL);
}

osEvent osMessageGet(
		osMessageQId queue_id,
		uint32_t millisec)
{
	  osStatus_t status;
	  osEvent    event;
	  uint32_t   message;

	  status = osMessageQueueGet((osMessageQueueId_t)queue_id, &message, NULL, millisec);
	  switch (status) {
	    case osOK:
	      event.status = osEventMessage;
	      event.value.v = message;
	      break;
	    case osErrorResource:
	      event.status = osOK;
	      break;
	    case osErrorTimeout:
	      event.status = osEventTimeout;
	      break;
	    default:
	      event.status = status;
	      break;
	  }
	  return event;
}

osStatus osMessagePut(
		osMessageQId queue_id,
		uint32_t info,
		uint32_t millisec)
{
	return osMessageQueuePut((osMessageQueueId_t)queue_id, &info, 0U, millisec);
}
