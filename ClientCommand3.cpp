#include "ClientCommand3.h"

ClientCommand3::ClientCommand3(const unsigned id) : id(id)
{

}

bool ClientCommand3::execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders)
{
	client->cancelOrder(id);

	return false;
}