/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSysLogAdapter_TECSGEN_H
#define tSysLogAdapter_TECSGEN_H

/*
 * celltype          :  tSysLogAdapter
 * global name       :  tSysLogAdapter
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
#include "sSysLog_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tSysLogAdapter_CB {
    int  dummy;
} tSysLogAdapter_CB;
/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */


/* セルタイプのIDX型 #_CTIX_# */
typedef int   tSysLogAdapter_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tSysLogAdapter_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSysLog_tecsgen.h"
#ifdef  tSysLogAdapter_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tSysLogAdapter_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY


/* セルCBを得るマクロ #_GCB_# */
#define tSysLogAdapter_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tSysLogAdapter_cSysLog_write( priority, p_syslog ) \
	  tSysLog_eSysLog_write( \
	    (priority), (p_syslog) )
#define tSysLogAdapter_cSysLog_read( p_syslog ) \
	  tSysLog_eSysLog_read( \
	    (p_syslog) )
#define tSysLogAdapter_cSysLog_mask( logMask, lowMask ) \
	  tSysLog_eSysLog_mask( \
	    (logMask), (lowMask) )
#define tSysLogAdapter_cSysLog_refer( pk_rlog ) \
	  tSysLog_eSysLog_refer( \
	    (pk_rlog) )
#define tSysLogAdapter_cSysLog_flush( ) \
	  tSysLog_eSysLog_flush( \
	    )

#else  /* TECSFLOW */
#define tSysLogAdapter_cSysLog_write( priority, p_syslog ) \
	  (p_that)->cSysLog.write__T( \
 (priority), (p_syslog) )
#define tSysLogAdapter_cSysLog_read( p_syslog ) \
	  (p_that)->cSysLog.read__T( \
 (p_syslog) )
#define tSysLogAdapter_cSysLog_mask( logMask, lowMask ) \
	  (p_that)->cSysLog.mask__T( \
 (logMask), (lowMask) )
#define tSysLogAdapter_cSysLog_refer( pk_rlog ) \
	  (p_that)->cSysLog.refer__T( \
 (pk_rlog) )
#define tSysLogAdapter_cSysLog_flush( ) \
	  (p_that)->cSysLog.flush__T( \
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


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tSysLogAdapter_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSysLogAdapter_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSysLogAdapter_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cSysLog_write( priority, p_syslog ) \
          tSysLogAdapter_cSysLog_write( priority, p_syslog )
#define cSysLog_read( p_syslog ) \
          tSysLogAdapter_cSysLog_read( p_syslog )
#define cSysLog_mask( logMask, lowMask ) \
          tSysLogAdapter_cSysLog_mask( logMask, lowMask )
#define cSysLog_refer( pk_rlog ) \
          tSysLogAdapter_cSysLog_refer( pk_rlog )
#define cSysLog_flush( ) \
          tSysLogAdapter_cSysLog_flush( )



/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB()
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSysLogAdapter_TECSGENH */
