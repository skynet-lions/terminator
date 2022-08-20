#include "T100DiskCreatePartDialog.h"

#include <wx/sizer.h>


T100DiskCreatePartDialog::T100DiskCreatePartDialog(wxWindow *parent, wxWindowID id, const wxString& title,
             const wxPoint& pos, const wxSize& size, long style, const wxString& name)
    :wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    create();
}

T100DiskCreatePartDialog::~T100DiskCreatePartDialog()
{
    //dtor
    destroy();
}

T100VOID T100DiskCreatePartDialog::create()
{
    wxSizer * const sizerTop = new wxBoxSizer(wxVERTICAL);

    sizerTop->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
                  wxSizerFlags().Right().Border());

    SetSizerAndFit(sizerTop);
}

T100VOID T100DiskCreatePartDialog::destroy()
{

}
