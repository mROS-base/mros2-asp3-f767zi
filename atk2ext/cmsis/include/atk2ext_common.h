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

/*
 * CMSIS LOG API
 */
#ifdef CMSIS_LOG_DISABLE_DEBUG
#define CMSIS_DEBUG(...)
#else
#define CMSIS_DEBUG(...) 		syslog(LOG_DEBUG, __VA_ARGS__)
#endif

#ifdef CMSIS_LOG_DISABLE_INFO
#define CMSIS_INFO(...)
#else
#define CMSIS_INFO(...)       syslog(LOG_NOTICE, __VA_ARGS__)
#endif

#ifdef CMSIS_LOG_DISABLE_WARN
#define CMSIS_WARN(...)
#else
#define CMSIS_WARN(...)       syslog(LOG_WARNING, __VA_ARGS__)
#endif

#ifdef CMSIS_LOG_DISABLE_ERROR
#define CMSIS_ERROR(...)
#else
#define CMSIS_ERROR(...)      syslog(LOG_ERROR, __VA_ARGS__)
#endif

#ifdef CMSIS_LOG_DISABLE_FATAL
#define CMSIS_FATAL(...)
#else
#define CMSIS_FATAL(...)      syslog(LOG_EMERG, __VA_ARGS__)
#endif


#endif /* _ATK2EXTEND_COMMON_H_ */
