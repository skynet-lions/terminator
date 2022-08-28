#ifndef T100VPCHARDWAREDIALOG_H
#define T100VPCHARDWAREDIALOG_H

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>


class T100VPCHardwareDialog : public wxDialog
{
    public:
        T100VPCHardwareDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHardwareDialog();

    protected:
		wxButton*       AppendButton;
		wxButton*       RemoveButton;
		wxListView*     ListView1;


    private:

		static const long ID_LISTVIEW1;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;

    protected:
		void OnAppendButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()

};

#endif // T100VPCHARDWAREDIALOG_H
