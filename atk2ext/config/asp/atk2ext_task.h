#ifndef _ATK2EXT_TASK_H_
#define _ATK2EXT_TASK_H_

#define TASKNAME(func)	TaskMain ## func

extern void	TASKNAME(Atk2ExtCyclicTask) (intptr_t exinf);
extern void Atk2ExtCyclicHandler(intptr_t exinf);

#endif /* _ATK2EXT_TASK_H_ */
