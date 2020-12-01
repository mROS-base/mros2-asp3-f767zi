#ifndef _ATK2EXT_TEST_H_
#define _ATK2EXT_TEST_H_


#ifdef OS_ATK2



#else

#include "atk2ext_task.h"

extern void	TASKNAME(Atk2ExtTestTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtTest2Task) (intptr_t exinf);


extern void	TASKNAME(Atk2TaskTestControl) (intptr_t exinf);

extern void	TASKNAME(Atk2TaskTestSupplier1) (intptr_t exinf);
extern void	TASKNAME(Atk2TaskTestSupplier2) (intptr_t exinf);
extern void	TASKNAME(Atk2TaskTestSupplier3) (intptr_t exinf);

extern void	TASKNAME(Atk2TaskTestConsumer1) (intptr_t exinf);
extern void	TASKNAME(Atk2TaskTestConsumer2) (intptr_t exinf);
extern void	TASKNAME(Atk2TaskTestConsumer3) (intptr_t exinf);
extern void ALARMCALLBACKNAME(Atk2TestCyclicHandler)(intptr_t exinf);

#endif
/*********************************************
 * Test Functions
 *********************************************/

/*
 * Message Queue
 */
extern void cmsis_message_queue_test_init(void);
extern void cmsis_message_queue_test_start(void);
extern void cmsis_message_queue_test_end(void);
extern int cmsis_message_queue_test_get_exec_num(void);

/*
 * Generic
 */
extern void cmsis_generic_test_init(void);
extern void cmsis_generic_test_start(void);
extern void cmsis_generic_test_end(void);
extern int cmsis_generic_test_get_exec_num(void);

/*
 * Thread
 */
extern void cmsis_thread_test_init(void);
extern void cmsis_thread_test_start(void);
extern void cmsis_thread_test_end(void);
extern int cmsis_thread_test_get_exec_num(void);

/*
 * Memory
 */
extern void atk2memory_test_init(void);
extern void atk2memory_test_start(void);
extern void atk2memory_test_end(void);
extern int atk2memory_test_get_exec_num(void);

/*
 * Kernel
 */
extern void cmsis_kernel_test_init(void);
extern void cmsis_kernel_test_start(void);
extern void cmsis_kernel_test_end(void);
extern int cmsis_kernel_test_get_exec_num(void);

/*
 * Mutexes
 */
extern void cmsis_mutexes_test_init(void);
extern void cmsis_mutexes_test_end(void);
extern void cmsis_mutexes_test_start(void);
extern int cmsis_mutexes_test_get_exec_num(void);

/*
 * Semaphores
 */
extern void cmsis_semaphores_test_init(void);
extern void cmsis_semaphores_test_end(void);
extern void cmsis_semaphores_test_start(void);
extern int cmsis_semaphores_test_get_exec_num(void);

#endif /* _ATK2EXT_TEST_H_ */
