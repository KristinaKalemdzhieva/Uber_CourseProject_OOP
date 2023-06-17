#pragma once
#include "Vector.hpp"
#include "Client.h"
#include "Driver.h"
#include "Order.h"

class System
{
	double totalProfit;

	Vector<User*> users;
	Vector<Order*> orders;

public:
	void registerUser(User* user);
	void login(const MyString& username, const MyString& password);
};