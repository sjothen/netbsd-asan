#include "../asan-interceptors.h"
#include <sys/ksem.h>

int _ksem_unlink(const char *);
int _asan_ksem_unlink(const char *);

int
_ksem_unlink(const char *name)
{
	int ret = _asan_ksem_unlink(name);

	touch_mem(name);

	return ret;
}
