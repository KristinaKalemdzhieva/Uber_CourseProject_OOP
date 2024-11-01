#include "ClientCommandExecutor.h"

bool ClientCommandExecutor::executeCommand(ClientCommand* command, Client* client, Vector<User*>& users, Vector<Order*>& orders)
{
	stop = command->execute(std::cout, client, users, orders);

	return stop;
}