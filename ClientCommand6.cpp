#include "ClientCommand6.h"

ClientCommand6::ClientCommand6(const double amount) : amount(amount)
{

}

bool ClientCommand6::execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders)
{
	client->addMoney(amount);

	return false;
}