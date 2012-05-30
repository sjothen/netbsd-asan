#include <unistd.h>
#include <string.h>

int chown(const char *, uid_t, gid_t);
int _asan_chown(const char *, uid_t, gid_t);

int
chown(const char *path, uid_t owner, gid_t group)
{
	int ret = _asan_chown(path, owner, group);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
