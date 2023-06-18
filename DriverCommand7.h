#pragma once
#include "DriverCommand.h"

//Logout
class DriverCommand7 : public DriverCommand
{
public:
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};