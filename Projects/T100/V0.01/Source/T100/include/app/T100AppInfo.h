#ifndef T100APPINFO_H
#define T100APPINFO_H

#include <wx/wx.h>
#include "T100Common.h"


class T100AppInfo
{
    public:
        T100AppInfo();
        virtual ~T100AppInfo();

        T100BOOL            TEST        = T100FALSE;
        T100BOOL            HELP        = T100FALSE;

        T100BOOL            ASSEMBLY    = T100FALSE;
        T100BOOL            EDITOR      = T100FALSE;
        T100BOOL            FONT        = T100FALSE;
        T100BOOL            IDE         = T100FALSE;
        T100BOOL            VDISK       = T100FALSE;
        T100BOOL            VDM         = T100FALSE;
        T100BOOL            VPC         = T100FALSE;

        T100BOOL            QUIT        = T100FALSE;
        T100BOOL            LIST        = T100FALSE;

        wxString            INPUT;
        wxString            OUTPUT;
        wxString            FILE;
        wxArrayString       IMPORTS;
        wxArrayString       UNITS;
        wxString            OFFSET;

        T100BOOL            LOG         = T100FALSE;
        T100BOOL            ERR         = T100FALSE;

    protected:

    private:
};

#endif // T100APPINFO_H
