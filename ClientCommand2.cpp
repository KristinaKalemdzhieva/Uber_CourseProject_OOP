#include "ClientCommand2.h"

ClientCommand2::ClientCommand2(const unsigned id) : id(id)
{

}

bool ClientCommand2::execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		client->checkOrder(id);
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}

	return false;
}