/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015      by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: cmsis.h,v 1.1 2015/09/27 14:23:07 roi Exp $
 */

#ifndef _CMSIS_F7_H_
#define _CMSIS_F7_H_

/*
 *  SIL TYPE to ACCESS the INSTRUCTATION TRACE MACROCELL REGISTER (ITM).
 */
#define TADR_ITM_BASE       (0xE0000000UL)				/* ITM Base Address */
#define TOFF_ITM_PORT       0x0000		/* (W)  ITM Stimulus Port Registers */
#define TOFF_ITM_TER        0x0E00		/* (RW) ITM Trace Enable Register */
#define TOFF_ITM_TPR        0x0E40		/* (RW) ITM Trace Privilege Register */
#define TOFF_ITM_TCR        0x0E80		/* (RW) ITM Trace Control Register */
#define TOFF_ITM_IWR        0x0EF8		/* (W)  ITM Integration Write Register */
#define TOFF_ITM_IRR        0x0EFC		/* (R)  ITM Integration Read Register */
#define TOFF_ITM_IMCR       0x0F00		/* (RW) ITM Integration Mode Control Register */
#define TOFF_ITM_LAR        0x0FB0		/* (W)  ITM Lock Access Register */
#define TOFF_ITM_LSR        0x0FB4		/* (R)  ITM Lock Status Register */
#define TOFF_ITM_PID4       0x0FD0		/* (R)  ITM Peripheral Identification Register #4 */
#define TOFF_ITM_PID5       0x0FD4		/* (R)  ITM Peripheral Identification Register #5 */
#define TOFF_ITM_PID6       0x0FD8		/* (R)  ITM Peripheral Identification Register #6 */
#define TOFF_ITM_PID7       0x0FDC		/* (R)  ITM Peripheral Identification Register #7 */
#define TOFF_ITM_PID0       0x0FE0		/* (R)  ITM Peripheral Identification Register #0 */
#define TOFF_ITM_PID1       0x0FE4		/* (R)  ITM Peripheral Identification Register #1 */
#define TOFF_ITM_PID2       0x0FE8		/* (R)  ITM Peripheral Identification Register #2 */
#define TOFF_ITM_PID3       0x0FEC		/* (R)  ITM Peripheral Identification Register #3 */
#define TOFF_ITM_CID0       0x0FF0		/* (R)  ITM Component  Identification Register #0 */
#define TOFF_ITM_CID1       0x0FF4		/* (R)  ITM Component  Identification Register #1 */
#define TOFF_ITM_CID2       0x0FF8		/* (R)  ITM Component  Identification Register #2 */
#define TOFF_ITM_CID3       0x0FFC		/* (R)  ITM Component  Identification Register #3 */

/*
 *  SIL TYPE to ACCESS the Data Watchpoint and Trace Register (DWT).
 */
#define TADR_DWT_BASE       (0xE0001000UL)				/* DWT Base Address */
#define TOFF_DWT_CTRL       0x0000		/* (RW)  Control Register */
#define TOFF_DWT_CYCCNT     0x0004		/* (RW)  Cycle Count Register */
#define TOFF_DWT_CPICNT     0x0008		/* (RW)  CPI Count Register */
#define TOFF_DWT_EXCCNT     0x000C		/* (RW)  Exception Overhead Count Register */
#define TOFF_DWT_SLEEPCNT   0x0010		/* (RW)  Sleep Count Register */
#define TOFF_DWT_LSUCNT     0x0014		/* (RW)  LSU Count Register */
#define TOFF_DWT_FOLDCNT    0x0018		/* (RW)  Folded-instruction Count Register */
#define TOFF_DWT_PCSR       0x001C		/* (R )  Program Counter Sample Register */
#define TOFF_DWT_COMP0      0x0020		/* (RW)  Comparator Register 0 */
#define TOFF_DWT_MASK0      0x0024		/* (RW)  Mask Register 0 */
#define TOFF_DWT_FUNCTION0  0x0028		/* (RW)  Function Register 0 */
#define TOFF_DWT_COMP1      0x0030		/* (RW)  Comparator Register 1 */
#define TOFF_DWT_MASK1      0x0034		/* (RW)  Mask Register 1 */
#define TOFF_DWT_FUNCTION1  0x0038		/* (RW)  Function Register 1 */
#define TOFF_DWT_COMP2      0x0040		/* (RW)  Comparator Register 2 */
#define TOFF_DWT_MASK2      0x0044		/* (RW)  Mask Register 2 */
#define TOFF_DWT_FUNCTION2  0x0048		/* (RW)  Function Register 2 */
#define TOFF_DWT_COMP3      0x0050		/* (RW)  Comparator Register 3 */
#define TOFF_DWT_MASK3      0x0054		/* (RW)  Mask Register 3 */
#define TOFF_DWT_FUNCTION3  0x0058		/* (RW)  Function Register 3 */
#define TOFF_DWT_LAR        0x0FB0		/* (W)  Lock Access Register */
#define TOFF_DWT_LSR        0x0FB4		/* (R)  Lock Status Register */

