#include "T100SentenceMove.h"

T100SentenceMove::T100SentenceMove(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceMove::~T100SentenceMove()
{
    //dtor
}

T100BOOL T100SentenceMove::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(ops);

    if(result){
        type            = T100SENTENCE_MOVE;
        m_token->type   = T100SENTENCE_MOVE;
    }

    return result;
}

T100BOOL T100SentenceMove::build(T100BuildInfo* info)
{

}
