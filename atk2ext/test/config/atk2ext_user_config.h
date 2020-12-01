#ifndef _ATK2EXT_CONFIG_H_
#define _ATK2EXT_CONFIG_H_

/***********************************************
 *
 * MEMORY
 *
 ***********************************************/
#define APP_HEAP_SIZE	(16 * 1024) /* 16KB */


/***********************************************
 *
 * THREAD
 *
 ***********************************************/
#define USER_THREAD_NUM		(7U)

extern void Atk2TaskTestConsumer1_Body(void *argument);
extern void Atk2TaskTestConsumer2_Body(void *argument);
extern void Atk2TaskTestConsumer3_Body(void *argument);

extern void Atk2TaskTestSupplier1_Body(void *argument);
extern void Atk2TaskTestSupplier2_Body(void *argument);
extern void Atk2TaskTestSupplier3_Body(void *argument);

#endif /* _ATK2EXT_CONFIG_H_ */
