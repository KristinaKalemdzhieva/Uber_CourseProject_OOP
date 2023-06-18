#include <iostream>
#include "CommandExecutor.h"
#include "CommandFactory.h"

int main()
{
   /* User adr("", "", "", "", UserType::Client);
    std::cout << sizeof(adr);*/

	CommandExecutor ex;

	while (!ex.executeCommand(CommandFactory::getInstance().getCommand())) {}

	return 0;
}