/*
 *  SIL TYPE to ACCESS the SYSTEM CONTROL and ID RREGISTER not in the SCB.
 */
#define TADR_SCS_BASE       (0xE000E000UL)				/* System Control Space Base Address  */
#define TOFF_SCS_ICTR       0x0004		/* (R)  Interrupt Controller Type Register */
#define TOFF_SCS_ACTLR      0x0008		/* (RW) Auxiliary Control Register */

/*
 *  SIL TYPE to ACCESS THE SYSTEM TIMER (SysTick).
 */
#define TADR_SYSTICK_BASE   (TADR_SCS_BASE+0x0010UL)	/* SysTick Base Address */
#define TOFF_SYSTICK_CTRL   0x0000		/* (RW) SysTick Control and Status Register */
#define TOFF_SYSTICK_LOAD   0x0004		/* (RW) SysTick Reload Value Register */
#define TOFF_SYSTICK_VAL    0x0008		/* (RW) SysTick Current Value Register */
#define TOFF_SYSTICK_CALIB  0x000C		/* (R)  SysTick Calibration Register */

/*
 *  SIL TYPE to ACCESS the NESTE VECTORED INTERRUPT CONTROLLER (NVIC).
 */
#define TADR_NVIC_BASE      (TADR_SCS_BASE+0x0100UL)	/* NVIC Base Address */
#define TOFF_NVIC_ISER      0x0000		/* (RW) Interrupt Set Enable Register */
#define TOFF_NVIC_ICER      0x0080		/* (RW) Interrupt Clear Enable Register */
#define TOFF_NVIC_ISPR      0x0100		/* (RW) Interrupt Set Pending Register */
#define TOFF_NVIC_ICPR      0x0180		/* (RW) Interrupt Clear Pending Register */
#define TOFF_NVIC_IABR      0x0200		/* (RW) Interrupt Active bit Register */
#define TOFF_NVIC_IP        0x0300		/* (RW) Interrupt Priority Register (8Bit wide) */
#define TOFF_NVIC_STIR      0x0E00		/* (W)  Software Trigger Interrupt Register */

/*
 *  SIL TYPE to ACCESS the SYSTEM CONTROL BLOCK (SCB).
 */
#define TADR_SCB_BASE       (TADR_SCS_BASE+0x0D00UL)	/* System Control Block Base Address  */
#define TOFF_SCB_CPUID      0x0000		/* (R)  CPUID Base Register */
#define TOFF_SCB_ICSR       0x0004		/* (RW) Interrupt Control and State Register */
#define TOFF_SCB_VTOR       0x0008		/* (RW) Vector Table Offset Register */
#define TOFF_SCB_AIRCR      0x000C		/* (RW) Application Interrupt and Reset Control Register */
  #define SCB_VTOR_TBLOFF_Pos         7                                    /* TBLOFF Position */
  #define SCB_VTOR_TBLOFF_Msk         (0x1FFFFFF << SCB_VTOR_TBLOFF_Pos)   /* TBLOFF Mask */
  #define SCB_AIRCR_VECTKEY_Pos       16                                   /* VECTKEY Position */
  #define SCB_AIRCR_VECTKEY_Msk       (0xFFFF << SCB_AIRCR_VECTKEY_Pos)    /* VECTKEY Mask */
  #define SCB_AIRCR_VECTKEYSTAT_Pos   16                                   /* VECTKEYSTAT Position */
  #define SCB_AIRCR_VECTKEYSTAT_Msk   (0xFFFF << SCB_AIRCR_VECTKEYSTAT_Pos)/* VECTKEYSTAT Mask */
  #define SCB_AIRCR_ENDIANESS_Pos     15                                   /* ENDIANESS Position */
  #define SCB_AIRCR_ENDIANESS_Msk     (1 << SCB_AIRCR_ENDIANESS_Pos)       /* ENDIANESS Mask */
  #define SCB_AIRCR_PRIGROUP_Pos      8                                    /* PRIGROUP Position */
  #define SCB_AIRCR_PRIGROUP_Msk      (7 << SCB_AIRCR_PRIGROUP_Pos)        /* PRIGROUP Mask */
  #define SCB_AIRCR_SYSRESETREQ_Pos   2                                    /* SYSRESETREQ Position */
  #define SCB_AIRCR_SYSRESETREQ_Msk   (1 << SCB_AIRCR_SYSRESETREQ_Pos)     /* SYSRESETREQ Mask */
  #define SCB_AIRCR_VECTCLRACTIVE_Pos 1                                    /* VECTCLRACTIVE Position */
  #define SCB_AIRCR_VECTCLRACTIVE_Msk (1 << SCB_AIRCR_VECTCLRACTIVE_Pos)   /* VECTCLRACTIVE Mask */
  #define SCB_AIRCR_VECTRESET_Pos     0                                    /* VECTRESET Position */
  #define SCB_AIRCR_VECTRESET_Msk     (1 /*<< SCB_AIRCR_VECTRESET_Pos*/)   /* VECTRESET Mask */
