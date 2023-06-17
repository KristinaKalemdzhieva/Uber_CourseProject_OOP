#pragma once
#include "DriverCommand.h"
#include "Address.h"

class DriverCommand1 : public DriverCommand
{
	Address address;

public:
	DriverCommand1(const MyString& name, const int x, const int y);
	void execute(std::ostream& os, Driver* driver) override;
};
