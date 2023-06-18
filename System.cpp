#include "System.h"

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
				//ClientCommandExecutor ex(dynamic_cast<Client*>(users[i]));
				ClientCommandExecutor ex;

				while (!ex.executeCommand(ClientCommandFactory::getInstance().getCommand(), static_cast<Client*>(users[i]), users, orders)) {}

			}
			//else
			//{
			//	DriverCommandExecutor ex;

			////	while (!ex.executeCommand(DriverCommandFactory::getInstance().getCommand(), static_cast<Driver*>(users[i]), this)) {}
			//}

			break;
		}
	}
}