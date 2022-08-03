#ifndef T100CMDLINESTRINGTOKEN_H
#define T100CMDLINESTRINGTOKEN_H

#include "T100Token.h"


class T100CmdLineStringToken : public T100Token
{
    public:
        T100CmdLineStringToken();
        virtual ~T100CmdLineStringToken();

        T100WSTRING         value;

    protected:

    private:
};

#endif // T100CMDLINESTRINGTOKEN_H
