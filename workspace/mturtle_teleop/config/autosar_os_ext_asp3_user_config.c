#include "autosar_os_ext_asp3_user_config.h"

const AutosarOsExtFlagMapEntryType autosar_os_ext_flag_user_map[AUTOSAR_OS_EXT_ASP3_FLAG_USER_NUM] = {
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtTcpTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtEthIfLinkTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtEthInputTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtHBPubTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtHBSubTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtSPDPTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtWriterTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtReaderTask),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(AutosarOsExtMROS2Task),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(MAIN_TASK),
  AUTOSAR_OS_EXT_FLAG_MAP_ENTRY(TELEOP_TASK),
};

const AutosarOsExtFlagMapEntryType* cmsis_get_flag_user_map(void)
{
  return autosar_os_ext_flag_user_map;
}

int cmsis_get_flag_user_num(void)
{
  return AUTOSAR_OS_EXT_ASP3_FLAG_USER_NUM;
}
