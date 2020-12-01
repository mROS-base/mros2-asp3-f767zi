#ifndef _ATK2EXT_TESTFW_H_
#define _ATK2EXT_TESTFW_H_

#include "atk2ext_common.h"
#include "atk2ext_user_config.h"
#include <string.h>

typedef struct {
	TaskType TaskID;
	void (*func) (void*);
} Atk2ExtTestFwFuncMapEntryType;
extern Atk2ExtTestFwFuncMapEntryType atk2ext_testfw_funcmap[USER_THREAD_NUM];

extern void atk2ext_testfw_setfunc(TaskType TaskID, void (*func) (void*));
extern void atk2ext_testfw_getfunc(void (**func) (void*));
extern void atk2ext_testfw_clrfunc(void);


extern void atk2ext_testfw_start_test(const char* name);
extern void atk2ext_testfw_end_test(void);
extern void atk2ext_testfw_failed_callback(const char *testname, int testno);

#define TestAssertEq(testname, testno, expect_value, actual_value)	\
do {	\
	if ((actual_value) == (expect_value)) { \
		/* syslog(LOG_NOTICE, " PASSED:<%s:%d> value(0x%lx) == expect_value(0x%lx)", testname, testno, actual_value, expect_value);*/ \
	} \
	else { \
		atk2ext_testfw_failed_callback(testname, testno);	\
		syslog(LOG_NOTICE, " FAILED:<%s:%d> value(0x%lx) != expect_value(0x%lx)", testname, testno, actual_value, expect_value); \
		syslog(LOG_NOTICE, " %s %s() line=%d", __FILE__, __FUNCTION__, __LINE__); \
	} \
} while (0)

#define TestAssertNotEq(testname, testno, expect_value, actual_value)	\
do {	\
	if ((actual_value) != (expect_value)) { \
		/* syslog(LOG_NOTICE, " PASSED:<%s:%d> value(0x%lx) != expect_value(0x%lx)", testname, testno, actual_value, expect_value); */ \
	} \
	else { \
		atk2ext_testfw_failed_callback(testname, testno);	\
		syslog(LOG_NOTICE, " FAILED:<%s:%d> value(0x%lx) == expect_value(0x%lx)", testname, testno, actual_value, expect_value); \
		syslog(LOG_NOTICE, " %s %s() line=%d", __FILE__, __FUNCTION__, __LINE__); \
	} \
} while (0)


#define TestAssertStringEq(testname, testno, expect_value, actual_value)	\
do {	\
	int expect_len = strlen(expect_value);	\
	int actual_len = strlen(actual_value);	\
	if ((expect_len == actual_len) && !strncmp(expect_value, actual_value, actual_len)) { \
		/* syslog(LOG_NOTICE, " PASSED:<%s:%d> value(%s) == expect_value(%s)", testname, testno, actual_value, expect_value); */ \
	} \
	else { \
		atk2ext_testfw_failed_callback(testname, testno);	\
		syslog(LOG_NOTICE, " FAILED:<%s:%d> value(%s) != expect_value(%s)", testname, testno, actual_value, expect_value); \
		syslog(LOG_NOTICE, " %s %s() line=%d", __FILE__, __FUNCTION__, __LINE__); \
	} \
} while (0)

#define TestAssertInRange(testname, testno, expect_value_mini, expect_value_max, actual_value)	\
do {	\
	if (((expect_value_mini) <= (actual_value)) && ((actual_value) <= (expect_value_max))) { \
		/* syslog(LOG_NOTICE, " PASSED:<%s:%d> value(0x%lx) == expect_value(0x%lx)", testname, testno, actual_value, expect_value);*/ \
	} \
	else { \
		atk2ext_testfw_failed_callback(testname, testno);	\
		syslog(LOG_NOTICE, " FAILED:<%s:%d> expect_value_mini(0x%lx) <= value(0x%lx) <= expect_value_max(%d)", testname, testno, expect_value_mini, actual_value, expect_value_max); \
		syslog(LOG_NOTICE, " %s %s() line=%d", __FILE__, __FUNCTION__, __LINE__); \
	} \
} while (0)


extern void atk2ext_testfw_set_cyclic_handler_func(void (*func) (void), void *argp);
extern void atk2ext_testfw_clr_cyclic_handler_func(void);
extern void *atk2ext_testfw_get_cyclic_handler_argp(void);


typedef struct {
	bool_t result;
	char* testname;
	void (*init) (void);
	void (*start) (void);
	void (*end) (void);
	int (*get_exec_num) (void);
} TestFwOperationType;

#define TEST_FW_OP_NUM	7U
extern TestFwOperationType test_fw_operations[TEST_FW_OP_NUM];

#define TEST_FW_OP_ENTRY(name)	\
		{ .result = true, .testname = #name, .init = name ## _init , .start = name ## _start , .end = name ## _end , .get_exec_num = name ## _get_exec_num }


#endif /* _ATK2EXT_TESTFW_H_ */
