#ifndef tSIOPortTargetMain__INLINE_H
#define tSIOPortTargetMain__INLINE_H

/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tSIOPortTargetMain_inline_template.h => src/tSIOPortTargetMain_inline.h
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: ciSIOCBR signature: siSIOCBR context:task optional:true
 *   bool_t     is_ciSIOCBR_joined()                     check if joined
 *   void           ciSIOCBR_readySend( );
 *   void           ciSIOCBR_readyReceive( );
 * call port: cSIOPort signature: sSIOPort context:task
 *   void           cSIOPort_open( );
 *   void           cSIOPort_close( );
 *   bool_t         cSIOPort_putChar( char c );
 *   int_t          cSIOPort_getChar( );
 *   void           cSIOPort_enableCBR( uint_t cbrtn );
 *   void           cSIOPort_disableCBR( uint_t cbrtn );
 * call port: cInterruptRequest signature: sInterruptRequest context:task
 *   ER             cInterruptRequest_disable( );
 *   ER             cInterruptRequest_enable( );
 *   ER             cInterruptRequest_clear( );
 *   ER             cInterruptRequest_raise( );
 *   ER_BOOL        cInterruptRequest_probe( );
 *
 * #[</PREAMBLE>]# */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eSIOPort
 * entry port: eSIOPort
 * signature:  sSIOPort
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSIOPort_open
 * name:         eSIOPort_open
 * global_name:  tSIOPortTargetMain_eSIOPort_open
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eSIOPort_open(CELLIDX idx)
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

/* #[<ENTRY_FUNC>]# eSIOPort_close
 * name:         eSIOPort_close
 * global_name:  tSIOPortTargetMain_eSIOPort_close
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eSIOPort_close(CELLIDX idx)
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

/* #[<ENTRY_FUNC>]# eSIOPort_putChar
 * name:         eSIOPort_putChar
 * global_name:  tSIOPortTargetMain_eSIOPort_putChar
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline bool_t
eSIOPort_putChar(CELLIDX idx, char c)
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

/* #[<ENTRY_FUNC>]# eSIOPort_getChar
 * name:         eSIOPort_getChar
 * global_name:  tSIOPortTargetMain_eSIOPort_getChar
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline int_t
eSIOPort_getChar(CELLIDX idx)
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

/* #[<ENTRY_FUNC>]# eSIOPort_enableCBR
 * name:         eSIOPort_enableCBR
 * global_name:  tSIOPortTargetMain_eSIOPort_enableCBR
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eSIOPort_enableCBR(CELLIDX idx, uint_t cbrtn)
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

/* #[<ENTRY_FUNC>]# eSIOPort_disableCBR
 * name:         eSIOPort_disableCBR
 * global_name:  tSIOPortTargetMain_eSIOPort_disableCBR
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eSIOPort_disableCBR(CELLIDX idx, uint_t cbrtn)
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
 * global_name:  tSIOPortTargetMain_eiSIOCBR_readySend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
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
 * global_name:  tSIOPortTargetMain_eiSIOCBR_readyReceive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
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

#endif /* tSIOPortTargetMain_INLINEH */
