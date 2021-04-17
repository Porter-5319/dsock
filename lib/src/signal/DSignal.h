#ifndef DSIGNAL_H
#define DSIGNAL_H


class DSignal
{
public:
    DSignal();

    /**
     * @brief ignoreSig
     * @param sig
     */
    static void ignoreSig(int sig);

    /**
     * @brief ignoreAllSig
     */
    static void ignoreAllSig();

    /**
     * @brief ignoreSig
     * @param sig
     */
    static void defaultSig(int sig);

    /**
     * @brief handleSig
     * @param signum
     */
    static void handleSig(int sig, void (*handler)(int));
};

#endif // DSIGNAL_H
