#include "cmsis_atk2_task_sync.h"
#include "cmsis_atk2_time.h"

typedef struct {
	QUEUE				queue;
	TaskType			taskID;
	uint32_t			timeout;
	uint32_t			stick;
	uint32_t			expiretick;
	StatusType			ercd;
} Atk2TaskWaitInfoType;

typedef struct {
	QUEUE						wait_queue;
	void						*data;
	Atk2TaskWaitInfoType		winfo;
} Atk2TaskWaitQueueEntryType;

static bool_t Atk2TaskIsTimeout(QUEUE *entry, void *arg);
static void Atk2TaskWakeup(QUEUE *entry, void *arg);
static bool_t Atk2TaskHasTargetId(QUEUE *entry, void *arg);
static void Atk2TaskSyncWaitInfoInit(Atk2TaskWaitInfoType *winfop, uint32_t timeout, TaskType taskID);


static Atk2QueueHeadInitializer(atk2_task_sync_queue);

StatusType Atk2TaskSyncSleep(uint32_t timeout)
{
	Atk2TaskWaitInfoType winfo;
	TaskType taskID;

	StatusType ercd = GetTaskID(&taskID);
	if (ercd != E_OK) {
		CMSIS_ERROR("ERROR:%s %s() %d winfo.ercd=%d\n", __FILE__, __FUNCTION__, __LINE__, ercd);
		return winfo.ercd;
	}
	Atk2TaskSyncWaitInfoInit(&winfo, timeout, taskID);
	SuspendOSInterrupts();
	Atk2QueueHeadAddTail(&atk2_task_sync_queue, &winfo.queue);
	ResumeOSInterrupts();

	(void)WaitEvent(Atk2ExtEvent);
	(void)ClearEvent(Atk2ExtEvent);

	return E_OK;
}
void *Atk2TaskSyncWait(Atk2QueueHeadType *waiting_queue, uint32_t timeout, StatusType *ercdp, TaskType taskID)
{
	Atk2TaskWaitQueueEntryType wait_info;

	wait_info.data = NULL;
	Atk2TaskSyncWaitInfoInit(&wait_info.winfo, timeout, taskID);

	if (waiting_queue != NULL) {
		Atk2QueueHeadAddTail(waiting_queue, &wait_info.wait_queue);
	}
	Atk2QueueHeadAddTail(&atk2_task_sync_queue, &wait_info.winfo.queue);
	ResumeOSInterrupts();

	(void)WaitEvent(Atk2ExtEvent);
	(void)ClearEvent(Atk2ExtEvent);

	SuspendOSInterrupts();
	if (waiting_queue != NULL) {
		Atk2QueueHeadRemoveEntry(waiting_queue, &wait_info.wait_queue);
	}
	if (ercdp != NULL) {
		*ercdp = wait_info.winfo.ercd;
	}
	return wait_info.data;
}
bool_t Atk2TaskSyncWakeupFirstEntry(Atk2QueueHeadType *waiting_queue, void *data, StatusType ercd)
{
	Atk2TaskWaitQueueEntryType *wait_infop = (Atk2TaskWaitQueueEntryType*)waiting_queue->entries;
	if (wait_infop != NULL) {
		Atk2QueueHeadInitializer(dq);
		wait_infop->data = data;
		wait_infop->winfo.ercd = ercd;
		Atk2QueueHeadConditionalRemove(&atk2_task_sync_queue, &dq, Atk2TaskHasTargetId, &wait_infop->winfo.taskID);

		ResumeOSInterrupts();
		Atk2QueueHeadDoAction(&dq, Atk2TaskWakeup, &ercd);
		SuspendOSInterrupts();
		return true;
	}
	else {
		return false;
	}
}

StatusType Atk2TaskSyncWakeup(TaskType taskID, StatusType ercd)
{
	Atk2QueueHeadInitializer(dq);

	SuspendOSInterrupts();
	Atk2QueueHeadConditionalRemove(&atk2_task_sync_queue, &dq, Atk2TaskHasTargetId, &taskID);
	ResumeOSInterrupts();

	Atk2QueueHeadDoAction(&dq, Atk2TaskWakeup, &ercd);
	return E_OK;
}

static void TaskScheduleCallback(void)
{
	uint32_t curr;
	StatusType err = E_OS_LIMIT;
	Atk2QueueHeadInitializer(dq);

	Atk2TimeIncTickCount();
	if (atk2_task_sync_queue.entries == NULL) {
		return;
	}
	curr = Atk2TimeGetTickCount();

	SuspendOSInterrupts();
	Atk2QueueHeadConditionalRemove(&atk2_task_sync_queue, &dq, Atk2TaskIsTimeout, (void*)&curr);
	ResumeOSInterrupts();

	Atk2QueueHeadDoAction(&dq, Atk2TaskWakeup, &err);
	return;
}

TASK(Atk2ExtCyclicTask)
{
	TaskScheduleCallback();
	TerminateTask();
	return;
}

static void Atk2TaskSyncWaitInfoInit(Atk2TaskWaitInfoType *winfop, uint32_t timeout, TaskType taskID)
{
	winfop->timeout = timeout;
	winfop->stick = Atk2TimeGetTickCount();
	winfop->expiretick = Atk2TimeGetExpireTickCount(winfop->stick, timeout);
	queue_initialize(&winfop->queue);
	winfop->taskID = taskID;
	winfop->ercd = E_OK;
	return;
}


static bool_t Atk2TaskIsTimeout(QUEUE *entry, void *arg)
{
	uint32_t curr = *((uint32_t*)arg);
	Atk2TaskWaitInfoType *winfop = (Atk2TaskWaitInfoType *)entry;
	if (winfop->timeout == ATK2_TASK_SYNC_WAIT_FOREVER) {
		return false;
	}
	if (Atk2TimeIsTimeout(curr, winfop->stick, winfop->expiretick)) {
		return true;
	}
	return false;
}

static void Atk2TaskWakeup(QUEUE *entry, void *arg)
{
	Atk2TaskWaitInfoType *winfop = (Atk2TaskWaitInfoType *)entry;
	StatusType ercd = *((StatusType*)arg);
	winfop->ercd = ercd;
	(void)SetEvent(winfop->taskID, Atk2ExtEvent);
	return;
}

static bool_t Atk2TaskHasTargetId(QUEUE *entry, void *arg)
{
	TaskType taskID = *((TaskType*)arg);
	Atk2TaskWaitInfoType *winfop = (Atk2TaskWaitInfoType *)entry;
	if (winfop->taskID == taskID) {
		return true;
	}
	return false;
}
