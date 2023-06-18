#pragma once
#include "DriverCommand.h"
#include "Address.h"

//Change address
class DriverCommand1 : public DriverCommand
{
	Address address;

public:
	DriverCommand1(const MyString& name, const int x, const int y);
	bool execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders) override;
};
