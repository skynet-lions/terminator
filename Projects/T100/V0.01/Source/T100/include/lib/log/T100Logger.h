#ifndef T100LOGGER_H
#define T100LOGGER_H

#include "ILog.h"


template <typename StringType>

class T100Logger
{
    public:
        T100Logger() {}
        virtual ~T100Logger() {}

        static T100VOID             out(StringType&) {}

    protected:

    private:
};

#endif // T100LOGGER_H
