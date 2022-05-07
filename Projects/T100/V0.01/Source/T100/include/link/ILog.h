#ifndef ILOG_H
#define ILOG_H

#include "T100Common.h"

template <typename StringType>

class ILog
{
    public:
        ILog() {}
        virtual ~ILog() {}

        virtual T100VOID        out(StringType&)=0;

    protected:

    private:
};

#endif // ILOG_H
