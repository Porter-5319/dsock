#include <QCoreApplication>
#include "DTcpServer.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    DTcpServer server;
    if (DRV_OK != server.init(9988)) {
        qInfo() << "Failed to init server ";
        return 0;
    }

    if (DRV_OK != server.acceptClient()) {
        qInfo() << "Failed to accept client ";
        return 0;
    }

//    std::string ch1 = "我是中国人";
//    std::string ch2 = "我是xxx";
//    std::string ch3 = "xxxxx";
//    int sizeofCh1 = ch1.length();
//    //int lenCh1 = strlen(ch1);
//    int sizeofCh2 = ch2.length();
//    //int lenCh2 = strlen(ch2);
//    int sizeofCh3 = ch3.length();
//    //int lenCh3 = strlen(ch3);

    while (true) {
        std::string msg;
        DRV res = server.recvMsg(msg);
        if (DRV_OK != res) {
            break;
        }

        qInfo() << "recv from client : " << QString::fromLocal8Bit(msg.c_str());

        std::string msgr("Info from server.");
        res = server.sendMsg(msgr);
        if (DRV_OK != res) {
            break;
        }
        qInfo() << "send to client : " << QString::fromLocal8Bit(msgr.c_str());
    }

    qInfo() << "Server is error .......... !";
}
