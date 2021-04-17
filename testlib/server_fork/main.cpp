#include <QCoreApplication>
#include "ForkServer.h"
#include "DSignal.h"


ForkServer server;

int main(int argc, char *argv[])
{
    DSignal::ignoreAllSig();
//    DSignal::handleSig(SIGINT, fatherExit);
//    DSignal::handleSig(SIGTERM, fatherExit);

    if (DRV_OK != server.runServer(9988)) {
        std::cout << "Failed to runServer " << std::endl;
        return 0;
    }

    // *****************************
    /*
     * SIGCHLD信号
     *  子进程结束时, 父进程会收到这个信号,如果父进程没有处理这个信号，也没有等待(wait)子进程，子进程虽然终止，
     *  但是还会在内核进程表中占有表项，这时的子进程称为僵尸进程。这种情 况我们应该避免(父进程或者忽略SIGCHILD信号，
     *  或者捕捉它，或者wait它派生的子进程，或者父进程先终止，这时子进程的终止自动由init进程 来接管)
     * SIG_IGN忽略的意思
     */

}
