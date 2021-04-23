#include "DLogFopen.h"

DLogFopen::DLogFopen()
    : mp_File(nullptr)
{

}
DLogFopen::~DLogFopen()
{

}

bool DLogFopen::lopen(const std::string &file, DLog::Mode mode)
{
    mp_File = fopen(file.c_str(), "w"/*getCharMode(mode)*/);
    if (!mp_File) {
        return false;
    }
    return true;
}

bool DLogFopen::lwrite(const std::string &msg)
{
    if (!mp_File) {
        return false;
    }
    if (fprintf(mp_File, "%s", msg.c_str()) < 0) {
        return false;
    }
    return true;
}

void DLogFopen::lclose()
{
    fclose(mp_File);
    mp_File = nullptr;
}
