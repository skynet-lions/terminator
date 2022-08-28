#include "../../../include/view/dialog/T100VPCHardwareDemoDialog.h"

//(*InternalHeaders(T100VPCHardwareDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VPCHardwareSelectDemoDialog.h"

//(*IdInit(T100VPCHardwareDemoDialog)
const long T100VPCHardwareDemoDialog::ID_LISTVIEW1 = wxNewId();
const long T100VPCHardwareDemoDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCHardwareDemoDialog::ID_BUTTON_REMOVE = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHardwareDemoDialog,wxDialog)
	//(*EventTable(T100VPCHardwareDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCHardwareDemoDialog::T100VPCHardwareDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHardwareDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHardwareDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,300));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer3->Add(AppendButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RemoveButton = new wxButton(this, ID_BUTTON_REMOVE, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	BoxSizer3->Add(RemoveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON_APPEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDemoDialog::OnAppendButtonClick);
	Connect(ID_BUTTON_REMOVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDemoDialog::OnRemoveButtonClick);
	//*)
}

T100VPCHardwareDemoDialog::~T100VPCHardwareDemoDialog()
{
	//(*Destroy(T100VPCHardwareDemoDialog)
	//*)
}


void T100VPCHardwareDemoDialog::OnAppendButtonClick(wxCommandEvent& event)
{
    T100VPCHardwareSelectDemoDialog     dialog(this);

    if(dialog.ShowModal() == wxID_OK){

    }
}

void T100VPCHardwareDemoDialog::OnRemoveButtonClick(wxCommandEvent& event)
{
}
