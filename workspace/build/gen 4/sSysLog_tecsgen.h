/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sSysLog_TECSGEN_H
#define sSysLog_TECSGEN_H

/*
 * signature   :  sSysLog
 * global name :  sSysLog
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sSysLog_VDES {
    struct tag_sSysLog_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sSysLog_VMT {
    ER             (*write__T)( const struct tag_sSysLog_VDES *edp, uint_t priority, const SYSLOG* p_syslog );
    ER_UINT        (*read__T)( const struct tag_sSysLog_VDES *edp, SYSLOG* p_syslog );
    ER             (*mask__T)( const struct tag_sSysLog_VDES *edp, uint_t logMask, uint_t lowMask );
    ER             (*refer__T)( const struct tag_sSysLog_VDES *edp, T_SYSLOG_RLOG* pk_rlog );
    ER             (*flush__T)( const struct tag_sSysLog_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sSysLog_Defined
#define  Descriptor_of_sSysLog_Defined
typedef struct { struct tag_sSysLog_VDES *vdes; } Descriptor( sSysLog );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSYSLOG_WRITE                   (1)
#define	FUNCID_SSYSLOG_READ                    (2)
#define	FUNCID_SSYSLOG_MASK                    (3)
#define	FUNCID_SSYSLOG_REFER                   (4)
#define	FUNCID_SSYSLOG_FLUSH                   (5)

#endif /* sSysLog_TECSGEN_H */
