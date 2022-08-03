#include "T100CmdLineParser.h"

#include "T100CmdLineStringScanner.h"
#include "T100CmdLineParameterScanner.h"


T100CmdLineParser::T100CmdLineParser()
{
    //ctor
}

T100CmdLineParser::~T100CmdLineParser()
{
    //dtor
}

T100BOOL T100CmdLineParser::parse(int argc, wchar_t** argv)
{
    T100BOOL                        result;
    T100CmdLineStringScanner        sscanner;
    T100CmdLineParameterScanner     pscanner;
    T100CmdLineParameterToken       token;

    sscanner.setSource(argc, argv);
    pscanner.setSource(&sscanner);


    result = pscanner.next(token);

}
