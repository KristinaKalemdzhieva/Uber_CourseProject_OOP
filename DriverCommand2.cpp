#include "DriverCommand2.h"

bool DriverCommand2::execute(std::ostream& os, Driver* driver, System* system)
{
	driver->checkMessages();
	return false;
}