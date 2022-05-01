#include "../../../include/ide/view/T100IDEFrame.h"

//(*InternalHeaders(T100IDEFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100IDEFrame)
//*)

BEGIN_EVENT_TABLE(T100IDEFrame,wxFrame)
	//(*EventTable(T100IDEFrame)
	//*)
END_EVENT_TABLE()

T100IDEFrame::T100IDEFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100IDEFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100IDEFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);

	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100IDEFrame::OnClose);
	//*)
}

T100IDEFrame::~T100IDEFrame()
{
	//(*Destroy(T100IDEFrame)
	//*)
}


void T100IDEFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
    exit(0);
}
