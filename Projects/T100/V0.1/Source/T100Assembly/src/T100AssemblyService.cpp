#include "T100AssemblyService.h"

#include "T100Assembly.h"


T100AssemblyService::T100AssemblyService()
{
    //ctor
}

T100AssemblyService::~T100AssemblyService()
{
    //dtor
}

T100WSTRING T100AssemblyService::Name()
{
    return L"Assembly";
}

T100BOOL T100AssemblyService::Run(T100WSTRING source, T100WSTRING target)
{
    T100Assembly        assembly;

    return assembly.run(source, target);
}
