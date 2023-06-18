#include "Command3.h"

bool Command3::execute(std::ostream& os, System* system)
{
	system->saveInfoInFile();
	return true;
}