#pragma once
#include <cstring>
#include <string>

bool write (const int connfd, const char* msg); /// return: 1 on success, 0 on error
inline bool write (const int connfd, const std::string& msg) /// calls write(int, char*)
{ return write(connfd, msg.c_str()); }

int read (const int connfd, std::string& msg); /// return nr of bytes read, 0 on EOF, -1 on error
