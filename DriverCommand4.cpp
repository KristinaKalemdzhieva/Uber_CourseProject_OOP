#include "DriverCommand4.h"

DriverCommand4::DriverCommand4(const unsigned id) : id(id)
{

}

bool DriverCommand4::execute(std::ostream& os, Driver* driver, System* system)
{
	//driver->declineOrder(id, system);

	return false;
}

//DriverCommand4::~DriverCommand4()
//{
//	delete system;
//}