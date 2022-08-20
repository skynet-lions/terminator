#ifndef T100DISKCTRL_H
#define T100DISKCTRL_H

#include <wx/menu.h>
#include <wx/dcclient.h>
#include <wx/control.h>
#include "T100Common.h"
#include "T100DiskCommon.h"


class T100DiskCtrl : public wxControl
{
    public:
        T100DiskCtrl(wxWindow* parent, wxWindowID id,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxControlNameStr);
        virtual ~T100DiskCtrl();

        T100VOID                    SetLength(T100DWORD);
        T100DWORD                   GetLength();

        T100BOOL                    AppendPart(T100DISK_PART*);
        T100BOOL                    RemovePart(T100DISK_PART*);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        wxMenu                      menu;

    private:
        static const long ID_PAINT;

        void OnPaint(wxPaintEvent& event);
        void OnMouse(wxMouseEvent& event);

        void OnNew(wxCommandEvent& event);

    private:
        T100WORD                    m_current           = 0;

        T100VOID                    DrawDisk(wxDC&);
        T100VOID                    DrawParts(wxDC&);
        T100VOID                    DrawPart(wxDC&, T100DISK_PART_CTRL*);

        T100INT                     Hit(T100WORD);

        T100VOID                    ShowMenu(T100WORD);

        T100DISK                    m_disk;

        T100DISK_PART_CTRL_VECTOR   m_parts;

        const wxBrush*              GetBrush(T100COLOUR_PRIMITIVE_TYPE);



};

#endif // T100DISKCTRL_H
