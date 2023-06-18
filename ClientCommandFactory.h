#pragma once
#include "ClientCommand1.h"
#include "ClientCommand2.h"
#include "ClientCommand3.h"
#include "ClientCommand4.h"
#include "ClientCommand5.h"
#include "ClientCommand6.h"
#include "ClientCommand7.h"

class ClientCommandFactory
{
	ClientCommandFactory() = default;
	ClientCommandFactory(const ClientCommandFactory& other) = delete;
	ClientCommandFactory& operator=(const ClientCommandFactory& other) = delete;

public:
	ClientCommand* getCommand() const;
	static ClientCommandFactory& getInstance();
};