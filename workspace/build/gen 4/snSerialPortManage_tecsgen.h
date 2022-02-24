/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef snSerialPortManage_TECSGEN_H
#define snSerialPortManage_TECSGEN_H

/*
 * signature   :  snSerialPortManage
 * global name :  snSerialPortManage
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_snSerialPortManage_VDES {
    struct tag_snSerialPortManage_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_snSerialPortManage_VMT {
    bool_t         (*getChar__T)( const struct tag_snSerialPortManage_VDES *edp, char* p_char );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_snSerialPortManage_Defined
#define  Descriptor_of_snSerialPortManage_Defined
typedef struct { struct tag_snSerialPortManage_VDES *vdes; } Descriptor( snSerialPortManage );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SNSERIALPORTMANAGE_GETCHAR      (1)

#endif /* snSerialPortManage_TECSGEN_H */
