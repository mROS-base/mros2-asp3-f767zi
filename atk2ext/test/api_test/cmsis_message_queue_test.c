#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_test.h"
#include "atk2ext_testfw.h"
#include "atk2ext_user_config.h"

static void test_new_01(void);

static void test_delete_01(void);
static void test_delete_02(void);

static void test_get_01(void);
static void test_get_02(void);
static void test_get_07(void);
static void test_get_08(void);
static void test_get_09(void);
static void test_get_10(void);
static void test_get_11(void);
static void test_get_12(void);
static void test_get_13(void);

static void test_getcnt_01(void);
static void test_getcnt_02(void);
static void test_getcnt_03(void);
static void test_getcnt_04(void);

static void test_put_01(void);
static void test_put_02(void);
static void test_put_11(void);
static void test_put_12(void);
static void test_put_13(void);
static void test_put_14(void);

static int exec_cunt = 0U;

static void test_exec(void (*exec_test_func)(void))
{
	exec_test_func();
	exec_cunt++;
	return;
}

#define TESTNAME "cmsis_message_queue_test"
void cmsis_message_queue_test_init(void)
{
	atk2ext_testfw_start_test(TESTNAME);
	return;
}
void cmsis_message_queue_test_end(void)
{
	atk2ext_testfw_end_test();
	return;
}

void cmsis_message_queue_test_start(void)
{
	test_exec(test_new_01);

	test_exec(test_delete_01);
	test_exec(test_delete_02);

	test_exec(test_put_01);
	test_exec(test_put_02);
	test_exec(test_put_11);
	test_exec(test_put_12);
	test_exec(test_put_13);
	test_exec(test_put_14);

	test_exec(test_get_01);
	test_exec(test_get_02);
	test_exec(test_get_07);
	test_exec(test_get_08);
	test_exec(test_get_09);
	test_exec(test_get_10);
	test_exec(test_get_11);
	test_exec(test_get_12);
	test_exec(test_get_13);

	test_exec(test_getcnt_01);
	test_exec(test_getcnt_02);
	test_exec(test_getcnt_03);
	test_exec(test_getcnt_04);

	return;
}

int cmsis_message_queue_test_get_exec_num(void)
{
	return exec_cunt;
}

static void test_put_01(void)
{
	char *api_name = "osMessageQueuePut:No.1";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{

		err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 2, osOK, err);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 3, osOK, err);
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 4, osOK, err);	return;
}
static void test_put_02_isr_callback(void)
{
	char *api_name = "osMessageQueuePut:isr_callback";
	int msg_data = 324;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)atk2ext_testfw_get_cyclic_handler_argp();
	if (msgq_id == NULL) {
		return;
	}
	TestAssertNotEq(api_name, 2, NULL, msgq_id);

	osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, 0);
	TestAssertEq(api_name, 3, osOK, err);

	atk2ext_testfw_clr_cyclic_handler_func();
	return;
}

static void test_put_02(void)
{
	char *api_name = "osMessageQueuePut:No.2";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		atk2ext_testfw_set_cyclic_handler_func(test_put_02_isr_callback, msgq_id);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 4, osOK, err);
		TestAssertEq(api_name, 5, 324, msg_data);

	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 6, osOK, err);
	return;
}
static void test_put_task_callback1(void *argp)
{
	char *api_name = "osMessageQueuePut:task_callback1";
	int msg_data = 11;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 3, osOK, err);
	return;
}
static void test_put_task_callback2(void *argp)
{
	char *api_name = "osMessageQueuePut:task_callback2";
	int msg_data = 12;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 3, osOK, err);
	return;
}
static void test_put_task_callback3(void *argp)
{
	char *api_name = "osMessageQueuePut:task_callback3";
	int msg_data = 13;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 3, osOK, err);
	return;
}

