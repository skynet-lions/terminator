#ifndef T100CMDLINEPARSER_H
#define T100CMDLINEPARSER_H

#include "T100Common.h"
#include "T100CmdLineParameterScanner.h"

#include "T100CmdLineExec.h"
#include "T100CmdLineSwitch.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineParam.h"


class T100CmdLineParser
{
    public:
        T100CmdLineParser();
        virtual ~T100CmdLineParser();

        virtual T100BOOL        parse(int, char**);

        T100BOOL                findExec(T100CmdLineExec&);
        T100BOOL                findSwitch(T100WSTRING, T100CmdLineSwitch&);
        T100BOOL                findOption(T100WSTRING, T100CmdLineOption&);
        T100BOOL                findParam(T100CmdLineParam&);

    protected:
        T100WSTRING             m_exec;


    private:
        T100CmdLineParameterScanner*        m_scanner           = T100NULL;

};

#endif // T100CMDLINEPARSER_H
