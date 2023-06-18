#pragma once
#include "ClientCommand.h"

//order
class ClientCommand1 : public ClientCommand
{
//	System* system = nullptr;
	Address address;
	Address destination;

public:
	ClientCommand1(const Address& address, const Address& destination);
	bool execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders) override;

	//~ClientCommand1();
};