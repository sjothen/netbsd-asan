#include "../asan-interceptors.h"
#include <unistd.h>

int __posix_chown(const char *, uid_t, gid_t);
int _asan___posix_chown(const char *, uid_t, gid_t);

int
__posix_chown(const char *path, uid_t owner, gid_t group)
{
	int ret = _asan___posix_chown(path, owner, group);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
