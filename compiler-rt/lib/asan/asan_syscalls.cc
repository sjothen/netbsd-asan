#include <unistd.h>

#define RENAME(name, ...) { \
	return name(__VA_ARGS__); \
}

#define _NETBSD_SOURCE

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>

int __adjtime(const struct timeval *delta, struct timeval *olddelta)
	RENAME(_asan___adjtime, delta, olddelta);

int __fhopen40(const void *fhp, size_t fh_size, int flags)
	RENAME(_asan___fhopen40, fhp, fh_size, flags);

int __fhstat40(const void *fhp, size_t fh_size, struct stat *sb)
	RENAME(_asan___fhstat40, fhp, fh_size, sb);

int __fhstatvfs140(const void *fhp, size_t fh_size,
		struct statvfs *buf, int flags)
	RENAME(_asan___fhstatvfs140, fhp, fh_size, buf, flags);

int __fstat30(int fd, struct stat *sb)
	RENAME(_asan___fstat30, fd, sb);

int __getcwd(char *bufp, size_t length)
	RENAME(_asan___getcwd, bufp, length);

#include <dirent.h>

int __getdents30(int fd, char *buf, size_t count)
	RENAME(_asan___getdents30, fd, buf, count);

#include <sys/mount.h>

int __getfh30(const char *fname, void *fhp, size_t *fh_size)
	RENAME(_asan___getfh30, fname, fhp, fh_size);

int __getlogin(char *namebuf, size_t namelen)
	RENAME(_asan___getlogin, namebuf, namelen);

int __lstat30(const char *path, struct stat *sb)
	RENAME(_asan___lstat30, path, sb);

#include <sys/param.h>

int __mount50(const char *type, const char *path, int flags,
		void *data, size_t data_len)
	RENAME(_asan___mount50, type, path, flags, data, data_len);

#include <sys/timex.h>

int __ntp_adjtime(struct timex *tp)
	RENAME(_asan___ntp_adjtime, tp);

int __ntp_gettime30(struct ntptimeval *ntvp)
	RENAME(_asan___ntp_gettime30, ntvp);

int __posix_chown(const char *path, uid_t owner, gid_t group)
	RENAME(_asan___posix_chown, path, owner, group);

int __posix_lchown(const char *path, uid_t owner, gid_t group)
	RENAME(_asan___posix_lchown, path, owner, group);

#include <sys/uio.h>

ssize_t __preadv(int d, const struct iovec *iov, int iovcnt, off_t offset)
	RENAME(_asan___preadv, d, iov, iovcnt, offset);

ssize_t __pwritev(int d, const struct iovec *iov, int iovcnt, off_t offset)
	RENAME(_asan___pwritev, d, iov, iovcnt, offset);

int __setlogin(const char *namebuf)
	RENAME(_asan___setlogin, namebuf);

#include <sys/signal.h>

int __sigaction_sigtramp(int signum, const struct sigaction *nsa,
		struct sigaction *osa, const void *tramp, int vers)
	RENAME(_asan___sigaction_sigtramp, signum, nsa, osa, tramp, vers);

#include <signal.h>

int __sigaltstack14(const struct sigaltstack *nss,
		struct sigaltstack *oss)
	RENAME(_asan___sigaltstack14, nss, oss);

int __sigpending14(sigset_t *set)
	RENAME(_asan___sigpending14, set);

#include <time.h>

int __sigtimedwait(const sigset_t *set, siginfo_t *info,
		struct timespec *timeout)
	RENAME(_asan___sigtimedwait, set, info, timeout);

int __stat30(const char *path, struct stat *ub)
	RENAME(_asan___stat30, path, ub);

#include <sys/sysctl.h>
#include <errno.h>

int __sysctl(const int *name, u_int namelen, void *old,
		size_t *oldlenp, const void *newp, size_t newlen)
	RENAME(_asan___sysctl, name, namelen, old, oldlenp, newp, newlen);

int __truncate(const char *path, int pad, off_t length)
	RENAME(_asan___truncate, path, pad, length);

#include <sys/ucontext.h>

int _getcontext(struct __ucontext *ucp)
	RENAME(_asan__getcontext, ucp);

#include <sys/ksem.h>
#define _LIBC
#include <sys/types.h>

int _ksem_getvalue(semid_t id, unsigned int *value)
	RENAME(_asan__ksem_getvalue, id, value);

