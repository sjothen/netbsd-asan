#include <sys/stat.h>

int mkdir(const char *, mode_t);
int _asan_mkdir(const char *, mode_t);

int
mkdir(const char *path, mode_t mode)
{
	int ret = _asan_mkdir(path, mode);

	if(ret == 0) {
		int sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
