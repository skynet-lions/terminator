#include "T100AssemblyApp.h"

#include "T100Assembly.h"
#include "T100AssemblyCmdLineParser.h"
#include "T100CmdLineStringScanner.h"
#include "T100CmdLineCharScanner.h"
#include "T100AssemblyCmdLineParameterScanner.h"



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

    T100AssemblyCmdLineInfo         info;

    result = parse(argc, argv, &info);
    if(!result){
        return T100FALSE;
    }

    return assembly.run(source, target);
}

T100BOOL T100AssemblyApp::parse(int argc, wchar_t** argv, T100AssemblyCmdLineInfo* info)
{
    T100BOOL                                result;
    T100AssemblyCmdLineParser               parser;

    result = parser.parse(argc, argv);
    if(!result){
        return T100FALSE;
    }

    return result;
}
