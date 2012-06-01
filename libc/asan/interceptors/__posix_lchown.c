#include "../asan-interceptors.h"
#include <unistd.h>

int __posix_lchown(const char *, uid_t, gid_t);
int _asan___posix_lchown(const char *, uid_t, gid_t);

int
__posix_lchown(const char *path, uid_t owner, gid_t group)
{
	int ret = _asan___posix_lchown(path, owner, group);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
