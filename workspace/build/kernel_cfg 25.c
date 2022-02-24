/* kernel_cfg.c */
#include "kernel/kernel_int.h"
#include "kernel_cfg.h"

#if !(TKERNEL_PRID == 0x0007U && (TKERNEL_PRVER & 0xf000U) == 0x3000U)
#error The kernel does not match this configuration file.
#endif

/*
 *  Include Directives
 */

#include "target_timer.h"
#ifdef USE_SYSTICK_AS_TIMETICK
#else
#ifdef USE_TIM_AS_HRT
#endif
#endif
#include "tTask_tecsgen.h"
#include "tISR_tecsgen.h"
#include "tInitializeRoutine_tecsgen.h"
#include "tTerminateRoutine_tecsgen.h"
#include "autosar_os_ext_task.h"
#include "task_impl.h"
#include "app.h"
#include "stm32f7xx_it.h"

/*
 *  Task Management Functions
 */

const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);

static STK_T _kernel_stack_TSKID_tTask_LogTask_Task[COUNT_STK_T(4096)];
static STK_T _kernel_stack_AutosarOsExtCyclicTask[COUNT_STK_T(592)];
static STK_T _kernel_stack_AutosarOsExtTcpTask[COUNT_STK_T(MROS2_STACK_SIZE_TcpTask)];
static STK_T _kernel_stack_AutosarOsExtEthIfLinkTask[COUNT_STK_T(MROS2_STACK_SIZE_EthIfLinkTask)];
static STK_T _kernel_stack_AutosarOsExtEthInputTask[COUNT_STK_T(MROS2_STACK_SIZE_EthInputTask)];
static STK_T _kernel_stack_AutosarOsExtHBPubTask[COUNT_STK_T(MROS2_STACK_SIZE_HBPubTask)];
static STK_T _kernel_stack_AutosarOsExtHBSubTask[COUNT_STK_T(MROS2_STACK_SIZE_HBSubTask)];
static STK_T _kernel_stack_AutosarOsExtSPDPTask[COUNT_STK_T(MROS2_STACK_SIZE_SPDPTask)];
static STK_T _kernel_stack_AutosarOsExtWriterTask[COUNT_STK_T(MROS2_STACK_SIZE_WriterTask)];
static STK_T _kernel_stack_AutosarOsExtReaderTask[COUNT_STK_T(MROS2_STACK_SIZE_ReaderTask)];
static STK_T _kernel_stack_AutosarOsExtUserDefaultTask[COUNT_STK_T(MROS2_STACK_SIZE_UserDefaultTask)];
static STK_T _kernel_stack_AutosarOsExtMROS2Task[COUNT_STK_T(MROS2_STACK_SIZE_UserDefaultTask)];
static STK_T _kernel_stack_MAIN_TASK[COUNT_STK_T(STACK_SIZE)];
const TINIB _kernel_tinib_table[TNUM_TSKID] = {
	{ (TA_ACT), (intptr_t)(&tTask_INIB_tab[0]), (TASK)(tTask_start), INT_PRIORITY(3), {	(void *)(_kernel_stack_TSKID_tTask_LogTask_Task), 	((void *)((char *)(_kernel_stack_TSKID_tTask_LogTask_Task) + (ROUND_STK_T(4096)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtCyclicTask)), INT_PRIORITY(TMIN_TPRI), {	(void *)(_kernel_stack_AutosarOsExtCyclicTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtCyclicTask) + (ROUND_STK_T(592)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtTcpTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtTcpTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtTcpTask) + (ROUND_STK_T(MROS2_STACK_SIZE_TcpTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtEthIfLinkTask)), INT_PRIORITY(MROS2_LOW_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtEthIfLinkTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtEthIfLinkTask) + (ROUND_STK_T(MROS2_STACK_SIZE_EthIfLinkTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtEthInputTask)), INT_PRIORITY(MROS2_LOW_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtEthInputTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtEthInputTask) + (ROUND_STK_T(MROS2_STACK_SIZE_EthInputTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtHBPubTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtHBPubTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtHBPubTask) + (ROUND_STK_T(MROS2_STACK_SIZE_HBPubTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtHBSubTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtHBSubTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtHBSubTask) + (ROUND_STK_T(MROS2_STACK_SIZE_HBSubTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtSPDPTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtSPDPTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtSPDPTask) + (ROUND_STK_T(MROS2_STACK_SIZE_SPDPTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtWriterTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtWriterTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtWriterTask) + (ROUND_STK_T(MROS2_STACK_SIZE_WriterTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtReaderTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtReaderTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtReaderTask) + (ROUND_STK_T(MROS2_STACK_SIZE_ReaderTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtUserDefaultTask)), INT_PRIORITY(MROS2_HIGH_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtUserDefaultTask), 	((void *)((char *)(_kernel_stack_AutosarOsExtUserDefaultTask) + (ROUND_STK_T(MROS2_STACK_SIZE_UserDefaultTask)))), }, },
	{ (TA_NULL), (intptr_t)(1), (TASK)(TASKNAME(AutosarOsExtMROS2Task)), INT_PRIORITY(MID_PRIORITY), {	(void *)(_kernel_stack_AutosarOsExtMROS2Task), 	((void *)((char *)(_kernel_stack_AutosarOsExtMROS2Task) + (ROUND_STK_T(MROS2_STACK_SIZE_UserDefaultTask)))), }, },
	{ (TA_ACT), (intptr_t)(0), (TASK)(main_task), INT_PRIORITY(MAIN_PRIORITY), {	(void *)(_kernel_stack_MAIN_TASK), 	((void *)((char *)(_kernel_stack_MAIN_TASK) + (ROUND_STK_T(STACK_SIZE)))), }, }
};

TCB _kernel_tcb_table[TNUM_TSKID];

const ID _kernel_torder_table[TNUM_TSKID] = { 
	TSKID_tTask_LogTask_Task, AutosarOsExtCyclicTask, AutosarOsExtTcpTask, AutosarOsExtEthIfLinkTask, AutosarOsExtEthInputTask, AutosarOsExtHBPubTask, AutosarOsExtHBSubTask, AutosarOsExtSPDPTask, AutosarOsExtWriterTask, AutosarOsExtReaderTask, AutosarOsExtUserDefaultTask, AutosarOsExtMROS2Task, MAIN_TASK
};

/*
 *  Semaphore Functions
 */

const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);

const SEMINIB _kernel_seminib_table[TNUM_SEMID] = {
	{ (TA_NULL), (0), (1) },
	{ (TA_NULL), (1), (1) }
};

SEMCB _kernel_semcb_table[TNUM_SEMID];

/*
 *  Eventflag Functions
 */

const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);

const FLGINIB _kernel_flginib_table[TNUM_FLGID] = {
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) },
	{ (TA_TPRI|TA_WMUL), (0) }
};

FLGCB _kernel_flgcb_table[TNUM_FLGID];

/*
 *  Dataqueue Functions
 */

const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);

TOPPERS_EMPTY_LABEL(const DTQINIB, _kernel_dtqinib_table);
TOPPERS_EMPTY_LABEL(DTQCB, _kernel_dtqcb_table);

/*
 *  Priority Dataqueue Functions
 */

const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);

TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);
TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);

