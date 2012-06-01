#include "../asan-interceptors.h"
#include <unistd.h>

int __truncate(const char *, int, off_t);
int _asan___truncate(const char *, int, off_t);

int
__truncate(const char *path, int pad, off_t length)
{
	int ret = _asan___truncate(path, pad, length);

	touch_mem(path);

	return ret;
}
