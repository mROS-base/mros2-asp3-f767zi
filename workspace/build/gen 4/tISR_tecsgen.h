/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tISR_TECSGEN_H
#define tISR_TECSGEN_H

/*
 * celltype          :  tISR
 * global name       :  tISR
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
#include "siHandlerBody_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tISR_INIB {
    /* call port #_TCP_# */
    /* attribute(RO) #_ATO_# */ 
    ID             id;
}  tISR_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tISR_CB_tab           tISR_INIB_tab
#define tISR_CB               tISR_INIB
#define tag_tISR_CB           tag_tISR_INIB

/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */
extern tISR_INIB  tISR_INIB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tISR_INIB *tISR_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tISR_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tUsart_tecsgen.h"
#ifdef  tISR_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tISR_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tISR_ID_BASE                (1)  /* ID のベース  #_NIDB_# */
#define tISR_N_CELL                 (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tISR_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tISR_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tISR_ATTR_id( p_that )	((p_that)->id)

#define tISR_GET_id(p_that) 	((p_that)->id)



#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tISR_ciISRBody_main( p_that ) \
	  tUsart_eiISR_main( \
	   &tUsart_INIB_tab[0] )

#else  /* TECSFLOW */
#define tISR_ciISRBody_main( p_that ) \
	  (p_that)->ciISRBody.main__T( \
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
#define VALID_IDX(IDX)  tISR_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tISR_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tISR_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tISR_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_id              tISR_ATTR_id( p_cellcb )


/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define ciISRBody_main( ) \
          ((void)p_cellcb, tISR_ciISRBody_main( p_cellcb ))



/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tISR_N_CELL; (i)++ ){ \
       (p_cb) = &tISR_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tISR_TECSGENH */
