#if 0
#include "atk2ext_common.h"
#include "cmsis_os.h"
#include <stdlib.h>

#include "atk2ext_sys_config.h"
extern void Atk2ExtTest2Task_Body(void *argument);

typedef struct {
	bool_t		ok;
	uint32_t	actual_value;
} TestResultType;

typedef enum {
	MemoryTest_1 = 0,
	MemoryTest_2,
	MemoryTest_3,
	osDelayTest,
	MessageQueueTest,
	SemaphoreTest,
	MutexTest_1,
	MutexTest_2,
	TestItemNum
} TestItemEnumType;

typedef struct {
	uint32_t		expect_value;
	TestResultType	result;
} TestItemType;

typedef struct {
	bool_t			all_ok;
	uint32_t		ok_num;
	uint32_t		ng_num;
	uint32_t		test_exec_count;
	uint32_t		test_item_num;
	TestItemType	*test_items;
} TestItemContainerType;

#define TEST_ITEM_MEMORY_1_NUM	20U
static TestItemType test_item_memory_1[TEST_ITEM_MEMORY_1_NUM];
#define TEST_ITEM_MEMORY_2_NUM	10U
static TestItemType test_item_memory_2[TEST_ITEM_MEMORY_2_NUM];
#define TEST_ITEM_MEMORY_3_NUM	20U
static TestItemType test_item_memory_3[TEST_ITEM_MEMORY_3_NUM];
#define TEST_ITEM_OS_DELAY_1_NUM	1U
static TestItemType test_item_osDelay_1[TEST_ITEM_OS_DELAY_1_NUM];
#define TEST_ITEM_MESSAGE_QUEUE_1_NUM	14U
static TestItemType test_item_message_queue_1[TEST_ITEM_MESSAGE_QUEUE_1_NUM];
#define TEST_ITEM_SEMAPHORE_1_NUM	8U
static TestItemType test_item_semaphore_1[TEST_ITEM_SEMAPHORE_1_NUM];
#define TEST_ITEM_MUTEX_1_NUM	5U
static TestItemType test_item_mutex_1[TEST_ITEM_MUTEX_1_NUM];
#define TEST_ITEM_MUTEX_2_NUM	9U
static TestItemType test_item_mutex_2[TEST_ITEM_MUTEX_2_NUM];

static TestItemContainerType test_item_container[TestItemNum] = {
		{ .test_item_num = TEST_ITEM_MEMORY_1_NUM, .test_items = test_item_memory_1 },
		{ .test_item_num = TEST_ITEM_MEMORY_2_NUM, .test_items = test_item_memory_2 },
		{ .test_item_num = TEST_ITEM_MEMORY_3_NUM, .test_items = test_item_memory_3 },
		{ .test_item_num = TEST_ITEM_OS_DELAY_1_NUM, .test_items = test_item_osDelay_1 },
		{ .test_item_num = TEST_ITEM_MESSAGE_QUEUE_1_NUM, .test_items = test_item_message_queue_1 },
		{ .test_item_num = TEST_ITEM_SEMAPHORE_1_NUM, .test_items = test_item_semaphore_1 },
		{ .test_item_num = TEST_ITEM_MUTEX_1_NUM, .test_items = test_item_mutex_1 },
		{ .test_item_num = TEST_ITEM_MUTEX_2_NUM, .test_items = test_item_mutex_2 },
};

static void TestStart(TestItemEnumType testType)
{
	test_item_container[testType].test_exec_count = 0;
	test_item_container[testType].all_ok = true;
	test_item_container[testType].ok_num = 0;
	test_item_container[testType].ng_num = 0;
	return;
}

static bool_t TestAssertCommon(TestItemEnumType testType, uint32_t expect_value, uint32_t actual_value)
{
	if (test_item_container[testType].test_exec_count >= test_item_container[testType].test_item_num) {
		test_item_container[testType].ng_num++;
		return false;
	}

	test_item_container[testType].test_items[test_item_container[testType].test_exec_count].expect_value = expect_value;
	test_item_container[testType].test_items[test_item_container[testType].test_exec_count].result.actual_value = actual_value;
	return true;
}

