/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sys/syscalls.h"
#include "dirent.h"

extern int sysint(unsigned int eax, unsigned int ebx, unsigned int ecx, unsigned int edx, unsigned int esi);

void _exit(int status)
{
    sysint(SYSINT_EXIT, *((unsigned int*)&status), 0, 0, 0);
}

int close(int file)
{
    return sysint(SYSINT_CLOSE, *((unsigned int*)&file), 0, 0, 0);
}

extern char **environ; /* pointer to array of char * strings that define the current environment variables */

int execve(char *name, char **argv, char **env)
{
  return sysint(SYSINT_EXECVE, (unsigned int)name, (unsigned int)argv, (unsigned int)env, 0);
}

int fork()
{
    return sysint(SYSINT_FORK, 0, 0, 0, 0);
}

int fstat(int file, struct stat *st)
{
    return sysint(SYSINT_FSTAT, *(unsigned int*)&file, (unsigned int)st, 0, 0);
}

int getpid()
{
    return sysint(SYSINT_GETPID, 0, 0, 0, 0);
}

int isatty(int file)
{
    return sysint(SYSINT_ISATTY, *((unsigned int*)&file), 0, 0, 0);
}

int kill(int pid, int sig)
{
    return sysint(SYSINT_KILL, *((unsigned int*)&pid), *((unsigned int*)&sig), 0, 0);
}

int link(char *old, char *new)
{
    return sysint(SYSINT_LINK, (unsigned int)old, (unsigned int)new, 0, 0);
}

int lseek(int file, int ptr, int dir)
{
    return sysint(SYSINT_LSEEK, *((unsigned int*)&file), (unsigned int)ptr, *((unsigned int*)&dir), 0);
}

int open(const char *name, int flags, ...)
{
    return sysint(SYSINT_OPEN, (unsigned int)name, *((unsigned int*)&flags), 0, 0);
}

int read(int file, char *ptr, int len)
{
    return sysint(SYSINT_READ, *((unsigned int*)&file), (unsigned int)ptr, *((unsigned int*)&len), 0);
}

caddr_t sbrk(int incr)
{
    int result = sysint(SYSINT_SBRK, *((unsigned int*)&incr), 0, 0, 0);
    return *(caddr_t*)(&result);
}

int stat(const char *file, struct stat *st)
{
    int f = open(file, 0);
    int status = fstat(f, st);
    close(f);

    return status;
}

clock_t times(struct tms *buf)
{
    return sysint(SYSINT_TIMES, (unsigned int)buf, 0, 0, 0);
}

int unlink(char *name)
{
    return sysint(SYSINT_UNLINK, (unsigned int)name, 0, 0, 0);
}

int wait(int *status)
{
  return sysint(SYSINT_WAIT, (unsigned int)status, 0, 0, 0);
}

int write(int file, char *ptr, int len)
{
    return sysint(SYSINT_WRITE, *((unsigned int*)&file), (unsigned int)ptr, *((unsigned int*)&len), 0);
}

int pipe(int pipefd[2])
{
    return sysint(SYSINT_PIPE, (unsigned int)pipefd, 0, 0, 0);
}

int dup(int filedes)
{
    return sysint(SYSINT_DUP, (unsigned int)filedes, 0, 0, 0);
}

int dup2(int filedes, int filedes2)
{
    return sysint(SYSINT_DUP2, *((unsigned int*)&filedes), *((unsigned int*)&filedes2), 0, 0);
}

int _readdir(int filedes, struct dirent* dirent)
{
    return sysint(SYSINT_READDIR, *((unsigned int*)&filedes), *((unsigned int*)&dirent), 0, 0);
}


char *getcwd(char *buf, size_t size)
{
    return sysint(SYSINT_GETWD, (unsigned int*) buf, *((unsigned int*)&size), 0, 0);
}

int chdir(const char *path)
{
    return sysint(SYSINT_CHDIR, (unsigned int*) path, 0, 0, 0);
}

DIR* opendir(const char *dirname)
{
    DIR* dir = malloc(sizeof(DIR));
    if (dir == NULL) {
        return NULL;
    }

    memset(dir, 0, sizeof(DIR));
    dir->fd = open(dirname, 0);

    return dir;
}

int closedir(DIR *dirp)
{
    if (dirp == NULL) {
        return -1;
    }

    close(dirp->fd);
    free(dirp);
    return 0;
}

struct dirent *readdir(DIR *dirp)
{
    if (dirp == NULL)
    {
        return NULL;
    }

    int result = _readdir(dirp->fd, &dirp->dirent);

    if (result == 0) {
        return &dirp->dirent;
    } else {
        return NULL;
    }
}

int usleep(useconds_t usec)
{
    unsigned int v = usec;
    return sysint(SYSINT_USLEEP, v, 0, 0, 0);   
}

unsigned int sleep(unsigned int seconds)
{
    return usleep(seconds*1000000);
}

int access(const char *pathname, int mode)
{
    return sysint(SYSINT_ACCESS, (unsigned int*) pathname, mode, 0, 0);
}