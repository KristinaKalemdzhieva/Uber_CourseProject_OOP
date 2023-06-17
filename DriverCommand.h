#pragma once
#include <iostream>
#include "Driver.h"

class DriverCommand
{
public:
	virtual void execute(std::ostream& os, Driver* driver) = 0;
	virtual ~DriverCommand() = default;
};