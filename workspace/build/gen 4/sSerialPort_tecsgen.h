/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sSerialPort_TECSGEN_H
#define sSerialPort_TECSGEN_H

/*
 * signature   :  sSerialPort
 * global name :  sSerialPort
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sSerialPort_VDES {
    struct tag_sSerialPort_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sSerialPort_VMT {
    ER             (*open__T)( const struct tag_sSerialPort_VDES *edp );
    ER             (*close__T)( const struct tag_sSerialPort_VDES *edp );
    ER_UINT        (*read__T)( const struct tag_sSerialPort_VDES *edp, char* buffer, uint_t length );
    ER_UINT        (*write__T)( const struct tag_sSerialPort_VDES *edp, const char* buffer, uint_t length );
    ER             (*control__T)( const struct tag_sSerialPort_VDES *edp, uint_t ioControl );
    ER             (*refer__T)( const struct tag_sSerialPort_VDES *edp, T_SERIAL_RPOR* pk_rpor );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sSerialPort_Defined
#define  Descriptor_of_sSerialPort_Defined
typedef struct { struct tag_sSerialPort_VDES *vdes; } Descriptor( sSerialPort );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSERIALPORT_OPEN                (1)
#define	FUNCID_SSERIALPORT_CLOSE               (2)
#define	FUNCID_SSERIALPORT_READ                (3)
#define	FUNCID_SSERIALPORT_WRITE               (4)
#define	FUNCID_SSERIALPORT_CONTROL             (5)
#define	FUNCID_SSERIALPORT_REFER               (6)

#endif /* sSerialPort_TECSGEN_H */