/*
 *  Mutex Functions
 */

const ID _kernel_tmax_mtxid = (TMIN_MTXID + TNUM_MTXID - 1);

TOPPERS_EMPTY_LABEL(const MTXINIB, _kernel_mtxinib_table);
TOPPERS_EMPTY_LABEL(MTXCB, _kernel_mtxcb_table);

/*
 *  Fixed-sized Memorypool Functions
 */

const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);

TOPPERS_EMPTY_LABEL(const MPFINIB, _kernel_mpfinib_table);
TOPPERS_EMPTY_LABEL(MPFCB, _kernel_mpfcb_table);

/*
 *  Cyclic Notification Functions
 */

const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);

const CYCINIB _kernel_cycinib_table[TNUM_CYCID] = {
	{ (TA_STA), (intptr_t)(0), (NFYHDR)(ALARMCALLBACKNAME(AutosarOsExtCyclicHandler)), (1000), (10000) },
	{ (TA_STA), (intptr_t)(0), (NFYHDR)(led_cyclic_handler), (1000000), (0) }
};

CYCCB _kernel_cyccb_table[TNUM_CYCID];

/*
 *  Alarm Notification Functions
 */

const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);

TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);
TOPPERS_EMPTY_LABEL(ALMCB, _kernel_almcb_table);

