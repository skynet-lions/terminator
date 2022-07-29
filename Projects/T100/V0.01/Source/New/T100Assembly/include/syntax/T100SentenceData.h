#ifndef T100SENTENCEDATA_H
#define T100SENTENCEDATA_H

#include "T100Sentence.h"


class T100SentenceData : public T100Sentence
{
    public:
        T100SentenceData(T100SentenceScanner*);
        virtual ~T100SentenceData();

    protected:

    private:
};

#endif // T100SENTENCEDATA_H
