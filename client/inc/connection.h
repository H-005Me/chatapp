#pragma once
#include <netinet/in.h>

class Connection
{
    int sockfd;     /// sock file descriptor
    sockaddr_in servAddr; /// server address
    int ipProt;     /// ip protocol family (ex. AF_INET)
    int sockType;   /// socket type (ex. SOCK_STREAM)
    int protocol;   /// (ex. 0)
    in_port_t port; /// port to connect to

public:
    /// CONSTRUCTORS
    Connection ();

    /// ipProt, sockType, protocol, port
    Connection (const int pipProt, const int psockType, const int pprotocol, const in_port_t pport);

    /// FUNCTIONS
    int connect (); /// return: 0 on success, -1 on error
};