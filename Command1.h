#pragma once
#include "Command.h"
#include "MyString.h"
#include "Driver.h"
#include "Client.h"

//Register
class Command1 : public Command
{
	User* user = nullptr;

public:
	Command1(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName);
	Command1(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, const MyString& carNumber, const unsigned phoneNumber);
	bool execute(std::ostream& os, System* system) override;

	~Command1();
};