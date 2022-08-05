#include "T100SentenceOut.h"

T100SentenceOut::T100SentenceOut(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceOut::~T100SentenceOut()
{
    //dtor
}

T100BOOL T100SentenceOut::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);
    if(!result){
        return T100FALSE;
    }

    result = parseComplexus(source);

    if(result){
        type            = T100SENTENCE_OUT;
        m_token->type   = T100SENTENCE_OUT;
    }

    return result;
}

T100BOOL T100SentenceOut::build(T100BuildInfo* info)
{

}
