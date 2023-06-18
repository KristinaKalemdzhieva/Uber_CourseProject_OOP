#pragma once
#include "DriverCommand.h"

class DriverCommand7 : public DriverCommand
{
public:
	bool execute(std::ostream& os, Driver* driver, System* system) override;
};