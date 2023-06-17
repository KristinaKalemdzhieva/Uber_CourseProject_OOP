#include "ClientCommand6.h"

ClientCommand6::ClientCommand6(const double amount) : amount(amount)
{

}

void ClientCommand6::execute(std::ostream& os, Client* client)
{
	client->addMoney(amount);
}