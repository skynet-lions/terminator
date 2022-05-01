#include "T100Assembly.h"

#include <iomanip>
#include <sstream>
#include <iostream>

#include "T100AssemblyHelp.h"
#include "T100AsmCmdParser.h"
#include "T100Builder.h"


T100Console     T100Assembly::m_console;


T100Assembly::T100Assembly()
{
    //ctor
    create();
}

T100Assembly::~T100Assembly()
{
    //dtor
    destroy();
}

T100VOID T100Assembly::create()
{
    T100Log::trace(T100ASSEMBLY_HINT_START);

    T100AsmCmdParser* cmd = T100NEW T100AsmCmdParser();

    m_console.setCmdParser(cmd);
}

T100VOID T100Assembly::destroy()
{
    T100Log::trace(T100ASSEMBLY_HINT_STOP);
}

T100BOOL T100Assembly::add(T100STDSTRING path)
{
    if(path.empty()){
        return T100FALSE;
    }

    m_imports.push_back(path);

    return T100TRUE;
}

T100BOOL T100Assembly::run(T100STDSTRING source, T100STDSTRING target)
{
    T100BOOL        result;
    T100Builder     builder;

    for(auto path : m_imports){
        builder.add(path);
    }

    T100Log::info(T100AssemblyHint::file_hint(source, "Assembly run..."));
    result = builder.run(source, target);

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(source, "Assembly success!"));

        std::cout << "\n!!!SUCCESS!!!\n";
    }else{
        T100Error::error(T100AssemblyHint::file_hint(source, "Assembly failure!"));
        //T100AssemblyError::print();

        std::cout << "\n!!!FAILURE!!!\n";
    }

    info();

    return result;
}

T100BOOL T100Assembly::run(T100STDSTRING& file)
{
    T100BOOL        result;
    T100Builder     builder;

    T100STDSTRING   target;

    //test
    target = "out";

    for(auto path : m_imports){
        builder.add(path);
    }
    //test
    builder.add(".");


    T100Log::info(T100AssemblyHint::file_hint(file, "Assembly run..."));
    result = builder.run(file, target);

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, "Assembly success!"));

        std::cout << "\n!!!SUCCESS!!!\n";
    }else{
        T100Error::error(T100AssemblyHint::file_hint(file, "Assembly failure!"));
        //T100AssemblyError::print();

        std::cout << "\n!!!FAILURE!!!\n";
    }

    return result;
}

T100VOID T100Assembly::help()
{
    T100AssemblyHelp help;

    help.show();
}

T100VOID T100Assembly::info()
{
    T100Log::info(T100AssemblyHint::info_hint(""));
}
