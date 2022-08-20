#ifndef T100DISKCREATEPARTDIALOG_H
#define T100DISKCREATEPARTDIALOG_H

#include <wx/dialog.h>
#include "T100Common.h"


class T100DiskCreatePartDialog : public wxDialog
{
    public:
        T100DiskCreatePartDialog(wxWindow *parent, wxWindowID id,
             const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
        virtual ~T100DiskCreatePartDialog();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100DISKCREATEPARTDIALOG_H
