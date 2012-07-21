#include "interceptors.h"
#include <unistd.h>

int revoke(const char *);
int _asan_revoke(const char *);

int
revoke(const char *path)
{
	int ret = _asan_revoke(path);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
