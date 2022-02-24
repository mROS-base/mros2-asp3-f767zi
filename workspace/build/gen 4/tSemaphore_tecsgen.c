/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSemaphore_tecsgen.h"
#include "tSemaphore_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eSemaphore : omitted by entry port optimize */

/* eiSemaphore : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */


/* 呼び口配列 #_CPA_# */


/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tSemaphore_INIB tSemaphore_INIB_tab[] = {
    /* cell: tSemaphore_CB_tab[0]:  SerialPort1_ReceiveSemaphore id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        SEMID_tSemaphore_SerialPort1_ReceiveSemaphore, /* id */
    },
    /* cell: tSemaphore_CB_tab[1]:  SerialPort1_SendSemaphore id=2 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        SEMID_tSemaphore_SerialPort1_SendSemaphore, /* id */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
tSemaphore_CB_initialize()
{
    tSemaphore_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
