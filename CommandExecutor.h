#pragma once
#include "Command.h"

class CommandExecutor
{
	bool stop = false;
	System* system = nullptr;

public:
	CommandExecutor();
	bool executeCommand(Command* command);

	~CommandExecutor();
};