#include "DriverCommand6.h"

DriverCommand6::DriverCommand6(const unsigned id, const unsigned messageId, const double amount) 
	: id(id), amount(amount), messageId(messageId)
{

}

bool DriverCommand6::execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		driver->acceptPayment(id, messageId, amount);
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}

	return false;
}