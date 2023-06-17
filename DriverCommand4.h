#pragma once
#include "DriverCommand.h"
#include "System.h";

class DriverCommand4 : public DriverCommand
{
	System* system;
	unsigned id;

public:
	DriverCommand4(const unsigned id, System* system);
	void execute(std::ostream& os, Driver* driver) override;
};
