#pragma once
#include "System.h"
#include "Command.h"

class CommandExecutor
{
	System* system;

public:
	CommandExecutor();
	void executeCommand(Command* command);

	~CommandExecutor();
};