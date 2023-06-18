#pragma once
#include "DriverCommand.h"

class DriverCommandExecutor
{
	bool stop = false;

public:
	bool executeCommand(DriverCommand* command, Driver* driver, Vector<User*>& users, Vector<Order*>& orders);
};
