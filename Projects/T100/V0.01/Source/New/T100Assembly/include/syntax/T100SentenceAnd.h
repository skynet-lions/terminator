#ifndef T100SENTENCEAND_H
#define T100SENTENCEAND_H

#include "T100Sentence.h"


class T100SentenceAnd : public T100Sentence
{
    public:
        T100SentenceAnd(T100SentenceScanner*);
        virtual ~T100SentenceAnd();

    protected:

    private:
};

#endif // T100SENTENCEAND_H
