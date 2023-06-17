#include "PaymentMessage.h"

PaymentMessage::PaymentMessage(const unsigned orderId, const double amount)
	: Message(orderId), amount(amount)
{

}

void PaymentMessage::printMessage() const
{
	std::cout << "Order ID: " << orderId << std::endl;
	std::cout << "Payment: " << amount << std::endl << std::endl;
}