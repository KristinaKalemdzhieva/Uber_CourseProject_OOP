#pragma once
#include "ClientCommand.h"

//Logout
class ClientCommand7 : public ClientCommand
{
public:
	bool execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders) override;
};