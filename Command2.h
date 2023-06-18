#pragma once
#include "Command.h"
#include "MyString.h"

//Login
class Command2 : public Command
{
	MyString username;
	MyString password;

public:
	Command2(const MyString& username, const MyString& password);
	bool execute(std::ostream& os, System* system) override;
};