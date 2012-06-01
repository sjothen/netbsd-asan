#include <sys/kern.h>

int _ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, semid_t *idp);
int _asan__ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, semid_t *idp);

int
_ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, semid_t *idp)
{
	int ret = _asan__ksem_open(name, oflag, mode, value, idp);

	if(ret == 0)
		ASAN_WRITE_RANGE(idp, sizeof(semid_t));

	return ret;
}
