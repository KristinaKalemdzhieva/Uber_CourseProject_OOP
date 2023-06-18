#pragma once
#include "Command.h"
#include "MyString.h"

//login
class Command2 : public Command
{
	MyString username;
	MyString password;

public:
	Command2(const MyString& username, const MyString& password);
	void execute(std::ostream& os, System* system) override;
};