#ifndef T100SENTENCEDEBUG_H
#define T100SENTENCEDEBUG_H

#include "T100Sentence.h"


class T100SentenceDebug : public T100Sentence
{
    public:
        T100SentenceDebug(T100SentenceScanner*);
        virtual ~T100SentenceDebug();

    protected:

    private:
};

#endif // T100SENTENCEDEBUG_H
