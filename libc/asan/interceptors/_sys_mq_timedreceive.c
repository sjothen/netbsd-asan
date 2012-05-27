#include <mqueue.h>
#include <time.h>

ssize_t _sys_mq_timedreceive(mqd_t mqdes, char *restrict msg_ptr, size_t msg_len,
	unsigned *restrict msg_prio,
	const struct timespec *restrict abs_timeout);
ssize_t _asan_sys_mq_timedreceive(mqd_t mqdes, char *restrict msg_ptr, size_t msg_len,
	unsigned *restrict msg_prio,
	const struct timespec *restrict abs_timeout);

ssize_t
_sys_mq_timedreceive(mqd_t mqdes, char *restrict msg_ptr, size_t msg_len,
	unsigned *restrict msg_prio,
	const struct timespec *restrict abs_timeout)
{
	ssize_t ret = _asan_sys_mq_timedreceive(mqdes, msg_ptr, msg_len,
			msg_prio, abs_timeout);

	if(ret == 0) {
		ASAN_WRITE_RANGE(msg_ptr, msg_len);
		
		if(msg_prio != NULL)
			ASAN_WRITE_RANGE(msg_prio, sizeof(unsigned));
	}

	return ret;
}
