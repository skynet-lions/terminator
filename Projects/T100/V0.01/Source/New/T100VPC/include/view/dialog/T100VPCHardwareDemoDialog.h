#ifndef T100VPCHARDWAREDEMODIALOG_H
#define T100VPCHARDWAREDEMODIALOG_H

//(*Headers(T100VPCHardwareDemoDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
//*)

class T100VPCHardwareDemoDialog: public wxDialog
{
	public:

		T100VPCHardwareDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCHardwareDemoDialog();

		//(*Declarations(T100VPCHardwareDemoDialog)
		wxButton* AppendButton;
		wxButton* RemoveButton;
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(T100VPCHardwareDemoDialog)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;
		//*)

	private:

		//(*Handlers(T100VPCHardwareDemoDialog)
		void OnAppendButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
