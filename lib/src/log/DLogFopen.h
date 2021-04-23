#ifndef DLOGFOPEN_H
#define DLOGFOPEN_H

#include "DLog.h"

class DLogFopen : public DLog
{
public:
    DLogFopen();
    ~DLogFopen() override;

    /**
     * @brief lopen
     * @param file
     * @param mode
     * @return
     */
    bool lopen(const std::string &file, DLog::Mode mode) override;

    /**
     * @brief lwrite
     * @param msg
     * @return
     */
    bool lwrite(const std::string &msg) override;

    /**
     * @brief close
     */
    void lclose() override;

private:
    FILE      *mp_File;
};

#endif // DLOGFOPEN_H
