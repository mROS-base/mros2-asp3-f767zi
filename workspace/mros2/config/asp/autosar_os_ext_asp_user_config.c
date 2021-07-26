#include "autosar_os_ext_asp_user_config.h"

const AutosarOsExtFlagMapEntryType autosar_os_ext_flag_user_map[AUTSAR_OS_EXT_ASP_FLAG_USER_NUM] = {
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtTcpTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtEthIfLinkTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtEthInputTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtHBPubTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtHBSubTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtSPDPTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtWriterTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtReaderTask),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtMROS2Task),
		AUTSAR_OS_EXT_FLAG_MAP_ENTRY(MAIN_TASK),
};

AutosarOsExtFlagMapEntryType* cmsis_get_flag_user_map(void)
{
	return autosar_os_ext_flag_user_map;
}

int cmsis_get_flag_user_num(void)
{
	return AUTSAR_OS_EXT_ASP_FLAG_USER_NUM;
}
