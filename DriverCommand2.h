#pragma once
#include "DriverCommand.h"

//Check messages
class DriverCommand2 : public DriverCommand
{
public:
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};
