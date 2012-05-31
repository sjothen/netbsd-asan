#include "../asan-interceptors.h"
#include <unistd.h>

int chdir(const char *);
int _asan_chdir(const char *);

int
chdir(const char *path)
{
	int ret = _asan_chdir(path);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
