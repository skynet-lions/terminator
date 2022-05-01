#ifndef T100SENTENCEMODE_H
#define T100SENTENCEMODE_H

#include "T100Sentence.h"

enum T100MODE_TYPE{
    T100MODE_NONE           = 0,
    T100MODE_REAL,
    T100MODE_VIRTUAL,
    T100MODE_MAX
};


class T100SentenceMode : public T100Sentence
{
    public:
        T100SentenceMode(T100SentenceScan*);
        virtual ~T100SentenceMode();

        T100BOOL            istiny          = T100FALSE;
        T100MODE_TYPE       mode            = T100MODE_VIRTUAL;

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:
        T100BOOL            parseSetup();

    private:
};

#endif // T100SENTENCEMODE_H
