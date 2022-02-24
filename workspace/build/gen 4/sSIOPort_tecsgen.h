/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sSIOPort_TECSGEN_H
#define sSIOPort_TECSGEN_H

/*
 * signature   :  sSIOPort
 * global name :  sSIOPort
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sSIOPort_VDES {
    struct tag_sSIOPort_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sSIOPort_VMT {
    void           (*open__T)( const struct tag_sSIOPort_VDES *edp );
    void           (*close__T)( const struct tag_sSIOPort_VDES *edp );
    bool_t         (*putChar__T)( const struct tag_sSIOPort_VDES *edp, char c );
    int_t          (*getChar__T)( const struct tag_sSIOPort_VDES *edp );
    void           (*enableCBR__T)( const struct tag_sSIOPort_VDES *edp, uint_t cbrtn );
    void           (*disableCBR__T)( const struct tag_sSIOPort_VDES *edp, uint_t cbrtn );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sSIOPort_Defined
#define  Descriptor_of_sSIOPort_Defined
typedef struct { struct tag_sSIOPort_VDES *vdes; } Descriptor( sSIOPort );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSIOPORT_OPEN                   (1)
#define	FUNCID_SSIOPORT_CLOSE                  (2)
#define	FUNCID_SSIOPORT_PUTCHAR                (3)
#define	FUNCID_SSIOPORT_GETCHAR                (4)
#define	FUNCID_SSIOPORT_ENABLECBR              (5)
#define	FUNCID_SSIOPORT_DISABLECBR             (6)

#endif /* sSIOPort_TECSGEN_H */
