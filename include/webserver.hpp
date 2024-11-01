/*
Project: openInventory
Author: Maxence Goutteratel
Date: 2023-10-31

Description: Web Server Class
*/

#ifndef OPENINVENTORY_WEBSERVER_HPP
#define OPENINVENTORY_WEBSERVER_HPP

#include "Poco/Util/ServerApplication.h"

#include "api.hpp"

//TODO: Load .env or config file to get those paths
#define HOSTNAME "api.newmax.dev:18044,31.220.100.77:18044"

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
    std::string address = HOSTNAME;
};

#endif //OPENINVENTORY_WEBSERVER_HPP
