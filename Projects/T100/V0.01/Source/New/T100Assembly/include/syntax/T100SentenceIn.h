#ifndef T100SENTENCEIN_H
#define T100SENTENCEIN_H

#include "T100Sentence.h"


class T100SentenceIn : public T100Sentence
{
    public:
        T100SentenceIn(T100SentenceScanner*);
        virtual ~T100SentenceIn();

    protected:

    private:
};

#endif // T100SENTENCEIN_H
