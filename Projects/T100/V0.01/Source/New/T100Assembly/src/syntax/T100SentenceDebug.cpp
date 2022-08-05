#include "T100SentenceDebug.h"

T100SentenceDebug::T100SentenceDebug(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceDebug::~T100SentenceDebug()
{
    //dtor
}

T100BOOL T100SentenceDebug::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_DEBUG;
        m_token->type   = T100SENTENCE_DEBUG;
    }

    return result;
}

T100BOOL T100SentenceDebug::build(T100BuildInfo* info)
{

}
