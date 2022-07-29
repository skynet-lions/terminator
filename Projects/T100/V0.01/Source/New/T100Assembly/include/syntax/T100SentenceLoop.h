#ifndef T100SENTENCELOOP_H
#define T100SENTENCELOOP_H

#include "T100Sentence.h"


class T100SentenceLoop : public T100Sentence
{
    public:
        T100SentenceLoop(T100SentenceScanner*);
        virtual ~T100SentenceLoop();

    protected:

    private:
};

#endif // T100SENTENCELOOP_H
