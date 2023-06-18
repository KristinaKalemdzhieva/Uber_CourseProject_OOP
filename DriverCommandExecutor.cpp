#include "DriverCommandExecutor.h"

bool DriverCommandExecutor::executeCommand(DriverCommand* command, Driver* driver, System* system)
{
	stop = command->execute(std::cout, driver, system);

	return stop;
}