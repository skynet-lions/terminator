#ifndef T100APPCOMMON_H
#define T100APPCOMMON_H


#include <wx/cmdline.h>
#include "T100Common.h"

//命令行参数设定
static const wxCmdLineEntryDesc T100CmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH, "?", "usage",          "run usage" },
    //
    { wxCMD_LINE_SWITCH, "T", "test",           "run test" },
    { wxCMD_LINE_SWITCH, "H", "help",           "show help" },
    { wxCMD_LINE_SWITCH, "V", "vpc",            "run vpc" },
    { wxCMD_LINE_SWITCH, "D", "vdisk",          "run vdisk console" },
    { wxCMD_LINE_SWITCH, "M", "vdm",            "run vdisk manager" },
    { wxCMD_LINE_SWITCH, "F", "font",           "run font file builder" },
    { wxCMD_LINE_SWITCH, "I", "ide",            "run ide" },
    { wxCMD_LINE_SWITCH, "A", "assembly",       "run assembler" },
    { wxCMD_LINE_SWITCH, "E", "editor",         "run editor" },
    { wxCMD_LINE_SWITCH, "L", "log",            "setup log" },
    { wxCMD_LINE_SWITCH, "R", "error",          "setup error" },
    //
    { wxCMD_LINE_SWITCH, "q", "quit",           "quit app" },
    { wxCMD_LINE_OPTION, "l", "",               "" },
    { wxCMD_LINE_OPTION, "i", "input",          "input file" },
    { wxCMD_LINE_OPTION, "o", "",               "" },
    { wxCMD_LINE_OPTION, "f", "file",           "input file" },
    //{ wxCMD_LINE_OPTION, "p", "imports",        "import path" },
    { wxCMD_LINE_OPTION, "u", "unit",           "test unit" },
    //{ wxCMD_LINE_OPTION, "s", "offset",         "memory offset" },
    //
    { wxCMD_LINE_NONE }
};

#endif // T100APPCOMMON_H
