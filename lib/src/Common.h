#ifndef COMMON_H
#define COMMON_H

#define RECV_SIZE 1024                            // The size of the data received each time

/**
 * @brief The DRV enum : Return value type
 */
enum  DRV {
    DRV_OK              = 0x000,                  // Function executes successfully
    DRV_TIMEOUT         = 0x001,                  // Function execution timeout
    DRV_FD_NEGATIVE     = 0x002,                  // Socket fd has a value less 0
    DRV_SIZE_NEGATIVE   = 0x003,                  // Return a nagetive size

    DRV_ERROR           = 0x004,                  // Function failed to execute
    DRV_ERROR_SOCKET    = 0x005,                  // Socket creation failed
    DRV_ERROR_CONNECT   = 0x006,                  // Failed to connect to server
    DRV_ERROR_BIND      = 0x007,                  // Failed to bind to the address
    DRV_ERROR_LISTEN    = 0x008,                  // Failed to listen to the fd
    DRV_ERROR_ACCEPT    = 0x009,                  // Failed to accept connections
};


#endif // COMMON_H
