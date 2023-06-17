#include "User.h"

User::User(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, UserType userType)
	: username(username), password(password), firstName(firstName), lastName(lastName), userType(userType), account(0)
{

}

const MyString& User::getUsername() const
{
	return username;
}

const MyString& User::getPassword() const
{
	return password;
}

const MyString& User::getFirstName() const
{
	return firstName;
}

const MyString& User::getLastName() const
{
	return lastName;
}

UserType User::getUserType() const
{
	return userType;
}