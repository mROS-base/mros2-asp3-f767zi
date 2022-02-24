/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tPutLogTarget_TECSGEN_H
#define tPutLogTarget_TECSGEN_H

/*
 * celltype          :  tPutLogTarget
 * global name       :  tPutLogTarget
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  yes
 * has_CB            :  no
 * has_INIB          :  no
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sPutLog_tecsgen.h"
#include "sSIOPort_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tPutLogTarget_CB {
    int  dummy;
} tPutLogTarget_CB;
/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */


/* セルタイプのIDX型 #_CTIX_# */
typedef int   tPutLogTarget_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sPutLog */
void         tPutLogTarget_ePutLog_putChar( char c);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tPutLogTarget_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSIOPortTargetMain_tecsgen.h"
#ifdef  tPutLogTarget_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tPutLogTarget_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY


/* セルCBを得るマクロ #_GCB_# */
#define tPutLogTarget_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tPutLogTarget_cSIOPort_open( ) \
	  tSIOPortTargetMain_eSIOPort_open( \
	   (tSIOPortTargetMain_IDX)0 )
#define tPutLogTarget_cSIOPort_close( ) \
	  tSIOPortTargetMain_eSIOPort_close( \
	   (tSIOPortTargetMain_IDX)0 )
#define tPutLogTarget_cSIOPort_putChar( c ) \
	  tSIOPortTargetMain_eSIOPort_putChar( \
	   (tSIOPortTargetMain_IDX)0, (c) )
#define tPutLogTarget_cSIOPort_getChar( ) \
	  tSIOPortTargetMain_eSIOPort_getChar( \
	   (tSIOPortTargetMain_IDX)0 )
#define tPutLogTarget_cSIOPort_enableCBR( cbrtn ) \
	  tSIOPortTargetMain_eSIOPort_enableCBR( \
	   (tSIOPortTargetMain_IDX)0, (cbrtn) )
#define tPutLogTarget_cSIOPort_disableCBR( cbrtn ) \
	  tSIOPortTargetMain_eSIOPort_disableCBR( \
	   (tSIOPortTargetMain_IDX)0, (cbrtn) )

#else  /* TECSFLOW */
#define tPutLogTarget_cSIOPort_open( ) \
	  (p_that)->cSIOPort.open__T( \
 )
#define tPutLogTarget_cSIOPort_close( ) \
	  (p_that)->cSIOPort.close__T( \
 )
#define tPutLogTarget_cSIOPort_putChar( c ) \
	  (p_that)->cSIOPort.putChar__T( \
 (c) )
#define tPutLogTarget_cSIOPort_getChar( ) \
	  (p_that)->cSIOPort.getChar__T( \
 )
#define tPutLogTarget_cSIOPort_enableCBR( cbrtn ) \
	  (p_that)->cSIOPort.enableCBR__T( \
 (cbrtn) )
#define tPutLogTarget_cSIOPort_disableCBR( cbrtn ) \
	  (p_that)->cSIOPort.disableCBR__T( \
 (cbrtn) )

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
#define GET_CELLCB(idx)  tPutLogTarget_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tPutLogTarget_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tPutLogTarget_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cSIOPort_open( ) \
          tPutLogTarget_cSIOPort_open( )
#define cSIOPort_close( ) \
          tPutLogTarget_cSIOPort_close( )
#define cSIOPort_putChar( c ) \
          tPutLogTarget_cSIOPort_putChar( c )
#define cSIOPort_getChar( ) \
          tPutLogTarget_cSIOPort_getChar( )
#define cSIOPort_enableCBR( cbrtn ) \
          tPutLogTarget_cSIOPort_enableCBR( cbrtn )
#define cSIOPort_disableCBR( cbrtn ) \
          tPutLogTarget_cSIOPort_disableCBR( cbrtn )




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define ePutLog_putChar  tPutLogTarget_ePutLog_putChar

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB()
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tPutLogTarget_TECSGENH */