static void TestAssertEq(TestItemEnumType testType, uint32_t expect_value, uint32_t actual_value)
{
	if (!TestAssertCommon(testType, expect_value, actual_value)) {
		return;
	}
	if (expect_value == actual_value) {
		test_item_container[testType].test_items[test_item_container[testType].test_exec_count].result.ok = true;
		test_item_container[testType].ok_num++;
	}
	else {
		test_item_container[testType].test_items[test_item_container[testType].test_exec_count].result.ok = false;
		test_item_container[testType].ng_num++;
	}
	test_item_container[testType].test_exec_count++;
	return;
}
static void TestAssertNotEq(TestItemEnumType testType, uint32_t expect_value, uint32_t actual_value)
{
	if (!TestAssertCommon(testType, expect_value, actual_value)) {
		return;
	}
	if (expect_value != actual_value) {
		test_item_container[testType].test_items[test_item_container[testType].test_exec_count].result.ok = true;
		test_item_container[testType].ok_num++;
	}
	else {
		test_item_container[testType].test_items[test_item_container[testType].test_exec_count].result.ok = false;
		test_item_container[testType].ng_num++;
	}
	test_item_container[testType].test_exec_count++;
	return;
}

/**************************************
 *
 * memory
 *
 **************************************/
/*
 * 1. allocate small size memory 10 times.
 * 2. free those memories
 * 3. allocate small size memory 10 times.
 * 4. free those memories
 */

static void memory_test_1(void)
{
	int i;
	int n = TEST_ITEM_MEMORY_1_NUM/2;
	char *p[TEST_ITEM_MEMORY_1_NUM/2];
	int allocate_size = 12;

	TestStart(MemoryTest_1);

	syslog(LOG_NOTICE, "%s: START", __FUNCTION__);
	/*
	 * 1. allocate small size memory 10 times.
	 */
	for (i = 0; i < n; i++) {
		p[i] = malloc(allocate_size);
		if (p[i] == NULL) {
			syslog(LOG_NOTICE, "NG: can not allocate memory.");
		}
		else {
			syslog(LOG_NOTICE, "OK: allocated memory = 0x%x", p[i]);
		}
		TestAssertNotEq(MemoryTest_1, (uint32_t)NULL, (uint32_t)p[i]);
		osDelay(1);
	}
	/*
	 * 2. free those memories
	 */
	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	/*
	 * 3. allocate small size memory 10 times.
	 */
	for (i = 0; i < n; i++) {
		p[i] = malloc(allocate_size);
		if (p[i] == NULL) {
			syslog(LOG_NOTICE, "NG: can not allocate memory.");
		}
		else {
			syslog(LOG_NOTICE, "OK: allocated memory = 0x%x", p[i]);
		}
		TestAssertNotEq(MemoryTest_1, (uint32_t)NULL, (uint32_t)p[i]);
		osDelay(1);
	}
	/*
	 * 4. free those memories
	 */
	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	syslog(LOG_NOTICE, "%s: END", __FUNCTION__);
	return;
}

/*
 * repeat 10 times following actions:
 * 1. allocate big memory
 * 2. free the memory
 */
static void memory_test_2(void)
{
	int i;
	int n = TEST_ITEM_MEMORY_2_NUM;
	char *p;
	int allocate_size = APP_HEAP_SIZE - 8192;
	syslog(LOG_NOTICE, "%s: START", __FUNCTION__);

	TestStart(MemoryTest_2);
	for (i = 0; i < n; i++) {
		/*
		 * 1. allocate big memory
		 */
		p = malloc(allocate_size);
		if (p == NULL) {
			syslog(LOG_NOTICE, "NG: can not allocate memory.");
		}
		else {
			syslog(LOG_NOTICE, "OK: allocated memory = 0x%x", p);
			/*
			 * 2. free the memory
			 */
			free(p);
		}
		TestAssertNotEq(MemoryTest_2, (uint32_t)NULL, (uint32_t)p);
		osDelay(1);
	}
	syslog(LOG_NOTICE, "%s: END", __FUNCTION__);
	return;
}
/*
 * 1. alloc small memory until no memory.
 * 2. free those memories.
 * 3. alloc small memory until no memory.
 * 4. free those memories.
 */
