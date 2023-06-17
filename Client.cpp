#include "Client.h"

Client::Client(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName)
	: User(username, password, firstName, lastName, UserType::Client)
{

}

void Client::orderTaxi(const Address& address, const Address& destination)
{
	//make connection with the system and find the nearest driver
	order = new Order(address, destination);

	std::cout << "Order ID: " << order->getId() << std::endl << std::endl;
}

void Client::checkOrder(const unsigned id)
{
	if (order->getId() != id)
	{
		throw std::invalid_argument("Incorrect id!");
	}

	order->check();
}

void Client::cancelOrder(const unsigned id)
{
	if (order->getId() != id)
	{
		throw std::invalid_argument("Incorrect id!");
	}

	order->changeOrderStatus(OrderStatus::Cancelled);
}

void Client::pay(const unsigned id, const double amount)
{
	if (order->getId() != id)
	{
		throw std::invalid_argument("Incorrect id!");
	}
	else if (account < amount)
	{
		throw std::out_of_range("No enough money!");
	}

	account -= amount;
	order->payToDriver(amount);
}

void Client::rate(const MyString& firstName, const MyString& lastName, const unsigned short rating)
{
	if (firstName != order->getDriverFirstName() || lastName != order->getDriverLastName())
	{
		throw std::invalid_argument("Incorrect driver name!");
	}

	order->rateDriver(rating);
}

void Client::addMoney(const double amount)
{
	account += amount;
}

Client::~Client()
{
	delete order;
}