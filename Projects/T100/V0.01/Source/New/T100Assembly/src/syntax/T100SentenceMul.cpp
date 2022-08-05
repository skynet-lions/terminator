#include "T100SentenceMul.h"

T100SentenceMul::T100SentenceMul(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceMul::~T100SentenceMul()
{
    //dtor
}

T100BOOL T100SentenceMul::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_MUL;
        m_token->type   = T100SENTENCE_MUL;
    }

    return result;
}

T100BOOL T100SentenceMul::build(T100BuildInfo* info)
{

}