static void test_put_11(void)
{
	char *api_name = "osMessageQueuePut:No.11";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier1, test_put_task_callback1);
		(void)osThreadNew(Atk2TaskTestSupplier1_Body, msgq_id, NULL);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 4, osOK, err);
		TestAssertEq(api_name, 5, 10, msg_data);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 6, osOK, err);
		TestAssertEq(api_name, 7, 11, msg_data);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 8, osErrorResource, err);
		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 9, osOK, err);
	return;
}
static void test_put_12(void)
{
	char *api_name = "osMessageQueuePut:No.12";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier1, test_put_task_callback1);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_put_task_callback2);
		(void)osThreadNew(Atk2TaskTestSupplier1_Body, msgq_id, NULL);
		osDelay(10);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, msgq_id, NULL);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 4, osOK, err);
		TestAssertEq(api_name, 5, 10, msg_data);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 6, osOK, err);
		TestAssertEq(api_name, 7, 11, msg_data);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 8, osOK, err);
		TestAssertEq(api_name, 9, 12, msg_data);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 10, osErrorResource, err);
		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 11, osOK, err);
	return;
}
static void test_put_13(void)
{
	char *api_name = "osMessageQueuePut:No.13";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		osStatus err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_setfunc(Atk2TaskTestSupplier1, test_put_task_callback1);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier2, test_put_task_callback2);
		atk2ext_testfw_setfunc(Atk2TaskTestSupplier3, test_put_task_callback3);
		(void)osThreadNew(Atk2TaskTestSupplier1_Body, msgq_id, NULL);
		osDelay(10);
		(void)osThreadNew(Atk2TaskTestSupplier2_Body, msgq_id, NULL);
		osDelay(10);
		(void)osThreadNew(Atk2TaskTestSupplier3_Body, msgq_id, NULL);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 4, osOK, err);
		TestAssertEq(api_name, 5, 10, msg_data);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 6, osOK, err);
		TestAssertEq(api_name, 7, 11, msg_data);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 8, osOK, err);
		TestAssertEq(api_name, 9, 12, msg_data);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 10, osOK, err);
		TestAssertEq(api_name, 11, 13, msg_data);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 12, osErrorResource, err);
		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 13, osOK, err);
	return;
}
static void test_put_14(void)
{
	char *api_name = "osMessageQueuePut:No.14";
	int msg_data = 1024;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 2, osOK, err);

	err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, 0);
	TestAssertEq(api_name, 3, osErrorParameter, err);
	return;
}


static void test_new_01(void)
{
	osMessageQueueId_t msgq_id = osMessageQueueNew(10, sizeof(int), NULL);
	TestAssertNotEq("osMessageQueueNew:No.1", 1, NULL, msgq_id);
	(void)osMessageQueueDelete(msgq_id);
	return;
}

static void test_delete_01(void)
{
	osMessageQueueId_t msgq_id = osMessageQueueNew(10, sizeof(int), NULL);
	TestAssertNotEq("osMessageQueueDelete:No.1", 1, NULL, msgq_id);
	osStatus_t err = osMessageQueueDelete(msgq_id);
	TestAssertEq("osMessageQueueDelete:No.1", 2, osOK, err);
	return;
}

static void test_delete_02(void)
{
	osMessageQueueId_t msgq_id = osMessageQueueNew(10, sizeof(int), NULL);
	TestAssertNotEq("osMessageQueueDelete:No.2", 1, NULL, msgq_id);
	osStatus_t err = osMessageQueueDelete(msgq_id);
	TestAssertEq("osMessageQueueDelete:No.2", 2, osOK, err);
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq("osMessageQueueDelete:No.2", 3, osErrorParameter, err);
	return;
}

static void test_get_01_task_callback(void *argp)
{
	char *api_name = "osMessageQueueGet:task_callback";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 4, osOK, err);
	TestAssertEq(api_name, 5, 10, msg_data);

	return;
}

static void test_get_01(void)
{
	char *api_name = "osMessageQueueGet:No.1";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{

		err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
		TestAssertEq(api_name, 2, osOK, err);

		atk2ext_testfw_setfunc(Atk2TaskTestConsumer1, test_get_01_task_callback);
		(void)osThreadNew(Atk2TaskTestConsumer1_Body, msgq_id, NULL);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 6, osErrorResource, err);

		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 7, osOK, err);
	return;
}

static void test_get_02_isr_callback(void)
{
	char *api_name = "osMessageQueueGet:isr_callback";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)atk2ext_testfw_get_cyclic_handler_argp();
	if (msgq_id == NULL) {
		return;
	}
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
	TestAssertEq(api_name, 4, osOK, err);
	TestAssertEq(api_name, 5, 10, msg_data);

	err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
	TestAssertEq(api_name, 6, osOK, err);
	TestAssertEq(api_name, 7, 512, msg_data);

	atk2ext_testfw_clr_cyclic_handler_func();
	return;
}

