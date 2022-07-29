#ifndef T100SENTENCEVARIABLE_H
#define T100SENTENCEVARIABLE_H

#include "T100Sentence.h"


class T100SentenceVariable : public T100Sentence
{
    public:
        T100SentenceVariable(T100SentenceScanner*);
        virtual ~T100SentenceVariable();

    protected:

    private:
};

#endif // T100SENTENCEVARIABLE_H