int _ksem_init(unsigned int value, semid_t *idp)
	RENAME(_asan__ksem_init, value, idp);

int _ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, semid_t *idp)
	RENAME(_asan__ksem_open, name, oflag, mode, value, idp);

int _ksem_unlink(const char *name)
	RENAME(_asan__ksem_unlink, name);

#include <lwp.h>

int _lwp_create(const ucontext_t *context, unsigned long flags, lwpid_t *new_lwp)
	RENAME(_asan__lwp_create, context, flags, new_lwp);

int _lwp_ctl(int features, struct lwpctl **address)
	RENAME(_asan__lwp_ctl, features, address);

int _lwp_getname(lwpid_t target, char *name, size_t len)
	RENAME(_asan__lwp_getname, target, name, len);

int _lwp_park(const struct timespec *ts, lwpid_t unpark,
		const void *hint, const void *unparkhint)
	RENAME(_asan__lwp_park, ts, unpark, hint, unparkhint);

int _lwp_setname(lwpid_t target, const char *name)
	RENAME(_asan__lwp_setname, target, name);

ssize_t _lwp_unpark_all(const lwpid_t *targets, size_t ntargets,
		const void *hint)
	RENAME(_asan__lwp_unpark_all, targets, ntargets, hint);

int _lwp_wait(lwpid_t wlwp, lwpid_t *rlwp)
	RENAME(_asan__lwp_wait, wlwp, rlwp);

int _setcontext(struct __ucontext *ucp)
	RENAME(_asan__setcontext, ucp);

int _sys___sigprocmask14(int how, const sigset_t *set,
		sigset_t *oset)
	RENAME(_asan__sys___sigprocmask14, how, set, oset);

int _sys___sigsuspend14(const sigset_t *sigmask)
	RENAME(_asan__sys___sigsuspend14, sigmask);

#include <sys/sched.h>

int _sys__sched_getaffinity(pid_t pid, lwpid_t lid,
		size_t size, cpuset_t *cpuset)
	RENAME(_asan__sys__sched_getaffinity, pid, lid, size, cpuset);

int _sys__sched_getparam(pid_t pid, lwpid_t lid, int *policy,
		struct sched_param *params)
	RENAME(_asan__sys__sched_getparam, pid, lid, policy, params);

int _sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset)
	RENAME(_asan__sys__sched_setaffinity, pid, lid, size, cpuset);

int _sys__sched_setparam(pid_t pid, lwpid_t lid, int policy,
		const struct sched_param *params)
	RENAME(_asan__sys__sched_setparam, pid, lid, policy, params);

#include <sys/socket.h>

int _sys_accept(int s, struct sockaddr * __restrict addr,
		socklen_t * __restrict addrlen)
	RENAME(_asan__sys_accept, s, addr, addrlen);

int _sys_connect(int s, const struct sockaddr *name,
		unsigned int namelen)
	RENAME(_asan__sys_connect, s, name, namelen);

int _sys_execve(const char *path, char * const *argp, char * const *envp)
	RENAME(_asan__sys_execve, path, argp, envp);

#include <fcntl.h>
#include <stdarg.h>

/* XXX: How to wrap vararg functions? */
int
_sys_fcntl(int fd, int cmd, ...);

#include <mqueue.h>

ssize_t _sys_mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
		unsigned *msg_prio)
	RENAME(_asan__sys_mq_receive, mqdes, msg_ptr, msg_len, msg_prio);

ssize_t _sys_mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
		unsigned msg_prio)
	RENAME(_asan__sys_mq_send, mqdes, msg_ptr, msg_len, msg_prio);

ssize_t _sys_mq_timedreceive(mqd_t mqdes, char *__restrict msg_ptr, size_t msg_len,
		unsigned *__restrict msg_prio,
		const struct timespec *__restrict abs_timeout)
	RENAME(_asan__sys_mq_timedreceive, mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);

ssize_t _sys_mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
		unsigned msg_prio, const struct timespec *abs_timeout)
	RENAME(_asan__sys_mq_timedsend, mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);

#include <sys/msg.h>

ssize_t _sys_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
	RENAME(_asan__sys_msgrcv, msqid, msgp, msgsz, msgtyp, msgflg);

