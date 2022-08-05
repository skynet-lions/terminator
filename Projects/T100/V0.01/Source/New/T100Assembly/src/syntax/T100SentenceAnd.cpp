#include "T100SentenceAnd.h"

T100SentenceAnd::T100SentenceAnd(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceAnd::~T100SentenceAnd()
{
    //dtor
}

T100BOOL T100SentenceAnd::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_AND;
        m_token->type   = T100SENTENCE_AND;
    }

    return result;
}

T100BOOL T100SentenceAnd::build(T100BuildInfo* info)
{

}
