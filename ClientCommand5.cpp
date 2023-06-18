#include "ClientCommand5.h"

ClientCommand5::ClientCommand5(const MyString& firstName, const MyString& lastName, const unsigned short rating)
	: firstName(firstName), lastName(lastName), rating(rating)
{

}

bool ClientCommand5::execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		client->rate(firstName, lastName, rating);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	return false;
}