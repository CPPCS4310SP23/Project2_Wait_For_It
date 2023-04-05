#ifndef __LIBPOSIX_RENICE_H
#define __LIBPOSIX_RENICE_H

#include <Macros.h>
#include "types.h"

/**
 * @brief
 *
 * @param pid 
 * @param stat_loc
 * @param priority
 * @param options
 * @return
 */

extern C pid_t renicepid(pid_t pid, u8 priority, int*stat_loc, int options);

#endif /* __LIBPOSIX_RENICE_H */
