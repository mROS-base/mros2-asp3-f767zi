/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSerialPortMain_templ.c => src/tSerialPortMain.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * receiveBufferSize uint_t           ATTR_receiveBufferSize
 * sendBufferSize   uint_t           ATTR_sendBufferSize
 * openFlag         bool_t           VAR_openFlag    
 * errorFlag        bool_t           VAR_errorFlag   
 * ioControl        uint_t           VAR_ioControl   
 * receiveBuffer    char*            VAR_receiveBuffer
 * receiveReadPointer uint_t           VAR_receiveReadPointer
 * receiveWritePointer uint_t           VAR_receiveWritePointer
 * receiveCount     uint_t           VAR_receiveCount
 * receiveFlowControl char             VAR_receiveFlowControl
 * receiveStopped   bool_t           VAR_receiveStopped
 * sendBuffer       char*            VAR_sendBuffer  
 * sendReadPointer  uint_t           VAR_sendReadPointer
 * sendWritePointer uint_t           VAR_sendWritePointer
 * sendCount        uint_t           VAR_sendCount   
 * sendStopped      bool_t           VAR_sendStopped 
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSIOPort signature: sSIOPort context:task
 *   void           cSIOPort_open( );
 *   void           cSIOPort_close( );
 *   bool_t         cSIOPort_putChar( char c );
 *   int_t          cSIOPort_getChar( );
 *   void           cSIOPort_enableCBR( uint_t cbrtn );
 *   void           cSIOPort_disableCBR( uint_t cbrtn );
 * call port: cSendSemaphore signature: sSemaphore context:task
 *   ER             cSendSemaphore_signal( );
 *   ER             cSendSemaphore_wait( );
 *   ER             cSendSemaphore_waitPolling( );
 *   ER             cSendSemaphore_waitTimeout( TMO timeout );
 *   ER             cSendSemaphore_initialize( );
 *   ER             cSendSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: ciSendSemaphore signature: siSemaphore context:non-task
 *   ER             ciSendSemaphore_signal( );
 * call port: cReceiveSemaphore signature: sSemaphore context:task
 *   ER             cReceiveSemaphore_signal( );
 *   ER             cReceiveSemaphore_wait( );
 *   ER             cReceiveSemaphore_waitPolling( );
 *   ER             cReceiveSemaphore_waitTimeout( TMO timeout );
 *   ER             cReceiveSemaphore_initialize( );
 *   ER             cReceiveSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: ciReceiveSemaphore signature: siSemaphore context:non-task
 *   ER             ciReceiveSemaphore_signal( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSerialPortMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSerialPort
 * entry port: eSerialPort
 * signature:  sSerialPort
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSerialPort_open
 * name:         eSerialPort_open
 * global_name:  tSerialPortMain_eSerialPort_open
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSerialPort_open(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSerialPort_close
 * name:         eSerialPort_close
 * global_name:  tSerialPortMain_eSerialPort_close
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSerialPort_close(CELLIDX idx)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSerialPort_read
 * name:         eSerialPort_read
 * global_name:  tSerialPortMain_eSerialPort_read
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eSerialPort_read(CELLIDX idx, char* buffer, uint_t length)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSerialPort_write
 * name:         eSerialPort_write
 * global_name:  tSerialPortMain_eSerialPort_write
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eSerialPort_write(CELLIDX idx, const char* buffer, uint_t length)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSerialPort_control
 * name:         eSerialPort_control
 * global_name:  tSerialPortMain_eSerialPort_control
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSerialPort_control(CELLIDX idx, uint_t ioControl)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eSerialPort_refer
 * name:         eSerialPort_refer
 * global_name:  tSerialPortMain_eSerialPort_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eSerialPort_refer(CELLIDX idx, T_SERIAL_RPOR* pk_rpor)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_PORT>]# enSerialPortManage
 * entry port: enSerialPortManage
 * signature:  snSerialPortManage
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# enSerialPortManage_getChar
 * name:         enSerialPortManage_getChar
 * global_name:  tSerialPortMain_enSerialPortManage_getChar
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
enSerialPortManage_getChar(CELLIDX idx, char* p_char)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eiSIOCBR
 * entry port: eiSIOCBR
 * signature:  siSIOCBR
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiSIOCBR_readySend
 * name:         eiSIOCBR_readySend
 * global_name:  tSerialPortMain_eiSIOCBR_readySend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiSIOCBR_readySend(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eiSIOCBR_readyReceive
 * name:         eiSIOCBR_readyReceive
 * global_name:  tSerialPortMain_eiSIOCBR_readyReceive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiSIOCBR_readyReceive(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
