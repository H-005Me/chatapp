#include "../inc/handleClient.h"
#include <iostream>
#include <thread>
#include "../inc/connection.h"

void createClientThread (Connection& conn, const int connfd)
{
    std::thread t(handleClient, std::ref(conn), connfd);
    t.detach();
}

void handleClient (Connection& conn, const int connfd)
{
    conn.close(connfd);
}