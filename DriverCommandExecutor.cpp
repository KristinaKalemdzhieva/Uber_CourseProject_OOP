#include "DriverCommandExecutor.h"

bool DriverCommandExecutor::executeCommand(DriverCommand* command, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	stop = command->execute(std::cout, driver, users, orders);

	return stop;
}