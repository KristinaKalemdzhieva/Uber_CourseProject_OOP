#pragma once
#include "Message.h"

class PaymentMessage : public Message
{
	double amount;

public:
	PaymentMessage(const unsigned orderId, const double amount);
	void printMessage() const override;
};