static void test_get_02(void)
{
	char *api_name = "osMessageQueueGet:No.2";
	int msg_data1 = 10;
	int msg_data2 = 512;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(2, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{

		err = osMessageQueuePut(msgq_id, (void*)&msg_data1, 0, osWaitForever);
		TestAssertEq(api_name, 2, osOK, err);
		err = osMessageQueuePut(msgq_id, (void*)&msg_data2, 0, osWaitForever);
		TestAssertEq(api_name, 3, osOK, err);

		atk2ext_testfw_set_cyclic_handler_func(test_get_02_isr_callback, msgq_id);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 0);
		TestAssertEq(api_name, 8, osErrorResource, err);

	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 9, osOK, err);
	return;
}

static void test_get_07(void)
{
	char *api_name = "osMessageQueueGet:No.7";
	int msg_data1 = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 0);
		TestAssertEq(api_name, 2, osErrorResource, err);

	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 3, osOK, err);
	return;
}

static void test_get_08_isr_callback(void)
{
	char *api_name = "osMessageQueueGet:isr_callback";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)atk2ext_testfw_get_cyclic_handler_argp();
	if (msgq_id == NULL) {
		return;
	}
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
	TestAssertEq(api_name, 8, osErrorResource, err);

	atk2ext_testfw_clr_cyclic_handler_func();
	return;
}


static void test_get_08(void)
{
	char *api_name = "osMessageQueueGet:No.8";
	int msg_data1 = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(2, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		atk2ext_testfw_set_cyclic_handler_func(test_get_08_isr_callback, msgq_id);
		osDelay(10);

		err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 0);
		TestAssertEq(api_name, 8, osErrorResource, err);
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 9, osOK, err);
	return;
}

static void test_get_09(void)
{
	char *api_name = "osMessageQueueGet:No.9";
	int msg_data1 = 123;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{
		uint32_t current_time = osKernelGetTickCount();
		err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 10);
		uint32_t wakeup_time = osKernelGetTickCount();
		TestAssertInRange(api_name, 2, 10, 11, (wakeup_time - current_time));
		TestAssertEq(api_name, 2, osErrorTimeout, err);

	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 3, osOK, err);
	return;
}


static void test_get_10_task_callback(void *argp)
{
	char *api_name = "osMessageQueueGet:task_callback";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 2, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 4, osOK, err);
	TestAssertEq(api_name, 5, 10, msg_data);

	return;
}

static void test_get_10(void)
{
	char *api_name = "osMessageQueueGet:No.10";
	int msg_data = 10;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{

		atk2ext_testfw_setfunc(Atk2TaskTestConsumer1, test_get_10_task_callback);
		(void)osThreadNew(Atk2TaskTestConsumer1_Body, msgq_id, NULL);
		osDelay(1000);

		err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
		TestAssertEq(api_name, 3, osOK, err);

		osDelay(10);
		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		TestAssertEq(api_name, 6, osErrorResource, err);

		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 7, osOK, err);
	return;
}

static void test_get_task_callback1(void *argp)
{
	char *api_name = "osMessageQueueGet:task_callback1";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 2, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 2, osOK, err);
	TestAssertEq(api_name, 2, 1024, msg_data);

	return;
}
static void test_get_task_callback2(void *argp)
{
	char *api_name = "osMessageQueueGet:task_callback2";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 3, osOK, err);
	TestAssertEq(api_name, 3, 8192, msg_data);

	return;
}
static void test_get_task_callback3(void *argp)
{
	char *api_name = "osMessageQueueGet:task_callback3";
	int msg_data;
	osMessageQueueId_t msgq_id = (osMessageQueueId_t)argp;
	TestAssertNotEq(api_name, 4, NULL, msgq_id);

	osStatus_t err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 4, osOK, err);
	TestAssertEq(api_name, 4, 4096, msg_data);

	return;
}

static void test_get_11(void)
{
	char *api_name = "osMessageQueueGet:No.11";
	int msg_data1 = 1024;
	int msg_data2 = 8192;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{

		atk2ext_testfw_setfunc(Atk2TaskTestConsumer1, test_get_task_callback1);
		atk2ext_testfw_setfunc(Atk2TaskTestConsumer2, test_get_task_callback2);
		(void)osThreadNew(Atk2TaskTestConsumer1_Body, msgq_id, NULL);
		osDelay(10);
		(void)osThreadNew(Atk2TaskTestConsumer2_Body, msgq_id, NULL);
		osDelay(10);

		err = osMessageQueuePut(msgq_id, (void*)&msg_data1, 0, osWaitForever);
		TestAssertEq(api_name, 3, osOK, err);
		err = osMessageQueuePut(msgq_id, (void*)&msg_data2, 0, osWaitForever);
		TestAssertEq(api_name, 4, osOK, err);

		osDelay(10);
		err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 0);
		TestAssertEq(api_name, 9, osErrorResource, err);

		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 10, osOK, err);
	return;
}

