#include "ClientCommand1.h"

ClientCommand1::ClientCommand1(const Address& address, const Address& destination)
	: address(address), destination(destination)
{

}

bool ClientCommand1::execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders)
{
	client->orderTaxi(address, destination);
	//system->addOrderAndFindDriver(client->getOrder(), client);

	return false;
}
