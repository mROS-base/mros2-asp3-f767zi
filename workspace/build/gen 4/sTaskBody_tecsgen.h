/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sTaskBody_TECSGEN_H
#define sTaskBody_TECSGEN_H

/*
 * signature   :  sTaskBody
 * global name :  sTaskBody
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sTaskBody_VDES {
    struct tag_sTaskBody_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sTaskBody_VMT {
    void           (*main__T)( const struct tag_sTaskBody_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sTaskBody_Defined
#define  Descriptor_of_sTaskBody_Defined
typedef struct { struct tag_sTaskBody_VDES *vdes; } Descriptor( sTaskBody );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_STASKBODY_MAIN                  (1)

#endif /* sTaskBody_TECSGEN_H */
