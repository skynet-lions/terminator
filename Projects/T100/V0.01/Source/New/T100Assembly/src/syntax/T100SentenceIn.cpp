#include "T100SentenceIn.h"

T100SentenceIn::T100SentenceIn(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceIn::~T100SentenceIn()
{
    //dtor
}

T100BOOL T100SentenceIn::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseComplexus(target);
    if(!result){
        return T100FALSE;
    }

    result = parseOperator(source);

    if(result){
        type            = T100SENTENCE_IN;
        m_token->type   = T100SENTENCE_IN;
    }

    return result;
}

T100BOOL T100SentenceIn::build(T100BuildInfo* info)
{

}
