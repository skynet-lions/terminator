#ifndef T100APPINFO_H
#define T100APPINFO_H

#include <wx/wx.h>
#include "T100Common.h"


class T100AppInfo
{
    public:
        T100AppInfo();
        virtual ~T100AppInfo();

        T100BOOL            LOG         = T100FALSE;
        T100BOOL            ERR         = T100FALSE;

        T100BOOL            TEST        = T100FALSE;
        T100BOOL            HELP        = T100FALSE;

        T100BOOL            QUIT        = T100FALSE;

    protected:

    private:
};

#endif // T100APPINFO_H
