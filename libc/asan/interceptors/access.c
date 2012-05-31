#include "../asan-interceptors.h"
#include <unistd.h>

int access(const char *, int);
int _asan_access(const char *, int);

int
access(const char *path, int flags)
{
	int ret = _asan_access(path, flags);

	touch_mem(path);

	return ret;
}
