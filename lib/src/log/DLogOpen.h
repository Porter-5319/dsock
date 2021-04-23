#ifndef DLOGSYSTEM_H
#define DLOGSYSTEM_H

#include "DLog.h"

class DLogOpen : public DLog
{
public:
    DLogOpen();
    ~DLogOpen() override;

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
    int        m_FD;
};

#endif // DLOGSYSTEM_H
