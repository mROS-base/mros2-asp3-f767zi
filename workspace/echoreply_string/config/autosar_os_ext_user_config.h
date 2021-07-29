#ifndef _AUTOSAR_OS_EXT_USER_CONFIG_H_
#define _AUTOSAR_OS_EXT_USER_CONFIG_H_

#include "cmsis_os.h"

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
#define USER_THREAD_NUM		9U

#endif /* _AUTOSAR_OS_EXT_USER_CONFIG_H_ */
