#include <sys/stat.h>

int __stat30(const char *, struct stat *);
int _asan__stat30(const char *, struct stat *);

int
__stat30(const char *path, struct stat *ub)
{
	int ret = _asan__stat30(path, ub);

	if(ret == 0)
		ASAN_WRITE_RANGE(ub, sizeof(struct stat));

	return ret;
}
