#include "interceptors.h"
#include <mqueue.h>
#include <time.h>

ssize_t _sys_mq_timedreceive(mqd_t mqdes, char *__restrict msg_ptr, size_t msg_len,
	unsigned *__restrict msg_prio,
	const struct timespec *__restrict abs_timeout);
ssize_t _asan__sys_mq_timedreceive(mqd_t mqdes, char *__restrict msg_ptr, size_t msg_len,
	unsigned *__restrict msg_prio,
	const struct timespec *__restrict abs_timeout);

ssize_t
_sys_mq_timedreceive(mqd_t mqdes, char *__restrict msg_ptr, size_t msg_len,
	unsigned *__restrict msg_prio,
	const struct timespec *__restrict abs_timeout)
{
	ssize_t ret = _asan__sys_mq_timedreceive(mqdes, msg_ptr, msg_len,
			msg_prio, abs_timeout);

	if(ret == 0) {
		ASAN_WRITE_RANGE(msg_ptr, msg_len);
		
		if(msg_prio != NULL)
			ASAN_WRITE_RANGE(msg_prio, sizeof(unsigned));
	}

	return ret;
}
