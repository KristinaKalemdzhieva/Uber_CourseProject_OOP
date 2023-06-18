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

	Driver* driver = nullptr;  
	Message* message = nullptr; 

	Address address;
	Address destination;

public:
	Order() = default; 
	Order(const Address& address, const Address& destination);

	void setArrivalTime(const unsigned arrivalTime);
	void setMessage(Message* message);
	void askDriver(Driver* driver);
	void setDriver(Driver* driver);

	const unsigned getId() const;
	Driver* getDriver() const;
	const MyString& getDriverFirstName() const;
	const MyString& getDriverLastName() const;
	const MyString& getAddressName() const;
	const MyString& getDistanceName() const;

	const Address& getAddress() const;
	const Address& getDestination() const;

	void check() const;

	void payToDriver(const double amount);
	void rateDriver(const unsigned short rating);

	void changeOrderStatus(OrderStatus newStatus);
	OrderStatus getOrderStatus() const;

	~Order();
};