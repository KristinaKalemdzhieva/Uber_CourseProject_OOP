#include "DriverCommand2.h"

bool DriverCommand2::execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		driver->checkMessages();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
	
	return false;
}