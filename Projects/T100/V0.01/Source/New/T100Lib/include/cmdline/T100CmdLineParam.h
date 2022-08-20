#ifndef T100CMDLINEPARAM_H
#define T100CMDLINEPARAM_H

#include "T100Common.h"
#include "T100CmdLineInfo.h"


class T100CmdLineParam : public T100CmdLineInfo
{
    public:
        T100CmdLineParam();
        virtual ~T100CmdLineParam();

        T100BOOL            parse(T100CmdLineParameterScanner*);

        T100WSTRING         value;

    protected:

    private:
};

#endif // T100CMDLINEPARAM_H
