#pragma once
#include <iostream>
#include "Driver.h"
#include "System.h"

class DriverCommand
{
public:
	virtual bool execute(std::ostream& os, Driver* driver, System* system) = 0;
	virtual ~DriverCommand() = default;
};