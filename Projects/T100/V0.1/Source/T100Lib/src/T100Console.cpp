#include "T100Console.h"

#include "T100ConsoleLog.h"
#include "T100ConsoleWin.h"


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
    case T100CONSOLE_COMMON:
        {
            //m_console = T100NEW T100CommonConsole();
        }
        break;
    case T100CONSOLE_WINDOWS:
        {
            m_console = T100NEW T100ConsoleWin();
        }
        break;
    case T100CONSOLE_LOG:
        {
            m_console = T100NEW T100ConsoleLog();
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

T100VOID T100Console::getline(T100WSTRING& msg)
{
    m_console->getline(msg);
}
