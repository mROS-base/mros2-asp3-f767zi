#ifndef _ATK2EXT_CONFIG_UTILS_H_
#define _ATK2EXT_CONFIG_UTILS_H_

#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_user_config.h"

/***********************************************
 *
 * THREAD
 *
 ***********************************************/

typedef struct {
	TaskType			taskID;
	osThreadFunc_t		func;
	void 				*argument;
} UserThreadAtk2TaskMapEntryType;

extern StatusType Atk2TaskConfigSet(const osThreadFunc_t func, void *argument);
extern StatusType Atk2TaskConfigGet(UserThreadAtk2TaskMapEntryType *config);
extern StatusType Atk2TaskConfigGetTaskID(const osThreadFunc_t func, TaskType *taskID);
extern UserThreadAtk2TaskMapEntryType user_thread_atk2task_map[USER_THREAD_NUM];

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

#endif /* _ATK2EXT_CONFIG_UTILS_H_ */
