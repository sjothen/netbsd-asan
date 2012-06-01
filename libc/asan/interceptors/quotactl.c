#include "../asan-interceptors.h"
#include <ufs/ufs/quota.h>

int quotactl(const char *, int, int, void *);
int _asan_quotactl(const char *, int, int, void *);

int
quotactl(const char *path, int cmd, int id, void *addr)
{
	int ret = _asan_quotactl(path, cmd, id, addr);

	if(ret == 0) {
		touch_mem(path);
		if(cmd == Q_GETQUOTA)
			ASAN_WRITE_RANGE(addr, sizeof(struct dqblk));
	}

	return ret;
}
