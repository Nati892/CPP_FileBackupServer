#pragma once
#include <iostream>
#include <boost/asio.hpp> 
#define BUFFER_SIZE 2048

class SocketHandler
{
public:
	SocketHandler(boost::asio::ip::tcp::socket* soc);
	~SocketHandler();
	bool Send(char*, uint32_t len);
	bool Rec(char**, size_t* len);
private:
	boost::asio::ip::tcp::socket* Soc;
};
