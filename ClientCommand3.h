#pragma once
#include "ClientCommand.h"

//Cancel order
class ClientCommand3 : public ClientCommand
{
	unsigned id;

public:
	ClientCommand3(const unsigned id);
	bool execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders) override;
};