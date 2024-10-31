//
// Created by max on 10/31/24.
//

#include "api.hpp"

class Api::RequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp) override
    {
        resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        resp.setContentType("text/html");

        std::ostream& out = resp.send();
        out << "<h1>Hello world!</h1>"
            << "<p>Host: "   << req.getHost()   << "</p>"
            << "<p>Method: " << req.getMethod() << "</p>"
            << "<p>URI: "    << req.getURI()    << "</p>";
        out.flush();

        std::cout << std::endl << req.getURI() << std::endl;
    }
};

Api::RequestHandler* Api::newRequestHandlerPtr() {
    return new RequestHandler;
}
