/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sDataqueue_TECSGEN_H
#define sDataqueue_TECSGEN_H

/*
 * signature   :  sDataqueue
 * global name :  sDataqueue
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sDataqueue_VDES {
    struct tag_sDataqueue_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sDataqueue_VMT {
    ER             (*send__T)( const struct tag_sDataqueue_VDES *edp, intptr_t data );
    ER             (*sendPolling__T)( const struct tag_sDataqueue_VDES *edp, intptr_t data );
    ER             (*sendTimeout__T)( const struct tag_sDataqueue_VDES *edp, intptr_t data, TMO timeout );
    ER             (*sendForce__T)( const struct tag_sDataqueue_VDES *edp, intptr_t data );
    ER             (*receive__T)( const struct tag_sDataqueue_VDES *edp, intptr_t* p_data );
    ER             (*receivePolling__T)( const struct tag_sDataqueue_VDES *edp, intptr_t* p_data );
    ER             (*receiveTimeout__T)( const struct tag_sDataqueue_VDES *edp, intptr_t* p_data, TMO timeout );
    ER             (*initialize__T)( const struct tag_sDataqueue_VDES *edp );
    ER             (*refer__T)( const struct tag_sDataqueue_VDES *edp, T_RDTQ* pk_dataqueueStatus );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sDataqueue_Defined
#define  Descriptor_of_sDataqueue_Defined
typedef struct { struct tag_sDataqueue_VDES *vdes; } Descriptor( sDataqueue );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SDATAQUEUE_SEND                 (1)
#define	FUNCID_SDATAQUEUE_SENDPOLLING          (2)
#define	FUNCID_SDATAQUEUE_SENDTIMEOUT          (3)
#define	FUNCID_SDATAQUEUE_SENDFORCE            (4)
#define	FUNCID_SDATAQUEUE_RECEIVE              (5)
#define	FUNCID_SDATAQUEUE_RECEIVEPOLLING       (6)
#define	FUNCID_SDATAQUEUE_RECEIVETIMEOUT       (7)
#define	FUNCID_SDATAQUEUE_INITIALIZE           (8)
#define	FUNCID_SDATAQUEUE_REFER                (9)

#endif /* sDataqueue_TECSGEN_H */
