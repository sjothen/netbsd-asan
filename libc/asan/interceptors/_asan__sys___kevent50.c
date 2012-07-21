#include "interceptors.h"
#include <sys/event.h>
#include <sys/time.h>

int _sys___kevent50(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout);
int _asan__sys___kevent50(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout);

int _sys___kevent50(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout)
{
	int ret = _asan__sys___kevent50(kq, changelist, nchanges, eventlist,
			nevents, timeout);

	if(ret != -1) {
		ASAN_READ_RANGE(changelist, nchanges*sizeof(struct kevent));
		ASAN_WRITE_RANGE(eventlist, ret*sizeof(struct kevent));
	}

	return ret;
}
