#pragma once
#include "ClientCommand.h"

class ClientCommandExecutor
{
	bool stop = false;

public:
	bool executeCommand(ClientCommand* command, Client* client, Vector<User*>& users, Vector<Order*>& orders);
};