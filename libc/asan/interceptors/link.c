#include <unistd.h>
#include <string.h>

int link(const char *, const char *);
int _asan_link(const char *, const char *);

int
link(const char *path, const char *link)
{
	int ret = _asan_link(path, link);

	if(ret == 0) {
		size_t szpath = strlen(path);
		size_t szlink = strlen(link);

		ASAN_READ_RANGE(path, szpath+1);
		ASAN_READ_RANGE(link, szlink+1);
	}

	return ret;
}
