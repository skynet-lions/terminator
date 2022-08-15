#include "T100FontTools.h"

#include <wx/fontenum.h>
#include "T100FontCommon.h"


T100FontTools::T100FontTools()
{
    //ctor
}

T100FontTools::~T100FontTools()
{
    //dtor
}

wxArrayString T100FontTools::getAllFontNames()
{
    wxArrayString       result;
    wxFontEnumerator    fonts;
    wxFontEncoding      encoding            = wxFONTENCODING_DEFAULT;

    result = fonts.GetFacenames(encoding);

    return result;
}

wxArrayString T100FontTools::getAllFontSizes()
{
    wxArrayString       result;

    result.Add(wxString("16"));

    return result;
}

T100BOOL T100FontTools::append(T100WORD begin, T100WORD end)
{
    T100FONTFILE_ROW* row = T100NEW T100FONTFILE_ROW;

    row->BEGIN  = begin;
    row->END    = end;
    row->LENGTH = row->END - row->BEGIN + 1;

    //m_rows.push_back(row);

    return T100TRUE;
}

T100BOOL T100FontTools::remove(T100HWORD index)
{
    /*
    if(index < m_rows.size()){
        T100FONTFILE_ROW*   row;

        row = m_rows.at(index);
        if(row)T100DELETE(row);
        //m_rows.erase(std::begin(m_rows) + index);
        return T100TRUE;
    }
    */

    return T100FALSE;
}
