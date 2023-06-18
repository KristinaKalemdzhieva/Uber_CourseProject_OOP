#pragma once
#include "Command.h"

class CommandExecutor
{
	System* system = nullptr;
	bool stop = false;

public:
	CommandExecutor();
	bool executeCommand(Command* command);

	~CommandExecutor();
};