#define TOFF_SCB_SCR        0x0010		/* (RW) System Control Register */
  #define SCB_SCR_SEVONPEND_Pos       4                                    /* SEVONPEND Position */
  #define SCB_SCR_SEVONPEND_Msk       (1 << SCB_SCR_SEVONPEND_Pos)         /* SEVONPEND Mask */
  #define SCB_SCR_SLEEPDEEP_Pos       2                                    /* SLEEPDEEP Position */
  #define SCB_SCR_SLEEPDEEP_Msk       (1 << SCB_SCR_SLEEPDEEP_Pos)         /* SLEEPDEEP Mask */
  #define SCB_SCR_SLEEPONEXIT_Pos     1                                    /* SCB SCR: SLEEPONEXIT Position */
  #define SCB_SCR_SLEEPONEXIT_Msk     (1 << SCB_SCR_SLEEPONEXIT_Pos)       /* SCB SCR: SLEEPONEXIT Mask */
#define TOFF_SCB_CCR        0x0014		/* (RW) Configuration Control Register */
  #define SCB_CCR_BP_Pos              18                                   /* Branch prediction enable bit Position */
  #define SCB_CCR_BP_Msk              (1 << SCB_CCR_BP_Pos)                /* Branch prediction enable bit Mask */
  #define SCB_CCR_IC_Pos              17                                   /* Instruction cache enable bit Position */
  #define SCB_CCR_IC_Msk              (1 << SCB_CCR_IC_Pos)                /* Instruction cache enable bit Mask */
  #define SCB_CCR_DC_Pos              16                                   /* Cache enable bit Position */
  #define SCB_CCR_DC_Msk              (1 << SCB_CCR_DC_Pos)                /* Cache enable bit Mask */
  #define SCB_CCR_STKALIGN_Pos        9                                    /* STKALIGN Position */
  #define SCB_CCR_STKALIGN_Msk        (1 << SCB_CCR_STKALIGN_Pos)          /* STKALIGN Mask */
  #define SCB_CCR_BFHFNMIGN_Pos       8                                    /* BFHFNMIGN Position */
  #define SCB_CCR_BFHFNMIGN_Msk       (1 << SCB_CCR_BFHFNMIGN_Pos)         /* BFHFNMIGN Mask */
  #define SCB_CCR_DIV_0_TRP_Pos       4                                    /* DIV_0_TRP Position */
  #define SCB_CCR_DIV_0_TRP_Msk       (1 << SCB_CCR_DIV_0_TRP_Pos)         /* DIV_0_TRP Mask */
  #define SCB_CCR_UNALIGN_TRP_Pos     3                                    /* UNALIGN_TRP Position */
  #define SCB_CCR_UNALIGN_TRP_Msk     (1 << SCB_CCR_UNALIGN_TRP_Pos)       /* UNALIGN_TRP Mask */
  #define SCB_CCR_USERSETMPEND_Pos    1                                    /* USERSETMPEND Position */
  #define SCB_CCR_USERSETMPEND_Msk    (1 << SCB_CCR_USERSETMPEND_Pos)      /* USERSETMPEND Mask */
  #define SCB_CCR_NONBASETHRDENA_Pos  0                                    /* NONBASETHRDENA Position */
  #define SCB_CCR_NONBASETHRDENA_Msk  (1 /*<< SCB_CCR_NONBASETHRDENA_Pos*/)/* NONBASETHRDENA Mask */
