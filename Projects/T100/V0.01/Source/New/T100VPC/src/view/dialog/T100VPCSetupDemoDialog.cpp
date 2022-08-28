#include "../../../include/view/dialog/T100VPCSetupDemoDialog.h"

//(*InternalHeaders(T100VPCSetupDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCSetupDemoDialog)
//*)

BEGIN_EVENT_TABLE(T100VPCSetupDemoDialog,wxDialog)
	//(*EventTable(T100VPCSetupDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCSetupDemoDialog::T100VPCSetupDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCSetupDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCSetupDemoDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VPCSetupDemoDialog::~T100VPCSetupDemoDialog()
{
	//(*Destroy(T100VPCSetupDemoDialog)
	//*)
}

