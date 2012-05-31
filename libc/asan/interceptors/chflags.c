#include "../asan-interceptors.h"
#include <unistd.h>

int chflags(const char *, unsigned long);
int _asan_chflags(const char *, unsigned long);

int
chflags(const char *path, unsigned long flags)
{
	int ret = _asan_chflags(path, flags);

	touch_mem(path);

	return ret;
}
