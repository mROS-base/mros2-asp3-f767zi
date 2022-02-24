/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSysLog_TECSGEN_H
#define tSysLog_TECSGEN_H

/*
 * celltype          :  tSysLog
 * global name       :  tSysLog
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  yes
 * has_CB            :  yes
 * has_INIB          :  yes
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sSysLog_tecsgen.h"
#include "sPutLog_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tSysLog_INIB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    uint_t         logBufferSize;
    uint_t         initLogMask;
    uint_t         initLowMask;
    SYSLOG*        logBuffer;
}  tSysLog_INIB;
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tSysLog_CB {
    tSysLog_INIB  *_inib;
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    uint_t         count;
    uint_t         head;
    uint_t         tail;
    uint_t         lost;
    uint_t         logMask;
    uint_t         lowMask;
}  tSysLog_CB;
/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */
extern  tSysLog_CB  tSysLog_SINGLE_CELL_CB;
extern  tSysLog_INIB  tSysLog_SINGLE_CELL_INIB;


/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tSysLog_CB *tSysLog_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sSysLog */
ER           tSysLog_eSysLog_write( uint_t priority, const SYSLOG* p_syslog);
ER_UINT      tSysLog_eSysLog_read( SYSLOG* p_syslog);
ER           tSysLog_eSysLog_mask( uint_t logMask, uint_t lowMask);
ER           tSysLog_eSysLog_refer( T_SYSLOG_RLOG* pk_rlog);
ER           tSysLog_eSysLog_flush();
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tSysLog_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tPutLogTarget_tecsgen.h"
#ifdef  tSysLog_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tSysLog_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY


/* セルCBを得るマクロ #_GCB_# */
#define tSysLog_GET_CELLCB(idx) ((void *)0)

/* 属性アクセスマクロ #_AAM_# */
#define tSysLog_ATTR_logBufferSize	(tSysLog_SINGLE_CELL_INIB.logBufferSize)
#define tSysLog_ATTR_initLogMask	(tSysLog_SINGLE_CELL_INIB.initLogMask)
#define tSysLog_ATTR_initLowMask	(tSysLog_SINGLE_CELL_INIB.initLowMask)

#define tSysLog_GET_logBufferSize()	(tSysLog_SINGLE_CELL_INIB.logBufferSize)
#define tSysLog_GET_initLogMask()	(tSysLog_SINGLE_CELL_INIB.initLogMask)
#define tSysLog_GET_initLowMask()	(tSysLog_SINGLE_CELL_INIB.initLowMask)


/* var アクセスマクロ #_VAM_# */
#define tSysLog_VAR_logBuffer	(tSysLog_SINGLE_CELL_INIB.logBuffer)
#define tSysLog_VAR_count   	(tSysLog_SINGLE_CELL_CB.count)
#define tSysLog_VAR_head    	(tSysLog_SINGLE_CELL_CB.head)
#define tSysLog_VAR_tail    	(tSysLog_SINGLE_CELL_CB.tail)
#define tSysLog_VAR_lost    	(tSysLog_SINGLE_CELL_CB.lost)
#define tSysLog_VAR_logMask 	(tSysLog_SINGLE_CELL_CB.logMask)
#define tSysLog_VAR_lowMask 	(tSysLog_SINGLE_CELL_CB.lowMask)

#define tSysLog_GET_logBuffer()	(tSysLog_SINGLE_CELL_CB.logBuffer)
#define tSysLog_SET_logBuffer(val)	(tSysLog_SINGLE_CELL_CB.logBuffer=(val))
#define tSysLog_GET_count() 	(tSysLog_SINGLE_CELL_CB.count)
#define tSysLog_SET_count(val)	(tSysLog_SINGLE_CELL_CB.count=(val))
#define tSysLog_GET_head()  	(tSysLog_SINGLE_CELL_CB.head)
#define tSysLog_SET_head(val)	(tSysLog_SINGLE_CELL_CB.head=(val))
#define tSysLog_GET_tail()  	(tSysLog_SINGLE_CELL_CB.tail)
#define tSysLog_SET_tail(val)	(tSysLog_SINGLE_CELL_CB.tail=(val))
#define tSysLog_GET_lost()  	(tSysLog_SINGLE_CELL_CB.lost)
#define tSysLog_SET_lost(val)	(tSysLog_SINGLE_CELL_CB.lost=(val))
#define tSysLog_GET_logMask()	(tSysLog_SINGLE_CELL_CB.logMask)
#define tSysLog_SET_logMask(val)	(tSysLog_SINGLE_CELL_CB.logMask=(val))
#define tSysLog_GET_lowMask()	(tSysLog_SINGLE_CELL_CB.lowMask)
#define tSysLog_SET_lowMask(val)	(tSysLog_SINGLE_CELL_CB.lowMask=(val))

#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tSysLog_cPutLog_putChar( c ) \
	  tPutLogTarget_ePutLog_putChar( \
	    (c) )

#else  /* TECSFLOW */
#define tSysLog_cPutLog_putChar( c ) \
	  (p_that)->cPutLog.putChar__T( \
 (c) )

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
#define GET_CELLCB(idx)  tSysLog_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSysLog_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSysLog_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_logBufferSize   tSysLog_ATTR_logBufferSize
#define ATTR_initLogMask     tSysLog_ATTR_initLogMask
#define ATTR_initLowMask     tSysLog_ATTR_initLowMask


/* var アクセスマクロ(短縮形) #_VAMA_# */
#define VAR_logBuffer        tSysLog_VAR_logBuffer
#define VAR_count            tSysLog_VAR_count
#define VAR_head             tSysLog_VAR_head
#define VAR_tail             tSysLog_VAR_tail
#define VAR_lost             tSysLog_VAR_lost
#define VAR_logMask          tSysLog_VAR_logMask
#define VAR_lowMask          tSysLog_VAR_lowMask

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cPutLog_putChar( c ) \
          tSysLog_cPutLog_putChar( c )




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eSysLog_write    tSysLog_eSysLog_write
#define eSysLog_read     tSysLog_eSysLog_read
#define eSysLog_mask     tSysLog_eSysLog_mask
#define eSysLog_refer    tSysLog_eSysLog_refer
#define eSysLog_flush    tSysLog_eSysLog_flush

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB()\
	tSysLog_SINGLE_CELL_CB.count = 0;\
	tSysLog_SINGLE_CELL_CB.head = 0;\
	tSysLog_SINGLE_CELL_CB.tail = 0;\
	tSysLog_SINGLE_CELL_CB.lost = 0;\
	tSysLog_SINGLE_CELL_CB.logMask = tSysLog_ATTR_initLogMask;\
	tSysLog_SINGLE_CELL_CB.lowMask = tSysLog_ATTR_initLowMask;
#define SET_CB_INIB_POINTER(i,p_that)\
	tSysLog_SINGLE_CELL_CB._inib = &tSysLog_SINGLE_CELL_INIB;

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSysLog_TECSGENH */