static void memory_test_3(void)
{
	int i;
	int n = TEST_ITEM_MEMORY_3_NUM/2;
	char *p[TEST_ITEM_MEMORY_3_NUM/2];
	int allocate_size = APP_HEAP_SIZE / 10;

	TestStart(MemoryTest_3);
	syslog(LOG_NOTICE, "%s: START", __FUNCTION__);
	/*
	 * 1. allocate small size memory 10 times.
	 */
	for (i = 0; i < n; i++) {
		p[i] = malloc(allocate_size);
		if (p[i] == NULL) {
			if (i >= 7) {
				syslog(LOG_NOTICE, "OK: %d times allocated. total=%d", i, n);
				TestAssertEq(MemoryTest_3, (uint32_t)NULL, (uint32_t)p[i]);
			}
			else {
				syslog(LOG_NOTICE, "NG: %d times allocated. total=%d expect=%d", i, n, n - 1);
				TestAssertNotEq(MemoryTest_3, (uint32_t)NULL, (uint32_t)p[i]);
			}
		}
		else {
			syslog(LOG_NOTICE, "OK: allocated memory = 0x%x", p[i]);
			TestAssertNotEq(MemoryTest_3, (uint32_t)NULL, (uint32_t)p[i]);
		}
		osDelay(1);
	}
	/*
	 * 2. free those memories
	 */
	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	/*
	 * 3. allocate small size memory 10 times.
	 */
	for (i = 0; i < n; i++) {
		p[i] = malloc(allocate_size);
		if (p[i] == NULL) {
			if (i >= 7) {
				syslog(LOG_NOTICE, "OK: %d times allocated. total=%d", i, n);
				TestAssertEq(MemoryTest_3, (uint32_t)NULL, (uint32_t)p[i]);
			}
			else {
				syslog(LOG_NOTICE, "NG: %d times allocated. total=%d expect=%d", i, n, n - 1);
				TestAssertNotEq(MemoryTest_3, (uint32_t)NULL, (uint32_t)p[i]);
			}
		}
		else {
			syslog(LOG_NOTICE, "OK: allocated memory = 0x%x", p[i]);
			TestAssertNotEq(MemoryTest_3, (uint32_t)NULL, (uint32_t)p[i]);
		}
		osDelay(1);
	}
	/*
	 * 4. free those memories
	 */
	for (i = 0; i < n; i++) {
		free(p[i]);
	}
	syslog(LOG_NOTICE, "%s: END", __FUNCTION__);
	return;
}

static void memory_test(void)
{
	memory_test_1();
	osDelay(1);
	memory_test_2();
	osDelay(1);
	memory_test_3();
	return;
}

/**************************************
 *
 * osDelay
 *
 **************************************/
#define OS_DELAY_TIME	100
static void osDelay_test(void)
{
	osStatus_t err = osOK;

	TestStart(osDelayTest);
	uint32_t t = osKernelGetTickCount();
	syslog(LOG_NOTICE, "Atk2ExtendTestTask activated(%d)!", t);

	uint32_t b_t = osKernelGetTickCount();
	err = osDelay(OS_DELAY_TIME);
	uint32_t a_t = osKernelGetTickCount();

	syslog(LOG_NOTICE, "Atk2ExtendTestTask terminated! err=%d before=%d after=%d", err, b_t, a_t);
	TestAssertEq(osDelayTest, (uint32_t)(b_t + OS_DELAY_TIME), (uint32_t)a_t);
	return;
}

/**************************************
 *
 * MessageQueue
 *
 **************************************/
/*
 * queue size: 2
 *
 * Supplier: Atk2ExtTestTask(priority High)
 * Consumer: Atk2ExtTest2Task(priority Low)
 */

