#include "Address.h"
#include <cmath>

Address::Address(const MyString& name, const int x, const int y)
	: name(name)
{
	point.x = x;
	point.y = y;
}

void Address::addClarifyingInfo(const MyString& clarifyingInfo)
{
	this->clarifyingInfo = clarifyingInfo;
}

double Address::getDist(const Address& other) const
{
	int dx = other.point.x - point.x;
	int dy = other.point.y - point.y;

	return sqrt(dx * dx + dy * dy);
}

const MyString& Address::getName() const
{
	return name;
}

void Address::changeAddress(const MyString& name, const int x, const int y)
{
	this->name = name;
	point.x = x;
	point.y = y;
	clarifyingInfo = "\0"; //?
}

void Address::changeAddress(const Address& other)
{
	name = other.name;
	point.x = other.point.x;
	point.y = other.point.y;
	clarifyingInfo = other.clarifyingInfo;
}