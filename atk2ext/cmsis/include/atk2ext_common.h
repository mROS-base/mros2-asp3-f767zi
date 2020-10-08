#ifndef _ATK2EXTEND_COMMON_H_
#define _ATK2EXTEND_COMMON_H_


#ifdef OS_ATK2
#include "kernel/kernel_impl.h"
#include "Os.h"
#include "Os_Lcfg.h"
#include "queue.h"
#include "sysmod/syslog.h"


typedef boolean bool_t;
#ifndef true
#define true TRUE
#endif
#ifndef false
#define false FALSE
#endif

#else
#include "t_stddef.h"
#include "tool_stddef.h"
#include "t_syslog.h"
#include "queue.h"
#include "kernel.h"
#include "kernel_cfg.h"
#include "sil.h"

typedef int StatusType;
typedef int AlarmType;
typedef int TaskType;
typedef int* TaskRefType;
typedef int AlarmType;
typedef int EventMaskType;

extern StatusType GetTaskID(TaskRefType TaskID);
extern StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
extern StatusType ClearEvent(EventMaskType Mask);
extern StatusType WaitEvent(EventMaskType Mask);
extern void ResumeAllInterrupts(void);
extern void SuspendAllInterrupts(void);
extern void ResumeOSInterrupts(void);
extern void SuspendOSInterrupts(void);
extern StatusType ActivateTask(TaskType TaskID);
extern StatusType TerminateTask(void);

#define E_OK	0
#define E_OS_CALLEVEL	2
#define E_OS_ID 3
#define E_OS_LIMIT 4
#define E_OS_RESOURCE 6

#define Atk2ExtEvent	0x00000001

#define TASK(func)	void TaskMain ## func (intptr_t exinf)

#endif /* OS_ATK2 */

extern bool_t CurrentContextIsISR(void);

#endif /* _ATK2EXTEND_COMMON_H_ */
