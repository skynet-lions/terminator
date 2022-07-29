#ifndef T100SENTENCEHALT_H
#define T100SENTENCEHALT_H

#include "T100Sentence.h"


class T100SentenceHalt : public T100Sentence
{
    public:
        T100SentenceHalt(T100SentenceScanner*);
        virtual ~T100SentenceHalt();

    protected:

    private:
};

#endif // T100SENTENCEHALT_H
