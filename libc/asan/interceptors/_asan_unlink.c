#include "interceptors.h"
#include <unistd.h>

int unlink(const char *);
int _asan_unlink(const char *);

int
unlink(const char *path)
{
	int ret = _asan_unlink(path);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
