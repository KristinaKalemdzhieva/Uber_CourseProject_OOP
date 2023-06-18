#include "Driver.h"

Driver::Driver(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, const MyString& carNumber, const unsigned phoneNumber)
	: User(username, password, firstName, lastName, UserType::Driver), carNumber(carNumber), phoneNumber(phoneNumber)
{
	ratingsCount = 0;
	ratingsSum = 0;
	taken = false;
}

const unsigned Driver::getPhoneNumber() const
{
	return phoneNumber;
}

const MyString& Driver::getCarNumber() const
{
	return carNumber;
}

const size_t Driver::getRating() const
{
	if (ratingsSum == 0 || ratingsCount == 0)
	{
		return 0;
	}

	return ratingsSum / ratingsCount;
}

const double Driver::getDistance(const Address& other) const
{
	return address.getDist(other);
}

void Driver::setRating(const unsigned short rating)
{
	if (rating > 6)
	{
		throw std::out_of_range("Invalid rating!");
	}

	ratingsSum += rating;
	++ratingsCount;
}

void Driver::addMessage(Message* message)
{
	messages.pushBack(message);
}

bool Driver::isTaken() const
{
	return taken;
}

void Driver::setIfTakenOrNot(bool status)
{
	taken = status;
}

void Driver::changeAddress(const Address& newAddress)
{
	address.changeAddress(newAddress);
}

void Driver::checkMessages() const
{
	if (messages.getSize() <= 0)
	{
		throw std::exception("No messages!");
	}

	for (size_t i = 0; i < messages.getSize(); ++i)
	{
		std::cout << "Message " << (i + 1) << ":" << std::endl;
		messages[i]->printMessage();
	}
}

void Driver::acceptOrder(const unsigned orderId, const unsigned messageId)
{
	this->orderId = orderId;
	taken = true;

	try
	{
		messages.popAt(messageId - 1);
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
}

void Driver::declineOrder(const unsigned messageId)
{
	try
	{
		messages.popAt(messageId - 1);
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
}

void Driver::finishOrder(const unsigned id, const Address& destination)
{
	if (id != orderId)
	{
		throw std::invalid_argument("Incorrect id!");
	}

	taken = false;
	address.changeAddress(destination);
}

void Driver::acceptPayment(const unsigned id, const unsigned messageId, const double amount)
{
	if (id != orderId)
	{
		throw std::invalid_argument("Incorrect id!");
	}

	account += amount;

	try
	{
		messages.popAt(messageId - 1);
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl << std::endl;
	}
}