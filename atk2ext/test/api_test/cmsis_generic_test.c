#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_test.h"
#include "atk2ext_testfw.h"
#include "atk2ext_user_config.h"

#include "cmsis_atk2_time.h"

static void test_delay_01(void);
//static void test_delay_02(void);	//not subject to inspection
static void test_delay_03(void);
static void test_delay_04(void);
static void test_delay_05(void);
static void test_delay_06(void);
static void test_delay_07(void);
static void test_delay_08(void);



#define TEST_DELAY_TIME_100ms		100U
#define TEST_DELAY_TIME_200ms		200U
#define TEST_DELAY_TIME_1000ms		1000U
#define TEST_DELAY_TIME_2000ms		2000U

#define TEST_DELAY_TASK_CALLBACK1	1
#define TEST_DELAY_TASK_CALLBACK2	2
#define TEST_DELAY_TASK_NONE		0



#define TEST_DELAY_TICK_COUNT_MAX	UINT32_MAX

typedef struct {
	char		id;
	uint32_t	time;
}TestDelayWakeupInfoType;
static TestDelayWakeupInfoType test_delay_wakeup[USER_THREAD_NUM];
static int test_delay_wakeup_count = 0U;

static int exec_cunt = 0U;

static void test_exec(void (*exec_test_func)(void))
{
	exec_test_func();
	exec_cunt++;
	return;
}

#define TESTNAME "cmsis_generic_test"
void cmsis_generic_test_init(void)
{
	int thread;
	atk2ext_testfw_start_test(TESTNAME);

	for (thread = 0; thread < USER_THREAD_NUM; thread++) {
		test_delay_wakeup[thread].id = TEST_DELAY_TASK_NONE;
		test_delay_wakeup[thread].time = 0;
	}

	return;
}
void cmsis_generic_test_end(void)
{
	atk2ext_testfw_end_test();
	return;
}

void cmsis_generic_test_start(void)
{
	test_exec(test_delay_01);
	test_exec(test_delay_03);
	test_exec(test_delay_04);
	test_exec(test_delay_05);
	test_exec(test_delay_06);
	test_exec(test_delay_07);
	test_exec(test_delay_08);
	return;
}

int cmsis_generic_test_get_exec_num(void)
{
	return exec_cunt;
}

static void test_delay_01(void)
{
	char *api_name = "osDelay:No.1";
	uint32_t exp_val;
	osStatus_t err;

	{
		uint32_t current_time = osKernelGetTickCount();
		err = osDelay(TEST_DELAY_TIME_100ms);
		uint32_t wakeup_time = osKernelGetTickCount();
		exp_val = TEST_DELAY_TIME_100ms;
		TestAssertInRange(api_name, 1, exp_val, exp_val+1U, (wakeup_time - current_time));
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}




static void test_delay_task_callback1(void *argp)
{
	char *api_name = "osDelay:No.3";
	osStatus_t err;

	err = osDelay(TEST_DELAY_TIME_100ms);
	TestAssertEq(api_name, 1, osOK, err);

	test_delay_wakeup[test_delay_wakeup_count].id = TEST_DELAY_TASK_CALLBACK1;
	test_delay_wakeup[test_delay_wakeup_count].time = osKernelGetTickCount();
	test_delay_wakeup_count++;

	return;
}

static void test_delay_task_callback2(void *argp)
{
	char *api_name = "osDelay:No.3";
	osStatus_t err;

	err = osDelay(TEST_DELAY_TIME_100ms);
	TestAssertEq(api_name, 1, osOK, err);

	test_delay_wakeup[test_delay_wakeup_count].id = TEST_DELAY_TASK_CALLBACK2;
	test_delay_wakeup[test_delay_wakeup_count].time = osKernelGetTickCount();
	test_delay_wakeup_count++;

	return;
}


static void test_delay_03(void)
{
	char *api_name = "osDelay:No.3";
	uint32_t exp_val;

	{
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_delay_task_callback1);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier3, test_delay_task_callback2);

		(void)osThreadNew(Atk2TaskTestSupplier2_Body, NULL, NULL);
		(void)osThreadNew(Atk2TaskTestSupplier3_Body, NULL, NULL);

		(void)osDelay(TEST_DELAY_TIME_200ms);

		exp_val =  test_delay_wakeup[0].time;

		TestAssertEq(api_name, 1, test_delay_wakeup[0].id, TEST_DELAY_TASK_CALLBACK2);
		TestAssertEq(api_name, 2, test_delay_wakeup[1].id, TEST_DELAY_TASK_CALLBACK1);
		TestAssertInRange(api_name, 3, exp_val, exp_val+1U, test_delay_wakeup[1].time);

		atk2ext_testfw_clrfunc();
	}

	return;
}


