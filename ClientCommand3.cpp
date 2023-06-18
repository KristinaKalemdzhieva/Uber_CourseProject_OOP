#include "ClientCommand3.h"

ClientCommand3::ClientCommand3(const unsigned id) : id(id)
{

}

bool ClientCommand3::execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		client->cancelOrder(id);
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}

	return false;
}