#define TOFF_SCB_SHP4       0x0018		/* (RW-8) System Handlers Priority Registers 4 */
#define TOFF_SCB_SHP5       0x0019		/* (RW-8) System Handlers Priority Registers 5 */
#define TOFF_SCB_SHP6       0x001A		/* (RW-8) System Handlers Priority Registers 6 */
#define TOFF_SCB_SHP7       0x001B		/* (RW-8) System Handlers Priority Registers 7 */
#define TOFF_SCB_SHP8       0x001C		/* (RW-8) System Handlers Priority Registers 8 */
#define TOFF_SCB_SHP9       0x001D		/* (RW-8) System Handlers Priority Registers 9 */
#define TOFF_SCB_SHP10      0x001E		/* (RW-8) System Handlers Priority Registers 10 */
#define TOFF_SCB_SHP11      0x001F		/* (RW-8) System Handlers Priority Registers 11 */
#define TOFF_SCB_SHP12      0x0020		/* (RW-8) System Handlers Priority Registers 12 */
#define TOFF_SCB_SHP13      0x0021		/* (RW-8) System Handlers Priority Registers 13 */
#define TOFF_SCB_SHP14      0x0022		/* (RW-8) System Handlers Priority Registers 14 */
#define TOFF_SCB_SHP15      0x0023		/* (RW-8) System Handlers Priority Registers 15 */
#define TOFF_SCB_SHCSR      0x0024		/* (RW) System Handler Control and State Register */
  #define SCB_SHCSR_USGFAULTENA_Pos   18                                   /* USGFAULTENA Position */
  #define SCB_SHCSR_USGFAULTENA_Msk   (1 << SCB_SHCSR_USGFAULTENA_Pos)     /* USGFAULTENA Mask */
  #define SCB_SHCSR_BUSFAULTENA_Pos   17                                   /* BUSFAULTENA Position */
  #define SCB_SHCSR_BUSFAULTENA_Msk   (1 << SCB_SHCSR_BUSFAULTENA_Pos)     /* BUSFAULTENA Mask */
  #define SCB_SHCSR_MEMFAULTENA_Pos   16                                   /* MEMFAULTENA Position */
  #define SCB_SHCSR_MEMFAULTENA_Msk   (1 << SCB_SHCSR_MEMFAULTENA_Pos)     /* MEMFAULTENA Mask */
  #define SCB_SHCSR_SVCALLPENDED_Pos  15                                   /* SVCALLPENDED Position */
  #define SCB_SHCSR_SVCALLPENDED_Msk  (1 << SCB_SHCSR_SVCALLPENDED_Pos)    /* SVCALLPENDED Mask */
  #define SCB_SHCSR_BUSFAULTPENDED_Pos 14                                  /* BUSFAULTPENDED Position */
  #define SCB_SHCSR_BUSFAULTPENDED_Msk (1 << SCB_SHCSR_BUSFAULTPENDED_Pos) /* BUSFAULTPENDED Mask */
  #define SCB_SHCSR_MEMFAULTPENDED_Pos 13                                  /* MEMFAULTPENDED Position */
  #define SCB_SHCSR_MEMFAULTPENDED_Msk (1 << SCB_SHCSR_MEMFAULTPENDED_Pos) /* MEMFAULTPENDED Mask */
  #define SCB_SHCSR_USGFAULTPENDED_Pos 12                                  /* USGFAULTPENDED Position */
  #define SCB_SHCSR_USGFAULTPENDED_Msk (1 << SCB_SHCSR_USGFAULTPENDED_Pos) /* USGFAULTPENDED Mask */
  #define SCB_SHCSR_SYSTICKACT_Pos    11                                   /* SYSTICKACT Position */
  #define SCB_SHCSR_SYSTICKACT_Msk    (1 << SCB_SHCSR_SYSTICKACT_Pos)      /* SYSTICKACT Mask */
  #define SCB_SHCSR_PENDSVACT_Pos     10                                   /* PENDSVACT Position */
  #define SCB_SHCSR_PENDSVACT_Msk     (1 << SCB_SHCSR_PENDSVACT_Pos)       /* PENDSVACT Mask */
  #define SCB_SHCSR_MONITORACT_Pos    8                                    /* MONITORACT Position */
  #define SCB_SHCSR_MONITORACT_Msk    (1 << SCB_SHCSR_MONITORACT_Pos)      /* MONITORACT Mask */
  #define SCB_SHCSR_SVCALLACT_Pos     7                                    /* SVCALLACT Position */
  #define SCB_SHCSR_SVCALLACT_Msk     (1 << SCB_SHCSR_SVCALLACT_Pos)       /* SVCALLACT Mask */
  #define SCB_SHCSR_USGFAULTACT_Pos   3                                    /* USGFAULTACT Position */
  #define SCB_SHCSR_USGFAULTACT_Msk   (1 << SCB_SHCSR_USGFAULTACT_Pos)     /* USGFAULTACT Mask */
  #define SCB_SHCSR_BUSFAULTACT_Pos   1                                    /* BUSFAULTACT Position */
  #define SCB_SHCSR_BUSFAULTACT_Msk   (1 << SCB_SHCSR_BUSFAULTACT_Pos)     /* BUSFAULTACT Mask */
  #define SCB_SHCSR_MEMFAULTACT_Pos   0                                    /* MEMFAULTACT Position */
  #define SCB_SHCSR_MEMFAULTACT_Msk   (1 /*<< SCB_SHCSR_MEMFAULTACT_Pos*/) /* MEMFAULTACT Mask */
