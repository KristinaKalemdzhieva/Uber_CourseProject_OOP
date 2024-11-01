#include "ClientCommandFactory.h"
#include "Address.h"

namespace
{
	void printMenu()
	{
		std::cout << " ______________________________________" << std::endl;
		std::cout << "|         __        __      ___        |" << std::endl;
		std::cout << "|        |   |   | |__ |\\ |  |         |" << std::endl;
		std::cout << "|        |__ |__ | |__ | \\|  |         |" << std::endl;
		std::cout << "|                                      |" << std::endl;
		std::cout << "|               -MENU-                 |" << std::endl;
		std::cout << "|______________________________________|" << std::endl;
		std::cout << "|                                      |" << std::endl;
		std::cout << "|          1.Order taxi                |" << std::endl;
		std::cout << "|          2.Check order               |" << std::endl;
		std::cout << "|          3.Cancel order              |" << std::endl;
		std::cout << "|          4.Pay order                 |" << std::endl;
		std::cout << "|          5.Rate driver               |" << std::endl;
		std::cout << "|          6.Add money                 |" << std::endl;
		std::cout << "|          7.Logout                    |" << std::endl;
		std::cout << "|______________________________________|" << std::endl << std::endl;
	}
}

ClientCommand* ClientCommandFactory::getCommand() const
{
	printMenu();

	std::cout << "Choose option: ";
	int n;
	std::cin >> n;

	if (n == 1)   //Order taxi 
	{
		std::cout << "Name of address: ";
		MyString name;
		std::cin >> name;

		std::cout << "Coordinates: ";
		int x, y;
		std::cin >> x >> y;

		std::cout << "Would you like to add clarifying information? (yes/no) -> ";
		char answer[4];
		std::cin >> answer;

		Address from(name, x, y);

		if (strcmp(answer, "yes") == 0)
		{
			std::cout << "Clarifying information: ";
			MyString clarifyingInfo;
			std::cin >> clarifyingInfo;

			from.addClarifyingInfo(clarifyingInfo);
		}

		std::cout << "Name of destination: ";
		std::cin >> name;

		std::cout << "Coordinates: ";
		std::cin >> x >> y;

		std::cout << "Would you like to add clarifying information? (yes/no) -> ";
		std::cin >> answer;

		Address to(name, x, y);

		if (strcmp(answer, "yes") == 0)
		{
			std::cout << "Clarifying information: ";
			MyString clarifyingInfo;
			std::cin >> clarifyingInfo;

			to.addClarifyingInfo(clarifyingInfo);
		}

		return new ClientCommand1(from, to);
	}
	else if (n == 2)    //Check order
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		return new ClientCommand2(id);
	}
	else if (n == 3)   //Cancel order
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		return new ClientCommand3(id);
	}
	else if (n == 4)   //Pay order
	{
		std::cout << "Order ID: ";
		unsigned id;
		std::cin >> id;

		std::cout << "Amount: ";
		double amount;
		std::cin >> amount;

		return new ClientCommand4(id, amount);
	}
	else if (n == 5)   //Rate driver
	{
		std::cout << "Driver's first name: ";
		MyString firstName;
		std::cin >> firstName;

		std::cout << "Driver's second name: ";
		MyString secondName;
		std::cin >> secondName;

		std::cout << "Rating: ";
		unsigned short rating;
		std::cin >> rating;

		return new ClientCommand5(firstName, secondName, rating);
	}
	else if (n == 6)   //Add money
	{
		std::cout << "Amount: ";
		double amount;
		std::cin >> amount;

		return new ClientCommand6(amount);
	}
	else if (n == 7)   //Logout
	{
		return new ClientCommand7();
	}
	else
	{
		std::cout << "Invalid option! Try again!" << std::endl << std::endl;
	}
}

ClientCommandFactory& ClientCommandFactory::getInstance()
{
	static ClientCommandFactory factory;
	return factory;
}