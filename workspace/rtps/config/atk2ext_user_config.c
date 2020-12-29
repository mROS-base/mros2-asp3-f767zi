#include "atk2ext_sys_config.h"
#include "atk2ext_common.h"

extern void tcpip_thread(void *arg);
extern void ethernetif_set_link(void* argument);
extern void ethernetif_input(void* argument);
void *networkSubDriverPtr;
void *networkPubDriverPtr;
void (*hbPubFuncPtr)(void *);
void (*hbSubFuncPtr)(void *);
extern void callWriterThreadFunction(void *arg);
extern void callReaderThreadFunction(void *arg);
extern void callRunBroadcast(void *args);

void callHbPubFunc(void *arg)
{
	if(hbPubFuncPtr != NULL && networkPubDriverPtr != NULL)
	{
		(*hbPubFuncPtr)(networkPubDriverPtr);
	}
}
void callHbSubFunc(void *arg)
{
	if(hbSubFuncPtr != NULL && networkSubDriverPtr != NULL)
	{
		(*hbSubFuncPtr)(networkSubDriverPtr);
	}
}

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
				.taskID = Atk2ExtUserDefaultTask,
				.func = StartDefaultTask,
				.argument = NULL,
		},
};
