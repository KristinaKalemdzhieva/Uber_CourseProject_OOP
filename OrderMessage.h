#pragma once
#include "Message.h"
#include "MyString.h"

class OrderMessage : public Message
{
	MyString clientFirstName;
	MyString clientLastName;
	MyString addressName;
	MyString destinationName;

public:
	OrderMessage(const unsigned orderId, const MyString& clientFirstName, const MyString& clientLastName, const MyString& addressName, const MyString& destinationName);
	void printMessage() const override;
};