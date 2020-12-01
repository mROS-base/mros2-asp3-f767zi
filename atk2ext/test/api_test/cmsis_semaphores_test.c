#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_test.h"
#include "atk2ext_testfw.h"
#include "atk2ext_user_config.h"

#include "cmsis_atk2_time.h"

#define CMSIS_SEMPHORES_TEST_TRUE   1
#define CMSIS_SEMPHORES_TEST_FALSE  0

#define TEST_SEMPHORES_MAX_TOKEN1	1U
#define TEST_SEMPHORES_INIT_TOKEN1	1U
#define TEST_SEMPHORES_MAX_TOKEN2	2U
#define TEST_SEMPHORES_INIT_TOKEN2	2U

#define TEST_SEMPHORES_DELAY_TIME_10ms 10U
#define TEST_SEMPHORES_DELAY_TIME_100ms 100U
#define TEST_SEMPHORES_DELAY_TIME_110ms 110U

typedef struct {
	osSemaphoreId_t id;
	char* api_name;
	uint32_t timeout;
}TestAcquireInfoType;

static void test_New_01(void);
static void test_Acquire_01(void);
static void test_Acquire_02(void);
static void test_Acquire_03(void);
static void test_Acquire_04(void);
static void test_Acquire_05(void);
static void test_Acquire_06(void);
static void test_Acquire_07(void);
static void test_Acquire_08(void);
static void test_Acquire_09(void);
static void test_Release_01(void);
static void test_Release_02(void);
static void test_Release_03(void);
static void test_Release_04(void);
static void test_Release_05(void);
static void test_Release_06(void);
static void test_Release_07(void);
static void test_dleate_01(void);
static void test_dleate_02(void);

static int exec_cunt = 0U;

static void test_exec(void (*exec_test_func)(void))
{
	exec_test_func();
	exec_cunt++;
	return;
}

#define TESTNAME "cmsis_semaphores_test"
void cmsis_semaphores_test_init(void)
{
	atk2ext_testfw_start_test(TESTNAME);
	return;
}
void cmsis_semaphores_test_end(void)
{
	atk2ext_testfw_end_test();
	return;
}

void cmsis_semaphores_test_start(void)
{
	test_exec(test_New_01);

	test_exec(test_Acquire_01);
	test_exec(test_Acquire_02);
	test_exec(test_Acquire_03);
	test_exec(test_Acquire_04);
	test_exec(test_Acquire_05);
	test_exec(test_Acquire_06);
	test_exec(test_Acquire_07);
	test_exec(test_Acquire_08);
	test_exec(test_Acquire_09);

	test_exec(test_Release_01);
	test_exec(test_Release_02);
	test_exec(test_Release_03);
	test_exec(test_Release_04);
	test_exec(test_Release_05);
	test_exec(test_Release_06);
	test_exec(test_Release_07);

	test_exec(test_dleate_01);
	test_exec(test_dleate_02);

	return;
}

int cmsis_semaphores_test_get_exec_num(void)
{
	return exec_cunt;
}

static void test_New_01(void)
{
	char *api_name = "osSemaphoreNew:No.1";
	osSemaphoreId_t id;
	osStatus_t err;
	{
		//pre nothing

		//do
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 2, osOK, err);
		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Acquire_01(void)
{
	char *api_name = "osSemaphoreAcquire:No.1";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		//do
		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		//done
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_acquire_task_callback1(void *argp)
{
	TestAcquireInfoType* info;
	osStatus_t err;

	info = (TestAcquireInfoType*)argp;
	err = osSemaphoreAcquire(info->id, 0);
	TestAssertEq(info->api_name, 1, osOK, err);

	(void)osDelay(info->timeout);

	err = osSemaphoreRelease(info->id);
	TestAssertEq(info->api_name, 2, osOK, err);

	return;
}

static void test_Acquire_02(void)
{
	char *api_name = "osSemaphoreAcquire:No.2";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		info.api_name = "osSemaphoreAcquire:No.2:callback";
		info.id = id;
		info.timeout = TEST_SEMPHORES_DELAY_TIME_100ms;

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);

		//do
		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_110ms);

		//done
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Acquire_03(void)
{
	char *api_name = "osSemaphoreAcquire:No.3";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		info.api_name = "osSemaphoreAcquire:No.3:callback";
		info.id = id;
		info.timeout = TEST_SEMPHORES_DELAY_TIME_100ms;

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier3, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier3_Body, (void*)&info, NULL);


		//do
		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osErrorResource, err);

		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_110ms);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 3, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Acquire_04(void)
{
	char *api_name = "osSemaphoreAcquire:No.4";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		info.api_name = "osSemaphoreAcquire:No.4:callback";
		info.id = id;
		info.timeout = TEST_SEMPHORES_DELAY_TIME_100ms;

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier3, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier3_Body, (void*)&info, NULL);


		//do
		err = osSemaphoreAcquire(id, TEST_SEMPHORES_DELAY_TIME_10ms);
		TestAssertEq(api_name, 2, osErrorTimeoutResource, err);

		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_110ms);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 3, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_acquire_task_callback2(void *argp)
{
	TestAcquireInfoType* info;
	osStatus_t err;

	info = (TestAcquireInfoType*)argp;
	err = osSemaphoreAcquire(info->id, osWaitForever);
	TestAssertEq(info->api_name, 1, osOK, err);

	err = osSemaphoreRelease(info->id);
	TestAssertEq(info->api_name, 2, osOK, err);

	return;
}

