#include "../inc/inout.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

static const size_t MSGLEN_SZ = 21; /// buffer size for msg header

bool write (const int connfd, const char* msg)
{
    const size_t MSG_SZ = strlen(msg);

    /// get size of msg in a char*
    char msglen[MSGLEN_SZ];
    snprintf(msglen, MSGLEN_SZ, "%lu", MSG_SZ);
    /// send number of bytes
    if (::write(connfd, msglen, MSGLEN_SZ) == -1) /// error
        return 0;

    /// send message
    if (::write(connfd, msg, MSG_SZ) == -1)
        return 0;
    
    return 1;
}

int read (const int connfd, std::string& msg)
{
    /// receive size of msg
    char recvBuff[MSGLEN_SZ];
    if (::read(connfd, recvBuff, MSGLEN_SZ) == -1)
        return -1;
    
    /// receive message
    const size_t msglen = atol(recvBuff);
    msg.resize(msglen);
    return ::read(connfd, &msg[0], msglen);
}