#define TOFF_SCB_CFSR       0x0028		/* (RW) Configurable Fault Status Register */
#define TOFF_SCB_HFSR       0x002C		/* (RW) HardFault Status Register */
#define TOFF_SCB_DFSR       0x0030		/* (RW) Debug Fault Status Register */
#define TOFF_SCB_MMFAR      0x0034		/* (RW) MemManage Fault Address Register */
#define TOFF_SCB_BFAR       0x0038		/* (RW) BusFault Address Register */
#define TOFF_SCB_AFSR       0x003C		/* (RW) Auxiliary Fault Status Register */
#define TOFF_SCB_PFR0       0x0040		/* (R)  Processor Feature Register 0 */
#define TOFF_SCB_PFR1       0x0044		/* (R)  Processor Feature Register 1 */
#define TOFF_SCB_ID_DFR     0x0048		/* (R)  Debug Feature Register */
#define TOFF_SCB_ID_AFR     0x004C		/* (R)  Auxiliary Feature Register */
#define TOFF_SCB_ID_MFR0    0x0050		/* (R)  Memory Model Feature Register #0 */
#define TOFF_SCB_ID_MFR1    0x0054		/* (R)  Memory Model Feature Register #1 */
#define TOFF_SCB_ID_MFR2    0x0058		/* (R)  Memory Model Feature Register #2 */
#define TOFF_SCB_ID_MFR3    0x005C		/* (R)  Memory Model Feature Register #3 */
#define TOFF_SCB_ID_ISAR0   0x0060		/* (R)  Instruction Set Attributes Register #0 */
#define TOFF_SCB_ID_ISAR1   0x0064		/* (R)  Instruction Set Attributes Register #1 */
#define TOFF_SCB_ID_ISAR2   0x0068		/* (R)  Instruction Set Attributes Register #2 */
#define TOFF_SCB_ID_ISAR3   0x006C		/* (R)  Instruction Set Attributes Register #3 */
#define TOFF_SCB_ID_ISAR4   0x0070		/* (R)  Instruction Set Attributes Register #4 */
#define TOFF_SCB_CLIDR      0x0078		/* (R)  Cache Level ID register */
#define TOFF_SCB_CTR        0x007C		/* (R)  Cache Type register */
#define TOFF_SCB_CCSIDR     0x0080		/* (R)  Cache Size ID Register */
  #define SCB_CCSIDR_WT_Pos           31                                   /* WT Position */
  #define SCB_CCSIDR_WT_Msk           (7 << SCB_CCSIDR_WT_Pos)             /* WT Mask */
  #define SCB_CCSIDR_WB_Pos           30                                   /* WB Position */
  #define SCB_CCSIDR_WB_Msk           (7 << SCB_CCSIDR_WB_Pos)             /* WB Mask */
  #define SCB_CCSIDR_RA_Pos           29                                   /* RA Position */
  #define SCB_CCSIDR_RA_Msk           (7 << SCB_CCSIDR_RA_Pos)             /* RA Mask */
  #define SCB_CCSIDR_WA_Pos           28                                   /* WA Position */
  #define SCB_CCSIDR_WA_Msk           (7 << SCB_CCSIDR_WA_Pos)             /* WA Mask */
  #define SCB_CCSIDR_NUMSETS_Pos      13                                   /* NumSets Position */
  #define SCB_CCSIDR_NUMSETS_Msk      (0x7FFF << SCB_CCSIDR_NUMSETS_Pos)   /* NumSets Mask */
  #define SCB_CCSIDR_ASSOCIATIVITY_Pos 3                                   /* Associativity Position */
  #define SCB_CCSIDR_ASSOCIATIVITY_Msk (0x3FF << SCB_CCSIDR_ASSOCIATIVITY_Pos) /* Associativity Mask */
  #define SCB_CCSIDR_LINESIZE_Pos     0                                    /* LineSize Position */
  #define SCB_CCSIDR_LINESIZE_Msk     (7 /*<< SCB_CCSIDR_LINESIZE_Pos*/)   /* LineSize Mask */
