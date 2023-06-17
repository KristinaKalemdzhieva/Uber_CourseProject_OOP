#pragma once
#include <iostream>

class Message
{
protected:
	unsigned orderId;
	
public:
	Message(const unsigned orderId) : orderId(orderId) {}

	virtual void printMessage() const = 0;
	virtual ~Message() = default;
};