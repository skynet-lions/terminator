#include "T100AssemblyApp.h"

T100AssemblyApp::T100AssemblyApp()
{
    //ctor
    create();
}

T100AssemblyApp::~T100AssemblyApp()
{
    //dtor
    destroy();
}

T100VOID T100AssemblyApp::create()
{
    T100BOOL            result;

    result = m_tank.start();
    if(!result){
        return;
    }

    result = m_tank.load(L"assembly", L"T100Assembly.dll");
    if(!result){
        return;
    }

    result = m_tank.find(L"assembly", m_library);
    if(!result){
        return;
    }
}

T100VOID T100AssemblyApp::destroy()
{

}

T100BOOL T100AssemblyApp::run(T100WSTRING source, T100WSTRING target)
{
    T100BOOL            result;
    T100BOOL(*method)(T100WSTRING, T100WSTRING)         = T100NULL;

    T100VOID*           handle          = T100NULL;


    handle = m_library->getMethod(L"assembly");

    method = reinterpret_cast<T100BOOL(*)(T100WSTRING, T100WSTRING)>(handle);

    result = method(source, target);

    return T100FALSE;
}
