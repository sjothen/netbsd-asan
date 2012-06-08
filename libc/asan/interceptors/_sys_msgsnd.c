#include "interceptors.h"
#include <sys/msg.h>

ssize_t _sys_msgsnd(int, const void *, size_t, int);
ssize_t _asan__sys_msgsnd(int, const void *, size_t, int);

ssize_t
_sys_msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
	ssize_t ret = _asan__sys_msgsnd(msqid, msgp, msgsz, msgflg);

	if(ret == 0)
		ASAN_READ_RANGE(msgp, msgsz);

	return ret;
}
