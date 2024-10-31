//
// Created by max on 10/31/24.
//

#include "webserver.hpp"

int WebServer::main(const std::vector<std::string> &args) {
    try {
        std::cout << "Starting server daemon..." << std::endl;
        srv->start();

        /// Gracefully quit
        waitForTerminationRequest();
        srv->stop();
        std::cout << "Closing server daemon..." << std::endl;
        return Application::EXIT_OK;
    } catch (Poco::Exception& exc) {
        exc.rethrow();
        return exc.code();
    }
}
