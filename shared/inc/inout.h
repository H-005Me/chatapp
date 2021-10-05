#pragma once
#include <cstring>
#include <string>

bool write (const int sockfd, const char* msg); /// return: 1 on success, 0 on error
inline bool write (const int sockfd, const std::string& msg) /// calls write(int, char*)
{ return write(sockfd, msg.c_str()); }

int read (const int sockfd, std::string& msg); /// return nr of bytes read, 0 on EOF, -1 on error
