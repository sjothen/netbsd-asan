#include "../asan-interceptors.h"
#include <unistd.h>

int chown(const char *, uid_t, gid_t);
int _asan_chown(const char *, uid_t, gid_t);

int
chown(const char *path, uid_t owner, gid_t group)
{
	int ret = _asan_chown(path, owner, group);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
