#include "DriverCommandFactory.h"

namespace
{
	void printMenu()
	{
		std::cout << " ______________________________________" << std::endl;
		std::cout << "| ___  _          _   _          _  _  |" << std::endl;
		std::cout << "|  |  |_| \\/ |   | \\ |_| | \\  / |_ |_| |" << std::endl;
		std::cout << "|  |  | | /\\ |   |_/ | \\ |  \\/  |_ | \\ |" << std::endl;
		std::cout << "|                                      |" << std::endl;
		std::cout << "|               -MENU-                 |" << std::endl;
		std::cout << "|______________________________________|" << std::endl;
		std::cout << "|                                      |" << std::endl;
		std::cout << "|          1.Change address            |" << std::endl;
		std::cout << "|          2.Check messages            |" << std::endl;
		std::cout << "|          3.Accept order              |" << std::endl;
		std::cout << "|          4.Decline order             |" << std::endl;
		std::cout << "|          5.Finish order              |" << std::endl;
		std::cout << "|          6.Accept payment            |" << std::endl;
		std::cout << "|          7.Logout                    |" << std::endl;
		std::cout << "|______________________________________|" << std::endl << std::endl;
	}
}

DriverCommand* DriverCommandFactory::getCommand() const
{
	printMenu();

	std::cout << "Choose option: ";
	int n;
	std::cin >> n;

	if (n == 1)   //change_address
	{
		std::cout << "Name of address: ";
		MyString name;
		std::cin >> name;

		std::cout << "Coordinates: ";
		int x, y;
		std::cin >> x >> y;

		return new DriverCommand1(name, x, y);
	}
	else if (n == 2)   //check_messages
	{
		return new DriverCommand2();
	}
	else if (n == 3)   //accept_order
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		std::cout << "Time to arrive (in minutes): ";
		unsigned minutes;
		std::cin >> minutes;

		return new DriverCommand3(id, minutes);
	}
	else if (n == 4) //decline_order
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		return new DriverCommand4(id);
	}
	else if (n == 5)   //finish_order
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		return new DriverCommand5(id);
	}
	else if (n == 6)   //accept_payment
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		std::cout << "Amount: ";
		double amount;
		std::cin >> amount;

		return new DriverCommand6(id, amount);
	}
	else if (n == 7)   //logout
	{
		return new DriverCommand7();
	}
	else
	{
		throw std::invalid_argument("Invalid option");
	}
}

DriverCommandFactory& DriverCommandFactory::getInstance()
{
	static DriverCommandFactory factory;
	return factory;
}