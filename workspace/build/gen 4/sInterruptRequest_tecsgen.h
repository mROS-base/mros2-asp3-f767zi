/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sInterruptRequest_TECSGEN_H
#define sInterruptRequest_TECSGEN_H

/*
 * signature   :  sInterruptRequest
 * global name :  sInterruptRequest
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sInterruptRequest_VDES {
    struct tag_sInterruptRequest_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sInterruptRequest_VMT {
    ER             (*disable__T)( const struct tag_sInterruptRequest_VDES *edp );
    ER             (*enable__T)( const struct tag_sInterruptRequest_VDES *edp );
    ER             (*clear__T)( const struct tag_sInterruptRequest_VDES *edp );
    ER             (*raise__T)( const struct tag_sInterruptRequest_VDES *edp );
    ER_BOOL        (*probe__T)( const struct tag_sInterruptRequest_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sInterruptRequest_Defined
#define  Descriptor_of_sInterruptRequest_Defined
typedef struct { struct tag_sInterruptRequest_VDES *vdes; } Descriptor( sInterruptRequest );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SINTERRUPTREQUEST_DISABLE       (1)
#define	FUNCID_SINTERRUPTREQUEST_ENABLE        (2)
#define	FUNCID_SINTERRUPTREQUEST_CLEAR         (3)
#define	FUNCID_SINTERRUPTREQUEST_RAISE         (4)
#define	FUNCID_SINTERRUPTREQUEST_PROBE         (5)

#endif /* sInterruptRequest_TECSGEN_H */
