#include "interceptors.h"
#include <sys/msg.h>

ssize_t _sys_msgrcv(int, void *, size_t, long, int);
ssize_t _asan__sys_msgrcv(int, void *, size_t, long, int);

ssize_t
_sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
{
	ssize_t ret = _asan__sys_msgrcv(msqid, msgp, msgsz, msgtyp, msgflg);

	if(ret >= 0)
		ASAN_WRITE_RANGE(msgp, msgsz);

	return ret;
}
