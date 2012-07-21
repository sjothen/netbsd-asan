#include "interceptors.h"
#include <unistd.h>

int link(const char *, const char *);
int _asan_link(const char *, const char *);

int
link(const char *path, const char *link)
{
	int ret = _asan_link(path, link);

	if(ret == 0) {
		touch_mem(path);
		touch_mem(link);
	}

	return ret;
}
