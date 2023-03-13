#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>

// Used ProcessList and 

Renice::Renice(int argc, char **argv) 
	: POSIXApplication(argc,argv)
{
	parser().setDescription("Changes the priority of a running process");
	parser().registerFlag('n', "priority", "change priority level");
	parser().registerPositional("PRIORITY", "The desired priority level to set the process to");
	parser().registerPositional("PROCESS_ID", "ID of the process to change priority of");
}

Renice::~Renice()
{
}

Renice::Result Renice::exec()
{
	if(arguments().get("priority"))
	{
		const ProcessClient process;
		ProcessClient::Info info;
		int priority = (atoi(arguments().get("PRIORITY")));
		ProcessID pid = (atoi(arguments().get("PROCESS_ID")));

		const ProcessClient::Result result = process.processInfo(pid, info);
		
		if(result != ProcessClient::Success)
		{
			ERROR("The process with ID" << pid << " does not exist!");
			return InvalidArgument;
		}

		if(priority < 1 || priority > 5)
		{
			ERROR("The priority level must be between 1 and 5!");
			return InvalidArgument;
		}

		printf("The process of ID %d has been set to priority level %d.", pid, priority);

	}

	return Success;
}
