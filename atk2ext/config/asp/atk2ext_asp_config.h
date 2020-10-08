#ifndef _ATK2EXT_CONFIG_H_
#define _ATK2EXT_CONFIG_H_

#include "atk2ext_common.h"

typedef struct {
	ID taskID;
	ID flgid;
} Atk2ExtFlagMapEntryType;

#define ATK2EXT_FLAG_MAP_ENTRY(taskname)	\
	{ .taskID = taskname, .flgid = taskname ## _FLG }

const Atk2ExtFlagMapEntryType atk2ext_flag_map[TNUM_FLGID];

extern ER Atk2ExtTask2EventFlag(ID taskID, ID *flgid);

#endif /* _ATK2EXT_CONFIG_H_ */
