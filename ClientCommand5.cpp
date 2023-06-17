#include "ClientCommand5.h"

ClientCommand5::ClientCommand5(const MyString& firstName, const MyString& lastName, const unsigned short rating)
	: firstName(firstName), lastName(lastName), rating(rating)
{

}

void ClientCommand5::execute(std::ostream& os, Client* client)
{
	client->rate(firstName, lastName, rating);
}