#define TOFF_SCB_CSSELR     0x0084		/* (RW) Cache Size Selection Register */
#define TOFF_SCB_CPACR      0x0088		/* (RW) Coprocessor Access Control Register */
#define TOFF_SCB_STIR       0x0200		/* (W)  Software Triggered Interrupt Register */
#define TOFF_SCB_MVFR0      0x0240		/* (R)  Media and VFP Feature Register 0 */
#define TOFF_SCB_MVFR1      0x0244		/* (R)  Media and VFP Feature Register 1 */
#define TOFF_SCB_MVFR2      0x0248		/* (R)  Media and VFP Feature Register 2 */
#define TOFF_SCB_ICIALLU    0x0250		/* (W)  I-Cache Invalidate All to PoU */
#define TOFF_SCB_ICIMVAU    0x0258		/* (W)  I-Cache Invalidate by MVA to PoU */
#define TOFF_SCB_DCIMVAC    0x025C		/* (W)  D-Cache Invalidate by MVA to PoC */
#define TOFF_SCB_DCISW      0x0260		/* (W)  D-Cache Invalidate by Set-way */
#define TOFF_SCB_DCCMVAU    0x0264		/* (W)  D-Cache Clean by MVA to PoU */
#define TOFF_SCB_DCCMVAC    0x0268		/* (W)  D-Cache Clean by MVA to PoC */
#define TOFF_SCB_DCCSW      0x026C		/* (W)  D-Cache Clean by Set-way */
#define TOFF_SCB_DCCIMVAC   0x0270		/* (W)  D-Cache Clean and Invalidate by MVA to PoC */
#define TOFF_SCB_DCCISW     0x0274		/* (W)  D-Cache Clean and Invalidate by Set-way */
#define TOFF_SCB_ITCMCR     0x0290		/* (RW)  Instruction Tightly-Coupled Memory Control Register   */
#define TOFF_SCB_DTCMCR     0x0294		/* (RW)  Data Tightly-Coupled Memory Control Registers */
#define TOFF_SCB_AHBPCR     0x0298		/* (RW)  AHBP Control Register */
#define TOFF_SCB_CACR       0x029C		/* (RW)  L1 Cache Control Register */
#define TOFF_SCB_AHBSCR     0x02A0		/* (RW)  AHB Slave Control Register */
#define TOFF_SCB_ABFSR      0x02A8		/* (RW)  Auxiliary Bus Fault Status Register */

/*
 *  SIL type to ACCESS the MEMORY PROTECTION UNIT (MPU).
 */
#define TADR_MPU_BASE       (TADR_SCS_BASE+0x0D90UL)	/* Memory Protection Unit */
#define TOFF_MPU_TYPE       0x0000		/* (R)  MPU Type Register */
  #define MPU_TYPE_IREGION_Pos        16                                   /* IREGION Position */
  #define MPU_TYPE_IREGION_Msk        (0xFF << MPU_TYPE_IREGION_Pos)       /* IREGION Mask */
  #define MPU_TYPE_DREGION_Pos        8                                    /* DREGION Position */
  #define MPU_TYPE_DREGION_Msk        (0xFF << MPU_TYPE_DREGION_Pos)       /* DREGION Mask */
  #define MPU_TYPE_SEPARATE_Pos       0                                    /* SEPARATE Position */
  #define MPU_TYPE_SEPARATE_Msk       (1 /*<< MPU_TYPE_SEPARATE_Pos*/)     /* SEPARATE Mask */
#define TOFF_MPU_CTRL       0x0004		/* (RW) MPU Control Register */
  #define MPU_CTRL_PRIVDEFENA_Pos     2                                    /* PRIVDEFENA Position */
  #define MPU_CTRL_PRIVDEFENA_Msk     (1 << MPU_CTRL_PRIVDEFENA_Pos)       /* PRIVDEFENA Mask */
  #define MPU_CTRL_HFNMIENA_Pos       1                                    /* HFNMIENA Position */
  #define MPU_CTRL_HFNMIENA_Msk       (1 << MPU_CTRL_HFNMIENA_Pos)         /* HFNMIENA Mask */
  #define MPU_CTRL_ENABLE_Pos         0                                    /* ENABLE Position */
  #define MPU_CTRL_ENABLE_Msk         (1 /*<< MPU_CTRL_ENABLE_Pos*/)       /* ENABLE Mask */
#define TOFF_MPU_RNR        0x0008		/* (RW) MPU Region RNRber Register */
#define TOFF_MPU_RBAR       0x000C		/* (RW) MPU Region Base Address Register */
#define TOFF_MPU_RASR       0x0010		/* (RW) MPU Region Attribute and Size Register         */
  #define MPU_RASR_ATTRS_Pos          16                                   /* MPU Region Attribute field Position */
  #define MPU_RASR_ATTRS_Msk          (0xFFFF << MPU_RASR_ATTRS_Pos)       /* MPU Region Attribute field Mask */
  #define MPU_RASR_XN_Pos             28                                   /* ATTRS.XN Position */
  #define MPU_RASR_XN_Msk             (1 << MPU_RASR_XN_Pos)               /* ATTRS.XN Mask */
  #define MPU_RASR_AP_Pos             24                                   /* ATTRS.AP Position */
  #define MPU_RASR_AP_Msk             (0x7 << MPU_RASR_AP_Pos)             /* ATTRS.AP Mask */
  #define MPU_RASR_TEX_Pos            19                                   /* ATTRS.TEX Position */
  #define MPU_RASR_TEX_Msk            (0x7 << MPU_RASR_TEX_Pos)            /* ATTRS.TEX Mask */
  #define MPU_RASR_S_Pos              18                                   /* ATTRS.S Position */
  #define MPU_RASR_S_Msk              (1 << MPU_RASR_S_Pos)                /* ATTRS.S Mask */
  #define MPU_RASR_C_Pos              17                                   /* ATTRS.C Position */
  #define MPU_RASR_C_Msk              (1 << MPU_RASR_C_Pos)                /* ATTRS.C Mask */
  #define MPU_RASR_B_Pos              16                                   /* ATTRS.B Position */
  #define MPU_RASR_B_Msk              (1 << MPU_RASR_B_Pos)                /* ATTRS.B Mask */
  #define MPU_RASR_SRD_Pos            8                                    /* Sub-Region Disable Position */
  #define MPU_RASR_SRD_Msk            (0xFF << MPU_RASR_SRD_Pos)           /* Sub-Region Disable Mask */
  #define MPU_RASR_SIZE_Pos           1                                    /* Region Size Field Position */
  #define MPU_RASR_SIZE_Msk           (0x1F << MPU_RASR_SIZE_Pos)          /* Region Size Field Mask */
  #define MPU_RASR_ENABLE_Pos         0                                    /* Region enable bit Position */
  #define MPU_RASR_ENABLE_Msk         (1 /*<< MPU_RASR_ENABLE_Pos*/)       /* Region enable bit Disable Mask */
