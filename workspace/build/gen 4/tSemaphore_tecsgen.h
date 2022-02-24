/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSemaphore_TECSGEN_H
#define tSemaphore_TECSGEN_H

/*
 * celltype          :  tSemaphore
 * global name       :  tSemaphore
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
#include "sSemaphore_tecsgen.h"
#include "siSemaphore_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tSemaphore_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    ID             id;
}  tSemaphore_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tSemaphore_CB_tab           tSemaphore_INIB_tab
#define tSemaphore_CB               tSemaphore_INIB
#define tag_tSemaphore_CB           tag_tSemaphore_INIB

/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */
extern tSemaphore_INIB  tSemaphore_INIB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tSemaphore_INIB *tSemaphore_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sSemaphore */
Inline ER           tSemaphore_eSemaphore_signal(tSemaphore_IDX idx);
Inline ER           tSemaphore_eSemaphore_wait(tSemaphore_IDX idx);
Inline ER           tSemaphore_eSemaphore_waitPolling(tSemaphore_IDX idx);
Inline ER           tSemaphore_eSemaphore_waitTimeout(tSemaphore_IDX idx, TMO timeout);
Inline ER           tSemaphore_eSemaphore_initialize(tSemaphore_IDX idx);
Inline ER           tSemaphore_eSemaphore_refer(tSemaphore_IDX idx, T_RSEM* pk_semaphoreStatus);
/* siSemaphore */
Inline ER           tSemaphore_eiSemaphore_signal(tSemaphore_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#define tSemaphore_ID_BASE          (1)  /* ID のベース  #_NIDB_# */
#define tSemaphore_N_CELL           (2)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tSemaphore_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tSemaphore_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tSemaphore_ATTR_id( p_that )	((p_that)->id)

#define tSemaphore_GET_id(p_that)	((p_that)->id)



#ifndef TECSFLOW
#else  /* TECSFLOW */
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
#define VALID_IDX(IDX)  tSemaphore_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tSemaphore_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSemaphore_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSemaphore_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_id              tSemaphore_ATTR_id( p_cellcb )





/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eSemaphore_signal tSemaphore_eSemaphore_signal
#define eSemaphore_wait  tSemaphore_eSemaphore_wait
#define eSemaphore_waitPolling tSemaphore_eSemaphore_waitPolling
#define eSemaphore_waitTimeout tSemaphore_eSemaphore_waitTimeout
#define eSemaphore_initialize tSemaphore_eSemaphore_initialize
#define eSemaphore_refer tSemaphore_eSemaphore_refer
#define eiSemaphore_signal tSemaphore_eiSemaphore_signal

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tSemaphore_N_CELL; (i)++ ){ \
       (p_cb) = &tSemaphore_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#ifndef TOPPERS_MACRO_ONLY

/* inline ヘッダの include #_INL_# */
#include "tSemaphore_inline.h"

#endif /* TOPPERS_MACRO_ONLY */

#ifdef TOPPERS_CB_TYPE_ONLY

/* inline のための undef #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tSemaphore_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef ATTR_id
#undef tSemaphore_ATTR_id
#undef tSemaphore_GET_id
#undef ATTR_attribute
#undef tSemaphore_ATTR_attribute
#undef tSemaphore_GET_attribute
#undef ATTR_initialCount
#undef tSemaphore_ATTR_initialCount
#undef tSemaphore_GET_initialCount
#undef ATTR_maxCount
#undef tSemaphore_ATTR_maxCount
#undef tSemaphore_GET_maxCount
#undef eSemaphore_signal
#undef eSemaphore_wait
#undef eSemaphore_waitPolling
#undef eSemaphore_waitTimeout
#undef eSemaphore_initialize
#undef eSemaphore_refer
#undef eiSemaphore_signal
#endif /* TOPPERS_CB_TYPE_ONLY */

#endif /* tSemaphore_TECSGENH */
