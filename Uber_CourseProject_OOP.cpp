#include <iostream>
#include "CommandExecutor.h"
#include "CommandFactory.h"

int main()
{
	CommandExecutor ex;

	while (!ex.executeCommand(CommandFactory::getInstance().getCommand())) {}

	return 0;
}
