#ifndef T100KEYWORDTOKEN_H
#define T100KEYWORDTOKEN_H

#include "T100String.h"
#include "T100Token.h"


class T100KeywordToken : public T100Token
{
    public:
        T100KeywordToken();
        virtual ~T100KeywordToken();

        T100String              data;
        T100BYTE_VECTOR         bytes;

        T100VOID                clear();
        T100KeywordToken*       copy();

    protected:

    private:
};

#endif // T100KEYWORDTOKEN_H
