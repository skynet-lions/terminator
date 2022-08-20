#ifndef T100CMDLINEOPTION_H
#define T100CMDLINEOPTION_H

#include "T100Common.h"
#include "T100CmdLineInfo.h"


class T100CmdLineOption : public T100CmdLineInfo
{
    public:
        T100CmdLineOption();
        virtual ~T100CmdLineOption();

        T100WSTRING         value;

    protected:

    private:
};

#endif // T100CMDLINEOPTION_H
