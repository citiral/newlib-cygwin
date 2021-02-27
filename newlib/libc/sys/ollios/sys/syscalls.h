#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#define SYSINT_OPEN   1
#define SYSINT_CLOSE  2
#define SYSINT_WRITE  3
#define SYSINT_READ   4
#define SYSINT_EXIT   5
#define SYSINT_FORK   6
#define SYSINT_GETPID 7
#define SYSINT_EXECVE 8
#define SYSINT_WAIT   9
#define SYSINT_ISATTY 10
#define SYSINT_LSEEK  11
#define SYSINT_FSTAT  12
#define SYSINT_KILL   13
#define SYSINT_LINK   14
#define SYSINT_SBRK   15
#define SYSINT_TIMES  16
#define SYSINT_UNLINK 17
#define SYSINT_PIPE   18
#define SYSINT_DUP    19
#define SYSINT_DUP2   20
#define SYSINT_READDIR 21
#define SYSINT_GETWD  22

#endif