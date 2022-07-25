#ifndef T100CLOCK_H
#define T100CLOCK_H

#include "T100Common.h"


class T100Clock
{
    public:
        T100Clock();
        virtual ~T100Clock();

        T100WORD            second();

        T100WORD            millisecond();

        T100WORD            microsecond();

        T100WORD            nanosecond();

    protected:

    private:
};

#endif // T100CLOCK_H
