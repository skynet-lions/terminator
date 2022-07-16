#include "T100Assembly.h"

#include "T100AssemblyService.h"


T100Assembly::T100Assembly()
{
    //ctor
}

T100Assembly::~T100Assembly()
{
    //dtor
}

T100BOOL T100Assembly::run(T100WSTRING source, T100WSTRING target)
{
    T100BOOL                result;
    T100ServiceTank         tank;
    T100BOOL(*method)(T100WSTRING, T100WSTRING)         = T100NULL;
    T100Library*            lib             = T100NULL;
    T100VOID*               handle          = T100NULL;


    result = tank.start();
    if(!result){
        return T100FALSE;
    }

    result = tank.load(L"assembly", L"T100Assembly.dll");
    if(!result){
        return T100FALSE;
    }

    result = tank.find(L"assembly", lib);
    if(!result){
        return T100FALSE;
    }
    if(!lib){
        return T100FALSE;
    }

    handle = lib->getMethod(L"assembly");

    method = reinterpret_cast<T100BOOL(*)(T100WSTRING, T100WSTRING)>(handle);

    result = method(source, target);

    return T100TRUE;
}
