#pragma once
#include "ClientCommand.h"

class ClientCommand4 : public ClientCommand
{
	unsigned id;
	double amount;

public:
	ClientCommand4(const unsigned id, const double amount);
	void execute(std::ostream& os, Client* client) override;
};