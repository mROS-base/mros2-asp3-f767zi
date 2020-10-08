#include "cmsis_atk2_time.h"

static uint32_t cmsis_atk2_current_time;

uint32_t Atk2TimeGetTickCount(void)
{
	return cmsis_atk2_current_time;
}
void Atk2TimeIncTickCount(void)
{
	cmsis_atk2_current_time++;
	return;
}

uint32_t Atk2TimeGetExpireTickCount(uint32_t stick, uint32_t timeout)
{
	uint32_t expiretick = stick + timeout;
	if (expiretick >= stick) {
		return expiretick;
	}

	/*
	 *  curr = UINT32_MAX
	 *  tmo  = 1
	 *  exp  = 0: (tmo=1) - (UINT32_MAX - (curr=(UINT32_MAX)) -1 = 0
	 */
	return (timeout - (UINT32_MAX - stick) - 1);
}

bool_t Atk2TimeIsTimeout(uint32_t curr, uint32_t s, uint32_t e)
{
	if (s <= e) {
		/*                                    |<- tmout ->|
		 *       |----------------------------s***********e--------------|
		 * Curr  :  +(case2.2)                   +(case1)      +(case2.1)
		 */
		if ((curr >= s) && (curr < e)) {
			// case1
			return false;
		}
		else {
			// case2.1 or case2.2
			return true;
		}
	}
	else {
		/*        ----------->|                           |<- tmout -----
		 *       |************e---------------------------s**************|
		 * Curr  : +(case1.2)      +(case2)                   +(case1.1)
		 */
		if ((curr >= e) && (curr < s)) {
			// case2
			return true;
		}
		else {
			// case1.1 or case1.2
			return false;
		}
	}
}
