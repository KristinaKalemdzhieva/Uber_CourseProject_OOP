#pragma once
#include "Command.h"

//close app
class Command3 : public Command
{
public:
	bool execute(std::ostream& os, System* system) override;
};