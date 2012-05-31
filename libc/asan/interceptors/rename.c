#include <stdio.h>
#include <string.h>

int rename(const char *, const char *);
int _asan_rename(const char *, const char *);

int
rename(const char *from, const char *to)
{
	int ret = _asan_rename(from, to);

	if(ret == 0) {
		size_t szfrom = strlen(from);
		size_t szto = strlen(to);

		ASAN_READ_RANGE(from, szfrom+1);
		ASAN_READ_RANGE(to, szto+1);
	}

	return ret;
}
