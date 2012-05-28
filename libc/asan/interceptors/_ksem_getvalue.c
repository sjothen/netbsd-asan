#include <sys/ksem.h>

int _ksem_getvalue(semid_t, unsigned int *);
int _asan_ksem_getvalue(semid_t, unsigned int *);

int
_ksem_getvalue(semid_t id, unsigned int *value)
{
	int ret = _asan_ksem_getvalue(id, value);

	if(ret == 0)
		ASAN_WRITE_RANGE(value, sizeof(unsigned int));

	return ret;
}
