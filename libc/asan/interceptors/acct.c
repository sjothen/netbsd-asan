#include <unistd.h>
#include <string.h>

int acct(const char *);
int _asan_acct(const char *);

int
acct(const char *path)
{
	int ret = _asan_acct(path);

	if(path != NULL) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
