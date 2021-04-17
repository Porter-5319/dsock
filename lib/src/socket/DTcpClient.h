#ifndef DTCPCLIENT_H
#define DTCPCLIENT_H

#include "DSockAPI.h"

class DTcpClient : public DSockAPI
{
public:
    DTcpClient();

    /**
     * @brief connectToServer
     * @param ip
     * @param port
     * @return
     */
    DRV connectToServer(const char *ip, const int &port);

    /**
     * @brief recvMsg
     * @param msg
     * @param s
     * @param us
     * @return
     */
    DRV recvMsg(std::string &msg, int s = 0, int us = 0);

    /**
     * @brief sendMsg
     * @param msg
     * @return
     */
    DRV sendMsg(const std::string &msg);

private:
    int          m_ClientFD;            //<! client fd
};

#endif // DTCPCLIENT_H
