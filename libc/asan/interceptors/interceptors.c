#include "interceptors.h"

uintptr_t
GetCurrentPc(void)
{
	return GET_CALLER_PC();
}

void
__asan_report_error(uintptr_t pc, uintptr_t bp, uintptr_t sp,
	uintptr_t addr, bool is_write, size_t access_size)
{
	return;
}

/*
 * Touch each byte of memory, terminated with NUL byte. This
 * will be compiled with ASan which will handle checking each
 * byte.
 */
void
touch_mem(const char *p)
{
	volatile const char *vp = p;
	
	while(*vp++ != '\0')
		;
}