static void test_Acquire_05(void)
{
	char *api_name = "osSemaphoreAcquire:No.5";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		info.api_name = "osSemaphoreAcquire:No.5:callback";
		info.id = id;

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		//do
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback2);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);

		Atk2TimeIncTickCountSet((osWaitForever - 10U));
		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_100ms);

		//done
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);

		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Acquire_06(void)
{
	char *api_name = "osSemaphoreAcquire:No.6";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		info.api_name = "osSemaphoreAcquire:No.6:callback";
		info.id = id;

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		//do
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback2);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier3, test_acquire_task_callback2);
		(void)osThreadNew(Atk2TaskTestSupplier3_Body, (void*)&info, NULL);


		Atk2TimeIncTickCountSet((osWaitForever - 10U));
		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_100ms);

		//done
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);

		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Acquire_07(void)
{
	char *api_name = "osSemaphoreAcquire:No.7";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		info.api_name = "osSemaphoreAcquire:No.7:callback";
		info.id = id;

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		//do
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback2);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier3, test_acquire_task_callback2);
		(void)osThreadNew(Atk2TaskTestSupplier3_Body, (void*)&info, NULL);
		atk2ext_testfw_setfunc(Atk2TaskTestConsumer3, test_acquire_task_callback2);
		(void)osThreadNew(Atk2TaskTestConsumer3_Body, (void*)&info, NULL);


		Atk2TimeIncTickCountSet((osWaitForever - 10U));
		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_100ms);

		//done
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);

		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Acquire_08(void)
{
	char *api_name = "osSemaphoreAcquire:No.8";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 2, osOK, err);

		//do
		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 3, osErrorParameter, err);

		//done

		atk2ext_testfw_clrfunc();
	}

	return;
}


static TestAcquireInfoType callback_info;
static int is_first_callback;
static void test_acquire_task_callback3(void)
{

	osStatus_t err;

	if (is_first_callback == CMSIS_SEMPHORES_TEST_TRUE) {
		err = osSemaphoreAcquire(callback_info.id, 0);
		TestAssertEq(callback_info.api_name, 1, osOK, err);

		err = osSemaphoreRelease(callback_info.id);
		TestAssertEq(callback_info.api_name, 2, osOK, err);
		is_first_callback = CMSIS_SEMPHORES_TEST_FALSE;
	}

	return;
}

static void test_Acquire_09(void)
{
	char *api_name = "osSemaphoreAcquire:No.9";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		is_first_callback = CMSIS_SEMPHORES_TEST_TRUE;
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);
		callback_info.id = id;
		callback_info.api_name = "osSemaphoreAcquire:No.9:callback";

		//do
		atk2ext_testfw_set_cyclic_handler_func(test_acquire_task_callback3, NULL);
		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_10ms);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}


