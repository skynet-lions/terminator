#ifndef T100IDEFRAME_H
#define T100IDEFRAME_H

//(*Headers(T100IDEFrame)
#include <wx/frame.h>
//*)

class T100IDEFrame: public wxFrame
{
	public:

		T100IDEFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100IDEFrame();

		//(*Declarations(T100IDEFrame)
		//*)

	protected:

		//(*Identifiers(T100IDEFrame)
		//*)

	private:

		//(*Handlers(T100IDEFrame)
		void OnClose(wxCloseEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
