#include "DriverCommand3.h"

DriverCommand3::DriverCommand3(const unsigned id, const unsigned minutes, System* system) : id(id), minutes(minutes), system(system)
{

}

void DriverCommand3::execute(std::ostream& os, Driver* driver)
{
	//driver->acceptOrder(id, minutes, system);
}