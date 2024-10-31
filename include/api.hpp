//
// Created by max on 10/31/24.
//

#ifndef OPENINVENTORY_API_HPP
#define OPENINVENTORY_API_HPP


#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class Api {
private:
    class RequestHandler;
    class RequestFactory;
public:
    Api() = default;
    ~Api() = default;
    static Api::RequestHandler* newRequestHandlerPtr();
};


#endif //OPENINVENTORY_API_HPP
