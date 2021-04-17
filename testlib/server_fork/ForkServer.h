#ifndef FORKSERVER_H
#define FORKSERVER_H

#include "DForkServer.h"

class ForkServer : public DForkServer
{
public:
    ForkServer();

    DRV run() override;
};

#endif // FORKSERVER_H
