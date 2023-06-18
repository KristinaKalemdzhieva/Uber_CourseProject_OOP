#include "CommandFactory.h"

namespace
{
	void printMenu()
	{
		std::cout << "               ____" << std::endl;
		std::cout << "          ____/TAXI\\____" << std::endl;
		std::cout << "         //      |     \\\\" << std::endl;
		std::cout << "    ____//_______|______\\\\____" << std::endl;
		std::cout << "  _/     | _     | _    |     \\" << std::endl;
		std::cout << " |   ___ |       |      | ___  |" << std::endl;
		std::cout << " |__/   \\|_______|______|/   \\_|" << std::endl;
		std::cout << "    \\___/                \\___/" << std::endl << std::endl;

		std::cout << "   |      ~UBER COMPANY~      |" << std::endl;
		std::cout << "   |           MENU           |" << std::endl;
		std::cout << "   |                          |" << std::endl;
		std::cout << "   |       1.Register         |" << std::endl;
		std::cout << "   |       2.Login            |" << std::endl;
		std::cout << "   |       3.Close app        |" << std::endl << std::endl;
	}
}

Command* CommandFactory::getCommand() const
{
	printMenu();

	std::cout << "Choose option: ";
	int n;
	std::cin >> n;

	if (n == 1)   //register
	{
		std::cout << "User type: ";
		MyString type;
		std::cin >> type;

		std::cout << "Username: ";
		MyString username;
		std::cin >> username;

		std::cout << "Password: ";
		MyString password;
		std::cin >> password;

		std::cout << "First name: ";
		MyString firstName;
		std::cin >> firstName;

		std::cout << "Last name: ";
		MyString lastName;
		std::cin >> lastName;

		if (type == "client")
		{
			return new Command1(username, password, firstName, lastName);
		}

		std::cout << "Car number: ";
		MyString carNumber;
		std::cin >> carNumber;

		std::cout << "Phone number: ";
		unsigned phoneNumber;
		std::cin >> phoneNumber;

		return new Command1(username, password, firstName, lastName, carNumber, phoneNumber);
	}
	else if (n == 2)   //login
	{
		std::cout << "Username: ";
		MyString username;
		std::cin >> username;

		std::cout << "Password: ";
		MyString password;
		std::cin >> password;

		return new Command2(username, password);
	}
	else if (n == 3)    //close app
	{
		return new Command3();
	}
	else
	{
		throw std::invalid_argument("Invalid option");
	}
}

CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory factory;
	return factory;
}