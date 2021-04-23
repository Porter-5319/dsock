#ifndef DFORKSERVER_H
#define DFORKSERVER_H

#include "DTcpServer.h"

class DForkServer
{
public:
    DForkServer();
    virtual ~DForkServer();

    /**
     * @brief runServer
     * @param port
     * @return
     */
    DRV runServer(int port);

    /**
     * @brief closeServerFD
     */
    void closeServerFD();

    /**
     * @brief closeClientFD
     */
    void closeClientFD();

protected:

    /**
     * @brief run : Pure virtual function , used in the chiled process for business coding.
     * @return
     */
    virtual DRV run() = 0;

    /**
     * @brief recvMsg
     * @param msg
     * @return
     */
    DRV recvMsg(std::string &msg);

    /**
     * @brief sendMsg
     * @param msg
     * @return
     */
    DRV sendMsg(const std::string &msg);

private:
    DTcpServer      *mp_Server;         // server
};

#endif // DFORKSERVER_H

/* The problems that needs to be resolved are as follows
 *   1. How to close extra sockets
 *      The parent process only needs to listen , not communicate , so close client FD
 *      The child process only needs to communicate , not listen , so close server FD
 *
 *   2. How to avoid zombie process
 *   3. All children needs to be notified when the parent process ends
 *
 */
