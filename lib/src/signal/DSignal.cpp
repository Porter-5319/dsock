#include "DSignal.h"
#include "../Common.h"
DSignal::DSignal()
{

}

void DSignal::ignoreSig(int sig)
{
    signal(sig, SIG_IGN);
}

void DSignal::defaultSig(int sig)
{
    signal(sig, SIG_DFL);
}

void DSignal::ignoreAllSig()
{
    for (int i = 0; i <= 64; i++) {
        signal(i, SIG_IGN);
    }
}

void DSignal::handleSig(int sig, void (*handler)(int))
{
    // void ( *signal(int signum, void (*handler)(int)) ) (int);
    signal(sig, handler);
}
