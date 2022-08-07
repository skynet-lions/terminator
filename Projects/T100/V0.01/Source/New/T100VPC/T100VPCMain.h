/***************************************************************
 * Name:      T100VPCMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100VPCMAIN_H
#define T100VPCMAIN_H

//(*Headers(T100VPCFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

#include "T100Common.h"


class T100VPCFrame: public wxFrame
{
    public:

        T100VPCFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100VPCFrame();

    private:

        //(*Handlers(T100VPCFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnStartMenuSelected(wxCommandEvent& event);
        void OnStopMenuSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100VPCFrame)
        static const long ID_MENUITEM_START;
        static const long ID_MENUITEM_STOP;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VPCFrame)
        wxMenuItem* StartMenu;
        wxMenuItem* StopMenu;
        wxStatusBar* StatusBar1;
        //*)

        T100VOID            create();
        T100VOID            destroy();

        DECLARE_EVENT_TABLE()
};

#endif // T100VPCMAIN_H
