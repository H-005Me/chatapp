#pragma once
#include <netinet/in.h>

const int IP_SZ = 15;

class ClientConn
{
    sockaddr_in client;

public:
    char* ip;
    int sockfd;

    /// CONSTRUCTORS
    ClientConn();
    ClientConn(const int psockfd, const sockaddr_in pclient);
};