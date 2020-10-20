#include "cmsis_atk2_task_sync.h"
#include "cmsis_os.h"

osStatus_t osDelay(uint32_t ticks)
{
	StatusType err;

	if (CurrentContextIsISR()) {
		return osErrorISR;
	}
	err = Atk2TaskSyncSleep(ticks);
	if (err != E_OK) {
		return osErrorISR;
	}
	return osOK;
}
