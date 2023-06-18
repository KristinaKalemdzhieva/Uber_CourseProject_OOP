#include "ClientCommand1.h"

ClientCommand1::ClientCommand1(const Address& address, const Address& destination)
	: address(address), destination(destination)
{

}

bool ClientCommand1::execute(std::ostream& os, Client* client, Vector<User*>& users, Vector<Order*>& orders)
{
	orders.pushBack(client->orderTaxi(address, destination));

	double minDistance = DBL_MAX;
	int userId = -1;

	for (int i = 0; i < users.getSize(); ++i)
	{
		if (users[i]->getUserType() == UserType::Driver) 
		{
			if (minDistance > static_cast<Driver*>(users[i])->getDistance(orders[orders.getSize() - 1]->getAddress()) && !static_cast<Driver*>(users[i])->isTaken())
			{
				if (orders[orders.getSize() - 1]->getDriver() != static_cast<Driver*>(users[i]))
				{
					minDistance = static_cast<Driver*>(users[i])->getDistance(orders[orders.getSize() - 1]->getAddress());
					userId = i;
				}
			}
		}
	}

	if (userId < 0)
	{
		std::cout << "No available drivers!" << std::endl << std::endl;
	}
	else
	{
		orders[orders.getSize() - 1]->askDriver(static_cast<Driver*>(users[userId]));
	}

	return false;
}
