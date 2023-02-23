#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wait.h"

Wait::Wait(int argc, char **argv) 
	: POSIXApplication(argc,argv)
{
	parser().setDescription();
	parser().registerPositional;
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
	return Success;
}
