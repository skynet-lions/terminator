#ifndef T100SENTENCECMT_H
#define T100SENTENCECMT_H

#include "T100Sentence.h"


class T100SentenceCmt : public T100Sentence
{
    public:
        T100SentenceCmt(T100SentenceScanner*);
        virtual ~T100SentenceCmt();

    protected:

    private:
};

#endif // T100SENTENCECMT_H
