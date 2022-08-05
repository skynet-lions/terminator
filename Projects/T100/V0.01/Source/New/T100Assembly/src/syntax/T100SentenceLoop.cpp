#include "T100SentenceLoop.h"

T100SentenceLoop::T100SentenceLoop(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceLoop::~T100SentenceLoop()
{
    //dtor
}

T100BOOL T100SentenceLoop::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_LOOP;
        m_token->type   = T100SENTENCE_LOOP;
    }

    return result;
}

T100BOOL T100SentenceLoop::build(T100BuildInfo* info)
{

}
