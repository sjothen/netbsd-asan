#include "../asan-interceptors.h"
#include <sys/ksem.h>
#define _LIBC
#include <sys/types.h>

int _ksem_unlink(const char *);
int _asan__ksem_unlink(const char *);

int
_ksem_unlink(const char *name)
{
	int ret = _asan__ksem_unlink(name);

	touch_mem(name);

	return ret;
}
