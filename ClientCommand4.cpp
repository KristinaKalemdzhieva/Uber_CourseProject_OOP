#include "ClientCommand4.h"

ClientCommand4::ClientCommand4(const unsigned id, const double amount) : id(id), amount(amount)
{

}

void ClientCommand4::execute(std::ostream& os, Client* client)
{
	client->pay(id, amount);
}