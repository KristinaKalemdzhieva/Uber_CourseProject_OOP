#pragma once
#include <iostream>
#include "System.h"

class Command
{
public:
	virtual bool execute(std::ostream& os, System* system) = 0;
	virtual ~Command() = default;
};