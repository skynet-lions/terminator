#ifndef ISTATE_H
#define ISTATE_H

#include "T100StateCommon.h"


class IState
{
    public:
        IState();
        virtual ~IState();

        T100STATE_ID            id      = 0;
        T100STATE_TYPE          type    = 0;

    protected:

    private:
};

#endif // ISTATE_H
