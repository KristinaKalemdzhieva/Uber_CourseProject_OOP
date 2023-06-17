#pragma once
#include "DriverCommand.h"

class DriverCommandExecutor
{
	Driver* driver;

public:
	DriverCommandExecutor(Driver* driver);
	void executeCommand(DriverCommand* command);
};
