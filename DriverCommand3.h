#pragma once
#include "DriverCommand.h"
#include "System.h"

class DriverCommand3 : public DriverCommand
{
	System* system;
	unsigned id;
	unsigned minutes;

public:
	DriverCommand3(const unsigned id, const unsigned minutes, System* system);
	void execute(std::ostream& os, Driver* driver) override;
};