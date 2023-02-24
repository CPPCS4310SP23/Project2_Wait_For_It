#include "sys/wait.h"
#include <stdio.h>
#include <unistd.h>
#include "wait.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>

// Used ProcessList and 

Wait::Wait(int argc, char **argv) 
	: POSIXApplication(argc,argv)
{
	parser().setDescription("Interrupts current execution until a child process specified by PROCESS_ID has changed state");
	parser().registerPositional("PROCESS_ID", "ID of the child process to wait for");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
	// Creating process object
	const ProcessClient process;

	// Creating process ID
	const ProcessID pid = (atoi(arguments().get("PROCESS_ID")));

	// Creating info object;
	ProcessClient::Info info;

	// Getting info from the process using pid, and info
	const ProcessClient:: Result result = process.processInfo(pid, info);
	
	// Getting the process id that is being requested
	const char* current_process = arguments().get("PROCESS_ID");

	if(result == ProcessClient::Success)
		waitpid(pid, 0, 0);
	else
	{
		// Using error implementation from MakeNode
		ERROR("The process with ID " << current_process << " does not exist!");
		return IOError;
	}

	return Success;
}
