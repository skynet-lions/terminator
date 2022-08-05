#ifndef T100CMDLINEPARSER_H
#define T100CMDLINEPARSER_H

#include "T100Common.h"
#include "T100CmdLineParameterScanner.h"


class T100CmdLineParser
{
    public:
        T100CmdLineParser();
        virtual ~T100CmdLineParser();

        virtual T100BOOL        parse(int, wchar_t**);

        T100BOOL                findExec();
        T100BOOL                findSwitch();
        T100BOOL                findOption();
        T100BOOL                findParam();

    protected:

    private:
        T100CmdLineParameterScanner*        m_scanner           = T100NULL;

};

#endif // T100CMDLINEPARSER_H
