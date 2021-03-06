#include "interceptors.h"
#include <sys/stdint.h>

int _ksem_unlink(const char *);
int _asan__ksem_unlink(const char *);

int
_ksem_unlink(const char *name)
{
	int ret = _asan__ksem_unlink(name);

	touch_mem(name);

	return ret;
}