/*
 * test scenario
 *
 * 0. Supplier: activate Task Consumer(but can not activate yet for priority).
 *
 * 1. Supplier: put 3 messages in succession
 *     ==> wait for 1 free
 *
 * 2. Consumer: activated and get 1 message.
 *    ===> sleep 1sec
 *
 * 3. Supplier: waked up and can put 1 message.
 *    ===> sleep 1sec
 *
 * 4. Consumer: get 3 messages in succession
 *     ==> can get 2 messaged but wait for 1 put
 *
 * 5. Supplier: put 1 message.
 *     ===> terminate.
 *
 * 6. Consumer: waked up and can get 1 message.
 *     ===> terminate.
 */
static osMessageQueueId_t msgq_id = NULL;
#define MSG_COUNT	2U
#define MSG_SIZE	4U
#define MSG_TIMEOUT	1000U

static void mq_test_supplier(void)
{
	osStatus_t err;
	int msg_data;
	syslog(LOG_NOTICE, "SUPPLIER:START");
	TestStart(MessageQueueTest);

	msgq_id = osMessageQueueNew(MSG_COUNT, MSG_SIZE, NULL);
	TestAssertNotEq(MessageQueueTest, (uint32_t)NULL, (uint32_t)msgq_id);
	if (msgq_id == NULL) {
		syslog(LOG_NOTICE, "NG: osMessageQueueNew() returns NULL");
		return;
	}

	//0. Supplier: activate Task Consumer(but can not activate yet for priority).
	(void)osThreadNew(Atk2ExtTest2Task_Body, "Message Queue Test", NULL);

	//1. Supplier: put 3 messages in succession
	//     ==> wait for 1 free
	msg_data = 1;
	err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osMessageQueuePut() returns err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueuePut(msg_data=%d)", msg_data);
	}
	msg_data = 2;
	err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osMessageQueuePut() returns err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueuePut(msg_data=%d)", msg_data);
	}
	msg_data = 3;
	err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osMessageQueuePut() returns err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueuePut(msg_data=%d)", msg_data);
	}
	//3. Supplier: waked up and can put 1 message.
	//   ===> sleep 1sec
	osDelay(MSG_TIMEOUT);

	// 5. Supplier: put 1 message.
	//     ===> terminate.
	msg_data = 4;
	err = osMessageQueuePut(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osMessageQueuePut() returns err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueuePut(msg_data=%d)", msg_data);
	}
	osDelay(MSG_TIMEOUT);
	syslog(LOG_NOTICE, "SUPPLIER:END");
	return;
}
static void mq_test_consumer(void)
{
	osStatus_t err;
	int msg_data = 0;
	syslog(LOG_NOTICE, "Consumer:START");

	// 2. Consumer: activated and get 1 message.
	//    ===> sleep 1sec
	err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	TestAssertEq(MessageQueueTest, (uint32_t)msg_data, (uint32_t)1);
	if ((err != osOK) || (msg_data != 1)) {
		syslog(LOG_NOTICE, "NG: osMessageQueueGet() returns err=%d msg_data=%d", err, msg_data);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueueGet(msg_data=%d)", msg_data);
	}

	// 4. Consumer: get 3 messages in succession
	//     ==> can get 2 messaged but wait for 1 put
	err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	TestAssertEq(MessageQueueTest, (uint32_t)msg_data, (uint32_t)2);
	if ((err != osOK) || (msg_data != 2)) {
		syslog(LOG_NOTICE, "NG: osMessageQueueGet() returns err=%d msg_data=%d", err, msg_data);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueueGet(msg_data=%d)", msg_data);
	}
	err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	TestAssertEq(MessageQueueTest, (uint32_t)msg_data, (uint32_t)3);
	if ((err != osOK) || (msg_data != 3)) {
		syslog(LOG_NOTICE, "NG: osMessageQueueGet() returns err=%d msg_data=%d", err, msg_data);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueueGet(msg_data=%d)", msg_data);
	}
	err = osMessageQueueGet(msgq_id, (void*)&msg_data, 0, MSG_TIMEOUT);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	TestAssertEq(MessageQueueTest, (uint32_t)msg_data, (uint32_t)4);
	if ((err != osOK) || (msg_data != 4)) {
		syslog(LOG_NOTICE, "NG: osMessageQueueGet() returns err=%d msg_data=%d", err, msg_data);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueueGet(msg_data=%d)", msg_data);
	}

	// 6. Consumer: waked up and can get 1 message.
	//     ===> terminate.
	err = osMessageQueueDelete(msgq_id);
	TestAssertEq(MessageQueueTest, (uint32_t)err, (uint32_t)osOK);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osMessageQueueDelete() err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osMessageQueueDelete() err=%d", err);
	}
	msgq_id = NULL;
	syslog(LOG_NOTICE, "Consumer:END");
	return;
}
/**************************************
 *
 * semaphore
 *
 **************************************/
