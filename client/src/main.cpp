#include "../inc/connection.h"
#include <iostream>
#include <netinet/in.h>

int main (int argc, char** argv)
{
    const char* IP = "188.24.126.196";
    const in_port_t PORT = 25565;

    Connection conn(IP, AF_INET, SOCK_STREAM, 0, PORT);
    if (conn.connect() != -0) {
        std::cout << "Connection Failed!" << '\n';
        return 1;
    }
    
    std::cout << "Connection Succeeded!" << '\n';
}