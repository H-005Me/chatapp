#include "../inc/handleClient.h"
#include <iostream>
#include <string>
#include <thread>
#include "../inc/connection.h"
#include "../../shared/inc/inout.h"

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
    const char* CLIENT_IP = conn.activeConnections[connfd].ip;
    in_port_t CLIENT_PORT = conn.activeConnections[connfd].port;

    std::cout << "[NEW CONNECTION] " << CLIENT_IP << ':' << CLIENT_PORT << " on socket " << connfd << std::endl;
    
    std::string msg;
    while (true) {
        read(connfd, msg);
        
        size_t sep = msg.find(';');
        int fd = std::stoi(msg.substr(0, sep)); /// socket to send to

        if (fd == -1)
            break;

        msg = msg.substr(sep+1); /// actual message
        
        std::cout << '[' << CLIENT_IP << ':' << CLIENT_PORT << "] To socket " << fd << ": " << msg << std::endl;
    }
    
    conn.close(connfd);
    std::cout << "[CLOSED CONNECTION] " << CLIENT_IP << ':' << CLIENT_PORT << " on socket " << connfd << std::endl;
}