#include "../asan-interceptors.h"
#include <unistd.h>

int symlink(const char *, const char *);
int _asan_symlink(const char *, const char *);

int
symlink(const char *path, const char *link)
{
	int ret = _asan_symlink(path, link);

	if(ret == 0) {
		touch_mem(path);
		touch_mem(link);
	}

	return ret;
}
