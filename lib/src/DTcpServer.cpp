#include "DTcpServer.h"

DTcpServer::DTcpServer()
    : m_ServerFD(-1)
    , m_ClientFD(-1)
{

}

DRV DTcpServer::init(const int &port)
{
    if (m_ServerFD > 0) {
        close(m_ServerFD);
        m_ServerFD = -1;
    }

    m_ServerFD = socket(AF_INET, SOCK_STREAM, 0);
    if (m_ServerFD < 0) {
        return DRV_ERROR_SOCKET;
    }

    /**
     *  SO_REUSEADDR makes a port ready to be used again immediately after it is released.
     *  In general, a port will wait two minutes before being used again
     */
    int option = 1;
    setsockopt(m_ServerFD, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    /**
     *  Initialize the server address
     */
    memset(&m_ServerAddr, 0, sizeof(m_ServerAddr));
    m_ServerAddr.sin_port = htons(static_cast<unsigned short>(port));
    m_ServerAddr.sin_family = AF_INET;
    m_ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /**
     *  Bind to the service address
     */
    bool res = bind(m_ServerFD, reinterpret_cast<struct sockaddr *>(&m_ServerAddr), sizeof(m_ServerAddr));
    if (res != 0) {
        closeFD(m_ServerFD);
        return DRV_ERROR_BIND;
    }

    /**
     *  listen
     */
    res = listen(m_ServerFD, 5);
    if (res != 0) {
        closeFD(m_ServerFD);
        return DRV_ERROR_LISTEN;
    }

    return DRV_OK;
}

DRV DTcpServer::acceptClient()
{
    if (m_ServerFD < 0) {
        return DRV_FD_NEGATIVE;
    }

    /**
     *  Accept the connection request from the client
     */
    memset(&m_ClientAddr, 0, sizeof(m_ClientAddr));
    unsigned long size = sizeof(struct sockaddr_in);
    m_ClientFD = accept(m_ServerFD, reinterpret_cast<struct sockaddr *>(&m_ClientAddr), reinterpret_cast<socklen_t *>(&size));
    if (m_ClientFD < 0) {
        return DRV_ERROR_ACCEPT;
    }
    return DRV_OK;
}

DRV DTcpServer::recvMsg(std::string &str, int s, int us)
{
    /**
     * Wait for a certain amount of time and return if the time expires
     */
    DRV res = waiting(m_ClientFD, s, us);
    if (DRV_OK != res) {
        return res;
    }

    /**
     * read str
     */
    res = drecv(m_ClientFD, str);
    if (DRV_OK != res) {
        return res;
    }

    return res;
}

DRV DTcpServer::sendMsg(const std::string &msg)
{
    /**
     * Wait for a certain amount of time and return if the time expires
     */
    DRV res = waiting(m_ClientFD, 0, 0);
    if (DRV_OK != res) {
        printf("waiting return false in client .... \n");
        return res;
    }

    /**
     * *****************************************************************
     */
    res = dsend(m_ClientFD, msg);
    if (DRV_OK != res) {
        return res;
    }

    return res;
}
