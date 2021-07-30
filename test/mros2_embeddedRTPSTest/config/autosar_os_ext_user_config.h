#ifndef _AUTSAR_OS_EXT_CONFIG_H_
#define _AUTSAR_OS_EXT_CONFIG_H_

#include "autosar_os_ext_common.h"
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

#endif /* _AUTSAR_OS_EXT_CONFIG_H_ */
