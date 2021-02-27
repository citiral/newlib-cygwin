#ifndef _SYS_DIRENT_H_
#define _SYS_DIRENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sys/reent.h"
#include "sys/types.h"

#define NAME_MAX 512

struct dirent {
    ino_t  d_ino;            // File serial number.
    char   d_name[NAME_MAX]; // Filename string of entry.
};

typedef struct __DIR {
    int fd;
    struct dirent dirent;
} DIR;

#ifdef __cplusplus
}
#endif


#endif