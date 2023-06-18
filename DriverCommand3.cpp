#include "DriverCommand3.h"

DriverCommand3::DriverCommand3(const unsigned id, const unsigned messageNumber, const unsigned minutes)
	: id(id), messageNumber(messageNumber), minutes(minutes)
{

}

bool DriverCommand3::execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	driver->acceptOrder(id, messageNumber);
	orders[id - 1]->setDriver(driver);
	orders[id - 1]->setArrivalTime(minutes);

	return false;
}