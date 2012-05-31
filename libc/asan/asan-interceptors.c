#include "asan-interceptors.h"

/*
 * Touch each byte of memory, terminated with NUL byte. This
 * will be compiled with ASan which will handle checking each
 * byte.
 */
void
touch_mem(char *p)
{
	volatile char *vp = p;
	
	while(*p++ != '\0')
		;
}
