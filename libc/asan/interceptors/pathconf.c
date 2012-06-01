#include "../asan-interceptors.h"
#include <unistd.h>

long pathconf(const char *, int);
long _asan_pathconf(const char *, int);

long
pathconf(const char *path, int name)
{
	long ret = _asan_pathconf(path, name);

	touch_mem(path);

	return ret;
}
