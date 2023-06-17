#include "ClientCommand1.h"

ClientCommand1::ClientCommand1(const Address& address, const Address& destination, System* system)
	: address(address), destination(destination), system(system)
{

}

void ClientCommand1::execute(std::ostream& os, Client* client)
{
	client->orderTaxi(address, destination);
	//system->addOrderAndFindDriver(client->getOrder(), client);
}