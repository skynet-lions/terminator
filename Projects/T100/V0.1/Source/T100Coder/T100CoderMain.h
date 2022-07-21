/***************************************************************
 * Name:      T100CoderMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100CODERMAIN_H
#define T100CODERMAIN_H

//(*Headers(T100CoderFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100CoderFrame: public wxFrame
{
    public:

        T100CoderFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100CoderFrame();

    private:

        //(*Handlers(T100CoderFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100CoderFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100CoderFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100CODERMAIN_H
