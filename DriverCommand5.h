#pragma once
#include "DriverCommand.h"

//Finish order 
class DriverCommand5 : public DriverCommand
{
	unsigned id;

public:
	DriverCommand5(const unsigned id);
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};