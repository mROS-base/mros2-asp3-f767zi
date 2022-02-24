/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sSemaphore_TECSGEN_H
#define sSemaphore_TECSGEN_H

/*
 * signature   :  sSemaphore
 * global name :  sSemaphore
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sSemaphore_VDES {
    struct tag_sSemaphore_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sSemaphore_VMT {
    ER             (*signal__T)( const struct tag_sSemaphore_VDES *edp );
    ER             (*wait__T)( const struct tag_sSemaphore_VDES *edp );
    ER             (*waitPolling__T)( const struct tag_sSemaphore_VDES *edp );
    ER             (*waitTimeout__T)( const struct tag_sSemaphore_VDES *edp, TMO timeout );
    ER             (*initialize__T)( const struct tag_sSemaphore_VDES *edp );
    ER             (*refer__T)( const struct tag_sSemaphore_VDES *edp, T_RSEM* pk_semaphoreStatus );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sSemaphore_Defined
#define  Descriptor_of_sSemaphore_Defined
typedef struct { struct tag_sSemaphore_VDES *vdes; } Descriptor( sSemaphore );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSEMAPHORE_SIGNAL               (1)
#define	FUNCID_SSEMAPHORE_WAIT                 (2)
#define	FUNCID_SSEMAPHORE_WAITPOLLING          (3)
#define	FUNCID_SSEMAPHORE_WAITTIMEOUT          (4)
#define	FUNCID_SSEMAPHORE_INITIALIZE           (5)
#define	FUNCID_SSEMAPHORE_REFER                (6)

#endif /* sSemaphore_TECSGEN_H */
