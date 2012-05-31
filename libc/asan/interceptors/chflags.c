#include <unistd.h>
#include <string.h>

int chflags(const char *, unsigned long);
int _asan_chflags(const char *, unsigned long);

int
chflags(const char *path, unsigned long flags)
{
	int ret = _asan_chflags(path, flags);

	size_t sz = strlen(path);
	ASAN_READ_RANGE(path, sz+1);

	return ret;
}
