#include "cmsis_atk2_task_sync.h"
#include "cmsis_os.h"

osStatus_t osDelay(uint32_t ticks)
{
	StatusType err;

	if (CurrentContextIsISR()) {
		return osErrorISR;
	}
	if (ticks == 0U) {
		ticks = 1U;
	}

	err = Atk2TaskSyncSleep(ticks);
	if (err != E_OK) {
		//osDelay cannot be called from Interrupt Service Routines.
		return osErrorISR;
	}
	return osOK;
}
