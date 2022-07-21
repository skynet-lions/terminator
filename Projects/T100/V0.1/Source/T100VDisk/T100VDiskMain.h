/***************************************************************
 * Name:      T100VDiskMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100VDISKMAIN_H
#define T100VDISKMAIN_H

//(*Headers(T100VDiskFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

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
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100VDiskFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100VDISKMAIN_H
