#include <FreeNOS/User.h>
#include "sys/renice.h"
#include "sys/types.h"
#include <errno.h>

//Copied the same pid as the wait command in libposix

pid_t renicepid(pid_t pid, u8 priority, int *stat_loc, int options)
{
	const ulong result = (ulong) ProcessCtl(pid, RenicePID, priority);

	switch((const API::Result) (result &0xffff))
	{
		case API::NotFound:
			errno = ESRCH;
			return (pid_t) -1;
		case API::Success:
			if(stat_loc)
			{
				*stat_loc = result >> 16;
			}
			return pid;
		default:
			errno = EIO;
			return (pid_t) -1;
	}
}

