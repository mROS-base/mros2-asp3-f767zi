#include "cmsis_os.h"
#include "cmsis_user_config.h"
#include "atk2ext_user_config.h"

extern void tcpip_thread(void *arg);
extern void ethernetif_set_link(void* argument);
extern void ethernetif_input(void* argument);
extern void callHbPubFunc(void *arg);
extern void callHbSubFunc(void *arg);
extern void StartDefaultTask(void * argument);
extern void callWriterThreadFunction(void *arg);
extern void callReaderThreadFunction(void *arg);
extern void callRunBroadcast(void *args);
extern void mros2_init(void *args);


UserThreadAtk2TaskMapEntryType user_thread_atk2task_map[USER_THREAD_NUM] = {
		{
				.taskID = Atk2ExtTcpTask,
				.func = tcpip_thread,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtEthIfLinkTask,
				.func = ethernetif_set_link,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtEthInputTask,
				.func = ethernetif_input,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtHBPubTask,
				.func = callHbPubFunc,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtHBSubTask,
				.func = callHbSubFunc,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtSPDPTask,
				.func = callRunBroadcast,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtWriterTask,
				.func = callWriterThreadFunction,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtReaderTask,
				.func = callReaderThreadFunction,
				.argument = NULL,
		},
		{
				.taskID = Atk2ExtMROS2Task,
				.func = mros2_init,
				.argument = NULL,
		},
};

UserThreadAtk2TaskMapEntryType* cmsis_get_user_thread_map(void)
{
	return user_thread_atk2task_map;
}
int cmsis_get_app_heap_size(void)
{
	return APP_HEAP_SIZE;
}
int cmsis_get_user_thread_num(void)
{
	return USER_THREAD_NUM;
}
