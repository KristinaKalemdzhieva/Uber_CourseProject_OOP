#include "ClientCommandExecutor.h"

ClientCommandExecutor::ClientCommandExecutor(Client* client) : client(client)
{

}

void ClientCommandExecutor::executeCommand(ClientCommand* command)
{
	command->execute(std::cout, client);
}