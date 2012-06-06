#include "interceptors.h"
#include <unistd.h>

int chroot(const char *);
int _asan_chroot(const char *);

int
chroot(const char *path)
{
	int ret = _asan_chroot(path);

	touch_mem(path);

	return ret;
}
