#ifndef T100FONTPANEL_H
#define T100FONTPANEL_H

//(*Headers(T100FontPanel)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
//*)

class T100FontPanel: public wxPanel
{
	public:

		T100FontPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100FontPanel();

		//(*Declarations(T100FontPanel)
		wxButton* AppendButton;
		wxButton* BrowseButton;
		wxButton* RemoveButton;
		wxButton* RunButton;
		wxChoice* FontChoice;
		wxComboBox* CodeBeginComboBox;
		wxComboBox* CodeEndComboBox;
		wxComboBox* FileComboBox;
		wxComboBox* FontSizeComboBox;
		wxListBox* CountryListBox;
		wxListBox* FontCodeListBox;
		wxPanel* PaintPanel;
		wxRadioButton* NameCodeRadioButton1;
		wxRadioButton* NameCodeRadioButton2;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticBox* StaticBox3;
		wxStaticBox* StaticBox4;
		//*)

	protected:

		//(*Identifiers(T100FontPanel)
		static const long ID_STATICBOX1;
		static const long ID_STATICBOX2;
		static const long ID_STATICBOX3;
		static const long ID_STATICBOX4;
		static const long ID_CHOICE_FONT;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_COMBOBOX_FONTSIZE;
		static const long ID_LISTBOX_COUNTRY;
		static const long ID_LISTBOX_FONTCODE;
		static const long ID_COMBOBOX_CODEBEGIN;
		static const long ID_COMBOBOX_CODEEND;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		static const long ID_BUTTON_RUN;
		static const long ID_PANEL_PAINT;
		//*)

	private:

		//(*Handlers(T100FontPanel)
		void OnFontChoiceSelect(wxCommandEvent& event);
		void OnNameCodeRadioButton1Select(wxCommandEvent& event);
		void OnNameCodeRadioButton2Select(wxCommandEvent& event);
		void OnFontSizeComboBoxSelected(wxCommandEvent& event);
		void OnFontSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnFontSizeComboBoxTextEnter(wxCommandEvent& event);
		void OnCountryListBoxSelect(wxCommandEvent& event);
		void OnFontCodeListBoxSelect(wxCommandEvent& event);
		void OnCodeBeginComboBoxSelected(wxCommandEvent& event);
		void OnCodeBeginComboBoxTextUpdated(wxCommandEvent& event);
		void OnCodeBeginComboBoxTextEnter(wxCommandEvent& event);
		void OnCodeEndComboBoxSelected(wxCommandEvent& event);
		void OnCodeEndComboBoxTextUpdated(wxCommandEvent& event);
		void OnCodeEndComboBoxTextEnter(wxCommandEvent& event);
		void OnAppendButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnBrowseButtonClick(wxCommandEvent& event);
		void OnRunButtonClick(wxCommandEvent& event);
		void OnPaintPanelPaint(wxPaintEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
