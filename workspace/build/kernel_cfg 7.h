/* kernel_cfg.h */
#ifndef TOPPERS_KERNEL_CFG_H
#define TOPPERS_KERNEL_CFG_H

#define TNUM_TSKID	13
#define TSKID_tTask_LogTask_Task	1
#define AutosarOsExtCyclicTask	2
#define AutosarOsExtTcpTask	3
#define AutosarOsExtEthIfLinkTask	4
#define AutosarOsExtEthInputTask	5
#define AutosarOsExtHBPubTask	6
#define AutosarOsExtHBSubTask	7
#define AutosarOsExtSPDPTask	8
#define AutosarOsExtWriterTask	9
#define AutosarOsExtReaderTask	10
#define AutosarOsExtUserDefaultTask	11
#define AutosarOsExtMROS2Task	12
#define MAIN_TASK	13

#define TNUM_SEMID	2
#define SEMID_tSemaphore_SerialPort1_ReceiveSemaphore	1
#define SEMID_tSemaphore_SerialPort1_SendSemaphore	2

#define TNUM_FLGID	12
#define AutosarOsExtCyclicTask_FLG	1
#define AutosarOsExtTcpTask_FLG	2
#define AutosarOsExtEthIfLinkTask_FLG	3
#define AutosarOsExtEthInputTask_FLG	4
#define AutosarOsExtHBPubTask_FLG	5
#define AutosarOsExtHBSubTask_FLG	6
#define AutosarOsExtSPDPTask_FLG	7
#define AutosarOsExtWriterTask_FLG	8
#define AutosarOsExtReaderTask_FLG	9
#define AutosarOsExtUserDefaultTask_FLG	10
#define AutosarOsExtMROS2Task_FLG	11
#define MAIN_TASK_FLG	12

#define TNUM_DTQID	0

#define TNUM_PDQID	0

#define TNUM_MTXID	0

#define TNUM_MPFID	0

#define TNUM_CYCID	2
#define AutosarOsExtCyclic	1
#define LED_CYCHDR	2

#define TNUM_ALMID	0

#define TNUM_ISRID	2
#define ISRID_tISR_SIOPortTarget1_ISRInstance	1
#define ETH_IRQ_HANDLER	2

#define TNUM_INIRTN	2

#define TNUM_TERRTN	2

#endif /* TOPPERS_KERNEL_CFG_H */
