/* This file is generated from target_rename.def by genrename. */

#ifndef TOPPERS_CHIP_RENAME_H
#define TOPPERS_CHIP_RENAME_H


/*
 * chip_config.c
 */
#define target_initialize			_kernel_target_initialize
#define target_exit					_kernel_target_exit

#ifdef TOPPERS_LABEL_ASM


/*
 * chip_config.c
 */
#define _target_initialize			__kernel_target_initialize
#define _target_exit				__kernel_target_exit

#endif /* TOPPERS_LABEL_ASM */

#include "arm_m_gcc/common/core_rename.h"

#endif /* TOPPERS_CHIP_RENAME_H */