/*
 * max count: 2
 * ini count: 2
 *
 * Consumer: Atk2ExtTestTask(priority High)
 * Supplier: Atk2ExtTest2Task(priority Low)
 */

/*
 * test scenario
 *
 * 0. Consumer: activate Task Supplier(but can not activate yet for priority).
 *
 * 1. Consumer: acquire 3 tokens in succession
 *     ==> wait for 1 free
 *
 * 2. Supplier: activated and release 1 token.
 *    ===> sleep 1sec
 *
 * 3. Consumer: waked up and can acquire 1 token.
 *     ===> terminate.
 *
 */
static osSemaphoreId_t semid = NULL;
#define SEM_MAX_COUNT	2
#define SEM_INI_COUNT	2
#define SEM_TIMEOUT	1000U
static void sem_consumer(void)
{
	osStatus_t err;
	syslog(LOG_NOTICE, "SEM: Consumer:START");

	TestStart(SemaphoreTest);

	semid = osSemaphoreNew(SEM_MAX_COUNT, SEM_INI_COUNT, NULL);
	TestAssertNotEq(SemaphoreTest, (uint32_t)NULL, (uint32_t)semid);
	if (semid == NULL) {
		syslog(LOG_NOTICE, "NG: osSemaphoreNew returns NULL");
		return;
	}
	// 0. Consumer: activate Task Supplier(but can not activate yet for priority).
	(void)osThreadNew(Atk2ExtTest2Task_Body, "Semaphore Test", NULL);

	// 1. Consumer: acquire 3 tokens in succession
	//     ==> wait for 1 free
	err = osSemaphoreAcquire(semid, SEM_TIMEOUT);
	TestAssertEq(SemaphoreTest, (uint32_t)osOK, (uint32_t)err);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osSemaphoreAcquire(1) failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreAcquire(1)");
	}
	err = osSemaphoreAcquire(semid, SEM_TIMEOUT);
	TestAssertEq(SemaphoreTest, (uint32_t)osOK, (uint32_t)err);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osSemaphoreAcquire(2) failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreAcquire(2)");
	}
	err = osSemaphoreAcquire(semid, SEM_TIMEOUT);
	TestAssertEq(SemaphoreTest, (uint32_t)osOK, (uint32_t)err);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osSemaphoreAcquire(3) failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreAcquire(3)");
	}
	// 3. Consumer: waked up and can acquire 1 token.
	//     ===> terminate.
	osDelay(SEM_TIMEOUT);
	semid = NULL;
	syslog(LOG_NOTICE, "SEM: Consumer:END");
	return;
}
static void sem_supplier(void)
{
	osStatus_t err;

	syslog(LOG_NOTICE, "SEM: Supplier:START");
	// 2. Supplier: activated and release 1 token.
	//    ===> sleep 1sec
	err = osSemaphoreRelease(semid);
	TestAssertEq(SemaphoreTest, (uint32_t)osOK, (uint32_t)err);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osSemaphoreRelease() failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreRelease()");
	}
	err = osSemaphoreRelease(semid);
	TestAssertEq(SemaphoreTest, (uint32_t)osOK, (uint32_t)err);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osSemaphoreRelease(1) failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreRelease(1)");
	}
	err = osSemaphoreRelease(semid);
	TestAssertEq(SemaphoreTest, (uint32_t)osOK, (uint32_t)err);
	if (err != osOK) {
		syslog(LOG_NOTICE, "NG: osSemaphoreRelease(2) failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreRelease(2)");
	}
	err = osSemaphoreRelease(semid);
	TestAssertEq(SemaphoreTest, (uint32_t)osErrorResource, (uint32_t)err);
	if (err != osErrorResource) {
		syslog(LOG_NOTICE, "NG: osSemaphoreRelease(3) failed err=%d", err);
	}
	else {
		syslog(LOG_NOTICE, "OK: osSemaphoreRelease(3): osErrorResource");
	}

	syslog(LOG_NOTICE, "SEM: Supplier:END");
	return;
}
/**************************************
 *
 * Mutex
 *
 **************************************/
