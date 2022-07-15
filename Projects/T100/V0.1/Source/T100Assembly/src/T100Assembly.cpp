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
    T100VOID*               handle          = T100NULL;
    T100AssemblyService*    service         = T100NULL;


    result = tank.start();
    if(!result){
        return T100FALSE;
    }

    result = tank.load(L"T100Assembly.dll");
    if(!result){
        return T100FALSE;
    }

    result = tank.find(L"assembly", handle);
    if(!result){
        return T100FALSE;
    }
    if(!handle){
        return T100FALSE;
    }

    service = reinterpret_cast<T100AssemblyService*>(handle);



    return T100TRUE;
}
