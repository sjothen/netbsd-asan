#include <sys/msg.h>

ssize_t _sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
ssize_t _asan__sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

ssize_t
_sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
{
	ssize_t ret = _asan__sys_msgrcv(msqid, msgp, msgz, msgtyp, msgflg);

	if(ret >= 0)
		ASAN_WRITE_RANGE(msgp, msgsz);

	return ret;
}
