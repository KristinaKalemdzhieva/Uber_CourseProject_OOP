#pragma once 
#include "MyString.h"

class Address
{
	MyString name;
	MyString clarifyingInfo;

	struct Point
	{
		int x;
		int y;

		Point() : x(0), y(0) { }
	} point;

public:
	Address() = default;
	Address(const MyString& name, const int x, const int y);

	void addClarifyingInfo(const MyString& clarifyingInfo);

	double getDist(const Address& other) const;
	const MyString& getName() const;

	void changeAddress(const MyString& name, const int x, const int y);
	void changeAddress(const Address& other);
};