/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tISR_tecsgen.h"
#include "tISR_factory.h"


/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tISR_INIB tISR_INIB_tab[] = {
    /* cell: tISR_CB_tab[0]:  SIOPortTarget1_ISRInstance id=1 */
    {
        /* attribute(RO) */ 
        ISRID_tISR_SIOPortTarget1_ISRInstance,   /* id */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* CB 初期化コード #_CIC_# */
void
tISR_CB_initialize()
{
    tISR_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
