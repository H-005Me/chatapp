#include <iostream>
#include <netinet/in.h>
#include "../inc/connection.h"
#include "../../shared/inc/inout.h"
#include <unistd.h>

int main (int argc, char** argv)
{
    const char* IP = "188.24.126.196";
    const in_port_t PORT = 25565;

    Connection conn(IP, AF_INET, SOCK_STREAM, 0, PORT);
    if (conn.connect() == -1) {
        std::cout << "Connection Failed!" << std::endl;
        return 1;
    }
    
    std::cout << "Connection Succeeded!" << std::endl;
}