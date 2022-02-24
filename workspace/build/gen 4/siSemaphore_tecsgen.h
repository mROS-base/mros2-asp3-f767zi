/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siSemaphore_TECSGEN_H
#define siSemaphore_TECSGEN_H

/*
 * signature   :  siSemaphore
 * global name :  siSemaphore
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siSemaphore_VDES {
    struct tag_siSemaphore_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siSemaphore_VMT {
    ER             (*signal__T)( const struct tag_siSemaphore_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siSemaphore_Defined
#define  Descriptor_of_siSemaphore_Defined
typedef struct { struct tag_siSemaphore_VDES *vdes; } Descriptor( siSemaphore );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SISEMAPHORE_SIGNAL              (1)

#endif /* siSemaphore_TECSGEN_H */
