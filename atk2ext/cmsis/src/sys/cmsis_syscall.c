#include "atk2ext_user_config.h"
#include "atk2ext_common.h"

uint8_t appheap[APP_HEAP_SIZE] __attribute__((section(".appheap")));

extern char heap_end;
extern char heap_start;
static char *current_heap_end = &heap_start;
void* _sbrk(int incr)
{
	char *prev_heap_end;

	if ((current_heap_end + incr) > &heap_end) {
		return ((void*)-1);
	}

	prev_heap_end = current_heap_end;
	current_heap_end += incr;

	return (void*) prev_heap_end;
}

void __dtors(void)
{

}

void __dtors_end(void) {
}




int _close_r (void *unused, int fd)
{
	return -1;
}

int _lseek_r (void *unused, int fd, int offset, int whence)
{
	return -1;
}

int _open_r (void *unused, char *file_name, int flags, int mode)
{
	return -1;
}

int _read_r (void *unused, int fd, void *buf, int size)
{

	return -1;
}

int _write_r (void *unused, int fd, const void *buf, int size)
{
	return -1;
}
int _fstat_r(int fd, void *buf)
{
	return -1;
}
int _isatty_r(int fd)
{
	return -1;
}
uint32_t sys_now(void)
{
	//TODO
	return 0;
}
