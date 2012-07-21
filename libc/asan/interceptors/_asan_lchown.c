#include "interceptors.h"
#include <unistd.h>

int lchown(const char *, uid_t, gid_t);
int _asan_lchown(const char *, uid_t, gid_t);

int
lchown(const char *path, uid_t owner, gid_t group)
{
	int ret = _asan_lchown(path, owner, group);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
