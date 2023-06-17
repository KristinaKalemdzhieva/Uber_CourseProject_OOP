#include "Driver.h"

//da se izmisi koga da se trie veche izpylneno syobshtenie i kak da razberem koe pored vyv vektora

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
	for (size_t i = 0; i < messages.getSize(); ++i)
	{
		std::cout << "Message " << i << ":" << std::endl;
		messages[i]->printMessage();
	}
}