#include "interceptors.h"
#include <sys/shm.h>

int __shmctl50(int, int, struct shmid_ds *);
int _asan___shmctl50(int, int, struct shmid_ds *);

int
__shmctl50(int shmid, int cmd, struct shmid_ds *buf)
{
	int ret = _asan___shmctl50(shmid, cmd, buf);

	if(ret == 0) {
		if(cmd == IPC_STAT)
			ASAN_WRITE_RANGE(buf, sizeof(struct shmid_ds));
	}

	return ret;
}
