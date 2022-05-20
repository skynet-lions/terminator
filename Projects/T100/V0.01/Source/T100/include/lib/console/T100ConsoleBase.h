#ifndef T100CONSOLEBASE_H
#define T100CONSOLEBASE_H

#include "T100ConsoleCommon.h"


class T100ConsoleBase
{
    public:
        T100ConsoleBase();
        virtual ~T100ConsoleBase();

        virtual T100VOID            outline(T100STDSTRING) = 0;

    protected:

    private:
};

#endif // T100CONSOLEBASE_H
