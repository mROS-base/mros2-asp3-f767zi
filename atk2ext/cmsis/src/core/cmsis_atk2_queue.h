#ifndef _CMSIS_ATK2_QUEUE_H_
#define _CMSIS_ATK2_QUEUE_H_

#include "atk2ext_common.h"

typedef struct {
	uint16_t	count;
	QUEUE		*entries;
} Atk2QueueHeadType;

#define Atk2QueueHeadInitializer(var)	\
		Atk2QueueHeadType var = { .count = 0, .entries = NULL }
#define Atk2QueueHeadInit(qheadp)	\
do {	\
	(qheadp)->count = 0;	\
	(qheadp)->entries = NULL;	\
} while (0)

extern void Atk2QueueHeadAddTail(Atk2QueueHeadType *headp, QUEUE *entry);
extern QUEUE* Atk2QueueHeadRemoveFirst(Atk2QueueHeadType *headp);
extern void Atk2QueueHeadRemoveEntry(Atk2QueueHeadType *headp, QUEUE *entry);
extern void Atk2QueueHeadConditionalRemove(Atk2QueueHeadType *srcq, Atk2QueueHeadType *dstq, bool_t (*cond_func) (QUEUE *entry, void *arg), void *arg);
extern void Atk2QueueHeadDoAction(Atk2QueueHeadType *headp, void (*act_func) (QUEUE *entry, void *arg), void *arg);

#endif /* _CMSIS_ATK2_QUEUE_H_ */
