#include "T100CmdLineCharScanner.h"

T100CmdLineCharScanner::T100CmdLineCharScanner()
{
    //ctor
}

T100CmdLineCharScanner::~T100CmdLineCharScanner()
{
    //dtor
}

T100VOID T100CmdLineCharScanner::setSource(T100Scanner* scanner)
{
    m_scanner = dynamic_cast<T100CmdLineStringScanner*>(scanner);
}

T100Scanner* T100CmdLineCharScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100CmdLineCharScanner::next(T100Token& token)
{
    m_token = (T100CmdLineCharToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100CmdLineCharScanner::run()
{

}
