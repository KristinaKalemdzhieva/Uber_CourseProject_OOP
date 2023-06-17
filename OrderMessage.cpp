#include "OrderMessage.h"

OrderMessage::OrderMessage(const unsigned orderId, const MyString& clientFirstName, const MyString& clientLastName, const MyString& addressName, const MyString& destinationName)
	: Message(orderId), clientFirstName(clientFirstName), clientLastName(clientLastName), addressName(addressName), destinationName(destinationName)
{

}

void OrderMessage::printMessage() const
{
	std::cout << "Order ID: " << orderId << std::endl;
	std::cout << "Client : " << clientFirstName << " " << clientLastName << std::endl;
	std::cout << "From: " << addressName << std::endl;
	std::cout << "To: " << destinationName << std::endl << std::endl;
}