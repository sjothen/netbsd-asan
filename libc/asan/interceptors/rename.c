#include "../asan-interceptors.h"
#include <stdio.h>

int rename(const char *, const char *);
int _asan_rename(const char *, const char *);

int
rename(const char *from, const char *to)
{
	int ret = _asan_rename(from, to);

	if(ret == 0) {
		touch_mem(from);
		touch_mem(to);
	}

	return ret;
}
