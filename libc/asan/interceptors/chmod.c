#include <sys/stat.h>
#include <string.h>

int chmod(const char *, mode_t);
int _asan_chmod(const char *, mode_t);

int
chmod(const char *path, mode_t mode)
{
	int ret = _asan_chmod(path, mode);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
