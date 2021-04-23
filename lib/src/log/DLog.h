#ifndef DLOG_H
#define DLOG_H

#include <stdio.h>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

class DLog
{
public:
    /**
     * @brief The Mode enum
     */
    enum Mode {
        DRead      = 0x000,               //<! Read only , return false if the file does not exit
        DWrite     = 0x001,               //<! Write only , and create a new file if it doesn't exist
        DReadWrite = 0x002,               //<! Read and Write , create a new file if it doesn't exist
        DAppend    = 0x003                //<! Append , create a new file if it doesn't exist
    };

    DLog();
    virtual ~DLog();

    /**
     * @brief lopen
     * @param file
     * @param mode
     * @return
     */
    virtual bool lopen(const std::string &file, Mode mode) = 0;

    /**
     * @brief lwrite
     * @param msg
     * @return
     */
    virtual bool lwrite(const std::string &msg) = 0;

    /**
     * @brief close
     */
    virtual void lclose() = 0;

protected:
    /**
     * @brief getIntMode
     * @param mode
     * @return
     */
    int getIntMode(const Mode mode);

    /**
     * @brief getCharMode
     * @param mode
     * @return
     */
    const char *getCharMode(const Mode mode);
};

#endif // DLOG_H
