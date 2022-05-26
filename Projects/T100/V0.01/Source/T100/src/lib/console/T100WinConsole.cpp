#include "T100WinConsole.h"

#include <windows.h>


T100WinConsole::T100WinConsole()
{
    //ctor
    create();
}

T100WinConsole::~T100WinConsole()
{
    //dtor
    destroy();
}

T100VOID T100WinConsole::create()
{
    setlocale(LC_ALL, "");
}

T100VOID T100WinConsole::destroy()
{

}

T100VOID T100WinConsole::setForegroundColour(T100COLOUR_PRIMITIVE_TYPE type)
{
    T100WORD    colour      = 0;

    switch(type){
    case T100COLOUR_BLACK:
        {
            colour = 0;
        }
        break;
    case T100COLOUR_WHITE:
        {
            colour = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_RED:
        {
            colour = FOREGROUND_RED;
        }
        break;
    case T100COLOUR_GREEN:
        {
            colour = FOREGROUND_GREEN;
        }
        break;
    case T100COLOUR_BLUE:
        {
            colour = FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_ORANGE:
        {
            colour = FOREGROUND_RED | FOREGROUND_GREEN;
        }
        break;
    case T100COLOUR_YELLOW:
        {
            colour = FOREGROUND_RED | FOREGROUND_BLUE;
        }
        break;
    case T100COLOUR_PURPLE:
        {
            colour = FOREGROUND_BLUE | FOREGROUND_GREEN;
        }
        break;
    default:
        break;
    };

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(INVALID_HANDLE_VALUE == handle)return;

    WINBOOL result = SetConsoleTextAttribute(handle, colour);

    if(result){
        T100ConsoleBase::setForegroundColour(type);
    }

}

/*
T100VOID T100WinConsole::outline(T100STDSTRING& msg, T100COLOUR_PRIMITIVE_TYPE type)
{
    if(m_foreground == type){
        outline(msg);
    }else{
        T100COLOUR_PRIMITIVE_TYPE   colour;

        colour = m_foreground;
        setForegroundColour(type);
        outline(msg);
        setForegroundColour(colour);
    }
}
*/

T100VOID T100WinConsole::outline(T100WSTRING& msg)
{
    wprintf(L"%s\n", msg);
}
