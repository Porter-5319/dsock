#include "DLog.h"

DLog::DLog()
{

}

DLog::~DLog()
{

}

int DLog::getIntMode(const Mode mode)
{
    if (DLog::DWrite == mode) {
        return O_WRONLY | O_CREAT;
    } else if (DLog::DReadWrite == mode) {
        return O_RDWR | O_CREAT;
    } else if (DLog::DAppend == mode) {
        return O_APPEND | O_CREAT;
    } else {
        return O_RDONLY;
    }
}

const char *DLog::getCharMode(const Mode mode)
{
    if (DLog::DWrite == mode) {
        return "w";
    } else if (DLog::DReadWrite == mode) {
        return "rw";
    } else if (DLog::DAppend == mode) {
        return "a";
    } else {
        return "r";
    }
}
