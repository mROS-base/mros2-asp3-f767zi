/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tBannerMain_tecsgen.h"
#include "tBannerMain_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eBannerInitialize : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eBannerInitialize : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eBannerInitialize : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tBannerMain_INIB tBannerMain_SINGLE_CELL_INIB = 
{
    /* entry port #_EP_# */ 
    /* attribute(RO) */ 
    "NUCLEO(STM32F767ZI:ARM Cortex-M7)",     /* targetName */
    "",                                      /* copyrightNotice */
};

/* 受け口ディスクリプタ #_EPD_# */
/* eBannerInitialize : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
tBannerMain_CB_initialize()
{
    SET_CB_INIB_POINTER(i,p_cb)
    INITIALIZE_CB()
}
