#include "interceptors.h"
#include <sys/msg.h>

int __msgctl50(int, int, struct msqid_ds *);
int _asan___msgctl50(int, int, struct msqid_ds *);

int
__msgctl50(int msgid, int cmd, struct msqid_ds *buf)
{
	int ret = _asan___msgctl50(msgid, cmd, buf);

	if(ret == 0) {
		if(cmd == IPC_STAT)
			ASAN_WRITE_RANGE(buf, sizeof(struct msqid_ds));
	}

	return ret;
}
