#include "T100SentenceJump.h"

T100SentenceJump::T100SentenceJump(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceJump::~T100SentenceJump()
{
    //dtor
}

T100BOOL T100SentenceJump::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JUMP;
        m_token->type   = T100SENTENCE_JUMP;
    }

    return result;
}

T100BOOL T100SentenceJump::build(T100BuildInfo* info)
{

}