/*
 *  Interrupt Management Functions
 */

#ifndef LOG_ISR_ENTER
#define LOG_ISR_ENTER(isrid)
#endif /* LOG_ISR_ENTER */

#ifndef LOG_ISR_LEAVE
#define LOG_ISR_LEAVE(isrid)
#endif /* LOG_ISR_LEAVE */

void
_kernel_inthdr_55(void)
{
	LOG_ISR_ENTER(ISRID_tISR_SIOPortTarget1_ISRInstance);
	((ISR)(tISR_start))((intptr_t)(&tISR_INIB_tab[0]));
	LOG_ISR_LEAVE(ISRID_tISR_SIOPortTarget1_ISRInstance);
}

void
_kernel_inthdr_77(void)
{
	LOG_ISR_ENTER(ETH_IRQ_HANDLER);
	((ISR)(ETH_IRQHandler))((intptr_t)(0));
	LOG_ISR_LEAVE(ETH_IRQ_HANDLER);
}

#define TNUM_DEF_INHNO	3
const uint_t _kernel_tnum_def_inhno = TNUM_DEF_INHNO;

INTHDR_ENTRY(INHNO_TIMER, 66, target_hrt_handler)
INTHDR_ENTRY(55, 55, _kernel_inthdr_55)
INTHDR_ENTRY(77, 77, _kernel_inthdr_77)

const INHINIB _kernel_inhinib_table[TNUM_DEF_INHNO] = {
	{ (INHNO_TIMER), (TA_NULL), (FP)(INT_ENTRY(INHNO_TIMER, target_hrt_handler)) },
	{ (55), (TA_NULL), (FP)(INT_ENTRY(55, _kernel_inthdr_55)) },
	{ (77), (TA_NULL), (FP)(INT_ENTRY(77, _kernel_inthdr_77)) }
};

#define TNUM_CFG_INTNO	3
const uint_t _kernel_tnum_cfg_intno = TNUM_CFG_INTNO;

const INTINIB _kernel_intinib_table[TNUM_CFG_INTNO] = {
	{ (INTNO_TIMER), (TA_ENAINT|INTATR_TIMER), (INTPRI_TIMER) },
	{ (USART_INTNO), (TA_NULL), (-2) },
	{ (77), (TA_EDGE), (-4) }
};

/*
 *  CPU Exception Management Functions
 */

#define TNUM_DEF_EXCNO	0
const uint_t _kernel_tnum_def_excno = TNUM_DEF_EXCNO;

TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);

/*
 *  Stack Area for Non-task Context
 */

static STK_T _kernel_istack[COUNT_STK_T(DEFAULT_ISTKSZ)];
const size_t _kernel_istksz = ROUND_STK_T(DEFAULT_ISTKSZ);
STK_T *const _kernel_istk = _kernel_istack;

#ifdef TOPPERS_ISTKPT
STK_T *const _kernel_istkpt = TOPPERS_ISTKPT(_kernel_istack, ROUND_STK_T(DEFAULT_ISTKSZ));
#endif /* TOPPERS_ISTKPT */

/*
 *  Time Event Management
 */

TMEVTN   _kernel_tmevt_heap[1 + TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];

/*
 *  Module Initialization Function
 */

void
_kernel_initialize_object(void)
{
	_kernel_initialize_task();
	_kernel_initialize_semaphore();
	_kernel_initialize_eventflag();
	_kernel_initialize_cyclic();
	_kernel_initialize_interrupt();
	_kernel_initialize_exception();
}

/*
 *  Initialization Routine
 */

const uint_t _kernel_tnum_inirtn = TNUM_INIRTN;

const INIRTNB _kernel_inirtnb_table[TNUM_INIRTN] = {
	{ (INIRTN)(target_hrt_initialize), (intptr_t)(0) },
	{ (INIRTN)(tInitializeRoutine_start), (intptr_t)(NULL) }
};

/*
 *  Termination Routine
 */

const uint_t _kernel_tnum_terrtn = TNUM_TERRTN;

