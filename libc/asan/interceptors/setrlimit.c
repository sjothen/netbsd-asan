#include "../asan-interceptors.h"
#include <sys/resource.h>

int setrlimit(int, const struct rlimit *);
int _asan_setrlimit(int, const struct rlimit *);

int
setrlimit(int resource, const struct rlimit *rlp)
{
	int ret = _asan_setrlimit(resource, rlp);

	if(ret == 0)
		ASAN_READ_RANGE(rlp, sizeof(struct rlimit));

	return ret;
}
