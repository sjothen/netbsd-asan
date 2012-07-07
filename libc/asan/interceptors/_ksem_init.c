#include "interceptors.h"
#include <sys/ksem.h>
#include <sys/stdint.h>

int _ksem_init(unsigned int, intptr_t);
int _asan__ksem_init(unsigned int, intptr_t);

int
_ksem_init(unsigned int value, intptr_t idp)
{
	int ret = _asan__ksem_init(value, idp);

	if(ret == 0)
		ASAN_WRITE_RANGE(idp, sizeof(intptr_t));

	return ret;
}
