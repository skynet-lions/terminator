#ifndef T100VPCHARDWARESELECTDIALOG_H
#define T100VPCHARDWARESELECTDIALOG_H

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>


class T100VPCHardwareSelectDialog : public wxDialog
{
    public:
        T100VPCHardwareSelectDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHardwareSelectDialog();

    protected:
		wxButton*           AppendButton;
		wxButton*           CloseButton;
		wxButton*           SettingButton;
		wxListView*         ListView1;

    private:
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_SETTING;
		static const long ID_BUTTON_CLOSE;

    protected:
        void OnCloseButtonClick(wxCommandEvent& event);
		void OnSettingButtonClick(wxCommandEvent& event);
		void OnAppendButtonClick(wxCommandEvent& event);

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()

};

#endif // T100VPCHARDWARESELECTDIALOG_H
