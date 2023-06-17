#pragma once
#include "ClientCommand.h"

class ClientCommand6 : public ClientCommand
{
	double amount;

public:
	ClientCommand6(const double amount);
	void execute(std::ostream& os, Client* client) override;
};