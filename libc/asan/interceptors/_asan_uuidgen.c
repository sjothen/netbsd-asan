#include "interceptors.h"
#include <sys/types.h>
#include <sys/uuid.h>

int uuidgen(struct uuid *, int);
int _asan_uuidgen(struct uuid *, int);

int
uuidgen(struct uuid *store, int count)
{
	int ret = _asan_uuidgen(store, count);

	if(ret == 0)
		ASAN_WRITE_RANGE(store, count*sizeof(struct uuid));

	return ret;
}
