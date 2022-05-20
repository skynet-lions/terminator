#ifndef T100CONSOLE_H
#define T100CONSOLE_H

#include "T100ConsoleBase.h"

class T100Console
{
    public:
        T100Console(T100CONSOLE_TYPE type = T100CONSOLE_WINDOWS);
        virtual ~T100Console();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100CONSOLE_TYPE            m_type          = T100CONSOLE_NONE;
        T100ConsoleBase*            m_base          = T100NULL;

};

#endif // T100CONSOLE_H