const TERRTNB _kernel_terrtnb_table[TNUM_TERRTN] = {
	{ (TERRTN)(tTerminateRoutine_start), (intptr_t)(NULL) },
	{ (TERRTN)(target_hrt_terminate), (intptr_t)(0) }
};

/*
 *  Target-dependent Definitions (ARM-M)
 */

/*
 *  ベクターテーブル
 */
__attribute__ ((section(".vector")))
const FP _kernel_vector_table[] = {
    (FP)(TOPPERS_ISTKPT(_kernel_istack, ROUND_STK_T(DEFAULT_ISTKSZ))),   /* 0 The initial stack pointer */
    (FP)_kernel_start,                 /* 1 The reset handler */
    (FP)(_kernel_core_exc_entry), /* 2 */
    (FP)(_kernel_core_exc_entry), /* 3 */
    (FP)(_kernel_core_exc_entry), /* 4 */
    (FP)(_kernel_core_exc_entry), /* 5 */
    (FP)(_kernel_core_exc_entry), /* 6 */
    (FP)(_kernel_core_exc_entry), /* 7 */
    (FP)(0),
    (FP)(0),
    (FP)(0),
    (FP)(_kernel_svc_handler),      /* 11 SVCall handler */
    (FP)(_kernel_core_exc_entry), /* 12 */
    (FP)(0),
    (FP)(_kernel_pendsv_handler),      /* 14 PendSV handler */
    (FP)(_kernel_core_int_entry), /* 15 */
    (FP)(_kernel_core_int_entry), /* 16 */
    (FP)(_kernel_core_int_entry), /* 17 */
    (FP)(_kernel_core_int_entry), /* 18 */
    (FP)(_kernel_core_int_entry), /* 19 */
    (FP)(_kernel_core_int_entry), /* 20 */
    (FP)(_kernel_core_int_entry), /* 21 */
    (FP)(_kernel_core_int_entry), /* 22 */
    (FP)(_kernel_core_int_entry), /* 23 */
    (FP)(_kernel_core_int_entry), /* 24 */
    (FP)(_kernel_core_int_entry), /* 25 */
    (FP)(_kernel_core_int_entry), /* 26 */
    (FP)(_kernel_core_int_entry), /* 27 */
    (FP)(_kernel_core_int_entry), /* 28 */
    (FP)(_kernel_core_int_entry), /* 29 */
    (FP)(_kernel_core_int_entry), /* 30 */
    (FP)(_kernel_core_int_entry), /* 31 */
    (FP)(_kernel_core_int_entry), /* 32 */
    (FP)(_kernel_core_int_entry), /* 33 */
    (FP)(_kernel_core_int_entry), /* 34 */
    (FP)(_kernel_core_int_entry), /* 35 */
    (FP)(_kernel_core_int_entry), /* 36 */
    (FP)(_kernel_core_int_entry), /* 37 */
    (FP)(_kernel_core_int_entry), /* 38 */
    (FP)(_kernel_core_int_entry), /* 39 */
    (FP)(_kernel_core_int_entry), /* 40 */
    (FP)(_kernel_core_int_entry), /* 41 */
    (FP)(_kernel_core_int_entry), /* 42 */
    (FP)(_kernel_core_int_entry), /* 43 */
    (FP)(_kernel_core_int_entry), /* 44 */
    (FP)(_kernel_core_int_entry), /* 45 */
    (FP)(_kernel_core_int_entry), /* 46 */
    (FP)(_kernel_core_int_entry), /* 47 */
    (FP)(_kernel_core_int_entry), /* 48 */
    (FP)(_kernel_core_int_entry), /* 49 */
    (FP)(_kernel_core_int_entry), /* 50 */
    (FP)(_kernel_core_int_entry), /* 51 */
    (FP)(_kernel_core_int_entry), /* 52 */
    (FP)(_kernel_core_int_entry), /* 53 */
    (FP)(_kernel_core_int_entry), /* 54 */
    (FP)(_kernel_core_int_entry), /* 55 */
    (FP)(_kernel_core_int_entry), /* 56 */
    (FP)(_kernel_core_int_entry), /* 57 */
    (FP)(_kernel_core_int_entry), /* 58 */
    (FP)(_kernel_core_int_entry), /* 59 */
    (FP)(_kernel_core_int_entry), /* 60 */
    (FP)(_kernel_core_int_entry), /* 61 */
    (FP)(_kernel_core_int_entry), /* 62 */
    (FP)(_kernel_core_int_entry), /* 63 */
    (FP)(_kernel_core_int_entry), /* 64 */
    (FP)(_kernel_core_int_entry), /* 65 */
    (FP)(_kernel_core_int_entry), /* 66 */
    (FP)(_kernel_core_int_entry), /* 67 */
    (FP)(_kernel_core_int_entry), /* 68 */
    (FP)(_kernel_core_int_entry), /* 69 */
    (FP)(_kernel_core_int_entry), /* 70 */
    (FP)(_kernel_core_int_entry), /* 71 */
    (FP)(_kernel_core_int_entry), /* 72 */
    (FP)(_kernel_core_int_entry), /* 73 */
    (FP)(_kernel_core_int_entry), /* 74 */
    (FP)(_kernel_core_int_entry), /* 75 */
    (FP)(_kernel_core_int_entry), /* 76 */
    (FP)(_kernel_core_int_entry), /* 77 */
    (FP)(_kernel_core_int_entry), /* 78 */
    (FP)(_kernel_core_int_entry), /* 79 */
    (FP)(_kernel_core_int_entry), /* 80 */
    (FP)(_kernel_core_int_entry), /* 81 */
    (FP)(_kernel_core_int_entry), /* 82 */
    (FP)(_kernel_core_int_entry), /* 83 */
    (FP)(_kernel_core_int_entry), /* 84 */
    (FP)(_kernel_core_int_entry), /* 85 */
    (FP)(_kernel_core_int_entry), /* 86 */
    (FP)(_kernel_core_int_entry), /* 87 */
    (FP)(_kernel_core_int_entry), /* 88 */
    (FP)(_kernel_core_int_entry), /* 89 */
    (FP)(_kernel_core_int_entry), /* 90 */
    (FP)(_kernel_core_int_entry), /* 91 */
    (FP)(_kernel_core_int_entry), /* 92 */
    (FP)(_kernel_core_int_entry), /* 93 */
    (FP)(_kernel_core_int_entry), /* 94 */
    (FP)(_kernel_core_int_entry), /* 95 */
    (FP)(_kernel_core_int_entry), /* 96 */
    (FP)(_kernel_core_int_entry), /* 97 */
    (FP)(_kernel_core_int_entry), /* 98 */
    (FP)(_kernel_core_int_entry), /* 99 */
    (FP)(_kernel_core_int_entry), /* 100 */
    (FP)(_kernel_core_int_entry), /* 101 */
    (FP)(_kernel_core_int_entry), /* 102 */
    (FP)(_kernel_core_int_entry), /* 103 */
    (FP)(_kernel_core_int_entry), /* 104 */
    (FP)(_kernel_core_int_entry), /* 105 */
    (FP)(_kernel_core_int_entry), /* 106 */
    (FP)(_kernel_core_int_entry), /* 107 */
    (FP)(_kernel_core_int_entry), /* 108 */
    (FP)(_kernel_core_int_entry), /* 109 */
    (FP)(_kernel_core_int_entry), /* 110 */
    (FP)(_kernel_core_int_entry), /* 111 */
    (FP)(_kernel_core_int_entry), /* 112 */
    (FP)(_kernel_core_int_entry), /* 113 */
    (FP)(_kernel_core_int_entry), /* 114 */
    (FP)(_kernel_core_int_entry), /* 115 */
    (FP)(_kernel_core_int_entry), /* 116 */
    (FP)(_kernel_core_int_entry), /* 117 */
    (FP)(_kernel_core_int_entry), /* 118 */
    (FP)(_kernel_core_int_entry), /* 119 */
    (FP)(_kernel_core_int_entry), /* 120 */
    (FP)(_kernel_core_int_entry), /* 121 */
    (FP)(_kernel_core_int_entry), /* 122 */
    (FP)(_kernel_core_int_entry), /* 123 */
    (FP)(_kernel_core_int_entry), /* 124 */
    (FP)(_kernel_core_int_entry), /* 125 */
};

