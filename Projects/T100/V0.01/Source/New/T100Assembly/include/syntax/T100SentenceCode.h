#ifndef T100SENTENCECODE_H
#define T100SENTENCECODE_H

#include "T100Sentence.h"


class T100SentenceCode : public T100Sentence
{
    public:
        T100SentenceCode(T100SentenceScanner*);
        virtual ~T100SentenceCode();

    protected:

    private:
};

#endif // T100SENTENCECODE_H
