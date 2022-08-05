#include "T100SentenceJnz.h"

T100SentenceJnz::T100SentenceJnz(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceJnz::~T100SentenceJnz()
{
    //dtor
}

T100BOOL T100SentenceJnz::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JNZ;
        m_token->type   = T100SENTENCE_JNZ;
    }

    return result;
}

T100BOOL T100SentenceJnz::build(T100BuildInfo* info)
{

}
