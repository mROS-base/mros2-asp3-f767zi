/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siSIOCBR_TECSGEN_H
#define siSIOCBR_TECSGEN_H

/*
 * signature   :  siSIOCBR
 * global name :  siSIOCBR
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siSIOCBR_VDES {
    struct tag_siSIOCBR_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siSIOCBR_VMT {
    void           (*readySend__T)( const struct tag_siSIOCBR_VDES *edp );
    void           (*readyReceive__T)( const struct tag_siSIOCBR_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siSIOCBR_Defined
#define  Descriptor_of_siSIOCBR_Defined
typedef struct { struct tag_siSIOCBR_VDES *vdes; } Descriptor( siSIOCBR );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SISIOCBR_READYSEND              (1)
#define	FUNCID_SISIOCBR_READYRECEIVE           (2)

#endif /* siSIOCBR_TECSGEN_H */
