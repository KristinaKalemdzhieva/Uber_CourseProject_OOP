#pragma once
#include "DriverCommand1.h"
#include "DriverCommand2.h"
#include "DriverCommand3.h"
#include "DriverCommand4.h"
#include "DriverCommand5.h"
#include "DriverCommand6.h"
#include "DriverCommand7.h"
//#include "System.h"

class DriverCommandFactory
{
	DriverCommandFactory() = default;
	DriverCommandFactory(const DriverCommandFactory& other) = delete;
	DriverCommandFactory& operator=(const DriverCommandFactory& other) = delete;

public:
	DriverCommand* getCommand() const;
	static DriverCommandFactory& getInstance();
};