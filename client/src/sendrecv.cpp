#include "../inc/sendrecv.h"
#include <iostream>
#include <unistd.h>
#include "../inc/drawui.h"
#include "../../shared/inc/inout.h"

/// DEFINITIONS

void handleRecv (const int sockfd, bool& running)
{
    const int TO_SLEEP = 500000; /// 500ms , arbitrary value, TODO revise this

    std::string msg; /// thread is probably stuck on read() after running is set to 0
    while (running) {
        std::cout << "T1" << std::endl;
        int r = read(sockfd, msg);
        std::cout << "T2" << std::endl;
        if (r == -1) {
            std::cout << "Read failed" << std::endl;
            usleep(TO_SLEEP);
            continue;
        }
        std::cout << "T3 - " << msg << std::endl;

        writeReceived(msg);
        std::cout << "T4" << std::endl;
    }
}