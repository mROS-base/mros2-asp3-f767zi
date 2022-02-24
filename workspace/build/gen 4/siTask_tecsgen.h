/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siTask_TECSGEN_H
#define siTask_TECSGEN_H

/*
 * signature   :  siTask
 * global name :  siTask
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siTask_VDES {
    struct tag_siTask_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siTask_VMT {
    ER             (*activate__T)( const struct tag_siTask_VDES *edp );
    ER             (*wakeup__T)( const struct tag_siTask_VDES *edp );
    ER             (*releaseWait__T)( const struct tag_siTask_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siTask_Defined
#define  Descriptor_of_siTask_Defined
typedef struct { struct tag_siTask_VDES *vdes; } Descriptor( siTask );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SITASK_ACTIVATE                 (1)
#define	FUNCID_SITASK_WAKEUP                   (2)
#define	FUNCID_SITASK_RELEASEWAIT              (3)

#endif /* siTask_TECSGEN_H */
