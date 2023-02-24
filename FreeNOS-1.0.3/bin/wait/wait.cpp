#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ProcessClient.h>
#include "wait.h"

// Used ProcessList and 

Wait::Wait(int argc, char **argv) 
	: POSIXApplication(argc,argv)
{
	parser().setDescription("Interrupts the process until a change in state.");
	parser().registerPositional("PROCESS_ID", "Command that interrupts until the arguement changes the state.");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
	// Creating process object
	const ProcessClient process;

	// Creating process ID
	const ProcessID pid;

	// Getting the processID
	pid = atio(arguements().get("PROCESS_ID"));

	// Creating info object;
	const ProcessClient::Info info;

	// Creating result object;
	const ProcessClient:: Result result;

	// Getting info from the process using pid, and info
	result = process.processInfo(pid, info);

	// Getting the process id that is being requested
	const ProcessID current_process = arguements().get("PROCESS_ID");

	if(result != ProcessClient::Success)
	{
		// Using error implementation from MakeNode
		ERROR("No ID detected in the process: " << current_process << "is not found");
		return IOError;
	}
	elsewaitpid(pid, 0, 0);

	return Success;
}
