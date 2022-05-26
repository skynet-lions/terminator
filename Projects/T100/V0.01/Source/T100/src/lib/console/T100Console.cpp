#include "T100Console.h"

#include "T100LogConsole.h"
#include "T100WinConsole.h"


T100Console::T100Console(T100CONSOLE_TYPE type)
    :m_type(type)
{
    //ctor
    create();
}

T100Console::~T100Console()
{
    //dtor
    destroy();
}

T100VOID T100Console::create()
{
    switch(m_type){
    case T100CONSOLE_WINDOWS:
        {
            m_console = T100NEW T100WinConsole();
        }
        break;
    case T100CONSOLE_LOG:
        {
            m_console = T100NEW T100LogConsole();
        }
        break;
    default:
        break;
    }
}

T100VOID T100Console::destroy()
{
    T100SAFE_DELETE(m_console);
}

T100VOID T100Console::outline(T100WSTRING& msg)
{
    m_console->outline(msg);
}
