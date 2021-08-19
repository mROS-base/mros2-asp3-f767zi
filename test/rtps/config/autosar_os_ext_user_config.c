#include "autosar_os_ext_sys_config.h"
#include "autosar_os_ext_common.h"

extern void tcpip_thread(void *arg);
extern void ethernetif_set_link(void* argument);
extern void ethernetif_input(void* argument);
extern void callHbPubFunc(void *arg);
extern void callHbSubFunc(void *arg);
extern void StartDefaultTask(void *argument);
extern void callWriterThreadFunction(void *arg);
extern void callReaderThreadFunction(void *arg);
extern void callRunBroadcast(void *args);


UserThreadAutosarOsTaskMapEntryType user_thread_autosar_ostask_map[USER_THREAD_NUM] = {
  {
    .taskID = AutosarOsExtTcpTask,
    .func = tcpip_thread,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtEthIfLinkTask,
    .func = ethernetif_set_link,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtEthInputTask,
    .func = ethernetif_input,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtHBPubTask,
    .func = callHbPubFunc,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtHBSubTask,
    .func = callHbSubFunc,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtSPDPTask,
    .func = callRunBroadcast,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtWriterTask,
    .func = callWriterThreadFunction,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtReaderTask,
    .func = callReaderThreadFunction,
    .argument = NULL,
  },
  {
    .taskID = AutosarOsExtUserDefaultTask,
    .func = StartDefaultTask,
    .argument = NULL,
  },
};
