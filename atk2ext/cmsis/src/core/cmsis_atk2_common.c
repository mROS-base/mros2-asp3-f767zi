#include "atk2ext_common.h"

bool_t CurrentContextIsISR(void)
{
	TaskType taskID;
	ISRType isrtype = GetISRID();
	if (isrtype != INVALID_ISR) {
		//C2ISR
		return true;
	}
	StatusType ercd = GetTaskID(&taskID);
	if (ercd != E_OK) {
		//C1ISR
		return true;
	}
	return false;
}
