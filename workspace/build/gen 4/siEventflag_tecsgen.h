/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siEventflag_TECSGEN_H
#define siEventflag_TECSGEN_H

/*
 * signature   :  siEventflag
 * global name :  siEventflag
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siEventflag_VDES {
    struct tag_siEventflag_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siEventflag_VMT {
    ER             (*set__T)( const struct tag_siEventflag_VDES *edp, FLGPTN setPattern );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siEventflag_Defined
#define  Descriptor_of_siEventflag_Defined
typedef struct { struct tag_siEventflag_VDES *vdes; } Descriptor( siEventflag );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SIEVENTFLAG_SET                 (1)

#endif /* siEventflag_TECSGEN_H */
