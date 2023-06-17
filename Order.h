#pragma once
#include "Address.h"
#include "Driver.h"
#include "OrderMessage.h"
#include "PaymentMessage.h"

enum class OrderStatus
{
	NotAccepted,
	Accepted,
	Finished,
	Cancelled
};

class Order
{
	static unsigned ID;

	unsigned id = 0;
	unsigned arrivalTime = 0;
	OrderStatus status = OrderStatus::NotAccepted;

	Driver* driver = nullptr;  // trqbva da se triqat
	Message* message = nullptr; // trqbva da se triqt

	Address address;
	Address destination;

public:
	Order() = default; //because of client's pointer
	Order(const Address& address, const Address& destination);

	void setArrivalTime(const unsigned arrivalTime);
	void setDriver(Driver* driver);

	const unsigned getId() const;
	const MyString& getDriverFirstName() const;
	const MyString& getDriverLastName() const;
	//const Address& getAddress() const;
	const MyString& getAddressName() const;
	const MyString& getDistanceName() const;

	void check() const;

	void payToDriver(const double amount);
	void rateDriver(const unsigned short rating);

	void changeOrderStatus(OrderStatus newStatus);
	OrderStatus getOrderStatus() const;

	~Order();
};