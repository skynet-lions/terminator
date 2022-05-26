#ifndef T100LOGCONSOLE_H
#define T100LOGCONSOLE_H

#include "T100ConsoleBase.h"


class T100LogConsole : public T100ConsoleBase
{
    public:
        T100LogConsole();
        virtual ~T100LogConsole();

        T100VOID            outline(T100WSTRING&);

    protected:

    private:
};

#endif // T100LOGCONSOLE_H
