#pragma once
#include "DriverCommand.h"

class DriverCommand3 : public DriverCommand
{
	unsigned id;
	unsigned minutes;

public:
	DriverCommand3(const unsigned id, const unsigned minutes);
	bool execute(std::ostream& os, Driver* driver, System* system) override;
};