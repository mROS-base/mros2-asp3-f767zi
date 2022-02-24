/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSerialAdapter_templ.c => src/tSerialAdapter.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSerialPort signature: sSerialPort context:task
 *   ER             cSerialPort_open( subscript );
 *   ER             cSerialPort_close( subscript );
 *   ER_UINT        cSerialPort_read( subscript, char* buffer, uint_t length );
 *   ER_UINT        cSerialPort_write( subscript, const char* buffer, uint_t length );
 *   ER             cSerialPort_control( subscript, uint_t ioControl );
 *   ER             cSerialPort_refer( subscript, T_SERIAL_RPOR* pk_rpor );
 *       subscript:  0...(NCP_cSerialPort-1)
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tSerialAdapter_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
