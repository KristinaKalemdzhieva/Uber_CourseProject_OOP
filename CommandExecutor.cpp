#include "CommandExecutor.h"

CommandExecutor::CommandExecutor()
{
	system = new System();
}

void CommandExecutor::executeCommand(Command* command)
{
	command->execute(std::cout, system);
}

CommandExecutor::~CommandExecutor()
{
	delete system;
}