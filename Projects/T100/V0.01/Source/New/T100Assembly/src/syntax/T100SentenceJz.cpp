#include "T100SentenceJz.h"

T100SentenceJz::T100SentenceJz(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceJz::~T100SentenceJz()
{
    //dtor
}

T100BOOL T100SentenceJz::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JZ;
        m_token->type   = T100SENTENCE_JZ;
    }

    return result;
}

T100BOOL T100SentenceJz::build(T100BuildInfo* info)
{

}
