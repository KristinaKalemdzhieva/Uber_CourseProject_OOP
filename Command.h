#pragma once
#include <iostream>
#include "System.h"

class Command
{
public:
	virtual void execute(std::ostream& os, System* system) = 0;
	virtual ~Command() = default;
};