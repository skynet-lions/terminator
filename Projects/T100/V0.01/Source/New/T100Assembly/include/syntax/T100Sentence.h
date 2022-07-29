#ifndef T100SENTENCE_H
#define T100SENTENCE_H

#include "T100AssemblyCommon.h"
class T100SentenceScanner;


class T100Sentence
{
    public:
        T100Sentence(T100SentenceScanner*);
        virtual ~T100Sentence();

        T100STRING              value;
        T100BOOL                parse();


    protected:

    private:
};

#endif // T100SENTENCE_H
