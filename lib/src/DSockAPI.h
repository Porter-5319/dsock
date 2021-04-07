#ifndef DSOCKAPI_H
#define DSOCKAPI_H

#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <netdb.h>

#include "Common.h"

/**
 * @brief The DSockAPI class
 */
class DSockAPI
{
public:
    DSockAPI();

protected:

    /**
     * @brief dsend
     * @param fd
     * @param msg
     * @return
     */
    DRV dsend(const int &fd, const std::string &msg);

    /**
     * @brief recvMsg
     * @param fd
     * @param msg
     * @return
     */
    DRV drecv(const int &fd, std::string &msg);

    /**
     * @brief waiting
     * @param fd
     * @param sec
     * @param usec
     * @return
     */
    DRV waiting(const int &fd, const int &sec = 0, const int &usec = 0);

    /**
     * @brief closeFD
     * @param fd
     */
    void closeFD(int &fd);

    /**
     * @brief ip
     * @param sin_addr
     * @return
     */
    char *ipFromAddr(const struct in_addr &sin_addr);

private:

    /**
     * @brief sendMsg
     * @param fd
     * @param buf
     * @param size
     * @return
     */
    DRV dsend(const int &fd, const char *buf, const size_t &size);
};

#endif // DSOCKAPI_H
