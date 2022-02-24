/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSerialPortMain_tecsgen.h"
#include "tSerialPortMain_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eSerialPort */
struct tag_tSerialPortMain_eSerialPort_DES {
    const struct tag_sSerialPort_VMT *vmt;
    tSerialPortMain_IDX  idx;
};

/* enSerialPortManage : omitted by entry port optimize */

/* eiSIOCBR : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eSerialPort */
ER             tSerialPortMain_eSerialPort_open_skel( const struct tag_sSerialPort_VDES *epd)
{
    struct tag_tSerialPortMain_eSerialPort_DES *lepd
        = (struct tag_tSerialPortMain_eSerialPort_DES *)epd;
    return tSerialPortMain_eSerialPort_open( lepd->idx );
}
ER             tSerialPortMain_eSerialPort_close_skel( const struct tag_sSerialPort_VDES *epd)
{
    struct tag_tSerialPortMain_eSerialPort_DES *lepd
        = (struct tag_tSerialPortMain_eSerialPort_DES *)epd;
    return tSerialPortMain_eSerialPort_close( lepd->idx );
}
ER_UINT        tSerialPortMain_eSerialPort_read_skel( const struct tag_sSerialPort_VDES *epd, char* buffer, uint_t length)
{
    struct tag_tSerialPortMain_eSerialPort_DES *lepd
        = (struct tag_tSerialPortMain_eSerialPort_DES *)epd;
    return tSerialPortMain_eSerialPort_read( lepd->idx, buffer, length );
}
ER_UINT        tSerialPortMain_eSerialPort_write_skel( const struct tag_sSerialPort_VDES *epd, const char* buffer, uint_t length)
{
    struct tag_tSerialPortMain_eSerialPort_DES *lepd
        = (struct tag_tSerialPortMain_eSerialPort_DES *)epd;
    return tSerialPortMain_eSerialPort_write( lepd->idx, buffer, length );
}
ER             tSerialPortMain_eSerialPort_control_skel( const struct tag_sSerialPort_VDES *epd, uint_t ioControl)
{
    struct tag_tSerialPortMain_eSerialPort_DES *lepd
        = (struct tag_tSerialPortMain_eSerialPort_DES *)epd;
    return tSerialPortMain_eSerialPort_control( lepd->idx, ioControl );
}
ER             tSerialPortMain_eSerialPort_refer_skel( const struct tag_sSerialPort_VDES *epd, T_SERIAL_RPOR* pk_rpor)
{
    struct tag_tSerialPortMain_eSerialPort_DES *lepd
        = (struct tag_tSerialPortMain_eSerialPort_DES *)epd;
    return tSerialPortMain_eSerialPort_refer( lepd->idx, pk_rpor );
}
/* enSerialPortManage : omitted by entry port optimize */
/* eiSIOCBR : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eSerialPort */
const struct tag_sSerialPort_VMT tSerialPortMain_eSerialPort_MT_ = {
    tSerialPortMain_eSerialPort_open_skel,
    tSerialPortMain_eSerialPort_close_skel,
    tSerialPortMain_eSerialPort_read_skel,
    tSerialPortMain_eSerialPort_write_skel,
    tSerialPortMain_eSerialPort_control_skel,
    tSerialPortMain_eSerialPort_refer_skel,
};
/* enSerialPortManage : omitted by entry port optimize */
/* eiSIOCBR : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
char tSerialPortMain_SerialPort1_SerialPortMain_CB_receiveBuffer_INIT[256];
char tSerialPortMain_SerialPort1_SerialPortMain_CB_sendBuffer_INIT[256];
/* セル INIB #_INIB_# */
tSerialPortMain_INIB tSerialPortMain_INIB_tab[] = {
    /* cell: tSerialPortMain_CB_tab[0]:  SerialPort1_SerialPortMain id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        256,                                     /* receiveBufferSize */
        256,                                     /* sendBufferSize */
        tSerialPortMain_SerialPort1_SerialPortMain_CB_receiveBuffer_INIT, /* receiveBuffer */
        tSerialPortMain_SerialPort1_SerialPortMain_CB_sendBuffer_INIT, /* sendBuffer */
    },
};

/* セル CB #_CB_# */
struct tag_tSerialPortMain_CB tSerialPortMain_CB_tab[1];
/* 受け口ディスクリプタ #_EPD_# */
extern const struct tag_tSerialPortMain_eSerialPort_DES SerialPort1_SerialPortMain_eSerialPort_des;
const struct tag_tSerialPortMain_eSerialPort_DES SerialPort1_SerialPortMain_eSerialPort_des = {
    &tSerialPortMain_eSerialPort_MT_,
    &tSerialPortMain_CB_tab[0],      /* CB 3 */
};
/* enSerialPortManage : omitted by entry port optimize */
/* eiSIOCBR : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
tSerialPortMain_CB_initialize()
{
    tSerialPortMain_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
