#ifndef _CMSIS_ATK2_TASK_LIFECYCLE_H_
#define _CMSIS_ATK2_TASK_LIFECYCLE_H_

#include "atk2ext_common.h"

typedef struct {
	TaskType taskID;
	void *argument;
	void (* task_func) (void *argument);
} Atk2TaskInfoType;
extern StatusType Atk2TaskLifecycleActivate(Atk2TaskInfoType *task_infop);
extern StatusType Atk2TaskLifecycleTerminate(void);


#endif /* _CMSIS_ATK2_TASK_LIFECYCLE_H_ */
