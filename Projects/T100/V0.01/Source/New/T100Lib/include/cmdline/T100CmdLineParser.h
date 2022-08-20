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

        virtual T100BOOL                    parse(int, wchar_t**);

        T100BOOL                            findExec(T100CmdLineExec&);
        T100BOOL                            findSwitch(T100WSTRING, T100CmdLineSwitch&);
        T100BOOL                            findOption(T100WSTRING, T100CmdLineOption&);
        T100BOOL                            findParam(T100CmdLineParam&);

    protected:
        T100WSTRING                         m_exec;

        T100CMDLINE_INFO_HASH               m_switchs;
        T100CMDLINE_INFO_HASH               m_options;
        T100CMDLINE_INFO_VECTOR             m_params;

        T100WORD                            m_index             = 0;


    private:
        T100CmdLineParameterScanner*        m_scanner           = T100NULL;

};

#endif // T100CMDLINEPARSER_H
