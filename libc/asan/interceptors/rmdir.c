#include <unistd.h>

int rmdir(const char *);
int _asan_rmdir(const char *);

int
rmdir(const char *path)
{
	int ret = _asan_rmdir(path);

	if(ret == 0) {
		int sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
