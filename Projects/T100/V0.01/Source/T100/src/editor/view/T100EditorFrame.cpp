#include "T100EditorFrame.h"

BEGIN_EVENT_TABLE(T100EditorFrame, wxFrame)
END_EVENT_TABLE()

T100EditorFrame::T100EditorFrame(wxWindow *parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style, const wxString& name)
    :wxFrame(parent, id, title, pos, size, style, name)
{
    //ctor
}

T100EditorFrame::~T100EditorFrame()
{
    //dtor
}
