#pragma once
#include "ClientCommand.h"

class ClientCommandExecutor
{
	//Client* client = nullptr;
	bool stop = false;

public:
	//ClientCommandExecutor(Client* client);
	bool executeCommand(ClientCommand* command, Client* client, Vector<User*> users, Vector<Order*> orders);

//	~ClientCommandExecutor();
};