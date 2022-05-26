#include "T100AppCmdLine.h"

#include <wx/cmdline.h>
#include "T100AppCommon.h"


T100AppCmdLine::T100AppCmdLine()
{
    //ctor
}

T100AppCmdLine::~T100AppCmdLine()
{
    //dtor
}

T100BOOL T100AppCmdLine::parse(int& argc, wxChar** argv, T100AppInfo& info)
{
    T100BOOL                result;
    wxCmdLineParser         parser;
    wxCmdLineSwitchState    state;

    parser.SetDesc(T100CmdLineDesc);
    parser.SetCmdLine(argc, argv);

    if(0 != parser.Parse()){
        return T100FALSE;
    }

    state = parser.FoundSwitch(wxT("T"));
    if(wxCMD_SWITCH_ON == state){
        info.TEST       = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("H"));
    if(wxCMD_SWITCH_ON == state){
        info.HELP       = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("V"));
    if(wxCMD_SWITCH_ON == state){
        info.VPC        = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("D"));
    if(wxCMD_SWITCH_ON == state){
        info.VDISK      = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("M"));
    if(wxCMD_SWITCH_ON == state){
        info.VDM        = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("F"));
    if(wxCMD_SWITCH_ON == state){
        info.FONT       = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("I"));
    if(wxCMD_SWITCH_ON == state){
        info.IDE        = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("A"));
    if(wxCMD_SWITCH_ON == state){
        info.ASSEMBLY   = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("E"));
    if(wxCMD_SWITCH_ON == state){
        info.EDITOR     = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("L"));
    if(wxCMD_SWITCH_ON == state){
        info.LOG        = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("R"));
    if(wxCMD_SWITCH_ON == state){
        info.ERR        = T100TRUE;
    }

    state = parser.FoundSwitch(wxT("q"));
    if(wxCMD_SWITCH_ON == state){
        info.QUIT       = T100TRUE;
    }
    state = parser.FoundSwitch(wxT("l"));
    if(wxCMD_SWITCH_ON == state){
        info.ERR        = T100TRUE;
    }

    wxString    value;
    if(parser.Found(wxT("l"), &value)){
        info.LIST       = T100TRUE;
    }

    if(parser.Found(wxT("i"), &value)){
        info.INPUT      = value;
    }

    if(info.ASSEMBLY){
        if(parser.Found(wxT("o"), &value)){
            info.OUTPUT     = value;
        }
    }else{
        double  item;
        if(parser.Found(wxT("o"), &item)){
            //info.OFFSET   = item;
        }
    }

    if(parser.Found(wxT("f"), &value)){
        info.FILE       = value;
    }

    if(parser.Found(wxT("u"), &value)){
        info.FILE       = value;
    }

    return T100TRUE;
}
