cmake_minimum_required(VERSION 3.22)
project(openInventory)

find_package(Poco CONFIG REQUIRED Net Util XML)

if(NOT TARGET Poco::Net)
    message(FATAL_ERROR "No Poco::Net target")
endif()

add_executable(openInventory src/main.cpp
        include/http_server.cpp
        include/http_server.h)

target_link_libraries(openInventory PUBLIC Poco::Net Poco::Util Poco::JSON)
target_include_directories(openInventory PUBLIC include)
