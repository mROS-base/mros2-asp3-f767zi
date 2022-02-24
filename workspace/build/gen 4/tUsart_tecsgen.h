/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tUsart_TECSGEN_H
#define tUsart_TECSGEN_H

/*
 * celltype          :  tUsart
 * global name       :  tUsart
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
#include "sSIOPort_tecsgen.h"
#include "siSIOCBR_tecsgen.h"
#include "siHandlerBody_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tUsart_INIB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    uintptr_t      baseAddress;
    uint32_t       bps;
}  tUsart_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tUsart_CB_tab           tUsart_INIB_tab
#define tUsart_CB               tUsart_INIB
#define tag_tUsart_CB           tag_tUsart_INIB

/* シングルトンセル CB プロトタイプ宣言 #_MCPB_# */
extern tUsart_INIB  tUsart_INIB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tUsart_INIB *tUsart_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sSIOPort */
void         tUsart_eSIOPort_open(tUsart_IDX idx);
void         tUsart_eSIOPort_close(tUsart_IDX idx);
bool_t       tUsart_eSIOPort_putChar(tUsart_IDX idx, char c);
int_t        tUsart_eSIOPort_getChar(tUsart_IDX idx);
void         tUsart_eSIOPort_enableCBR(tUsart_IDX idx, uint_t cbrtn);
void         tUsart_eSIOPort_disableCBR(tUsart_IDX idx, uint_t cbrtn);
/* siHandlerBody */
void         tUsart_eiISR_main(tUsart_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tUsart_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSIOPortTargetMain_tecsgen.h"
#ifdef  tUsart_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tUsart_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tUsart_ID_BASE              (1)  /* ID のベース  #_NIDB_# */
#define tUsart_N_CELL               (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tUsart_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tUsart_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tUsart_ATTR_baseAddress( p_that )	((p_that)->baseAddress)
#define tUsart_ATTR_bps( p_that )	((p_that)->bps)

#define tUsart_GET_baseAddress(p_that)	((p_that)->baseAddress)
#define tUsart_GET_bps(p_that)	((p_that)->bps)



#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tUsart_ciSIOCBR_readySend( p_that ) \
	  tSIOPortTargetMain_eiSIOCBR_readySend( \
	   (tSIOPortTargetMain_IDX)0 )
#define tUsart_ciSIOCBR_readyReceive( p_that ) \
	  tSIOPortTargetMain_eiSIOCBR_readyReceive( \
	   (tSIOPortTargetMain_IDX)0 )

#else  /* TECSFLOW */
#define tUsart_ciSIOCBR_readySend( p_that ) \
	  (p_that)->ciSIOCBR.readySend__T( \
 )
#define tUsart_ciSIOCBR_readyReceive( p_that ) \
	  (p_that)->ciSIOCBR.readyReceive__T( \
 )

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

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tUsart_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tUsart_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tUsart_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tUsart_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_baseAddress     tUsart_ATTR_baseAddress( p_cellcb )
#define ATTR_bps             tUsart_ATTR_bps( p_cellcb )


/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define ciSIOCBR_readySend( ) \
          ((void)p_cellcb, tUsart_ciSIOCBR_readySend( p_cellcb ))
#define ciSIOCBR_readyReceive( ) \
          ((void)p_cellcb, tUsart_ciSIOCBR_readyReceive( p_cellcb ))




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eSIOPort_open    tUsart_eSIOPort_open
#define eSIOPort_close   tUsart_eSIOPort_close
#define eSIOPort_putChar tUsart_eSIOPort_putChar
#define eSIOPort_getChar tUsart_eSIOPort_getChar
#define eSIOPort_enableCBR tUsart_eSIOPort_enableCBR
#define eSIOPort_disableCBR tUsart_eSIOPort_disableCBR
#define eiISR_main       tUsart_eiISR_main

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tUsart_N_CELL; (i)++ ){ \
       (p_cb) = &tUsart_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tUsart_TECSGENH */
