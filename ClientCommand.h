#pragma once
#include <iostream>
#include "Client.h"
#include "Vector.hpp"

class ClientCommand
{
public:
	virtual bool execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders) = 0;
	virtual ~ClientCommand() = default;
};