#include "T100AppTools.h"

#include "T100Log.h"


T100AppTools::T100AppTools()
{
    //ctor
}

T100AppTools::~T100AppTools()
{
    //dtor
}

T100VOID T100AppTools::init()
{
    T100Log::start();

    T100WSTRING     str;

    str = L"你好";

    T100Log::out(str);
}

T100VOID T100AppTools::uninit()
{
    T100Log::stop();
}
