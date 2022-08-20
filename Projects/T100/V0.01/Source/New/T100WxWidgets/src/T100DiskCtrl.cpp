#include "T100DiskCtrl.h"

#include <wx/dcclient.h>
#include "T100DiskCreatePartDialog.h"
#include "T100DiskDialog.h"


const long T100DiskCtrl::ID_PAINT = wxNewId();


T100DiskCtrl::T100DiskCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                     const wxSize& size, long style, const wxValidator& validator,
                     const wxString& name)
    :wxControl(parent, id, pos, size, style, validator, name)
{
    //ctor
    create();
}

T100DiskCtrl::~T100DiskCtrl()
{
    //dtor
    destroy();
}

T100VOID T100DiskCtrl::create()
{
    Connect(wxEVT_PAINT, (wxObjectEventFunction)&T100DiskCtrl::OnPaint);
    Connect(wxEVT_RIGHT_DOWN, (wxObjectEventFunction)&T100DiskCtrl::OnMouse);

    Connect(wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnNew);

    menu.Append(wxID_NEW);
}

T100VOID T100DiskCtrl::destroy()
{

}

T100VOID T100DiskCtrl::SetLength(T100DWORD length)
{
    m_disk.LENGTH   = length;
}

T100DWORD T100DiskCtrl::GetLength()
{
    return m_disk.LENGTH;
}

T100BOOL T100DiskCtrl::AppendPart(T100DISK_PART* part)
{
    T100DISK_PART_CTRL_VECTOR::iterator      it;

    for(it = m_parts.begin(); it != m_parts.end(); it++){
        if(part == (*it)->PART){
            return T100FALSE;
        }
    }

    T100DISK_PART_CTRL*     item    = T100NEW T100DISK_PART_CTRL();

    item->PART      = part;

    item->RATIO     = part->LENGTH * 1.0 / m_disk.LENGTH;

    T100FLOAT       temp;

    temp = item->RATIO;

    item->X         = m_current;
    item->Y         = 0;
    item->WIDTH     = GetSize().GetWidth() * item->RATIO;
    item->HEIGHT    = 25;

    m_current += item->WIDTH;

    m_parts.push_back(item);
    return T100TRUE;
}

T100BOOL T100DiskCtrl::RemovePart(T100DISK_PART* part)
{
    T100DISK_PART_CTRL_VECTOR::iterator      it;

    for(it = m_parts.begin(); it != m_parts.end(); it++){
        if(part == (*it)->PART){
            T100DISK_PART_CTRL* item = (*it);
            m_parts.erase(it);
            T100SAFE_DELETE(item);
            T100SAFE_DELETE(part);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100VOID T100DiskCtrl::OnNew(wxCommandEvent& event)
{
    T100DiskCreatePartDialog        dialog(this, wxID_ANY, wxEmptyString);

    if(dialog.ShowModal() == wxID_OK){
        T100DISK_PART*   part    = T100NEW T100DISK_PART();

        part->LENGTH    = 512;

        AppendPart(part);

        Refresh();
    }
}

T100VOID T100DiskCtrl::OnPaint(wxPaintEvent& event)
{
    wxClientDC      dc(this);

    DrawDisk(dc);

    DrawParts(dc);

}

T100VOID T100DiskCtrl::OnMouse(wxMouseEvent& event)
{
    T100INT     result;

    result = Hit(event.GetX());


    //PopupMenu(&menu);

    ShowMenu(result);
}

T100VOID T100DiskCtrl::DrawDisk(wxDC& dc)
{
    T100WORD        width;
    T100WORD        height;

    width   = GetSize().GetWidth() - 5;
    height  = GetSize().GetHeight() - 5;

    dc.SetBrush(*wxGREEN_BRUSH);

    dc.DrawRectangle(wxPoint(0, 0), wxSize(width, height));

    dc.DrawText(L"1G", wxPoint(150, 5));


}

T100VOID T100DiskCtrl::DrawParts(wxDC& dc)
{
    for(T100DISK_PART_CTRL* item : m_parts){
        if(item){
            DrawPart(dc, item);
        }
    }
}

T100VOID T100DiskCtrl::DrawPart(wxDC& dc, T100DISK_PART_CTRL* item)
{
    T100WORD        x;
    T100WORD        y;
    T100WORD        width;
    T100WORD        height;

    x       = item->X;
    y       = item->Y;
    width   = item->WIDTH;
    height  = item->HEIGHT;

    dc.SetBrush(*wxYELLOW_BRUSH);

    dc.DrawRectangle(wxPoint(item->X, item->Y), wxSize(item->WIDTH, item->HEIGHT));

    dc.DrawText(L"1G", wxPoint(150, 5));
}


const wxBrush* T100DiskCtrl::GetBrush(T100COLOUR_PRIMITIVE_TYPE type)
{
    switch(type){
    case T100COLOUR_BLACK:
        {
            return wxBLACK_BRUSH;
        }
        break;
    case T100COLOUR_WHITE:
        {
            return wxWHITE_BRUSH;
        }
        break;
    case T100COLOUR_RED:
        {
            return wxRED_BRUSH;
        }
        break;
    case T100COLOUR_GREEN:
        {
            return wxGREEN_BRUSH;
        }
        break;
    case T100COLOUR_BLUE:
        {
            return wxBLUE_BRUSH;
        }
        break;
    case T100COLOUR_ORANGE:
        {
            return wxBLACK_BRUSH;
        }
        break;
    case T100COLOUR_YELLOW:
        {
            return wxYELLOW_BRUSH;
        }
        break;
    case T100COLOUR_PURPLE:
        {
            return wxBLACK_BRUSH;
        }
        break;
    }

    return wxBLACK_BRUSH;
}

T100INT T100DiskCtrl::Hit(T100WORD x)
{
    T100INT     result      = -1;
    T100WORD    current     = 0;
    T100WORD    left;
    T100WORD    right;
    T100WORD    index;


    for(index = 0; index < m_parts.size(); index++){
        T100DISK_PART_CTRL*     item;

        item = m_parts[index];
        if(item){
            left    = current;
            right   = left + item->WIDTH;

            if(x >= left && x <= right){
                return index;
            }else{
                current += item->WIDTH;
            }
        }
    }

    return result;
}

T100VOID T100DiskCtrl::ShowMenu(T100WORD index)
{
    switch(index){
    case 1:
        {

        }
        break;
    case 2:
        {

        }
        break;
    case 3:
        {

        }
        break;
    }
}
