#include <unistd.h>
#include <string.h>

int chroot(const char *);
int _asan_chroot(const char *);

int
chroot(const char *path)
{
	int ret = _asan_chroot(path);

	int sz = strlen(path);
	ASAN_READ_RANGE(path, sz+1);

	return ret;
}
