#pragma once
#include "ClientCommand.h"

class ClientCommand5 : public ClientCommand
{
	MyString firstName;
	MyString lastName;
	unsigned short rating;

public:
	ClientCommand5(const MyString& firstName, const MyString& lastName, const unsigned short rating);
	bool execute(std::ostream& os, Client* client, Vector<User*> users, Vector<Order*> orders) override;
};