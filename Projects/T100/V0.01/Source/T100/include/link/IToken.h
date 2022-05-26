#ifndef ITOKEN_H
#define ITOKEN_H

#include "T100StateCommon.h"


class IToken
{
    public:
        IToken();
        virtual ~IToken();

        T100TOKEN_TYPE          type        = T100TOKEN_TYPE_NONE;

        virtual T100VOID        clear() = 0;

    protected:

    private:
};

#endif // ITOKEN_H
