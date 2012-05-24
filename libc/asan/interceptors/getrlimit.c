#include <sys/resource.h>

int getrlimit(int, struct rlimit *);
int _asan_getrlimit(int, struct rlimit *);

int
getrlimit(int resource, struct rlimit *rlp)
{
	int ret = _asan_getrlimit(resource, rlp);

	if(ret == 0)
		ASAN_WRITE_RANGE(rlp, sizeof(struct rlimit));

	return ret;
}
