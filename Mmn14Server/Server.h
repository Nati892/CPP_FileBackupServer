#pragma once
#include <boost/asio.hpp>
#include <iostream>
#include "Message.h"
#include "SocketHandler.h"

using namespace boost::asio::ip;

class Server
{
public:
	void ServerInit(int port);
	void ServerRun();
private:
	void HandleClient(tcp::socket* soc);
	boost::asio::io_context io_context;
	tcp::acceptor* acceptor;
};
