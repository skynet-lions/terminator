#include "T100CmdLineParameterScanner.h"

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
    m_scanner = dynamic_cast<T100CmdLineStringScanner*>(scanner);
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

    result = m_scanner->next(m_item);


}
