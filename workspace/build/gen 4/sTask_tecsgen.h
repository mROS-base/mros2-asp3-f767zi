/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sTask_TECSGEN_H
#define sTask_TECSGEN_H

/*
 * signature   :  sTask
 * global name :  sTask
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sTask_VDES {
    struct tag_sTask_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sTask_VMT {
    ER             (*activate__T)( const struct tag_sTask_VDES *edp );
    ER_UINT        (*cancelActivate__T)( const struct tag_sTask_VDES *edp );
    ER             (*getTaskState__T)( const struct tag_sTask_VDES *edp, STAT* p_tskstat );
    ER             (*changePriority__T)( const struct tag_sTask_VDES *edp, PRI priority );
    ER             (*getPriority__T)( const struct tag_sTask_VDES *edp, PRI* p_priority );
    ER             (*refer__T)( const struct tag_sTask_VDES *edp, T_RTSK* pk_taskStatus );
    ER             (*wakeup__T)( const struct tag_sTask_VDES *edp );
    ER_UINT        (*cancelWakeup__T)( const struct tag_sTask_VDES *edp );
    ER             (*releaseWait__T)( const struct tag_sTask_VDES *edp );
    ER             (*suspend__T)( const struct tag_sTask_VDES *edp );
    ER             (*resume__T)( const struct tag_sTask_VDES *edp );
    ER             (*raiseTerminate__T)( const struct tag_sTask_VDES *edp );
    ER             (*terminate__T)( const struct tag_sTask_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sTask_Defined
#define  Descriptor_of_sTask_Defined
typedef struct { struct tag_sTask_VDES *vdes; } Descriptor( sTask );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_STASK_ACTIVATE                  (1)
#define	FUNCID_STASK_CANCELACTIVATE            (2)
#define	FUNCID_STASK_GETTASKSTATE              (3)
#define	FUNCID_STASK_CHANGEPRIORITY            (4)
#define	FUNCID_STASK_GETPRIORITY               (5)
#define	FUNCID_STASK_REFER                     (6)
#define	FUNCID_STASK_WAKEUP                    (7)
#define	FUNCID_STASK_CANCELWAKEUP              (8)
#define	FUNCID_STASK_RELEASEWAIT               (9)
#define	FUNCID_STASK_SUSPEND                   (10)
#define	FUNCID_STASK_RESUME                    (11)
#define	FUNCID_STASK_RAISETERMINATE            (12)
#define	FUNCID_STASK_TERMINATE                 (13)

#endif /* sTask_TECSGEN_H */
