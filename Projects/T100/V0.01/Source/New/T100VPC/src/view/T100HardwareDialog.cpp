#include "../../include/view/T100HardwareDialog.h"

//(*InternalHeaders(T100HardwareDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100HardwareDialog)
const long T100HardwareDialog::ID_STATICBOX1 = wxNewId();
const long T100HardwareDialog::ID_LISTVIEW1 = wxNewId();
const long T100HardwareDialog::ID_BUTTON1 = wxNewId();
const long T100HardwareDialog::ID_BUTTON2 = wxNewId();
const long T100HardwareDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100HardwareDialog,wxDialog)
	//(*EventTable(T100HardwareDialog)
	//*)
END_EVENT_TABLE()

T100HardwareDialog::T100HardwareDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100HardwareDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100HardwareDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(184,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("Label"), wxPoint(8,8), wxSize(384,424), 0, _T("ID_STATICBOX1"));
	ListView1 = new wxListView(Panel1, ID_LISTVIEW1, wxPoint(24,32), wxSize(352,264), wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxPoint(32,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxPoint(144,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	//*)
}

T100HardwareDialog::~T100HardwareDialog()
{
	//(*Destroy(T100HardwareDialog)
	//*)
}

