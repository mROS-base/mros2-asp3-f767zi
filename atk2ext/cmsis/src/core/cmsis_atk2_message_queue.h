#ifndef _CMSIS_ATK2_MESSAGE_QUEUE_H_
#define _CMSIS_ATK2_MESSAGE_QUEUE_H_

#include "cmsis_atk2_queue.h"
#include "cmsis_atk2_types.h"

#define ATK2MESSAGE_QUEUE_HEAD_MAGICNO		0xDEAFBEAD
typedef struct {
	uint16_t			prealloc_num;
	uint16_t			entry_size;
	uint32_t			magicno;
	Atk2QueueHeadType	used;
	Atk2QueueHeadType	free;
	Atk2QueueHeadType	getter_waiting;
	Atk2QueueHeadType	putter_waiting;
} Atk2MessageQueueType;


typedef struct {
	QUEUE						queue;
	/*
	 * Priority
	 *
	 *  Highest  UINT16_MAX
	 *  Lowest   0
	 */
	uint16_t					prio;
	void						*data;
} Atk2MessageQueueEntryType;


typedef struct {
	uint16_t 					prealloc_num;
	uint16_t 					entry_size;
	Atk2MessageQueueEntryType   *control_datap;
	void 	 					*entries_datap;
} Atk2MessageQueueConfigType;
extern Atk2MessageQueueType *Atk2MessageQueueCreate(Atk2MessageQueueConfigType *config);
extern StatusType Atk2MessageQueueDelete(Atk2MessageQueueType *qh);

extern StatusType Atk2MessageQueueGet(Atk2MessageQueueType *qh, void *msg_ptr, uint8_t *msg_prio, uint32_t timeout);
extern StatusType Atk2MessageQueuePut(Atk2MessageQueueType *qh, const void *msg_ptr, uint8_t msg_prio, uint32_t timeout);

#endif /* _CMSIS_ATK2_MESSAGE_QUEUE_H_ */
