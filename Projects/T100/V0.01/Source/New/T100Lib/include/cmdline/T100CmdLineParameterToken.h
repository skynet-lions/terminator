#ifndef T100CMDLINEPARAMETERTOKEN_H
#define T100CMDLINEPARAMETERTOKEN_H

#include "T100Token.h"


class T100CmdLineParameterToken : public T100Token
{
    public:
        T100CmdLineParameterToken();
        virtual ~T100CmdLineParameterToken();

        T100WSTRING             value;

        T100VOID                clear();

    protected:

    private:
};

#endif // T100CMDLINEPARAMETERTOKEN_H
