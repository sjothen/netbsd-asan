#include <sys/sa.h>

int sa_register(sa_upcall_t, sa_upcall_t *, int,
		ssize_t);
int _asan_sa_register(sa_upcall_t, sa_upcall_t *, int,
		ssize_t);

int
sa_register(sa_upcall_t new, sa_upcall_t *old, int flags,
		ssize_t stackinfo_offset)
{
	int ret = _asan_sa_register(new, old, flags,
			stackinfo_offset);

	if(ret == 0)
		ASAN_WRITE_RANGE(old, sizeof(sa_upcall_t));

	return ret;
}
