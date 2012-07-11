#include "interceptors.h"
#include <ufs/ufs/quota.h>
#include <ufs/ufs/quota1.h>

int __quotactl(const char *, int, int, void *);
int _asan___quotactl(const char *, int, int, void *);

int
__quotactl(const char *path, int cmd, int id, void *addr)
{
	int ret = _asan___quotactl(path, cmd, id, addr);

	if(ret == 0) {
		touch_mem(path);
		if(cmd == Q_GETQUOTA)
			ASAN_WRITE_RANGE(addr, sizeof(struct dqblk));
	}

	return ret;
}
