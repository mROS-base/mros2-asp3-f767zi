/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siDataqueue_TECSGEN_H
#define siDataqueue_TECSGEN_H

/*
 * signature   :  siDataqueue
 * global name :  siDataqueue
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siDataqueue_VDES {
    struct tag_siDataqueue_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siDataqueue_VMT {
    ER             (*sendPolling__T)( const struct tag_siDataqueue_VDES *edp, intptr_t data );
    ER             (*sendForce__T)( const struct tag_siDataqueue_VDES *edp, intptr_t data );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siDataqueue_Defined
#define  Descriptor_of_siDataqueue_Defined
typedef struct { struct tag_siDataqueue_VDES *vdes; } Descriptor( siDataqueue );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SIDATAQUEUE_SENDPOLLING         (1)
#define	FUNCID_SIDATAQUEUE_SENDFORCE           (2)

#endif /* siDataqueue_TECSGEN_H */
