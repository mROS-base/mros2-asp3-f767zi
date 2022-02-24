/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tBannerMain_TECSGEN_H
#define tBannerMain_TECSGEN_H

/*
 * celltype          :  tBannerMain
 * global name       :  tBannerMain
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  yes
 * has_CB            :  no
 * has_INIB          :  yes
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
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tBannerMain_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    char*          targetName;
    char*          copyrightNotice;
}  tBannerMain_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tBannerMain_SINGLE_CELL_CB   tBannerMain_SINGLE_CELL_INIB
#define tBannerMain_CB               tBannerMain_INIB
#define tag_tBannerMain_CB           tag_tBannerMain_INIB

/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */
extern  tBannerMain_INIB  tBannerMain_SINGLE_CELL_INIB;


/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tBannerMain_INIB *tBannerMain_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sRoutineBody */
void         tBannerMain_eBannerInitialize_main();
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY


/* セルCBを得るマクロ #_GCB_# */
#define tBannerMain_GET_CELLCB(idx) ((void *)0)

/* 属性アクセスマクロ #_AAM_# */
#define tBannerMain_ATTR_targetName	(tBannerMain_SINGLE_CELL_INIB.targetName)
#define tBannerMain_ATTR_copyrightNotice	(tBannerMain_SINGLE_CELL_INIB.copyrightNotice)

#define tBannerMain_GET_targetName()	(tBannerMain_SINGLE_CELL_INIB.targetName)
#define tBannerMain_GET_copyrightNotice()	(tBannerMain_SINGLE_CELL_INIB.copyrightNotice)



#ifndef TECSFLOW
#else  /* TECSFLOW */
#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tBannerMain_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tBannerMain_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tBannerMain_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_targetName      tBannerMain_ATTR_targetName
#define ATTR_copyrightNotice tBannerMain_ATTR_copyrightNotice





/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eBannerInitialize_main tBannerMain_eBannerInitialize_main

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB()
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tBannerMain_TECSGENH */
