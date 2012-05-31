#include "../asan-interceptors.h"
#include <unistd.h>

int __setlogin(const char *);
int _asan__setlogin(const char *);

int
__setlogin(const char *namebuf)
{
	int ret = _asan__setlogin(namebuf);

	touch_mem(namebuf);

	return ret;
}
