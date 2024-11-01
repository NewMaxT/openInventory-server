#include "gtest/gtest.h"
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Exception.h>
#include <iostream>
#include <sstream>

TEST(PocoLibTest, poco_net_test) {
    Poco::Net::HTTPClientSession session("httpbin.org");
    Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/get");
    Poco::Net::HTTPResponse response;

    // Send request and receive response
    session.sendRequest(request);
    std::istream& resStream = session.receiveResponse(response);

    // Check if the response is OK (HTTP 200)
    EXPECT_EQ(response.getStatus(), Poco::Net::HTTPResponse::HTTP_OK);

    // Optional: Check response content
    std::ostringstream oss;
    Poco::StreamCopier::copyStream(resStream, oss);
    std::string responseContent = oss.str();
    EXPECT_FALSE(responseContent.empty());
}