static void test_Release_01(void)
{
	char *api_name = "osSemaphoreRelease:No.1";
	osSemaphoreId_t id;
	TestAcquireInfoType info;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		info.id = id;
		info.api_name = "osSemaphoreRelease:No.1:callback";
		info.timeout = TEST_SEMPHORES_DELAY_TIME_100ms;

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);

		//do
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);

		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_100ms);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Release_02(void)
{
	char *api_name = "osSemaphoreRelease:No.2";
	osSemaphoreId_t id;
	TestAcquireInfoType info;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		info.id = id;
		info.api_name = "osSemaphoreRelease:No.2:callback";
		info.timeout = TEST_SEMPHORES_DELAY_TIME_10ms;

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);

		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_100ms);

		//do
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 4, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Release_03(void)
{
	char *api_name = "osSemaphoreRelease:No.3";
	osSemaphoreId_t id;
	TestAcquireInfoType info;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		info.id = id;
		info.api_name = "osSemaphoreRelease:No.3:callback";
		info.timeout = TEST_SEMPHORES_DELAY_TIME_10ms;

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_acquire_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);

		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_10ms);

		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osOK, err);

		//do
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 4, osErrorResource, err);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 5, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Release_04(void)
{
	char *api_name = "osSemaphoreRelease:No.4";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		is_first_callback = CMSIS_SEMPHORES_TEST_TRUE;
		callback_info.id = id;
		callback_info.api_name = "osSemaphoreRelease:No.4:callback";

		//do
		atk2ext_testfw_set_cyclic_handler_func(test_acquire_task_callback3, NULL);
		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_10ms);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 3, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_Release_05(void)
{
	char *api_name = "osSemaphoreRelease:No.5";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 2, osOK, err);

		//do
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 3, osErrorParameter, err);

		//done

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_release_task_callback1(void *argp)
{
	TestAcquireInfoType* info;
	osStatus_t err;

	info = (TestAcquireInfoType*)argp;
	err = osSemaphoreRelease(info->id);
	TestAssertEq(info->api_name, 1, osOK, err);

	return;
}

static void test_Release_06(void)
{
	char *api_name = "osSemaphoreRelease:No.6";
	osSemaphoreId_t id;
	osStatus_t err;
	TestAcquireInfoType info;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		info.id = id;
		info.api_name = "osSemaphoreRelease:No.6:callback";

		//do
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_release_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, (void*)&info, NULL);

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 3, osOK, err);
		err = osSemaphoreRelease(id);
		TestAssertEq(api_name, 4, osOK, err);

		//done

		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 5, osOK, err);
		atk2ext_testfw_clrfunc();
	}

	return;
}


static void test_release_task_callback2(void)
{

	osStatus_t err;

	if (is_first_callback == CMSIS_SEMPHORES_TEST_TRUE) {
		err = osSemaphoreRelease(callback_info.id);
		TestAssertEq(callback_info.api_name, 1, osOK, err);
		is_first_callback = CMSIS_SEMPHORES_TEST_FALSE;
	}

	return;
}

static void test_Release_07(void)
{
	char *api_name = "osSemaphoreRelease:No.7";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		is_first_callback = CMSIS_SEMPHORES_TEST_TRUE;
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN2, TEST_SEMPHORES_INIT_TOKEN2, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		err = osSemaphoreAcquire(id, 0);
		TestAssertEq(api_name, 2, osOK, err);

		callback_info.id = id;
		callback_info.api_name = "osSemaphoreRelease:No.7:callback";

		//do
		atk2ext_testfw_set_cyclic_handler_func(test_release_task_callback2, NULL);
		(void)osDelay(TEST_SEMPHORES_DELAY_TIME_10ms);

		//done
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 3, osOK, err);

		atk2ext_testfw_clrfunc();
	}

	return;
}


static void test_dleate_01(void)
{
	char *api_name = "osSemaphoreDleate:No.1";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);

		//do
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 2, osOK, err);

		//done

		atk2ext_testfw_clrfunc();
	}

	return;
}

static void test_dleate_02(void)
{
	char *api_name = "osSemaphoreDleate:No.2";
	osSemaphoreId_t id;
	osStatus_t err;

	{
		//pre
		id = osSemaphoreNew(TEST_SEMPHORES_MAX_TOKEN1, TEST_SEMPHORES_INIT_TOKEN1, NULL);
		TestAssertNotEq(api_name, 1, id, NULL);
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 2, osOK, err);

		//do
		err = osSemaphoreDelete(id);
		TestAssertEq(api_name, 3, osErrorParameter, err);

		//done

		atk2ext_testfw_clrfunc();
	}

	return;
}
