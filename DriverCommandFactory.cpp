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

	if (n == 1)   //Change address
	{
		std::cout << "Name of address: ";
		MyString name;
		std::cin >> name;

		std::cout << "Coordinates: ";
		int x, y;
		std::cin >> x >> y;

		return new DriverCommand1(name, x, y);
	}
	else if (n == 2)   //Check messages
	{
		return new DriverCommand2();
	}
	else if (n == 3)   //Accept order
	{
		std::cout << "Message number: ";
		unsigned messageId;
		std::cin >> messageId;

		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		std::cout << "Time to arrive (in minutes): ";
		unsigned minutes;
		std::cin >> minutes;

		return new DriverCommand3(id, messageId, minutes);
	}
	else if (n == 4) //Decline order 
	{
		std::cout << "Message number: ";
		unsigned messageId;
		std::cin >> messageId;

		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		return new DriverCommand4(id, messageId);
	}
	else if (n == 5)   //Finish order 
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		return new DriverCommand5(id);
	}
	else if (n == 6)   //Accept payment
	{
		std::cout << "Message number: ";
		unsigned messageId;
		std::cin >> messageId;

		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		std::cout << "Amount: ";
		double amount;
		std::cin >> amount;

		return new DriverCommand6(id, messageId, amount);
	}
	else if (n == 7)   //Logout
	{
		return new DriverCommand7();
	}
	else
	{
		std::cout << "Invalid option! Try again!" << std::endl << std::endl;
	}
}

DriverCommandFactory& DriverCommandFactory::getInstance()
{
	static DriverCommandFactory factory;
	return factory;
}