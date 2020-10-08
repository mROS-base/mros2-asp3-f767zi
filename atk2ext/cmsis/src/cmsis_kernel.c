#include "cmsis_atk2_time.h"
#include "cmsis_os.h"

uint32_t osKernelGetTickCount(void)
{
	return Atk2TimeGetTickCount();
}
