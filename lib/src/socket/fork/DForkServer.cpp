#include "DForkServer.h"

DForkServer::DForkServer()
    : mp_Server(nullptr)
{}

DForkServer::~DForkServer()
{
    DELETE_PTR(mp_Server)
}

DRV DForkServer::runServer(int port)
{
    DRV res = DRV_OK;
    if (!mp_Server) {
        mp_Server = new DTcpServer();
    }

    // init server
    res = mp_Server->init(port);
    if (DRV_OK != res) {
        return res;
    }

    // accept and fork
    while (true) {

        // Accept the connection request from the client
        if (DRV_OK != mp_Server->acceptClient()) {
            continue;
        }

        // Fork a new process to handle all business for the client
        pid_t fpit = fork();

        /* Close the extra sockets
         * The parent process only needs to listen , not communicate , so close client FD
         * The child process only needs to communicate , not listen , so close server FD
         */
        if (fpit > 0) {
            mp_Server->closeClientFD();
            continue; // Continue to accept connections from other clients
        } else {
            mp_Server->closeServerFD();
        }

        //
        return run();
    }
}

void DForkServer::closeServerFD()
{
    if (mp_Server) {
        mp_Server->closeServerFD();
    }
}

void DForkServer::closeClientFD()
{
    if (mp_Server) {
        mp_Server->closeClientFD();
    }
}

DRV DForkServer::recvMsg(std::string &msg)
{
    if (!mp_Server) {
        return DRV_ERROR;
    }
    return mp_Server->recvMsg(msg);
}

DRV DForkServer::sendMsg(const std::string &msg)
{
    if (!mp_Server) {
        return DRV_ERROR;
    }
    return mp_Server->sendMsg(msg);
}
