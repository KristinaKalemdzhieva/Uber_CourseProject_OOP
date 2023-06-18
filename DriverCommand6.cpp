#include "DriverCommand6.h"

DriverCommand6::DriverCommand6(const unsigned id, const double amount) : id(id), amount(amount)
{

}

bool DriverCommand6::execute(std::ostream& os, Driver* driver, System* system)
{
	//driver->acceptPayment(id, amount);
	return false;
}