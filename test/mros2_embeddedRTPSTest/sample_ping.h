#ifndef _AUTSAR_OS_EXT_TEST_H_
#define _AUTSAR_OS_EXT_TEST_H_

#include "autosar_os_ext_task.h"

extern void	TASKNAME(AutosarOsExtTcpTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtEthIfLinkTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtEthInputTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtHBPubTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtHBSubTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtSPDPTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtWriterTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtReaderTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtUserDefaultTask) (intptr_t exinf);
extern void	TASKNAME(AutosarOsExtMROS2Task) (intptr_t exinf);

#endif /* _AUTSAR_OS_EXT_TEST_H_ */
