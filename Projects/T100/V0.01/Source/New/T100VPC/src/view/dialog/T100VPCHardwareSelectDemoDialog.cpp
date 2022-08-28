#include "../../../include/view/dialog/T100VPCHardwareSelectDemoDialog.h"

//(*InternalHeaders(T100VPCHardwareSelectDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCHardwareSelectDemoDialog)
const long T100VPCHardwareSelectDemoDialog::ID_LISTVIEW1 = wxNewId();
const long T100VPCHardwareSelectDemoDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCHardwareSelectDemoDialog::ID_BUTTON_SETTING = wxNewId();
const long T100VPCHardwareSelectDemoDialog::ID_BUTTON_CLOSE = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHardwareSelectDemoDialog,wxDialog)
	//(*EventTable(T100VPCHardwareSelectDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCHardwareSelectDemoDialog::T100VPCHardwareSelectDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHardwareSelectDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHardwareSelectDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer3->Add(AppendButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SettingButton = new wxButton(this, ID_BUTTON_SETTING, _("设置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SETTING"));
	BoxSizer3->Add(SettingButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CloseButton = new wxButton(this, ID_BUTTON_CLOSE, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLOSE"));
	BoxSizer3->Add(CloseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_APPEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareSelectDemoDialog::OnAppendButtonClick);
	Connect(ID_BUTTON_SETTING,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareSelectDemoDialog::OnSettingButtonClick);
	Connect(ID_BUTTON_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareSelectDemoDialog::OnCloseButtonClick);
	//*)
}

T100VPCHardwareSelectDemoDialog::~T100VPCHardwareSelectDemoDialog()
{
	//(*Destroy(T100VPCHardwareSelectDemoDialog)
	//*)
}


void T100VPCHardwareSelectDemoDialog::OnCloseButtonClick(wxCommandEvent& event)
{
}

void T100VPCHardwareSelectDemoDialog::OnSettingButtonClick(wxCommandEvent& event)
{
}

void T100VPCHardwareSelectDemoDialog::OnAppendButtonClick(wxCommandEvent& event)
{
}
