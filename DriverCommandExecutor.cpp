#include "DriverCommandExecutor.h"

DriverCommandExecutor::DriverCommandExecutor(Driver* driver) : driver(driver)
{

}

void DriverCommandExecutor::executeCommand(DriverCommand* command)
{
	command->execute(std::cout, driver);
}