/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siHandlerBody_TECSGEN_H
#define siHandlerBody_TECSGEN_H

/*
 * signature   :  siHandlerBody
 * global name :  siHandlerBody
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siHandlerBody_VDES {
    struct tag_siHandlerBody_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siHandlerBody_VMT {
    void           (*main__T)( const struct tag_siHandlerBody_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siHandlerBody_Defined
#define  Descriptor_of_siHandlerBody_Defined
typedef struct { struct tag_siHandlerBody_VDES *vdes; } Descriptor( siHandlerBody );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SIHANDLERBODY_MAIN              (1)

#endif /* siHandlerBody_TECSGEN_H */
