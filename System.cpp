#include "System.h"

System::System()
{
	User* user = new Client("krisi", "123", "Kristina", "Kalemdzhieva");
	users.pushBack(user);

	User* user2 = new Driver("demo", "321", "Dragan", "Ivanov", "SM1234AN", 0323);
	users.pushBack(user2);
}

void System::registerUser(User* user)
{
	users.pushBack(user);
}

void System::login(const MyString& username, const MyString& password)
{
	for (size_t i = 0; i < users.getSize(); ++i)
	{
		if (users[i]->getUsername() == username && users[i]->getPassword() == password)
		{
			if (users[i]->getUserType() == UserType::Client)
			{
				ClientCommandExecutor ex;

				while (!ex.executeCommand(ClientCommandFactory::getInstance().getCommand(), static_cast<Client*>(users[i]), users, orders)) {}

			}
			else
			{
				DriverCommandExecutor ex;

				while (!ex.executeCommand(DriverCommandFactory::getInstance().getCommand(), static_cast<Driver*>(users[i]), users, orders)) {}
			}

			break;
		}
	}
}

namespace
{
	void printLogo(std::ofstream& file)
	{
		file << "               ____" << std::endl;
		file << "          ____/TAXI\\____" << std::endl;
		file << "         //      |     \\\\" << std::endl;
		file << "    ____//_______|______\\\\____" << std::endl;
		file << "  _/     | _     | _    |     \\" << std::endl;
		file << " |   ___ |       |      | ___  |" << std::endl;
		file << " |__/   \\|_______|______|/   \\_|" << std::endl;
		file << "    \\___/                \\___/" << std::endl << std::endl;

		file << "          ~UBER COMPANY~       " << std::endl << std::endl;
	}
}

void System::saveInfoInFile()
{
	std::ofstream file("UberCompany.txt");
	if (!file.is_open())
	{
		throw std::runtime_error("Error openning the file!");
	}

	printLogo(file);

	file << "CLIENTS" << std::endl;
	file << "-------------------------------" << std::endl;
	saveClientsInfo(file);

	file << "DRIVERS" << std::endl;
	file << "-------------------------------" << std::endl;
	saveDriversInfo(file);

	file << "ORDERS" << std::endl;
	file << "-------------------------------" << std::endl;
	saveOrdersInfo(file);

	getTotalProfit();

	file << "PROFIT: " << totalProfit << std::endl;

	file.close();
}

void System::saveClientsInfo(std::ofstream& ofs) const
{
	for (size_t i = 0; i < users.getSize(); ++i)
	{
		if (users[i]->getUserType() == UserType::Client) 
		{
			ofs << "Name: " << users[i]->getFirstName() << " " << users[i]->getLastName() << "   ";
			ofs << "Username: " << users[i]->getUsername() << "   " << "Password: " << users[i]->getPassword() << "   ";
			ofs << "Account: " << users[i]->getAccount() << std::endl;
		}
	}
	ofs << std::endl << std::endl << std::endl;
}

void System::saveDriversInfo(std::ofstream& ofs) const
{
	for (size_t i = 0; i < users.getSize(); ++i)
	{
		if (users[i]->getUserType() == UserType::Driver)
		{
			ofs << "Name: " << users[i]->getFirstName() << " " << users[i]->getLastName() << "   ";
			ofs << "Username: " << users[i]->getUsername() << "   " << "Password: " << users[i]->getPassword() << "   ";
			ofs << "Account: " << users[i]->getAccount() << std::endl;
		}
	}
	ofs << std::endl << std::endl << std::endl;
}

void System::saveOrdersInfo(std::ofstream& ofs) const
{
	for (size_t i = 0; i < orders.getSize(); ++i)
	{
		ofs << "Order ID: " << orders[i]->getId() << "   ";
		ofs << "Address: " << orders[i]->getAddressName() << "   " << "Destination: " << orders[i]->getDistanceName() << "   ";

		if (orders[i]->getOrderStatus() == OrderStatus::NotAccepted)
		{
			ofs << "Status: Not Accepted" << std::endl;
			break;
		}
		else if (orders[i]->getOrderStatus() == OrderStatus::Cancelled)
		{
			ofs << "Status: Cancelled" << std::endl;
			break;
		}

		ofs << "Driver: " << orders[i]->getDriverFirstName() << " " << orders[i]->getDriverLastName();

		if (orders[i]->getOrderStatus() == OrderStatus::Accepted)
		{
			ofs << "Status: Accepted" << std::endl;
		}
		else
		{
			ofs << "Status: Finished" << std::endl;
		}
	}
	ofs << std::endl << std::endl << std::endl;
}

void System::getTotalProfit()
{
	for (size_t i = 0; i < users.getSize(); ++i)
	{
		if (users[i]->getUserType() == UserType::Driver)
		{
			totalProfit += users[i]->getAccount();
		}
	}
}