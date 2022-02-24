/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sKernel_TECSGEN_H
#define sKernel_TECSGEN_H

/*
 * signature   :  sKernel
 * global name :  sKernel
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sKernel_VDES {
    struct tag_sKernel_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sKernel_VMT {
    ER             (*getExtendedInformation__T)( const struct tag_sKernel_VDES *edp, intptr_t* p_exinf );
    ER             (*sleep__T)( const struct tag_sKernel_VDES *edp );
    ER             (*sleepTimeout__T)( const struct tag_sKernel_VDES *edp, TMO timeout );
    ER             (*delay__T)( const struct tag_sKernel_VDES *edp, RELTIM delayTime );
    ER             (*exit__T)( const struct tag_sKernel_VDES *edp );
    ER             (*disableTerminate__T)( const struct tag_sKernel_VDES *edp );
    ER             (*enableTerminate__T)( const struct tag_sKernel_VDES *edp );
    bool_t         (*senseTerminate__T)( const struct tag_sKernel_VDES *edp );
    ER             (*setTime__T)( const struct tag_sKernel_VDES *edp, SYSTIM systemTime );
    ER             (*getTime__T)( const struct tag_sKernel_VDES *edp, SYSTIM* p_systemTime );
    ER             (*adjustTime__T)( const struct tag_sKernel_VDES *edp, int32_t adjustTime );
    HRTCNT         (*fetchHighResolutionTimer__T)( const struct tag_sKernel_VDES *edp );
    ER             (*rotateReadyQueue__T)( const struct tag_sKernel_VDES *edp, PRI taskPriority );
    ER             (*getTaskId__T)( const struct tag_sKernel_VDES *edp, ID* p_taskId );
    ER             (*getLoad__T)( const struct tag_sKernel_VDES *edp, PRI taskPriority, uint_t* p_load );
    ER             (*getNthTask__T)( const struct tag_sKernel_VDES *edp, PRI taskPriority, uint_t nth, ID* p_taskID );
    ER             (*lockCpu__T)( const struct tag_sKernel_VDES *edp );
    ER             (*unlockCpu__T)( const struct tag_sKernel_VDES *edp );
    ER             (*disableDispatch__T)( const struct tag_sKernel_VDES *edp );
    ER             (*enableDispatch__T)( const struct tag_sKernel_VDES *edp );
    bool_t         (*senseContext__T)( const struct tag_sKernel_VDES *edp );
    bool_t         (*senseLock__T)( const struct tag_sKernel_VDES *edp );
    bool_t         (*senseDispatch__T)( const struct tag_sKernel_VDES *edp );
    bool_t         (*senseDispatchPendingState__T)( const struct tag_sKernel_VDES *edp );
    bool_t         (*senseKernel__T)( const struct tag_sKernel_VDES *edp );
    ER             (*exitKernel__T)( const struct tag_sKernel_VDES *edp );
    ER             (*changeInterruptPriorityMask__T)( const struct tag_sKernel_VDES *edp, PRI interruptPriority );
    ER             (*getInterruptPriorityMask__T)( const struct tag_sKernel_VDES *edp, PRI* p_interruptPriority );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sKernel_Defined
#define  Descriptor_of_sKernel_Defined
typedef struct { struct tag_sKernel_VDES *vdes; } Descriptor( sKernel );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SKERNEL_GETEXTENDEDINFORMATION  (1)
#define	FUNCID_SKERNEL_SLEEP                   (2)
#define	FUNCID_SKERNEL_SLEEPTIMEOUT            (3)
#define	FUNCID_SKERNEL_DELAY                   (4)
#define	FUNCID_SKERNEL_EXIT                    (5)
#define	FUNCID_SKERNEL_DISABLETERMINATE        (6)
#define	FUNCID_SKERNEL_ENABLETERMINATE         (7)
#define	FUNCID_SKERNEL_SENSETERMINATE          (8)
#define	FUNCID_SKERNEL_SETTIME                 (9)
#define	FUNCID_SKERNEL_GETTIME                 (10)
#define	FUNCID_SKERNEL_ADJUSTTIME              (11)
#define	FUNCID_SKERNEL_FETCHHIGHRESOLUTIONTIMER (12)
#define	FUNCID_SKERNEL_ROTATEREADYQUEUE        (13)
#define	FUNCID_SKERNEL_GETTASKID               (14)
#define	FUNCID_SKERNEL_GETLOAD                 (15)
#define	FUNCID_SKERNEL_GETNTHTASK              (16)
#define	FUNCID_SKERNEL_LOCKCPU                 (17)
#define	FUNCID_SKERNEL_UNLOCKCPU               (18)
#define	FUNCID_SKERNEL_DISABLEDISPATCH         (19)
#define	FUNCID_SKERNEL_ENABLEDISPATCH          (20)
#define	FUNCID_SKERNEL_SENSECONTEXT            (21)
#define	FUNCID_SKERNEL_SENSELOCK               (22)
#define	FUNCID_SKERNEL_SENSEDISPATCH           (23)
#define	FUNCID_SKERNEL_SENSEDISPATCHPENDINGSTATE (24)
#define	FUNCID_SKERNEL_SENSEKERNEL             (25)
#define	FUNCID_SKERNEL_EXITKERNEL              (26)
#define	FUNCID_SKERNEL_CHANGEINTERRUPTPRIORITYMASK (27)
#define	FUNCID_SKERNEL_GETINTERRUPTPRIORITYMASK (28)

#endif /* sKernel_TECSGEN_H */
