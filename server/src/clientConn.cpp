#include "../inc/clientConn.h"
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>

ClientConn::ClientConn() : sockfd(-1), port(0)
{ memset(&client, 0, sizeof(client)); }

ClientConn::ClientConn(const int psockfd, const sockaddr_in pclient) : sockfd(psockfd), client(pclient)
{
    strncpy(ip, inet_ntoa(client.sin_addr), IP_SZ-1);
    port = ntohs(client.sin_port);
}