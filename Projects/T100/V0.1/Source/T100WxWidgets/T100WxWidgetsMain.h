/***************************************************************
 * Name:      T100WxWidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100WXWIDGETSMAIN_H
#define T100WXWIDGETSMAIN_H

//(*Headers(T100WxWidgetsFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100WxWidgetsFrame: public wxFrame
{
    public:

        T100WxWidgetsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100WxWidgetsFrame();

    private:

        //(*Handlers(T100WxWidgetsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100WxWidgetsFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100WxWidgetsFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100WXWIDGETSMAIN_H
