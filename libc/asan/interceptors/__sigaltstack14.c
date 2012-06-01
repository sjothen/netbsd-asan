#include <unistd.h>
#include <signal.h>

int __sigaltstack14(const struct sigaltstack *,
		struct sigaltstack *);
int _asan___sigaltstack14(const struct sigaltstack *,
		struct sigaltstack *);

int
__sigaltstack14(const struct sigaltstack *nss,
		struct sigaltstack *oss)
{
	int ret = _asan___sigaltstack14(nss, oss);

	if(ret == 0) {
		if(oss != NULL)
			ASAN_WRITE_RANGE(oss, sizeof(struct sigaltstack));
	}

	return ret;
}
