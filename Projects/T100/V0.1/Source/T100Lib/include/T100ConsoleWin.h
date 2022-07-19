#ifndef T100CONSOLEWIN_H
#define T100CONSOLEWIN_H

#include "T100ConsoleBase.h"


class T100ConsoleWin : public T100ConsoleBase
{
    public:
        T100ConsoleWin();
        virtual ~T100ConsoleWin();

        T100VOID            outline(T100WSTRING&);

        T100VOID            getline(T100WSTRING&);

        T100VOID            setForegroundColour(T100COLOUR_PRIMITIVE_TYPE);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100CONSOLEWIN_H
