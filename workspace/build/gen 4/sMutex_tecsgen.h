/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sMutex_TECSGEN_H
#define sMutex_TECSGEN_H

/*
 * signature   :  sMutex
 * global name :  sMutex
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sMutex_VDES {
    struct tag_sMutex_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sMutex_VMT {
    ER             (*lock__T)( const struct tag_sMutex_VDES *edp );
    ER             (*lockPolling__T)( const struct tag_sMutex_VDES *edp );
    ER             (*lockTimeout__T)( const struct tag_sMutex_VDES *edp, TMO timeout );
    ER             (*unlock__T)( const struct tag_sMutex_VDES *edp );
    ER             (*initialize__T)( const struct tag_sMutex_VDES *edp );
    ER             (*refer__T)( const struct tag_sMutex_VDES *edp, T_RMTX* pk_mutexStatus );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sMutex_Defined
#define  Descriptor_of_sMutex_Defined
typedef struct { struct tag_sMutex_VDES *vdes; } Descriptor( sMutex );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SMUTEX_LOCK                     (1)
#define	FUNCID_SMUTEX_LOCKPOLLING              (2)
#define	FUNCID_SMUTEX_LOCKTIMEOUT              (3)
#define	FUNCID_SMUTEX_UNLOCK                   (4)
#define	FUNCID_SMUTEX_INITIALIZE               (5)
#define	FUNCID_SMUTEX_REFER                    (6)

#endif /* sMutex_TECSGEN_H */
