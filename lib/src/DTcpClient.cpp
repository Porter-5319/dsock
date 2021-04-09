#include "DTcpClient.h"

DTcpClient::DTcpClient()
    : m_ClientFD(-1)
{

}

DRV DTcpClient::connectToServer(const char *ip, const int &port)
{
    if (m_ClientFD >= 0) {
        closeFD(m_ClientFD);
    }

    /**
     *  Create client socket
     */
    m_ClientFD = socket(AF_INET, SOCK_STREAM, 0);
    if (m_ClientFD < 0)
        return DRV_ERROR_SOCKET;

    /**
     *  Initialize the server address
     */
    struct hostent *ht = gethostbyname(ip);
    if (!ht) {
        closeFD(m_ClientFD);
        return DRV_ERROR;
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(static_cast<unsigned short>(port));
    memcpy(&serverAddr.sin_addr, ht->h_addr, static_cast<size_t>(ht->h_length));

    /**
     *  Connect to server
     */
    int res = connect(m_ClientFD, reinterpret_cast<struct sockaddr *>(&serverAddr), sizeof(serverAddr));
    if (res != 0) {
        printf("connect - %d\n", res);
        closeFD(m_ClientFD);
        return DRV_ERROR_CONNECT;
    }

    return DRV_OK;
}

DRV DTcpClient::recvMsg(std::string &msg, int s, int us)
{
    /**
     * Wait for a certain amount of time and return if the time expires
     */
    DRV res = waiting(m_ClientFD, s, us);
    if (DRV_OK != res) {
        return res;
    }

    /**
     * read buf
     */
    return drecv(m_ClientFD, msg);
}

DRV DTcpClient::sendMsg(const std::string &msg)
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
    return dsend(m_ClientFD, msg);
}
