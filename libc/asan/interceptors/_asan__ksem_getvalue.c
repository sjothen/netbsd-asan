#include "interceptors.h"
#include <sys/stdint.h>

int _ksem_getvalue(intptr_t, unsigned int *);
int _asan__ksem_getvalue(intptr_t, unsigned int *);

int
_ksem_getvalue(intptr_t id, unsigned int *value)
{
	int ret = _asan__ksem_getvalue(id, value);

	if(ret == 0)
		ASAN_WRITE_RANGE(value, sizeof(unsigned int));

	return ret;
}
