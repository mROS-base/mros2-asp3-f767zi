#include "atk2ext_sys_config.h"
#include "atk2ext_common.h"

extern void tcpip_thread(void *arg);
extern void ethernetif_set_link(void* argument);
extern void ethernetif_input(void* argument);

UserThreadAtk2TaskMapEntryType user_thread_atk2task_map[USER_THREAD_NUM] = {
		{
				.taskID = Atk2ExtTestTask,
				.func = tcpip_thread,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtTest2Task,
				.func = ethernetif_set_link,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtTest3Task,
				.func = ethernetif_input,
				.argument = NULL,
		},
};