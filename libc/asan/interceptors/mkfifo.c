#include <sys/stat.h>
#include <string.h>

int mkfifo(const char *, mode_t);
int _asan_mkfifo(const char *, mode_t);

int
mkfifo(const char *path, mode_t mode)
{
	int ret = _asan_mkfifo(path, mode);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
