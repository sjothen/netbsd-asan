#include "interceptors.h"
#include <unistd.h>

int lchflags(const char *, unsigned long);
int _asan_lchflags(const char *, unsigned long);

int
lchflags(const char *path, unsigned long flags)
{
	int ret = _asan_lchflags(path, flags);

	touch_mem(path);

	return ret;
}
