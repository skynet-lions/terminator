#include "T100ConsoleLog.h"

#include "T100Log.h"


T100ConsoleLog::T100ConsoleLog()
{
    //ctor
}

T100ConsoleLog::~T100ConsoleLog()
{
    //dtor
}

T100VOID T100ConsoleLog::outline(T100WSTRING& msg)
{
    T100Log::info(msg);
}

T100VOID T100ConsoleLog::getline(T100WSTRING& msg)
{

}
