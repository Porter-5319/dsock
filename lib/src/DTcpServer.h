#ifndef DTCPSERVER_H
#define DTCPSERVER_H

#include "DSockAPI.h"

class DTcpServer : public DSockAPI
{
public:
    DTcpServer();

    /**
     * @brief init
     * @param port
     * @return
     */
    DRV init(const int &port);

    /**
     * @brief acceptClient
     * @return
     */
    DRV acceptClient();

    /**
     * @brief recvMsg
     * @param str
     * @param s
     * @param us
     * @return
     */
    DRV recvMsg(std::string &str, int s = 0, int us = 0);

    /**
     * @brief sendMsg
     * @param msg
     * @return
     */
    DRV sendMsg(const std::string &msg);

private:
    int                     m_ServerFD;            //<! server fd
    int                     m_ClientFD;            //<! client fd
    struct sockaddr_in      m_ServerAddr;          //<! server address
    struct sockaddr_in      m_ClientAddr;          //<! client address
};

#endif // DTCPSERVER_H
