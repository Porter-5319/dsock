#include <QCoreApplication>
#include "DTcpClient.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    DTcpClient client;
    if (DRV_OK != client.connectToServer("127.0.0.1", 9988)) {
        qInfo() << "Failed to connect to server ............. ! ";
        return 0;
    }

    std::string msg("info from client");
    for (int i = 0; i < 10; i++) {
        DRV res = client.sendMsg(msg);
        if (DRV_OK != res) {
            break;
        }
        qInfo() << "send to server : " << QString::fromLocal8Bit(msg.c_str());

        std::string msgr;
        res = client.recvMsg(msgr);
        if (DRV_OK != res) {
            break;
        }
        qInfo() << "recv from server : " << QString::fromLocal8Bit(msgr.c_str());
    }

    qInfo() << "Finished to send msg ......... !";
}
