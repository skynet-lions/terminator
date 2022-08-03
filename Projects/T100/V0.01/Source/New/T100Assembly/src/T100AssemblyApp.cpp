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
    T100BOOL        result;
    T100WSTRING     source;
    T100WSTRING     target;
    T100Assembly    assembly;

    T100AssemblyInfo        info;

    result = parse(argc, argv, &info);
    if(!result){
        return T100FALSE;
    }

    return assembly.run(source, target);
}

T100BOOL T100AssemblyApp::parse(int argc, wchar_t** argv, T100AssemblyInfo* info)
{
    T100BOOL        result;

    return result;
}
