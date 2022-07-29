#ifndef T100SENTENCEEND_H
#define T100SENTENCEEND_H

#include "T100Sentence.h"


class T100SentenceEnd : public T100Sentence
{
    public:
        T100SentenceEnd(T100SentenceScanner*);
        virtual ~T100SentenceEnd();

    protected:

    private:
};

#endif // T100SENTENCEEND_H
