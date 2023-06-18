#include "Order.h"

unsigned Order::ID = 1;

Order::Order(const Address& address, const Address& destination)
	: address(address), destination(destination)
{
	status = OrderStatus::NotAccepted;
	arrivalTime = 0;
	id = ID;
	++ID;
}

void Order::setArrivalTime(const unsigned arrivalTime)
{
	this->arrivalTime = arrivalTime;
}

void Order::setMessage(Message* message)
{
	this->message = message;
}

void Order::askDriver(Driver* driver)
{
	this->driver = driver;
	driver->addMessage(message);
}

void Order::setDriver(Driver* driver)
{
	this->driver = driver;
	this->driver->setIfTakenOrNot(true);
	status = OrderStatus::Accepted;
}

const unsigned Order::getId() const
{
	return id;
}

Driver* Order::getDriver() const
{
	return driver;
}

const MyString& Order::getDriverFirstName() const
{
	return driver->getFirstName();
}

const MyString& Order::getDriverLastName() const
{
	return driver->getLastName();
}

const MyString& Order::getAddressName() const
{
	return address.getName();
}

const MyString& Order::getDistanceName() const
{
	return destination.getName();
}

const Address& Order::getAddress() const
{
	return address;
}

const Address& Order::getDestination() const
{
	return destination;
}

void Order::check() const
{
	if (status == OrderStatus::Finished || status == OrderStatus::Cancelled)
	{
		throw std::invalid_argument("No such order!");
	}
	else if (status == OrderStatus::NotAccepted)
	{
		std::cout << "Your order has not been accepted yet." << std::endl;
		return;
	}

	std::cout << "Driver: " << driver->getFirstName() << " " << driver->getLastName() << std::endl;
	std::cout << "Phone number: " << driver->getPhoneNumber() << std::endl;
	std::cout << "Car number: " << driver->getCarNumber() << std::endl;
	std::cout << "Rating: " << driver->getRating() << std::endl;
	std::cout << "Arrival time: " << arrivalTime << " minutes" << std::endl << std::endl;
}

void Order::payToDriver(const double amount)
{
	message = new PaymentMessage(id, amount);
	driver->addMessage(message);
}

void Order::rateDriver(const unsigned short rating)
{
	driver->setRating(rating);
}

void Order::changeOrderStatus(OrderStatus newStatus)
{
	//add switch for the different cases and the following consequences for the driver from them
	status = newStatus;
}

OrderStatus Order::getOrderStatus() const
{
	return status;
}

Order::~Order()
{
	delete driver;
	delete message;
}