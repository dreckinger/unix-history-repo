/*
 * System call prototypes.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 * created from FreeBSD: src/sys/alpha/linux/syscalls.master,v 1.66 2006/02/06 01:13:47 rwatson Exp 
 */

#ifndef _LINUX_SYSPROTO_H_
#define	_LINUX_SYSPROTO_H_

#include <sys/signal.h>
#include <sys/acl.h>
#include <sys/thr.h>
#include <sys/umtx.h>
#include <posix4/_semaphore.h>

#include <sys/ucontext.h>

struct proc;

struct thread;

#define	PAD_(t)	(sizeof(register_t) <= sizeof(t) ? \
		0 : sizeof(register_t) - sizeof(t))

#if BYTE_ORDER == LITTLE_ENDIAN
#define	PADL_(t)	0
#define	PADR_(t)	PAD_(t)
#else
#define	PADL_(t)	PAD_(t)
#define	PADR_(t)	0
#endif

#define	nosys	linux_nosys
struct linux_fork_args {
	register_t dummy;
};
struct osf1_wait4_args {
	char pid_l_[PADL_(int)]; int pid; char pid_r_[PADR_(int)];
	char status_l_[PADL_(int *)]; int * status; char status_r_[PADR_(int *)];
	char options_l_[PADL_(int)]; int options; char options_r_[PADR_(int)];
	char rusage_l_[PADL_(struct osf1_rusage *)]; struct osf1_rusage * rusage; char rusage_r_[PADR_(struct osf1_rusage *)];
};
struct linux_link_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char to_l_[PADL_(char *)]; char * to; char to_r_[PADR_(char *)];
};
struct linux_unlink_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_chdir_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_mknod_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
	char dev_l_[PADL_(l_dev_t)]; l_dev_t dev; char dev_r_[PADR_(l_dev_t)];
};
struct linux_chmod_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_mode_t)]; l_mode_t mode; char mode_r_[PADR_(l_mode_t)];
};
struct linux_chown_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char uid_l_[PADL_(l_uid_t)]; l_uid_t uid; char uid_r_[PADR_(l_uid_t)];
	char gid_l_[PADL_(l_gid_t)]; l_gid_t gid; char gid_r_[PADR_(l_gid_t)];
};
struct linux_brk_args {
	char dsend_l_[PADL_(l_ulong)]; l_ulong dsend; char dsend_r_[PADR_(l_ulong)];
};
struct linux_lseek_args {
	char fdes_l_[PADL_(l_uint)]; l_uint fdes; char fdes_r_[PADR_(l_uint)];
	char off_l_[PADL_(l_off_t)]; l_off_t off; char off_r_[PADR_(l_off_t)];
	char whence_l_[PADL_(l_int)]; l_int whence; char whence_r_[PADR_(l_int)];
};
struct linux_umount_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_ptrace_args {
	register_t dummy;
};
struct linux_access_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
};
struct linux_kill_args {
	char pid_l_[PADL_(l_int)]; l_int pid; char pid_r_[PADR_(l_int)];
	char signum_l_[PADL_(l_int)]; l_int signum; char signum_r_[PADR_(l_int)];
};
struct linux_open_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct osf1_sigprocmask_args {
	char how_l_[PADL_(int)]; int how; char how_r_[PADR_(int)];
	char mask_l_[PADL_(u_long)]; u_long mask; char mask_r_[PADR_(u_long)];
};
struct linux_sigpending_args {
	register_t dummy;
};
struct linux_ioctl_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(l_ulong)]; l_ulong arg; char arg_r_[PADR_(l_ulong)];
};
struct linux_symlink_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char to_l_[PADL_(char *)]; char * to; char to_r_[PADR_(char *)];
};
struct linux_readlink_args {
	char name_l_[PADL_(char *)]; char * name; char name_r_[PADR_(char *)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char count_l_[PADL_(l_int)]; l_int count; char count_r_[PADR_(l_int)];
};
struct linux_execve_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char argp_l_[PADL_(char **)]; char ** argp; char argp_r_[PADR_(char **)];
	char envp_l_[PADL_(char **)]; char ** envp; char envp_r_[PADR_(char **)];
};
struct linux_getpagesize_args {
	register_t dummy;
};
struct linux_vfork_args {
	register_t dummy;
};
struct linux_newstat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char buf_l_[PADL_(struct l_newstat *)]; struct l_newstat * buf; char buf_r_[PADR_(struct l_newstat *)];
};
struct linux_newlstat_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char buf_l_[PADL_(struct l_newstat *)]; struct l_newstat * buf; char buf_r_[PADR_(struct l_newstat *)];
};
struct linux_mmap_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_ulong)]; l_ulong len; char len_r_[PADR_(l_ulong)];
	char prot_l_[PADL_(l_ulong)]; l_ulong prot; char prot_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
	char fd_l_[PADL_(l_ulong)]; l_ulong fd; char fd_r_[PADR_(l_ulong)];
	char pos_l_[PADL_(l_ulong)]; l_ulong pos; char pos_r_[PADR_(l_ulong)];
};
struct linux_munmap_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
};
struct linux_mprotect_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char prot_l_[PADL_(l_ulong)]; l_ulong prot; char prot_r_[PADR_(l_ulong)];
};
struct linux_vhangup_args {
	register_t dummy;
};
struct linux_setgroups_args {
	char gidsetsize_l_[PADL_(l_int)]; l_int gidsetsize; char gidsetsize_r_[PADR_(l_int)];
	char grouplist_l_[PADL_(l_gid_t *)]; l_gid_t * grouplist; char grouplist_r_[PADR_(l_gid_t *)];
};
struct linux_getgroups_args {
	char gidsetsize_l_[PADL_(l_int)]; l_int gidsetsize; char gidsetsize_r_[PADR_(l_int)];
	char grouplist_l_[PADL_(l_gid_t *)]; l_gid_t * grouplist; char grouplist_r_[PADR_(l_gid_t *)];
};
struct osf1_setitimer_args {
	char which_l_[PADL_(u_int)]; u_int which; char which_r_[PADR_(u_int)];
	char itv_l_[PADL_(struct itimerval *)]; struct itimerval * itv; char itv_r_[PADR_(struct itimerval *)];
	char oitv_l_[PADL_(struct itimerval *)]; struct itimerval * oitv; char oitv_r_[PADR_(struct itimerval *)];
};
struct linux_gethostname_args {
	register_t dummy;
};
struct linux_getdtablesize_args {
	register_t dummy;
};
struct linux_newfstat_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(struct l_newstat *)]; struct l_newstat * buf; char buf_r_[PADR_(struct l_newstat *)];
};
struct linux_fcntl_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(l_ulong)]; l_ulong arg; char arg_r_[PADR_(l_ulong)];
};
struct osf1_select_args {
	char nd_l_[PADL_(u_int)]; u_int nd; char nd_r_[PADR_(u_int)];
	char in_l_[PADL_(fd_set *)]; fd_set * in; char in_r_[PADR_(fd_set *)];
	char ou_l_[PADL_(fd_set *)]; fd_set * ou; char ou_r_[PADR_(fd_set *)];
	char ex_l_[PADL_(fd_set *)]; fd_set * ex; char ex_r_[PADR_(fd_set *)];
	char tv_l_[PADL_(struct timeval *)]; struct timeval * tv; char tv_r_[PADR_(struct timeval *)];
};
struct osf1_socket_args {
	char domain_l_[PADL_(int)]; int domain; char domain_r_[PADR_(int)];
	char type_l_[PADL_(int)]; int type; char type_r_[PADR_(int)];
	char protocol_l_[PADL_(int)]; int protocol; char protocol_r_[PADR_(int)];
};
struct linux_connect_args {
	char s_l_[PADL_(l_int)]; l_int s; char s_r_[PADR_(l_int)];
	char name_l_[PADL_(struct l_sockaddr *)]; struct l_sockaddr * name; char name_r_[PADR_(struct l_sockaddr *)];
	char namelen_l_[PADL_(l_int)]; l_int namelen; char namelen_r_[PADR_(l_int)];
};
struct linux_getpriority_args {
	char which_l_[PADL_(int)]; int which; char which_r_[PADR_(int)];
	char who_l_[PADL_(int)]; int who; char who_r_[PADR_(int)];
};
struct osf1_sigreturn_args {
	char sigcntxp_l_[PADL_(struct osigcontext *)]; struct osigcontext * sigcntxp; char sigcntxp_r_[PADR_(struct osigcontext *)];
};
struct osf1_sigsuspend_args {
	char ss_l_[PADL_(unsigned long)]; unsigned long ss; char ss_r_[PADR_(unsigned long)];
};
struct linux_recvmsg_args {
	register_t dummy;
};
struct linux_sendmsg_args {
	register_t dummy;
};
struct osf1_gettimeofday_args {
	char tp_l_[PADL_(struct timeval *)]; struct timeval * tp; char tp_r_[PADR_(struct timeval *)];
	char tzp_l_[PADL_(struct timezone *)]; struct timezone * tzp; char tzp_r_[PADR_(struct timezone *)];
};
struct osf1_getrusage_args {
	char who_l_[PADL_(long)]; long who; char who_r_[PADR_(long)];
	char rusage_l_[PADL_(void *)]; void * rusage; char rusage_r_[PADR_(void *)];
};
struct linux_rename_args {
	char from_l_[PADL_(char *)]; char * from; char from_r_[PADR_(char *)];
	char to_l_[PADL_(char *)]; char * to; char to_r_[PADR_(char *)];
};
struct linux_truncate_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char length_l_[PADL_(l_ulong)]; l_ulong length; char length_r_[PADR_(l_ulong)];
};
struct osf1_sendto_args {
	char s_l_[PADL_(int)]; int s; char s_r_[PADR_(int)];
	char buf_l_[PADL_(caddr_t)]; caddr_t buf; char buf_r_[PADR_(caddr_t)];
	char len_l_[PADL_(size_t)]; size_t len; char len_r_[PADR_(size_t)];
	char flags_l_[PADL_(int)]; int flags; char flags_r_[PADR_(int)];
	char to_l_[PADL_(struct sockaddr *)]; struct sockaddr * to; char to_r_[PADR_(struct sockaddr *)];
	char tolen_l_[PADL_(int)]; int tolen; char tolen_r_[PADR_(int)];
};
struct linux_socketpair_args {
	register_t dummy;
};
struct linux_mkdir_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char mode_l_[PADL_(l_int)]; l_int mode; char mode_r_[PADR_(l_int)];
};
struct linux_rmdir_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_getrlimit_args {
	char resource_l_[PADL_(l_uint)]; l_uint resource; char resource_r_[PADR_(l_uint)];
	char rlim_l_[PADL_(struct l_rlimit *)]; struct l_rlimit * rlim; char rlim_r_[PADR_(struct l_rlimit *)];
};
struct linux_setrlimit_args {
	char resource_l_[PADL_(l_uint)]; l_uint resource; char resource_r_[PADR_(l_uint)];
	char rlim_l_[PADL_(struct l_rlimit *)]; struct l_rlimit * rlim; char rlim_r_[PADR_(struct l_rlimit *)];
};
struct linux_quotactl_args {
	register_t dummy;
};
struct osf1_sigaction_args {
	char sig_l_[PADL_(int)]; int sig; char sig_r_[PADR_(int)];
	char nsa_l_[PADL_(struct osf1_sigaction *)]; struct osf1_sigaction * nsa; char nsa_r_[PADR_(struct osf1_sigaction *)];
	char osa_l_[PADL_(struct osf1_sigaction *)]; struct osf1_sigaction * osa; char osa_r_[PADR_(struct osf1_sigaction *)];
};
struct linux_msgctl_args {
	char msqid_l_[PADL_(l_int)]; l_int msqid; char msqid_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char buf_l_[PADL_(struct l_msqid_ds *)]; struct l_msqid_ds * buf; char buf_r_[PADR_(struct l_msqid_ds *)];
};
struct linux_msgget_args {
	char key_l_[PADL_(l_key_t)]; l_key_t key; char key_r_[PADR_(l_key_t)];
	char msgflg_l_[PADL_(l_int)]; l_int msgflg; char msgflg_r_[PADR_(l_int)];
};
struct linux_msgrcv_args {
	char msqid_l_[PADL_(l_int)]; l_int msqid; char msqid_r_[PADR_(l_int)];
	char msgp_l_[PADL_(struct l_msgbuf *)]; struct l_msgbuf * msgp; char msgp_r_[PADR_(struct l_msgbuf *)];
	char msgsz_l_[PADL_(l_size_t)]; l_size_t msgsz; char msgsz_r_[PADR_(l_size_t)];
	char msgtyp_l_[PADL_(l_long)]; l_long msgtyp; char msgtyp_r_[PADR_(l_long)];
	char msgflg_l_[PADL_(l_int)]; l_int msgflg; char msgflg_r_[PADR_(l_int)];
};
struct linux_msgsnd_args {
	char msqid_l_[PADL_(l_int)]; l_int msqid; char msqid_r_[PADR_(l_int)];
	char msgp_l_[PADL_(struct l_msgbuf *)]; struct l_msgbuf * msgp; char msgp_r_[PADR_(struct l_msgbuf *)];
	char msgsz_l_[PADL_(l_size_t)]; l_size_t msgsz; char msgsz_r_[PADR_(l_size_t)];
	char msgflg_l_[PADL_(l_int)]; l_int msgflg; char msgflg_r_[PADR_(l_int)];
};
struct linux_semctl_args {
	char semid_l_[PADL_(l_int)]; l_int semid; char semid_r_[PADR_(l_int)];
	char semnum_l_[PADL_(l_int)]; l_int semnum; char semnum_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char arg_l_[PADL_(union l_semun)]; union l_semun arg; char arg_r_[PADR_(union l_semun)];
};
struct linux_semget_args {
	char key_l_[PADL_(l_key_t)]; l_key_t key; char key_r_[PADR_(l_key_t)];
	char nsems_l_[PADL_(l_int)]; l_int nsems; char nsems_r_[PADR_(l_int)];
	char semflg_l_[PADL_(l_int)]; l_int semflg; char semflg_r_[PADR_(l_int)];
};
struct linux_semop_args {
	char semid_l_[PADL_(l_int)]; l_int semid; char semid_r_[PADR_(l_int)];
	char tsops_l_[PADL_(struct l_sembuf *)]; struct l_sembuf * tsops; char tsops_r_[PADR_(struct l_sembuf *)];
	char nsops_l_[PADL_(l_uint)]; l_uint nsops; char nsops_r_[PADR_(l_uint)];
};
struct linux_lchown_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char uid_l_[PADL_(l_uid_t)]; l_uid_t uid; char uid_r_[PADR_(l_uid_t)];
	char gid_l_[PADL_(l_gid_t)]; l_gid_t gid; char gid_r_[PADR_(l_gid_t)];
};
struct linux_shmat_args {
	char shmid_l_[PADL_(l_int)]; l_int shmid; char shmid_r_[PADR_(l_int)];
	char shmaddr_l_[PADL_(char *)]; char * shmaddr; char shmaddr_r_[PADR_(char *)];
	char shmflg_l_[PADL_(l_int)]; l_int shmflg; char shmflg_r_[PADR_(l_int)];
};
struct linux_shmctl_args {
	char shmid_l_[PADL_(l_int)]; l_int shmid; char shmid_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_int)]; l_int cmd; char cmd_r_[PADR_(l_int)];
	char buf_l_[PADL_(struct l_shmid_ds *)]; struct l_shmid_ds * buf; char buf_r_[PADR_(struct l_shmid_ds *)];
};
struct linux_shmdt_args {
	char shmaddr_l_[PADL_(char *)]; char * shmaddr; char shmaddr_r_[PADR_(char *)];
};
struct linux_shmget_args {
	char key_l_[PADL_(l_key_t)]; l_key_t key; char key_r_[PADR_(l_key_t)];
	char size_l_[PADL_(l_size_t)]; l_size_t size; char size_r_[PADR_(l_size_t)];
	char shmflg_l_[PADL_(l_int)]; l_int shmflg; char shmflg_r_[PADR_(l_int)];
};
struct linux_msync_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char fl_l_[PADL_(l_int)]; l_int fl; char fl_r_[PADR_(l_int)];
};
struct linux_getsid_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
};
struct linux_sigaltstack_args {
	register_t dummy;
};
struct osf1_sysinfo_args {
	char cmd_l_[PADL_(int)]; int cmd; char cmd_r_[PADR_(int)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char count_l_[PADL_(long)]; long count; char count_r_[PADR_(long)];
};
struct linux_sysfs_args {
	char option_l_[PADL_(l_int)]; l_int option; char option_r_[PADR_(l_int)];
	char arg1_l_[PADL_(l_ulong)]; l_ulong arg1; char arg1_r_[PADR_(l_ulong)];
	char arg2_l_[PADL_(l_ulong)]; l_ulong arg2; char arg2_r_[PADR_(l_ulong)];
};
struct osf1_getsysinfo_args {
	char op_l_[PADL_(u_long)]; u_long op; char op_r_[PADR_(u_long)];
	char buffer_l_[PADL_(caddr_t)]; caddr_t buffer; char buffer_r_[PADR_(caddr_t)];
	char nbytes_l_[PADL_(u_long)]; u_long nbytes; char nbytes_r_[PADR_(u_long)];
	char arg_l_[PADL_(caddr_t)]; caddr_t arg; char arg_r_[PADR_(caddr_t)];
	char flag_l_[PADL_(u_long)]; u_long flag; char flag_r_[PADR_(u_long)];
};
struct osf1_setsysinfo_args {
	char op_l_[PADL_(u_long)]; u_long op; char op_r_[PADR_(u_long)];
	char buffer_l_[PADL_(caddr_t)]; caddr_t buffer; char buffer_r_[PADR_(caddr_t)];
	char nbytes_l_[PADL_(u_long)]; u_long nbytes; char nbytes_r_[PADR_(u_long)];
	char arg_l_[PADL_(caddr_t)]; caddr_t arg; char arg_r_[PADR_(caddr_t)];
	char flag_l_[PADL_(u_long)]; u_long flag; char flag_r_[PADR_(u_long)];
};
struct linux_bdflush_args {
	register_t dummy;
};
struct linux_sethae_args {
	register_t dummy;
};
struct linux_mount_args {
	char specialfile_l_[PADL_(char *)]; char * specialfile; char specialfile_r_[PADR_(char *)];
	char dir_l_[PADL_(char *)]; char * dir; char dir_r_[PADR_(char *)];
	char filesystemtype_l_[PADL_(char *)]; char * filesystemtype; char filesystemtype_r_[PADR_(char *)];
	char rwflag_l_[PADL_(l_ulong)]; l_ulong rwflag; char rwflag_r_[PADR_(l_ulong)];
	char data_l_[PADL_(void *)]; void * data; char data_r_[PADR_(void *)];
};
struct linux_old_adjtimex_args {
	register_t dummy;
};
struct linux_swapoff_args {
	register_t dummy;
};
struct linux_getdents_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char dent_l_[PADL_(void *)]; void * dent; char dent_r_[PADR_(void *)];
	char count_l_[PADL_(l_uint)]; l_uint count; char count_r_[PADR_(l_uint)];
};
struct linux_create_module_args {
	register_t dummy;
};
struct linux_init_module_args {
	register_t dummy;
};
struct linux_delete_module_args {
	register_t dummy;
};
struct linux_get_kernel_syms_args {
	register_t dummy;
};
struct linux_syslog_args {
	char type_l_[PADL_(l_int)]; l_int type; char type_r_[PADR_(l_int)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char len_l_[PADL_(l_int)]; l_int len; char len_r_[PADR_(l_int)];
};
struct linux_reboot_args {
	char magic1_l_[PADL_(l_int)]; l_int magic1; char magic1_r_[PADR_(l_int)];
	char magic2_l_[PADL_(l_int)]; l_int magic2; char magic2_r_[PADR_(l_int)];
	char cmd_l_[PADL_(l_uint)]; l_uint cmd; char cmd_r_[PADR_(l_uint)];
	char arg_l_[PADL_(void *)]; void * arg; char arg_r_[PADR_(void *)];
};
struct linux_clone_args {
	char flags_l_[PADL_(l_int)]; l_int flags; char flags_r_[PADR_(l_int)];
	char stack_l_[PADL_(void *)]; void * stack; char stack_r_[PADR_(void *)];
};
struct linux_uselib_args {
	char library_l_[PADL_(char *)]; char * library; char library_r_[PADR_(char *)];
};
struct linux_sysinfo_args {
	register_t dummy;
};
struct linux_sysctl_args {
	char args_l_[PADL_(struct l___sysctl_args *)]; struct l___sysctl_args * args; char args_r_[PADR_(struct l___sysctl_args *)];
};
struct linux_oldumount_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
};
struct linux_times_args {
	char buf_l_[PADL_(struct l_times_argv *)]; struct l_times_argv * buf; char buf_r_[PADR_(struct l_times_argv *)];
};
struct linux_personality_args {
	char per_l_[PADL_(l_ulong)]; l_ulong per; char per_r_[PADR_(l_ulong)];
};
struct linux_setfsuid_args {
	char uid_l_[PADL_(l_uid_t)]; l_uid_t uid; char uid_r_[PADR_(l_uid_t)];
};
struct linux_setfsgid_args {
	char gid_l_[PADL_(l_gid_t)]; l_gid_t gid; char gid_r_[PADR_(l_gid_t)];
};
struct linux_ustat_args {
	char dev_l_[PADL_(l_dev_t)]; l_dev_t dev; char dev_r_[PADR_(l_dev_t)];
	char ubuf_l_[PADL_(struct l_ustat *)]; struct l_ustat * ubuf; char ubuf_r_[PADR_(struct l_ustat *)];
};
struct linux_statfs_args {
	char path_l_[PADL_(char *)]; char * path; char path_r_[PADR_(char *)];
	char buf_l_[PADL_(struct l_statfs_buf *)]; struct l_statfs_buf * buf; char buf_r_[PADR_(struct l_statfs_buf *)];
};
struct linux_fstatfs_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(struct l_statfs_buf *)]; struct l_statfs_buf * buf; char buf_r_[PADR_(struct l_statfs_buf *)];
};
struct linux_sched_setscheduler_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char policy_l_[PADL_(l_int)]; l_int policy; char policy_r_[PADR_(l_int)];
	char param_l_[PADL_(struct l_sched_param *)]; struct l_sched_param * param; char param_r_[PADR_(struct l_sched_param *)];
};
struct linux_sched_getscheduler_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
};
struct linux_sched_get_priority_max_args {
	char policy_l_[PADL_(l_int)]; l_int policy; char policy_r_[PADR_(l_int)];
};
struct linux_sched_get_priority_min_args {
	char policy_l_[PADL_(l_int)]; l_int policy; char policy_r_[PADR_(l_int)];
};
struct linux_newuname_args {
	char buf_l_[PADL_(struct l_newuname_t *)]; struct l_newuname_t * buf; char buf_r_[PADR_(struct l_newuname_t *)];
};
struct linux_mremap_args {
	char addr_l_[PADL_(l_ulong)]; l_ulong addr; char addr_r_[PADR_(l_ulong)];
	char old_len_l_[PADL_(l_ulong)]; l_ulong old_len; char old_len_r_[PADR_(l_ulong)];
	char new_len_l_[PADL_(l_ulong)]; l_ulong new_len; char new_len_r_[PADR_(l_ulong)];
	char flags_l_[PADL_(l_ulong)]; l_ulong flags; char flags_r_[PADR_(l_ulong)];
	char new_addr_l_[PADL_(l_ulong)]; l_ulong new_addr; char new_addr_r_[PADR_(l_ulong)];
};
struct linux_nfsservctl_args {
	register_t dummy;
};
struct linux_pciconfig_read_args {
	register_t dummy;
};
struct linux_pciconfig_write_args {
	register_t dummy;
};
struct linux_query_module_args {
	register_t dummy;
};
struct linux_prctl_args {
	register_t dummy;
};
struct linux_pread_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char nbyte_l_[PADL_(l_size_t)]; l_size_t nbyte; char nbyte_r_[PADR_(l_size_t)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
};
struct linux_pwrite_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char nbyte_l_[PADL_(l_size_t)]; l_size_t nbyte; char nbyte_r_[PADR_(l_size_t)];
	char offset_l_[PADL_(l_loff_t)]; l_loff_t offset; char offset_r_[PADR_(l_loff_t)];
};
struct linux_rt_sigreturn_args {
	register_t dummy;
};
struct linux_rt_sigaction_args {
	char sig_l_[PADL_(l_int)]; l_int sig; char sig_r_[PADR_(l_int)];
	char act_l_[PADL_(l_sigaction_t *)]; l_sigaction_t * act; char act_r_[PADR_(l_sigaction_t *)];
	char oact_l_[PADL_(l_sigaction_t *)]; l_sigaction_t * oact; char oact_r_[PADR_(l_sigaction_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_rt_sigprocmask_args {
	char how_l_[PADL_(l_int)]; l_int how; char how_r_[PADR_(l_int)];
	char mask_l_[PADL_(l_sigset_t *)]; l_sigset_t * mask; char mask_r_[PADR_(l_sigset_t *)];
	char omask_l_[PADL_(l_sigset_t *)]; l_sigset_t * omask; char omask_r_[PADR_(l_sigset_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_rt_sigpending_args {
	register_t dummy;
};
struct linux_rt_sigtimedwait_args {
	register_t dummy;
};
struct linux_rt_sigqueueinfo_args {
	register_t dummy;
};
struct linux_rt_sigsuspend_args {
	char newset_l_[PADL_(l_sigset_t *)]; l_sigset_t * newset; char newset_r_[PADR_(l_sigset_t *)];
	char sigsetsize_l_[PADL_(l_size_t)]; l_size_t sigsetsize; char sigsetsize_r_[PADR_(l_size_t)];
};
struct linux_select_args {
	char nfds_l_[PADL_(l_int)]; l_int nfds; char nfds_r_[PADR_(l_int)];
	char readfds_l_[PADL_(l_fd_set *)]; l_fd_set * readfds; char readfds_r_[PADR_(l_fd_set *)];
	char writefds_l_[PADL_(l_fd_set *)]; l_fd_set * writefds; char writefds_r_[PADR_(l_fd_set *)];
	char exceptfds_l_[PADL_(l_fd_set *)]; l_fd_set * exceptfds; char exceptfds_r_[PADR_(l_fd_set *)];
	char timeout_l_[PADL_(struct l_timeval *)]; struct l_timeval * timeout; char timeout_r_[PADR_(struct l_timeval *)];
};
struct linux_getitimer_args {
	char which_l_[PADL_(l_int)]; l_int which; char which_r_[PADR_(l_int)];
	char itv_l_[PADL_(struct l_itimerval *)]; struct l_itimerval * itv; char itv_r_[PADR_(struct l_itimerval *)];
};
struct linux_setitimer_args {
	char which_l_[PADL_(l_int)]; l_int which; char which_r_[PADR_(l_int)];
	char itv_l_[PADL_(struct l_itimerval *)]; struct l_itimerval * itv; char itv_r_[PADR_(struct l_itimerval *)];
	char oitv_l_[PADL_(struct l_itimerval *)]; struct l_itimerval * oitv; char oitv_r_[PADR_(struct l_itimerval *)];
};
struct linux_utimes_args {
	char fname_l_[PADL_(char *)]; char * fname; char fname_r_[PADR_(char *)];
	char times_l_[PADL_(struct l_timeval *)]; struct l_timeval * times; char times_r_[PADR_(struct l_timeval *)];
};
struct linux_wait4_args {
	char pid_l_[PADL_(l_pid_t)]; l_pid_t pid; char pid_r_[PADR_(l_pid_t)];
	char status_l_[PADL_(l_uint *)]; l_uint * status; char status_r_[PADR_(l_uint *)];
	char options_l_[PADL_(l_int)]; l_int options; char options_r_[PADR_(l_int)];
	char rusage_l_[PADL_(struct l_rusage *)]; struct l_rusage * rusage; char rusage_r_[PADR_(struct l_rusage *)];
};
struct linux_adjtimex_args {
	register_t dummy;
};
struct linux_getcwd_args {
	char buf_l_[PADL_(char *)]; char * buf; char buf_r_[PADR_(char *)];
	char bufsize_l_[PADL_(l_ulong)]; l_ulong bufsize; char bufsize_r_[PADR_(l_ulong)];
};
struct linux_capget_args {
	register_t dummy;
};
struct linux_capset_args {
	register_t dummy;
};
struct linux_sendfile_args {
	register_t dummy;
};
struct linux_pivot_root_args {
	char new_root_l_[PADL_(char *)]; char * new_root; char new_root_r_[PADR_(char *)];
	char put_old_l_[PADL_(char *)]; char * put_old; char put_old_r_[PADR_(char *)];
};
struct linux_mincore_args {
	char start_l_[PADL_(l_ulong)]; l_ulong start; char start_r_[PADR_(l_ulong)];
	char len_l_[PADL_(l_size_t)]; l_size_t len; char len_r_[PADR_(l_size_t)];
	char vec_l_[PADL_(u_char *)]; u_char * vec; char vec_r_[PADR_(u_char *)];
};
struct linux_pciconfig_iobase_args {
	register_t dummy;
};
struct linux_getdents64_args {
	char fd_l_[PADL_(l_uint)]; l_uint fd; char fd_r_[PADR_(l_uint)];
	char dirent_l_[PADL_(void *)]; void * dirent; char dirent_r_[PADR_(void *)];
	char count_l_[PADL_(l_uint)]; l_uint count; char count_r_[PADR_(l_uint)];
};
#define	nosys	linux_nosys
int	linux_fork(struct thread *, struct linux_fork_args *);
int	osf1_wait4(struct thread *, struct osf1_wait4_args *);
int	linux_link(struct thread *, struct linux_link_args *);
int	linux_unlink(struct thread *, struct linux_unlink_args *);
int	linux_chdir(struct thread *, struct linux_chdir_args *);
int	linux_mknod(struct thread *, struct linux_mknod_args *);
int	linux_chmod(struct thread *, struct linux_chmod_args *);
int	linux_chown(struct thread *, struct linux_chown_args *);
int	linux_brk(struct thread *, struct linux_brk_args *);
int	linux_lseek(struct thread *, struct linux_lseek_args *);
int	linux_umount(struct thread *, struct linux_umount_args *);
int	linux_ptrace(struct thread *, struct linux_ptrace_args *);
int	linux_access(struct thread *, struct linux_access_args *);
int	linux_kill(struct thread *, struct linux_kill_args *);
int	linux_open(struct thread *, struct linux_open_args *);
int	osf1_sigprocmask(struct thread *, struct osf1_sigprocmask_args *);
int	linux_sigpending(struct thread *, struct linux_sigpending_args *);
int	linux_ioctl(struct thread *, struct linux_ioctl_args *);
int	linux_symlink(struct thread *, struct linux_symlink_args *);
int	linux_readlink(struct thread *, struct linux_readlink_args *);
int	linux_execve(struct thread *, struct linux_execve_args *);
int	linux_getpagesize(struct thread *, struct linux_getpagesize_args *);
int	linux_vfork(struct thread *, struct linux_vfork_args *);
int	linux_newstat(struct thread *, struct linux_newstat_args *);
int	linux_newlstat(struct thread *, struct linux_newlstat_args *);
int	linux_mmap(struct thread *, struct linux_mmap_args *);
int	linux_munmap(struct thread *, struct linux_munmap_args *);
int	linux_mprotect(struct thread *, struct linux_mprotect_args *);
int	linux_vhangup(struct thread *, struct linux_vhangup_args *);
int	linux_setgroups(struct thread *, struct linux_setgroups_args *);
int	linux_getgroups(struct thread *, struct linux_getgroups_args *);
int	osf1_setitimer(struct thread *, struct osf1_setitimer_args *);
int	linux_gethostname(struct thread *, struct linux_gethostname_args *);
int	linux_getdtablesize(struct thread *, struct linux_getdtablesize_args *);
int	linux_newfstat(struct thread *, struct linux_newfstat_args *);
int	linux_fcntl(struct thread *, struct linux_fcntl_args *);
int	osf1_select(struct thread *, struct osf1_select_args *);
int	osf1_socket(struct thread *, struct osf1_socket_args *);
int	linux_connect(struct thread *, struct linux_connect_args *);
int	linux_getpriority(struct thread *, struct linux_getpriority_args *);
int	osf1_sigreturn(struct thread *, struct osf1_sigreturn_args *);
int	osf1_sigsuspend(struct thread *, struct osf1_sigsuspend_args *);
int	linux_recvmsg(struct thread *, struct linux_recvmsg_args *);
int	linux_sendmsg(struct thread *, struct linux_sendmsg_args *);
int	osf1_gettimeofday(struct thread *, struct osf1_gettimeofday_args *);
int	osf1_getrusage(struct thread *, struct osf1_getrusage_args *);
int	linux_rename(struct thread *, struct linux_rename_args *);
int	linux_truncate(struct thread *, struct linux_truncate_args *);
int	osf1_sendto(struct thread *, struct osf1_sendto_args *);
int	linux_socketpair(struct thread *, struct linux_socketpair_args *);
int	linux_mkdir(struct thread *, struct linux_mkdir_args *);
int	linux_rmdir(struct thread *, struct linux_rmdir_args *);
int	linux_getrlimit(struct thread *, struct linux_getrlimit_args *);
int	linux_setrlimit(struct thread *, struct linux_setrlimit_args *);
int	linux_quotactl(struct thread *, struct linux_quotactl_args *);
int	osf1_sigaction(struct thread *, struct osf1_sigaction_args *);
int	linux_msgctl(struct thread *, struct linux_msgctl_args *);
int	linux_msgget(struct thread *, struct linux_msgget_args *);
int	linux_msgrcv(struct thread *, struct linux_msgrcv_args *);
int	linux_msgsnd(struct thread *, struct linux_msgsnd_args *);
int	linux_semctl(struct thread *, struct linux_semctl_args *);
int	linux_semget(struct thread *, struct linux_semget_args *);
int	linux_semop(struct thread *, struct linux_semop_args *);
int	linux_lchown(struct thread *, struct linux_lchown_args *);
int	linux_shmat(struct thread *, struct linux_shmat_args *);
int	linux_shmctl(struct thread *, struct linux_shmctl_args *);
int	linux_shmdt(struct thread *, struct linux_shmdt_args *);
int	linux_shmget(struct thread *, struct linux_shmget_args *);
int	linux_msync(struct thread *, struct linux_msync_args *);
int	linux_getsid(struct thread *, struct linux_getsid_args *);
int	linux_sigaltstack(struct thread *, struct linux_sigaltstack_args *);
int	osf1_sysinfo(struct thread *, struct osf1_sysinfo_args *);
int	linux_sysfs(struct thread *, struct linux_sysfs_args *);
int	osf1_getsysinfo(struct thread *, struct osf1_getsysinfo_args *);
int	osf1_setsysinfo(struct thread *, struct osf1_setsysinfo_args *);
int	linux_bdflush(struct thread *, struct linux_bdflush_args *);
int	linux_sethae(struct thread *, struct linux_sethae_args *);
int	linux_mount(struct thread *, struct linux_mount_args *);
int	linux_old_adjtimex(struct thread *, struct linux_old_adjtimex_args *);
int	linux_swapoff(struct thread *, struct linux_swapoff_args *);
int	linux_getdents(struct thread *, struct linux_getdents_args *);
int	linux_create_module(struct thread *, struct linux_create_module_args *);
int	linux_init_module(struct thread *, struct linux_init_module_args *);
int	linux_delete_module(struct thread *, struct linux_delete_module_args *);
int	linux_get_kernel_syms(struct thread *, struct linux_get_kernel_syms_args *);
int	linux_syslog(struct thread *, struct linux_syslog_args *);
int	linux_reboot(struct thread *, struct linux_reboot_args *);
int	linux_clone(struct thread *, struct linux_clone_args *);
int	linux_uselib(struct thread *, struct linux_uselib_args *);
int	linux_sysinfo(struct thread *, struct linux_sysinfo_args *);
int	linux_sysctl(struct thread *, struct linux_sysctl_args *);
int	linux_oldumount(struct thread *, struct linux_oldumount_args *);
int	linux_times(struct thread *, struct linux_times_args *);
int	linux_personality(struct thread *, struct linux_personality_args *);
int	linux_setfsuid(struct thread *, struct linux_setfsuid_args *);
int	linux_setfsgid(struct thread *, struct linux_setfsgid_args *);
int	linux_ustat(struct thread *, struct linux_ustat_args *);
int	linux_statfs(struct thread *, struct linux_statfs_args *);
int	linux_fstatfs(struct thread *, struct linux_fstatfs_args *);
int	linux_sched_setscheduler(struct thread *, struct linux_sched_setscheduler_args *);
int	linux_sched_getscheduler(struct thread *, struct linux_sched_getscheduler_args *);
int	linux_sched_get_priority_max(struct thread *, struct linux_sched_get_priority_max_args *);
int	linux_sched_get_priority_min(struct thread *, struct linux_sched_get_priority_min_args *);
int	linux_newuname(struct thread *, struct linux_newuname_args *);
int	linux_mremap(struct thread *, struct linux_mremap_args *);
int	linux_nfsservctl(struct thread *, struct linux_nfsservctl_args *);
int	linux_pciconfig_read(struct thread *, struct linux_pciconfig_read_args *);
int	linux_pciconfig_write(struct thread *, struct linux_pciconfig_write_args *);
int	linux_query_module(struct thread *, struct linux_query_module_args *);
int	linux_prctl(struct thread *, struct linux_prctl_args *);
int	linux_pread(struct thread *, struct linux_pread_args *);
int	linux_pwrite(struct thread *, struct linux_pwrite_args *);
int	linux_rt_sigreturn(struct thread *, struct linux_rt_sigreturn_args *);
int	linux_rt_sigaction(struct thread *, struct linux_rt_sigaction_args *);
int	linux_rt_sigprocmask(struct thread *, struct linux_rt_sigprocmask_args *);
int	linux_rt_sigpending(struct thread *, struct linux_rt_sigpending_args *);
int	linux_rt_sigtimedwait(struct thread *, struct linux_rt_sigtimedwait_args *);
int	linux_rt_sigqueueinfo(struct thread *, struct linux_rt_sigqueueinfo_args *);
int	linux_rt_sigsuspend(struct thread *, struct linux_rt_sigsuspend_args *);
int	linux_select(struct thread *, struct linux_select_args *);
int	linux_getitimer(struct thread *, struct linux_getitimer_args *);
int	linux_setitimer(struct thread *, struct linux_setitimer_args *);
int	linux_utimes(struct thread *, struct linux_utimes_args *);
int	linux_wait4(struct thread *, struct linux_wait4_args *);
int	linux_adjtimex(struct thread *, struct linux_adjtimex_args *);
int	linux_getcwd(struct thread *, struct linux_getcwd_args *);
int	linux_capget(struct thread *, struct linux_capget_args *);
int	linux_capset(struct thread *, struct linux_capset_args *);
int	linux_sendfile(struct thread *, struct linux_sendfile_args *);
int	linux_pivot_root(struct thread *, struct linux_pivot_root_args *);
int	linux_mincore(struct thread *, struct linux_mincore_args *);
int	linux_pciconfig_iobase(struct thread *, struct linux_pciconfig_iobase_args *);
int	linux_getdents64(struct thread *, struct linux_getdents64_args *);

#ifdef COMPAT_43

#define	nosys	linux_nosys

#endif /* COMPAT_43 */


#ifdef COMPAT_FREEBSD4

#define	nosys	linux_nosys

#endif /* COMPAT_FREEBSD4 */

#undef PAD_
#undef PADL_
#undef PADR_

#endif /* !_LINUX_SYSPROTO_H_ */
