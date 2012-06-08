#include "interceptors.h"
#include <unistd.h>

int setgroups(int, const gid_t *);
int _asan_setgroups(int, const gid_t *);

int
setgroups(int ngroups, const gid_t *gidset)
{
	int ret = _asan_setgroups(ngroups, gidset);

	if(ret == 0) {
		ASAN_READ_RANGE(gidset, ngroups*sizeof(gid_t));
	}

	return ret;
}
