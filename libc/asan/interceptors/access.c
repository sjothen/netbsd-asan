#include <unistd.h>
#include <string.h>

int access(const char *, int);
int _asan_access(const char *, int);

int
access(const char *path, int flags)
{
	int ret = _asan_access(path, flags);

	size_t sz = strlen(path);
	ASAN_READ_RANGE(path, sz+1);

	return ret;
}
