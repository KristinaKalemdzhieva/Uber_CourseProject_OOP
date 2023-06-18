#pragma once
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"

class CommandFactory
{
	CommandFactory() = default;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;

public:
	Command* getCommand() const;
	static CommandFactory& getInstance();
};