#define TOFF_MPU_RBAR_A1    0x0014		/* (RW) MPU Alias 1 Region Base Address Register       */
#define TOFF_MPU_RASR_A1    0x0018		/* (RW) MPU Alias 1 Region Attribute and Size Register */
#define TOFF_MPU_RBAR_A2    0x001C		/* (RW) MPU Alias 2 Region Base Address Register       */
#define TOFF_MPU_RASR_A2    0x0020		/* (RW) MPU Alias 2 Region Attribute and Size Register */
#define TOFF_MPU_RBAR_A3    0x0024		/* (RW) MPU Alias 3 Region Base Address Register       */
#define TOFF_MPU_RASR_A3    0x0028		/* (RW) MPU Alias 3 Region Attribute and Size Register */

/*
 *  SIL TYPE to ACCESS the TRACE PORT INTERFACE REGISTER (TPI).
 */
#define TADR_TPI_BASE       (0xE0040000UL)				/* TPI Base Address                   */
#define TOFF_TPI_SSPSR      0x0000		/* (R)  Supported Parallel Port Size Register */
#define TOFF_TPI_CSPSR      0x0004		/* (RW) Current Parallel Port Size Register */
#define TOFF_TPI_ACPR       0x0010		/* (RW) Asynchronous Clock Prescaler Register */
#define TOFF_TPI_SPPR       0x00F0		/* (RW) Selected Pin Protocol Register */
#define TOFF_TPI_FFSR       0x0300		/* (R)  Formatter and Flush Status Register */
#define TOFF_TPI_FFCR       0x0304		/* (RW) Formatter and Flush Control Register */
#define TOFF_TPI_FSCR       0x0308		/* (R)  Formatter Synchronization Counter Register */
#define TOFF_TPI_TRIGGER    0x0EE8		/* (R)  TRIGGER */
#define TOFF_TPI_FIFO0      0x0EEC		/* (R)  Integration ETM Data */
#define TOFF_TPI_ITATBCTR2  0x0EF0		/* (R)  ITATBCTR2 */
#define TOFF_TPI_ITATBCTR0  0x0EF8		/* (R)  ITATBCTR0 */
#define TOFF_TPI_FIFO1      0x0EFC		/* (R)  Integration ITM Data */
#define TOFF_TPI_ITCTRL     0x0F00		/* (RW) Integration Mode Control */
#define TOFF_TPI_CLAIMSET   0x0FA0		/* (RW) Claim tag set */
#define TOFF_TPI_CLAIMCLR   0x0FA4		/* (RW) Claim tag clear */
#define TOFF_TPI_DEVID      0x0FC8		/* (R)  TPIU_DEVID */
#define TOFF_TPI_DEVTYPE    0x0FCC		/* (R)  TPIU_DEVTYPE */

/*
 *  SIL TYPE to ACCESS the CORE DEBUG REGISTER (CoreDebug).
 */
#define TADR_COREDEBUG_BASE (0xE000EDF0UL)				/* Core Debug Base Address  */
#define TOFF_COREDEBUG_DHCSR 0x0000	/* (RW) Debug Halting Control and Status Register    */
#define TOFF_COREDEBUG_DCRSR 0x0004	/* (W)  Debug Core Register Selector Register        */
#define TOFF_COREDEBUG_DCRDR 0x0008	/* (RW) Debug Core Register Data Register            */
#define TOFF_COREDEBUG_DEMCR 0x000C	/* (RW) Debug Exception and Monitor Control Register */

/*
 *  SIL TYPE to ACCESS the FLOATING POINT UNIT (FPU).
 */
