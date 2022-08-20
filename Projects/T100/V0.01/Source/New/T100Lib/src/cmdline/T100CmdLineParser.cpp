#include "T100CmdLineParser.h"

#include "T100CmdLineStringScanner.h"
#include "T100CmdLineCharScanner.h"
#include "T100CmdLineParameterScanner.h"


T100CmdLineParser::T100CmdLineParser()
{
    //ctor
}

T100CmdLineParser::~T100CmdLineParser()
{
    //dtor
}

T100BOOL T100CmdLineParser::parse(int argc, wchar_t** argv)
{
    T100BOOL                        result;

    T100CmdLineStringScanner        strscanner;
    T100CmdLineCharScanner          chscanner;
    T100CmdLineParameterScanner     parascanner;

    T100CmdLineParameterToken       token;

    strscanner.setSource(argc, argv);
    chscanner.setSource(&strscanner);
    parascanner.setSource(&chscanner);

    while(parascanner.next(token)){

        switch(token.type){
        case T100CMDLINE_TOKEN_EXEC:
            {

                return T100TRUE;
            }
            break;
        }

    }

    return T100TRUE;
}

T100BOOL T100CmdLineParser::findExec(T100CmdLineExec& exec)
{
    exec.value = m_exec;
    return T100TRUE;
}

T100BOOL T100CmdLineParser::findSwitch(T100WSTRING key, T100CmdLineSwitch& target)
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;

    T100CmdLineInfo*        temp            = T100NULL;

    temp = m_switchs[key];

    if(temp){
        target = static_cast<T100CmdLineSwitch&>(*temp);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CmdLineParser::findOption(T100WSTRING key, T100CmdLineOption& target)
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;

    T100CmdLineInfo*        temp            = T100NULL;

    temp = m_options[key];

    if(temp){
        target = static_cast<T100CmdLineOption&>(*temp);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CmdLineParser::findParam(T100CmdLineParam& target)
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;

    T100CmdLineInfo*        temp            = T100NULL;

    temp = m_params[m_index++];

    if(temp){
        target = static_cast<T100CmdLineParam&>(*temp);
    }else{
        result = T100FALSE;
    }

    return result;
}
