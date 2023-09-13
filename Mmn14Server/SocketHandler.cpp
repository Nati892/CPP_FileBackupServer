#include "SocketHandler.h"


SocketHandler::SocketHandler(boost::asio::ip::tcp::socket* soc)
{
	Soc = soc;
}

SocketHandler::~SocketHandler()
{
	//TODO clean soc and buffer
}

bool SocketHandler::Rec(char** buffer, size_t* len)
{
	char* data = (char*)malloc(BUFFER_SIZE);
	memset(data, 0, BUFFER_SIZE);//Set the buffer to 0's
	boost::system::error_code error;
	try {
		size_t bytesRead = boost::asio::read(*Soc, boost::asio::buffer(buffer, BUFFER_SIZE), error);

		if (error == boost::asio::error::eof) {//Reached end Connection closed by the client
			if (bytesRead > 0)
			{
				*len = bytesRead;
				*buffer = data;
			}
			else
			{
				free(data);
				data = nullptr;
			}
			std::cout << "Connection closed by client" << std::endl;
			return false;
		}
		else if (error) {//Case of generic error
			std::cerr << "Error: " << error.message() << std::endl;
			if (bytesRead > 0)
			{
				*len = bytesRead;
				*buffer = data;
			}
			else
			{
				free(data);
				data = nullptr;
			}
			free(data);
			data = nullptr;
			return false;
		}
		if (bytesRead > 0)
		{
			*len = bytesRead;
			*buffer = data;
		}
		else
		{
			free(data);
			data = nullptr;
		}
		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		free(data);
		return false;
	}
	return true;
}

bool SocketHandler::Send(char* data, uint32_t len)
{
	boost::system::error_code error;
	boost::asio::write(*Soc, boost::asio::buffer(data, len));

	if (error == boost::asio::error::eof) {
		// Connection closed by the client
		std::cout << "Connection closed by client" << std::endl;
		free(data);
		return false;
	}
	if (error) {
		// Generic error
		std::cerr << "Error: " << error.message() << std::endl;
		free(data);
		return false;
	}

	return true; // Data sent successfully
	return true;
}
