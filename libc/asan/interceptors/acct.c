#include "../asan-interceptors.h"
#include <unistd.h>

int acct(const char *);
int _asan_acct(const char *);

int
acct(const char *path)
{
	int ret = _asan_acct(path);

	if(path != NULL) {
		touch_mem(path);
	}

	return ret;
}
