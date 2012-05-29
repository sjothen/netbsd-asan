#include <sys/msg.h>

int msgctl(int, int, struct msgid_ds *);
int _asan_msgctl(int, int, struct msgid_ds *);

int
msgctl(int msgid, int cmd, struct msgid_ds *buf)
{
	int ret = _asan_msgctl(msgid, cmd, buf);

	if(ret == 0) {
		if(cmd == IPC_STAT)
			ASAN_WRITE_RANGE(buf, sizeof(struct msgid_ds));
	}

	return ret;
}
