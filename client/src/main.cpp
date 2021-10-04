#include "../inc/connection.h"
#include <iostream>

int main (int argc, char** argv)
{
    Connection conn(AF_INET, SOCK_STREAM, 0, 25565);
    if (conn.connect() == -1) {
        std::cout << "Connection Failed!" << '\n';
    } else {
        std::cout << "Connection Succeeded!" << '\n';
    }
}