#include "DLogOpen.h"

DLogOpen::DLogOpen()
    : m_FD(-1)
{

}
DLogOpen::~DLogOpen()
{

}

bool DLogOpen::lopen(const std::string &file, DLog::Mode mode)
{
    //
    m_FD = open(file.c_str(), getIntMode(mode), S_IRWXU);
    if (m_FD < 0) {
        return false;
    }
    return true;
}

bool DLogOpen::lwrite(const std::string &msg)
{
    if (m_FD < 0) {
        return false;
    }
    if (write(m_FD, msg.c_str(), msg.length()) < 0) {
        return false;
    }
    return true;
}

void DLogOpen::lclose()
{
    close(m_FD);
    m_FD = -1;
}


