/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSysLog_tecsgen.h"
#include "tSysLog_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eSysLog : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eSysLog : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eSysLog : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
SYSLOG tSysLog_SINGLE_CELL_CB_logBuffer_INIT[32];
/* セル INIB #_INIB_# */
tSysLog_INIB tSysLog_SINGLE_CELL_INIB = 
{
    /* entry port #_EP_# */ 
    /* attribute(RO) */ 
    32,                                      /* logBufferSize */
    LOG_UPTO(LOG_DEBUG),                     /* initLogMask */
    LOG_UPTO(LOG_EMERG),                     /* initLowMask */
    tSysLog_SINGLE_CELL_CB_logBuffer_INIT,   /* logBuffer */
};

/* セル CB #_CB_# */
struct tag_tSysLog_CB tSysLog_SINGLE_CELL_CB;
/* 受け口ディスクリプタ #_EPD_# */
/* eSysLog : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
tSysLog_CB_initialize()
{
    SET_CB_INIB_POINTER(i,p_cb)
    INITIALIZE_CB()
}
