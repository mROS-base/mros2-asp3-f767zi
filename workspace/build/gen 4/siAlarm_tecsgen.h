/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siAlarm_TECSGEN_H
#define siAlarm_TECSGEN_H

/*
 * signature   :  siAlarm
 * global name :  siAlarm
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siAlarm_VDES {
    struct tag_siAlarm_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siAlarm_VMT {
    ER             (*start__T)( const struct tag_siAlarm_VDES *edp, RELTIM alarmTime );
    ER             (*stop__T)( const struct tag_siAlarm_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siAlarm_Defined
#define  Descriptor_of_siAlarm_Defined
typedef struct { struct tag_siAlarm_VDES *vdes; } Descriptor( siAlarm );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SIALARM_START                   (1)
#define	FUNCID_SIALARM_STOP                    (2)

#endif /* siAlarm_TECSGEN_H */
