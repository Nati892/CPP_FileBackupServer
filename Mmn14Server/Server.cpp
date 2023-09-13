#include "Server.h"


void Server::ServerInit(int port) {
	acceptor = new tcp::acceptor(io_context);
	try {
		acceptor->open(tcp::v4());
		acceptor->bind(tcp::endpoint(tcp::v4(), port));
		acceptor->listen();
	}
	catch (const std::exception& e) {
		std::cerr << "Error:starting server " << e.what() << "\n";
		throw e; // Rethrow the exception for error handling in main()
	}
}

void Server::ServerRun()
{
	while (true)
	{
		try {
			std::thread* clientThread = nullptr;
			tcp::socket* soc;
			soc = new tcp::socket(io_context);

			acceptor->accept(*soc);
			std::cerr << "Accepted a new connection" << "\n";

			clientThread = new std::thread([this, soc]() {
				this->HandleClient(soc);
				});

		}
		catch (const std::exception& e) {}
	}
}


void Server::HandleClient(tcp::socket* socket)
{
	SocketHandler soc_handler = SocketHandler(socket);

	char* data;
	RequestHeader* reqHeader = nullptr;

	while (true) {
		// Read data from the client
		char** data = nullptr;
		size_t data_len = 0;
		soc_handler.Rec(data, &data_len);
		int len_handled = GetRequestHeader(*data, data_len, reqHeader);
	}

	socket->cancel();
	socket->close();
}