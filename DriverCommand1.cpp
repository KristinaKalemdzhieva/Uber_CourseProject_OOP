#include "DriverCommand1.h"

DriverCommand1::DriverCommand1(const MyString& name, const int x, const int y) : address(name, x, y)
{

}

bool DriverCommand1::execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	driver->changeAddress(address);

	return false;
}