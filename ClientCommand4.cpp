#include "ClientCommand4.h"

ClientCommand4::ClientCommand4(const unsigned id, const double amount) : id(id), amount(amount)
{

}

bool ClientCommand4::execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		client->pay(id, amount);
	}
	catch(std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}

	return false;
}