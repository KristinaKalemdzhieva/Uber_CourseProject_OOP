#include "DriverCommand4.h"

DriverCommand4::DriverCommand4(const unsigned id, const unsigned messageId) 
	: id(id), messageId(messageId)
{

}

bool DriverCommand4::execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	driver->declineOrder(messageId);

	double minDistance = DBL_MAX;
	int userId = -1;

	for (int i = 0; i < users.getSize(); ++i)
	{
		if (users[i]->getUserType() == UserType::Driver)
		{
			if (minDistance > static_cast<Driver*>(users[i])->getDistance(orders[id - 1]->getAddress()) && !static_cast<Driver*>(users[i])->isTaken())
			{
				if (orders[id - 1]->getDriver() != static_cast<Driver*>(users[i]))
				{
					minDistance = static_cast<Driver*>(users[i])->getDistance(orders[id - 1]->getAddress());
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
		orders[id - 1]->askDriver(static_cast<Driver*>(users[userId]));
	}

	return false;
}