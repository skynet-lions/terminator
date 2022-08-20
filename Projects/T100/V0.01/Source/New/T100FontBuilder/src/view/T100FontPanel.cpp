#include "../../include/view/T100FontPanel.h"

//(*InternalHeaders(T100FontPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100UnicodeCommon.h"
#include "T100FontHint.h"
#include "T100FontCallback.h"


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
const long T100FontPanel::ID_COMBOBOX_CODEBEGIN = wxNewId();
const long T100FontPanel::ID_COMBOBOX_CODEEND = wxNewId();
const long T100FontPanel::ID_BUTTON_APPEND = wxNewId();
const long T100FontPanel::ID_BUTTON_REMOVE = wxNewId();
const long T100FontPanel::ID_COMBOBOX_FILE = wxNewId();
const long T100FontPanel::ID_BUTTON_BROWSE = wxNewId();
const long T100FontPanel::ID_BUTTON_RUN = wxNewId();
const long T100FontPanel::ID_PANEL_PAINT = wxNewId();
const long T100FontPanel::ID_LISTCTRL_FONTCODE = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100FontPanel,wxPanel)
	//(*EventTable(T100FontPanel)
	//*)
END_EVENT_TABLE()

T100FontPanel::T100FontPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);

	create();
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
	FontSizeComboBox = new wxComboBox(this, ID_COMBOBOX_FONTSIZE, wxEmptyString, wxPoint(280,24), wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX_FONTSIZE"));
	CountryListBox = new wxListBox(this, ID_LISTBOX_COUNTRY, wxPoint(16,88), wxSize(84,152), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX_COUNTRY"));
	CodeBeginComboBox = new wxComboBox(this, ID_COMBOBOX_CODEBEGIN, wxEmptyString, wxPoint(280,88), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CODEBEGIN"));
	CodeEndComboBox = new wxComboBox(this, ID_COMBOBOX_CODEEND, wxEmptyString, wxPoint(280,128), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_CODEEND"));
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxPoint(288,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	RemoveButton = new wxButton(this, ID_BUTTON_REMOVE, _("删除"), wxPoint(288,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	FileComboBox = new wxComboBox(this, ID_COMBOBOX_FILE, wxEmptyString, wxPoint(16,272), wxSize(280,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX_FILE"));
	BrowseButton = new wxButton(this, ID_BUTTON_BROWSE, _("浏览…"), wxPoint(312,272), wxSize(75,23), 0, wxDefaultValidator, _T("ID_BUTTON_BROWSE"));
	RunButton = new wxButton(this, ID_BUTTON_RUN, _("运行"), wxPoint(160,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RUN"));
	PaintPanel = new wxPanel(this, ID_PANEL_PAINT, wxPoint(120,376), wxSize(168,152), wxBORDER_SIMPLE, _T("ID_PANEL_PAINT"));
	FontCodeListCtrl = new wxListCtrl(this, ID_LISTCTRL_FONTCODE, wxPoint(104,88), wxSize(168,152), wxLC_REPORT|wxBORDER_SIMPLE, wxDefaultValidator, _T("ID_LISTCTRL_FONTCODE"));

	Connect(ID_CHOICE_FONT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontChoiceSelect);
	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnNameCodeRadioButton1Select);
	Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnNameCodeRadioButton2Select);
	Connect(ID_COMBOBOX_FONTSIZE,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontSizeComboBoxSelected);
	Connect(ID_COMBOBOX_FONTSIZE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&T100FontPanel::OnFontSizeComboBoxTextUpdated);
	Connect(ID_COMBOBOX_FONTSIZE,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&T100FontPanel::OnFontSizeComboBoxTextEnter);
	Connect(ID_LISTBOX_COUNTRY,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnCountryListBoxSelect);
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
	Connect(ID_LISTCTRL_FONTCODE,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontCodeListCtrlItemSelect);
	Connect(ID_LISTCTRL_FONTCODE,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&T100FontPanel::OnFontCodeListCtrlItemDeselect);
	//*)
}

T100FontPanel::~T100FontPanel()
{
	//(*Destroy(T100FontPanel)
	//*)

    destroy();
}

T100VOID T100FontPanel::create()
{
    wxArrayString   result;

    m_running = T100FALSE;

    result = T100FontTools::getAllFontNames();
    FontChoice->Append(result);

    result = T100FontTools::getAllFontSizes();
    FontSizeComboBox->Append(result);

    int i = 0;

    while("" != T100FONT_COUNTRY[i][0]){
        CountryListBox->Append(T100FONT_COUNTRY[i][0]);
        i++;
    }

    FontCodeListCtrl->InsertColumn(0, _("开始"));
    FontCodeListCtrl->InsertColumn(1, _("结束"));

    FileComboBox->SetValue(_("resources\\font.fnt"));
}

T100VOID T100FontPanel::destroy()
{

}


void T100FontPanel::OnFontChoiceSelect(wxCommandEvent& event)
{
    m_tools.m_fontname = FontChoice->GetString(FontChoice->GetSelection());
}

void T100FontPanel::OnNameCodeRadioButton1Select(wxCommandEvent& event)
{
    m_tools.m_convert = T100TRUE;
}

void T100FontPanel::OnNameCodeRadioButton2Select(wxCommandEvent& event)
{
    m_tools.m_convert = T100FALSE;
}

void T100FontPanel::OnFontSizeComboBoxSelected(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = FontSizeComboBox->GetValue().ToLongLong(&value);

    if(result && 150 >= value){
        m_tools.m_length    = value;
        m_tools.m_width     = value;
        m_tools.m_height    = value;
    }
}

void T100FontPanel::OnFontSizeComboBoxTextUpdated(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = FontSizeComboBox->GetValue().ToLongLong(&value);

    if(result && 150 >= value){
        m_tools.m_length    = value;
        m_tools.m_width     = value;
        m_tools.m_height    = value;
    }
}

void T100FontPanel::OnFontSizeComboBoxTextEnter(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = FontSizeComboBox->GetValue().ToLongLong(&value);

    if(result && 150 >= value){
        m_tools.m_length    = value;
        m_tools.m_width     = value;
        m_tools.m_height    = value;
    }
}

void T100FontPanel::OnCountryListBoxSelect(wxCommandEvent& event)
{
    T100WORD        index;
    T100STDSTRING   country;

    index       = CountryListBox->GetSelection();
    country     = T100FONT_COUNTRY[index][1];

    CodeBeginComboBox->Clear();
    CodeEndComboBox->Clear();

    if("china" == country){
        int i = 0;
        while("" != T100FONT_CHINA_CODE[i][0]){
            CodeBeginComboBox->Append(T100FONT_CHINA_CODE[i][0]);
            CodeEndComboBox->Append(T100FONT_CHINA_CODE[i][1]);
            i++;
        }

    }else if("america" == country){
        int i = 0;
        while("" != T100FONT_AMERICA_CODE[i][0]){
            CodeBeginComboBox->Append(T100FONT_AMERICA_CODE[i][0]);
            CodeEndComboBox->Append(T100FONT_AMERICA_CODE[i][1]);
            i++;
        }
    }else{

    }
}

void T100FontPanel::OnCodeBeginComboBoxSelected(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = CodeBeginComboBox->GetValue().ToLongLong(&value, 16);

    if(result){
        //m_tools.m_begin = value;
        //m_tools.m_value = value;
    }
}

void T100FontPanel::OnCodeBeginComboBoxTextUpdated(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = CodeBeginComboBox->GetValue().ToLongLong(&value, 16);

    if(result){
        //m_tools.m_begin = value;
        //m_tools.m_value = value;
    }
}

void T100FontPanel::OnCodeBeginComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100FontPanel::OnCodeEndComboBoxSelected(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = CodeEndComboBox->GetValue().ToLongLong(&value, 16);

    if(result){
        //m_tools.m_end   = value;
    }
}

void T100FontPanel::OnCodeEndComboBoxTextUpdated(wxCommandEvent& event)
{
    T100BOOL    result;
    T100LONG    value;

    result = CodeEndComboBox->GetValue().ToLongLong(&value, 16);

    if(result){
        //m_tools.m_end   = value;
    }
}

void T100FontPanel::OnCodeEndComboBoxTextEnter(wxCommandEvent& event)
{
}

void T100FontPanel::OnAppendButtonClick(wxCommandEvent& event)
{
    long id;
    long index;

    if(CodeBeginComboBox->GetValue().empty()){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_CODE_BEGIN_NOT_SELECTED), _("ERROR:"));

        dialog.ShowModal();
        return;
    };

    if(CodeEndComboBox->GetValue().empty()){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_CODE_END_NOT_SELECTED), _("ERROR:"));

        dialog.ShowModal();
        return;
    };

    T100BOOL    result;
    T100LONG    begin;
    T100LONG    end;

    result = CodeBeginComboBox->GetValue().ToLongLong(&begin, 16);

    if(result){
        //m_tools.m_begin     = value;
        //m_tools.m_value     = value;
    }else{
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"), wxICON_ERROR);

        dialog.ShowModal();
        return;
    }

    result = CodeEndComboBox->GetValue().ToLongLong(&end, 16);

    if(result){
        //m_tools.m_end       = value;
    }else{
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"), wxICON_ERROR);

        dialog.ShowModal();
        return;
    }

    if(!m_tools.append(begin, end)){
        return;
    }

    id = FontCodeListCtrl->GetItemCount();
    index = FontCodeListCtrl->InsertItem(id, CodeBeginComboBox->GetValue());
    FontCodeListCtrl->SetItem(index, 1, CodeEndComboBox->GetValue());
}

void T100FontPanel::OnRemoveButtonClick(wxCommandEvent& event)
{
    if(-1 == m_current){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_CODE_LIST_NOT_SELECTED), _("WARNING:"), wxICON_WARNING);

        dialog.ShowModal();

    }else{
        T100HWORD   index;
        index = m_current;
        if(m_tools.remove(index)){
            if(FontCodeListCtrl->DeleteItem(m_current)){
                m_current = -1;
            }
        }
    }
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
    wxFileDialog dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return;

    wxString path;
    wxString name;
    wxString file;

    path = dialog.GetDirectory();
    name = dialog.GetFilename();

    file = path;
    file += "\\";
    file += name;

    FileComboBox->Append(FileComboBox->GetValue());
    FileComboBox->SetValue(file);
}

void T100FontPanel::OnRunButtonClick(wxCommandEvent& event)
{
    T100BOOL    result;

    if(m_running){
        RunButton->SetLabel(_("运行"));
        m_tools.closeFile();
        m_running = T100FALSE;
        return;
    }

    result = verify();
    if(!result){
        return;
    }

    m_running = !m_running;

    m_tools.m_row_size = FontCodeListCtrl->GetItemCount();
    result = m_tools.createFile(FileComboBox->GetValue().ToStdWstring());
    if(!result){
        m_running = T100FALSE;
        return;
    }

    RunButton->SetLabel(_("结束"));
    PaintPanel->Refresh();
}

void T100FontPanel::OnPaintPanelPaint(wxPaintEvent& event)
{
    if(!m_running){
        return;
    }

    wxPaintDC   dc(PaintPanel);
    if(m_tools.draw(dc)){
        m_tools.capture(dc);
        m_tools.writeItem();
    }else{
        m_running = T100FALSE;
        m_tools.closeFile();
    }

    if(m_running){
        PaintPanel->Refresh();
    }else{
        RunButton->SetLabel(_("运行"));
        m_tools.m_value = m_tools.m_begin;
    }

}


T100BOOL T100FontPanel::verify()
{
    int index;

    index = FontChoice->GetSelection();

    if(0 > index){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"));

        dialog.ShowModal();

        return T100FALSE;
    }

    if(NameCodeRadioButton1->GetValue() || NameCodeRadioButton2->GetValue()){
    }else{
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"));

        dialog.ShowModal();

        return T100FALSE;
    }

    if(FontSizeComboBox->GetValue().empty()){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"));

        dialog.ShowModal();

        return T100FALSE;
    }

    if(0 > CountryListBox->GetSelection()){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"));

        dialog.ShowModal();

        return T100FALSE;
    }

    if(0 == FontCodeListCtrl->GetItemCount()){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"));

        dialog.ShowModal();

        return T100FALSE;
    }

    if(FileComboBox->GetValue().empty()){
        wxMessageDialog dialog(T100NULL, wxString(T100FONTBUILDER_HINT_PARAMETERS_ERROR), _("ERROR:"), wxICON_ERROR);

        dialog.ShowModal();

        return T100FALSE;
    }

    return T100TRUE;
}

void T100FontPanel::OnFontCodeListCtrlItemSelect(wxListEvent& event)
{
    m_current = event.GetIndex();
}

void T100FontPanel::OnFontCodeListCtrlItemDeselect(wxListEvent& event)
{
    m_current = -1;
}
