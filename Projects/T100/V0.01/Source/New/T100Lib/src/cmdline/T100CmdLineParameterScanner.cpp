#include "T100CmdLineParameterScanner.h"

#include "T100CmdLineCommon.h"

#include "T100CmdLineInfo.h"
#include "T100CmdLineExec.h"
#include "T100CmdLineParam.h"


T100CmdLineParameterScanner::T100CmdLineParameterScanner()
{
    //ctor
}

T100CmdLineParameterScanner::~T100CmdLineParameterScanner()
{
    //dtor
}

T100VOID T100CmdLineParameterScanner::setSource(T100Scanner* scanner)
{
    m_scanner = dynamic_cast<T100CmdLineCharScanner*>(scanner);
}

T100Scanner* T100CmdLineParameterScanner::getSource()
{
    return m_scanner;
}

T100VOID T100CmdLineParameterScanner::setInfo(T100CmdLineInfo* info)
{
    m_info = info;
}

T100BOOL T100CmdLineParameterScanner::next(T100Token& token)
{
    m_token = (T100CmdLineParameterToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100CmdLineParameterScanner::run()
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;
    T100CmdLineInfo*        info            = T100NULL;

    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item.type){
    case T100CMDLINE_TOKEN_PROMPT:
        {
            info = T100NEW T100CmdLineInfo();

            info->parse(this);
        }
        break;
    case T100CMDLINE_TOKEN_EXEC:
        {
            m_token->value  = T100NEW T100CmdLineExec();
            m_token->type   = T100CMDLINE_TOKEN_EXEC;
            return T100TRUE;
        }
        break;
    case T100CMDLINE_TOKEN_CHAR:
        {
            info = T100NEW T100CmdLineParam();

            info->parse(this);
        }
        break;
    }

    return result;
}

T100BOOL T100CmdLineParameterScanner::read()
{
    T100BOOL            result          = T100TRUE;

    result = m_scanner->next(m_item);

    return result;
}

T100BOOL T100CmdLineParameterScanner::append()
{

}

T100BOOL T100CmdLineParameterScanner::classify()
{

}
