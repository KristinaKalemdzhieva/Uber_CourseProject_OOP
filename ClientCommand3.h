#pragma once
#include "ClientCommand.h"

class ClientCommand3 : public ClientCommand
{
	unsigned id;

public:
	ClientCommand3(const unsigned id);
	void execute(std::ostream& os, Client* client) override;
};