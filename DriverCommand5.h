#pragma once
#include "DriverCommand.h"

class DriverCommand5 : public DriverCommand
{
	unsigned id;

public:
	DriverCommand5(const unsigned id);
	bool execute(std::ostream& os, Driver* driver, System* system) override;
};