static void test_delay_task_callback4(void *argp)
{
	uint32_t current_time;

	//200ms timeout over
	current_time = osKernelGetTickCount();
	if ((current_time + *(uint32_t*)argp) >= current_time) {
		Atk2TimeIncTickCountSet(current_time + *(uint32_t*)argp);
	}
	else {
		Atk2TimeIncTickCountSet(current_time + *(uint32_t*)argp + 1U);
	}


	return;
}


static void test_delay_04(void)
{
	char *api_name = "osDelay:No.4";
	uint32_t test_start_time;
	uint32_t current_time;
	uint32_t over_time;
	uint32_t exp_val;
	osStatus_t err;


	test_start_time = osKernelGetTickCount();

	{

		//pre
		Atk2TimeIncTickCountSet(TEST_DELAY_TIME_1000ms);

		over_time = TEST_DELAY_TIME_200ms + 9U;
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier1, test_delay_task_callback4);
		(void)osThreadNew(Atk2TaskTestSupplier1_Body, (void*)&over_time, NULL);

		//do
		err = osDelay(TEST_DELAY_TIME_200ms);
		current_time = osKernelGetTickCount();
		exp_val = TEST_DELAY_TIME_1000ms + TEST_DELAY_TIME_200ms + 10U;
		TestAssertInRange(api_name, 1, exp_val, exp_val+1U, current_time);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	Atk2TimeIncTickCountSet(test_start_time);

	return;
}

static void test_delay_05(void)
{
	uint32_t test_start_time;
	char *api_name = "osDelay:No.5";
	uint32_t exp_val;
	osStatus_t err;


	test_start_time = osKernelGetTickCount();
	{
		Atk2TimeIncTickCountSet(TEST_DELAY_TIME_1000ms);
		err = osDelay(TEST_DELAY_TIME_200ms);
		uint32_t wakeup_time = osKernelGetTickCount();
		exp_val = TEST_DELAY_TIME_1000ms + TEST_DELAY_TIME_200ms;
		TestAssertInRange(api_name, 1, exp_val, exp_val+1U, wakeup_time);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	Atk2TimeIncTickCountSet(test_start_time);

	return;
}


static void test_delay_06(void)
{
	uint32_t test_start_time;
	char *api_name = "osDelay:No.6";
	uint32_t over_time;
	osStatus_t err;

	test_start_time = osKernelGetTickCount();
	{
		//pre
		Atk2TimeIncTickCountSet(TEST_DELAY_TIME_1000ms);
		over_time = TEST_DELAY_TICK_COUNT_MAX - TEST_DELAY_TIME_1000ms + 9U;
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier1, test_delay_task_callback4);
		(void)osThreadNew(Atk2TaskTestSupplier1_Body, (void*)&over_time, NULL);

		//do
		err = osDelay(TEST_DELAY_TIME_200ms);
		uint32_t wakeup_time = osKernelGetTickCount();
		TestAssertInRange(api_name, 1, 10U, 11U, wakeup_time);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	Atk2TimeIncTickCountSet(test_start_time);

	return;
}


static void test_delay_07(void)
{
	uint32_t test_start_time;
	char *api_name = "osDelay:No.7";
	uint32_t over_time;
	osStatus_t err;

	test_start_time = osKernelGetTickCount();
	{
		Atk2TimeIncTickCountSet(TEST_DELAY_TICK_COUNT_MAX - 10U);

		//pre
		over_time = TEST_DELAY_TICK_COUNT_MAX - (TEST_DELAY_TICK_COUNT_MAX - 10U) + (TEST_DELAY_TIME_200ms + 9U);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier1, test_delay_task_callback4);
		(void)osThreadNew(Atk2TaskTestSupplier1_Body, (void*)&over_time, NULL);

		err = osDelay(TEST_DELAY_TIME_200ms);
		uint32_t wakeup_time = osKernelGetTickCount();
		TestAssertInRange(api_name, 1, 210U, 211U, wakeup_time);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	Atk2TimeIncTickCountSet(test_start_time);

	return;
}

static void test_delay_08(void)
{
	uint32_t test_start_time;
	char *api_name = "osDelay:No.8";
	osStatus_t err;

	test_start_time = osKernelGetTickCount();
	{
		Atk2TimeIncTickCountSet(TEST_DELAY_TICK_COUNT_MAX - 10U);
		err = osDelay(TEST_DELAY_TIME_200ms);
		uint32_t wakeup_time = osKernelGetTickCount();
		TestAssertInRange(api_name, 1, 189, 190, wakeup_time);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	Atk2TimeIncTickCountSet(test_start_time);

	return;
}

