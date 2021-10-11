#include <iostream>
#include <netinet/in.h>
#include "../inc/connection.h"
#include "../inc/drawui.h"
#include "../inc/sendrecv.h"
#include "../../shared/inc/inout.h"
#include <thread>

int main (int argc, char** argv)
{
    const char* IP = "188.24.126.196";
    const in_port_t PORT = 25565;

    Connection conn(IP, AF_INET, SOCK_STREAM, 0, PORT);
    if (conn.connect() == -1) {
        std::cout << "Connection Failed!" << std::endl;
        return 1;
    }

    system("clear");

    drawUi();

    bool hrReadRunning = 1; /// while read thread in handleRecv is running
    std::thread hrRead(handleRecv, conn.sockfd, std::ref(hrReadRunning)); /// handleRecv read thread

    std::string msg;
    bool running = 1;

    while (running) {
        int fd;   std::cin >> fd;
        
        if (fd >= 0) {
            std::getline(std::cin, msg);
            msg = std::to_string(fd) + ';' + msg.substr(1);
        } else {
            msg = std::to_string(fd) + ';';
            running = 0;
        }

        write(conn.sockfd, msg);
    }

    hrReadRunning = 0;
    hrRead.join();
}