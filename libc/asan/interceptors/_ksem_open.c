#include "interceptors.h"
#include <sys/ksem.h>
#include <sys/stdint.h>

int _ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, intptr_t idp);
int _asan__ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, intptr_t idp);

int
_ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, intptr_t idp)
{
	int ret = _asan__ksem_open(name, oflag, mode, value, idp);

	if(ret == 0)
		ASAN_WRITE_RANGE(idp, sizeof(intptr_t));

	return ret;
}
