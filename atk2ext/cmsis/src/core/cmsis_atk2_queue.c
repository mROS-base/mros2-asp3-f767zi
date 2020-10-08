#include "cmsis_atk2_queue.h"
#include "cmsis_atk2_memory.h"

void Atk2QueueHeadAddTail(Atk2QueueHeadType *headp, QUEUE *entry)
{
	queue_initialize(entry);
	if (headp->entries == NULL) {
		headp->entries = entry;
	}
	else {
		//add last
		queue_insert_prev(headp->entries, entry);
	}
	headp->count++;
	return;
}
void Atk2QueueHeadRemoveEntry(Atk2QueueHeadType *headp, QUEUE *entry)
{
	if (headp->entries != NULL) {
		QUEUE *next = entry->p_next;
		queue_delete(entry);
		headp->count--;
		if (headp->count == 0) {
			headp->entries = NULL;
		}
		else if (headp->entries == entry) {
			headp->entries = next;
		}
	}
	return;
}
QUEUE* Atk2QueueHeadRemoveFirst(Atk2QueueHeadType *headp)
{
	QUEUE *first = headp->entries;
	if (first != NULL) {
		Atk2QueueHeadRemoveEntry(headp, first);
	}
	return first;
}
void Atk2QueueHeadConditionalRemove(Atk2QueueHeadType *srcq, Atk2QueueHeadType *dstq, bool_t (*cond_func) (QUEUE *entry, void *arg), void *arg)
{
	uint32_t i;
	uint32_t count = srcq->count;
	QUEUE *entry = srcq->entries;
	QUEUE *next;

	for (i = 0; i < count; i++) {
		next = entry->p_next;
		if (cond_func(entry, arg)) {
			Atk2QueueHeadRemoveEntry(srcq, entry);
			Atk2QueueHeadAddTail(dstq, entry);
		}
		entry = next;
	}
	return;
}
void Atk2QueueHeadDoAction(Atk2QueueHeadType *headp, void (*act_func) (QUEUE *entry, void *arg), void *arg)
{
	uint32_t i;
	uint32_t count = headp->count;
	QUEUE *entry = headp->entries;
	QUEUE *next;
	for (i = 0; i < count; i++) {
		next = entry->p_next;
		act_func(entry, arg);
		entry = next;
	}
}

