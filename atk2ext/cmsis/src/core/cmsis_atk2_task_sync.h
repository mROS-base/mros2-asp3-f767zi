#ifndef _CMSIS_ATK2_TASK_SYNC_H_
#define _CMSIS_ATK2_TASK_SYNC_H_

#include "cmsis_atk2_queue.h"
#include "cmsis_atk2_types.h"

extern StatusType Atk2TaskSyncSleep(uint32_t timeout);
extern StatusType Atk2TaskSyncWakeup(TaskType taskID, StatusType ercd);

extern void *Atk2TaskSyncWait(Atk2QueueHeadType *waiting_queue, uint32_t timeout, StatusType *ercdp, TaskType taskID);
extern bool_t Atk2TaskSyncWakeupFirstEntry(Atk2QueueHeadType *waiting_queue, void *data, StatusType ercd);

#endif /* _CMSIS_ATK2_TASK_SYNC_H_ */