#define TADR_FPU_BASE       (TADR_SCS_BASE+0x0F30UL)	/* Floating Point Unit */
#define TOFF_FPU_FPCCR      0x0004		/* (RW) Floating-Point Context Control Register */
#define TOFF_FPU_FPCAR      0x0008		/* (RW) Floating-Point Context Address Register */
#define TOFF_FPU_FPDSCR     0x000C		/* (RW) Floating-Point Default Status Control Register */
#define TOFF_FPU_MVFR0      0x0010		/* (R)  Media and FP Feature Register 0 */
#define TOFF_FPU_MVFR1      0x0014		/* (R)  Media and FP Feature Register 1 */
#define TOFF_FPU_MVFR2      0x0018		/* (R)  Media and FP Feature Register 2 */

/*
 *  CORTEX_Preemption_Priority_Group CORTEX Preemption Priority Group
 */
#define NVIC_PRIORITYGROUP_0    0x00000007	/* 0 bits for pre-emption priority 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1    0x00000006	/* 1 bits for pre-emption priority 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2    0x00000005	/* 2 bits for pre-emption priority 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3    0x00000004	/* 3 bits for pre-emption priority 1 bits for subpriority */
#define NVIC_PRIORITYGROUP_4    0x00000003	/* 4 bits for pre-emption priority 0 bits for subpriority */

/*
 *  CORTEX_MPU_HFNMI_PRIVDEF_Control MPU HFNMI and PRIVILEGED Access control
 */
#define MPU_HFNMI_PRIVDEF_NONE  0x00000000
#define MPU_HARDFAULT_NMI       0x00000002
#define MPU_PRIVILEGED_DEFAULT  0x00000004
#define MPU_HFNMI_PRIVDEF       0x00000006

/*
 *  CORTEX_MPU_TEX_Levels MPU TEX Levels
 */
#define MPU_TEX_LEVEL0          0x00
#define MPU_TEX_LEVEL1          0x01
#define MPU_TEX_LEVEL2          0x02

/*
 *  CORTEX_MPU_Region_Size CORTEX MPU Region Size
 */
#define MPU_REGION_SIZE_32B     0x04
#define MPU_REGION_SIZE_64B     0x05
#define MPU_REGION_SIZE_128B    0x06
#define MPU_REGION_SIZE_256B    0x07
#define MPU_REGION_SIZE_512B    0x08
#define MPU_REGION_SIZE_1KB     0x09
#define MPU_REGION_SIZE_2KB     0x0A
#define MPU_REGION_SIZE_4KB     0x0B
#define MPU_REGION_SIZE_8KB     0x0C
#define MPU_REGION_SIZE_16KB    0x0D
#define MPU_REGION_SIZE_32KB    0x0E
#define MPU_REGION_SIZE_64KB    0x0F
#define MPU_REGION_SIZE_128KB   0x10
#define MPU_REGION_SIZE_256KB   0x11
#define MPU_REGION_SIZE_512KB   0x12
#define MPU_REGION_SIZE_1MB     0x13
#define MPU_REGION_SIZE_2MB     0x14
#define MPU_REGION_SIZE_4MB     0x15
#define MPU_REGION_SIZE_8MB     0x16
#define MPU_REGION_SIZE_16MB    0x17
#define MPU_REGION_SIZE_32MB    0x18
#define MPU_REGION_SIZE_64MB    0x19
#define MPU_REGION_SIZE_128MB   0x1A
#define MPU_REGION_SIZE_256MB   0x1B
#define MPU_REGION_SIZE_512MB   0x1C
#define MPU_REGION_SIZE_1GB     0x1D
#define MPU_REGION_SIZE_2GB     0x1E
#define MPU_REGION_SIZE_4GB     0x1F

/*
 *  CORTEX_MPU_Region_Number CORTEX MPU Region Number
 */
#define MPU_REGION_NUMBER0      0x00
#define MPU_REGION_NUMBER1      0x01
#define MPU_REGION_NUMBER2      0x02
#define MPU_REGION_NUMBER3      0x03
#define MPU_REGION_NUMBER4      0x04
#define MPU_REGION_NUMBER5      0x05
#define MPU_REGION_NUMBER6      0x06
#define MPU_REGION_NUMBER7      0x07

/*
 *  CORTEX_MPU_Region_Permission_Attributes CORTEX MPU Region Permission Attributes 
 */
#define MPU_REGION_NO_ACCESS    0x00
#define MPU_REGION_PRIV_RW      0x01
#define MPU_REGION_PRIV_RW_URO  0x02
#define MPU_REGION_FULL_ACCESS  0x03
#define MPU_REGION_PRIV_RO      0x05
#define MPU_REGION_PRIV_RO_URO  0x06


#endif  /* _CMSIS_F7_H_ */

