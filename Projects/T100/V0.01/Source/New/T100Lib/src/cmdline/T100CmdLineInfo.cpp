#include "T100CmdLineInfo.h"

#include "T100CmdLineParameterScanner.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineSwitch.h"


T100CmdLineInfo::T100CmdLineInfo()
{
    //ctor
}

T100CmdLineInfo::~T100CmdLineInfo()
{
    //dtor
}

T100BOOL T100CmdLineInfo::parse(T100CmdLineParameterScanner* scanner)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100CmdLineInfo*    info            = T100NULL;
    T100WCHAR           first;
    T100WCHAR           second;

    value = scanner->read();
    if(!value){
        return T100FALSE;
    }

    value = scanner->read();
    if(!value){
        return T100FALSE;
    }

    switch(scanner->m_item.type){
    case T100CMDLINE_TOKEN_EQUAL:
        {
            info = T100NEW T100CmdLineOption();

            info->parse(scanner);
        }
        break;
    case T100CMDLINE_TOKEN_CHAR:
        {
            info = T100NEW T100CmdLineSwitch();

            info->parse(scanner);
        }
        break;
    case T100CMDLINE_TOKEN_END:
        {
            info = T100NEW T100CmdLineSwitch();
        }
        break;
    case T100CMDLINE_TOKEN_EOF:
        {
            info = T100NEW T100CmdLineSwitch();
        }
        break;
    default:
        {
            return T100FALSE;
        }
        break;
    }

    return T100TRUE;
}
