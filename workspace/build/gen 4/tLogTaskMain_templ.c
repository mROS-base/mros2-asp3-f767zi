/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tLogTaskMain_templ.c => src/tLogTaskMain.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * interval         RELTIM           ATTR_interval   
 * flushWait        RELTIM           ATTR_flushWait  
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSerialPort signature: sSerialPort context:task
 *   ER             cSerialPort_open( );
 *   ER             cSerialPort_close( );
 *   ER_UINT        cSerialPort_read( char* buffer, uint_t length );
 *   ER_UINT        cSerialPort_write( const char* buffer, uint_t length );
 *   ER             cSerialPort_control( uint_t ioControl );
 *   ER             cSerialPort_refer( T_SERIAL_RPOR* pk_rpor );
 * call port: cnSerialPortManage signature: snSerialPortManage context:task
 *   bool_t         cnSerialPortManage_getChar( char* p_char );
 * call port: cSysLog signature: sSysLog context:task
 *   ER             cSysLog_write( uint_t priority, const SYSLOG* p_syslog );
 *   ER_UINT        cSysLog_read( SYSLOG* p_syslog );
 *   ER             cSysLog_mask( uint_t logMask, uint_t lowMask );
 *   ER             cSysLog_refer( T_SYSLOG_RLOG* pk_rlog );
 *   ER             cSysLog_flush( );
 * call port: cPutLog signature: sPutLog context:task
 *   void           cPutLog_putChar( char c );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tLogTaskMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eLogTaskBody
 * entry port: eLogTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLogTaskBody_main
 * name:         eLogTaskBody_main
 * global_name:  tLogTaskMain_eLogTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLogTaskBody_main()
{
}

/* #[<ENTRY_PORT>]# eLogTaskTerminate
 * entry port: eLogTaskTerminate
 * signature:  sRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLogTaskTerminate_main
 * name:         eLogTaskTerminate_main
 * global_name:  tLogTaskMain_eLogTaskTerminate_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLogTaskTerminate_main()
{
}

/* #[<ENTRY_PORT>]# eLogTask
 * entry port: eLogTask
 * signature:  sLogTask
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLogTask_flush
 * name:         eLogTask_flush
 * global_name:  tLogTaskMain_eLogTask_flush
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLogTask_flush(uint_t count)
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
