#include "CommandExecutor.h"

CommandExecutor::CommandExecutor()
{
	system = new System();
}

bool CommandExecutor::executeCommand(Command* command)
{
	stop = command->execute(std::cout, system);

	return stop;
}

CommandExecutor::~CommandExecutor()
{
	delete system;
}