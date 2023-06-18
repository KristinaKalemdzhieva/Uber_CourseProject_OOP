#pragma once
#include "DriverCommand.h"
//#include "System.h"

class DriverCommandExecutor
{
	bool stop = false;

public:
	bool executeCommand(DriverCommand* command, Driver* driver, System* system);
};
