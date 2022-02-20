#include "cmsis_os.h"
#include "cmsis_config_utl.h"
#include "task_impl.h"

TASK(AutosarOsExtTcpTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}

TASK(AutosarOsExtEthIfLinkTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}

TASK(AutosarOsExtEthInputTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtHBPubTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtHBSubTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtSPDPTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtWriterTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtReaderTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtUserDefaultTask)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
TASK(AutosarOsExtMROS2Task)
{
  UserThreadAutosarOsTaskMapEntryType config;
  StatusType ercd = AutosarOsTaskConfigGet(&config);

  if (ercd == E_OK) {
    config.func(config.argument);
  }

  (void)osThreadTerminate(NULL);
  return;
}
