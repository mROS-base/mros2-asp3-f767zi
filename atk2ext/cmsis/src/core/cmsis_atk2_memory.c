#include "cmsis_atk2_memory.h"
#include <stdlib.h>

void *Atk2MemoryAlloc(uint32_t size)
{
	void *addrp = NULL;

	if (CurrentContextIsISR()) {
		return NULL;
	}
	SuspendOSInterrupts();
	addrp = malloc(size);
	ResumeOSInterrupts();

	return addrp;
}

void Atk2MemoryFree(void *addrp)
{
	if (CurrentContextIsISR()) {
		return;
	}
	if (addrp != NULL) {
		SuspendOSInterrupts();
		free(addrp);
		ResumeOSInterrupts();
	}
	return;
}
