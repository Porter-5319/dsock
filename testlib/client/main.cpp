#include <QCoreApplication>
#include "DTcpClient.h"

int main(int argc, char *argv[])
{
    DTcpClient client;
    if (DRV_OK != client.connectToServer("127.0.0.1", 9988)) {
        std::cout << "Failed to connect to server ............. ! ";
        return 0;
    }

    std::string msg("");
    while (true) {
        std::cout << "client: ";
        std::cin >> msg;
        if (msg.empty()) {
            continue;
        }

        DRV res = client.sendMsg(msg);
        if (DRV_OK != res) {
            std::cout << "消息发送失败 ******************************* 错误码: " << res;
            break;
        }

        std::string msgr;
        res = client.recvMsg(msgr);
        if (DRV_OK != res) {
            std::cout << "连接断开" << std::endl;
            break;
        }

        std::cout << "server: " << msgr << std::endl;
    }

    std::cout << "Finished to send msg ......... !";
}
