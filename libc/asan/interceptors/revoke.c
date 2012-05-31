#include <unistd.h>
#include <string.h>

int revoke(const char *);
int _asan_revoke(const char *);

int
revoke(const char *path)
{
	int ret = _asan_revoke(path);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
