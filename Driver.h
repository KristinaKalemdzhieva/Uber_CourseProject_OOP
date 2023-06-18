#pragma once
#include "User.h"
#include "Message.h"
#include "Address.h"
#include "Vector.hpp"

class Driver : public User
{
	bool taken;
	unsigned orderId;
	unsigned phoneNumber;
	size_t ratingsCount;
	size_t ratingsSum;
	MyString carNumber; //16 bytes

	Vector<Message*> messages; //24 bytes

	Address address; //40 bytes

public:
	Driver() = default;
	Driver(const MyString& username, const MyString& password, const MyString& firstName, const MyString& lastName, const MyString& carNumber, const unsigned phoneNumber);

	const unsigned getPhoneNumber() const;
	const MyString& getCarNumber() const;
	const size_t getRating() const;
	const double getDistance(const Address& other) const;

	void setRating(const unsigned short rating);
	void addMessage(Message* message);
	bool isTaken() const;
	void setIfTakenOrNot(bool status);

	void changeAddress(const Address& newAddress);
	void checkMessages() const;

	void acceptOrder(const unsigned orderId, const unsigned messageId);
	void declineOrder(const unsigned messageId);
	void finishOrder(const unsigned id, const Address& destination);
	void acceptPayment(const unsigned id, const unsigned messageId, const double amount);
};