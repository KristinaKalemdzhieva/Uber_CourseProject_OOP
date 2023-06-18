#pragma once
#include "DriverCommand.h"

//Accept payment
class DriverCommand6 : public DriverCommand
{
	unsigned id;
	double amount;
	unsigned messageId;

public:
	DriverCommand6(const unsigned id, const unsigned messageId, const double amount);
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};