/*
 * 1stLocker: Atk2ExtTestTask(priority High)
 * 2ndLocker: Atk2ExtTest2Task(priority Low)
 */

/*
 * test scenario
 *
 * 0. 1stLocker: activate Task 2ndLocker(but can not activate yet for priority).
 *
 * 1. 1stLocker: lock
 *     ==> wait for 1 free
 *
 * 2. 2ndLocker: activated and lock.
 *    ===> wait for unlock
 *
 * 3. 1stLocker: unlock
 *     ===> terminate.
 *
 * 4. 2ndLocker: unlock
 *     ===> terminate.
 */
static osMutexId_t mutexid = NULL;
#define MUTEX_TIMEOUT	1000U
static int mutex_lock_count = 1;
static TestItemEnumType current_mutex_test = MutexTest_1;
static void mutex_locker(int id, int count)
{
	int i;
	osStatus_t err;

	if (id == 0) {
		syslog(LOG_NOTICE, "MUTEX: 1stLocker:START");
		osMutexAttr_t attr;
		if (count > 1) {
			current_mutex_test = MutexTest_2;
			attr.attr_bits = osMutexRecursive;
			mutexid = osMutexNew(&attr);
		}
		else {
			current_mutex_test = MutexTest_1;
			mutexid = osMutexNew(NULL);
		}
		TestStart(current_mutex_test);
		TestAssertNotEq(current_mutex_test, (uint32_t)NULL, (uint32_t)mutexid);

		if (mutexid == NULL) {
			syslog(LOG_NOTICE, "NG: osMutexNew returns NULL");
			return;
		}
		// 0. 1stLocker: activate Task 2ndLocker(but can not activate yet for priority).
		(void)osThreadNew(Atk2ExtTest2Task_Body, "Mutex Test", NULL);
	}
	else {
		syslog(LOG_NOTICE, "MUTEX: 2ndLocker:START");
	}

	// 1. lock
	//     ==> wait for 1 free
	for (i = 0; i < count; i++) {
		err = osMutexAcquire(mutexid, MUTEX_TIMEOUT * 2);
		TestAssertEq(current_mutex_test, (uint32_t)osOK, (uint32_t)err);
		if (err != osOK) {
			syslog(LOG_NOTICE, "NG: [%d] osMutexAcquire(%d) failed err=%d", id, i, err);
		}
		else {
			syslog(LOG_NOTICE, "OK: [%d] osMutexAcquire(%d)", id, i);
		}
	}
	if (id == 0) {
		osDelay(1);
	}

	// 3. unlock
	//     ===> terminate.
	for (i = 0; i < count; i++) {
		err = osMutexRelease(mutexid);
		TestAssertEq(current_mutex_test, (uint32_t)osOK, (uint32_t)err);
		if (err != osOK) {
			syslog(LOG_NOTICE, "NG: [%d] osMutexRelease(%d) failed err=%d", id, i, err);
		}
		else {
			syslog(LOG_NOTICE, "OK: [%d] osMutexRelease(%d)", id, i);
		}
	}
	if (id == 0) {
		osDelay(MUTEX_TIMEOUT);
		syslog(LOG_NOTICE, "MUTEX: 1stLocker:END");
	}
	else {
		syslog(LOG_NOTICE, "MUTEX: 2ndLocker:END");
		osMutexDelete(mutexid);
		mutexid = NULL;
	}
	return;
}

