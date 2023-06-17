#include "MyString.h"
#include <cstring>

void MyString::copyFrom(const MyString& other)
{
	length = other.length;
	data = new char[length + 1];
	strcpy(data, other.data);
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
}

void MyString::moveFrom(MyString&& other) noexcept
{
	data = other.data;
	other.data = nullptr;
	length = other.length;
}

MyString::MyString(size_t capacity)
{
	length = capacity - 1;
	data = new char[capacity];
}

MyString::MyString() : MyString(1)
{
	data[0] = '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	strcpy(this->data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

size_t MyString::getLength() const
{
	return length;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[(length += other.length) + 1];
	result[0] = '\0';

	strcat(result, data);
	strcat(result, other.data);

	delete[] data;
	data = result;

	return *this;
}

MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > length)
	{
		throw std::length_error("Error, substr out of range");
	}

	MyString result(howMany + 1);
	for (int i = 0; i < howMany; i++)
	{
		result.data[i] = data[begin + i];
	}
	result[howMany] = '\0';

	return result;
}

char& MyString::operator[](size_t index)
{
	return data[index];
}

char MyString::operator[](size_t index) const
{
	return data[index];
}

const char* MyString::c_str() const
{
	return data;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs.getLength() + rhs.getLength() + 1);

	result[0] = '\0';
	strcat(result.data, lhs.data);
	strcat(result.data, rhs.data);

	return result;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff;

	delete[] str.data;
	str.length = strlen(buff);
	str.data = new char[str.length + 1];
	strcpy(str.data, buff);

	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}