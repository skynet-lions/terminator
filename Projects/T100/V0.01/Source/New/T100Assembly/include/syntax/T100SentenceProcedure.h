#ifndef T100SENTENCEPROCEDURE_H
#define T100SENTENCEPROCEDURE_H

#include "T100Sentence.h"


class T100SentenceProcedure : public T100Sentence
{
    public:
        T100SentenceProcedure(T100SentenceScanner*);
        virtual ~T100SentenceProcedure();

    protected:

    private:
};

#endif // T100SENTENCEPROCEDURE_H
