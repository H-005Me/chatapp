#include "../inc/handleClient.h"
#include <iostream>
#include <string>
#include <thread>
#include "../inc/connection.h"

/// DECLARATIONS
std::string receiveName();

/// DEFINITIONS
void createClientThread (Connection& conn, const int connfd)
{
    std::thread t(handleClient, std::ref(conn), connfd);
    t.detach();
}

void handleClient (Connection& conn, const int connfd)
{
    std::cout << "[NEW CONNECTION] " << "connfd = " << connfd << '\n';
    conn.close(connfd);
    std::cout << "[CLOSED CONNECTION] " << "connfd = " << connfd << '\n';
}