#pragma once
#include "ClientCommand.h"

class ClientCommand6 : public ClientCommand
{
	double amount;

public:
	ClientCommand6(const double amount);
	bool execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders) override;
};