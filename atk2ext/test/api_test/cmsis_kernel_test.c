#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_test.h"
#include "atk2ext_testfw.h"
#include "atk2ext_user_config.h"

#include "cmsis_atk2_time.h"

static void test_gettick_01(void);
static void test_gettick_02(void);
static void test_gettick_callback1(void);

#define TEST_KERNEL_SLEEP_TIME_100ms		100U
#define TEST_KERNEL_SLEEP_TIME_200ms		200U
#define TEST_KERNEL_SLEEP_TIME_1000ms		1000U
#define TEST_KERNEL_SLEEP_TIME_2000ms		2000U

static int exec_cunt = 0U;

static void test_exec(void (*exec_test_func)(void))
{
	exec_test_func();
	exec_cunt++;
	return;
}

#define TESTNAME "cmsis_kernel_test"
void cmsis_kernel_test_init(void)
{
	atk2ext_testfw_start_test(TESTNAME);
	return;
}
void cmsis_kernel_test_end(void)
{
	atk2ext_testfw_end_test();
	return;
}

void cmsis_kernel_test_start(void)
{
	test_exec(test_gettick_01);
	test_exec(test_gettick_02);
	return;
}

int cmsis_kernel_test_get_exec_num(void)
{
	return exec_cunt;
}

static int test_kernel_callback_waekup_count = 0;
static void test_gettick_callback1(void)
{
	char *api_name = "osKernelGetTickCount:No.2";
	uint32_t wakeup_time;

	{
		//osKernelGetTickCount:No.1 100ms + osKernelGetTickCount:No.2 100ms = 200ms
		if (test_kernel_callback_waekup_count < TEST_KERNEL_SLEEP_TIME_100ms) {
			test_kernel_callback_waekup_count++;
		}
		else if (test_kernel_callback_waekup_count == TEST_KERNEL_SLEEP_TIME_100ms) {
			wakeup_time = osKernelGetTickCount();
			TestAssertInRange(api_name, 1, wakeup_time, wakeup_time+1U, TEST_KERNEL_SLEEP_TIME_200ms);

			test_kernel_callback_waekup_count++;
		}

	}

	return;
}

static void test_gettick_01(void)
{
	char *api_name = "osKernelGetTickCount:No.1";
	uint32_t wakeup_time;

	{
		(void)osDelay(TEST_KERNEL_SLEEP_TIME_100ms);
		wakeup_time = osKernelGetTickCount();
		TestAssertInRange(api_name, 1, wakeup_time, wakeup_time+1U, TEST_KERNEL_SLEEP_TIME_100ms);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_gettick_02(void)
{
	{
		atk2ext_testfw_set_cyclic_handler_func(test_gettick_callback1, NULL);
		(void)osDelay(TEST_KERNEL_SLEEP_TIME_200ms);

		atk2ext_testfw_clrfunc();
	}

	return;
}



