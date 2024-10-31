/*
Project: openInventory
Author: Maxence Goutteratel
Date: 2023-10-13

Description: Entry point of the program
*/

#include "webserver.hpp"

int main(int argc, char** argv) {
    try
    {
        WebServer server;
        return server.run(argc, argv);
    }
    catch (Poco::Exception& exc)
    {
        std::cerr << exc.displayText() << std::endl;
        return Poco::Util::Application::EXIT_SOFTWARE;
    }
}



