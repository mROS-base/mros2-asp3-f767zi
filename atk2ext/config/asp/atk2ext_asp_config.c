#include "atk2ext_asp_config.h"
#include "atk2ext_asp_user_config.h"
#include "atk2ext_asp_sys_config.h"

ER Atk2ExtTask2EventFlag(ID taskID, ID *flgid)
{
	uint32_t i;
	for (i = 0; i < ATK2EXT_ASP_FLAG_USER_NUM; i++) {
		if (atk2ext_flag_user_map[i].taskID == taskID) {
			*flgid = atk2ext_flag_user_map[i].flgid;
			return E_OK;
		}
	}
	for (i = 0; i < ATK2EXT_ASP_FLAG_SYS_NUM; i++) {
		if (atk2ext_flag_sys_map[i].taskID == taskID) {
			*flgid = atk2ext_flag_sys_map[i].flgid;
			return E_OK;
		}
	}
	return E_OS_ID;
}
