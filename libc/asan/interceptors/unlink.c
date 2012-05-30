#include <unistd.h>
#include <string.h>

int unlink(const char *);
int _asan_unlink(const char *);

int
unlink(const char *path)
{
	int ret = _asan_unlink(path);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
