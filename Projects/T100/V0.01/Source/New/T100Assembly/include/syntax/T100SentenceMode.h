#ifndef T100SENTENCEMODE_H
#define T100SENTENCEMODE_H

#include "T100Sentence.h"


typedef enum{
    T100MODE_NONE           = 0,
    T100MODE_REAL,
    T100MODE_VIRTUAL,
    T100MODE_MAX
}T100MODE;

typedef enum{
    T100TYPE_NONE           = 0,
    T100TYPE_TINY,
    T100TYPE_SMALL,
    T100TYPE_BIG,
    T100TYPE_MAX
}T100TYPE;


class T100SentenceMode : public T100Sentence
{
    public:
        T100SentenceMode(T100SentenceScanner*);
        virtual ~T100SentenceMode();

    protected:

    private:
};

#endif // T100SENTENCEMODE_H
