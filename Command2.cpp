#include "Command2.h"

Command2::Command2(const MyString& username, const MyString& password)
	:username(username), password(password)
{

}

bool Command2::execute(std::ostream& os, System* system)
{
	system->login(username, password);
	return false;
}