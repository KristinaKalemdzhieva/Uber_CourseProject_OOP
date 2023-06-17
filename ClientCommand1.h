#pragma once
#include "ClientCommand.h"
#include "System.h"

//order
class ClientCommand1 : public ClientCommand
{
	System* system;
	Address address;
	Address destination;

public:
	ClientCommand1(const Address& address, const Address& destination, System* system);
	void execute(std::ostream& os, Client* client) override;
};