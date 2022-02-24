/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef siCpuExceptionHandlerBody_TECSGEN_H
#define siCpuExceptionHandlerBody_TECSGEN_H

/*
 * signature   :  siCpuExceptionHandlerBody
 * global name :  siCpuExceptionHandlerBody
 * context     :  non-task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_siCpuExceptionHandlerBody_VDES {
    struct tag_siCpuExceptionHandlerBody_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_siCpuExceptionHandlerBody_VMT {
    void           (*main__T)( const struct tag_siCpuExceptionHandlerBody_VDES *edp, const void* p_excinf );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_siCpuExceptionHandlerBody_Defined
#define  Descriptor_of_siCpuExceptionHandlerBody_Defined
typedef struct { struct tag_siCpuExceptionHandlerBody_VDES *vdes; } Descriptor( siCpuExceptionHandlerBody );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SICPUEXCEPTIONHANDLERBODY_MAIN  (1)

#endif /* siCpuExceptionHandlerBody_TECSGEN_H */
