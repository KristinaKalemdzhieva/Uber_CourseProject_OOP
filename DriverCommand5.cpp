#include "DriverCommand5.h"

DriverCommand5::DriverCommand5(const unsigned id) : id(id)
{

}

bool DriverCommand5::execute(std::ostream& os, Driver* driver, System* system)
{
	//driver->finishOrder(id, system);

	return false;
}