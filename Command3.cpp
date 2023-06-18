#include "Command3.h"

bool Command3::execute(std::ostream& os, System* system)
{
	try
	{
		system->saveInfoInFile();
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	
	return true;
}