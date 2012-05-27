#include <mqueue.h>

ssize_t _sys_mq_receive(mqd_t, char *, size_t,
	unsigned *);
ssize_t _asan_sys_mq_receive(mqd_t, char *, size_t,
	unsigned *);

ssize_t
_sys_mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
	unsigned *msg_prio)
{
	ssize_t ret = _asan_sys_mq_receive(mqdes, msg_ptr, msg_len,
			msg_prio);

	if(ret == 0) {
		ASAN_WRITE_RANGE(msg_ptr, msg_len);

		if(msg_prio != NULL)
			ASAN_WRITE_RANGE(msg_prio, sizeof(unsigned));
	}

	return ret;
}
