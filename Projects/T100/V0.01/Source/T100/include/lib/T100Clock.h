#ifndef T100CLOCK_H
#define T100CLOCK_H

#include "T100Common.h"


class T100Clock
{
    public:
        T100Clock();
        virtual ~T100Clock();

        static T100WORD         second();

    protected:

    private:
};

#endif // T100CLOCK_H
