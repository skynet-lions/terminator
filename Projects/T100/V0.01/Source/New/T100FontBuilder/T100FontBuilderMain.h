/***************************************************************
 * Name:      T100FontBuilderMain.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100FONTBUILDERMAIN_H
#define T100FONTBUILDERMAIN_H

//(*Headers(T100FontBuilderFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class T100FontBuilderFrame: public wxFrame
{
    public:

        T100FontBuilderFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100FontBuilderFrame();

    private:

        //(*Handlers(T100FontBuilderFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100FontBuilderFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100FontBuilderFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100FONTBUILDERMAIN_H
