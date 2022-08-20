/***************************************************************
 * Name:      T100VDiskMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100VDISKMAIN_H
#define T100VDISKMAIN_H

//(*Headers(T100VDiskFrame)
#include <T100DiskCtrl.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)


#include "T100Common.h"


class T100VDiskFrame: public wxFrame
{
    public:

        T100VDiskFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100VDiskFrame();

    private:

        //(*Handlers(T100VDiskFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100VDiskFrame)
        static const long ID_CUSTOM1;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VDiskFrame)
        T100DiskCtrl* DiskCtrl;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        T100VOID            create();
        T100VOID            destroy();

        DECLARE_EVENT_TABLE()
};

#endif // T100VDISKMAIN_H
