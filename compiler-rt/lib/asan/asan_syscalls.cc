#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>

int __adjtime(const struct timeval *delta, struct timeval *olddelta)
	__RENAME(_asan___adjtime);

int __fhopen40(const void *fhp, size_t fh_size, int flags)
	__RENAME(_asan___fhopen40);

int __fhstat50(const void *fhp, size_t fh_size, struct stat *sb)
	__RENAME(_asan___fhstat50);

int __fhstatvfs140(const void *fhp, size_t fh_size,
		struct statvfs *buf, int flags)
	__RENAME(_asan___fhstatvfs140);

int __fstat50(int fd, struct stat *sb)
	__RENAME(_asan___fstat50);

int __getcwd(char *bufp, size_t length)
	__RENAME(_asan___getcwd);

#include <dirent.h>

int __getdents30(int fd, char *buf, size_t count)
	__RENAME(_asan___getdents30);

#include <sys/mount.h>

int __getfh30(const char *fname, void *fhp, size_t *fh_size)
	__RENAME(_asan___getfh30);

int __getlogin(char *namebuf, size_t namelen)
	__RENAME(_asan___getlogin);

int __lstat50(const char *path, struct stat *sb)
	__RENAME(_asan___lstat50);

#include <sys/param.h>

int __mount50(const char *type, const char *path, int flags,
		void *data, size_t data_len)
	__RENAME(_asan___mount50);

#include <sys/timex.h>

int __ntp_adjtime(struct timex *tp)
	__RENAME(_asan___ntp_adjtime);

int __ntp_gettime50(struct ntptimeval *ntvp)
	__RENAME(_asan___ntp_gettime50);

int __posix_chown(const char *path, uid_t owner, gid_t group)
	__RENAME(_asan___posix_chown);

int __posix_lchown(const char *path, uid_t owner, gid_t group)
	__RENAME(_asan___posix_lchown);

#include <sys/uio.h>

ssize_t __preadv(int d, const struct iovec *iov, int iovcnt, off_t offset)
	__RENAME(_asan___preadv);

ssize_t __pwritev(int d, const struct iovec *iov, int iovcnt, off_t offset)
	__RENAME(_asan___pwritev);

int __setlogin(const char *namebuf)
	__RENAME(_asan___setlogin);

#include <sys/signal.h>

int __sigaction_sigtramp(int signum, const struct sigaction *nsa,
		struct sigaction *osa, const void *tramp, int vers)
	__RENAME(_asan___sigaction_sigtramp);

#include <signal.h>

int __sigaltstack14(const struct sigaltstack *nss,
		struct sigaltstack *oss)
	__RENAME(_asan___sigaltstack14);

int __sigpending14(sigset_t *set)
	__RENAME(_asan___sigpending14);

#include <time.h>

int __sigtimedwait(const sigset_t *set, siginfo_t *info,
		struct timespec *timeout)
	__RENAME(_asan____sigtimedwait50);

int __stat50(const char *path, struct stat *ub)
	__RENAME(_asan___stat50);

#include <sys/sysctl.h>
#include <errno.h>

int __sysctl(const int *name, u_int namelen, void *old,
		size_t *oldlenp, const void *newp, size_t newlen)
	__RENAME(_asan___sysctl);

int __truncate(const char *path, int pad, off_t length)
	__RENAME(_asan___truncate);

#include <sys/ucontext.h>

int _getcontext(struct __ucontext *ucp)
	__RENAME(_asan__getcontext);

#include <sys/ksem.h>

int _ksem_getvalue(intptr_t id, unsigned int *value)
	__RENAME(_asan__ksem_getvalue);

int _ksem_init(unsigned int value, intptr_t idp)
	__RENAME(_asan__ksem_init);

int _ksem_open(const char *name, int oflag, mode_t mode,
		unsigned int value, intptr_t idp)
	__RENAME(_asan__ksem_open);

int _ksem_unlink(const char *name)
	__RENAME(_asan__ksem_unlink);

#include <lwp.h>

int _lwp_create(const ucontext_t *context, unsigned long flags, lwpid_t *new_lwp)
	__RENAME(_asan__lwp_create);

int _lwp_ctl(int features, struct lwpctl **address)
	__RENAME(_asan__lwp_ctl);

int _lwp_getname(lwpid_t target, char *name, size_t len)
	__RENAME(_asan__lwp_getname);

int ___lwp_park50(const struct timespec *ts, lwpid_t unpark,
		const void *hint, const void *unparkhint)
	__RENAME(_asan____lwp_park50);