ssize_t _sys_msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
	RENAME(_asan__sys_msgsnd, msqid, msgp, msgsz, msgflg);

int _sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
	RENAME(_asan__sys_nanosleep, rqtp, rmtp);

/* XXX: How to wrap vararg functions? */
int _sys_open(const char *path, int flags, ...);

#include <sys/poll.h>

int _sys_poll(struct pollfd *fds, nfds_t nfds, int timeout)
	RENAME(_asan__sys_poll, fds, nfds, timeout);

int _sys_pollts(struct pollfd * __restrict fds, nfds_t nfds,
		const struct timespec * __restrict ts,
		const sigset_t * __restrict sigmask)
	RENAME(_asan__sys_pollts, fds, nfds, ts, sigmask);

ssize_t _sys_pread(int fd, void *buf, size_t nread, off_t offset)
	RENAME(_asan__sys_pread, fd, buf, nread, offset);

#include <sys/select.h>

int _sys_pselect(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
		fd_set * __restrict exceptfds, const struct timespec * __restrict timeout,
		const sigset_t * __restrict sigmask)
	RENAME(_asan__sys_pselect, nfds, readfds, writefds, exceptfds, timeout, sigmask);

ssize_t _sys_pwrite(int fd, const void *buf, size_t nbyte,
		int pad, off_t offset)
	RENAME(_asan__sys_pwrite, fd, buf, nbyte, pad, offset);

ssize_t _sys_read(int fd, void *buf, size_t nread)
	RENAME(_asan__sys_read, fd, buf, nread);

ssize_t _sys_readlink(const char * __restrict path, char * __restrict buf,
		size_t bufsiz)
	RENAME(_asan__sys_readlink, path, buf, bufsiz);

ssize_t _sys_readv(int d, const struct iovec *iov, int iovcnt)
	RENAME(_asan__sys_readv, d, iov, iovcnt);

int _sys_select(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
		fd_set * __restrict exceptfds, struct timeval * __restrict timeout)
	RENAME(_asan__sys_select, nfds, readfds, writefds, exceptfds, timeout);

#include <sys/wait.h>
#include <sys/resource.h>

pid_t _sys_wait4(pid_t wpid, int *status, int options,
		struct rusage *rusage)
	RENAME(_asan__sys_wait4, wpid, status, options, rusage);

ssize_t _sys_write(int fd, const void *buf, size_t nbyte)
	RENAME(_asan__sys_write, fd, buf, nbyte);

ssize_t _sys_writev(int d, const struct iovec *iov, int iovcnt)
	RENAME(_asan__sys_writev, d, iov, iovcnt);

int access(const char *path, int flags)
	RENAME(_asan_access, path, flags);

int acct(const char *path)
	RENAME(_asan_acct, path);

int bind(int s, const struct sockaddr *name, unsigned int namelen)
	RENAME(_asan_bind, s, name, namelen);

int chdir(const char *path)
	RENAME(_asan_chdir, path);

int chflags(const char *path, unsigned long flags)
	RENAME(_asan_chflags, path, flags);

int chmod(const char *path, mode_t mode)
	RENAME(_asan_chmod, path, mode);

int chown(const char *path, uid_t owner, gid_t group)
	RENAME(_asan_chown, path, owner, group);

int chroot(const char *path)
	RENAME(_asan_chroot, path);

int clock_getres(clockid_t clock_id, struct timespec *res)
	RENAME(_asan_clock_getres, clock_id, res);

int clock_gettime(clockid_t clock_id, struct timespec *tp)
	RENAME(_asan_clock_gettime, clock_id, tp);

int clock_settime(clockid_t clock_id, const struct timespec *tp)
	RENAME(_asan_clock_settime, clock_id, tp);

#include <sys/extattr.h>

int extattr_delete_fd(int fd, int attrnamespace,
		const char *attrname)
	RENAME(_asan_extattr_delete_fd, fd, attrnamespace, attrname);

int extattr_delete_file(const char *path, int attrnamespace,
		const char *attrname)
	RENAME(_asan_extattr_delete_file, path, attrnamespace, attrname);

int extattr_delete_link(const char *path, int attrnamespace,
		const char *attrname)
	RENAME(_asan_extattr_delete_link, path, attrnamespace, attrname);

