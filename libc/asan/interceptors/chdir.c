#include <unistd.h>
#include <string.h>

int chdir(const char *);
int _asan_chdir(const char *);

int
chdir(const char *path)
{
	int ret = _asan_chdir(path);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
