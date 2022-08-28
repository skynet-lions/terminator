#ifndef T100VPCDEBUGDEMODIALOG_H
#define T100VPCDEBUGDEMODIALOG_H

//(*Headers(T100VPCDebugDemoDialog)
#include <wx/dialog.h>
//*)

class T100VPCDebugDemoDialog: public wxDialog
{
	public:

		T100VPCDebugDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDebugDemoDialog();

		//(*Declarations(T100VPCDebugDemoDialog)
		//*)

	protected:

		//(*Identifiers(T100VPCDebugDemoDialog)
		//*)

	private:

		//(*Handlers(T100VPCDebugDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
