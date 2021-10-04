#pragma once
#include <netinet/in.h>
#include <set>

class Connection
{
    int listenfd;   /// listen file descriptor
    sockaddr_in servAddr; /// server address
    int ipProt;     /// ip protocol family (ex. AF_INET)
    int sockType;   /// socket type (ex. SOCK_STREAM)
    int protocol;   /// (ex. 0)
    int addr;       /// address (ex. INADDR_ANY)
    in_port_t port; /// port to connect to

public:
    std::set<int> activeConnections;

    /// CONSTRUCTORS
    Connection ();

    /// ipProt, sockType, protocol, addr, port
    Connection (const int pipProt, const int psockType, const int pprotocol, const int paddr, const in_port_t pport);

    /// FUNCTIONS
    int listen (const int nrConn); /// return: 0 on success, -1 on error
    int accept (); /// return: connfd on success, -1 on error
    int close (const int connfd);  /// return: 0 on success, -1 on error
};