int _lwp_setname(lwpid_t target, const char *name)
	__RENAME(_asan__lwp_setname);

ssize_t _lwp_unpark_all(const lwpid_t *targets, size_t ntargets,
		const void *hint)
	__RENAME(_asan__lwp_unpark_all);

int _lwp_wait(lwpid_t wlwp, lwpid_t *rlwp)
	__RENAME(_asan__lwp_wait);

int _setcontext(struct __ucontext *ucp)
	__RENAME(_asan__setcontext);

int __sigprocmask14(int how, const sigset_t *set,
		sigset_t *oset)
	__RENAME(_asan__sys___sigprocmask14);

int __sigsuspend14(const sigset_t *sigmask)
	__RENAME(_asan__sys___sigsuspend14);

#include <sys/sched.h>

int _sched_getaffinity(pid_t pid, lwpid_t lid,
		size_t size, cpuset_t *cpuset)
	__RENAME(_asan__sys__sched_getaffinity);

int _sched_getparam(pid_t pid, lwpid_t lid, int *policy,
		struct sched_param *params)
	__RENAME(_asan__sys__sched_getparam);

int _sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset)
	__RENAME(_asan__sys__sched_setaffinity);

int _sched_setparam(pid_t pid, lwpid_t lid, int policy,
		const struct sched_param *params)
	__RENAME(_asan__sys__sched_setparam);

#include <sys/socket.h>

int accept(int s, struct sockaddr * __restrict addr,
		socklen_t * __restrict addrlen)
	__RENAME(_asan__sys_accept);

int connect(int s, const struct sockaddr *name,
		unsigned int namelen)
	__RENAME(_asan__sys_connect);

int execve(const char *path, char * const *argp, char * const *envp)
	__RENAME(_asan__sys_execve);

#include <fcntl.h>
#include <stdarg.h>

int
fcntl(int fd, int cmd, ...)
	__RENAME(_asan_fcntl);

#include <mqueue.h>

ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
		unsigned *msg_prio)
	__RENAME(_asan__sys_mq_receive);

ssize_t mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
		unsigned msg_prio)
	__RENAME(_asan__sys_mq_send);

ssize_t mq_timedreceive(mqd_t mqdes, char *__restrict msg_ptr, size_t msg_len,
		unsigned *__restrict msg_prio,
		const struct timespec *__restrict abs_timeout)
	__RENAME(_asan__sys_mq_timedreceive);

ssize_t mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
		unsigned msg_prio, const struct timespec *abs_timeout)
	__RENAME(_asan__sys_mq_timedsend);

#include <sys/msg.h>

ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
	__RENAME(_asan__sys_msgrcv);

ssize_t msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
	__RENAME(_asan__sys_msgsnd);

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
	__RENAME(_asan__sys_nanosleep);

int open(const char *path, int flags, ...)
	__RENAME(_asan_open);

#include <sys/poll.h>

int poll(struct pollfd *fds, nfds_t nfds, int timeout)
	__RENAME(_asan__sys_poll);

int pollts(struct pollfd * __restrict fds, nfds_t nfds,
		const struct timespec * __restrict ts,
		const sigset_t * __restrict sigmask)
	__RENAME(_asan__sys_pollts);

ssize_t pread(int fd, void *buf, size_t nread, off_t offset)
	__RENAME(_asan__sys_pread);

#include <sys/select.h>

int pselect(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
		fd_set * __restrict exceptfds, const struct timespec * __restrict timeout,
		const sigset_t * __restrict sigmask)
	__RENAME(_asan__sys_pselect);

ssize_t pwrite(int fd, const void *buf, size_t nbyte,
		int pad, off_t offset)
	__RENAME(_asan__sys_pwrite);

ssize_t read(int fd, void *buf, size_t nread)
	__RENAME(_asan__sys_read);

ssize_t readlink(const char * __restrict path, char * __restrict buf,
		size_t bufsiz)
	__RENAME(_asan__sys_readlink);

ssize_t readv(int d, const struct iovec *iov, int iovcnt)
	__RENAME(_asan__sys_readv);

int select(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
		fd_set * __restrict exceptfds, struct timeval * __restrict timeout)
	__RENAME(_asan__sys_select);

#include <sys/wait.h>
#include <sys/resource.h>

pid_t wait4(pid_t wpid, int *status, int options,
		struct rusage *rusage)
	__RENAME(_asan__sys_wait4);

ssize_t write(int fd, const void *buf, size_t nbyte)
	__RENAME(_asan__sys_write);

