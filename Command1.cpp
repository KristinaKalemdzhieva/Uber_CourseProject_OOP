#include "Command1.h"

Command1::Command1(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName)
{
	user = new Client(username, password, firstName, lastName);
}

Command1::Command1(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, const MyString& carNumber, const unsigned phoneNumber)
{
	user = new Driver(username, password, firstName, lastName, carNumber, phoneNumber);
}

void Command1::execute(std::ostream& os, System* system)
{
	system->registerUser(user);
}

Command1::~Command1()
{
	delete user;
}