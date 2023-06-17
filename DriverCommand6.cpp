#include "DriverCommand6.h"

DriverCommand6::DriverCommand6(const unsigned id, const double amount) : id(id), amount(amount)
{

}

void DriverCommand6::execute(std::ostream& os, Driver* driver)
{
	//driver->acceptPayment(id, amount);
}