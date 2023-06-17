#pragma once
#include "DriverCommand.h"

class DriverCommand6 : public DriverCommand
{
	unsigned id;
	double amount;

public:
	DriverCommand6(const unsigned id, const double amount);
	void execute(std::ostream& os, Driver* driver) override;
};