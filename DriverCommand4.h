#pragma once
#include "DriverCommand.h"

//Decline order
class DriverCommand4 : public DriverCommand
{
	unsigned id;
	unsigned messageId;

public:
	DriverCommand4(const unsigned id, const unsigned messageId);
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};
