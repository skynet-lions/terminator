#ifndef T100SENTENCEIMPORT_H
#define T100SENTENCEIMPORT_H

#include "T100Sentence.h"


class T100SentenceImport : public T100Sentence
{
    public:
        T100SentenceImport(T100SentenceScanner*);
        virtual ~T100SentenceImport();

    protected:

    private:
};

#endif // T100SENTENCEIMPORT_H
