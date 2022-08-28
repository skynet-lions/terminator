#ifndef T100VPCSETUPDEMODIALOG_H
#define T100VPCSETUPDEMODIALOG_H

//(*Headers(T100VPCSetupDemoDialog)
#include <wx/dialog.h>
//*)

class T100VPCSetupDemoDialog: public wxDialog
{
	public:

		T100VPCSetupDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCSetupDemoDialog();

		//(*Declarations(T100VPCSetupDemoDialog)
		//*)

	protected:

		//(*Identifiers(T100VPCSetupDemoDialog)
		//*)

	private:

		//(*Handlers(T100VPCSetupDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
