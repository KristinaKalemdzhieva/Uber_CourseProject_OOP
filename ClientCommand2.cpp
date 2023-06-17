#include "ClientCommand2.h"

ClientCommand2::ClientCommand2(const unsigned id) : id(id)
{

}

void ClientCommand2::execute(std::ostream& os, Client* client)
{
	client->checkOrder(id);
}