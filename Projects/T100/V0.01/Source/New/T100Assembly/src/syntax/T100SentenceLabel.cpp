#include "T100SentenceLabel.h"

T100SentenceLabel::T100SentenceLabel(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceLabel::~T100SentenceLabel()
{
    //dtor
}

T100BOOL T100SentenceLabel::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        name            = m_item->value;
        type            = T100SENTENCE_LABEL;
        m_token->type   = T100SENTENCE_LABEL;
    }

    return result;
}

T100BOOL T100SentenceLabel::build(T100BuildInfo* info)
{

}
