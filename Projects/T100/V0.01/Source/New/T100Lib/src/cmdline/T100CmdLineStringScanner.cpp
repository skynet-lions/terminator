#include "T100CmdLineStringScanner.h"

T100CmdLineStringScanner::T100CmdLineStringScanner()
{
    //ctor
}

T100CmdLineStringScanner::~T100CmdLineStringScanner()
{
    //dtor
}

T100VOID T100CmdLineStringScanner::setSource(int argc, wchar_t** argv)
{
    m_index     = 0;
    m_argc      = argc;
    m_argv      = argv;
}

T100BOOL T100CmdLineStringScanner::next(T100Token& token)
{
    m_token = (T100CmdLineStringToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100CmdLineStringScanner::run()
{
    if(m_index <= m_argc){
        m_token->value = m_argv[m_index++];
        return T100TRUE;
    }
    return T100FALSE;
}
