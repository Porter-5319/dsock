#include "ForkServer.h"

ForkServer::ForkServer()
    : DForkServer()
{

}

DRV ForkServer::run()
{
    DRV res = DRV_OK;
    while (true) {
        std::string msg;
        res = recvMsg(msg);
        if (DRV_OK != res) {
            break;
        }

        std::cout << getpid() << " client: " << msg << std::endl;
        std::cout << getpid() << " server: " << msg << std::endl;
        //std::string msgr;
        //std::cin >> msgr;
        res = sendMsg(msg);
        if (DRV_OK != res) {
            std::cout << getpid() << " server exit !!! ";
            break;
        }
    }

    exit(0);
}
