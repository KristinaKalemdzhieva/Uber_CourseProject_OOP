#include "ClientCommand3.h"

ClientCommand3::ClientCommand3(const unsigned id) : id(id)
{

}

void ClientCommand3::execute(std::ostream& os, Client* client)
{
	client->cancelOrder(id);
}