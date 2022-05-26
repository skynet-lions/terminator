#ifndef T100WINCONSOLE_H
#define T100WINCONSOLE_H

#include "T100ConsoleBase.h"


class T100WinConsole : public T100ConsoleBase
{
    public:
        T100WinConsole();
        virtual ~T100WinConsole();

        T100VOID                outline(T100WSTRING&);

        T100VOID                setForegroundColour(T100COLOUR_PRIMITIVE_TYPE);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100WINCONSOLE_H
