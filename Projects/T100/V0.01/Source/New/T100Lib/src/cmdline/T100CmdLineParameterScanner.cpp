#include "T100CmdLineParameterScanner.h"

#include "T100CmdLineCommon.h"

#include "T100CmdLineInfo.h"


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
    T100BOOL        result          = T100TRUE;

    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item.type){
    case T100CMDLINE_TOKEN_PROMPT:
        {

        }
        break;
    case T100CMDLINE_TOKEN_EXEC:
        {
            m_token->value  = m_item.exec;
            m_token->type   = T100CMDLINE_TOKEN_EXEC;
            return T100TRUE;
        }
        break;
    case T100CMDLINE_TOKEN_CHAR:
        {

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
