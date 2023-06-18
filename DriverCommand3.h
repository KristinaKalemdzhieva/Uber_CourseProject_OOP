#pragma once
#include "DriverCommand.h"

//Accept order
class DriverCommand3 : public DriverCommand
{
	unsigned id;
	unsigned minutes;
	unsigned messageNumber;

public:
	DriverCommand3(const unsigned id, const unsigned messageNumber, const unsigned minutes);
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};