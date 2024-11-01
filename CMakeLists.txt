cmake_minimum_required(VERSION 3.22)
project(openInventory)

# Finding the required packages
find_package(Poco CONFIG REQUIRED Net Util XML Data JSON NetSSL)
find_package(pcre2 CONFIG REQUIRED)
find_package(libpqxx CONFIG REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(lz4 CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(expat CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Enable testing
enable_testing()

# Add test executable

add_test(NAME PocoLibTest COMMAND poco_net_test)

add_executable(openInventory
        src/main.cpp
        src/webserver.cpp
        src/api.cpp
)

add_executable(poco_net_test unit_testing/utest_pocolib.cpp)

# .hpp / .h headers
target_include_directories(openInventory PUBLIC include)

# Linking dependencies
target_link_libraries(openInventory
        PRIVATE
            PCRE2::8BIT
            PCRE2::16BIT
            PCRE2::32BIT
            PCRE2::POSIX
            libpqxx::pqxx
            lz4::lz4
            OpenSSL::SSL
            OpenSSL::Crypto
            ZLIB::ZLIB
            expat::expat
            PostgreSQL::PostgreSQL
        PUBLIC
            Poco::Net
            Poco::Util
            Poco::JSON
            Poco::Data
            Poco::NetSSL
)

target_link_libraries(poco_net_test PRIVATE Poco::Net Poco::Util Poco::JSON GTest::gtest GTest::gtest_main GTest::gmock
        GTest::gmock_main)