ssize_t writev(int d, const struct iovec *iov, int iovcnt)
	__RENAME(_asan__sys_writev);

int access(const char *path, int flags)
	__RENAME(_asan_access);

int acct(const char *path)
	__RENAME(_asan_acct);

int bind(int s, const struct sockaddr *name, unsigned int namelen)
	__RENAME(_asan_bind);

int chdir(const char *path)
	__RENAME(_asan_chdir);

int chflags(const char *path, unsigned long flags)
	__RENAME(_asan_chflags);

int chmod(const char *path, mode_t mode)
	__RENAME(_asan_chmod);

int chown(const char *path, uid_t owner, gid_t group)
	__RENAME(_asan_chown);

int chroot(const char *path)
	__RENAME(_asan_chroot);

int clock_getres(clockid_t clock_id, struct timespec *res)
	__RENAME(_asan_clock_getres);

int clock_gettime(clockid_t clock_id, struct timespec *tp)
	__RENAME(_asan_clock_gettime);

int clock_settime(clockid_t clock_id, const struct timespec *tp)
	__RENAME(_asan_clock_settime);

#include <sys/extattr.h>

int extattr_delete_fd(int fd, int attrnamespace,
		const char *attrname)
	__RENAME(_asan_extattr_delete_fd);

int extattr_delete_file(const char *path, int attrnamespace,
		const char *attrname)
	__RENAME(_asan_extattr_delete_file);

int extattr_delete_link(const char *path, int attrnamespace,
		const char *attrname)
	__RENAME(_asan_extattr_delete_link);

ssize_t extattr_get_fd(int fd, int attrnamespace, const char *attrname,
		void *data, size_t nbytes)
	__RENAME(_asan_extattr_get_fd);

ssize_t extattr_get_file(const char *path, int attrnamespace, const char *attrname,
		void *data, size_t nbytes)
	__RENAME(_asan_extattr_get_file);

ssize_t extattr_get_link(const char *path, int attrnamespace, const char *attrname,
		void *data, size_t nbytes)
	__RENAME(_asan_extattr_get_link);

ssize_t extattr_list_fd(int fd, int attrnamespace,
		void *data, size_t nbytes)
	__RENAME(_asan_extattr_list_fd);

ssize_t extattr_list_file(const char *path, int attrnamespace,
		void *data, size_t nbytes)
	__RENAME(_asan_extattr_list_file);

ssize_t extattr_list_link(const char *path, int attrnamespace,
		void *data, size_t nbytes)
	__RENAME(_asan_extattr_list_link);

