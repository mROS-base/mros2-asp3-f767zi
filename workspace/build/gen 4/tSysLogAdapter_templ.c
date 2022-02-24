/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSysLogAdapter_templ.c => src/tSysLogAdapter.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSysLog signature: sSysLog context:task
 *   ER             cSysLog_write( uint_t priority, const SYSLOG* p_syslog );
 *   ER_UINT        cSysLog_read( SYSLOG* p_syslog );
 *   ER             cSysLog_mask( uint_t logMask, uint_t lowMask );
 *   ER             cSysLog_refer( T_SYSLOG_RLOG* pk_rlog );
 *   ER             cSysLog_flush( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSysLogAdapter_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
