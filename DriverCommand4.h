#pragma once
#include "DriverCommand.h"

class DriverCommand4 : public DriverCommand
{
	unsigned id;

public:
	DriverCommand4(const unsigned id);
	bool execute(std::ostream& os, Driver* driver, System* system) override;
};
