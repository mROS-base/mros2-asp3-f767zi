#include "autosar_os_ext_sys_config.h"
#include "autosar_os_ext_common.h"

extern void tcpip_thread(void *arg);
extern void ethernetif_set_link(void* argument);
extern void ethernetif_input(void* argument);
extern void sample_lwip_scene3(void);

UserThreadAutosarOsTaskMapEntryType user_thread_autosar_ostask_map[USER_THREAD_NUM] = {
		{
				.taskID = AutosarOsExtTestTask,
				.func = tcpip_thread,
				.argument = NULL,
		},
		{
				.taskID = AutosarOsExtTest2Task,
				.func = ethernetif_set_link,
				.argument = NULL,
		},
		{
				.taskID = AutosarOsExtTest3Task,
				.func = ethernetif_input,
				.argument = NULL,
		},
		{
				.taskID = AutosarOsTaskTestControl,
				.func = (void *)(sample_lwip_scene3),
				.argument = NULL,
		},
};