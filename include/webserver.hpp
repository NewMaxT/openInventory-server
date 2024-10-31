/*
Project: openInventory
Author: Maxence Goutteratel
Date: 2023-10-31

Description: Web Server Class
*/

#ifndef OPENINVENTORY_WEBSERVER_HPP
#define OPENINVENTORY_WEBSERVER_HPP

#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/HTTPServer.h"
#include "api.hpp"

class WebServer : public Poco::Util::ServerApplication {

protected:
    /// Main function of the daemon process.
    /// Overrides the parent class (Poco::Util::ServerApplication) method
    int main(const std::vector<std::string> &args) override;

private:
    class RequestFactory : public Poco::Net::HTTPRequestHandlerFactory {
    public:
        Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest &) override
        {
            return (Poco::Net::HTTPRequestHandler*) Api::newRequestHandlerPtr();
        }
    };

    Poco::Net::HTTPServer *srv = new Poco::Net::HTTPServer(new RequestFactory,
                                                           Poco::Net::ServerSocket(18044),
                                                           new Poco::Net::HTTPServerParams);
};

#endif //OPENINVENTORY_WEBSERVER_HPP
