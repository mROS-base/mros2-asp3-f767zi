#ifndef _ATK2EXT_CONFIG_H_
#define _ATK2EXT_CONFIG_H_

#include "atk2ext_common.h"
#include "cmsis_os.h"

/***********************************************
 *
 * MEMORY
 *
 ***********************************************/
#define APP_HEAP_SIZE	(16 * 1024) /* 16KB */


/***********************************************
 *
 * THREAD
 *
 ***********************************************/
#define USER_THREAD_NUM		1U
typedef struct {
	TaskType			taskID;
	osThreadFunc_t		func;
	void 				*argument;
} UserThreadAtk2TaskMapEntryType;

extern StatusType Atk2TaskConfigSet(const osThreadFunc_t func, void *argument);
extern StatusType Atk2TaskConfigGet(UserThreadAtk2TaskMapEntryType *config);
extern StatusType Atk2TaskConfigGetTaskID(const osThreadFunc_t func, TaskType *taskID);

/***********************************************
 *
 * MESSAGE QUEUE
 *
 ***********************************************/
#define MESSAGE_QUEUE_ENTRY_ALIGNMENT_SIZE	4U
#define MESSAGE_QUEUE_ENTRY_ALIGNED_SIZE(size)	\
	(	\
			(	\
				(	\
						(size) + (MESSAGE_QUEUE_ENTRY_ALIGNMENT_SIZE - 1)	\
				)	\
				/ MESSAGE_QUEUE_ENTRY_ALIGNMENT_SIZE	\
			)	\
			* MESSAGE_QUEUE_ENTRY_ALIGNMENT_SIZE	\
	)

#endif /* _ATK2EXT_CONFIG_H_ */
