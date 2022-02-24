/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siNotificationHandler_TECSGEN_H
#define siNotificationHandler_TECSGEN_H

/*
 * signature   :  siNotificationHandler
 * global name :  siNotificationHandler
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siNotificationHandler_VDES {
    struct tag_siNotificationHandler_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siNotificationHandler_VMT {
    void   (*dummy__)(void);
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siNotificationHandler_Defined
#define  Descriptor_of_siNotificationHandler_Defined
typedef struct { struct tag_siNotificationHandler_VDES *vdes; } Descriptor( siNotificationHandler );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */

#endif /* siNotificationHandler_TECSGEN_H */
