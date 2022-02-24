/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tTask_TECSGEN_H
#define tTask_TECSGEN_H

/*
 * celltype          :  tTask
 * global name       :  tTask
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  no
 * has_INIB          :  yes
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sTask_tecsgen.h"
#include "siTask_tecsgen.h"
#include "sTaskBody_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tTask_INIB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    ID             id;
}  tTask_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tTask_CB_tab           tTask_INIB_tab
#define tTask_CB               tTask_INIB
#define tag_tTask_CB           tag_tTask_INIB

/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */
extern tTask_INIB  tTask_INIB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tTask_INIB *tTask_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sTask */
Inline ER           tTask_eTask_activate(tTask_IDX idx);
Inline ER_UINT      tTask_eTask_cancelActivate(tTask_IDX idx);
Inline ER           tTask_eTask_getTaskState(tTask_IDX idx, STAT* p_tskstat);
Inline ER           tTask_eTask_changePriority(tTask_IDX idx, PRI priority);
Inline ER           tTask_eTask_getPriority(tTask_IDX idx, PRI* p_priority);
Inline ER           tTask_eTask_refer(tTask_IDX idx, T_RTSK* pk_taskStatus);
Inline ER           tTask_eTask_wakeup(tTask_IDX idx);
Inline ER_UINT      tTask_eTask_cancelWakeup(tTask_IDX idx);
Inline ER           tTask_eTask_releaseWait(tTask_IDX idx);
Inline ER           tTask_eTask_suspend(tTask_IDX idx);
Inline ER           tTask_eTask_resume(tTask_IDX idx);
Inline ER           tTask_eTask_raiseTerminate(tTask_IDX idx);
Inline ER           tTask_eTask_terminate(tTask_IDX idx);
/* siTask */
Inline ER           tTask_eiTask_activate(tTask_IDX idx);
Inline ER           tTask_eiTask_wakeup(tTask_IDX idx);
Inline ER           tTask_eiTask_releaseWait(tTask_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tTask_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tLogTaskMain_tecsgen.h"
#ifdef  tTask_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tTask_CB_TYPE_ONLY */
#define tTask_ID_BASE               (1)  /* ID のベース  #_NIDB_# */
#define tTask_N_CELL                (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tTask_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tTask_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tTask_ATTR_id( p_that )	((p_that)->id)

#define tTask_GET_id(p_that)	((p_that)->id)



#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tTask_cTaskBody_main( p_that ) \
	  tLogTaskMain_eLogTaskBody_main( \
	    )

#else  /* TECSFLOW */
#define tTask_cTaskBody_main( p_that ) \
	  (p_that)->cTaskBody.main__T( \
 )

#endif /* TECSFLOW */
#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tTask_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tTask_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tTask_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tTask_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_id              tTask_ATTR_id( p_cellcb )


/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cTaskBody_main( ) \
          ((void)p_cellcb, tTask_cTaskBody_main( p_cellcb ))




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eTask_activate   tTask_eTask_activate
#define eTask_cancelActivate tTask_eTask_cancelActivate
#define eTask_getTaskState tTask_eTask_getTaskState
#define eTask_changePriority tTask_eTask_changePriority
#define eTask_getPriority tTask_eTask_getPriority
#define eTask_refer      tTask_eTask_refer
#define eTask_wakeup     tTask_eTask_wakeup
#define eTask_cancelWakeup tTask_eTask_cancelWakeup
#define eTask_releaseWait tTask_eTask_releaseWait
#define eTask_suspend    tTask_eTask_suspend
#define eTask_resume     tTask_eTask_resume
#define eTask_raiseTerminate tTask_eTask_raiseTerminate
#define eTask_terminate  tTask_eTask_terminate
#define eiTask_activate  tTask_eiTask_activate
#define eiTask_wakeup    tTask_eiTask_wakeup
#define eiTask_releaseWait tTask_eiTask_releaseWait

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tTask_N_CELL; (i)++ ){ \
       (p_cb) = &tTask_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#ifndef TOPPERS_MACRO_ONLY

/* inline ヘッダの include #_INL_# */
#include "tTask_inline.h"

#endif /* TOPPERS_MACRO_ONLY */

#ifdef TOPPERS_CB_TYPE_ONLY

/* inline のための undef #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tTask_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef ATTR_id
#undef tTask_ATTR_id
#undef tTask_GET_id
#undef ATTR_attribute
#undef tTask_ATTR_attribute
#undef tTask_GET_attribute
#undef ATTR_priority
#undef tTask_ATTR_priority
#undef tTask_GET_priority
#undef ATTR_stackSize
#undef tTask_ATTR_stackSize
#undef tTask_GET_stackSize
#undef tTask_cTaskBody_main
#undef cTaskBody_main
#undef eTask_activate
#undef eTask_cancelActivate
#undef eTask_getTaskState
#undef eTask_changePriority
#undef eTask_getPriority
#undef eTask_refer
#undef eTask_wakeup
#undef eTask_cancelWakeup
#undef eTask_releaseWait
#undef eTask_suspend
#undef eTask_resume
#undef eTask_raiseTerminate
#undef eTask_terminate
#undef eiTask_activate
#undef eiTask_wakeup
#undef eiTask_releaseWait
#endif /* TOPPERS_CB_TYPE_ONLY */

#endif /* tTask_TECSGENH */
