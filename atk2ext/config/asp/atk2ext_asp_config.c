#include "atk2ext_asp_config.h"

const Atk2ExtFlagMapEntryType atk2ext_flag_map[TNUM_FLGID] = {
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtCyclicTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtTestTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtTest2Task),
};

ER Atk2ExtTask2EventFlag(ID taskID, ID *flgid)
{
	uint32_t i;
	for (i = 0; i < TNUM_FLGID; i++) {
		if (atk2ext_flag_map[i].taskID == taskID) {
			*flgid = atk2ext_flag_map[i].flgid;
			return E_OK;
		}
	}
	return E_OS_ID;
}
