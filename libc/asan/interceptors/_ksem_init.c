#include <sys/ksem.h>

int _ksem_init(unsigned int, semid_t *);
int _asan_ksem_init(unsigned int, semid_t *);

int
_ksem_init(unsigned int value, semid_t *idp)
{
	int ret = _asan_ksem_init(value, idp);

	if(ret == 0)
		ASAN_WRITE_RANGE(idp, sizeof(semid_t));

	return ret;
}
