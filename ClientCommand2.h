#pragma once
#include "ClientCommand.h"

class ClientCommand2 : public ClientCommand
{
	unsigned id;

public:
	ClientCommand2(const unsigned id);
	void execute(std::ostream& os, Client* client) override;
};