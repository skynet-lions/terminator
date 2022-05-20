#include "T100WinConsole.h"

#include <iostream>
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

T100COLOUR_PRIMITIVE_TYPE T100WinConsole::getForegroundColour()
{
    return m_foreground;
}

T100VOID T100WinConsole::setBackgroundColour(T100COLOUR_PRIMITIVE_TYPE type)
{
    m_background    = type;
}

T100COLOUR_PRIMITIVE_TYPE T100WinConsole::getBackgroundColour()
{
    return m_background;
}

T100VOID T100WinConsole::out(T100STDSTRING msg)
{
    std::cout << msg;
}

T100VOID T100WinConsole::out(T100STDWSTRING msg)
{
    wprintf(msg.c_str());
}

T100VOID T100WinConsole::outline(T100STDSTRING msg)
{
    std::cout << msg << std::endl;
}

T100VOID T100WinConsole::outline(T100STDWSTRING msg)
{
    wprintf(msg.c_str());
    wprintf(L"\n");
}

T100VOID T100WinConsole::outline(T100STDSTRING msg, T100COLOUR_PRIMITIVE_TYPE type)
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
        m_foreground = type;
    }

}
