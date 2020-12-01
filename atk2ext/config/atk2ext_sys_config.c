#include "atk2ext_sys_config.h"

StatusType Atk2TaskConfigSet(const osThreadFunc_t func, void *argument)
{
	int i;
	for (i = 0; i < USER_THREAD_NUM; i++)
	{
		if (user_thread_atk2task_map[i].func == func) {
			user_thread_atk2task_map[i].argument = argument;
			return E_OK;
		}
	}
	return E_OS_ID;
}

StatusType Atk2TaskConfigGetTaskID(const osThreadFunc_t func, TaskType *taskID)
{
	int i;
	for (i = 0; i < USER_THREAD_NUM; i++)
	{
		if (user_thread_atk2task_map[i].func == func) {
			*taskID = user_thread_atk2task_map[i].taskID;
			return E_OK;
		}
	}
	return E_OS_ID;
}

StatusType Atk2TaskConfigGet(UserThreadAtk2TaskMapEntryType *config)
{
	int i;
	TaskType taskID;
	StatusType ercd;

	ercd = GetTaskID(&taskID);
	if (ercd != E_OK) {
		return ercd;
	}

	for (i = 0; i < USER_THREAD_NUM; i++)
	{
		if (user_thread_atk2task_map[i].taskID == taskID) {
			*config = user_thread_atk2task_map[i];
			return E_OK;
		}
	}
	return E_OS_ID;
}
