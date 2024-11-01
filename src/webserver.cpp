#include "webserver.hpp"
#include "Poco/Net/SecureServerSocket.h"
#include "Poco/Net/HTTPServer.h"

//TODO: Load .env or config file to get those paths
#define SSL_SERVER_PRIVATE_KEY "path"
#define SSL_CERTIFICATE_FILE "path"
#define SSL_CA_FILE "path"

#define BACKLOG_LISTEN 64

int WebServer::main(const std::vector<std::string> &args) {
    try {
        std::cout << "-- -- -- Starting server daemon... -- -- --" << std::endl;

        Poco::Net::initializeSSL();

        Poco::Net::Context::Ptr context = new Poco::Net::Context(Poco::Net::Context::SERVER_USE,
                                                                 SSL_SERVER_PRIVATE_KEY,
                                                                 SSL_CERTIFICATE_FILE,
                                                                 SSL_CA_FILE,
                                                                 Poco::Net::Context::VERIFY_STRICT,
                                                                 9,
                                                                 false,
                                                                 "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");

        Poco::Net::SocketAddress socketAddress(address);
        Poco::Net::SecureServerSocket sslPort(socketAddress, BACKLOG_LISTEN, context);

        std::cout << "LOG | SSL Sockets Initialized " << std::endl;

        auto *srv = new Poco::Net::HTTPServer(new RequestFactory,
                                              sslPort,
                                              new Poco::Net::HTTPServerParams);

        srv->start();

        /// Gracefully quit
        waitForTerminationRequest();
        srv->stop();
        std::cout << "Closing server daemon..." << std::endl;
        delete srv;
        return Application::EXIT_OK;
    } catch (Poco::Exception& exc) {
        exc.rethrow();
        return exc.code();
    }
}
