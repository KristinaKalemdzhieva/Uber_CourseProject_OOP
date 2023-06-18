#pragma once
#include <fstream>
#include "Vector.hpp"
#include "Order.h"
#include "ClientCommandExecutor.h"
#include "ClientCommandFactory.h"
#include "DriverCommandExecutor.h"
#include "DriverCommandFactory.h"

class System
{
	double totalProfit = 0;

	Vector<User*> users;
	Vector<Order*> orders;

public:
	System();

	void registerUser(User* user);
	void login(const MyString& username, const MyString& password);

	void saveInfoInFile();

	void saveClientsInfo(std::ofstream& ofs) const;
	void saveDriversInfo(std::ofstream& ofs) const;
	void saveOrdersInfo(std::ofstream& ofs) const;

	void getTotalProfit();
};