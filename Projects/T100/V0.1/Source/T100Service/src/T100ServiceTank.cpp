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

T100BOOL T100ServiceTank::find(T100WSTRING name, T100Library*& lib)
{
    lib = m_hash[name];
    return T100TRUE;
}

T100BOOL T100ServiceTank::load(T100WSTRING name, T100WSTRING file)
{
    T100BOOL            result;
    T100WSTRING         path;
    T100VOID*           handle;

    path = m_root + L"\\" + file;

    T100Library*    obj     = T100NEW T100Library(path);

    if(!obj){
        return T100FALSE;
    }

    result = obj->load();
    if(!result){
        T100SAFE_DELETE(obj);
        return T100FALSE;
    }

    m_hash[name] = obj;

    return T100TRUE;
}

T100BOOL T100ServiceTank::verify(T100WSTRING file, T100BOOL loaded)
{
    T100BOOL            result;
    T100WSTRING         name;
    T100WSTRING         path;
    T100VOID*           handle;

    path = m_root + L"\\" + file;

    T100Library*    obj         = T100NEW T100Library(path);

    if(!obj){
        return T100FALSE;
    }

    result = obj->load();
    if(!result){
        T100SAFE_DELETE(obj);
        return T100FALSE;
    }

    T100WSTRING(*method)();

    if(loaded){
        handle = obj->getMethod(L"service_name");
        if(!handle){
            obj->unload();
            T100SAFE_DELETE(obj);
        }

        method = reinterpret_cast<T100WSTRING(*)()>(handle);
        name = method();
        if(name.empty()){
            obj->unload();
            T100SAFE_DELETE(obj);
        }

        m_hash[name] = obj;
    }else{
        obj->unload();
        T100SAFE_DELETE(obj);
    }

    return T100TRUE;
}
