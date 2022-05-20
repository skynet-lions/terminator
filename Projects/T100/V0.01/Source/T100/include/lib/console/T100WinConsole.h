#ifndef T100WINCONSOLE_H
#define T100WINCONSOLE_H

#include "T100ConsoleBase.h"
#include "T100GraphicCommon.h"


class T100WinConsole : public T100ConsoleBase
{
    public:
        T100WinConsole();
        virtual ~T100WinConsole();

        T100VOID                out(T100STDSTRING);
        T100VOID                out(T100STDWSTRING);

        T100VOID                outline(T100STDSTRING);
        T100VOID                outline(T100STDSTRING, T100COLOUR_PRIMITIVE_TYPE);

        T100VOID                outline(T100STDWSTRING);


        T100VOID                        setForegroundColour(T100COLOUR_PRIMITIVE_TYPE);
        T100COLOUR_PRIMITIVE_TYPE       getForegroundColour();

        T100VOID                        setBackgroundColour(T100COLOUR_PRIMITIVE_TYPE);
        T100COLOUR_PRIMITIVE_TYPE       getBackgroundColour();

    protected:
        T100VOID                create();
        T100VOID                destroy();


        T100COLOUR_PRIMITIVE_TYPE       m_foreground        = T100COLOUR_WHITE;
        T100COLOUR_PRIMITIVE_TYPE       m_background        = T100COLOUR_BLACK;

    private:
};

#endif // T100WINCONSOLE_H
