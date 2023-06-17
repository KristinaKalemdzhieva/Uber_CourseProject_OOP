#pragma once
#include "MyString.h"

enum class UserType
{
	Client,
	Driver
};

class User
{
private:
	MyString username;
	MyString password;
	MyString firstName;
	MyString lastName;

protected:
	double account;
	UserType userType;

public:
	User(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, UserType userType);

	const MyString& getUsername() const;
	const MyString& getPassword() const;
	const MyString& getFirstName() const;
	const MyString& getLastName() const;

	UserType getUserType() const;
};

