#include "DriverCommand3.h"

DriverCommand3::DriverCommand3(const unsigned id, const unsigned minutes) 
	: id(id), minutes(minutes)
{

}

bool DriverCommand3::execute(std::ostream& os, Driver* driver, System* system)
{
	//driver->acceptOrder(id, minutes, system);

	return false;
}

//DriverCommand3::~DriverCommand3()
//{
//	delete system;
//}