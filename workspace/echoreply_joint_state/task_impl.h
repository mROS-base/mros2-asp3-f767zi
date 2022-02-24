#ifndef _AUTOSAR_OS_EXT_TEST_H_
#define _AUTOSAR_OS_EXT_TEST_H_

#include "cmsis_config_utl.h"

extern void	TASKNAME(AutosarOsExtTcpTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtEthIfLinkTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtEthInputTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtHBPubTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtHBSubTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtSPDPTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtWriterTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtReaderTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtUserDefaultTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtMROS2Task) (intptr_t exinf);

/*
 * priorities of mROS 2 tasks for RTPS
 *
 * TODO: We assigned relatevely lower priorities for EthIfLinkTask and
 * EthInputTask than the application. Check whether these are appropriate.
 */
#define MROS2_HIGH_PRIORITY MAIN_PRIORITY
#define MROS2_LOW_PRIORITY  LOW_PRIORITY+1

/*
 * experimental: stack size of mROS 2 tasks for RTPS
 * Each comment refers the location of original definition
 */
// application/include/lwipopt.h
// #define TCPIP_THREAD_STACKSIZE 1024
#define MROS2_STACK_SIZE_TcpTask 1024
// application/src/lwip.c
// #define INTERFACE_THREAD_STACK_SIZE ( 1024 )
#define MROS2_STACK_SIZE_EthIfLinkTask 1024
// application/src/ethernet.c
// #define INTERFACE_THREAD_STACK_SIZE ( 350 )
#define MROS2_STACK_SIZE_EthInputTask 350
// embeddedRTPS/include/config.h
// const int HEARTBEAT_STACKSIZE = 1200;          // byte
#define MROS2_STACK_SIZE_HBPubTask 1200
#define MROS2_STACK_SIZE_HBSubTask 1200
// const uint16_t SPDP_WRITER_STACKSIZE = 550;    // byte
#define MROS2_STACK_SIZE_SPDPTask 550
// const int THREAD_POOL_WRITER_STACKSIZE = 1100; // byte
#define MROS2_STACK_SIZE_WriterTask 1100
// const int THREAD_POOL_READER_STACKSIZE = 1600; // byte
#define MROS2_STACK_SIZE_ReaderTask 1600
// embeddedRTPS-STM32/stm32/Src/main.cpp
// osThreadDef(defaultTask, StartDefaultTask, osPriorityRealtime, 0, 250);
#define MROS2_STACK_SIZE_UserDefaultTask 500


#endif /* _AUTOSAR_OS_EXT_TEST_H_ */
