#include "../inc/connection.h"
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>

Connection::Connection ()
    : sockfd(0), ipProt(PF_UNSPEC), sockType(0), protocol(0), port(0)
{ memset(&servAddr, 0, sizeof(servAddr)); }

Connection::Connection (const char* pip, const int pipProt, const int psockType, const int pprotocol, const in_port_t pport)
    : ipProt(pipProt), sockType(psockType), protocol(pprotocol), port(pport)
{
    memset(&servAddr, 0, sizeof(servAddr));
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = ipProt;
    servAddr.sin_port = htons(port);

    sockfd = socket(ipProt, sockType, protocol);
    inet_pton(ipProt, pip, &servAddr.sin_addr);
}

int Connection::connect ()
{
    return ::connect(sockfd, (sockaddr*)&servAddr, sizeof(servAddr));
}