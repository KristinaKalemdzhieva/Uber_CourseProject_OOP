#pragma once
#include "ClientCommand.h"

class ClientCommand4 : public ClientCommand
{
	unsigned id;
	double amount;

public:
	ClientCommand4(const unsigned id, const double amount);
	bool execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders) override;
};