static void test_get_12(void)
{
	char *api_name = "osMessageQueueGet:No.12";
	int msg_data1 = 1024;
	int msg_data2 = 8192;
	int msg_data3 = 4096;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	{

		atk2ext_testfw_setfunc(Atk2TaskTestConsumer1, test_get_task_callback1);
		atk2ext_testfw_setfunc(Atk2TaskTestConsumer2, test_get_task_callback2);
		atk2ext_testfw_setfunc(Atk2TaskTestConsumer3, test_get_task_callback3);
		(void)osThreadNew(Atk2TaskTestConsumer1_Body, msgq_id, NULL);
		osDelay(10);
		(void)osThreadNew(Atk2TaskTestConsumer2_Body, msgq_id, NULL);
		osDelay(10);
		(void)osThreadNew(Atk2TaskTestConsumer3_Body, msgq_id, NULL);
		osDelay(10);

		err = osMessageQueuePut(msgq_id, (void*)&msg_data1, 0, osWaitForever);
		TestAssertEq(api_name, 5, osOK, err);
		err = osMessageQueuePut(msgq_id, (void*)&msg_data2, 0, osWaitForever);
		TestAssertEq(api_name, 6, osOK, err);
		err = osMessageQueuePut(msgq_id, (void*)&msg_data3, 0, osWaitForever);
		TestAssertEq(api_name, 7, osOK, err);

		osDelay(10);
		err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 0);
		TestAssertEq(api_name, 8, osErrorResource, err);

		atk2ext_testfw_clrfunc();
	}
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 9, osOK, err);
	return;
}

static void test_get_13(void)
{
	char *api_name = "osMessageQueueGet:No.13";
	int msg_data1 = 1024;
	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 9, osOK, err);

	err = osMessageQueueGet(msgq_id, (void*)&msg_data1, 0, 0);
	TestAssertEq(api_name, 8, osErrorParameter, err);
	return;
}

static void test_getcnt_01(void)
{
	char *api_name = "osMessageQueueGetCount:No.1";
	int msg_data = 10;

	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(10, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);

	err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
	TestAssertEq(api_name, 2, osOK, err);

	uint32_t count = osMessageQueueGetCount(msgq_id);
	TestAssertEq(api_name, 3, 1, count);

	err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
	TestAssertEq(api_name, 4, osOK, err);

	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 5, osOK, err);
	return;
}

static void test_getcnt_02_isr_callback(void)
{
	char *api_name = "osMessageQueueGetCount:isr_callback";

	osMessageQueueId_t msgq_id = (osMessageQueueId_t)atk2ext_testfw_get_cyclic_handler_argp();
	if (msgq_id == NULL) {
		return;
	}
	TestAssertNotEq(api_name, 3, NULL, msgq_id);

	uint32_t count = osMessageQueueGetCount(msgq_id);
	TestAssertEq(api_name, 4, 10, count);

	atk2ext_testfw_clr_cyclic_handler_func();
	return;
}

static void test_getcnt_02(void)
{
	char *api_name = "osMessageQueueGetCount:No.2";
	int msg_data = 10;
	int i;

	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(10, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);

	for (i = 0; i < 10; i++) {
		err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, osWaitForever);
		//TestAssertEq(api_name, i + 2, osOK, err);
	}

	atk2ext_testfw_set_cyclic_handler_func(test_getcnt_02_isr_callback, msgq_id);
	osDelay(10);

	for (i = 0; i < 10; i++) {
		err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, 0);
		//TestAssertEq(api_name, i + 14, osOK, err);
	}

	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, i + 5, osOK, err);
	return;
}
static void test_getcnt_03(void)
{
	char *api_name = "osMessageQueueGetCount:No.3";

	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(10, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);

	uint32_t count = osMessageQueueGetCount(msgq_id);
	TestAssertEq(api_name, 2, 0, count);

	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 3, osOK, err);
	return;
}
static void test_getcnt_04(void)
{
	char *api_name = "osMessageQueueGetCount:No.4";

	osStatus_t err;
	osMessageQueueId_t msgq_id = osMessageQueueNew(1, sizeof(int), NULL);
	TestAssertNotEq(api_name, 1, NULL, msgq_id);
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(api_name, 2, osOK, err);

	uint32_t count = osMessageQueueGetCount(msgq_id);
	TestAssertEq(api_name, 3, 0, count);
	return;
}
