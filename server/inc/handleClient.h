#pragma once
#include "connection.h"

void createClientThread (Connection& conn, const int connfd); /// creates the thread which handles the client
void handleClient (Connection& conn, const int connfd); /// handles the client