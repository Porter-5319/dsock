#include "DSockAPI.h"

DSockAPI::DSockAPI()
{

}

DRV DSockAPI::dsend(const int &fd, const std::string &msg)
{
    if (fd < 0) {
        return DRV_FD_NEGATIVE;
    }

    size_t size = msg.length();
    const char *buf = msg.c_str();
    return dsend(fd, buf, size);
}

DRV DSockAPI::drecv(const int &fd, std::string &msg)
{
    if (fd < 0) {
        return DRV_FD_NEGATIVE;
    }

    char buf[RECV_SIZE];
    ssize_t totalSize = 0;
    while (true) {
        memset(buf, 0, sizeof(buf));
        ssize_t readSize = recv(fd, buf, sizeof(buf), 0);

        if (readSize <= 0 && 0 == totalSize)
            return DRV_SIZE_UN_POSITIVE;

        msg.append(buf);
        totalSize += readSize;

        // Data receiving completed, directly exit
        if (readSize < RECV_SIZE)
            break;
    }
    return DRV_OK;
}

DRV DSockAPI::waiting(const int &fd, const int &sec, const int &usec)
{
    if (fd < 0) {
        return DRV_FD_NEGATIVE;
    }

    if (sec <= 0 && usec <= 0) {
        return DRV_OK;
    }

    fd_set set;
    FD_ZERO(&set);
    FD_SET(fd, &set);

    struct timeval timeout;
    timeout.tv_sec = sec;
    timeout.tv_usec = usec;

    int res = select(fd, &set, nullptr, nullptr, &timeout);
    if (res <= 0) {
        // =0 -> timeout
        // <0 -> error
        // >0 -> right
        if (res == 0) {
            return DRV_TIMEOUT;
        } else {
            return DRV_ERROR;
        }
    }
    return DRV_OK;
}

void DSockAPI::closeFD(int &fd)
{
    close(fd);
    fd = -1;
}

char *DSockAPI::ipFromAddr(const struct in_addr &sin_addr)
{
    return inet_ntoa(sin_addr);
}

DRV DSockAPI::dsend(const int &fd, const char *buf, const size_t &size)
{
    if (fd < 0) {
        return DRV_FD_NEGATIVE;
    }

    size_t leftBufSize = size; // The number of bytes left in the unsent message
    size_t curPos = 0; // current pos
    while (leftBufSize > 0) {
        ssize_t sendSize = send(fd, buf + curPos, leftBufSize, 0);
        if (sendSize > 0) {
            leftBufSize -= static_cast<size_t>(sendSize);
            curPos += static_cast<size_t>(sendSize);
            continue;
        }

        if (0 == curPos)
            return DRV_ERROR;
        else
            break;
    }
    return DRV_OK;
}
