#include "asan-interceptors.h"

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
