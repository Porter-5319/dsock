#include <QCoreApplication>
#include "DTcpServer.h"

int main(int argc, char *argv[])
{
    DTcpServer server;
    if (DRV_OK != server.init(9988)) {
        std::cout << "Failed to init server " << std::endl;
        return 0;
    }

    while (true) {
        if (DRV_OK != server.acceptClient()) {
            std::cout << "Failed to accept client " << std::endl;
            continue;
        }

        while (true) {
            std::string msg;
            DRV res = server.recvMsg(msg);
            if (DRV_OK != res) {
                break;
            }

            std::cout << "client: " << msg << std::endl;
            std::cout << "server: ";
            std::string msgr;
            std::cin >> msgr;
            res = server.sendMsg(msgr);
            if (DRV_OK != res) {
                break;
            }
        }
    }
}
