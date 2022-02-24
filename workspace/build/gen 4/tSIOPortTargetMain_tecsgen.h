/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSIOPortTargetMain_TECSGEN_H
#define tSIOPortTargetMain_TECSGEN_H

/*
 * celltype          :  tSIOPortTargetMain
 * global name       :  tSIOPortTargetMain
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
#include "sSIOPort_tecsgen.h"
#include "siSIOCBR_tecsgen.h"
#include "sInterruptRequest_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tSIOPortTargetMain_CB {
    int  dummy;
} tSIOPortTargetMain_CB;
/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */

/* セルタイプのIDX型 #_CTIX_# */
typedef int   tSIOPortTargetMain_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sSIOPort */
Inline void         tSIOPortTargetMain_eSIOPort_open(tSIOPortTargetMain_IDX idx);
Inline void         tSIOPortTargetMain_eSIOPort_close(tSIOPortTargetMain_IDX idx);
Inline bool_t       tSIOPortTargetMain_eSIOPort_putChar(tSIOPortTargetMain_IDX idx, char c);
Inline int_t        tSIOPortTargetMain_eSIOPort_getChar(tSIOPortTargetMain_IDX idx);
Inline void         tSIOPortTargetMain_eSIOPort_enableCBR(tSIOPortTargetMain_IDX idx, uint_t cbrtn);
Inline void         tSIOPortTargetMain_eSIOPort_disableCBR(tSIOPortTargetMain_IDX idx, uint_t cbrtn);
/* siSIOCBR */
Inline void         tSIOPortTargetMain_eiSIOCBR_readySend(tSIOPortTargetMain_IDX idx);
Inline void         tSIOPortTargetMain_eiSIOCBR_readyReceive(tSIOPortTargetMain_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tSIOPortTargetMain_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSerialPortMain_tecsgen.h"
#include "tUsart_tecsgen.h"
#include "tInterruptRequest_tecsgen.h"
#ifdef  tSIOPortTargetMain_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tSIOPortTargetMain_CB_TYPE_ONLY */
#define tSIOPortTargetMain_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tSIOPortTargetMain_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tSIOPortTargetMain_VALID_IDX(IDX) (1)

/* optional 呼び口をテストするマクロ #_TOCP_# */
#define tSIOPortTargetMain_is_ciSIOCBR_joined(p_that) \
	  (1)

/* セルCBを得るマクロ #_GCB_# */
#define tSIOPortTargetMain_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tSIOPortTargetMain_ciSIOCBR_readySend( p_that ) \
	  tSerialPortMain_eiSIOCBR_readySend( \
	   &tSerialPortMain_CB_tab[0] )
#define tSIOPortTargetMain_ciSIOCBR_readyReceive( p_that ) \
	  tSerialPortMain_eiSIOCBR_readyReceive( \
	   &tSerialPortMain_CB_tab[0] )
#define tSIOPortTargetMain_cSIOPort_open( p_that ) \
	  tUsart_eSIOPort_open( \
	   &tUsart_INIB_tab[0] )
#define tSIOPortTargetMain_cSIOPort_close( p_that ) \
	  tUsart_eSIOPort_close( \
	   &tUsart_INIB_tab[0] )
#define tSIOPortTargetMain_cSIOPort_putChar( p_that, c ) \
	  tUsart_eSIOPort_putChar( \
	   &tUsart_INIB_tab[0], (c) )
#define tSIOPortTargetMain_cSIOPort_getChar( p_that ) \
	  tUsart_eSIOPort_getChar( \
	   &tUsart_INIB_tab[0] )
#define tSIOPortTargetMain_cSIOPort_enableCBR( p_that, cbrtn ) \
	  tUsart_eSIOPort_enableCBR( \
	   &tUsart_INIB_tab[0], (cbrtn) )
#define tSIOPortTargetMain_cSIOPort_disableCBR( p_that, cbrtn ) \
	  tUsart_eSIOPort_disableCBR( \
	   &tUsart_INIB_tab[0], (cbrtn) )
#define tSIOPortTargetMain_cInterruptRequest_disable( p_that ) \
	  tInterruptRequest_eInterruptRequest_disable( \
	   &tInterruptRequest_INIB_tab[0] )
#define tSIOPortTargetMain_cInterruptRequest_enable( p_that ) \
	  tInterruptRequest_eInterruptRequest_enable( \
	   &tInterruptRequest_INIB_tab[0] )
#define tSIOPortTargetMain_cInterruptRequest_clear( p_that ) \
	  tInterruptRequest_eInterruptRequest_clear( \
	   &tInterruptRequest_INIB_tab[0] )
#define tSIOPortTargetMain_cInterruptRequest_raise( p_that ) \
	  tInterruptRequest_eInterruptRequest_raise( \
	   &tInterruptRequest_INIB_tab[0] )
#define tSIOPortTargetMain_cInterruptRequest_probe( p_that ) \
	  tInterruptRequest_eInterruptRequest_probe( \
	   &tInterruptRequest_INIB_tab[0] )

#else  /* TECSFLOW */
#define tSIOPortTargetMain_ciSIOCBR_readySend( p_that ) \
	  (p_that)->ciSIOCBR.readySend__T( \
 )
#define tSIOPortTargetMain_ciSIOCBR_readyReceive( p_that ) \
	  (p_that)->ciSIOCBR.readyReceive__T( \
 )
#define tSIOPortTargetMain_cSIOPort_open( p_that ) \
	  (p_that)->cSIOPort.open__T( \
 )
#define tSIOPortTargetMain_cSIOPort_close( p_that ) \
	  (p_that)->cSIOPort.close__T( \
 )
#define tSIOPortTargetMain_cSIOPort_putChar( p_that, c ) \
	  (p_that)->cSIOPort.putChar__T( \
 (c) )
#define tSIOPortTargetMain_cSIOPort_getChar( p_that ) \
	  (p_that)->cSIOPort.getChar__T( \
 )
#define tSIOPortTargetMain_cSIOPort_enableCBR( p_that, cbrtn ) \
	  (p_that)->cSIOPort.enableCBR__T( \
 (cbrtn) )
#define tSIOPortTargetMain_cSIOPort_disableCBR( p_that, cbrtn ) \
	  (p_that)->cSIOPort.disableCBR__T( \
 (cbrtn) )
#define tSIOPortTargetMain_cInterruptRequest_disable( p_that ) \
	  (p_that)->cInterruptRequest.disable__T( \
 )
#define tSIOPortTargetMain_cInterruptRequest_enable( p_that ) \
	  (p_that)->cInterruptRequest.enable__T( \
 )
#define tSIOPortTargetMain_cInterruptRequest_clear( p_that ) \
	  (p_that)->cInterruptRequest.clear__T( \
 )
#define tSIOPortTargetMain_cInterruptRequest_raise( p_that ) \
	  (p_that)->cInterruptRequest.raise__T( \
 )
#define tSIOPortTargetMain_cInterruptRequest_probe( p_that ) \
	  (p_that)->cInterruptRequest.probe__T( \
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
#define VALID_IDX(IDX)  tSIOPortTargetMain_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tSIOPortTargetMain_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSIOPortTargetMain_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSIOPortTargetMain_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define ciSIOCBR_readySend( ) \
          ((void)p_cellcb, tSIOPortTargetMain_ciSIOCBR_readySend( p_cellcb ))
#define ciSIOCBR_readyReceive( ) \
          ((void)p_cellcb, tSIOPortTargetMain_ciSIOCBR_readyReceive( p_cellcb ))
#define cSIOPort_open( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cSIOPort_open( p_cellcb ))
#define cSIOPort_close( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cSIOPort_close( p_cellcb ))
#define cSIOPort_putChar( c ) \
          ((void)p_cellcb, tSIOPortTargetMain_cSIOPort_putChar( p_cellcb, c ))
#define cSIOPort_getChar( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cSIOPort_getChar( p_cellcb ))
#define cSIOPort_enableCBR( cbrtn ) \
          ((void)p_cellcb, tSIOPortTargetMain_cSIOPort_enableCBR( p_cellcb, cbrtn ))
#define cSIOPort_disableCBR( cbrtn ) \
          ((void)p_cellcb, tSIOPortTargetMain_cSIOPort_disableCBR( p_cellcb, cbrtn ))
#define cInterruptRequest_disable( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cInterruptRequest_disable( p_cellcb ))
#define cInterruptRequest_enable( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cInterruptRequest_enable( p_cellcb ))
#define cInterruptRequest_clear( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cInterruptRequest_clear( p_cellcb ))
#define cInterruptRequest_raise( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cInterruptRequest_raise( p_cellcb ))
#define cInterruptRequest_probe( ) \
          ((void)p_cellcb, tSIOPortTargetMain_cInterruptRequest_probe( p_cellcb ))



/* optional 呼び口をテストするマクロ（短縮形） #_TOCPA_# */
#define is_ciSIOCBR_joined()\
		tSIOPortTargetMain_is_ciSIOCBR_joined(p_cellcb)

/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eSIOPort_open    tSIOPortTargetMain_eSIOPort_open
#define eSIOPort_close   tSIOPortTargetMain_eSIOPort_close
#define eSIOPort_putChar tSIOPortTargetMain_eSIOPort_putChar
#define eSIOPort_getChar tSIOPortTargetMain_eSIOPort_getChar
#define eSIOPort_enableCBR tSIOPortTargetMain_eSIOPort_enableCBR
#define eSIOPort_disableCBR tSIOPortTargetMain_eSIOPort_disableCBR
#define eiSIOCBR_readySend tSIOPortTargetMain_eiSIOCBR_readySend
#define eiSIOCBR_readyReceive tSIOPortTargetMain_eiSIOCBR_readyReceive

/* イテレータコード (FOREACH_CELL)の生成(CB,INIB は存在しない) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#ifndef TOPPERS_MACRO_ONLY

/* inline ヘッダの include #_INL_# */
#include "tSIOPortTargetMain_inline.h"

#endif /* TOPPERS_MACRO_ONLY */

#ifdef TOPPERS_CB_TYPE_ONLY

/* inline のための undef #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tSIOPortTargetMain_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef is_ciSIOCBR_joined
#undef tSIOPortTargetMain_ciSIOCBR_readySend
#undef ciSIOCBR_readySend
#undef tSIOPortTargetMain_ciSIOCBR_readyReceive
#undef ciSIOCBR_readyReceive
#undef tSIOPortTargetMain_cSIOPort_open
#undef cSIOPort_open
#undef tSIOPortTargetMain_cSIOPort_close
#undef cSIOPort_close
#undef tSIOPortTargetMain_cSIOPort_putChar
#undef cSIOPort_putChar
#undef tSIOPortTargetMain_cSIOPort_getChar
#undef cSIOPort_getChar
#undef tSIOPortTargetMain_cSIOPort_enableCBR
#undef cSIOPort_enableCBR
#undef tSIOPortTargetMain_cSIOPort_disableCBR
#undef cSIOPort_disableCBR
#undef tSIOPortTargetMain_cInterruptRequest_disable
#undef cInterruptRequest_disable
#undef tSIOPortTargetMain_cInterruptRequest_enable
#undef cInterruptRequest_enable
#undef tSIOPortTargetMain_cInterruptRequest_clear
#undef cInterruptRequest_clear
#undef tSIOPortTargetMain_cInterruptRequest_raise
#undef cInterruptRequest_raise
#undef tSIOPortTargetMain_cInterruptRequest_probe
#undef cInterruptRequest_probe
#undef eSIOPort_open
#undef eSIOPort_close
#undef eSIOPort_putChar
#undef eSIOPort_getChar
#undef eSIOPort_enableCBR
#undef eSIOPort_disableCBR
#undef eiSIOCBR_readySend
#undef eiSIOCBR_readyReceive
#endif /* TOPPERS_CB_TYPE_ONLY */

#endif /* tSIOPortTargetMain_TECSGENH */
