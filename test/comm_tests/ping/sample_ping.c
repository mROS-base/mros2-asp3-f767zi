#include "autosar_os_ext_common.h"
#include "cmsis_os.h"
#include "autosar_os_ext_sys_config.h"
#include "sample_ping.h"

TASK(AutosarOsExtTestTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}

TASK(AutosarOsExtTest2Task)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}

TASK(AutosarOsExtTest3Task)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
