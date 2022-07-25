/***************************************************************
 * Name:      T100VDiskMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100VDiskMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100VDiskFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(T100VDiskFrame)
const long T100VDiskFrame::idMenuQuit = wxNewId();
const long T100VDiskFrame::idMenuAbout = wxNewId();
const long T100VDiskFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VDiskFrame,wxFrame)
    //(*EventTable(T100VDiskFrame)
    //*)
END_EVENT_TABLE()

T100VDiskFrame::T100VDiskFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100VDiskFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnAbout);
    //*)
}

T100VDiskFrame::~T100VDiskFrame()
{
    //(*Destroy(T100VDiskFrame)
    //*)
}

void T100VDiskFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100VDiskFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
