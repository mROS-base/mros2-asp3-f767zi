#ifndef _CMSIS_ATK2_ALARM_POOL_H_
#define _CMSIS_ATK2_ALARM_POOL_H_

#include "atk2ext_common.h"

extern StatusType Atk2AlarmPoolInit(void);
extern StatusType Atk2AlarmPoolAlloc(AlarmType *AlarmID);
extern StatusType Atk2AlarmPoolFree(AlarmType AlarmID);

#endif /* _CMSIS_ATK2_ALARM_POOL_H_ */
