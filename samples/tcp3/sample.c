#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_sys_config.h"
#include "sample.h"

TASK(Atk2ExtTestTask)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2ExtTest2Task)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2ExtTest3Task)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2TaskTestControl)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
