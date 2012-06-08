#include "interceptors.h"
#include <unistd.h>

int getgroups(int, gid_t *);
int _asan_getgroups(int, gid_t *);

int
getgroups(int gidsetlen, gid_t *gidset)
{
	int ret = _asan_getgroups(gidsetlen, gidset);
	
	if(ret >= 0)
		ASAN_WRITE_RANGE(gidset, gidsetlen);

	return ret;
}
