#include "T100Service.h"

T100Service::T100Service()
{
    //ctor
}

T100Service::~T100Service()
{
    //dtor
}

T100WSTRING T100Service::Name()
{
    T100WSTRING     result;

    return result;
}

T100BOOL T100Service::Register()
{
    return T100FALSE;
}

T100BOOL T100Service::Unsubscribe()
{
    return T100FALSE;
}

T100BOOL T100Service::Load()
{
    return T100FALSE;
}

T100BOOL T100Service::Unload()
{
    return T100FALSE;
}

T100BOOL T100Service::Create()
{
    return T100FALSE;
}

T100BOOL T100Service::Destroy()
{
    return T100FALSE;
}

T100BOOL T100Service::Start()
{
    return T100FALSE;
}

T100BOOL T100Service::Stop()
{
    return T100FALSE;
}
