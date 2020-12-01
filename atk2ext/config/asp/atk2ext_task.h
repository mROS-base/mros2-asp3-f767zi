#ifndef _ATK2EXT_TASK_H_
#define _ATK2EXT_TASK_H_

#define TASKNAME(func)	TaskMain ## func
#define ALARMCALLBACKNAME(func) AlarmManin ## func

extern void	TASKNAME(Atk2ExtCyclicTask) (intptr_t exinf);
extern void ALARMCALLBACKNAME(Atk2ExtCyclicHandler) (intptr_t exinf);

#endif /* _ATK2EXT_TASK_H_ */
