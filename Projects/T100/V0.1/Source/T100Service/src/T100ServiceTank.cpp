#include "T100ServiceTank.h"

#include "T100Library.h"


T100ServiceTank::T100ServiceTank()
{
    //ctor
    create();
}

T100ServiceTank::~T100ServiceTank()
{
    //dtor
    destroy();
}

T100VOID T100ServiceTank::create()
{
    m_root = L"..\\plugin";
}

T100VOID T100ServiceTank::destroy()
{

}

T100BOOL T100ServiceTank::start()
{
    return T100TRUE;
}

T100BOOL T100ServiceTank::stop()
{
    return T100FALSE;
}

T100BOOL T100ServiceTank::find(T100WSTRING name, T100VOID* handle)
{
    return T100FALSE;
}

T100BOOL T100ServiceTank::load(T100WSTRING file)
{
    T100BOOL        result;
    T100WSTRING     name;

    name = m_root + L"\\" + file;

    T100Library*    obj     = T100NEW T100Library(name);

    if(!obj){
        return T100FALSE;
    }

    result = obj->load();
    if(!result){
        return T100FALSE;
    }

    return T100TRUE;
}
