#include <sys/msg.h>

ssize_t _sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
ssize_t _asan_sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

ssize_t
_sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
{
	ssize_t ret = _asan_sys_msgrcv(msqid, msgp, msgz, msgtyp, msgflg);

	return ret;
}
