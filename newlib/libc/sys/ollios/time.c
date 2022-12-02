#include "sys/syscalls.h"
#include <stdint.h>
#include <time.h>

int _get_cmos_utc(cmos_time_t *ct)
{
    return sysint(SYSINT_GET_CMOS_UTC, ct, 0, 0, 0);
}