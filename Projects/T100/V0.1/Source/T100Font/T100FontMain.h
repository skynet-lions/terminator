/***************************************************************
 * Name:      T100FontMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100FONTMAIN_H
#define T100FONTMAIN_H

//(*Headers(T100FontFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100FontFrame: public wxFrame
{
    public:

        T100FontFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100FontFrame();

    private:

        //(*Handlers(T100FontFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100FontFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100FontFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100FONTMAIN_H
