/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tTerminateRoutine_TECSGEN_H
#define tTerminateRoutine_TECSGEN_H

/*
 * celltype          :  tTerminateRoutine
 * global name       :  tTerminateRoutine
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  no
 * has_INIB          :  no
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sRoutineBody_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tTerminateRoutine_CB {
    int  dummy;
} tTerminateRoutine_CB;
/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */

/* セルタイプのIDX型 #_CTIX_# */
typedef int   tTerminateRoutine_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tTerminateRoutine_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tLogTaskMain_tecsgen.h"
#ifdef  tTerminateRoutine_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tTerminateRoutine_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tTerminateRoutine_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tTerminateRoutine_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tTerminateRoutine_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tTerminateRoutine_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tTerminateRoutine_cTerminateRoutineBody_main( p_that ) \
	  tLogTaskMain_eLogTaskTerminate_main( \
	    )

#else  /* TECSFLOW */
#define tTerminateRoutine_cTerminateRoutineBody_main( p_that ) \
	  (p_that)->cTerminateRoutineBody.main__T( \
 )

#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tTerminateRoutine_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tTerminateRoutine_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tTerminateRoutine_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tTerminateRoutine_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cTerminateRoutineBody_main( ) \
          ((void)p_cellcb, tTerminateRoutine_cTerminateRoutineBody_main( p_cellcb ))



/* イテレータコード (FOREACH_CELL)の生成(CB,INIB は存在しない) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tTerminateRoutine_TECSGENH */
