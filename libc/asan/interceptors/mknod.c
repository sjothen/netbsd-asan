#include <sys/stat.h>
#include <string.h>

int mknod(const char *, mode_t, dev_t);
int _asan_mknod(const char *, mode_t, dev_t);

int
mknod(const char *path, mode_t mode, dev_t dev)
{
	int ret = _asan_mknod(path, mode, dev);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