static void Atk2ExtTestTask_Body(void *argument)
{
	syslog(LOG_NOTICE, "### TEST START");

	memory_test();
	osDelay_test();
	mq_test_supplier();
	sem_consumer();
	mutex_lock_count = 1;
	mutex_locker(0, mutex_lock_count);
	mutex_lock_count = 2;
	mutex_locker(0, mutex_lock_count);

	syslog(LOG_NOTICE, "### TEST END");
	return;
}

void Atk2ExtTest2Task_Body(void *argument)
{
	syslog(LOG_NOTICE, "Atk2ExTest2Task activated: %s", argument);
	if (msgq_id != NULL) {
		mq_test_consumer();
	}
	else if (semid != NULL) {
		sem_supplier();
	}
	else if (mutexid != NULL) {
		mutex_locker(1, mutex_lock_count);
	}
	syslog(LOG_NOTICE, "Atk2ExTest2Task terminated");
	return;
}

TASK(Atk2ExtTestTask)
{
	Atk2ExtTestTask_Body(NULL);

	TerminateTask();
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

#endif

#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_sys_config.h"
#include "atk2ext_test.h"
#include "atk2ext_testfw.h"

TestFwOperationType test_fw_operations[TEST_FW_OP_NUM] = {
		TEST_FW_OP_ENTRY(cmsis_kernel_test),
		TEST_FW_OP_ENTRY(cmsis_generic_test),
		TEST_FW_OP_ENTRY(cmsis_mutexes_test),
		TEST_FW_OP_ENTRY(cmsis_semaphores_test),
		TEST_FW_OP_ENTRY(atk2memory_test),
		TEST_FW_OP_ENTRY(cmsis_thread_test),
		TEST_FW_OP_ENTRY(cmsis_message_queue_test),
};

Atk2ExtTestFwFuncMapEntryType atk2ext_testfw_funcmap[USER_THREAD_NUM] = {
		{ .TaskID = Atk2TaskTestControl, .func = NULL },
		{ .TaskID = Atk2TaskTestSupplier1, .func = NULL },
		{ .TaskID = Atk2TaskTestSupplier2, .func = NULL },
		{ .TaskID = Atk2TaskTestSupplier3, .func = NULL },
		{ .TaskID = Atk2TaskTestConsumer1, .func = NULL },
		{ .TaskID = Atk2TaskTestConsumer2, .func = NULL },
		{ .TaskID = Atk2TaskTestConsumer3, .func = NULL },
};


TASK(Atk2TaskTestControl)
{
	int i;
	for (i = 0; i < TEST_FW_OP_NUM; i++) {
		test_fw_operations[i].init();
		test_fw_operations[i].start();
		test_fw_operations[i].end();
	}
	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2TaskTestSupplier1)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2TaskTestSupplier2)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}
TASK(Atk2TaskTestSupplier3)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2TaskTestConsumer1)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2TaskTestConsumer2)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}

TASK(Atk2TaskTestConsumer3)
{
	UserThreadAtk2TaskMapEntryType config;
	StatusType ercd = Atk2TaskConfigGet(&config);

	if (ercd == E_OK) {
		config.func(config.argument);
	}

	(void)osThreadTerminate(NULL);
	return;
}


static void Atk2TaskTestCommon_Body(void *argument)
{
	void (*func) (void*)  = NULL;

	atk2ext_testfw_getfunc(&func);
	if (func != NULL) {
		func(argument);
	}
	return;
}
void Atk2TaskTestConsumer1_Body(void *argument)
{
	Atk2TaskTestCommon_Body(argument);
	return;
}
void Atk2TaskTestConsumer2_Body(void *argument)
{
	Atk2TaskTestCommon_Body(argument);
	return;
}
void Atk2TaskTestConsumer3_Body(void *argument)
{
	Atk2TaskTestCommon_Body(argument);
	return;
}

void Atk2TaskTestSupplier1_Body(void *argument)
{
	Atk2TaskTestCommon_Body(argument);
	return;
}
void Atk2TaskTestSupplier2_Body(void *argument)
{
	Atk2TaskTestCommon_Body(argument);
	return;
}
void Atk2TaskTestSupplier3_Body(void *argument)
{
	Atk2TaskTestCommon_Body(argument);
	return;
}
