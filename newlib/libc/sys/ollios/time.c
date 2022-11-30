#include "sys/syscalls.h"
#include <stdint.h>
#include <time.h>

typedef struct _cmos_time {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint8_t year;
} cmos_time_t;

int _get_cmos_utc(cmos_time_t *ct)
{
    return sysint(SYSINT_GET_CMOS_UTC, ct, 0, 0, 0);
}