int extattr_set_fd(int fd, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
	__RENAME(_asan_extattr_set_fd);

int extattr_set_file(const char *path, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
	__RENAME(_asan_extattr_set_file);

int extattr_set_link(const char *path, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
	__RENAME(_asan_extattr_set_link);

int extattrctl(const char *path, int cmd, const char *filename,
		int attrnamespace, const char *attrname)
	__RENAME(_asan_extattrctl);

int fstatvfs1(int fd, struct statvfs *buf, int flags)
	__RENAME(_asan_fstatvfs1);

int __futimes50(int fd, const struct timeval times[2])
	__RENAME(_asan___futimes50);

int getgroups(int gidsetlen, gid_t *gidset)
	__RENAME(_asan_getgroups);

int __getitimer50(int which, struct itimerval *value)
	__RENAME(_asan___getitimer50);

int getpeername(int s, struct sockaddr * __restrict name,
		socklen_t * __restrict namelen)
	__RENAME(_asan_getpeername);

int getrlimit(int resource, struct rlimit *rlp)
	__RENAME(_asan_getrlimit);

int getrusage(int who, struct rusage *rusage)
	__RENAME(_asan_getrusage);

int getsockname(int s, struct sockaddr * __restrict name,
		socklen_t * __restrict namelen)
	__RENAME(_asan_getsockname);

int getsockopt(int s, int level, int optname, void * __restrict optval,
		socklen_t * __restrict optlen)
	__RENAME(_asan_getsockopt);

int __gettimeofday50(struct timeval * __restrict tp, void * __restrict tzp)
	__RENAME(_asan___gettimeofday50);

int getvfsstat(struct statvfs *buf, size_t bufsize, int flags)
	__RENAME(_asan_getvfsstat);

#include <sys/event.h>

int __kevent50(int kq, const struct kevent *changelist, size_t nchanges,
		struct kevent *eventlist, size_t nevents,
		const struct timespec *timeout)
	__RENAME(_asan___kevent50);

int lchflags(const char *path, unsigned long flags)
	__RENAME(_asan_lchflags);

int lchmod(const char *path, mode_t mode)
	__RENAME(_asan_lchmod);

int lchown(const char *path, uid_t owner, gid_t group)
	__RENAME(_asan_lchown);

#include <ufs/ufs/dinode.h>
#include <ufs/lfs/lfs.h>

int lfs_bmapv(fsid_t *fsidp, struct block_info *blkiov, int blkcnt)
	__RENAME(_asan_lfs_bmapv);

int link(const char *path, const char *link)
	__RENAME(_asan_link);

int __lutimes50(const char *path, const struct timeval times[2])
	__RENAME(_asan___lutimes50);

int mkdir(const char *path, mode_t mode)
	__RENAME(_asan_mkdir);

int mkfifo(const char *path, mode_t mode)
	__RENAME(_asan_mkfifo);

int mknod(const char *path, mode_t mode, dev_t dev)
	__RENAME(_asan_mknod);

#include <sys/module.h>

int modctl(int cmd, void *arg)
	__RENAME(_asan_modctl);

int msgctl(int msgid, int cmd, struct msqid_ds *buf)
	__RENAME(_asan_msgctl);

long pathconf(const char *path, int name)
	__RENAME(_asan_pathconf);

#include <sys/pmc.h>

int pmc_get_info(int ctr, int op, void *args)
	__RENAME(_asan_pmc_get_info);

int profil(char *samples, size_t size, u_long offset, u_int scale)
	__RENAME(_asan_profil);

#include <ufs/ufs/quota.h>

int quotactl(const char *path, int cmd, int id, void *addr)
	__RENAME(_asan_quotactl);

ssize_t recvfrom(int s, void * __restrict buf, size_t len, int flags,
		struct sockaddr * __restrict from, socklen_t * __restrict fromlen)
	__RENAME(_asan_recvfrom);

ssize_t recvmsg(int s, struct msghdr *msg, int flags)
	__RENAME(_asan_recvmsg);

int rename(const char *from, const char *to)
	__RENAME(_asan_rename);

int revoke(const char *path)
	__RENAME(_asan_revoke);

int rmdir(const char *path)
	__RENAME(_asan_rmdir);

ssize_t sendmsg(int s, const struct msghdr *msg, int flags)
	__RENAME(_asan_sendmsg);

ssize_t sendto(int s, const void *msg, size_t len, int flags,
		const struct sockaddr *to, socklen_t tolen)
	__RENAME(_asan_sendto);

int setgroups(int ngroups, const gid_t *gidset)
	__RENAME(_asan_setgroups);

int __setitimer50(int which, const struct itimerval * __restrict value,
		struct itimerval * __restrict ovalue)
	__RENAME(_asan___setitimer50);

int setrlimit(int resource, const struct rlimit *rlp)
	__RENAME(_asan_setrlimit);

int setsockopt(int s, int level, int name, const void *val,
		unsigned int valsize)
	__RENAME(_asan_setsockopt);

int settimeofday(const struct timeval *tv, const void *tzp)
	__RENAME(_asan_settimeofday);

#include <sys/shm.h>

int __shmctl50(int shmid, int cmd, struct shmid_ds *buf)
	__RENAME(_asan___shmctl50);

int socketpair(int d, int type, int protocol, int *sv)
	__RENAME(_asan_socketpair);

int statvfs1(const char *path, struct statvfs *buf, int flags)
	__RENAME(_asan_statvfs1);

#include <sys/swap.h>

int swapctl(int cmd, void *arg, int misc)
	__RENAME(_asan_swapctl);

int symlink(const char *path, const char *link)
	__RENAME(_asan_symlink);

int timer_create(clockid_t clockid, struct sigevent * __restrict evp,
		timer_t * __restrict timerid)
	__RENAME(_asan_timer_create);

int __timer_gettime50(timer_t timerid, struct itimerspec *tim)
	__RENAME(_asan___timer_gettime50);

int __timer_settime50(timer_t timerid, int flags,
		const struct itimerspec * __restrict tim,
		struct itimerspec * __restrict otim)
	__RENAME(_asan___timer_settime50);

int undelete(const char *path)
	__RENAME(_asan_undelete);

int unlink(const char *path)
	__RENAME(_asan_unlink);

int unmount(const char *path, int flags)
	__RENAME(_asan_unmount);

int __utimes50(const char *path, const struct timeval times[2])
	__RENAME(_asan___utimes50);

#include <sys/uuid.h>

int uuidgen(struct uuid *store, int count)
	__RENAME(_asan_uuidgen);
