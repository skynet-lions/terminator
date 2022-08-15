#ifndef T100FONTTOOLS_H
#define T100FONTTOOLS_H

#include <wx/wx.h>
#include "T100Common.h"


class T100FontTools
{
    friend class T100FontPanel;
    public:
        T100FontTools();
        virtual ~T100FontTools();

        static wxArrayString        getAllFontNames();
        static wxArrayString        getAllFontSizes();

        T100BOOL                    append(T100WORD, T100WORD);
        T100BOOL                    remove(T100HWORD);

    protected:
        T100STDSTRING               m_fontname      = "";
        wxString                    m_current;

        T100WORD                    m_row_size      = 0;
        T100INT                     m_row_current   = -1;

    private:
        T100HWORD                   m_length        = 0;
        T100BYTE                    m_width         = 16;
        T100BYTE                    m_height        = 16;

        T100WORD                    m_begin         = 0;
        T100WORD                    m_end           = 0;

};

#endif // T100FONTTOOLS_H
