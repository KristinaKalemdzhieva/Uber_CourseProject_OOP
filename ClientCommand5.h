#pragma once
#include "ClientCommand.h"

//Rate driver
class ClientCommand5 : public ClientCommand
{
	unsigned short rating;
	MyString firstName;
	MyString lastName;

public:
	ClientCommand5(const MyString& firstName, const MyString& lastName, const unsigned short rating);
	bool execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders) override;
};