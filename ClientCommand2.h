#pragma once
#include "ClientCommand.h"

//Check order
class ClientCommand2 : public ClientCommand
{
	unsigned id;

public:
	ClientCommand2(const unsigned id);
	bool execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders) override;
};