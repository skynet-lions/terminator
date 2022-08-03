#ifndef T100CMDLINEPARSER_H
#define T100CMDLINEPARSER_H

#include "T100Common.h"


class T100CmdLineParser
{
    public:
        T100CmdLineParser();
        virtual ~T100CmdLineParser();

        T100BOOL            parse(int, wchar_t**);

    protected:

    private:
};

#endif // T100CMDLINEPARSER_H
