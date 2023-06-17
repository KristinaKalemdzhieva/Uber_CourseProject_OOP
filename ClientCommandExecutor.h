#pragma once
#include "ClientCommand.h"

class ClientCommandExecutor
{
	Client* client;

public:
	ClientCommandExecutor(Client* client);
	void executeCommand(ClientCommand* command);
};