const FP _kernel_exc_tbl[] = {
   (FP)(_kernel_default_exc_handler), /* 0 */
   (FP)(_kernel_default_exc_handler), /* 1 */
   (FP)(_kernel_default_exc_handler), /* 2 */
   (FP)(_kernel_default_exc_handler), /* 3 */
   (FP)(_kernel_default_exc_handler), /* 4 */
   (FP)(_kernel_default_exc_handler), /* 5 */
   (FP)(_kernel_default_exc_handler), /* 6 */
   (FP)(_kernel_default_exc_handler), /* 7 */
   (FP)(_kernel_default_exc_handler), /* 8 */
   (FP)(_kernel_default_exc_handler), /* 9 */
   (FP)(_kernel_default_exc_handler), /* 10 */
   (FP)(_kernel_default_exc_handler), /* 11 */
   (FP)(_kernel_default_exc_handler), /* 12 */
   (FP)(_kernel_default_exc_handler), /* 13 */
   (FP)(_kernel_default_exc_handler), /* 14 */
   (FP)(_kernel_default_int_handler), /* 15 */
   (FP)(_kernel_default_int_handler), /* 16 */
   (FP)(_kernel_default_int_handler), /* 17 */
   (FP)(_kernel_default_int_handler), /* 18 */
   (FP)(_kernel_default_int_handler), /* 19 */
   (FP)(_kernel_default_int_handler), /* 20 */
   (FP)(_kernel_default_int_handler), /* 21 */
   (FP)(_kernel_default_int_handler), /* 22 */
   (FP)(_kernel_default_int_handler), /* 23 */
   (FP)(_kernel_default_int_handler), /* 24 */
   (FP)(_kernel_default_int_handler), /* 25 */
   (FP)(_kernel_default_int_handler), /* 26 */
   (FP)(_kernel_default_int_handler), /* 27 */
   (FP)(_kernel_default_int_handler), /* 28 */
   (FP)(_kernel_default_int_handler), /* 29 */
   (FP)(_kernel_default_int_handler), /* 30 */
   (FP)(_kernel_default_int_handler), /* 31 */
   (FP)(_kernel_default_int_handler), /* 32 */
   (FP)(_kernel_default_int_handler), /* 33 */
   (FP)(_kernel_default_int_handler), /* 34 */
   (FP)(_kernel_default_int_handler), /* 35 */
   (FP)(_kernel_default_int_handler), /* 36 */
   (FP)(_kernel_default_int_handler), /* 37 */
   (FP)(_kernel_default_int_handler), /* 38 */
   (FP)(_kernel_default_int_handler), /* 39 */
   (FP)(_kernel_default_int_handler), /* 40 */
   (FP)(_kernel_default_int_handler), /* 41 */
   (FP)(_kernel_default_int_handler), /* 42 */
   (FP)(_kernel_default_int_handler), /* 43 */
   (FP)(_kernel_default_int_handler), /* 44 */
   (FP)(_kernel_default_int_handler), /* 45 */
   (FP)(_kernel_default_int_handler), /* 46 */
   (FP)(_kernel_default_int_handler), /* 47 */
   (FP)(_kernel_default_int_handler), /* 48 */
   (FP)(_kernel_default_int_handler), /* 49 */
   (FP)(_kernel_default_int_handler), /* 50 */
   (FP)(_kernel_default_int_handler), /* 51 */
   (FP)(_kernel_default_int_handler), /* 52 */
   (FP)(_kernel_default_int_handler), /* 53 */
   (FP)(_kernel_default_int_handler), /* 54 */
   (FP)(_kernel_inthdr_55), /* 55 */
   (FP)(_kernel_default_int_handler), /* 56 */
   (FP)(_kernel_default_int_handler), /* 57 */
   (FP)(_kernel_default_int_handler), /* 58 */
   (FP)(_kernel_default_int_handler), /* 59 */
   (FP)(_kernel_default_int_handler), /* 60 */
   (FP)(_kernel_default_int_handler), /* 61 */
   (FP)(_kernel_default_int_handler), /* 62 */
   (FP)(_kernel_default_int_handler), /* 63 */
   (FP)(_kernel_default_int_handler), /* 64 */
   (FP)(_kernel_default_int_handler), /* 65 */
   (FP)(target_hrt_handler), /* 66 */
   (FP)(_kernel_default_int_handler), /* 67 */
   (FP)(_kernel_default_int_handler), /* 68 */
   (FP)(_kernel_default_int_handler), /* 69 */
   (FP)(_kernel_default_int_handler), /* 70 */
   (FP)(_kernel_default_int_handler), /* 71 */
   (FP)(_kernel_default_int_handler), /* 72 */
   (FP)(_kernel_default_int_handler), /* 73 */
   (FP)(_kernel_default_int_handler), /* 74 */
   (FP)(_kernel_default_int_handler), /* 75 */
   (FP)(_kernel_default_int_handler), /* 76 */
   (FP)(_kernel_inthdr_77), /* 77 */
   (FP)(_kernel_default_int_handler), /* 78 */
   (FP)(_kernel_default_int_handler), /* 79 */
   (FP)(_kernel_default_int_handler), /* 80 */
   (FP)(_kernel_default_int_handler), /* 81 */
   (FP)(_kernel_default_int_handler), /* 82 */
   (FP)(_kernel_default_int_handler), /* 83 */
   (FP)(_kernel_default_int_handler), /* 84 */
   (FP)(_kernel_default_int_handler), /* 85 */
   (FP)(_kernel_default_int_handler), /* 86 */
   (FP)(_kernel_default_int_handler), /* 87 */
   (FP)(_kernel_default_int_handler), /* 88 */
   (FP)(_kernel_default_int_handler), /* 89 */
   (FP)(_kernel_default_int_handler), /* 90 */
   (FP)(_kernel_default_int_handler), /* 91 */
   (FP)(_kernel_default_int_handler), /* 92 */
   (FP)(_kernel_default_int_handler), /* 93 */
   (FP)(_kernel_default_int_handler), /* 94 */
   (FP)(_kernel_default_int_handler), /* 95 */
   (FP)(_kernel_default_int_handler), /* 96 */
   (FP)(_kernel_default_int_handler), /* 97 */
   (FP)(_kernel_default_int_handler), /* 98 */
   (FP)(_kernel_default_int_handler), /* 99 */
   (FP)(_kernel_default_int_handler), /* 100 */
   (FP)(_kernel_default_int_handler), /* 101 */
   (FP)(_kernel_default_int_handler), /* 102 */
   (FP)(_kernel_default_int_handler), /* 103 */
   (FP)(_kernel_default_int_handler), /* 104 */
   (FP)(_kernel_default_int_handler), /* 105 */
   (FP)(_kernel_default_int_handler), /* 106 */
   (FP)(_kernel_default_int_handler), /* 107 */
   (FP)(_kernel_default_int_handler), /* 108 */
   (FP)(_kernel_default_int_handler), /* 109 */
   (FP)(_kernel_default_int_handler), /* 110 */
   (FP)(_kernel_default_int_handler), /* 111 */
   (FP)(_kernel_default_int_handler), /* 112 */
   (FP)(_kernel_default_int_handler), /* 113 */
   (FP)(_kernel_default_int_handler), /* 114 */
   (FP)(_kernel_default_int_handler), /* 115 */
   (FP)(_kernel_default_int_handler), /* 116 */
   (FP)(_kernel_default_int_handler), /* 117 */
   (FP)(_kernel_default_int_handler), /* 118 */
   (FP)(_kernel_default_int_handler), /* 119 */
   (FP)(_kernel_default_int_handler), /* 120 */
   (FP)(_kernel_default_int_handler), /* 121 */
   (FP)(_kernel_default_int_handler), /* 122 */
   (FP)(_kernel_default_int_handler), /* 123 */
   (FP)(_kernel_default_int_handler), /* 124 */
   (FP)(_kernel_default_int_handler), /* 125 */
};


const uint32_t _kernel_bitpat_cfgint[8] = {
   UINT32_C(0x00000000),
   UINT32_C(0x00800000),
   UINT32_C(0x00002004),
   UINT32_C(0x00000000),
   UINT32_C(0x00000000),
   UINT32_C(0x00000000),
   UINT32_C(0x00000000),
   UINT32_C(0x00000000),
};

