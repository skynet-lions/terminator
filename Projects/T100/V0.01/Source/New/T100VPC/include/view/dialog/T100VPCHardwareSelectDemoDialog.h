#ifndef T100VPCHARDWARESELECTDEMODIALOG_H
#define T100VPCHARDWARESELECTDEMODIALOG_H

//(*Headers(T100VPCHardwareSelectDemoDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
//*)

class T100VPCHardwareSelectDemoDialog: public wxDialog
{
	public:

		T100VPCHardwareSelectDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCHardwareSelectDemoDialog();

		//(*Declarations(T100VPCHardwareSelectDemoDialog)
		wxButton* AppendButton;
		wxButton* CloseButton;
		wxButton* SettingButton;
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(T100VPCHardwareSelectDemoDialog)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_SETTING;
		static const long ID_BUTTON_CLOSE;
		//*)

	private:

		//(*Handlers(T100VPCHardwareSelectDemoDialog)
		void OnCloseButtonClick(wxCommandEvent& event);
		void OnSettingButtonClick(wxCommandEvent& event);
		void OnAppendButtonClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
