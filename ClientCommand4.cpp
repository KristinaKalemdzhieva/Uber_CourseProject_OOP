#include "ClientCommand4.h"

ClientCommand4::ClientCommand4(const unsigned id, const double amount) : id(id), amount(amount)
{

}

bool ClientCommand4::execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders)
{
	client->pay(id, amount);

	return false;
}