#pragma once
#include "ClientCommand.h"

//Order taxi
class ClientCommand1 : public ClientCommand
{
	Address address;
	Address destination;

public:
	ClientCommand1(const Address& address, const Address& destination);
	bool execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders) override;
};