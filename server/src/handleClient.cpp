#include "../inc/handleClient.h"
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
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
    const int TO_SLEEP = 500000; /// 500ms , arbitrary value, TODO revise this

    const char* CLIENT_IP = conn.activeConnections[connfd].ip;
    in_port_t CLIENT_PORT = conn.activeConnections[connfd].port;

    std::cout << "[NEW CONNECTION] " << CLIENT_IP << ':' << CLIENT_PORT << " on socket " << connfd << std::endl;
    
    std::string msg;
    while (true) {
        switch (read(connfd, msg)) {
        case -1:
            std::cout << "Read failed" << std::endl;
            usleep(TO_SLEEP);
            continue;
        
        case 0: /// eof - socket closed
            std::cout << "Socket closed" << std::endl;
            goto closeSocket; 
        
        default:
            size_t sep = msg.find(';');
            int fd = std::stoi(msg.substr(0, sep)); /// socket to send to

            if (fd == -1)
                break;

            msg = msg.substr(sep+1); /// actual message
            
            std::cout << '[' << CLIENT_IP << ':' << CLIENT_PORT << "] To socket " << fd << ": " << msg << std::endl;

            write(fd, msg);
        }
    }
    
    closeSocket:
    conn.close(connfd);
    std::cout << "[CLOSED CONNECTION] " << CLIENT_IP << ':' << CLIENT_PORT << " on socket " << connfd << std::endl;
}