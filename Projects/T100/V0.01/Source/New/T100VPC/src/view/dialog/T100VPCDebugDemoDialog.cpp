#include "../../../include/view/dialog/T100VPCDebugDemoDialog.h"

//(*InternalHeaders(T100VPCDebugDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDebugDemoDialog)
//*)

BEGIN_EVENT_TABLE(T100VPCDebugDemoDialog,wxDialog)
	//(*EventTable(T100VPCDebugDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCDebugDemoDialog::T100VPCDebugDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDebugDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDebugDemoDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VPCDebugDemoDialog::~T100VPCDebugDemoDialog()
{
	//(*Destroy(T100VPCDebugDemoDialog)
	//*)
}

