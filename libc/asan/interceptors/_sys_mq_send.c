#include <mqueue.h>

ssize_t _sys_mq_send(mqd_t, const char *, size_t,
	unsigned);
ssize_t _asan__sys_mq_send(mqd_t, const char *, size_t,
	unsigned);

ssize_t
_sys_mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
	unsigned msg_prio)
{
	ssize_t ret = _asan__sys_mq_send(mqdes, msg_ptr, msg_len,
			msg_prio);

	if(ret == 0) {
		ASAN_READ_RANGE(msg_ptr, msg_len);
	}

	return ret;
}
