/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siKernel_TECSGEN_H
#define siKernel_TECSGEN_H

/*
 * signature   :  siKernel
 * global name :  siKernel
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siKernel_VDES {
    struct tag_siKernel_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siKernel_VMT {
    HRTCNT         (*fetchHighResolutionTimer__T)( const struct tag_siKernel_VDES *edp );
    ER             (*rotateReadyQueue__T)( const struct tag_siKernel_VDES *edp, PRI taskPriority );
    ER             (*getTaskId__T)( const struct tag_siKernel_VDES *edp, ID* p_taskId );
    ER             (*lockCpu__T)( const struct tag_siKernel_VDES *edp );
    ER             (*unlockCpu__T)( const struct tag_siKernel_VDES *edp );
    bool_t         (*senseContext__T)( const struct tag_siKernel_VDES *edp );
    bool_t         (*senseLock__T)( const struct tag_siKernel_VDES *edp );
    bool_t         (*senseDispatch__T)( const struct tag_siKernel_VDES *edp );
    bool_t         (*senseDispatchPendingState__T)( const struct tag_siKernel_VDES *edp );
    bool_t         (*senseKernel__T)( const struct tag_siKernel_VDES *edp );
    ER             (*exitKernel__T)( const struct tag_siKernel_VDES *edp );
    bool_t         (*exceptionSenseDispatchPendingState__T)( const struct tag_siKernel_VDES *edp, const void* p_exceptionInformation );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siKernel_Defined
#define  Descriptor_of_siKernel_Defined
typedef struct { struct tag_siKernel_VDES *vdes; } Descriptor( siKernel );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SIKERNEL_FETCHHIGHRESOLUTIONTIMER (1)
#define	FUNCID_SIKERNEL_ROTATEREADYQUEUE       (2)
#define	FUNCID_SIKERNEL_GETTASKID              (3)
#define	FUNCID_SIKERNEL_LOCKCPU                (4)
#define	FUNCID_SIKERNEL_UNLOCKCPU              (5)
#define	FUNCID_SIKERNEL_SENSECONTEXT           (6)
#define	FUNCID_SIKERNEL_SENSELOCK              (7)
#define	FUNCID_SIKERNEL_SENSEDISPATCH          (8)
#define	FUNCID_SIKERNEL_SENSEDISPATCHPENDINGSTATE (9)
#define	FUNCID_SIKERNEL_SENSEKERNEL            (10)
#define	FUNCID_SIKERNEL_EXITKERNEL             (11)
#define	FUNCID_SIKERNEL_EXCEPTIONSENSEDISPATCHPENDINGSTATE (12)

#endif /* siKernel_TECSGEN_H */
