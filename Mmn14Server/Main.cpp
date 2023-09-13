#include "Main.h"



int main() {
	boost::asio::io_context io_context;
	tcp::acceptor acceptor(io_context);

	Server LocalServer;
	try {
		LocalServer.ServerInit(PORT);
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: Unable to start server acceptor - " << e.what() << std::endl;
		return 1; // Return an error code
	}

	LocalServer.ServerRun();

	return 0;
}

