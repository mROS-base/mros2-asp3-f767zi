#ifndef _CMSIS_ATK2_TIME_H_
#define _CMSIS_ATK2_TIME_H_

#include "atk2ext_common.h"

extern uint32_t Atk2TimeGetTickCount(void);
extern void Atk2TimeIncTickCount(void);
extern uint32_t Atk2TimeGetExpireTickCount(uint32_t stick, uint32_t timeout);
extern bool_t Atk2TimeIsTimeout(uint32_t curr, uint32_t s, uint32_t e);


//TODO test func
extern void Atk2TimeIncTickCountSet(uint32_t set_time);

#endif /* _CMSIS_ATK2_TIME_H_ */
