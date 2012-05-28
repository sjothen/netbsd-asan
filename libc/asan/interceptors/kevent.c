#include <sys/event.h>
#include <sys/time.h>

int kevent(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout);
int _asan_kevent(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout);

int kevent(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout)
{
	int ret = _asan_kevent(kq, changelist, nchanges, eventlist,
			nevents, timeout);

	if(ret != -1)
		ASAN_WRITE_RANGE(eventlist, ret*sizeof(struct kevent));

	return ret;
}
