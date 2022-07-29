#ifndef T100SENTENCELABEL_H
#define T100SENTENCELABEL_H

#include "T100Sentence.h"


class T100SentenceLabel : public T100Sentence
{
    public:
        T100SentenceLabel(T100SentenceScanner*);
        virtual ~T100SentenceLabel();

    protected:

    private:
};

#endif // T100SENTENCELABEL_H
