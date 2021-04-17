#ifndef COMMON_H
#define COMMON_H

#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <signal.h>
#include <functional>

#define RECV_SIZE 1024                            // The size of the data received each time

/**
 * @brief The DRV enum : Return value type
 */
enum  DRV {
    DRV_OK               = 0x000,                  // Function executes successfully
    DRV_TIMEOUT          = 0x001,                  // Function execution timeout
    DRV_FD_NEGATIVE      = 0x002,                  // Socket fd has a value less 0
    DRV_SIZE_NEGATIVE    = 0x003,                  // Return a nagetive size
    DRV_SIZE_UN_POSITIVE = 0x004,                  // Return a nagetive size

    DRV_ERROR            = 0x014,                  // Function failed to execute
    DRV_ERROR_SOCKET     = 0x015,                  // Socket creation failed
    DRV_ERROR_CONNECT    = 0x016,                  // Failed to connect to server
    DRV_ERROR_BIND       = 0x017,                  // Failed to bind to the address
    DRV_ERROR_LISTEN     = 0x018,                  // Failed to listen to the fd
    DRV_ERROR_ACCEPT     = 0x019,                  // Failed to accept connections

    DRV_CHILD_EXIT       = 0x020,
};




/**
 * @brief fatherExit : The signal handler whe the parent process exits
 * @param sig
 */
//void fatherExit(int sig)
//{
//    if (sig > 0) {
//        signal(sig, SIG_IGN);
//        signal(SIGINT, SIG_IGN);
//        signal(SIGTERM, SIG_IGN);
//    }

//    //
//    kill(0, 15);

//    // 释放资源
//}
//void childExit(int sig);


/**
 * @brief DELETE_PTR : Defines a macro that deletes a pointer
 */
#define DELETE_PTR(p) \
    if (p) { \
        delete p; \
        p = nullptr; \
    } \


#endif // COMMON_H
