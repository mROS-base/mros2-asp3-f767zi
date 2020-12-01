#include "atk2ext_common.h"
#include "cmsis_os.h"
#include "atk2ext_test.h"
#include "atk2ext_testfw.h"
#include "atk2ext_user_config.h"
#include "cmsis_atk2_memory.h"

static void test_alloc_01(void);
static void test_alloc_02(void);

static void test_free_01(void);
static void test_free_02(void);
static void test_free_03(void);

static int exec_cunt = 0U;
static void test_exec(void (*exec_test_func)(void))
{
	exec_test_func();
	exec_cunt++;
	return;
}

#define TESTNAME "atk2memory_test"
void atk2memory_test_init(void)
{
	atk2ext_testfw_start_test(TESTNAME);
	return;
}
void atk2memory_test_end(void)
{
	atk2ext_testfw_end_test();
	return;
}

void atk2memory_test_start(void)
{
	test_exec(test_alloc_01);
	test_exec(test_alloc_02);

	test_exec(test_free_01);
	test_exec(test_free_02);
	test_exec(test_free_03);
	return;
}

int atk2memory_test_get_exec_num(void)
{
	return exec_cunt;
}

static void test_alloc_01(void)
{
	int size = APP_HEAP_SIZE/2;
	void* p = Atk2MemoryAlloc(size);
	TestAssertNotEq("Atk2MemoryAlloc:No.1", 1, NULL, p);
	Atk2MemoryFree(p);
	return;
}

static void test_alloc_02(void)
{
	int size = APP_HEAP_SIZE + 1;
	void* p = Atk2MemoryAlloc(size);
	TestAssertEq("Atk2MemoryAlloc:No.2", 1, NULL, p);
	return;
}
static void test_free_01(void)
{
	int i;
	int num = 4;
	int size = APP_HEAP_SIZE/2;
	for (i = 0; i < num; i++) {
		void* p = Atk2MemoryAlloc(size);
		TestAssertNotEq("Atk2MemoryFree:No.1", i, NULL, p);
		Atk2MemoryFree(p);
	}
	return;
}

#define LOOP_NUM	10
static void test_free_02(void)
{
	int i;
	int size = APP_HEAP_SIZE/10;
	int alloc_num = 0;
	void *p[LOOP_NUM];

	//prepare
	for (i = 0; i < LOOP_NUM; i++) {
		p[i] = Atk2MemoryAlloc(size);
		if (p[i] != NULL) {
			alloc_num++;
		}
	}
	for (i = 0; i < LOOP_NUM; i++) {
		if (p[i] != NULL) {
			Atk2MemoryFree(p[i]);
		}
	}
	//do test
	for (i = 0; i < alloc_num; i++) {
		p[i] = Atk2MemoryAlloc(size);
		TestAssertNotEq("Atk2MemoryFree:No.2", i, NULL, p[i]);
	}
	//cleanup
	for (i = 0; i < LOOP_NUM; i++) {
		if (p[i] != NULL) {
			Atk2MemoryFree(p[i]);
		}
	}
	return;
}

static void test_free_03(void)
{
	int i;
	int size = APP_HEAP_SIZE/3;
	int alloc_num = 0;
	void *p[LOOP_NUM];

	//prepare
	for (i = 0; i < LOOP_NUM; i++) {
		p[i] = Atk2MemoryAlloc(size);
		if (p[i] != NULL) {
			alloc_num++;
		}
	}
	for (i = 0; i < LOOP_NUM; i++) {
		if (p[i] != NULL) {
			Atk2MemoryFree(p[i]);
		}
	}
	//do test
	for (i = 0; i < alloc_num; i++) {
		p[i] = Atk2MemoryAlloc(size);
		TestAssertNotEq("Atk2MemoryFree:No.3", i, NULL, p[i]);
	}
	//cleanup
	for (i = 0; i < LOOP_NUM; i++) {
		if (p[i] != NULL) {
			Atk2MemoryFree(p[i]);
		}
	}
	return;
}
