/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tInterruptRequest_TECSGEN_H
#define tInterruptRequest_TECSGEN_H

/*
 * celltype          :  tInterruptRequest
 * global name       :  tInterruptRequest
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
#include "sInterruptRequest_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tInterruptRequest_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    INTNO          interruptNumber;
}  tInterruptRequest_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tInterruptRequest_CB_tab           tInterruptRequest_INIB_tab
#define tInterruptRequest_CB               tInterruptRequest_INIB
#define tag_tInterruptRequest_CB           tag_tInterruptRequest_INIB

/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */
extern tInterruptRequest_INIB  tInterruptRequest_INIB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tInterruptRequest_INIB *tInterruptRequest_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sInterruptRequest */
Inline ER           tInterruptRequest_eInterruptRequest_disable(tInterruptRequest_IDX idx);
Inline ER           tInterruptRequest_eInterruptRequest_enable(tInterruptRequest_IDX idx);
Inline ER           tInterruptRequest_eInterruptRequest_clear(tInterruptRequest_IDX idx);
Inline ER           tInterruptRequest_eInterruptRequest_raise(tInterruptRequest_IDX idx);
Inline ER_BOOL      tInterruptRequest_eInterruptRequest_probe(tInterruptRequest_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#define tInterruptRequest_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tInterruptRequest_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tInterruptRequest_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tInterruptRequest_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tInterruptRequest_ATTR_interruptNumber( p_that )	((p_that)->interruptNumber)

#define tInterruptRequest_GET_interruptNumber(p_that)	((p_that)->interruptNumber)



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
#define VALID_IDX(IDX)  tInterruptRequest_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tInterruptRequest_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tInterruptRequest_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tInterruptRequest_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_interruptNumber tInterruptRequest_ATTR_interruptNumber( p_cellcb )





/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eInterruptRequest_disable tInterruptRequest_eInterruptRequest_disable
#define eInterruptRequest_enable tInterruptRequest_eInterruptRequest_enable
#define eInterruptRequest_clear tInterruptRequest_eInterruptRequest_clear
#define eInterruptRequest_raise tInterruptRequest_eInterruptRequest_raise
#define eInterruptRequest_probe tInterruptRequest_eInterruptRequest_probe

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tInterruptRequest_N_CELL; (i)++ ){ \
       (p_cb) = &tInterruptRequest_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#ifndef TOPPERS_MACRO_ONLY

/* inline ヘッダの include #_INL_# */
#include "tInterruptRequest_inline.h"

#endif /* TOPPERS_MACRO_ONLY */

#ifdef TOPPERS_CB_TYPE_ONLY

/* inline のための undef #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tInterruptRequest_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef ATTR_interruptNumber
#undef tInterruptRequest_ATTR_interruptNumber
#undef tInterruptRequest_GET_interruptNumber
#undef ATTR_attribute
#undef tInterruptRequest_ATTR_attribute
#undef tInterruptRequest_GET_attribute
#undef ATTR_interruptPriority
#undef tInterruptRequest_ATTR_interruptPriority
#undef tInterruptRequest_GET_interruptPriority
#undef eInterruptRequest_disable
#undef eInterruptRequest_enable
#undef eInterruptRequest_clear
#undef eInterruptRequest_raise
#undef eInterruptRequest_probe
#endif /* TOPPERS_CB_TYPE_ONLY */

#endif /* tInterruptRequest_TECSGENH */
