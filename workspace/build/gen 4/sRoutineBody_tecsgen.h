/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sRoutineBody_TECSGEN_H
#define sRoutineBody_TECSGEN_H

/*
 * signature   :  sRoutineBody
 * global name :  sRoutineBody
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sRoutineBody_VDES {
    struct tag_sRoutineBody_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sRoutineBody_VMT {
    void           (*main__T)( const struct tag_sRoutineBody_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sRoutineBody_Defined
#define  Descriptor_of_sRoutineBody_Defined
typedef struct { struct tag_sRoutineBody_VDES *vdes; } Descriptor( sRoutineBody );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SROUTINEBODY_MAIN               (1)

#endif /* sRoutineBody_TECSGEN_H */
