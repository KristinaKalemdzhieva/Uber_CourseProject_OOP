#pragma once
#include <iostream>
#include "Order.h"
#include "Vector.hpp"

class DriverCommand
{
public:
	virtual bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) = 0;
	virtual ~DriverCommand() = default;
};