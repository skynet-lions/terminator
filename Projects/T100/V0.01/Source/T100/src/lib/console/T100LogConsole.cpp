#include "T100LogConsole.h"

#include "T100Log.h"


T100LogConsole::T100LogConsole()
{
    //ctor
}

T100LogConsole::~T100LogConsole()
{
    //dtor
}

T100VOID T100LogConsole::outline(T100WSTRING& msg)
{
    T100Log::info(msg);
}
