#include <mqueue.h>
#include <time.h>

ssize_t _sys_mq_timedsend(mqd_t, const char *, size_t,
	unsigned, const struct timespec *);
ssize_t _asan__sys_mq_timedsend(mqd_t, const char *, size_t,
	unsigned, const struct timespec *);

ssize_t
_sys_mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
	unsigned msg_prio, const struct timespec *abs_timeout)
{
	ssize_t ret = _asan__sys_mq_timedsend(mqdes, msg_ptr, msg_len,
			msg_prio, abs_timeout);

	if(ret == 0) {
		ASAN_READ_RANGE(msg_ptr, msg_len);
		
		if(abs_timeout != NULL)
			ASAN_READ_RANGE(abs_timeout, sizeof(struct timespec));
	}

	return ret;
}
