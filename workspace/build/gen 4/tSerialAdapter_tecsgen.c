/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSerialAdapter_tecsgen.h"
#include "tSerialAdapter_factory.h"


/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */
extern struct tag_sSerialPort_VDES SerialPort1_SerialPortMain_eSerialPort_des;

/* 呼び口配列 #_CPA_# */
struct tag_sSerialPort_VDES * const SerialAdapter_cSerialPort[] = {
    &SerialPort1_SerialPortMain_eSerialPort_des,
};

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tSerialAdapter_INIB tSerialAdapter_SINGLE_CELL_INIB = 
{
    /* call port (INIB) #_CP_# */ 
    SerialAdapter_cSerialPort,               /* #_CCP3B_# */
    1,                                       /* length of cSerialPort (n_cSerialPort) #_CCP4_# */
};

/* 受け口ディスクリプタ #_EPD_# */
/* CB 初期化コード #_CIC_# */
void
tSerialAdapter_CB_initialize()
{
    SET_CB_INIB_POINTER(i,p_cb)
    INITIALIZE_CB()
}
