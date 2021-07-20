#include "cmsis_os.h"
#include "cmsis_config_utl.h"
#include "sample_ping.h"

TASK(Atk2ExtTcpTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2ExtEthIfLinkTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2ExtEthInputTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtHBPubTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtHBSubTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtSPDPTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtWriterTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtReaderTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtUserDefaultTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2ExtMROS2Task)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
