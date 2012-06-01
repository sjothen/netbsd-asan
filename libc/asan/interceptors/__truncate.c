#include "../asan-interceptors.h"
#include <unistd.h>

int __truncate(const char *, int, off_t);
int _asan__truncate(const char *, int, off_t);

int
__truncate(const char *path, int pad, off_t length)
{
	int ret = _asan__truncate(path, pad, length);

	touch_mem(path);

	return ret;
}
