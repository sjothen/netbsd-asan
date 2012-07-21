#include "interceptors.h"
#include <unistd.h>

int undelete(const char *);
int _asan_undelete(const char *);

int
undelete(const char *path)
{
	int ret = _asan_undelete(path);

	touch_mem(path);

	return ret;
}
