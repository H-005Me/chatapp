#include "../inc/connection.h"
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>

Connection::Connection ()
    : listenfd(0), ipProt(PF_UNSPEC), sockType(0), protocol(0), addr(INADDR_NONE), port(0)
{ memset(&servAddr, 0, sizeof(servAddr)); }

Connection::Connection (const int pipProt, const int psockType, const int pprotocol, const int paddr, const in_port_t pport)
    : ipProt(pipProt), sockType(psockType), protocol(pprotocol), addr(paddr), port(pport)
{
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = ipProt;
    servAddr.sin_addr.s_addr = htonl(addr);
    servAddr.sin_port = htons(port);

    listenfd = socket(ipProt, sockType, protocol); /// create socket
    bind(listenfd, (sockaddr*)&servAddr, sizeof(servAddr)); /// bind socket
}

int Connection::listen (const int nrConn)
{ return ::listen(listenfd, nrConn); }

int Connection::accept ()
{
    sockaddr_in client;
    const unsigned long CLIENT_SZ = sizeof(client);
    memset(&client, 0, CLIENT_SZ);

    int connfd = ::accept(listenfd, (sockaddr*)&client, (socklen_t*)&CLIENT_SZ);

    if (connfd != -1)
        activeConnections.insert(std::pair<int, ClientConn>(connfd, ClientConn(connfd, client)));
    
    return connfd;
}

int Connection::close (const int connfd)
{
    int res = ::close(connfd);

    if (res == 0)
        activeConnections.erase(connfd);
    
    return res;
}