ssize_t extattr_get_fd(int fd, int attrnamespace, const char *attrname,
		void *data, size_t nbytes)
	RENAME(_asan_extattr_get_fd, fd, attrnamespace, attrname, data, nbytes);

ssize_t extattr_get_file(const char *path, int attrnamespace, const char *attrname,
		void *data, size_t nbytes)
	RENAME(_asan_extattr_get_file, path, attrnamespace, attrname, data, nbytes);

ssize_t extattr_get_link(const char *path, int attrnamespace, const char *attrname,
		void *data, size_t nbytes)
	RENAME(_asan_extattr_get_link, path, attrnamespace, attrname, data, nbytes);

ssize_t extattr_list_fd(int fd, int attrnamespace,
		void *data, size_t nbytes)
	RENAME(_asan_extattr_list_fd, fd, attrnamespace, data, nbytes);

ssize_t extattr_list_file(const char *path, int attrnamespace,
		void *data, size_t nbytes)
	RENAME(_asan_extattr_list_file, path, attrnamespace, data, nbytes);

ssize_t extattr_list_link(const char *path, int attrnamespace,
		void *data, size_t nbytes)
	RENAME(_asan_extattr_list_link, path, attrnamespace, data, nbytes);

int extattr_set_fd(int fd, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
	RENAME(_asan_extattr_set_fd, fd, attrnamespace, attrname, data, nbytes);

int extattr_set_file(const char *path, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
	RENAME(_asan_extattr_set_file, path, attrnamespace, attrname, data, nbytes);

int extattr_set_link(const char *path, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
	RENAME(_asan_extattr_set_link, path, attrnamespace, attrname, data, nbytes);

int extattrctl(const char *path, int cmd, const char *filename,
		int attrnamespace, const char *attrname)
	RENAME(_asan_extattrctl, path, cmd, filename, attrnamespace, attrname);

int fstatvfs1(int fd, struct statvfs *buf, int flags)
	RENAME(_asan_fstatvfs1, fd, buf, flags);

int futimes(int fd, const struct timeval times[2])
	RENAME(_asan_futimes, fd, times);

int getgroups(int gidsetlen, gid_t *gidset)
	RENAME(_asan_getgroups, gidsetlen, gidset);

int getitimer(int which, struct itimerval *value)
	RENAME(_asan_getitimer, which, value);

int getpeername(int s, struct sockaddr * __restrict name,
		socklen_t * __restrict namelen)
	RENAME(_asan_getpeername, s, name, namelen);

int getrlimit(int resource, struct rlimit *rlp)
	RENAME(_asan_getrlimit, resource, rlp);

int getrusage(int who, struct rusage *rusage)
	RENAME(_asan_getrusage, who, rusage);

int getsockname(int s, struct sockaddr * __restrict name,
		socklen_t * __restrict namelen)
	RENAME(_asan_getsockname, s, name, namelen);

int getsockopt(int s, int level, int optname, void * __restrict optval,
		socklen_t * __restrict optlen)
	RENAME(_asan_getsockopt, s, level, optname, optval, optlen);

int gettimeofday(struct timeval * __restrict tp, void * __restrict tzp)
	RENAME(_asan_gettimeofday, tp, tzp);

int getvfsstat(struct statvfs *buf, size_t bufsize, int flags)
	RENAME(_asan_getvfsstat, buf, bufsize, flags);

#include <sys/event.h>

int kevent(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout)
	RENAME(_asan_kevent, kq, changelist, nchanges, eventlist, nevents,
			timeout);

int lchflags(const char *path, unsigned long flags)
	RENAME(_asan_lchflags, path, flags);

int lchmod(const char *path, mode_t mode)
	RENAME(_asan_lchmod, path, mode);

int lchown(const char *path, uid_t owner, gid_t group)
	RENAME(_asan_lchown, path, owner, group);

#include <ufs/lfs/lfs.h>

int lfs_bmapv(fsid_t *fsidp, BLOCK_INFO *blkiov, int blkcnt)
	RENAME(_asan_lfs_bmapv, fsidp, blkiov, blkcnt);

int link(const char *path, const char *link)
	RENAME(_asan_link, path, link);

int lutimes(const char *path, const struct timeval times[2])
	RENAME(_asan_lutimes, path, times);

int mkdir(const char *path, mode_t mode)
	RENAME(_asan_mkdir, path, mode);

int mkfifo(const char *path, mode_t mode)
	RENAME(_asan_mkfifo, path, mode);

int mknod(const char *path, mode_t mode, dev_t dev)
	RENAME(_asan_mknod, path, mode, dev);

#include <sys/module.h>

int modctl(int cmd, void *arg)
	RENAME(_asan_modctl, cmd, arg);

int msgctl(int msgid, int cmd, struct msqid_ds *buf)
	RENAME(_asan_msgctl, msgid, cmd, buf);

long pathconf(const char *path, int name)
	RENAME(_asan_pathconf, path, name);

#include <sys/pmc.h>

int pmc_get_info(int ctr, int op, void *args)
	RENAME(_asan_pmc_get_info, ctr, op, args);

int profil(char *samples, size_t size, u_long offset, u_int scale)
	RENAME(_asan_profil, samples, size, offset, scale);

#include <ufs/ufs/quota.h>

int quotactl(const char *path, int cmd, int id, void *addr)
	RENAME(_asan_quotactl, path, cmd, id, addr);

ssize_t recvfrom(int s, void * __restrict buf, size_t len, int flags,
		struct sockaddr * __restrict from, socklen_t * __restrict fromlen)
	RENAME(_asan_recvfrom, s, buf, len, flags, from, fromlen);

ssize_t recvmsg(int s, struct msghdr *msg, int flags)
	RENAME(_asan_recvmsg, s, msg, flags);

int rename(const char *from, const char *to)
	RENAME(_asan_rename, from, to);

int revoke(const char *path)
	RENAME(_asan_revoke, path);

int rmdir(const char *path)
	RENAME(_asan_rmdir, path);

ssize_t sendmsg(int s, const struct msghdr *msg, int flags)
	RENAME(_asan_sendmsg, s, msg, flags);

ssize_t sendto(int s, const void *msg, size_t len, int flags,
		const struct sockaddr *to, socklen_t tolen)
	RENAME(_asan_sendto, s, msg, len, flags, to, tolen);

int setgroups(int ngroups, const gid_t *gidset)
	RENAME(_asan_setgroups, ngroups, gidset);

int setitimer(int which, const struct itimerval * __restrict value,
		struct itimerval * __restrict ovalue)
	RENAME(_asan_setitimer, which, value, ovalue);

int setrlimit(int resource, const struct rlimit *rlp)
	RENAME(_asan_setrlimit, resource, rlp);

int setsockopt(int s, int level, int name, const void *val,
		unsigned int valsize)
	RENAME(_asan_setsockopt, s, level, name, val, valsize);

int settimeofday(const struct timeval *tv, const void *tzp)
	RENAME(_asan_settimeofday, tv, tzp);

#include <sys/shm.h>

int shmctl(int shmid, int cmd, struct shmid_ds *buf)
	RENAME(_asan_shmctl, shmid, cmd, buf);

int socketpair(int d, int type, int protocol, int *sv)
	RENAME(_asan_socketpair, d, type, protocol, sv);

int statvfs1(const char *path, struct statvfs *buf, int flags)
	RENAME(_asan_statvfs1, path, buf, flags);

#include <sys/swap.h>

int swapctl(int cmd, void *arg, int misc)
	RENAME(_asan_swapctl, cmd, arg, misc);

int symlink(const char *path, const char *link)
	RENAME(_asan_symlink, path, link);

int timer_create(clockid_t clockid, struct sigevent * __restrict evp,
		timer_t * __restrict timerid)
	RENAME(_asan_timer_create, clockid, evp, timerid);

int timer_gettime(timer_t timerid, struct itimerspec *tim)
	RENAME(_asan_timer_gettime, timerid, tim);

int timer_settime(timer_t timerid, int flags,
		const struct itimerspec * __restrict tim,
		struct itimerspec * __restrict otim)
	RENAME(_asan_timer_settime, timerid, flags, tim, otim);

int undelete(const char *path)
	RENAME(_asan_undelete, path);

int unlink(const char *path)
	RENAME(_asan_unlink, path);

int unmount(const char *path, int flags)
	RENAME(_asan_unmount, path, flags);

int utimes(const char *path, const struct timeval times[2])
	RENAME(_asan_utimes, path, times);

#include <sys/uuid.h>

int uuidgen(struct uuid *store, int count)
	RENAME(_asan_uuidgen, store, count);
