#include "T100SentenceCall.h"

T100SentenceCall::T100SentenceCall(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceCall::~T100SentenceCall()
{
    //dtor
}

T100BOOL T100SentenceCall::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseProcedure();

    if(result){
        type            = T100SENTENCE_CALL;
        m_token->type   = T100SENTENCE_CALL;
    }

    return result;
}

T100BOOL T100SentenceCall::parseProcedure()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:
    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_LABEL:
        {
            name    = m_item->value;

            setLoaded(T100FALSE);
            return T100TRUE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

    //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceCall::build(T100BuildInfo* info)
{

}
