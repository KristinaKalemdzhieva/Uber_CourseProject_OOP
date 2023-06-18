#pragma once
#include "User.h"
#include "Address.h"
#include "Order.h"
#include "Message.h"

class Client : public User
{
	Order* order = nullptr;

public:
	Client(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName);

	Order* orderTaxi(const Address& address, const Address& destination);
	void checkOrder(const unsigned id);
	void cancelOrder(const unsigned id);
	void pay(const unsigned id, const double amount);
	void rate(const MyString& firstName, const MyString& lastName, const unsigned short rating);
	void addMoney(const double amount);

	~Client();
};