#include <iostream>
#include "../inc/connection.h"
#include "../inc/handleClient.h"
#include "../../shared/inc/useful.h"

int main (int argc, char** argv)
{
    Connection conn(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 25565);
    if (conn.listen(1024) == -1) {
        error("main() - call to listen() failed");
        return 1;
    }

    bool running = 1;

    while (running) {
        int currentConn = conn.accept(); /// TODO this returns 4, then 5, then 4 etc, not 4, 4, 4
        
        if (currentConn == -1) { /// connection failed
            std::cout << "[WARNING] " << "Connection failed" << std::endl;
            continue;
        }

        createClientThread(conn, currentConn);
    }

    for (const auto& activeConnection : conn.activeConnections)
        conn.close(activeConnection.first);
}