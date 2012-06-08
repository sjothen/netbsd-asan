#include "interceptors.h"
#include <sys/socket.h>

int setsockopt(int, int, int, const void *,
		unsigned int);
int _asan_setsockopt(int, int, int, const void *,
		unsigned int);

int
setsockopt(int s, int level, int name, const void *val,
		unsigned int valsize)
{
	int ret = _asan_setsockopt(s, level, name, val, valsize);

	if(ret == 0)
		ASAN_READ_RANGE(val, valsize);

	return ret;
}
