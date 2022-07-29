#ifndef T100SENTENCEOUT_H
#define T100SENTENCEOUT_H

#include "T100Sentence.h"


class T100SentenceOut : public T100Sentence
{
    public:
        T100SentenceOut(T100SentenceScanner*);
        virtual ~T100SentenceOut();

    protected:

    private:
};

#endif // T100SENTENCEOUT_H
