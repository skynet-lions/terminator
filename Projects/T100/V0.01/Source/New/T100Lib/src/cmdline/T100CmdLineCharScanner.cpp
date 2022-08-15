#include "T100CmdLineCharScanner.h"

#include "T100ConsoleCommon.h"
#include "T100CmdLineCommon.h"


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
    T100BOOL            result          = T100TRUE;


    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item.type){
    case T100CMDLINE_TOKEN_EXEC:
        {
            m_token->exec   = m_item.value;
            m_token->type   = m_item.type;
            m_item.value.clear();
            return T100TRUE;
        }
        break;
    }

    result = append();

    if(!result){
        return T100FALSE;
    }

    result = classify();

    if(!result){
        return T100FALSE;
    }

    return result;
}

T100BOOL T100CmdLineCharScanner::read()
{
    T100BOOL            result          = T100TRUE;

    if(m_index >= m_item.value.size()){
        result = m_scanner->next(m_item);
        if(result){
            m_index = 0;
        }else{
            return T100FALSE;
        }
    }else{
        m_index++;
    }

    return T100TRUE;
}

T100BOOL T100CmdLineCharScanner::append()
{
    m_token->value = m_item.value[m_index];

    return T100TRUE;
}

T100BOOL T100CmdLineCharScanner::classify()
{
    if(T100CONSOLE_COMMAND_PROMPT_DEFAULT == m_token->value){
        m_token->type   = T100CMDLINE_TOKEN_PROMPT;
    }else{
        m_token->type   = T100CMDLINE_TOKEN_CHAR;
    }

    return T100TRUE;
}
