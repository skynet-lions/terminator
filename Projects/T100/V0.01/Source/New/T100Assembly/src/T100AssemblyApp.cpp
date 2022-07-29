#include "T100AssemblyApp.h"

#include "T100Assembly.h"


T100AssemblyApp::T100AssemblyApp()
{
    //ctor
}

T100AssemblyApp::~T100AssemblyApp()
{
    //dtor
}

T100BOOL T100AssemblyApp::run(int argc, wchar_t** argv)
{
    T100WSTRING     source;
    T100WSTRING     target;
    T100Assembly    assembly;

    return assembly.run(source, target);
}
