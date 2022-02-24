/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tUsart_tecsgen.h"
#include "tUsart_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eSIOPort : omitted by entry port optimize */

/* eiISR : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eSIOPort : omitted by entry port optimize */
/* eiISR : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eSIOPort : omitted by entry port optimize */
/* eiISR : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tUsart_INIB tUsart_INIB_tab[] = {
    /* cell: tUsart_CB_tab[0]:  SIOPortTarget1_Usart id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        USART_BASE,                              /* baseAddress */
        BPS_SETTING,                             /* bps */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* eSIOPort : omitted by entry port optimize */
/* eiISR : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
tUsart_CB_initialize()
{
    tUsart_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
