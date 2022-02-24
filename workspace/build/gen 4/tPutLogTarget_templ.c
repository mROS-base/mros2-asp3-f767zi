/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tPutLogTarget_templ.c => src/tPutLogTarget.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSIOPort signature: sSIOPort context:task
 *   void           cSIOPort_open( );
 *   void           cSIOPort_close( );
 *   bool_t         cSIOPort_putChar( char c );
 *   int_t          cSIOPort_getChar( );
 *   void           cSIOPort_enableCBR( uint_t cbrtn );
 *   void           cSIOPort_disableCBR( uint_t cbrtn );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tPutLogTarget_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# ePutLog
 * entry port: ePutLog
 * signature:  sPutLog
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# ePutLog_putChar
 * name:         ePutLog_putChar
 * global_name:  tPutLogTarget_ePutLog_putChar
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
ePutLog_putChar(char c)
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
