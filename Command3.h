#pragma once
#include "Command.h"

//Close app
class Command3 : public Command
{
public:
	bool execute(std::ostream& os, System* system) override;
};