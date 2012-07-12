.PATH: ${.CURDIR}/asan/interceptors

MKLINT=no

# sa_register.c _sys__sched_getaffinity.c _sys__sched_setaffinity.c
# _sys__sched_getparam.c _sys__sched_getparam.c _getcontext.c

SRCS+=	__adjtime.c __truncate.c _sys_mq_send.c chown.c getsockname.c rename.c \
	__fhopen40.c _sys_mq_timedreceive.c chroot.c getsockopt.c revoke.c \
	__fhstat50.c _ksem_getvalue.c _sys_mq_timedsend.c clock_getres.c __gettimeofday50.c rmdir.c \
	__fhstatvfs140.c _ksem_init.c _sys_msgrcv.c clock_gettime.c getvfsstat.c \
	__fstat50.c _ksem_open.c _sys_msgsnd.c clock_settime.c interceptors.c sendmsg.c \
	__getcwd.c _ksem_unlink.c _sys_nanosleep.c extattr_delete_fd.c sendto.c \
	__getdents30.c _lwp_create.c _sys_open.c extattr_delete_file.c _sys___kevent50.c setgroups.c \
	__getfh30.c _lwp_ctl.c _sys_poll.c extattr_delete_link.c lchflags.c __setitimer50.c \
	__getlogin.c _lwp_getname.c _sys_pollts.c extattr_get_fd.c lchmod.c setrlimit.c \
	__lstat50.c ___lwp_park50.c _sys_pread.c extattr_get_file.c lchown.c setsockopt.c \
	__mmap.c _lwp_setname.c _sys_pselect.c extattr_get_link.c lfs_bmapv.c settimeofday.c \
	__mount50.c _lwp_unpark_all.c _sys_pwrite.c extattr_list_fd.c link.c __shmctl50.c \
	__ntp_adjtime.c _lwp_wait.c _sys_read.c extattr_list_file.c __lutimes50.c socketpair.c \
	__ntp_gettime50.c _setcontext.c _sys_readlink.c extattr_list_link.c mkdir.c statvfs1.c \
	__posix_chown.c _sys___sigprocmask14.c _sys_readv.c extattr_set_fd.c mkfifo.c swapctl.c \
	__posix_lchown.c _sys___sigsuspend14.c _sys_select.c extattr_set_file.c __mknod50.c symlink.c \
	__preadv.c _sys_wait4.c extattr_set_link.c modctl.c timer_create.c \
	__pwritev.c _sys_write.c extattrctl.c __msgctl50.c __timer_gettime50.c \
	__setlogin.c _sys_writev.c fstatvfs1.c munmap.c __timer_settime50.c \
	__sigaction_sigtramp.c access.c __futimes50.c pathconf.c undelete.c \
	__sigaltstack14.c _sys_accept.c acct.c getgroups.c pmc_get_info.c unlink.c \
	__sigpending14.c _sys_connect.c bind.c __getitimer50.c profil.c unmount.c \
	____sigtimedwait50.c _sys_execve.c chdir.c getpeername.c __quotactl.c __utimes50.c \
	__stat50.c _sys_fcntl.c chflags.c getrlimit.c recvfrom.c uuidgen.c _getcontext.c
