#include "../../include/view/T100FontPanel.h"

//(*InternalHeaders(T100FontPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100FontPanel)
const long T100FontPanel::ID_STATICBOX1 = wxNewId();
const long T100FontPanel::ID_STATICBOX2 = wxNewId();
const long T100FontPanel::ID_STATICBOX3 = wxNewId();
const long T100FontPanel::ID_STATICBOX4 = wxNewId();
const long T100FontPanel::ID_CHOICE_FONT = wxNewId();
const long T100FontPanel::ID_RADIOBUTTON1 = wxNewId();
const long T100FontPanel::ID_RADIOBUTTON2 = wxNewId();
const long T100FontPanel::ID_COMBOBOX_FONTSIZE = wxNewId();
const long T100FontPanel::ID_LISTBOX_COUNTRY = wxNewId();
const long T100FontPanel::ID_LISTBOX_FONTCODE = wxNewId();
const long T100FontPanel::ID_COMBOBOX_CODEBEGIN = wxNewId();
const long T100FontPanel::ID_COMBOBOX_CODEEND = wxNewId();
const long T100FontPanel::ID_BUTTON_APPEND = wxNewId();
const long T100FontPanel::ID_BUTTON_REMOVE = wxNewId();
const long T100FontPanel::ID_COMBOBOX_FILE = wxNewId();
const long T100FontPanel::ID_BUTTON_BROWSE = wxNewId();
const long T100FontPanel::ID_BUTTON_RUN = wxNewId();
const long T100FontPanel::ID_PANEL_PAINT = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100FontPanel,wxPanel)
	//(*EventTable(T100FontPanel)
	//*)
END_EVENT_TABLE()

T100FontPanel::T100FontPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100FontPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100FontPanel)
	Create(parent, id, wxDefaultPosition, wxSize(400,550), wxTAB_TRAVERSAL, _T("id"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("字体："), wxPoint(8,0), wxSize(256,64), 0, _T("ID_STATICBOX1"));
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("字号："), wxPoint(272,0), wxSize(128,64), 0, _T("ID_STATICBOX2"));
	StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("编码："), wxPoint(8,64), wxSize(392,184), 0, _T("ID_STATICBOX3"));
	StaticBox4 = new wxStaticBox(this, ID_STATICBOX4, _("文件："), wxPoint(8,248), wxSize(392,64), 0, _T("ID_STATICBOX4"));
	FontChoice = new wxChoice(this, ID_CHOICE_FONT, wxPoint(16,24), wxSize(176,25), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_FONT"));
	NameCodeRadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("GBK"), wxPoint(200,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	NameCodeRadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("UTF-8"), wxPoint(200,40), wxSize(56,17), 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	FontSizeComboBox = new wxComboBox(this, ID_COMBOBOX_FONTSIZE, wxEmptyString, wxPoint(280,24), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FONTSIZE"));
	CountryListBox = new wxListBox(this, ID_LISTBOX_COUNTRY, wxPoint(16,88), wxSize(84,152), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX_COUNTRY"));
	FontCodeListBox = new wxListBox(this, ID_LISTBOX_FONTCODE, wxPoint(104,88), wxSize(168,152), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX_FONTCODE"));
	CodeBeginComboBox = new wxComboBox(this, ID_COMBOBOX_CODEBEGIN, wxEmptyString, wxPoint(280,88), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CODEBEGIN"));
	CodeEndComboBox = new wxComboBox(this, ID_COMBOBOX_CODEEND, wxEmptyString, wxPoint(280,128), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CODEEND"));
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxPoint(288,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	RemoveButton = new wxButton(this, ID_BUTTON_REMOVE, _("删除"), wxPoint(288,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	FileComboBox = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxPoint(16,272), wxSize(280,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	BrowseButton = new wxButton(this, ID_BUTTON_BROWSE, _("浏览…"), wxPoint(312,272), wxSize(75,23), 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	RunButton = new wxButton(this, ID_BUTTON_RUN, _("运行"), wxPoint(160,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RUN"));
	PaintPanel = new wxPanel(this, ID_PANEL_PAINT, wxPoint(120,376), wxSize(168,152), wxBORDER_SIMPLE, _T("ID_PANEL_PAINT"));

	Connect(ID_CHOICE_FONT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontChoiceSelect);
	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnNameCodeRadioButton1Select);
	Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnNameCodeRadioButton2Select);
	Connect(ID_COMBOBOX_FONTSIZE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontSizeComboBoxSelected);
	Connect(ID_COMBOBOX_FONTSIZE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100FontPanel::OnFontSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FONTSIZE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100FontPanel::OnFontSizeComboBoxTextEnter);
	Connect(ID_LISTBOX_COUNTRY,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnCountryListBoxSelect);
	Connect(ID_LISTBOX_FONTCODE,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontCodeListBoxSelect);
	Connect(ID_COMBOBOX_CODEBEGIN,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnCodeBeginComboBoxSelected);
	Connect(ID_COMBOBOX_CODEBEGIN,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100FontPanel::OnCodeBeginComboBoxTextUpdated);
	Connect(ID_COMBOBOX_CODEBEGIN,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100FontPanel::OnCodeBeginComboBoxTextEnter);
	Connect(ID_COMBOBOX_CODEEND,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnCodeEndComboBoxSelected);
	Connect(ID_COMBOBOX_CODEEND,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100FontPanel::OnCodeEndComboBoxTextUpdated);
	Connect(ID_COMBOBOX_CODEEND,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100FontPanel::OnCodeEndComboBoxTextEnter);
	Connect(ID_BUTTON_APPEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100FontPanel::OnAppendButtonClick);
	Connect(ID_BUTTON_REMOVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100FontPanel::OnRemoveButtonClick);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFileComboBoxSelected);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100FontPanel::OnFileComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FILE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100FontPanel::OnFileComboBoxTextEnter);
	Connect(ID_BUTTON_BROWSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100FontPanel::OnBrowseButtonClick);
	Connect(ID_BUTTON_RUN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100FontPanel::OnRunButtonClick);
	PaintPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100FontPanel::OnPaintPanelPaint,0,this);
	//*)
}

T100FontPanel::~T100FontPanel()
{
	//(*Destroy(T100FontPanel)
	//*)
}


void T100FontPanel::OnFontChoiceSelect(wxCommandEvent& event)
{
}

void T100FontPanel::OnNameCodeRadioButton1Select(wxCommandEvent& event)
{
}

void T100FontPanel::OnNameCodeRadioButton2Select(wxCommandEvent& event)
{
}

void T100FontPanel::OnFontSizeComboBoxSelected(wxCommandEvent& event)
{
}

void T100FontPanel::OnFontSizeComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100FontPanel::OnFontSizeComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100FontPanel::OnCountryListBoxSelect(wxCommandEvent& event)
{
}

void T100FontPanel::OnFontCodeListBoxSelect(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeBeginComboBoxSelected(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeBeginComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeBeginComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeEndComboBoxSelected(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeEndComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeEndComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100FontPanel::OnAppendButtonClick(wxCommandEvent& event)
{
}

void T100FontPanel::OnRemoveButtonClick(wxCommandEvent& event)
{
}

void T100FontPanel::OnFileComboBoxSelected(wxCommandEvent& event)
{
}

void T100FontPanel::OnFileComboBoxTextUpdated(wxCommandEvent& event)
{
}

void T100FontPanel::OnFileComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100FontPanel::OnBrowseButtonClick(wxCommandEvent& event)
{
}

void T100FontPanel::OnRunButtonClick(wxCommandEvent& event)
{
}

void T100FontPanel::OnPaintPanelPaint(wxPaintEvent& event)
{
}
