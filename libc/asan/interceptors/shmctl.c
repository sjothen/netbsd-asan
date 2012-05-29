#include <sys/shm.h>

int shmctl(int, int, struct shmid_ds *);
int _asan_shmctl(int, int, struct shmid_ds *);

int
shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
	int ret = _asan_shmctl(shmid, cmd, buf);

	if(ret == 0) {
		if(cmd == IPC_STAT)
			ASAN_WRITE_RANGE(buf, sizeof(struct shmid_ds));
	}

	return ret;
}
