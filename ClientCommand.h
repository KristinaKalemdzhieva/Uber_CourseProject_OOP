#pragma once
#include <iostream>
#include "Client.h"

class ClientCommand
{
public:
	virtual void execute(std::ostream& os, Client* client) = 0;
	virtual ~ClientCommand() = default;
};