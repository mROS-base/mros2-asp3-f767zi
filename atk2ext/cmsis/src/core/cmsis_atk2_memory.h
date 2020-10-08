#ifndef _CMSIS_ATK2_MEMORY_H_
#define _CMSIS_ATK2_MEMORY_H_

#include "atk2ext_common.h"

extern void *Atk2MemoryAlloc(uint32_t size);
extern void Atk2MemoryFree(void *addrp);

#endif /* _CMSIS_ATK2_MEMORY_H_ */
