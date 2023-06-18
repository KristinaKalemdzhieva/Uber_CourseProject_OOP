#include "DriverCommand5.h"

DriverCommand5::DriverCommand5(const unsigned id) : id(id)
{

}

bool DriverCommand5::execute(std::ostream& os, Driver* driver, Vector<User*>& users, Vector<Order*>& orders)
{
	try
	{
		driver->finishOrder(id, orders[id]->getDestination());
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}

	orders[id]->changeOrderStatus(OrderStatus::Finished);

	return false;
}