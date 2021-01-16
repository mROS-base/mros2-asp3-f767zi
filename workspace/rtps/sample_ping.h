#ifndef _ATK2EXT_TEST_H_
#define _ATK2EXT_TEST_H_

#include "atk2ext_task.h"

extern void	TASKNAME(Atk2ExtTcpTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtEthIfLinkTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtEthInputTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtHBPubTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtHBSubTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtSPDPTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtWriterTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtReaderTask) (intptr_t exinf);
extern void	TASKNAME(Atk2ExtUserDefaultTask) (intptr_t exinf);

/* 
 * priorities of mROS 2 tasks for RTPS
 *
 * TODO: We assigned relatevely lower priorities for EthIfLinkTask and
 * EthInputTask than the application. Check whether these are appropriate.
 */
#define MROS2_HIGH_PRIORITY MAIN_PRIORITY
#define MROS2_LOW_PRIORITY  LOW_PRIORITY+1

#endif /* _ATK2EXT_TEST_H_ */
