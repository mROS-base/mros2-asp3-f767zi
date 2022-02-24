/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSerialAdapter_TECSGEN_H
#define tSerialAdapter_TECSGEN_H

/*
 * celltype          :  tSerialAdapter
 * global name       :  tSerialAdapter
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
#include "sSerialPort_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tSerialAdapter_INIB {
    /* call port #_TCP_# */
    struct tag_sSerialPort_VDES *const*cSerialPort;
    int_t n_cSerialPort;
}  tSerialAdapter_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tSerialAdapter_SINGLE_CELL_CB   tSerialAdapter_SINGLE_CELL_INIB
#define tSerialAdapter_CB               tSerialAdapter_INIB
#define tag_tSerialAdapter_CB           tag_tSerialAdapter_INIB

/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */
extern  tSerialAdapter_INIB  tSerialAdapter_SINGLE_CELL_INIB;


/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tSerialAdapter_INIB *tSerialAdapter_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* 呼び口配列の大きさを得るマクロ #_NCPA_# */
#define N_CP_cSerialPort  (tSerialAdapter_SINGLE_CELL_INIB.n_cSerialPort)
#define NCP_cSerialPort   (tSerialAdapter_SINGLE_CELL_INIB.n_cSerialPort)

/* セルCBを得るマクロ #_GCB_# */
#define tSerialAdapter_GET_CELLCB(idx) ((void *)0)
#ifndef TECSFLOW
 /* 呼び口関数マクロ #_CPM_# */
#define tSerialAdapter_cSerialPort_open( subscript ) \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript]->VMT->open__T( \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript] )
#define tSerialAdapter_cSerialPort_close( subscript ) \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript]->VMT->close__T( \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript] )
#define tSerialAdapter_cSerialPort_read( subscript, buffer, length ) \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript]->VMT->read__T( \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript], (buffer), (length) )
#define tSerialAdapter_cSerialPort_write( subscript, buffer, length ) \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript]->VMT->write__T( \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript], (buffer), (length) )
#define tSerialAdapter_cSerialPort_control( subscript, ioControl ) \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript]->VMT->control__T( \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript], (ioControl) )
#define tSerialAdapter_cSerialPort_refer( subscript, pk_rpor ) \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript]->VMT->refer__T( \
	  tSerialAdapter_SINGLE_CELL_INIB.cSerialPort[subscript], (pk_rpor) )

#else  /* TECSFLOW */
#define tSerialAdapter_cSerialPort_open( subscript ) \
	  (p_that)->cSerialPort[subscript].open__T( \
 )
#define tSerialAdapter_cSerialPort_close( subscript ) \
	  (p_that)->cSerialPort[subscript].close__T( \
 )
#define tSerialAdapter_cSerialPort_read( subscript, buffer, length ) \
	  (p_that)->cSerialPort[subscript].read__T( \
 (buffer), (length) )
#define tSerialAdapter_cSerialPort_write( subscript, buffer, length ) \
	  (p_that)->cSerialPort[subscript].write__T( \
 (buffer), (length) )
#define tSerialAdapter_cSerialPort_control( subscript, ioControl ) \
	  (p_that)->cSerialPort[subscript].control__T( \
 (ioControl) )
#define tSerialAdapter_cSerialPort_refer( subscript, pk_rpor ) \
	  (p_that)->cSerialPort[subscript].refer__T( \
 (pk_rpor) )

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
#define GET_CELLCB(idx)  tSerialAdapter_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSerialAdapter_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSerialAdapter_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cSerialPort_open( subscript ) \
          tSerialAdapter_cSerialPort_open( subscript )
#define cSerialPort_close( subscript ) \
          tSerialAdapter_cSerialPort_close( subscript )
#define cSerialPort_read( subscript, buffer, length ) \
          tSerialAdapter_cSerialPort_read( subscript, buffer, length )
#define cSerialPort_write( subscript, buffer, length ) \
          tSerialAdapter_cSerialPort_write( subscript, buffer, length )
#define cSerialPort_control( subscript, ioControl ) \
          tSerialAdapter_cSerialPort_control( subscript, ioControl )
#define cSerialPort_refer( subscript, pk_rpor ) \
          tSerialAdapter_cSerialPort_refer( subscript, pk_rpor )



/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB()
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSerialAdapter_TECSGENH */
